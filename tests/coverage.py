#!/usr/bin/env python3
"""Run gcov for the unit-test target and enforce a line coverage threshold."""

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--build-dir", required=True)
    parser.add_argument("--threshold", type=float, required=True)
    parser.add_argument("--sources", nargs="+", required=True)
    return parser.parse_args()


def run_gcov(build_dir, sources):
    object_dir = Path(build_dir) / "CMakeFiles" / "unit_tests.dir"
    gcov = os.environ.get("GCOV", "gcov")
    command = [gcov, "-o", str(object_dir), *sources]
    subprocess.run(command, check=True)


def collect_line_coverage(sources):
    covered = 0
    executable = 0
    for source in sources:
        gcov_file = Path(f"{Path(source).name}.gcov")
        if not gcov_file.exists():
            raise FileNotFoundError(f"missing gcov output: {gcov_file}")

        for line in gcov_file.read_text(encoding="utf-8").splitlines():
            match = re.match(r"\s*([^:]+):\s*(\d+):(.*)", line)
            if not match:
                continue
            count = match.group(1).strip()
            if count == "-":
                continue

            executable += 1
            if count not in {"#####", "====="} and int(count.rstrip("*")) > 0:
                covered += 1

    return covered, executable


def main():
    args = parse_args()
    run_gcov(args.build_dir, args.sources)
    covered, executable = collect_line_coverage(args.sources)
    percent = 100.0 if executable == 0 else covered * 100.0 / executable
    print(f"Line coverage: {percent:.2f}% ({covered}/{executable})")
    if percent + 1e-9 < args.threshold:
        print(f"Coverage is below required threshold {args.threshold:.2f}%", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

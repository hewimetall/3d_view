# s21_view3d

A small C/raylib OBJ viewer. Drop a Wavefront `.obj` file onto the window to
render the model and use the side panel controls to move, rotate, and scale it.

## Requirements

- CMake 3.16 or newer
- A C11 compiler
- Git access to GitHub during the first app build, because CMake fetches:
  - raylib 6.0
  - raygui 4.0
- Linux graphics development libraries required by raylib when building the GUI
  app, such as OpenGL, X11, pthread, dl, rt, and math libraries.
- Python 3 and `gcov` for the coverage target.

The headless unit tests do not require raylib, raygui, OpenGL, or the Check test
framework.

## Environment

Common optional variables:

- `BUILD_DIR`: Makefile build directory for normal builds. Defaults to `build`.
- `COVERAGE_DIR`: Makefile build directory for coverage builds. Defaults to
  `build/coverage`.
- `CC`: C compiler used by CMake. Use `CC=gcc` for the coverage target so gcov
  data is emitted in the expected format.
- `GCOV`: gcov-compatible executable used by `tests/coverage.py`. Defaults to
  `gcov`.

## Setup and build

Configure and build the graphical app:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --target s21_view3d --parallel
```

Or use Make:

```sh
make build
```

## Run

```sh
./build/s21_view3d
```

Or:

```sh
make run
```

## Test

Run the headless unit test suite:

```sh
cmake -S . -B build -DBUILD_APP=OFF -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target unit_tests --parallel
ctest --test-dir build --output-on-failure
```

Or:

```sh
make test
```

## Coverage

Coverage is measured from real unit-test execution across the headless parser,
math, transform, and input-validation code. The coverage gate fails below 93%.

```sh
CC=gcc cmake -S . -B build/coverage -DBUILD_APP=OFF -DENABLE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build/coverage --target coverage --parallel
```

Or:

```sh
make coverage
```

## Dependencies

Application dependencies are declared in `CMakeLists.txt` through
`FetchContent` and pinned to upstream commit IDs for reproducible builds:

- raylib 6.0
- raygui 4.0

There are no npm, pip, or cargo dependency manifests in this repository, so
`npm audit`, `pip-audit`, and `cargo audit` are not applicable.

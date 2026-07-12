BUILD_DIR ?= build
COVERAGE_DIR ?= build/coverage

.PHONY: all configure build run test coverage clean dist

all: build

configure:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release

build: configure
	cmake --build $(BUILD_DIR) --target s21_view3d --parallel

run: build
	./$(BUILD_DIR)/s21_view3d

test:
	cmake -S . -B $(BUILD_DIR) -DBUILD_APP=OFF -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(BUILD_DIR) --target unit_tests --parallel
	ctest --test-dir $(BUILD_DIR) --output-on-failure

coverage:
	CC=gcc cmake -S . -B $(COVERAGE_DIR) -DBUILD_APP=OFF -DENABLE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(COVERAGE_DIR) --target coverage --parallel

dist:
	git archive --format=tar.gz -o s21_view3d.tar.gz --prefix=s21_view3d/ HEAD

clean:
	rm -rf $(BUILD_DIR) build/coverage *.gcov



all := $(./*.c)
TEST_FILES := array_stack_help.c calculate.c string_edit.c tests/main.c tests/test.c validate.c
	
all: install 
	../build/s21_view3d

install:
	mkdir -p ../build
	cmake -S . -B ../build 
	cmake open ../build/ 
	cmake --build ../build --target s21_view3d 
	../build/s21_view3d
	
uninstall:
	rm -rf ../build

test:
	mkdir -p ../build
	cmake -S . -B ../build 
	cmake open ../build/ 
	cmake --build ../build --target test
	../build/test
dvi:
	open readme.html

dist:
	git archive --format=tar.gz -o C7_SmartCalc_v1.0-1.tar.gz --prefix=my-repo/ develop

gcov_report: test
	mv ./build/CMakeFiles/test.dir/*.gcda .
	mv ./build/CMakeFiles/test.dir/*.gcno .
	gcov *.c 
	find ./ -type f -iname '*.gcda'
	lcov --directory ./ --capture --output-file postgresql.info --gcov-tool=gcov-12
	mkdir cov-report || true
	genhtml -o ./cov-report/ postgresql.info || true

cppcheck: $(all) 
	cppcheck  $^;

format: $(all)
	cp ../materials/linters/.clang-format .
	clang-format -i -style=google $^;
	rm .clang-format

clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.a.* && rm -rf main.a*
	-rm -rf lib* && rm -rf test
	-rm -rf test_*
	-rm -rf *tar.gz

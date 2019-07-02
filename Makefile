GCC = g++
FLAGS = -O3 -W -Wall -Werror -Wextra
DEPS = -lGL -lGLU -lglut

all: clean build_folder tugas4

clean:
	@rm -rf build/

build_folder:
	@mkdir build/
	@mkdir build/o/
	@mkdir build/bin/

line.o: src/line.cc src/line.hh
	${GCC} -c src/line.cc -o build/o/line.o

main.o: src/main.cc
	${GCC} -c src/main.cc -o build/o/main.o

tugas4: line.o main.o
	${GCC} ${FLAGS} build/o/line.o build/o/main.o ${DEPS} -o build/bin/tugas4

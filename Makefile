# file that state requirements/recipe to compile the project
# Copyright (C) 2018  Erlangga Ibrahim
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

GCC = g++
FLAGS = -W -Wall -Werror -Wextra
DEPS = -lGL -lGLU -lglut

EXEC_NAME = tugas4.exec

O = build/o

all: clean build_folder ${EXEC_NAME}

clean:
	@rm -rf build/

build_folder:
	@mkdir build/
	@mkdir ${O}/
	@mkdir build/bin/

# Dependencies
point.o: src/point.cc src/point.hh
	${GCC} ${FLAGS} -c src/point.cc -o ${O}/point.o

line.o: src/line.cc src/line.hh
	${GCC} ${FLAGS} -c src/line.cc -o ${O}/line.o

intersection.o: src/intersection.cc src/intersection.hh
	${GCC} ${FLAGS} -c src/intersection.cc -o ${O}/intersection.o

draw.o: src/draw.cc src/draw.hh
	${GCC} ${FLAGS} -c src/draw.cc -o ${O}/draw.o

text.o: src/text.cc src/text.hh
	${GCC} ${FLAGS} -c src/text.cc -o ${O}/text.o

main.o: src/main.cc
	${GCC} ${FLAGS} -c src/main.cc -o ${O}/main.o

# Executable
${EXEC_NAME}: point.o line.o intersection.o draw.o text.o main.o
	${GCC} ${FLAGS} ${O}/point.o ${O}/line.o ${O}/intersection.o ${O}/draw.o ${O}/text.o ${O}/main.o ${DEPS} -o build/bin/${EXEC_NAME}

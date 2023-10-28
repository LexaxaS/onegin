DFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all: a.exe

a.exe: object/main.o object/onegin.o object/sort.o object/file_opener.o
	g++ object/main.o object/onegin.o object/sort.o object/file_opener.o

object/main.o: src/main.cpp
	g++ $(DFLAGS) -I./headers/ -c src/main.cpp -o object/main.o

object/quadratic.o: src/onegin.cpp
	g++ $(DFLAGS) -I./headers/ -c src/onegin.cpp -o object/onegin.o

object/tester.o: src/sort.cpp
	g++ $(DFLAGS) -I./headers/ -c src/sort.cpp -o object/sort.o

object/tools.o: src/file_opener.cpp
	g++ $(DFLAGS) -I./headers/ -c src/file_opener.cpp -o object/file_opener.o

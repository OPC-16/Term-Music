LIB = -lncurses

OBJ_FILES += \
			 src/obj/control.o \
			 src/obj/display.o \
			 src/obj/song.o \
			 src/obj/main.o	\

default: $(OBJ_FILES)
	g++ src/obj/*.o $(LIB) -o output/term-music

src/obj/control.o: src/control.cpp
	g++ -c src/control.cpp -o src/obj/control.o

src/obj/display.o: src/display.cpp
	g++ -c src/display.cpp -o src/obj/display.o

src/obj/song.o: src/song.cpp
	g++ -c src/song.cpp -o src/obj/song.o

src/obj/main.o: src/main.cpp
	g++ -c src/main.cpp -o src/obj/main.o

run: 
	@echo "--- Running Term-Music ---"
	@./output/term-music

clean:
	@echo "--- Removing all Object Files from obj/ dir ---"
	rm -r src/obj/*.o

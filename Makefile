LIB = -lncurses

OBJ_FILES += \
			 obj/control.o \
			 obj/display.o \
			 obj/song.o \
			 obj/main.o	\

default: $(OBJ_FILES)
	g++ obj/*.o $(LIB) -o ../output/term-music

obj/control.o: control.cpp
	g++ -c control.cpp -o obj/control.o

obj/display.o: display.cpp
	g++ -c display.cpp -o obj/display.o

obj/song.o: song.cpp
	g++ -c song.cpp -o obj/song.o

obj/main.o: control.cpp
	g++ -c main.cpp -o obj/main.o

run: 
	@echo "--- Running Term-Music ---"
	@./../output/term-music

clean:
	@echo "--- Removing all Object Files from obj/ dir ---"
	rm -r obj/*.o

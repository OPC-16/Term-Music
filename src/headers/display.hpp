#pragma once

#include <ncurses.h>

#include "song.hpp"

class Display {
    public:
        Display();

        ~Display();

        void initialize();

        void clear(WINDOW* win);

        void refresh(WINDOW* win);

        void displaySongs();
    private:
        void construct();

    private:
        WINDOW *songListWindow, *currentSongWindow, *timeWindow;
        Song* song = new Song("/home/omkar/Hermes");
        int yMax, xMax;
};

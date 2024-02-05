#pragma once

#include <ncurses.h>

class Display {
    public:
        Display();

        void initialize();

        void clear(WINDOW* win);

        void refresh(WINDOW* win);
    private:
        void construct();

    private:
        WINDOW *songListWindow, *currentSongWindow, *timeWindow;
        int yMax, xMax;
};

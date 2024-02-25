#pragma once

#include <vector>
#include <string>
#include <ncurses.h>

class Display {
    public:
        Display();

        // ~Display();

        void initialize();

        void clear(WINDOW* win);

        void refresh(WINDOW* win);

        void displaySongs(const std::vector<std::string>&, int);

        WINDOW* getSongListWindow();

        WINDOW* getCurrentSongWindow();

        WINDOW* getTimeWindow();

        chtype getInput();

    private:
        void construct();

    private:
        WINDOW *songListWindow, *currentSongWindow, *timeWindow;
        int yMax, xMax;
        int selectedIndex;
        std::string selectedString;
};

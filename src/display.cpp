#include "headers/display.hpp"

Display::Display() {
    getmaxyx(stdscr, this->yMax, this->xMax);
    construct();
}

void Display::initialize() {
    clear(songListWindow);
    refresh(songListWindow);

    clear(currentSongWindow);
    refresh(currentSongWindow);

    clear(timeWindow);
    refresh(timeWindow);
}

void Display::clear(WINDOW* win) {
    wclear(win);
    box(win, 0, 0);
}

void Display::refresh(WINDOW* win) {
    ::refresh();  //refresh provided by ncurses
    wrefresh(win);
}

void Display::construct() {
    songListWindow = newwin(yMax - 3, xMax, 0, 0);
    currentSongWindow = newwin(1, xMax, yMax - 3, 0);
    timeWindow = newwin(1, xMax, yMax - 2, 0);
}

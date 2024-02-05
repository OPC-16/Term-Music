#include "headers/display.hpp"

#include <string>
#include <vector>

Display::Display() {
    getmaxyx(stdscr, this->yMax, this->xMax);
    construct();
}

Display::~Display() {
    delete song;
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

void Display::displaySongs() {
    std::vector<std::string> directories = song->getDirectories();
    std::vector<std::string> songs = song->getSongs();

    clear(songListWindow);

    int i, j;
    for (i = 0; i < directories.size(); i++) {
        mvwprintw(songListWindow, i+1, 1, "%s", directories[i].c_str());
    }

    for (j = 0; j < songs.size(); j++, i++) {
        mvwprintw(songListWindow, i, 1, "%s", songs[j].c_str());
    }

    refresh(songListWindow);
}

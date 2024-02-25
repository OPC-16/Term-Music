#include "headers/display.hpp"

#include <string>
#include <vector>

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

    selectedIndex = 1;

    scrollok(songListWindow, true);
    keypad(songListWindow, true);
}

void Display::displaySongs(const std::vector<std::string>& vectorToDisplay, int yOffset) {
    for (int i = yOffset; i < vectorToDisplay.size(); i++) {
        // highlight the selected string
        // if (i == selectedIndex)
        //     wattron(songListWindow, A_REVERSE);

        mvwprintw(songListWindow, i, 1, "%s", vectorToDisplay[i].c_str());

        // turn off highlighting
        // if (i == selectedIndex)
        //     wattroff(songListWindow, A_REVERSE);
    }

    refresh(songListWindow);
}

WINDOW* Display::getSongListWindow() {
    return songListWindow;
}

WINDOW* Display::getCurrentSongWindow() {
    return currentSongWindow;
}

WINDOW* Display::getTimeWindow() {
    return timeWindow;
}

chtype Display::getInput() {
    return wgetch(songListWindow);  //wgetch also performs an addtionnal wrefresh on the specified window
}

#include <ncurses.h>

#include "headers/display.hpp"

int main() {
    initscr();
    noecho();

    Display display;
    display.initialize();
    refresh();

    getch();
    endwin();
}

#include <ncurses.h>

#include "headers/control.hpp"

int main() {
    initscr();
    refresh();
    noecho();
    curs_set(0); //hide the cursor

    Control app("/home/omkar/Hermes");
    app.updateState();
    while (!app.isAppOver()) {
        app.processInput();
        app.updateState();
        app.redraw();
    }

    endwin();
}

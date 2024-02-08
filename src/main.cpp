#include <ncurses.h>

#include "headers/display.hpp"
#include "headers/control.hpp"

int main() {
    initscr();
    refresh();
    noecho();
    curs_set(0); //hide the cursor

    // Display display;
    // display.initialize();
    // display.displaySongs();
    // refresh();

    Control app("/home/omkar/Hermes");
    app.updateState();
    while (!app.isAppOver()) {
        app.processInput();
        app.updateState();
        app.redraw();
    }

    endwin();
}

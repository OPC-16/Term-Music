#include "headers/control.hpp"
#include "headers/display.hpp"

bool Control::isAppOver() {
    return appOver;
}

void Control::updateState() {
    display.displaySongs(song->getDirectories(), 1);

    int offsetForSongs = song->getDirectories().size();
    display.displaySongs(song->getSongs(), offsetForSongs + 1);
}

void Control::processInput() {
    chtype input = display.getInput();
    switch (input) {
        case 'q':
            appOver = true;
            break;
        default:
            break;
    }
}

void Control::redraw() {
    display.refresh(display.getSongListWindow());
}

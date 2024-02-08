#pragma once

#include <ncurses.h>
#include <string>

#include "display.hpp"
#include "song.hpp"

class Control {
    public:
        Control(std::string s) {
            appOver = false;

            song = new Song(s);
            display = Display();
            display.initialize();
        }

        ~Control() {
            delete song;
        }

        void updateState();

        void processInput();

        void redraw();

        bool isAppOver();

    private:
        Display display;
        Song *song;
        bool appOver;
};

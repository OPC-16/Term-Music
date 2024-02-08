#pragma once

#include <string>
#include <vector>

class Song {
    public:
        Song(std::string);

        std::vector<std::string> getDirectories();

        std::vector<std::string> getSongs();

        std::string getCurrentSong();

        std::string getRootSongDirectory();

        void initialize();

    private:
        std::vector<std::string> songs;
        std::vector<std::string> directories;
        std::string rootSongDirectory;
        std::string currentSong;
};

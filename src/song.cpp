#include "headers/song.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>

namespace fs = std::filesystem;

Song::Song(std::string root_song_dir) {
    this->rootSongDirectory = root_song_dir;
    initialize();
}

std::vector<std::string> Song::getDirectories() {
    return directories;
}

std::vector<std::string> Song::getSongs() {
    return songs;
}

std::string Song::getCurrentSong() {
    return currentSong;
}

void Song::initialize() {
    try {
        for (const auto& entry : fs::directory_iterator(rootSongDirectory)) {
            std::string stringRepresentationOfEntry = entry.path().string();

            if (fs::is_directory(entry)) {
                if (stringRepresentationOfEntry.find(".") != std::string::npos) { //skipping hidden directories
                    continue;
                }

                stringRepresentationOfEntry.insert(stringRepresentationOfEntry.length(), "/");
                directories.emplace_back(stringRepresentationOfEntry);
            }
            else {
                songs.emplace_back(stringRepresentationOfEntry);
            }
        }

        //sorting the directories and songs alphabetically
        std::sort(directories.begin(), directories.end());
        std::sort(songs.begin(), songs.end());

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

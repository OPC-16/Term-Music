> [!WARNING]
> **Incomplete** Project

# Term-Music

It is a terminal-based music player.\
It uses [`Ncurses`](https://invisible-island.net/ncurses/announce.html) for the text based frontend, and uses [`PulseAudio`](https://www.freedesktop.org/wiki/Software/PulseAudio/) for the song playback.

The `MVC` Design Pattern is used here. 
* M = Model
* V = View
* C = Control

The *View* essentially means what the user sees and can take input from the user. Then that input is passed to the *Control* module and after processing the input the *Model* is changed. Then those changes are
reflected by the *View* module with help of *Control* module. So the core logic is implemented by the *Control* module.\
https://en.wikipedia.org/wiki/Model–view–controller

---

### Model
The `song` is responsible for maintaining the structure of the directory which contains songs. And handles the song playback logic.

### View
The `display` shows the interface to the user which contains list of songs and name of currently playing song. And it handles the input from user.

### Control
The `control` has main job of updating the state of the program, processing the user input and then redrawing the display based on that input.

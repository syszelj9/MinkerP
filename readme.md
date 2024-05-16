A lightweight bare-bones command line mp3 player made in C.

<a href="#">
    <img src="https://img.shields.io/badge/1.0-Version-Version" /></a>
<a href="#">
    <img src="https://img.shields.io/badge/1-Release-Release?logo=gitlab" /></a>

_____________
Starting out
-------------
1. Once you have built the package, simply do `./player <name of the directory where the music is stored>`
The player will immediately start playing the first song.

_____________________
KEYBINDS AND CONTROL
---------------------
1. To pause the music, press `s`. Yes, I know it says stopped but it actually just pauses it.
2. To show the progress bar, press `v`. Along with showing you the song progress. It also shows you the bitrate, speed and so on.
3. To speed the currently playing track up, press `c`.
    ________
    Looping
    --------
    - To create a loop point A, press `o` once, then press it again to create the second loop point and that loop will play.
    - To cancel the loop and continue playing the song as normal, press `o` a third time.

4. Pressing `L` shows you the current playlist/folder you are in, and the current track that is playing.
5. If the program has nothing to play, it will just exit.
6. Pressing the keys on the numpad or number row (123...0) will navigate through parts of the song.

______________
COMMON ERRORS
--------------
1. `Failed to execute mpg123` or `Fork failed`, you are missing the MPG123 package.
2. `Invalid choice, please try again`, there is something wrong with the file you are trying to play, or it just doesn't exist.
3. `Failed to open directory`, failed to open the given directory..

_____________
DEPENDENCIES
-------------
1.  mpg123

Developer's note:
-The program is quite small.
-Given it's size, there aren't many things that can go wrong.
-It's either your computer, or your brain.

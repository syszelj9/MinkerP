A lightweight bare-bones command line mp3 player made in C.

![Static Badge](https://img.shields.io/badge/1.1-Version-Version)

<a href="#">
    <img src="https://img.shields.io/badge/1-Release-Release?logo=gitlab" /></a>

## Requirements

- gcc
- mpg123

## Installation

Clone the repository and compile the program:

```bash
git clone https://github.com/syszelj9/MinkerP
cd MinkerP
sudo make
```

_____________
Starting out
-------------
1. Once you have built the package, simply do `minkerp <path of music directory>`
The player will immediately start playing the first song.

_____________________
KEYBINDS AND CONTROL
---------------------
1. To pause the music, press `S`.
2. To show the progress bar, press `V`. Along with showing you the song progress. It also shows you the bitrate, speed and so on.
3. To speed the currently playing track up, press `C`.
4. To completely stop the current song, press `Q`, and it will prompt you to enter a choice again, wether you want to play something else, or quit the program.
5. I don't rember what `M` does, but it does sum...
    ________
    Looping
    --------
    - To create a loop point A, press `o` once, then press it again to create the second loop point and that loop will play.
    - To cancel the loop and continue playing the song as normal, press `o` a third time.

6. Pressing `L` shows you the current playlist/folder you are in, and the current track that is playing.
7. If the program has nothing to play, it will just exit.
8. Pressing the keys on the numpad or number row (123...0) will navigate through parts of the song.

______________
COMMON ERRORS
--------------
1. `Failed to execute mpg123` or `Fork failed`, you are missing the MPG123 package.
2. `Invalid choice, please try again`, there is something wrong with the file you are trying to play, or it just doesn't exist.
3. `Failed to open directory`, failed to open the given directory, it is important to enter the full path of the directory and it should contain only mp3 files.

_____________
DEPENDENCIES
-------------
1.  mpg123

Developer's note:
-The program is quite small.
-Given it's size, there aren't many things that can go wrong.
-It's either your computer, or your brain.

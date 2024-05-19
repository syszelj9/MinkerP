all:
	gcc -o player mplayer.c
	sudo cp player /usr/bin/minkerp

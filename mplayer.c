#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ioctl.h>

void play_mp3(char *filename) {
    pid_t pid = fork();
    if (pid == 0) {
        execlp("mpg123", "mpg123", "-q", filename, NULL);
        perror("Failed to execute mpg123");
        exit(1);
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        waitpid(pid, NULL, 0);
    }
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen and move cursor to home position
}

void hide_cursor() {
    printf("\033[?25l"); // ANSI escape code to hide the cursor
}

void show_cursor() {
    printf("\033[?25h"); // ANSI escape code to show the cursor
}

void print_logo() {
    clear_screen();
    printf("\n");
    printf("  __  __ _       _            ____  \n");
    printf(" |  \\/  (_)_ __ | | _____ _ __|  _ \\ \n");
    printf(" | |\\/| | | '_ \\| |/ / _ \\ '__| |_) |\n");
    printf(" | |  | | | | | |   <  __/ |  |  __/ \n");
    printf(" |_|  |_|_|_| |_|_|\\_\\___|_|  |_|    \n");
    printf("-------------------------------------\n");
}

void display_menu() {
    printf("\n");
    printf("Menu:\n");
    printf("1. Play next song\n");
    printf("2. Quit\n");
    printf("3. Search and play a specific song\n");
}

void search_and_play(char *directory) {
    char song_name[256];
    printf("Enter the name of the song to search and play: ");
    scanf("%s", song_name);

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(directory)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, song_name) != NULL && strstr(ent->d_name, ".mp3") != NULL) {
                char path[256];
                snprintf(path, sizeof(path), "%s/%s", directory, ent->d_name);
                printf("Playing: %s\n", ent->d_name);
                play_mp3(path);
                closedir(dir);
                return;
            }
        }
        printf("Song '%s' not found in the directory.\n", song_name);
        closedir(dir);
    } else {
        perror("Failed to open directory");
    }
}

void handle_choice(int choice, char *directory, DIR *dir) {
    switch (choice) {
        case 1:
            break; // Continue to play the next song
        case 2:
            printf("Quitting the player...\n");
            if (dir != NULL) {
                closedir(dir);
            }
            show_cursor();
            exit(0);
        case 3:
            search_and_play(directory);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    hide_cursor();
    print_logo();
    display_menu();

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(argv[1])) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".mp3") != NULL) {
                char path[256];
                snprintf(path, sizeof(path), "%s/%s", argv[1], ent->d_name);
                printf("Playing: %s\n", ent->d_name);
                play_mp3(path);

                // Display menu
                int choice;
                do {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    clear_screen();
                    print_logo();
                    display_menu();
                    handle_choice(choice, argv[1], dir);
                } while (choice != 1);
            }
        }
        closedir(dir);
    } else {
        perror("Failed to open directory");
        show_cursor();
        return 1;
    }

    printf("No more songs to play. Exiting...\n");
    show_cursor();

    return 0;
}


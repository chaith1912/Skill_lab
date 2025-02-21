#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a song node
typedef struct Song {
    char name[100];
    struct Song *next;
} Song;

Song *head = NULL, *current = NULL;

// Function to add a song to the playlist
void addSong() {
    Song *newSong = (Song *)malloc(sizeof(Song));
    if (!newSong) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter song name: ");
    scanf(" %[^\n]", newSong->name); // Read string with spaces
    newSong->next = head; // Point to head to maintain circular structure

    if (head == NULL) {
        head = newSong;
        newSong->next = head;
    } else {
        Song *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newSong;
    }
    
    if (current == NULL) current = head;

    printf("Song Added: %s\n", newSong->name);
}

// Function to play the next song
void nextSong() {
    if (current == NULL) {
        printf("Playlist is empty! Add songs first.\n");
        return;
    }
    printf("Next Song: %s\n", current->name);
    current = current->next;
}

// Function to display the currently playing song
void currentSong() {
    if (current == NULL) {
        printf("No song is playing. Add songs to the playlist.\n");
        return;
    }
    printf("Current Song: %s\n", current->name);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n1. Add Song\n2. Play Next Song\n3. Show Current Song\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(); break;
            case 2: nextSong(); break;
            case 3: currentSong(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
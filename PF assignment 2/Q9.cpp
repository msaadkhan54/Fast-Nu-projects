#include <stdio.h>

int main() {
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerRow, playerCol;
    int collectedItems = 0;
    char move;

    // Find player position
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 'P') {
                playerRow = i;
                playerCol = j;
                break;
            }
        }
    }

    while (1) {
        // Show grid
        for (int i = 0; i < 5; i++) {
        	printf("|");
            for (int j = 0; j < 5; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("|");
            printf("\n");
        }

        printf("Enter your move ('W' for up, 'S' for down, 'A' for left, 'D' for right, 'Q' for quit): ");
        scanf(" %c", &move);
        if (move == 'Q') {
            printf("Thank you:)\n");
            break;
        }

        int newRow = playerRow;
        int newCol = playerCol;

        if (move == 'W') {
            newRow--;
        } else if (move == 'S') {
            newRow++;
        } else if (move == 'A') {
            newCol--;
        } else if (move == 'D') {
            newCol++;
        } else {
            printf("Invalid input:(\n");
            continue;
        }

        if (newRow < 0 || newRow >= 5 || newCol < 0 || newCol >= 5) {
            printf("Invalid move:(\n");
            continue;
        }


        if (grid[newRow][newCol] == 'X') {
            printf("Invalid move:(\n");
            continue;
        }

        if (grid[newRow][newCol] == 'I') {
            collectedItems++;
            printf("Congrats! You collected an item:)\nTotal items collected: %d\n", collectedItems);
        }

        grid[playerRow][playerCol] = ' ';
        grid[newRow][newCol] = 'P';
        playerRow = newRow;
        playerCol = newCol;
    }

    return 0;
}


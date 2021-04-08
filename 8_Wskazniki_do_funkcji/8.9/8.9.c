#include <stdio.h>
#include <stdlib.h>
#include "board.h"
// #include "board.c"

int main() {
    struct board_t* board;
    printf("Enter width and height of the board: ");
    int width, heigth;
    if (scanf("%d %d", &width, &heigth) != 2) {
        printf("Incorrect input");
        return 1;
    }
    if (width <= 0 || heigth <= 0) {
        printf("Incorrect input data");
        return 2;
    }
    if (create_board(&board, width, heigth) == 2) {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter player's initial coordinates (x, y): ");
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Incorrect input");
        free_board(board);
        return 1;
    }
    if (x < 0 || y < 0 || x > width - 1 || y > heigth - 1) {
        printf("Incorrect input data");
        free_board(board);
        return 2;
    }
    set_player(board, x, y);
    

    while (getchar() != '\n');
    display_board(board);
    
    char action = 'w';
    while (action != 'q') {
        
        printf("Choose your action");
        if (!scanf("%c", &action)) {
            printf("Incorrect choice\n");
            continue;
        }
        while (getchar() != '\n');
        if (action == 'q') { break; }

        if (action != 'w' && action != 'a' && action != 's' && action != 'd') {
            printf("Incorrect choice\n");
            continue;
        }
        switch (action) {
        case 'w':
            board->move_player_up(board);
            break;

        case 's':
            board->move_player_down(board);
            break;

        case 'a':
            board->move_player_left(board);
            break;

        case 'd':
            board->move_player_right(board);
            break;

        default:
            printf("How?!?!?");
        }

        display_board(board);
    }

    free_board(board);
    return 0;
}


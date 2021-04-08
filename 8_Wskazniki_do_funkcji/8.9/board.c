#include "board.h"

int create_board(struct board_t** board, int width, int height) {
    if (board == NULL || width <= 0 || height <= 0) return 1;
    *board = malloc(sizeof(struct board_t));
    if (*board == NULL) return 2;
    (*board)->board = (char**)malloc(height * sizeof(char*));
    if ((*board)->board == NULL) { free(*board); return 2; }
    for (int i = 0; i < height; i++) {
        *((*board)->board + i) = (char*)malloc((width + 1) * sizeof(char));
        if (*((*board)->board + i) == NULL) {
            for (int j = 0; j < i; j++) free(*((*board)->board + j));
            free((*board)->board);
            free(*board);
            return 2;
        }
        for (int j = 0; j < width; j++) { *(*((*board)->board + i) + j) = '.'; }
        *(*((*board)->board + i) + width) = '\0';
    }
    (*board)->height = height;
    (*board)->width = width;
    (*board)->is_init = 0;
    (*board)->move_player_down = move_player_down;
    (*board)->move_player_up = move_player_up;
    (*board)->move_player_left = move_player_left;
    (*board)->move_player_right = move_player_right;
    return 0;
}
void display_board(const struct board_t* board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            printf("%c", *(*(board->board + i) + j));
        }
        printf("\n");
    }
}
void free_board(struct board_t* board) {
    if (board == NULL || board->height <= 0 || board->width <= 0 || board->board == NULL) return;
    for (int i = 0; i < board->height; i++) { if (*(board->board + i) != NULL) free(*(board->board + i)); }
    if (board->board != NULL) free(board->board);
    free(board);
}
int set_player(struct board_t* board, int x, int y) {
    if (board == NULL || board->is_init == 1 || board->height <= 0 || board->width <= 0 || x > board->width-1 || y > board->height-1 || x < 0 || y < 0 || board->board == NULL) return 1;
    
    *(*((board->board) + y) + x) = '@';
    (board->player).x = x;
    (board->player).y = y;
    board->is_init = 1;
    return 0;
}

struct board_t* move_player_up(struct board_t* board) {
    if (board == NULL || board->board == NULL || board->is_init == 0 || board->width <= 0 || board->height <= 0 || board->player.x < 0 || board->player.y < 0) return NULL;
    if (board->player.x > (board->width - 1) || board->player.y > (board->height - 1)) return NULL;
    int player_x = board->player.x;
    int player_y = board->player.y;
    *(*((board->board) + player_y) + player_x) = '.';
    if (player_y == 0) {
        board->player.y = ((board->height) - 1);
        player_y = board->player.y;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    else {
        board->player.y = player_y - 1;
        player_y = board->player.y;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    return board;
}
struct board_t* move_player_down(struct board_t* board) {
    if (board == NULL || board->board == NULL || board->is_init == 0 || board->width <= 0 || board->height <= 0 || board->player.x < 0 || board->player.y < 0) return NULL;
    if (board->player.x > (board->width - 1) || board->player.y > (board->height - 1)) return NULL;
    int player_x = board->player.x;
    int player_y = board->player.y;
    *(*((board->board) + player_y) + player_x) = '.';
    if (player_y == ((board->height) - 1)) {
        board->player.y = 0;
        player_y = board->player.y;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    else {
        board->player.y = player_y + 1;
        player_y = board->player.y;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    return board;
}
struct board_t* move_player_left(struct board_t* board) {
    if (board == NULL || board->board == NULL || board->is_init == 0 || board->width <= 0 || board->height <= 0 || board->player.x < 0 || board->player.y < 0) return NULL;
    if (board->player.x > (board->width - 1) || board->player.y > (board->height - 1)) return NULL;

    int player_x = board->player.x;
    int player_y = board->player.y;
    *(*((board->board) + player_y) + player_x) = '.';

    if (player_x == 0) {
        board->player.x = ((board->width) - 1);
        player_x = board->player.x;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    else {
        board->player.x = player_x - 1;
        player_x = board->player.x;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    return board;
}
struct board_t* move_player_right(struct board_t* board) {
    if (board == NULL || board->board == NULL || board->is_init == 0 || board->width <= 0 || board->height <= 0 || board->player.x < 0 || board->player.y < 0) return NULL;
    if (board->player.x > (board->width - 1) || board->player.y > (board->height - 1)) return NULL;

    int player_x = board->player.x;
    int player_y = board->player.y;
    *(*((board->board) + player_y) + player_x) = '.';

    if (player_x == ((board->width) - 1)) {
        board->player.x = 0;
        player_x = board->player.x;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    else {
        board->player.x = player_x + 1;
        player_x = board->player.x;
        *(*((board->board) + player_y) + player_x) = '@';
    }
    return board;
}
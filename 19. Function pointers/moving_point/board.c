#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


int create_board(struct board_t **board, int width,int height)
{
    if(board == NULL || width <= 0 || height <= 0)
        return 1;
    *board = calloc(1, sizeof(struct board_t));
    if(*board == NULL)
        return 2;
    (*board)->height = height;
    (*board)->width = width;
    (*board)->is_init = 0;
    ((*board)->board) = calloc(height, sizeof(char*));
    if(((*board)->board) == NULL)
    {
        free(*board);
        return 2;
    }
    for(int i = 0; i < height; i++)
    {
        *((*board)->board+i) = calloc(width+1, sizeof(char));
        if(*((*board)->board+i) == NULL)
        {
            for(int g = i-1; g >= 0; g--)
                free(*((*board)->board+g));
            free((*board)->board);
            free(*board);
            return 2;
        }
    }
    int i, j;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            *(*((*board)->board+i)+j) = '.';
        }
        *(*((*board)->board+i)+j) = '\0';
    }
    (*board)->move_player_down = &move_player_down;
    (*board)->move_player_up = &move_player_up;
    (*board)->move_player_right = &move_player_right;
    (*board)->move_player_left = &move_player_left;
    return 0;

}
void display_board(const struct board_t *board)
{
    if(board == NULL || board->height <= 0 || board->width <= 0
    || board->board == NULL)
        return;
    for(int i = 0; i < board->height; i++)
    {
        for(int j = 0; j < board->width; j++)
        {
            printf("%c", *(*(board->board+i)+j));
        }
        printf("\n");
    }
}
void free_board(struct board_t *board)
{
    if(board == NULL || board->board == NULL || board->width <= 0 ||
    board->height <= 0)
        return;
    for(int i = 0; i < board->height; i++)
    {
        free(*(board->board+i));
    }
    free(board->board);
    free(board);
}
int set_player(struct board_t *board, int x, int y)
{
    if(board == NULL || board->board == NULL || board->height <= 0
    || board->width <= 0 || x < 0 || y < 0 || x >= board->width || y >= board->height || board->is_init == 1)
        return 1;
    *(*(board->board+y)+x) = '@';
    board->is_init = 1;
    board->player.x = x;
    board->player.y = y;
    return 0;
}

struct board_t* move_player_up(struct board_t* board)
{
    if (board == NULL || board -> board == NULL|| !board->is_init || board->player.y < 0 || board->player.y >= board->height ||
            board->player.x < 0 || board->player.x >= board->width) {
        return NULL;
    }
    *(*(board->board+(board->player.y))+(board->player.x)) = '.';
    board->player.y = (board->player.y - 1 + board->height)%board->height;
    *(*(board->board+(board->player.y))+(board->player.x)) = '@';
    return board;
}
struct board_t* move_player_down(struct board_t* board)
{
    if (board == NULL || board -> board == NULL|| !board->is_init || board->player.y < 0 || board->player.y >= board->height ||
        board->player.x < 0 || board->player.x >= board->width) {
        return NULL;
    }
    *(*(board->board+(board->player.y))+(board->player.x)) = '.';
    board->player.y = (board->player.y + 1)%board->height;
    *(*(board->board+(board->player.y))+(board->player.x)) = '@';
    return board;
}
struct board_t* move_player_left(struct board_t* board)
{
    if (board == NULL || board -> board == NULL|| !board->is_init || board->player.y < 0 || board->player.y >= board->height ||
        board->player.x < 0 || board->player.x >= board->width) {
        return NULL;
    }
    *(*(board->board+(board->player.y))+(board->player.x)) = '.';
    board->player.x = (board->player.x - 1 + board->width)%board->width;
    *(*(board->board+(board->player.y))+(board->player.x)) = '@';
    return board;
}
struct board_t* move_player_right(struct board_t* board)
{
    if (board == NULL || board -> board == NULL|| !board->is_init || board->player.y < 0 || board->player.y >= board->height ||
        board->player.x < 0 || board->player.x >= board->width) {
        return NULL;
    }
    *(*(board->board+(board->player.y))+(board->player.x)) = '.';
    board->player.x = (board->player.x + 1)%board->width;
    *(*(board->board+(board->player.y))+(board->player.x)) = '@';
    return board;
}





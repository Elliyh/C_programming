#include <stdio.h>
#include "board.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int main() {
    printf("Enter width and height of the board:");
    int width, height;
    if(scanf("%d %d", &width, &height)!= 2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(width <= 0 || height <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }


    struct board_t* board;
    int prov = create_board(&board, width, height);
    if(prov == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }


    printf("Enter player's initial coordinates (x, y):");
    int x, y;
    if(scanf("%d %d", &x, &y)!= 2)
    {
        printf("Incorrect input");
        free_board(board);
        return 1;
    }
    if(x < 0 || y < 0 || x >= width || y >= height)
    {
        printf("Incorrect input data");
        free_board(board);
        return 2;
    }
    set_player(board, x ,y);
    display_board(board);
    char c;
    /*board->move_player_down = &move_player_down;
    board->move_player_up = &move_player_up;
    board->move_player_right = &move_player_right;
    board->move_player_left = &move_player_left;*/
    while(1)
    {
        printf("Choose your action:");
        getchar();
        scanf("%c", &c);
        if(c == 'q')
            break;
        if(c != 'w' && c != 'a' && c != 's' && c != 'd')
        {
            printf("Incorrect choice\n");
            continue;
        }


        switch (c)
        {
            case 'w':
                board->move_player_up(board);
                break;
            case 'a':
                board->move_player_left(board);
                break;
            case 's':
                board->move_player_down(board);
                break;
            case 'd':
                board->move_player_right(board);
                break;
            default:
                printf("Incorrect choice\n");
        }
        display_board(board);
    }
    free_board(board);
    return 0;
}



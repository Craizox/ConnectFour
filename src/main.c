#include <stdio.h>
#include "board.h"
#include "check_win.h"


static int ask_player_mov(char **board, char player)
{
    char *buf;
    scanf("%ms", &buf);
    return put_char_in_board(board, player, buf);
}

static void ask_player_name(char **p1, char **p2)
{
    printf("Name of player 1: ");
    scanf("%ms", p1);
    printf("Name of player 2: ");
    scanf("%ms", p2);
}


int main(void)
{
    char *player1;
    char *player2;
    ask_player_name(&player1, &player2);
    char **board = board_init();
    board_print(board);
    int turn_play = 0;
    int win_p1 = 0, win_p2 = 0, full = 0;
    while(!(win_p1 = check_win(board, 'o')) && !(win_p2 = check_win(board, 'x'))
            && !(full = check_full(board)))
    {
        if (turn_play % 2 == 0)
        {
            printf("Turn of %s: ", player1);
            if (ask_player_mov(board, 'o'))
            {
                board_print(board);
                turn_play++;
            }
        }
        else
        {
            printf("Turn of %s: ", player2);
            if (ask_player_mov(board, 'x'))
            {
                board_print(board);
                turn_play++;
            }
        }

    }
    return 0;
}

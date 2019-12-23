#include <stdio.h>
#include "board.h"
#include "check_win.h"
#include <stdlib.h>

static int ask_player_mov(char **board, char player)
{
    char *buf;
    scanf("%ms", &buf);
    int res = put_char_in_board(board, player, buf);
    free(buf);
    return res;
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
    int turn_play = 0;
    int win_p1 = 0, win_p2 = 0, full = 0;
    int play = 1;
    while (play)
    {
        char *player1;
        char *player2;
        ask_player_name(&player1, &player2);
        char **board = board_init();
        board_print(board);
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
        if (win_p1)
            printf("%s WON\n", player1);
        if (win_p2)
            printf("%s WON\n", player2);
        if (full)
            printf("EGALITY\n");

        printf("Do you want to play again [Y/n] ? ");
        char *buf;
        scanf("%ms", &buf);
        if (buf[0] == 'Y' || buf[0] == 'y')
            play = 1;
        else
            play = 0;
        free(buf);
        free(player1);
        free(player2);

    board_free(board);
    }
    return 0;
}

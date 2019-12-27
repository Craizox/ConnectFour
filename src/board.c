#include "board.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **board_init(void)
{
    char **board = calloc(6, sizeof(char *));
    for (int i = 0; i < 6; i++)
    {
        board[i] = calloc(7, sizeof(char));
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = ' '; //32 white space
        }
    }
    return board;
}

static int check_if_set(char **board, char player, int col)
{
    for (int i = 5; i >= 0; i--)
    {
        if (board[i][col] == ' ')
        {
            board[i][col] = player;
            return 1;
        }
    }
    printf("There is no more space in this column\n");
    return 0;
}

static int check_input(char *input)
{
    if (strlen(input) != 1)
    {
        printf("Please choose a column between A and G\n");
        return 0;
    }
    if ((*input < 'a' || *input > 'g') && (*input < 'A' || *input > 'G'))
    {
        printf("Please choose a column between A and G\n");
        return 0;
    }
    return 1;
}

static int char_to_int(char c)
{
    switch (c)
    {
    case 'a':
        return 0;
    case 'A':
        return 0;
    case 'b':
        return 1;
    case 'B':
        return 1;
    case 'c':
        return 2;
    case 'C':
        return 2;
    case 'd':
        return 3;
    case 'D':
        return 3;
    case 'e':
        return 4;
    case 'E':
        return 4;
    case 'f':
        return 5;
    case 'F':
        return 5;
    case 'g':
        return 6;
    case 'G':
        return 6;
    default:
        return -1;
    }
}


int put_char_in_board(char **board, char player, char *input)
{
    if (check_input(input))
        return check_if_set(board, player, char_to_int(*input));
    return 0;
}

int check_full(char **board)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void board_print(char **board)
{
    printf("     A   B   C   D   E   F   G\n");
    for (int i = 0; i < 6; i++)
    {
        printf("    ---------------------------\n");
        for (int j = 0; j < 7; j++)
        {
            if (j == 0)
            {
                if (board[i][j] == 'o')
                    printf(" %d | \033[34;1m%c\033[00m |", i, board[i][j]);
                else if ( board[i][j] == 'x')
                    printf(" %d | \033[31;1m%c\033[00m |", i, board[i][j]);
                else
                    printf(" %d | \033[34;1m%c\033[00m |", i, board[i][j]);

            }
            else
            {
                if (board[i][j] == 'o')
                    printf(" \033[34;1m%c\033[00m |", board[i][j]);
                else if ( board[i][j] == 'x')
                    printf(" \033[31;1m%c\033[00m |", board[i][j]);
                else
                    printf(" %c |", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("    ---------------------------\n");
    printf("\n");
}

void board_free(char **board)
{
    for (int i = 0; i < 6; i++)
    {
        free(board[i]);
    }
    free(board);
}

#include "check_win.h"
#include <stdio.h>
static int check_ldiag(char **board, char player, int line, int col)
{
    int win = 0;
    for (; line >= 0 && col < 7; line--, col++)
    {
        if (win == 4)
            return 1;
        if (board[line][col] != player)
            return 0;
        else
            win++;
        if (win == 4)
            return 1;
    }
    return 0;
}


static int check_rdiag(char **board, char player, int line, int col)
{
    int win = 0;
    for (; line < 6 && col < 7; line++, col++)
    {
        if (win == 4)
            return 1;
        if (board[line][col] != player)
            return 0;
        else
            win++;
        if (win == 4)
            return 1;
    }
    return 0;
}


static int check_line(char **board, char player, int line, int col)
{
    int win = 0;
    for (; col < 7; col++)
    {
        if (win == 4)
            return 1;
        if (board[line][col] != player)
            return 0;
        else
            win++;
        if (win == 4)
            return 1;
    }
    return 0;
}


static int check_col(char **board, char player, int line, int col)
{
    int win = 0;
    for (; line < 6; line++)
    {
        if (win == 4)
            return 1;
        if (board[line][col] != player)
            return 0;
        else
            win++;
        if (win == 4)
            return 1;
    }
    return 0;
}

int check_win(char **board, char player)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == player)
            {
                if (check_ldiag(board, player, i, j) || check_rdiag(board, player, i, j))
                    return 1;
                if (check_line(board, player, i, j) || check_col(board, player, i, j))
                    return 1;
            }
        }
    }
    return 0;
}

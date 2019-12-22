#ifndef BOARD_H
#define BOARD_H

/**
** \brief function that initilized the board
**
** \return the newly alloacted board
*/
char **board_init(void);

/**
** \brief funtio that free all the memory used by the board
**
** \param board: board to be freed
*/
void board_free(char **board);

/**
** \brief function that check if the board is full
**
** \param board: board to be checked
**
** \return 1 if the board is full, 0 otherwise
*/
int check_full(char **board);

/**
** \brief function that put the character of the corresponding player in the right place
**
** \param board: Where the character shall be placed
** \param player: Character corresponging to the player
** \param input: where the user wants to puts the character
**
** \return 1 on success, 0 otherwise
*/
int put_char_in_board(char **board, char player, char *input);

/**
** \brief function that print the board
**
** \param board: board to be printed
*/
void board_print(char **board);

#endif /* !BOARD_H */

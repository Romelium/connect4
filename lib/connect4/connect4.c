#include "connect4.h"
#include <stdio.h>

/**
 * @brief Prints the connect4 board on the console.
 *
 * @param connect4 The connect4 that will be printed.
 */
void connect4_print(const struct Connect4 *connect4)
{
    // Reverse loop cause we want y index 0 to be ground
    for (size_t y = CONNECT4_HEIGHT; y-- > 0;)
    {
        for (size_t x = 0; x < CONNECT4_WIDTH; x++)
        {
            char tile;

            switch (connect4->board[x][y])
            {
            case empty:
                tile = '_';
                break;
            case player1:
                tile = 'X';
                break;
            case player2:
                tile = 'O';
                break;
            }
            printf("%c", tile);
        }
        printf("\n");
    }
}
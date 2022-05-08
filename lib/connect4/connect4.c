#include "connect4.h"
#include <stdio.h>
#include <assert.h>

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
            case tile_empty:
                tile = '_';
                break;
            case tile_player1:
                tile = 'X';
                break;
            case tile_player2:
                tile = 'O';
                break;
            }
            printf("%c", tile);
        }
        printf("\n");
    }
}

void connect4_drop(struct Connect4 *connect4, const size_t drop_position, const bool switch_turn)
{
    // This stops the program from running any further and issues.
    assert(drop_position < CONNECT4_WIDTH && "You are exceeding the number of columns in the board.");

    for (size_t y = 0; y < CONNECT4_HEIGHT; y++)
    {
        // Check if current tile is empty.
        if (connect4->board[drop_position][y] == tile_empty)
        {
            // Add current player to the current tile.
            connect4->board[drop_position][y] = connect4->turn ? tile_player1 : tile_player2;

            // Automatically switches the player's turn.
            if (switch_turn)
                connect4->turn = !connect4->turn;

            // End the function
            return;
        }
    }
}
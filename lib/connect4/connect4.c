#include "connect4.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

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
            connect4->board[drop_position][y] = connect4->turn ? tile_player2 : tile_player1;

            // Automatically switches the player's turn.
            if (switch_turn)
                connect4->turn = !connect4->turn;

            // End the function
            return;
        }
    }
}

bool connect4_check_win_player(const struct Connect4 *connect4, enum Tile player)
{
    // Check for horizonal wins
    for (size_t x = 0; x < CONNECT4_WIDTH - 3; x++)
    {
        for (size_t y = 0; y < CONNECT4_HEIGHT; y++)
        {
            if (connect4->board[x][y] == player && connect4->board[x + 1][y] == player && connect4->board[x + 2][y] == player && connect4->board[x + 3][y] == player)
            {
                return true;
            }
        }
    }
    // Check for vertical wins
    for (size_t x = 0; x < CONNECT4_WIDTH; x++)
    {
        for (size_t y = 0; y < CONNECT4_HEIGHT - 3; y++)
        {
            if (connect4->board[x][y] == player && connect4->board[x][y + 1] == player && connect4->board[x][y + 2] == player && connect4->board[x][y + 3] == player)
            {
                return true;
            }
        }
    }

    // Check for diagonal wins
    for (size_t x = 0; x < CONNECT4_WIDTH - 3; x++)
    {
        for (size_t y = 0; y < CONNECT4_HEIGHT - 3; y++)
        {
            if (
                connect4->board[x][y] == player && connect4->board[x + 1][y + 1] == player && connect4->board[x + 2][y + 2] == player && connect4->board[x + 3][y + 3] == player ||
                connect4->board[x][y + 3] == player && connect4->board[x + 1][y + 2] == player && connect4->board[x + 2][y + 1] == player && connect4->board[x + 3][y] == player)
            {
                return true;
            }
        }
    }
    return false;
}

bool connect4_check_win_draw(const struct Connect4 *connect4)
{
    for (size_t x = 0; x < CONNECT4_WIDTH; x++)
    {
        if (connect4->board[x][CONNECT4_HEIGHT - 1] == tile_empty)
        {
            return false;
        }
    }
    return true;
}

enum Winner
connect4_check_win(const struct Connect4 *connect4)
{
    if (connect4_check_win_player(connect4, tile_player1))
    {
        return winner_player1;
    }
    else if (connect4_check_win_player(connect4, tile_player2))
    {
        return winner_player2;
    }
    else if (connect4_check_win_draw(connect4))
    {
        return winner_draw;
    }
    return winner_none;
}

int search(const struct Connect4 *connect4, const size_t depth)
{
    switch (connect4_check_win(connect4))
    {
    case winner_player1:
        return 1;
    case winner_player2:
        return -1;
    case winner_draw:
        return 0;
    }
    if (depth > 0)
    {
        // size_t best_move = 0;                                // Which move will be output
        int best_score = connect4->turn ? INT_MAX : INT_MIN; // The score of the best_move

        for (size_t i = 0; i < CONNECT4_WIDTH; i++)
        {
            // Skip if the current column is filled
            if (connect4->board[i][CONNECT4_HEIGHT - 1] != tile_empty)
                continue;

            struct Connect4 connect4_search = *connect4; // copy the connect4 struct
            connect4_drop(&connect4_search, i, true);    // drops a tile on the copied connect4 struct

            int score = search(&connect4_search, depth - 1); // search the possible moves tree for the score

            if (connect4->turn && score < best_score ||
                !connect4->turn && score > best_score)
            {
                best_score = score;
                // best_move = i;
            }
        }
        // return best_move;
        return best_score;
    }
    return 0;
}

size_t search_best_move(const struct Connect4 *connect4, const size_t depth)
{
    size_t best_move = 0;                                // Which move will be output
    int best_score = connect4->turn ? INT_MAX : INT_MIN; // The score of the best_move

    for (size_t i = 0; i < CONNECT4_WIDTH; i++)
    {
        // Skip if the current column is filled
        if (connect4->board[i][CONNECT4_HEIGHT - 1] != tile_empty)
            continue;

        struct Connect4 connect4_search = *connect4; // copy the connect4 struct
        connect4_drop(&connect4_search, i, true);    // drops a tile on the copied connect4 struct

        int score = search(&connect4_search, depth); // search the possible moves tree for the score

        if (connect4->turn && score < best_score ||
            !connect4->turn && score > best_score)
        {
            best_score = score;
            best_move = i;
        }
    }
    return best_move;
}
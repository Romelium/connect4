#ifndef CONNECT4_H
#define CONNECT4_H

#include <stddef.h>
#include <stdbool.h>

#define CONNECT4_WIDTH 7
#define CONNECT4_HEIGHT 6

struct Connect4
{
    /**
     * @brief The Connect4 board. Tells you which tile is connected to what player or empty.
     */
    enum Tile
    {
        tile_empty,
        tile_player1,
        tile_player2
    } board[CONNECT4_WIDTH][CONNECT4_HEIGHT];

    /**
     * @brief Which player is in turn. False is player1 and True is player2.
     */
    bool turn;
};

/**
 * @brief Prints the connect4 board on the console.
 *
 * @param connect4 The connect4 that will be printed.
 */
void connect4_print(const struct Connect4 *connect4);
/**
 * @brief Add a tile on the highest empty point at the selected row of the Connect4 struct.
 *
 * @param connect4 The Connect4 struct that a tile will be dropped on.
 * @param drop_position Which row the tile will be dropped on.
 * @param switch_turn Automatically switches the player's turn.
 */
void connect4_drop(struct Connect4 *connect4, const size_t drop_position, const bool switch_turn);

enum Winner
{
    winner_none,
    winner_player1,
    winner_player2,
    winner_draw,
} connect4_check_win(const struct Connect4 *connect4);

/**
 * @brief Search the possible moves tree for the best score.
 *
 * @param depth How far to search in the possible moves tree.
 * @param connect4 Search for the current player best score.
 * @return The best score
 */
int search(const struct Connect4 *connect4, const size_t depth);

/**
 * @brief Search the possible moves tree for the best move.
 *
 * @param depth How far to search in the possible moves tree.
 * @param connect4 Search for the current player best move.
 * @return The best move
 */
size_t search_best_move(const struct Connect4 *connect4, const size_t depth);

#endif
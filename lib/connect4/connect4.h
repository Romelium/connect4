#ifndef CONNECT4_H
#define CONNECT4_H

#include <stddef.h>
#include <stdbool.h>

#define CONNECT4_WIDTH 7
#define CONNECT4_HEIGHT 6

struct Connect4
{
    // The Connect 4 board grid
    enum Tile
    {
        empty,
        player1,
        player2
    } board[CONNECT4_WIDTH][CONNECT4_HEIGHT];

    // Which player is in turn
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
#endif
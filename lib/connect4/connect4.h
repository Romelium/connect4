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

#endif
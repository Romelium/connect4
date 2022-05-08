#include <stdio.h>
#include "connect4.h"

int main()
{
    struct Connect4 connect4 = {.board = {0}, .turn = false};

    connect4_drop(&connect4, 0, true);
    connect4_drop(&connect4, 5, true);
    connect4_drop(&connect4, 2, true);
    connect4_drop(&connect4, 2, true);
    connect4_drop(&connect4, 2, true);
    connect4_drop(&connect4, 0, true);
    connect4_print(&connect4);
    return 0;
}

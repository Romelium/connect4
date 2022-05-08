#include <stdio.h>
#include "connect4.h"

int main()
{
    struct Connect4 connect4 = {.board = {0}, .turn = false};
    connect4_print(&connect4);
    return 0;
}

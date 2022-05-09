#include <stdio.h>
#include "connect4.h"

int main()
{
    struct Connect4 connect4 = {.board = {0}, .turn = false};
    connect4_print(&connect4);

    while (1)
    {
        int input;
        scanf("%d", &input);

        connect4_drop(&connect4, input, true);
        connect4_print(&connect4);

        switch (connect4_check_win(&connect4))
        {
        case winner_player1:
            printf("winner: player 1!\n");
            goto end;
        case winner_player2:
            printf("winner: player 2!\n");
            goto end;
        case winner_draw:
            printf("DRAW!\n");
            goto end;
        }
    }
end:
    return 0;
}

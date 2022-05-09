#include <stdio.h>
#include "connect4.h"
#include <time.h>

int main()
{
    struct Connect4 connect4 = {.board = {0}, .turn = false};
    connect4_print(&connect4);

    while (1)
    {
        clock_t start = clock();
        int input;
        scanf("%d", &input);

        connect4_drop(&connect4, input, true);

        clock_t end = clock();

        float time_taken = (float)(end - start) / CLOCKS_PER_SEC;

        printf("\n");
        connect4_print(&connect4);
        printf("Time Taken: %.6f\n", time_taken);

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

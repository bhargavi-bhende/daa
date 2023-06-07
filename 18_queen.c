#include <stdio.h>
#include <stdbool.h>

#define N 4

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check if there is a queen in the same row on the left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(int board[N][N], int col)
{
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing a queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        // Check if the queen can be placed on the board[i][col]
        if (isSafe(board, i, col))
        {
            // Place the queen in the current position
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1))
                return true;

            // If placing the queen in board[i][col] doesn't lead to a solution, remove the queen from the current position
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int board[N][N] = {0};

    if (solveNQueens(board, 0))
    {
        printf("Solution found:\n");
        printBoard(board);
    }
    else
    {
        printf("Solution not found for N = %d\n", N);
    }

    return 0;
}

#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main(int argc, char* argv[])
{
    int ** puzzle;
    int progress;

   // if(argc != 1){
    //   printf("arguments are passed in.\n");
      puzzle = createPuzzle(argc, argv);
  //  }
  //  else{
  //   printf("There are 0 arguments passed in.\n");
  //    puzzle = createPuzzle2();
  //  }
    printf("setting up sudoku\n");
    Sudoku * sudoku;

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    while (UNSOLVED > 0)
    {
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);

        if (progress == 0)
        {
            printf("\nFailed to solve the puzzle!\n\n");

            break;
        }
    }

    printPuzzle(sudoku->squares);

    return 0;
}

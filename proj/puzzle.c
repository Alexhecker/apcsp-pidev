#include "sudoku.h"
#include <ctype.h> 
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define MAXINPUT 100 


Sudoku * createSudoku(Square *** squares, Box ** boxes)
{
    Sudoku * sudoku;
    sudoku = malloc(sizeof(Sudoku));

    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;
}

/* Sudoku * setUpPuzzle(int ** puzzle) 
 *
 * Initial puzzle creation
 */
Sudoku * setUpPuzzle(int ** puzzle)
{
    Square *** sudoku;
    Box ** boxes;
    int i, j, x;
    int currentBox = 0;

    sudoku = (Square***)malloc(sizeof(Square**)*9);
    boxes = createBoxes();

    /* loop through rows */
    for (i = 0; i < SIZE_ROWS; i++)
    {
        /* malloc space for each row */
        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);

        /* loop through columns */
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            /* malloc space for each square */
            sudoku[i][j] = (Square*)malloc(sizeof(Square)*9);

            /* assign number to sudoke adt */
            sudoku[i][j]->number = puzzle[i][j];

            /* assign row and column numbers to each square */
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solvable = 9;

            boxes[currentBox]->squares[ boxes[currentBox]->numbers ] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for (x = 0; x < SIZE_ROWS; x++)
            {
                sudoku[i][j]->possible[x] = 0;
            }

            if (j == 2)
                currentBox++;
            if (j == 5)
                currentBox++;

        }

        currentBox -= 2;
        if (i == 2)
            currentBox = 3;
        if (i == 5)
            currentBox = 6;
    }

    /* loop through rows */
    for (i = 0; i < SIZE_ROWS; i++)
    {
        /* loop through columns */
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return createSudoku(sudoku, boxes);
}

/*
 * int updateSudoku(Square *** sudoku, int row, int column)
 *
 * Once a single square is solved, all other squares along
 * the same row and coloumn must be updated to reflect the
 * change
 */
int updateSudoku(Square *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;

    for (x = 0; x < SIZE_ROWS; x++)
    {
        if (sudoku[x][column]->possible[number - 1] == 0)
        {
            sudoku[x][column]->solvable--;
        }
        sudoku[x][column]->possible[number -1] = 1;
    }

    for (x = 0; x < SIZE_COLUMNS; x++)
    {
        if (sudoku[row][x]->possible[number - 1] == 0)
        {
            sudoku[row][x]->solvable--;
        }
        sudoku[row][x]->possible[number -1] = 1;
    }

    return 1;

}

/*
 * int checkPuzzle(Square *** sudoku, Box ** boxes)
 *
 * Loop through all squares in the puzzle to check for
 * a solvable square.
 */
int checkPuzzle(Square *** sudoku, Box ** boxes)
{
    int i, j, x;

    /* loop through rows */
    for (i = 0; i < SIZE_ROWS; i++)
    {
        /* loop through columns */
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->solvable == 1)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);

                return 1;
            }
        }
    }
  int boxSingles(Square *** sudoku, Box ** boxes); 
    if (boxSingles(sudoku, boxes))
        return 1;
  
  int checkRows(Square *** sudoku, Box ** boxes);
    return checkRows(sudoku, boxes);
}

/*
 * int ** createPuzzle()
 *
 * Create a double array containing the puzzle
 */
int ** createPuzzle(int argc, char* argv[])
{
    int ** puzzle;
    int i, j;
    

    int array[9][9]= {0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0,

                      0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0,
/*  */
                      0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0 };


 if(argc == 2){
    int i = 0, j =0;
    int num;
    
    for (char *p = strtok(argv[1]," "); p != NULL; p = strtok(NULL, " "))
      {
        //puts(p);
        num  = atoi(p);
        
        array[i][j] = num;
//      printf("You have input the number '%d' (%s) for location: (%d, %d)\n", array[i][j], p, i, j); 
        if(j==8){
  
          j = 0;
          i = i +1; 
          num  = atoi(p);
          array[i][j] = num;  
        }
        else{
          // array[i][j] = num; 
          j = j +1; 
        }

      }

  }
  
  
else{
 for(int i=0; i< SIZE_ROWS; i++){
  for(int j=0; j< SIZE_COLUMNS; j++){
  printf("Initial value is '%d' for location: (%d, %d)\nEnter a number less than 10!\n", array[i][j], i, j);

  int test=0;
 // int input[3];
  int number;
  int num; 
while(test==0){
  char input[MAXINPUT] = "";

  int length, i; 

  scanf("%s", input);
  length = strlen (input);
  for(i=0; i<length; i++){
    if(!isdigit(input[i])){
      printf("Entered input is not a number\nPlease enter a number!\n");
      
    }
    else{
      num = atoi(input);
      if(num>9){
        printf("Number must be LESS than 10!\n");
      }
      else{
        test =1 ;
      }
   }
  }
}
 
  array[i][j]=num;
  printf("You have input the number '%d' for location: (%d, %d)\n", array[i][j], i, j);
  }
 }
}

   
    puzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < 9; i++)
    {
        puzzle[i] = (int*)malloc(sizeof(int)*9);

        for (j = 0; j < 9; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

/*
 * void printPuzzle(Square *** puzzle)
 *
 * Display puzzle in sudoku form
 */
void printPuzzle(Square *** puzzle)
{
    int i, j; 

    printf("-------------------------------\n");
    for (i = 0; i < SIZE_ROWS; i++)
    {
        printf("|");
        /* print each row */
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            
            printf(" %d ", puzzle[i][j]->number);

            if (((j + 1) % 3) == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3) == 0)
        {
            printf("-------------------------------\n");
        }
    }

}


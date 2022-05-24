#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point{
    unsigned int x;
    unsigned int y;
}point;

typedef struct cell{
    int val;
    point location;
}cell;

cell* empty_Sudoku();
cell* random_Sudoku();
void print_Sudoku(cell* Sudoku);

int main(){

    cell* sudoku;
    sudoku = empty_Sudoku;
    print_Sudoku(sudoku);
    sudoku = random_Sudoku;
    printf("\n");
    print_Sudoku(sudoku);

    return(0);
}

cell* empty_Sudoku(){

    int column;
    int row;
    
    cell Sudoku[27];
    for (size_t i = 0; i < 27; i++){
        column = i % 10;
        row = (i - (i % 10)) / 10;
        Sudoku[i].val = 0;
        Sudoku[i].location.x = column;
        Sudoku[i].location.y = row;
        
    }
    cell* p = &Sudoku[0];
    return(p);
}

cell* random_Sudoku(){

    int column;
    int row;
    srand(time(NULL));

    cell Sudoku[27];
    for (size_t i = 0; i < 27; i++){
        column = i % 10;
        row = (i - (i % 9)) / 10;
        Sudoku[i].val = rand() % 10 +1;
        Sudoku[i].location.x = column;
        Sudoku[i].location.y = row;
        
    }
    cell* p = &Sudoku[0];
    return(p); 
}

void print_Sudoku(cell* Sudoku){

    int row = 0;
    int row_pr;
    
    for (size_t i = 0; i < 27; i++){
        
        row_pr = row;
        row = (i - (i % 10)) / 10;
        
        if (row > row_pr){
            printf("\n\n");
        }
        
        printf("\t%d\t", Sudoku[i].val);
        
    } 
    printf("\n\n");   
}



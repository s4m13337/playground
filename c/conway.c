#include<stdio.h>

/**
 * conway game of life
 * each cell can either be 0 (dead) or 1 (alive)
 * underpopulation: a live cell with less than 2 dead cells becomes dead
 * survival: a live cell with 2 or 3 live cells lives for the next generation
 * overpopulation: a live cell with more than 3 neighbors becomes dead
 * reproduction: a dead cell with exactly 3 neighbors becomes live
 */
int main(){
    int dim=32;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("|0");
        }
        printf("|\n");
    }

}
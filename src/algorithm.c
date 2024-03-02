#include "../include/algorithm.h"
#include <stdbool.h>
#include <stdlib.h>
//Cell map[100][100] = {0}; //<--- why am I not declaring this in my window file? how dumb am i?


Position openCellPosition[40][80];


int heuristic(Position start, Position end){
    return abs(start.x_pos - end.x_pos) + abs(start.y_pos - end.y_pos);
}



Cell *findLowestFCostCell(){
    return NULL;
}


void processNeighbors(int x, int y){
    ;
}

void findPath(Cell *map, Position start, Position end){
    ;
}
#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#pragma once
#include "position.h"
#include <stdbool.h>

typedef struct Cell{
    Position current_position;
    int gCost; //this represents a cot from start node to this or the next node
    int hCost; //estimate of cost from this node to the end
    int fCost; //total cost (gCost + hCost);
    bool walkable; //if this node is walkable
    struct Cell *parent; //parent cell for path reconstruction ---> need to understand this bit
    //since evaluating or storing current position is useless (we are implementing this with array index are the position we need);
}Cell;

void findPath(Cell *map, Position start, Position end);
int heuristic(Position start, Position end);
Cell *findLowestFCostCell();
void processNeighbors(int x, int y);

#endif
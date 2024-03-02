//this file will house all the code thats displayed on the screen 
#include <stdbool.h>
#include <raylib.h>
#include "../include/algorithm.h"
#include "../include/mapparser.h"
#include <stdio.h>
#include <stdlib.h>

//trying to roughly draw map
//maybe I should just use a struct for this //the struct will also hold the postion of each 
Position start_position = {0}; //currently I myself am confused if I need position like this creating the grid is already going to be what I need (ig they can become useful as start and endposition i give to my find path function)
Position end_position = {0}; //we will just have one end position and find our way to it
bool end_pos_found = false;

Cell mapData[40][80];


int getindexStart(const char *buffer){ //probably not needed but lets see;
    int i;
    for(i=0; buffer[i] != 'S'; i++) ;
    return i;
}

int getWidth(const char *buffer){
    int i;
    for(i = 0; buffer[i] != '\n'; i++)  ;
    return i;
}

void drawMap(const char *map) {
    int startX = 10;
    int startY = 10;
    int posX = startX;
    int posY = startY;
    int dx = 20;
    int dy = 20;
    int k=0;
    int j=0;
    int radius = 5;

    for (int i = 0; map[i] != '\0'; i++) {
        switch (map[i]) {
            case '\n': // New line
                j++;
                posX = startX;
                posY += dy;
                k = 0;
                break;
            case '-':
                DrawLine(posX, posY + dy / 2, posX + dx, posY + dy / 2, BLACK);
                
                
                //ANYONE CAN CONTRIBUTE FOR THE FOLLOWING TASK!! Thank you
                //<<in this future we can make a function for this task and i will definitely use a dynamic allocated structure since we have to store the current location anyway>>
                //or maybe directly parse it into the struct and then draw the struct as the map (For the future me).
                
                
                mapData[j][k].walkable = false;
                mapData[j][k].current_position.x_pos = k;
                mapData[j][k].current_position.y_pos = j;
                posX += dx;
                k++;
                break;
            case '|':
                DrawLine(posX + dx / 2, posY, posX + dx / 2, posY + dy, BLACK);
                mapData[j][k].walkable = false;
                mapData[j][k].current_position.x_pos = k;
                mapData[j][k].current_position.y_pos = j;
                posX += dx;
                k++;
                break;
            case 'o':
                DrawCircle(posX + dx / 2, posY + dy / 2, radius, GRAY);
                mapData[j][k].walkable = false;
                mapData[j][k].current_position.x_pos = k;
                mapData[j][k].current_position.y_pos = j;
                posX += dx;
                k++;
                break;
            case ' ':
                mapData[j][k].walkable = true;
                mapData[j][k].current_position.x_pos = k;
                mapData[j][k].current_position.y_pos = j;
                posX += dx;
                k++;
                break;
            case 'S':
                DrawRectangle(posX-dx, posY, 3*dx, dy, GREEN);
                mapData[j][k].walkable = true;
                mapData[j][k].current_position.x_pos = k;
                mapData[j][k].current_position.y_pos = j;
                start_position.x_pos = k; //these will now give me the index in the cell
                start_position.y_pos = j;
                posX += dx;
                k++;
                break;
            case 'G':
                DrawRectangle(posX-dx, posY, 3*dx, dy, RED);
                mapData[j][k].walkable = true;
                mapData[j][k].current_position.x_pos = k;
                mapData[j][k].current_position.y_pos = j;
                if(!end_pos_found){ //will implement just this but as a index in Cell;
                    end_position.x_pos = k;
                    end_position.y_pos = j;
                    end_pos_found = true;
                }
                k++;
                posX += dx;
                break;
            default: //that should leave us with no other condition but to be safe
                mapData[j][k].walkable = false;
                k++;
                posX += dx;
                break;
        }
    }
}

void window(const int screenWidth, const int screenHeight){
    //Rectangle car = {screenWidth/2 -50, screenHeight/2 -30, 50, 30};
    //Cell *currentMap = NULL;//<--set this to null until and do the work inside the fnction to create the cell layout;;
    InitWindow(screenWidth, screenHeight, "MicroMouse Simulator");
    SetTargetFPS(30);
    char *buffer = mapParser("/home/celestial/Desktop/Programming/micromouse/maps/mazefiles/classic/yama7.txt");//path should soon be selected dynamically by the ui
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            //DrawRectangleRec(car, RED);
            drawMap(buffer);
            //DrawText("Testing", screenWidth/2 - 30, screenHeight/2 -40 , 20, LIGHTGRAY);
        EndDrawing();
    }
    printf("start position is:\nx=%d,y=%d\nend_positionis\nx=%d, y=%d\n", start_position.x_pos,start_position.y_pos,end_position.x_pos,end_position.y_pos);
    printf("%c\n", buffer[getindexStart(buffer)]);
    //printf("width = %d\nheight = %d\n", getWidth(buffer),33);
    //printf("%s", buffer);
    printf("start position:\n%d,%d",start_position.x_pos, start_position.y_pos);
    free(buffer);
    CloseWindow();
}

// for eaiser implementation whatever I was doing earlier was useless but now lets do something that is neededs

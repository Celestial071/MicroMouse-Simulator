//this file will house all the code thats displayed on the screen 
#include "../include/window.h"
#include "../include/mapparser.h"
#include <raylib.h>

const int dx = 20; //some val ---> just needs to be little more than the thickness of car
const int dy = 30; //some val ---> currently just has to be little bit more than the height of the car


//trying to roughly draw map
//maybe I should just use a struct for this //the struct will also hold the postion of each 
void drawMap(const char *map) {
    int startX = 10;
    int startY = 10;
    int posX = startX;
    int posY = startY;
    int dx = 20;
    int dy = 20;
    int radius = 5;

    for (int i = 0; map[i] != '\0'; i++) {
        switch (map[i]) {
            case '\n': // New line
                posX = startX;
                posY += dy;
                break;
            case '-':
                DrawLine(posX, posY + dy / 2, posX + dx, posY + dy / 2, BLACK);
                posX += dx;
                break;
            case '|':
                DrawLine(posX + dx / 2, posY, posX + dx / 2, posY + dy, BLACK);
                posX += dx;
                break;
            case 'o':
                DrawCircle(posX + dx / 2, posY + dy / 2, radius, GRAY);
                posX += dx;
                break;
            case ' ':
                posX += dx;
                break;
            case 'S':
                DrawRectangle(posX-dx, posY, 3*dx, dy, GREEN);
                posX += dx;
                break;
            case 'G':
                DrawRectangle(posX-dx, posY, 3*dx, dy, RED);
                posX += dx;
                break;
            default:
                //posX += dx;
                break;
        }
    }
}

void window(const int screenWidth, const int screenHeight){
    //Rectangle car = {screenWidth/2 -50, screenHeight/2 -30, 50, 30};
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

    printf("%s", buffer);
    free(buffer);
    CloseWindow();
}
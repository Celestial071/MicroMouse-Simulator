#include "../include/mapparser.h"

//now since it might be important to have the map with us all the time, its best to return it from this

long fileSize(const char *path){
    FILE *infile = fopen(path, "rb");

    if(infile == NULL){
        perror("Error opening file");
    }
    fseek(infile, 0, SEEK_END);
    long fileSize = ftell(infile);
    rewind(infile); //probably redundant as the file closes it should be reset anyway (but still a good practice)
    fclose(infile);
    return fileSize;
}


char *mapParser(const char *path){
    FILE *infile = fopen(path, "rb");

    long size = fileSize(path);
    char *map = calloc(1, size+1);
    int i =0;
    for(i=0; i<size+1; i++){
        map[i] = getc(infile);
    }
    map[i] = '\0';
    fclose(infile);
    return map;
}
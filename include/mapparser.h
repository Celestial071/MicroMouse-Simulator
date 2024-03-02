#ifndef _MAPPARSER_H
#define _MAPPARSER_H
#pragma once
//so this will be a helper function or a function that will change the 256 byte of date in the map into a array or we can use a struct and then move forward
//then it might be valuable to store this data in a struct or a 2nd dimensional array so I can directly parse and compare to start drawing
//first lets get the path of the map we will start parsing (the format is about the same)

long fileSize(const char *path); //return the size of the file we are working with
char *mapParser(const char *path); //will change this to a char * and just return the string of file

#endif
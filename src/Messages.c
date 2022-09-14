#include "Messages.h"
#include <stdio.h>

void printResizingError(char* msg)
{
    printf("Resizing Error in %s!", msg);
}

void printFileError(char* filePath)
{
    printf("Cannot open file: %s", filePath);
}

void printArgumentError(void)
{
    printf("Incorrect arguments count!");
}
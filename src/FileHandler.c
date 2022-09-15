#include "ContentStruct.h"
#include "Defines.h"
#include "FileHandler.h"
#include <stdio.h>

static void readLinesFromFile(FILE* filePtr, FileContent* outContent)
{
    char currentChar = INIT_ZERO;
    
    while ((currentChar = fgetc(filePtr)) != EOF)
    {
        if (currentChar == '\n')
        {       
            addChar(&outContent->rows[outContent->size], END_OF_STRING);
            moveToNextRow(outContent);
        }
        else
        {
            addChar(&outContent->rows[outContent->size], currentChar);
        }
    }
}

bool readFile(FileContent* outContent, const char *filePath)
{
    FILE *filePtr = NULL;
    filePtr = fopen(filePath, "r");

    if (filePtr == NULL)
    { 
        return false;
    }

    initFileContent(outContent);
    readLinesFromFile(filePtr, outContent);
    
    fclose(filePtr);
    return true;
}


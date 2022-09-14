#include "ContentStruct.h"
#include "FileHandler.h"
#include <stdio.h>

static void readLinesFromFile(FILE* filePtr, FileContent* outContent)
{
    char currentChar = 0;
    
    while ((currentChar = fgetc(filePtr)) != EOF)
    {
        if (currentChar == '\n')
        {       
            addChar(&outContent->rows[outContent->size], '\0');
            moveToNextRow(outContent);
        }
        else
        {
            addChar(&outContent->rows[outContent->size], currentChar);
        }
    }
}

bool readFile(FileContent* content, const char *filePath)
{
    FILE *filePtr = NULL;
    filePtr = fopen(filePath, "r");

    if (filePtr == NULL)
    { 
        return false;
    }

    readLinesFromFile(filePtr, content);
    
    fclose(filePtr);
    return true;
}


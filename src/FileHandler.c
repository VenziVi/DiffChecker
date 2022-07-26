#include <stdlib.h>
#include <stdio.h>
#include "FileHandler.h"

static fileContent readLinesFromFile(FILE *file_ptr)
{
    fileContent outContent = {0};
    size_t rowIndex = 0;

    size_t capacity = 5;
    outContent.lines = malloc(sizeof(char*) * capacity);

    size_t lineCapacity = 10;
    outContent.lines[rowIndex] = malloc(lineCapacity);

    char currentChar = 0;
    size_t lineIndex = 0;

    while ((currentChar = fgetc(file_ptr)) != EOF)
    {
        if (currentChar == '\n')
        {
            if ((rowIndex + 1) == capacity)
            {
                capacity *= 2;
                outContent.lines = realloc(outContent.lines, sizeof(char*) * capacity);
            }

            outContent.lines[rowIndex][lineIndex] = '\0';
            rowIndex++;

            lineCapacity = 10;
            outContent.lines[rowIndex] = malloc(lineCapacity);
            lineIndex = 0;
        }
        else
        {
            if ((lineIndex + 1) == lineCapacity)
            {
               lineCapacity *= 2;
               outContent.lines[rowIndex] = realloc(outContent.lines[rowIndex], lineCapacity);
            }

            outContent.lines[rowIndex][lineIndex] = currentChar;
            lineIndex++;
        }
    }

    outContent.numberOfRows = rowIndex;
    return outContent;
}

fileContent readFile(const char *filePath)
{
    FILE *file_ptr = NULL;
    file_ptr = fopen(filePath, "r");
    
    if (file_ptr == NULL)
    {
        printf("Cannot open file: %s", filePath);   
        exit(1);
    }

    fileContent outContent = readLinesFromFile(file_ptr);
    
    fclose(file_ptr);
    return outContent;
}

void deinitFileContent(fileContent *file)
{
    for (size_t i = 0; i <= file->numberOfRows; i++)
    {
        free(file->lines[i]);
    }
    
    free(file->lines);
}
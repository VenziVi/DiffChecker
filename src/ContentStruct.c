#include "ContentStruct.h"
#include "Messages.h"
#include "Defines.h"
#include <stdlib.h>

void initFileContent(FileContent* outContent)
{
    outContent->rows = malloc(sizeof(Line) * FILE_CONTENT_INIT_CAPACITY);
    outContent->capacity = FILE_CONTENT_INIT_CAPACITY;
    outContent->size = SIZE_INIT_VALUE;

    initLine(outContent);
}

void initLine(FileContent* content)
{
    content->rows[content->size].line = malloc(sizeof(char) * LINE_INIT_CAPACITY);
    content->rows[content->size].capacity = LINE_INIT_CAPACITY;
    content->rows[content->size].size = SIZE_INIT_VALUE;
}

void addChar(Line* line, char currChar)
{
    if ((line->capacity - CAPACITY_COMPARE_VALUE) == line->size)
    {
        resizeLine(line);
    }

    if (currChar == END_OF_STRING)
    {
        line->line[--line->size] = currChar;
    }
    else
    {
        line->line[line->size++] = currChar;
    }
}

void resizeLine(Line* line)
{
    line->capacity *= INCREASE_VALUE;

    char* resizedLine = realloc(line->line, sizeof(char) * line->capacity);

    if (resizedLine == NULL)
    {
        printResizingError("Resize line");
        return;
    }
    
    line->line = resizedLine;
}

void moveToNextRow(FileContent* outContent)
{
    if ((outContent->capacity - CAPACITY_COMPARE_VALUE) == outContent->size)
    {
        resizeFileContent(outContent);
    }

    outContent->size++;
    initLine(outContent);
}

void resizeFileContent(FileContent* outContent)
{
    outContent->capacity *= INCREASE_VALUE;

    Line* resizedContent = realloc(outContent->rows, sizeof(Line) * outContent->capacity);

    if (resizedContent == NULL)
    {
        printResizingError("Resize File Content");
        return;
    }

    outContent->rows = resizedContent;
}

void deinitFileContent(FileContent* content)
{
    for (size_t i = 0; i <= content->size; i++)
    {
        free(content->rows[i].line);
    }

    free(content->rows);
}
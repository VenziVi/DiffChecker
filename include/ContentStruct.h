#ifndef CONTENT_STRUCT_H_
#define CONTENT_STRUCT_H_

#include "Defines.h"

typedef struct
{
    char* line;
    num_v size;
    num_v capacity;
} Line;

typedef struct
{
    Line* rows;
    num_v size;
    num_v capacity;
} FileContent;

void initFileContent(FileContent* outContent);
void initLine(FileContent* outContent);
void addChar(Line* line, char currentChar);
void moveToNextRow(FileContent* outContent);
void resizeFileContent(FileContent* outContent);
void resizeLine(Line* line);
void deinitFileContent(FileContent* outContent);

#endif // CONTENT_STRUCT_H_
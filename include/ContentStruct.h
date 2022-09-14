#ifndef CONTENT_STRUCT_H_
#define CONTENT_STRUCT_H_

#include <stddef.h>

typedef struct
{
    char* line;
    size_t size;
    size_t capacity;
} Line;

typedef struct
{
    Line* rows;
    size_t size;
    size_t capacity;
} FileContent;

FileContent* initFileContent(void);
void initLine(FileContent* outContent);
void addChar(Line* line, char currentChar);
void moveToNextRow(FileContent* outContent);
void resizeFileContent(FileContent* outContent);
void resizeLine(Line* line);
void deinitFileContent(FileContent* outContent);

#endif // CONTENT_STRUCT_H_
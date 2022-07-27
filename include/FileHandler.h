#ifndef _FILE_HANDLER_H
#define _FILE_HANDLER_H

#include <stddef.h>

typedef struct 
{
    char **lines;
    size_t numberOfRows;

} fileContent;

fileContent readFile(const char *filePath);
void deinitFileContent(fileContent *file);

#endif // _FILE_HANDLER_H

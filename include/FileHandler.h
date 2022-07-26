#ifndef CODE_ACADEMY_DIFF_TOOL_FILE_HANDLER_H
#define CODE_ACADEMY_DIFF_TOOL_FILE_HANDLER_H

#include <stddef.h>

typedef struct 
{
    char **lines;
    size_t numberOfRows;

} fileContent;

fileContent readFile(const char *filePath);
void deinitFileContent(fileContent *file);

#endif // CODE_ACADEMY_DIFF_TOOL_FILE_HANDLER_H

#ifndef FILE_HANDLER_H_
#define FILE_HANDLER_H_

#include "ContentStruct.h"
#include <stdbool.h>

bool readFile(FileContent* content, const char *filePath);

#endif // FILE_HANDLER_H_S
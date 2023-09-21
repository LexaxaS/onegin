#ifndef ONEGIN_H
#define ONEGIN_H

#include <stdio.h>
#include "sort.hpp"

size_t fileLen(const char * file);
size_t setbuf(char* buf, char** pointers, size_t flen, FILE* fileEO);
void printBuf(char **pointers, FILE *SortedEO);
void bufReturn(char* buf, size_t flen);


#endif
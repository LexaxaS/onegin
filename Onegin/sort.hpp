#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include "onegin.hpp"

#define MIN(a,b)                 \
        ({                       \
        __typeof__(a) c = a;     \
        __typeof__(b) d = b;     \
        c < d ? c : d;           \
        }) 


typedef int CompareFunc_t(const void *a, const void *b);

void swap(void *a, void *b, size_t size);
int strComp(const String* str1, const String* str2);
int strCompRev(const String* str1, const String* str2);
void intswap(void *data, size_t a, size_t b);
int intComp(const void *a, const void *b);
void puzirikSortir(void *data, size_t size, size_t elemSize, CompareFunc_t *CompareFunc);

#endif
#ifndef SORT_H
#define SORT_H

#include <stdio.h>

#define MIN(a,b)                 \
        ({                       \
        __typeof__(a) c = a;     \
        __typeof__(b) d = b;     \
        c < d ? c : d;           \
        }) 


typedef int CompareFunc_t (const void *a, const void *b);
typedef void SwapFunc_t (void *data, size_t a, size_t b);

void swap(void *a, void *b, size_t size);
int strCompRev(const void *str1, const void *str2);
void intswap(void *data, size_t a, size_t b);
int intComp(const void *a, const void *b);
void puzirikSortir(void *data, size_t size, size_t elemSize, CompareFunc_t *CompareFunc);
int strComp(const void *a, const void *b);

#endif
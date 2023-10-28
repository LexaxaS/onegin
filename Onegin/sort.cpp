#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "sort.hpp"


void puzirikSortir(void *data, size_t size, size_t elemSize, CompareFunc_t *CompareFunc)
    {
    assert(data);
    assert(size);
    assert(elemSize);
    assert(CompareFunc);

    for (size_t i = 0; i < size; i++)
        {
        for (size_t j = 0; j < size - i - 1; j++)
            {
            if (CompareFunc((data +  j      * elemSize), 
                            (data + (j + 1) * elemSize)) > 0)
                {
                swap(data + j * elemSize, data + (j + 1) * elemSize, elemSize);
                }
            }
        }        
    }

int intComp(const void *a, const void *b)
    {
    assert(a);
    assert(b);

    return (*(const int*) a - *(const int*) b);
    }

void swap(void *a, void *b, size_t size)
    {
    assert(a);
    assert(b);
    assert(size);

    char* _a = (char*) a;
    char* _b = (char*) b;
    for (size_t i = 0; i < size; i++)
        {
        char _temp = _a[i];
        _a[i] = _b[i];
        _b[i] = _temp;
        }
    }

int strComp(const String* str1, const String* str2)
    {
    assert(str1);
    assert(str2);

    const char *cstr1 = str1->linePtr;
    const char *cstr2 = str2->linePtr;
    size_t ns1 = str1->length;
    size_t ns2 = str2->length;
    size_t str1_i = 0;
    size_t str2_i = 0;
    while ((str1_i < MIN(ns1, ns2)) & (str2_i < MIN(ns1, ns2)))
        if (!isalpha(*(cstr1 + str1_i)))
            {
            str1_i++;
            }
        else if (!isalpha(*(cstr2 + str2_i)))
            {
            str2_i++;
            }
        else if (*(cstr1 + str1_i) != *(cstr2 + str2_i))
            {
            if (*(cstr1  + str1_i) > *(cstr2 + str2_i))
                return 1;
            else
                return -1;
            }
        else
            {
            str1_i++;
            str2_i++;
            }
        
    if (ns1 > ns2)
        return 1;
    else if (ns1 < ns2)
        return -1;
    else
        return 0;
    }



int strCompRev(const String* str1, const String* str2)
    {
    assert(str1);
    assert(str2);

    const char *cstr1 = str1->linePtr;
    const char *cstr2 = str2->linePtr;
    size_t ns1 = str1->length;
    size_t ns2 = str2->length;
    size_t str1_i = ns1;
    size_t str2_i = ns2;
    while ((str1_i > 0) & (str2_i > 0))
        if (!isalpha(*(cstr1 + str1_i)))
            {
            str1_i--;
            }
        else if (!isalpha(*(cstr2 + str2_i)))
            {
            str2_i--;
            }
        else if (*(cstr1 + str1_i) != *(cstr2 + str2_i))
            {
            if (*(cstr1  + str1_i) > *(cstr2 + str2_i))
                return 1;
            else
                return -1;
            }
        else
            {
            str1_i--;
            str2_i--;
            }
        
    if (ns1 > ns2)
        return 1;
    else if (ns1 < ns2)
        return -1;
    else
        return 0;
    }


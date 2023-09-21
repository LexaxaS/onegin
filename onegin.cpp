#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <assert.h>
#include "onegin.hpp"


size_t setbuf(char *buf, char **pointers, size_t flen, FILE* fileEO)
    {
    assert(buf);
    assert(pointers);
    assert(flen);
    assert(fileEO);

    size_t cnt = 1;
    fread(buf, sizeof(char), flen, fileEO);

    size_t buf_i = 0;
    size_t poi_j = 1;
    pointers[0] = &buf[0];
    while (buf_i + 2 < flen)
        {
        if (buf[buf_i] == '\r')
            {
            if (buf[buf_i + 2] != '\r')
                {
                pointers[poi_j] = &(buf[buf_i + 2]);
                poi_j++;
                cnt++;
                }
            buf[buf_i] = '\0';
            buf_i += 2;
            
            }
        else if (buf[buf_i] == '\n')
            {
            pointers[poi_j] = &(buf[buf_i + 1]);
            buf_i++;
            poi_j++;
            cnt++;
            }
        else
            {
            buf_i++;
            }
        }
    pointers[poi_j] = 0;
    return cnt;
    }  

void printBuf(char **pointers, FILE *SortedEO)
    {
    assert(pointers);
    while (*pointers != NULL)
        {
        fprintf(SortedEO, "%s\n", *pointers);
        *pointers++;
        }
    }

void bufReturn(char* buf, size_t flen)
    {
    assert(buf);
    assert(flen);

    size_t buf_i = 0;
    while (buf_i + 2 < flen)
        {
        if (buf[buf_i] == '\0')
            {
            buf[buf_i] = '\r';
            buf_i ++;
            }
        else
            {
            buf_i++;
            }
        }
    }
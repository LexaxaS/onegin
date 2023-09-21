#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "sort.hpp"
#include "onegin.hpp"
#include "file_opener.hpp"

int main()
    {
    //char filename_i[] = "onev.txt";
    char filename_i[] = "Eugene Onegin.txt";
    char filename_o[] = "SortedEO.txt";
    FILE *fileEO = fileopener(filename_i);
    FILE *SortedEO = fileopenerW(filename_o);
    size_t flen = fileLen(filename_i);
    char* buf = (char*) calloc(flen, sizeof(char));
    char** pointers = (char**) calloc(flen, sizeof(char*));
    size_t cnt = setbuf(buf, pointers, flen, fileEO);

    fprintf(SortedEO, "\nSort from left\n\n\n");
    puzirikSortir(pointers, cnt, sizeof(char**), strComp);
    printBuf(pointers, SortedEO);

    fprintf(SortedEO, "\n\nSort from right\n\n\n");
    puzirikSortir(pointers, cnt, sizeof(char**), strCompRev);
    printBuf(pointers, SortedEO);

    bufReturn(buf, flen);
    fprintf(SortedEO, "\n\nOriginal\n\n\n");
    fprintf(SortedEO, "%s\n\n", buf);
    fclose(SortedEO);
    fclose(fileEO);
    return 0;
    }



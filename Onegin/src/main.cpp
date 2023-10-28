#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "..\headers\sort.hpp"
#include "..\headers\onegin.hpp"
#include "..\headers\file_opener.hpp"

int main()
    {
    char filename[] = "../onev.txt";
    FILE *fileEO = fileopener(filename);
    size_t flen = fileLen(filename);
    char* buf = (char*) calloc(flen, sizeof(char));
    char** pointers = (char**) calloc(flen, sizeof(char*));
    size_t cnt = setbuf(buf, pointers, flen, fileEO);

    printf("\nSort from left\n\n\n");
    puzirikSortir(pointers, cnt, sizeof(char**), strComp);
    printBuf(pointers);

    printf("\n\nSort from right\n\n\n");
    puzirikSortir(pointers, cnt, sizeof(char**), strCompRev);
    printBuf(pointers);

    bufReturn(buf, flen);
    printf("\n\nOriginal\n\n\n");
    printf("%s\n\n", buf);
    
    fclose(fileEO);
    free(buf);
    free(pointers);
    return 0;
    }



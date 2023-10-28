#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <assert.h>
#include "sort.hpp"
#include "onegin.hpp"
#include "file_opener.hpp"


int _strComp(const void *str1, const void *str2);
int _strCompRev(const void *str1, const void *str2);

void sortText(Text* text, CmpSide_t cmpSide)
    {
    switch (cmpSide)
        {
        case LEFT:
            puzirikSortir((void*)text->bufPtr, text->nLines, sizeof(char), _strComp);
            break;
        case RIGHT:
            puzirikSortir((void*)text->bufPtr, text->nLines, sizeof(char), _strCompRev);
            break;
        default:
            puzirikSortir((void*)text->bufPtr, text->nLines, sizeof(char), _strComp);
            break;
        }
    }

Text setbuf(char filename_i[])
    {
    assert(filename_i);

    Text text = {};

    char filename_o[] = "SortedEO.txt";
    FILE *fileEO = fileopener(filename_i);
    FILE *SortedEO = fileopenerW(filename_o);
    text.size = fileLen(filename_i);  
    text.file = SortedEO;
    char* buf = (char*) calloc(text.size, sizeof(char));
    fread(buf, sizeof(char), text.size, fileEO);
    fclose(fileEO);      
    text.bufPtr = buf;
    text.nLines = countLines(buf);

    text.lines = setPtr(buf, text.nLines, text.size);
    
    return text;
    }  


const String* setPtr(char* buf, size_t nLines, size_t flen)
    {

    size_t buf_i = 0;
    size_t ptr_j = 1;

    String* pointers = (String*) calloc(nLines + 1, sizeof(*pointers));

    size_t lineLen = 0;

    pointers[0].linePtr = &buf[0];
    while (buf_i + 2 < flen)
        {
        if (buf[buf_i] == '\r')
            {
            if (buf[buf_i + 2] != '\r')
                {
                pointers[ptr_j - 1].length = lineLen;
                pointers[ptr_j].linePtr = &(buf[buf_i + 2]);
                ptr_j++;
                }
            buf[buf_i] = '\0';
            buf_i += 2;
            lineLen = 0;
            }
        else if (buf[buf_i] == '\n')
            {
            pointers[ptr_j - 1].length = lineLen;
            pointers[ptr_j].linePtr = &(buf[buf_i + 1]);
            lineLen = 0;
            buf_i++;
            ptr_j++;
            }
        else
            {
            buf_i++;
            lineLen++;
            }
        }
    pointers[ptr_j].linePtr = 0;
    return pointers;
    }

size_t countLines(const char* str)
{
    size_t nlines = 1;
    const char* terPtr = strchr(str, '\n');
    while (terPtr != NULL)
    {
        nlines++;
        terPtr = strchr(terPtr + 1, '\n');
    }
    return nlines;
}

void printBuf(const String* pointers, FILE *SortedEO)
    {
    assert(pointers);
    while (*pointers->linePtr != NULL)
        {
        fprintf(SortedEO, "%s\n", *pointers->linePtr);
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
            buf_i++;
            }
        else
            {
            buf_i++;
            }
        }
    }

int _strComp(const void *str1, const void *str2)
    {
    return strComp((const String*) str1, (const String*) str2);
    }

int _strCompRev(const void *str1, const void *str2)
    {
    return strCompRev((const String*) str1, (const String*) str2);
    }
    
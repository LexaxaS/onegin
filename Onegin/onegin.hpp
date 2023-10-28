#ifndef ONEGIN_H
#define ONEGIN_H

typedef int CmpSide_t;

enum CmpSide_e {LEFT, RIGHT};
struct String
{
    const char* linePtr;
    size_t length;
};

struct Text
{
    char* bufPtr;
    const String* lines;
    size_t size;
    size_t nLines;
    FILE* file;
};

size_t countLines(const char* str);
void sortText(Text* text, CmpSide_t cmpSide);
const String* setPtr(char* buf, size_t nLines, size_t flen);
size_t fileLen(const char * file);
Text setbuf(char filename_i[]);
void printBuf(const String* pointers, FILE *SortedEO);
void bufReturn(char* buf, size_t flen);

#endif
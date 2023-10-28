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

    Text text = setbuf(filename_i);

    fprintf(text.file, "\nSort from left\n\n\n");
    sortText(&text, LEFT);
    printBuf(text.lines, text.file);

    fprintf(text.file, "\n\nSort from right\n\n\n");
    sortText(&text, RIGHT);
    printBuf(text.lines, text.file);

    bufReturn(text.bufPtr, text.size);
    fprintf(text.file, "\n\nOriginal\n\n\n");
    fprintf(text.file, "%s\n\n", text.bufPtr);
    fclose(text.file);

    return 0;
    }

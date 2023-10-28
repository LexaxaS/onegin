/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN(a,b)                 \
        ({                       \
        __typeof__(a) c = a;     \
        __typeof__(b) d = b;     \
        c < d ? c : d;           \
        }) 

typedef int CompareFunc_t (const void *a, const void *b);


int strComp(char *a, char *b);
void swap(void *a, void *b, size_t size);
void intswap(int data[], int a, int b);
void quickSortir(int *data, size_t strt, size_t size, size_t elemSize, CompareFunc_t *CompareFunc);
int intComp(const void *a, const void *b);


int main()
    {
    int dt[13] = {5, 6, 3, 1, 2, 4, 10, 15, 9, 14, 13, 10, 11};
    for (int i = 0; i < 13; i++)
        printf("%d ", dt[i]);
    // swap(dt, 2, 3);
    printf("\n");
    quickSortir(dt, 0, 12, sizeof(int), intComp);
    for (int i = 0; i < 13; i++)
        printf("%d ", dt[i]);
    return 0;
    }




void quickSortir(int *data, size_t left, size_t right, size_t elemSize, CompareFunc_t *CompareFunc)
    {
    size_t st = left;
    size_t kn = right;    
    printf("st - left=<%d> | right=<%d>\n", left, right);        

    if (right > left + 2)
        {
        int mid = data[left];
        while (left < right)
            {
            while (left < right)
                {
                if (data[left] >= mid)
                    break;
                left++;
                }
            while (left < right)
                {
                if (data[right] <= mid)
                    break;
                right--;
                }
            //printf("f");
            if (left >= right)
                break;
            intswap(data, left, right);
            
            }
        printf("e - left=<%d> | right=<%d>\n\n", left, right);
        quickSortir(data, st, left - 1, elemSize, CompareFunc);
        quickSortir(data, left + 1, kn , elemSize, CompareFunc);
        }
    else if (right - left == 3)
        {
        if (data[left] > data[left + 1])
            {
            if (data[left + 1] > data[left + 2])
                {
                intswap(data, left, left + 2);
                return;
                }
            else
                {
                if (data[left] > data[left + 2])
                    {
                    intswap(data, left, left + 1);
                    intswap(data, left + 1, left + 2);
                    return;
                    }
                else
                    {
                    intswap(data, left, left + 1);
                    return;
                    }
                }
            }
        else
            {
            if (data[left + 1] < data[left + 2])
                {
                return;
                }
            else
                {
                if (data[left] > data[left + 2])
                    {
                    intswap(data, left, left + 1);
                    intswap(data, left + 1, left + 2);
                    return;
                    }
                else
                    {
                    intswap(data, left, left + 1);
                    return;
                    }
                }
            }
        }
    else if (right - left == 2)
        {
        if (data[left] >= data[left + 1])
            {
            intswap(data, left, left + 1);
            return;
            }
        }
    else
        return;
    }


void intswap(int data[], int a, int b)
    {
    int c = data[a];
    data[a] = data[b];
    data[b] = c;
    }

int intComp(const void *a, const void *b)
    {
    return (*(const int*) a - *(const int*) b);
    }

int strComp(char *a, char *b)
    {
    int ns1 = strlen(a);
    int ns2 = strlen(b);
    int a_i = 0;
    int b_i = 0;
    while (a_i < MIN(ns1, ns2) & b_i < MIN(ns1, ns2))
        if (!isalpha(*(a + a_i)))
            {
            a_i++;
            }
        else if (!isalpha(*(b + b_i)))
            {
            b_i++;
            }
        else if (*(a + a_i) != *(b + b_i))
            {
            if (*(a + a_i) > *(b + b_i))
                return 1;
            else
                return -1;
            }
        else
            {
            a_i++;
            b_i++;
            }
        
    if (ns1 > ns2)
        return 1;
    else if (ns1 < ns2)
        return -1;
    else
        return 0;
    }

void swap(void *a, void *b, size_t size)
    {
    char* _a = (char*) a;
    char* _b = (char*) b;
    for (size_t i = 0; i < size; i++)
        {
        char _temp = _a[i];
        _a[i] = _b[i];
        _b[i] = _temp;
        }
    }

*/
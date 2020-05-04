#include <stdio.h>
#include <stdlib.h>
#define MAKS 10

void tukar(int *, int *);

int main()
{
    int data[MAKS]= {5,4,3,2,1,10,9,8,7,6};
    int i;
    int jarak = MAKS;
    while(jarak>1)
    {
        jarak /= 2;
        int did_swap = 1;
        while(did_swap==1)
        {
            did_swap=0;
            for(i=0; i<(MAKS-jarak); i++)
            {
                if(data[i]>data[i+jarak])
                {
                    tukar(&data[i], &data[i+jarak]);
                    did_swap=1;
                    for(int i=0; i<MAKS; i++)
                    {
                        printf("%d ", data[i]);
                    }
                    puts("");
                }
            }
        }
    }
    return 0;
}

void tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


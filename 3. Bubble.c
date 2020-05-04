#include <stdio.h>
#include <stdlib.h>
#define MAKS 10

void tukar(int *, int *);

int main()
{
    int data[MAKS]= {5,4,3,2,1,10,9,8,6,7};
    int akhir = MAKS-2;
    int did_swap=1;
    while(akhir >=0 && did_swap == 1)
    {
        did_swap=0;
        for(int i=0; i<=akhir; i++)
        {
            if(data[i]>data[i+1])
            {
                tukar(&data[i], &data[i+1]);
                did_swap=1;
                for(int i=0; i<MAKS; i++)
                {
                    printf("%d ", data[i]);
                }
                puts("");
            }

        }
        akhir--;
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


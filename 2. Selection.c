#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

int main()
{
    int angka[MAKS]={5,4,3,2,1};
    printf("Kondisi array awal: ");
    for(int i=0;i<MAKS;i++)
    {
        printf("%d ", angka[i]);
    }
    int i,j, min;
    for(i=0; i<MAKS-1; i++)
    {
        min = i;
        j = i+1;
        while(j<MAKS)
        {
            if(angka[j] < angka[min])
                min = j;
            j++;
        }
        int temp = angka[i];
        angka[i] = angka[min];
        angka[min] = temp;
    }

    printf("\nSetelah diurutkan: ");
	for(int i=0; i<MAKS; i++){
		printf("%d ", angka[i]);
	}

    return 0;
}

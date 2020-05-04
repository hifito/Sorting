#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

void quicksort_rekursif(int[], int , int);
int partition(int[], int , int);
void tukar(int *, int *);

int main()
{
    int angka[MAKS]= {5,4,3,2,1};
    printf("Kondisi array awal: ");
    int r=MAKS-1;
    for(int i=0; i<=4; i++)
    {
        printf("%d ", angka[i]);
    }
    quicksort_rekursif(angka,0,r);
    printf("\nSetelah diurutkan: ");
    for(int i=0; i<MAKS; i++)
    {
        printf("%d ", angka[i]);
    }

    return 0;
}

void quicksort_rekursif(int angka[], int p, int r)
{
    int q;
    if(p<r)
    {
        q = partition(angka,p,r);
        quicksort_rekursif(angka,p,q);
        quicksort_rekursif(angka,q+1,r);
    }
}

int partition(int angka[], int p, int r)
{
    int pivot, i, j;
    pivot = angka[p];
    i = p;
    j = r;
    do{
        while(angka[j] > pivot)
            j--;
        while(angka[i] < pivot)
            i++;
        if(i<j){
            tukar(&angka[j], &angka[i]);
            j--;
        }
        else
            return j;
    }while(i<j);
}

void tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}






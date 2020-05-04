#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

void mergersort_rekursif(int[], int , int );
void merge(int[], int , int , int );

int main()
{
    int angka[MAKS]= {5,4,3,2,1};
    printf("Kondisi array awal: ");
    int r=MAKS-1;
    for(int i=0; i<=4; i++)
    {
        printf("%d ", angka[i]);
    }
    mergersort_rekursif(angka, 0, r);
    printf("\nSetelah diurutkan: ");
    for(int i=0; i<MAKS; i++)
    {
        printf("%d ", angka[i]);
    }

    return 0;
}


void mergersort_rekursif(int angka[], int l, int r)
{
    int med;
    if(l<r)
    {
        med = (l+r)/2;
        mergersort_rekursif(angka,l,med);
        mergersort_rekursif(angka,med+1,r);
        merge(angka,l,med,r);
    }
}

void merge(int angka[], int left, int med, int right)
{
    int s1, f1, s2, f2, temp[MAKS], i, j;
    s1 = left;
    f1 = med;
    s2 = med+1;
    f2 = right;
    i = left;
    while((s1<=f1) && (s2<=f2))
    {
        if(angka[s1] < angka[s2])
        {
            temp[i] = angka[s1];
            s1++;
        }
        else
        {
            temp[i] = angka[s2];
            s2++;
        }
        i++;
    }
    while(s1<=f1)
    {
        temp[i] = angka[s1];
        s1++;
        i++;
    }
    while(s2<=f2)
    {
        temp[i] = angka[s2];
        s2++;
        i++;
    }
    j = left;
    while(j<=right)
    {
        angka[j] = temp[j];
        j++;
    }
}


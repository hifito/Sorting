#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

int main()
{
    int angka[MAKS]={5,4,3,2,1};
    printf("Kondisi array awal: ");
    for(int i=0;i<=4;i++)
    {
        printf("%d ", angka[i]);
    }
    for(int i=1; i<MAKS; i++){
		for(int j=i; j>0 && angka[j]<angka[j-1]; j--){
			int temp=angka[j-1];
			angka[j-1]=angka[j];
			angka[j]=temp;
		}
	}
    printf("\nSetelah diurutkan: ");
	for(int i=0; i<MAKS; i++){
		printf("%d ", angka[i]);
	}
    return 0;
}

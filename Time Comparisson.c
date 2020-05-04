#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int data[99999999], datatemp[99999999], tampung[99999999];
int n, mode;
long int t1=0,t2=0,waktu;
void input();
void menu();
void menu2();
void insertion();
void selection();
void bubble();
void shell();
void merge(int, int, int);
void mergesort(int, int);
int partisi(int, int);
void quick(int, int);
void random();
void backup();
void tukar(int *, int *);

int main()
{
    input();
    do
    {
        menu();
    }
    while(1);
}

void input()
{
    printf("Masukkan jumlah data: ");
    scanf("%d",&n);
    random();
}

void menu()
{
    int pilih;
    printf("\nMenu Sorting\n");
    printf("1. Insertion\n");
    printf("2. Selection\n");
    printf("3. Bubble\n");
    printf("4. Shell\n");
    printf("5. Merge\n");
    printf("6. Quick\n");
    printf("8. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilih);
    fflush(stdin);
    switch(pilih)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            menu2(pilih);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Pilihan Salah!");
            menu();
            break;
    }
    if(pilih!=7)
        printf("\nWaktu pengerjaan %ld detik",waktu);
}

void menu2(int pilih)
{
    printf("\nPilih Mode");
    printf("\n1.Ascending");
    printf("\n2.Descending");
    printf("\nMasukkan pilihan menu :");
    scanf("%d",&mode);
    fflush(stdin);
    time(&t1);
    switch(pilih)
    {
    case 1:
        insertion();
        break;
    case 2:
        selection();
        break;
    case 3:
        bubble();
        break;
    case 4:
        shell();
        break;
    case 5:
        mergesort(0,n-1);
        break;
    case 6:
        quick(0,n-1);
        break;
    }
    time(&t2);
    waktu=(t2-t1);
}

void insertion()
{
    for(int i=1; i<n; i++)
    {
        if(mode==1)
        {
            for(int j=i; j>0 && data[j]<data[j-1]; j--)
            {
                int temp=data[j-1];
                data[j-1]=data[j];
                data[j]=temp;
            }
        }
        else
        {
            for(int j=i; j>0 && data[j]>data[j-1]; j--)
            {
                int temp=data[j-1];
                data[j-1]=data[j];
                data[j]=temp;
            }
        }
    }
}

void selection()
{
    int i, j, minmax;
    for (i = 0; i < n - 1; i++)
    {
        minmax = i;
        if (mode == 2)
        {
            for (j = i + 1; j < n; j++)
            {
                if (data[j] > data[minmax])
                    minmax = j;
            }
        }
        else
        {
            for (j = i + 1; j < n; j++)
            {
                if (data[j] < data[minmax])
                    minmax = j;
            }
        }
        int temp = data[i];
        data[i] = data[minmax];
        data[minmax] = temp;
    }
}

void bubble(int data[], int mode)
{
    int akhir = n-2;
    int did_swap=1;
    while(akhir >=0 && did_swap == 1)
    {
        did_swap=0;
        for(int i=0; i<=akhir; i++)
        {
            if(mode==1)
            {
                if(data[i]>data[i+1])
                {
                    tukar(&data[i], &data[i+1]);
                    did_swap=1;
                }
            }
            else if(mode==2)
            {
                if(data[i]<data[i+1])
                {
                    tukar(&data[i], &data[i+1]);
                    did_swap=1;
                }
            }

        }
        akhir--;
    }
}

void shell()
{
    int i;
    int jarak = n;
    while(jarak>1)
    {
        jarak /= 2;
        int did_swap = 1;
        while(did_swap==1)
        {
            did_swap=0;
            for(i=0; i<(n-jarak); i++)
            {
                if(mode==1)
                {
                    if(data[i]>data[i+jarak])
                    {
                        tukar(&data[i], &data[i+jarak]);
                        did_swap=1;
                    }
                }
                else if(mode==2)
                {
                    if(data[i]<data[i+jarak])
                    {
                        tukar(&data[i], &data[i+jarak]);
                        did_swap=1;
                    }
                }
            }
        }
    }
}

void mergesort(int dep, int bel)
{
    int m;
    if(dep < bel)
    {
        m = (dep+bel)/2;
        mergesort(dep,m);
        mergesort(m+1,bel);
        merge(dep,m,bel);
        //cetak();
    }
}
void merge(int dep,int teng, int bel)
{
    int s1,f1,s2,f2,i,kondisi;
    s1=dep;
    f1=teng;
    s2=teng+1;
    f2=bel;
    i=dep;
    while(s1<=f1 && s2<=f2)
    {
        if(mode==1)
            kondisi=data[s1]<data[s2];
        else
            kondisi=data[s1]>data[s2];
        if(kondisi)
        {
            tampung[i]=data[s1];
            s1++;
        }
        else
        {
            tampung[i]=data[s2];
            s2++;
        }
        i++;
    }
    while(s1<=f1)
    {
        tampung[i]=data[s1];
        s1++;
        i++;
    }
    while(s2<=f2)
    {
        tampung[i]=data[s2];
        s2++;
        i++;
    }
    i=dep;
    while(i<=f2)
    {
        data[i]=tampung[i];
        i++;
    }
}
void quick(int dep, int bel)
{
    int m;
    if(dep < bel)
    {
        m = partisi(dep,bel);
        quick(dep,m);
        quick(m+1,bel);
    }
}
int partisi(int dep, int bel)
{
    int pivot, i,j;

    pivot=data[dep];
    i=dep;
    j=bel;
    do
    {
        if(mode==1)
        {
            while(data[i]<pivot)
                i++;
            while(data[j]>pivot)
                j--;
        }
        else
        {
            while(data[i]>pivot)
                i++;
            while(data[j]<pivot)
                j--;
        }
        if(i<j)
        {
            tukar(&data[i],&data[j]);
            j--;
        }
        else
            return j;
    }
    while(i<j);
}

void random()
{
    int i;
    srand(time(NULL));
    for(i=0; i<n; i++)
        data[i]=rand();
}

void backup()
{
    int i;
    for(i=0; i<n; i++)
        datatemp[i] = data[i];
}

void tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


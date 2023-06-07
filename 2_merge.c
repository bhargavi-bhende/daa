#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#define N 100000

int tarr[N],harr[N],tharr[N],ttharr[N],i,j,l=0,m=0,n=0,q=0;
double ten[3],hun[3],tho[3],ttho[3];
clock_t t;

void input(int);

void merge(int [], int, int);
void mergesub(int [], int, int, int);
void sortm();
void display();
void emparr(int [], int);
void emp();

int main()
{
            input(1);
            sortm();
            printf("\n------------------------------------------------------------------------");
            printf("\n\t    Ascending(Best)");
            emp();
            input(2);
            sortm();
            printf("\t    Random(Average)");
            emp();
             input(3);
            sortm();
            printf("\t    Descending(Worst)");
            
            display();
 return 0;
}

void input(int ch)
{
 if(ch==1)
 {
  for(i=1;i<=10;i++)
   tarr[i]=i;
  for(i=1;i<=100;i++)
   harr[i]=i;
  for(i=1;i<=1000;i++)
   tharr[i]=i;
  for(i=1;i<=10000;i++)
   ttharr[i]=i;
 }
 if(ch==2)
 {
  for(i=1;i<=10;i++)
   tarr[i]=rand();
  for(i=1;i<=100;i++)
   harr[i]=rand();
  for(i=1;i<=1000;i++)
   tharr[i]=rand();
  for(i=1;i<=10000;i++)
   ttharr[i]=rand();
 }
 if(ch==3)
 {
  for(i=1;i<=10;i++)
   tarr[i]=10-(i-1);
  for(i=1;i<=100;i++)
   harr[i]=100-(i-1);
  for(i=1;i<=1000;i++)
   tharr[i]=1000-(i-1);
  for(i=1;i<=10000;i++)
   ttharr[i]=10000-(i-1);
 }
}

void merge(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        merge(a, beg, mid);
        merge(a, mid + 1, end);
        mergesub(a, beg, mid, end);
    }
}

void mergesub(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)
    LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
    RightArray[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        if(LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

void sortm()
{
    t = clock();
    merge(tarr,1,10);
   t = clock() - t;
   ten[++l] = ((double)t)/CLOCKS_PER_SEC;
   t = clock();
    merge(harr,1,100);
   t = clock() - t;
   hun[++m] = ((double)t)/CLOCKS_PER_SEC;
   t = clock();
    merge(tharr,1,1000);
   t = clock() - t;
   tho[++n] = ((double)t)/CLOCKS_PER_SEC;
   t = clock();
    merge(ttharr,1,10000);
   t = clock() - t;
   ttho[++q]= ((double)t)/CLOCKS_PER_SEC;
}

void display()
{
printf("\n------------------------------------------------------------------------");
  printf("\n");
  printf("1-10");
  for(i=1;i<=3;i++){
   printf("\t\t%f",ten[i]);
  }
  printf("\n");
  printf("1-100");
  for(i=1;i<=3;i++){
   printf("\t\t%f",hun[i]);
   }
  printf("\n");
   printf("1-1000");
  for(i=1;i<=3;i++){
   printf("\t\t%f",tho[i]);
      }
  printf("\n");
   printf("1-10000");
   for(i=1;i<=3;i++){
   printf("\t\t%f",ttho[i]);
   }
printf("\n------------------------------------------------------------------------\n");
}
void emparr(int arr[],int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

void emp()
{
  emparr(tarr,10);
            emparr(harr,100);
            emparr(tharr,1000);
            emparr(ttharr,10000);  
}
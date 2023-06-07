#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#define N 100000

int tarr[N],harr[N],tharr[N],ttharr[N],i,j,l=0,m=0,n=0,q=0;
double ten[3],hun[3],tho[3],ttho[3];
clock_t t;

void input(int);

void quick(int [], int, int);
int partition (int [], int , int);
void sortq();
void display();

int main()
{
            input(1);
            sortq();
            printf("\n------------------------------------------------------------------------");
            printf("\n\t    Ascending(Best)");
            input(2);
            sortq();
            printf("\t    Random(Average)");
             input(3);
            sortq();
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

void quick(int a[], int start, int end)
{
 if (start < end)
 {
  int p = partition(a, start, end);
  quick(a, start, p - 1);
  quick(a, p + 1, end);
 }
}

int partition (int a[], int start, int end)
{
 int pivot = a[end];
 int i = (start - 1);
 for (j = start; j <= end - 1; j++)
 {
  if (a[j] < pivot)
  {
   i++;
   int t = a[i];
   a[i] = a[j];
   a[j] = t;
  }
 }
 int t = a[i+1];
 a[i+1] = a[end];
 a[end] = t;
 return (i + 1);
}

void sortq()
{
    t = clock();
   quick(tarr,1,10);
   t = clock() - t;
   ten[++l] = ((double)t)/CLOCKS_PER_SEC;
   t = clock();
   quick(harr,1,100);
   t = clock() - t;
   hun[++m] = ((double)t)/CLOCKS_PER_SEC;
   t = clock();
   quick(tharr,1,1000);
   t = clock() - t;
   tho[++n] = ((double)t)/CLOCKS_PER_SEC;
   t = clock();
   quick(ttharr,1,10000);
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

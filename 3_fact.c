#include<stdio.h>
#include <time.h>
#include<stdlib.h>

clock_t t;
double fact[2],fibb[2];
int i;

void input();
int wtf(int);
int tf(int,int);
int wtfib(int);
int tfib(int,int,int);
void display(int);

int main()
{
 int ch;
 printf("\n----------------------------------------------------------------");
 printf("\n\t\t\t\t\t\t MAIN MENU");
 printf("\n----------------------------------------------------------------");
 printf("\n 1. Factorial \n 2. Fibonacci \n 3. Quit");
 printf("\n----------------------------------------------------------------");
 do
 {
 printf("\nEnter your choice : ");
 scanf("%d",&ch);
 printf("\n----------------------------------------------------------------");

switch(ch)
{
 case 1: input(ch);
         display(ch);
         break;

 case 2: input(ch);
         display(ch);
         break;

 case 3: printf("\n Exiting program...\n");
          printf("\n----------------------------------------------------------------");
         break;

 default:  printf("Invalid choice. Try again.\n");
           break;
}
}while(ch!=3);
return 0;
}

void input(int ch)
{
    int num,result;
    printf("\nEnter a non-negative integer: ");
    scanf("%d", &num);
    if (num < 0)
        printf("Error: Factorial and Fibonacci series are not defined for negative numbers.\n");
    else
     {
         if(ch==1)
          {
             t = clock();
             result=wtf(num);
             t = clock() - t;
             fact[1] = ((double)t)/CLOCKS_PER_SEC;
             t = clock();
             result=tf(num,1);
             t = clock() - t;
             fact[2] = ((double)t)/CLOCKS_PER_SEC;
          }
          if(ch==2)
          {
             t = clock();
           for ( i=0; i<num; i++) {
                    result = wtfib(i);
                }
            t = clock() - t;
            fibb[1] = ((double)t)/CLOCKS_PER_SEC;
            t = clock();
            for ( i=0; i<num; i++) {
                    result = tfib(i, 0, 1);
                }
             t = clock() - t;
            fibb[2] = ((double)t)/CLOCKS_PER_SEC;
          }
     }
}

int wtf(int n)
{
    if (n == 0) {
        return 1;
    }
    else {
        return n * wtf(n-1);
}
}

int tf(int n,int acc)
{
    if (n == 0) {
        return acc;
    }
    else {
        return tf(n-1, n*acc);
    }
}

int wtfib(int n)
{
    if (n <= 1) {
        return n;
    }
    else {
        return wtfib(n-1) + wtfib(n-2);
    }
}

int tfib(int n,int a,int b)
{
  if (n == 0) {
        return a;
    }
    else if (n == 1) {
        return b;
    }
    else {
        return tfib(n-1, b, a+b);
    }
}

void display(int ch)
{
    printf("\n----------------------------------------------------------------");
    printf("\n\t\t\t   Without Tail \tWith Tail");
    printf("\n----------------------------------------------------------------");
      printf("\n");
  if(ch==1)
  {
  printf("Factorial");
  for(i=1;i<=2;i++)
  {
   printf("\t\t%f",fact[i]);
  }
  }
  if(ch==2)
  {
  printf("Fibbonaci");
  for(i=1;i<=2;i++)
  {
   printf("\t\t%f",fibb[i]);
  }
  }
    printf("\n----------------------------------------------------------------");
}

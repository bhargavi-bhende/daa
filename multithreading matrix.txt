
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define M 3
#define K 2
#define N 3
#define NUM_THREADS 10
int A [M][K] = { {1,4}, {2,5}, {3,6} };
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];
struct v {
   int i; /* row */
   int j; /* column */
};
void *runner(void *param); /* the thread */
int main(int argc, char *argv[]) {
   int i,j, count = 0;
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         struct v *data = (struct v *) malloc(sizeof(struct v));
         data->i = i;
         data->j = j;
         pthread_t tid;       //Thread ID
         pthread_attr_t attr; //Set of thread attributes
         pthread_attr_init(&attr);
         pthread_create(&tid,&attr,runner,data);
         pthread_join(tid, NULL);
         count++;
      }
   }
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}
void *runner(void *param) {
   struct v *data = param; // the structure that holds our data
   int n, sum = 0; //the counter and sum
   for(n = 0; n< K; n++){
      sum += A[data->i][n] * B[n][data->j];
   }
   C[data->i][data->j] = sum;
   pthread_exit(0);
}

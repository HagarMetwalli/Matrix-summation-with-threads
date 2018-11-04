#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define thread_num 6
#define H 3

pthread_t threads[thread_num];
int A[H][H] = { {1,2,3}, {1,2,3}, {1,2,3} },
    B[H][H] = { {4,5,6}, {4,5,6}, {4,5,6} },
    sum[H][H];

void* Add(void* arg)
{
	int i, j;
	for (i = 0; i < H; i++)
		for (j = 0; j < H; j++)
			sum[i][j] = A[i][j] + B[i][j];
}


int main()
{
    int i, j, it = 0;

    for(i = 0; i < thread_num; i++)
      pthread_create(&threads[i], NULL, &Add, (void*)it++);


    for(i = 0; i < thread_num ; i++)
      pthread_join(threads[i], NULL);



    printf("\nSum:\n");
    for (i = 0; i < H; i++)
    {
      for (j = 0; j < H; j++)
        printf("%d ", sum[i][j]);

      printf("\n");
    }

    return 0;
}
/////////////////////////////////////////////
// Thread id
/*
pthread_t threadId;

// Create a thread that will function threadFunc()
int err = pthread_create(&threadId, NULL, &threadFunc, NULL);
// Check if thread is created sucessfuly
pthread_create() returns the error code to specify the result of t*/

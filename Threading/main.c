#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum =0 ;

void* threading(void* x)
{
    for(int  i =0 ; i< atoi(x); i++)
        sum += i;

    // sucessfully end
    pthread_exit(0);

}

int main(int argc , char*argv[])
{
    if(argc != 2) {
	printf("error");
	exit(0);
    }
    // thread id
    pthread_t tid;
    // threaads attributs (will not study in details)
    pthread_attr_t attr;
    // get the default attributs
    pthread_attr_init(&attr);
    // create the thread
    pthread_create(&tid,&attr,threading,argv[1]);
    // wait for the thread to be finished
    pthread_join(tid,NULL);

    printf("Sum=%d",sum);
    return 0;
}

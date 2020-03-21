#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
        int ID = 0;
        key_t key = 5678;
        char* pointerShm;
        int SharedMemorySize = 10;
        // int shmget(key_t key, size_t size, int shmflg);
        // get the shared memory or creates it
        // key = id of the shared memory ,size = size of memory , flags is to set shared memory options
        // 0666 is used in chmod to change permessions (none user group world) (0 6 6 6), ["write":4,"read":2,"readWrite":6,"executable":1]
        // IPC_CREAT is to create process , if it is already exists .. remove it
        ID = shmget(key,SharedMemorySize, 0666);
        if(ID < 0) {perror("Creation Error") ; exit(1);}
        puts("Created !");
        // void *shmat(int shmid, const void *shmaddr,int shmflg);
        // attach the shared memory to the calling process (if the shmaddr != NULL)
        // if shmaddr == NULL , the OS Chooses a suitable memory location and returns it , shmflg : i don't know search for it please :D
        pointerShm = shmat(ID,NULL,0);
        if (pointerShm == (char*)-1) {perror("Attatching Error"); exit(1);}
        puts("Attatched !");

        puts(pointerShm);
        // client changes the shared memory
        char* temp = pointerShm;
        for (int i =0 ; i < 3; i++)
            *temp++ = 'A' + i;

        puts(pointerShm);
        return 0;
}

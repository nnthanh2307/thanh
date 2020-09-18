#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include <pthread.h>

// sem_id
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

using namespace std;

// sharing memory between processes
// int main() {
//     pthread_mutexattr_t attributes;
//     pthread_mutexattr_init(&attributes);
//     pthread_mutexattr_setpshared(&attributes, PTHREAD_PROCESS_SHARED);

//     int handle = shm_open("/shm", O_CREAT | O_RDWR, 0777);
//     ftruncate(handle, 2048 * sizeof(int));
//     char *memory = (char*)mmap(0, 2048 * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, handle, 0);

//     //mutex share -> set mutex address at begin of the shared memory
//     pthread_mutex_t *mutex = (pthread_mutex_t*) memory;
//     pthread_mutex_init(mutex, &attributes);
//     pthread_mutexattr_destroy(&attributes);

//     cout<< "Memory address: "<< &memory<< endl;


//     // variable share -> at right after muxtex
//     int* count = (int*)(memory + sizeof(pthread_mutex_t));
//     *count = 0;

//     cout<< "count address: "<< &count<< endl;;

//     cout << "Initial count = "<< *count<< endl;

//     int value_returned_from_child = 0;
//     pid_t pid = fork();

//     if(pid == 0){
//         pthread_mutex_lock(mutex);
//         (*count)++;
//         cout<< "Child Process increased the count to "<< *count << endl;
//         pthread_mutex_unlock(mutex);
//         value_returned_from_child = 99;
//     }

//     else{
//         int status;
//         cout<< "pid of child process: "<< pid<< endl;
//         // waiting for the child process to finish
//         waitpid(pid, &status, 0);
//         value_returned_from_child = WEXITSTATUS(status);
//         cout<< "value return from child = "<< value_returned_from_child << endl;
//         pthread_mutex_lock(mutex);
//         (*count)++;
//         cout<< "Parent process increased the count to "<< (*count)<< endl;
//         pthread_mutex_unlock(mutex);
//     }

//     munmap(memory, 2048*sizeof(int));
//     shm_unlink("/shm");
//     return value_returned_from_child;

// }

// Sharing semaphores between processes
// sem_post: increase couter -> 1, sem_wait: wait counter > 0 and decrease by 1; sem_trywait: decrease counter by 1

// int main(){
//     sem_t *sem_id = sem_open("/sema", O_CREAT, 0777, 0);

//     pid_t pid = fork();
//     if(pid == 0){
//         cout << "Child: done, release semaphore"<< endl;
//          sem_post(sem_id);
//         sleep(2);
//         if(sem_wait(sem_id) < 0)
//             cout<< "Child: [sem_wait] failed" << endl;
//          cout<< "Child: wait semaphore Done"<< endl;

//         sem_close(sem_id);
//     } else {
//         int status;
//         if(sem_wait(sem_id) < 0)
//             cout<< "Parent: [sem_wait] failed" << endl;
//         cout<< "Parent: child printed" << endl;
//         sem_post(sem_id);
//         sem_close(sem_id);
//         sem_unlink("/sema");
//         wait(&status);
//         cout<<"Parent done" << endl;
//     }
//     return 0;
// }

// Sharing between processes - message queues
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <string.h>
// #include <sys/wait.h>
// #include <mqueue.h>

// #define PMODE 0655

// int main(){
//     int status;
//     struct mq_attr attr;
//     attr.mq_maxmsg = 10;
//     attr.mq_msgsize = 20;


//     pid_t pid = fork();
//     // child process: sending message
//     if(pid ==0){
//         char message[20];
//         strncpy(message, "Hello parrent!", 14);

//         mqd_t mqfd = mq_open("/msgqueue", O_WRONLY | O_CREAT, PMODE, &attr);
//         if(mqfd == -1){
//             perror("Child mq_open failure");
//             exit(0);
//         }

//         status = mq_send(mqfd, message, strlen(message), 0);
//         if(status == -1){
//             perror("mq_send failure\n");
//         }
//         else{
//             cout<<"Child is sending message: "<< message << endl;
//             cout << "mq_send successful" << endl;
//         }

//         mq_close(mqfd);
//         cout<< "Child process done" << endl;
//     }

//     // parent - receiving message
//     else{
//         //read only
//         mqd_t mqfd = mq_open("/msgqueue", O_RDONLY|O_CREAT, PMODE, &attr);
//         if(mqfd == -1){
//             perror("Parrent mq_open failure");
//             exit(0);
//         }
//         // parrent is waiting for the child process to finish
//         waitpid(pid, &status, 0);
//         char buff[100];
//         status = mq_receive(mqfd, buff, 100, 0);
//         if(status == -1){
//             perror("mq_receive failure\n");
//         } else{
//             cout<< "mq_receive successful: " << buff << endl;
//         }
//         mq_close(mqfd);
//         mq_unlink("/msgqueue");
//         cout<< "Parent process done"<< endl;
//     }
//     return 0;
// }

// Sharing between processes - Pipes: Anonymous Pipe, Named Pipes.
// Anonymous Pipe
// #include <stdio.h>
// #include <unistd.h>
// int main(){
//     int status, myPipe[2];
//     pipe(myPipe); // create the pipe
//     pid_t pid = fork();

//     // Child process
//     if(pid == 0){
//         close(myPipe[0]); // close nused read end
//         write(myPipe[1], "abc", 3);
//         cout<<"Child process send 'abc'" << endl;
//         close(myPipe[1]);
//     }

//     // Parent process
//     else{
//         char buffer[21];
//         close(myPipe[1]); // close unused write end
//         int pid_child = wait(&status);
//         int length = read(myPipe[0], buffer, 20);
//         buffer[length] = '\0';
//         cout<<"Parent process received: "<< buffer << endl;
//         close (myPipe[0]);
//     }


//     return 0;
// }

//----Named Pipe------------------
#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
    int status;
    mknod("/tmp/pipefile", S_IFIFO|S_IRUSR|S_IWUSR, 0);
    pid_t pid = fork();
    /* Child Process */
    if(pid == 0){
        int myPipe = open("/tmp/pipefile", O_WRONLY);
        write(myPipe, "abc", 3);
        cout << "Child process sent abc" << endl;
        close(myPipe);
    }
    /* parent process */
    else{
        int myPipe = open("/tmp/pipefile", O_RDONLY);
        char buffer[21];
        int pid_child = wait(&status);
        int length = read(myPipe, buffer, 20);
        buffer[length] = '\0';
        cout << "Parent process received " << buffer << endl;
        close (myPipe);
    }
    unlink("/tmp/pipefile");
    return 0;
}
// Sharing between processes - Soket
// sharing between processes - Signal

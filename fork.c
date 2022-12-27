#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    int pid;

    printf("The parent pid is %d\n",getpid());

    for(int i=1;i<=5;i++)
    {
        pid=fork();

        if(pid<0)
        {
            printf("Fork failed\n");
            return 0;
        }
        else if(pid==0)
        {
            printf("The child %d pid is %d\n",i,getpid());
            return 0;
        }
        wait(NULL);
    }

    return 0;
}
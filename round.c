#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid,bt,wt,tt;
};

int main(){
    int n,ttt=0,twt=0;
    float avgwt,avgtt;
    int flag=0;

    printf("Enter the number of process: ");
    scanf("%d",&n);

    struct process p[n];
    int rembt[n];

    for(int i=0;i<n;i++){
        printf("Enter the burst time for process %d: ",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
        rembt[i]=p[i].bt;
    }
    int tq,time=0;

    printf("Enter the time quantam: ");
    scanf("%d",&tq);


    while(flag==0)
    {
        flag=1;
        for(int i=0;i<n;i++)
        {
            if(rembt[i]>tq)
            {
                rembt[i]-=tq;
                time+=tq;
                flag=0;
            }
            else if(rembt[i]!=0){
                time+=rembt[i];
                rembt[i]=0;
                p[i].tt=time;
                p[i].wt=time-p[i].bt;
                flag=0;
            }
        }
    }

    printf("Proccess pid\tBT\tWT\tTT\n");

    for(int i=0;i<n;i++)
    {
        printf("\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
    }
    
}

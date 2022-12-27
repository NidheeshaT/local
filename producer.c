#include<stdio.h>
#include<stdlib.h>

int main()
{
    int producer,bufferSize,consumer,in=0,out=0,items=0;

    printf("Enter the buffer size: ");
    scanf("%d",&bufferSize);
    int buffer[bufferSize];
    while(1)
    {
        int ch;

        printf("1.Produce 2.Consume 3.Exit\n");
        scanf("%d",&ch);

        if(ch==1)
        {
            if(items==bufferSize)
                printf("Buffer is full\n");
            else{
                printf("Enter the item to produced: ");
                scanf("%d",&producer);
                buffer[in]=producer;
                in =(in+1)%bufferSize;
                items++;
            }
        }
        else if(ch==2)
        {
            if(items==0)
                printf("Buffer is empty\n");
            else{
                consumer=buffer[out];
                out =(out+1)%bufferSize;
                items--;
                printf("Item consumed: %d\n",consumer);
            }
        }
        else{
            break;
        }

    }
    return 0;
}
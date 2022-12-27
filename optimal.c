#include<stdio.h>
#include<stdlib.h>
int n,f;

int optimal(int ref[],int frames[],int index)
{
    int opt[f];

    for(int i=0;i<f;i++)
    {
        int found=0;
        for(int j=index;j<n;j++)
        {
            if(ref[j]==frames[i])
            {
                found=1;
                opt[i]=j;
                break;
            }
        }

        if(!found)
            return i;
    }

    int max=opt[0];
    int k=0;

    for(int i=1;i<f;i++)
    {
        if(opt[i]>max)
        {
            k=i;
            max=opt[i];
        }
    }
    return k;
}

int main()
{
    int i,j,found;

    printf("Enter the number of pages: ");
    scanf("%d",&n);

    printf("Enter the number of frames: ");
    scanf("%d",&f);

    int ref[n],frames[f];

    printf("Enter the reference string: ");
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);

    for(i=0;i<f;i++)
        frames[i]=-1;

    int victim=-1;
    int count=0,pf=0;

    for(i=0;i<n;i++)
    {
        found=0;

        for(j=0;j<f;j++)
        {
            if(frames[j]==ref[i])
            {
                found=1;
                break;
            }
        }

        if(!found)
        {
            if(count<f)
            {
                victim=count++;
                frames[victim]=ref[i];
                pf++;
            }
            else{
                victim=optimal(ref,frames,i);
                frames[victim]=ref[i];
                pf++;
            }
        }

        printf("%d --> ",ref[i]);
        for(j=0;j<f;j++)
        {
            printf("%d ",frames[j]);
        }
        if(found)
            printf("Page hit\n");
        else
            printf("Page miss\n");
    }

    printf("The number of page faults %d \n",pf);
    return 0;
}
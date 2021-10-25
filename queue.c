
#include<stdio.h>
#include<stdlib.h>
int show(int *array,int *front,int *rear)
{
    if((*rear)!=-1)
    {
        for(int i=(*front);i<=(*rear);i++)
        {
            printf("%d\n",array[i]);
        }
    }
    else
    {
        printf("Sorry No element in the array!!\n");
    }
}
int enqueue(int*array,int*front,int*rear,int*size)
{
    if((*rear)<(*size)-1)
    {
        int ele;
        if((*front)==-1)
            {
                (*front)++;
                printf("Front setted!!\n");
            }
        (*rear)++;
        printf("Enter the element in the queue:\t");
        scanf("%d",&ele);
        array[(*rear)]=ele;
    }
    else
    {
        printf("Sorry, the Queue Overflow!!!\n");
    }
    return 0;

}
int dequeue(int *array,int *front,int *rear,int *size)
{
    if((*front)==-1||(*front)>(*rear))
    {
        printf("sorry , queue underflow!!!\n");
    }
    else
    {
        (*front)=(*front)+1;

    }

    return 0;
}
int main()
{
    int *array,p=1,size,choice;
    int front=-1,rear=-1;
    printf("Enter the size in queue:\t");
    scanf("%d",&size);
    array=(int*)malloc(size*sizeof(int));
    while(p!=0)
    {
    printf("\n1.Show\n2.En-queue\n3.De-queue\n4.Exit\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:show(array,&front,&rear);break;
        case 2:enqueue(array,&front,&rear,&size);break;
        case 3:dequeue(array,&front,&rear,&size);break;
        case 4:p=0;break;
    }
    }
    return 0;
}

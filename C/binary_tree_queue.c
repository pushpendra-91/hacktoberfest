#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}node;

typedef struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
}queue;

void create(queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (node **) malloc (q->size*sizeof(node *));
}

void enqueue(queue *q, node *x)
{
    if ((q->rear+1)%q->size == q->front)
        printf("Queue is full!!\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

node *dequeue(queue *q)
{
    node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is empty!!\n");
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isempty(queue q)
{
    return q.front == q.rear;
}

node *root = NULL;
int arr[100];
int size=0;

void treeCreate()
{
    node *p, *t;
    int x;
    queue q;
    create(&q, 100);

    printf("Enter root value : ");
    scanf("%d", &x);
    root = (node *) malloc (sizeof(node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    size++;
    arr[0] = x;

    while (!isempty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (node *) malloc (sizeof(node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
            size++;
            arr[size-1] = x;
        }
        printf("Enter right child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (node *) malloc (sizeof(node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
            size++;
            arr[size-1] = x;
        }
    }
}

void preOrder(node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

void postOrder(node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

int main() 
{
    treeCreate();

    printf("The tree is : ");
    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The preorder is : ");
    preOrder(root);
    printf("\n");

    printf("The postorder is : ");
    postOrder(root);
    printf("\n");

    printf("The inorder is : ");
    inOrder(root);
    printf("\n");


    return 0;
}
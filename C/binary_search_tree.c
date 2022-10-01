#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}node;

node *root = NULL;
int arr[100];
int size=0;

void insert(int key)
{
    node *t = root;
    node *p, *r;

    if (root == NULL)
    {
        size++;
        arr[0] = key;

        p = (node *) malloc (sizeof(node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    size++;
    arr[size-1] = key;

    p = (node *) malloc (sizeof(node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void searchKey(int key)
{
    int index = 0;
    node *p = root;
    while (p != NULL)
    {
        if (key > p->data)
            p = p->rchild;
        else if (key < p->data)
            p = p->lchild;
        else
        {
            printf("%d found at index %d of the BST (we have not returned anything, and only found the index here)!!\n", key, index);
            return;
        }
        index++;
    }
    printf("%d not present in the BST!!\n", key);
}

int Height(node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

node *inPre(node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

node *inSucc(node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
}

node *delete(node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        return NULL;
    }

    if (key > p->data)
        p->rchild = delete(p->rchild, key);
    else if (key < p->data)
        p->lchild = delete(p->lchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            node *q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = delete(p->lchild, q->data);
        }
        else
        {
            node *q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = delete(p->rchild, q->data);
        }
    }
}

node * searchNode(int key)
{
    int index = 0;
    node *p = root;
    while (p!=NULL)
    {
        if (key > p->data)
            p = p->rchild;
        else if (key < p->data)
            p = p->lchild;
        else
        {
            printf("%d found at index %d of the BST (we have returned the node here)!!\n", key, index);
            return p;
        }
        index++;
    }
    printf("%d not present in the BST!!\n", key);
    return NULL;
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

void displayTree()
{
    printf("The tree is : ");
    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, x;
    printf("How many elements do you want to insert into the BST? : ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        printf("Enter element at position %d : ", i+1);
        scanf("%d", &x);
        insert(x);
    }

    displayTree();

    printf("The inorder is : ");
    inOrder(root);
    printf("\n");

    printf("Enter number to be searched in the BST : ");
    scanf("%d", &x);
    searchKey(x);
    node *searchedNode = searchNode(x);

    printf("Enter the key you want to delete : ");
    scanf("%d", &x);
    delete(root, x);

    displayTree();

    return 0;
}
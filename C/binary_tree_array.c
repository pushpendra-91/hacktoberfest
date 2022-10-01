#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int *arr;
    int curSize;
} node;

node *tree;

void initializeTree()
{
    tree = (node *) malloc (sizeof(node));
    tree->arr = (int *) malloc (sizeof(int));
    tree->curSize = 1;
    int rootVal;
    printf("Enter value of root of the tree : ");
    scanf("%d", &rootVal);
    tree->arr[0] = rootVal;
}

void addLeft()
{
    int leftVal;
    tree->curSize++;
    printf("Enter the value of the left child : ");
    scanf("%d", &leftVal);
    tree->arr = (int *) realloc (tree->arr, sizeof(int)+1);
    tree->arr[tree->curSize-1] = leftVal;
}

void addRight()
{
    int rightVal;
    tree->curSize++;
    printf("Enter the value of the right child : ");
    scanf("%d", &rightVal);
    tree->arr = (int *) realloc (tree->arr, sizeof(int)+1);
    tree->arr[tree->curSize-1] = rightVal;
    printf("%d", tree->arr[tree->curSize-1]);
}

void inorderTraversal()
{
    int count = 0;
    int maxsize = tree->curSize+1;
    float levels = log10(maxsize)/log10(2);
    int index = (maxsize)/2;
    printf("INORDER TRAVERSAL : ");
    while (count < maxsize-1)
    {
        if (index != -1)
        {
            printf("%d ", index);
        }
        if (index == 1)
        {
            index = maxsize - pow(2,levels-2);
        }
        else if (index*2 >= maxsize && index%2==0)
        {
            index = index/2;
        }
        else if (index*2 >= maxsize && index%2==1)
        {
            index = index/4;
        }
        else if (index*2 < maxsize && index%2==0)
        {
            index = index*2+1;
        }
        else if (index*2 < maxsize && index%2==1)
        {
            index = index*2+1;
        }
        count++;
    }

}

void printTree()
{
    printf("The tree is : ");
    for (int i=0; i<tree->curSize-1; i++)
    {
        if (tree->arr[i] != -1)
        {
            printf("%d ", tree->arr[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("%d\n", tree->arr[tree->curSize-1]);
}

int main() 
{
    int levels;
    printf("Enter the number of levels in your binary tree : ");
    scanf("%d", &levels);
    initializeTree();
    int nodes = pow(2,levels) - 1;
    for (int i=0; i<levels-1; i++)
    {
        for (int j=0; j<pow(2,i); j++)
        {
            addLeft();
            addRight();
        }
    }
    printTree();

    inorderTraversal();
    
    return 0;
}
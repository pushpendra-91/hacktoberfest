#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *arr[50];
int curTreeNodes = 0;

void initializeTree()
{
    arr[0] = (node *) malloc (sizeof(node));
    curTreeNodes++;
    printf("Enter root node : ");
    scanf("%d", &arr[0]->data);
    arr[0]->left = arr[0]->right = NULL;
}

void displayTree()
{
    printf("The tree is : ");
    for (int i=0; i<curTreeNodes; i++)
    {
        if (arr[i]->data != -1)
        {
            printf("%d ", arr[i]->data);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void addLevel()
{
    int minIndex = curTreeNodes;
    int maxIndex = (minIndex*2);
    for (int i= minIndex; i<=maxIndex; i++)
    {
        arr[i] = (node *) realloc (arr[i], sizeof(node)+1);
        if (i%2==0)
        {
            printf("Enter right child : ");
            scanf("%d", &arr[i]->data);
            arr[i]->left = arr[i]->right = NULL;
        }
        else
        {
            printf("Enter left child : ");
            scanf("%d", &arr[i]->data);
            arr[i]->left = arr[i]->right = NULL;
        }
        curTreeNodes++;
    }
}

void createLinks()
{
    int sub = pow(2, log10(curTreeNodes+1)/log10(2) - 1);
    arr[0]->left = arr[1];
    arr[0]->right = arr[2];
    for (int i=1; i<curTreeNodes - sub; i++)
    {
        arr[i]->left = arr[i*2 + 1];
        arr[i]->right = arr[i*2 + 2];
    }
}

void deleteNode()
{
    int index;
    printf("Enter index of the node to be deleted : ");
    scanf("%d", &index);

    if (index == curTreeNodes-1)
    {
        free(arr[index]);
        curTreeNodes--;
    }
    else
    {
        arr[index]->data = arr[curTreeNodes-1]->data;
        free(arr[curTreeNodes-1]);
        curTreeNodes--;
    }
}

void inorderTraversal()
{
    int count = 0;
    int maxsize = curTreeNodes+1;
    int levels = (int)log10(curTreeNodes+1)/log10(2);
    int index = (curTreeNodes+1)/2;
    printf("INORDER TRAVERSAL : ");
    while (count < curTreeNodes)
    {
        if (index != -1)
        {
            printf("%d ", index);
        }
        if (index == 1)
        {
            index = curTreeNodes + 1 - pow(2,levels-2);
        }
        else if (index*2 >= curTreeNodes+1 && index%2==0)
        {
            index = index/2;
        }
        else if (index*2 >= curTreeNodes+1 && index%2==1)
        {
            index = index/4;
        }
        else if (index*2 < curTreeNodes+1 && index%2==0)
        {
            index = index*2+1;
        }
        else if (index*2 < curTreeNodes+1 && index%2==1)
        {
            index = index*2+1;
        }
        count++;
    }
    printf("\n");

}

int main()
{
    printf("INITIALIZING THE TREE : \n");
    initializeTree();
    displayTree();

    int choice;
    char ans = 'y';
    while (ans == 'y')
    {
        printf("MENU\n");
        printf("1. Add level to the tree.\n");
        printf("2. Display the binary tree.\n");
        printf("3. Delete node from the tree.\n");
        printf("4. Print the inorder traversal order.\n");
        printf("Enter you choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addLevel();
            createLinks();
        }
        else if (choice == 2)
        {
            displayTree();
        }
        else if (choice == 3)
        {
            deleteNode();
        }
        else if (choice == 4)
        {
            inorderTraversal();
        }

        printf("Do you want to continue (y/n) ? : ");
        scanf(" %c", &ans);
    }
}
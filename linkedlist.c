#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node* link;
};

struct node* root = NULL;

void addend()
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value of node : ");
    scanf("%d",&newnode->data);
    newnode->link = NULL;

    if(root == NULL)
    root = newnode;

    else
    {
        struct node* tmp = root;
        while(tmp->link != NULL)
        tmp = tmp->link;
        tmp->link = newnode;
        
    }
}

void display()
{
    if(root == NULL)
    printf("Linked List is empty\n");

    else{
        struct node* tmp = root;
        while(tmp != NULL)
        {
            printf("%d -> ",tmp->data);
            tmp = tmp->link;
        }
    }
}

int length()
{
    if(root == NULL)
    return 0;

    else{
        int c = 0;
        struct node* tmp = root;
        while(tmp != NULL)
        {
            c++;
            tmp = tmp->link;
        }
        return c;
    }
}

void addbegin()
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value of node : ");
    scanf("%d",&newnode->data);
    newnode->link = NULL;

    if(root == NULL)
    root = newnode;

    else
    {
       newnode->link = root;
       root = newnode;
    }
}

void addafter()
{
    int pos;
    printf("Enter position of node : ");
    scanf("%d",&pos);

    if(pos>length())
    printf("Position is greater than Length");
    
    else{
       struct node* newnode;
       newnode = (struct node*)malloc(sizeof(struct node));
       printf("Enter value of node : ");
       scanf("%d",&newnode->data);
       newnode->link = NULL;

    if(root == NULL)
    root = newnode;

    else if(pos == 1)
    {
       newnode->link = root;
       root = newnode;
    }

    else
    {
        int i = 1;
        struct node* tmp = root;
        while(i<pos)
        {
            i++;
            tmp = tmp->link;
        }
        newnode->link = tmp->link;
        tmp->link = newnode;
    }
   }
}

void delet()
{
    if(root == NULL)
    {
        printf("Linked List is Empty\n");
    }

    int pos;
    printf("Enter position to delete : ");
    scanf("%d",&pos);

    if(pos>length())
    printf("Position does not exists\n");

    else{
        if(pos == 1)
        {
            struct node* p = root;
            root = root->link;
            p->link = NULL;
            free(p);
            return;
        }
        int i = 0;
        struct node* p = root;
        struct node* q;
        while(i<pos)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p = q->link;
        q->link = NULL;
        free(q);
    }
}

void main()
{
   while(1)
   {
    printf("Enter 1 to insert node at end \nEnter 2 to insert node at begin\n");
    printf("Enter 3 to insert node after n nodes \nEnter 4 to delete a node \nEnter 5 to display elements\n");
    printf("Enter 0 to exit : ");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        addend();
        break;

        case 2: 
        addbegin();
        break;

        case 3:
        addafter();
        break;

        case 4:
        delet();
        break;

        case 5:
        display();
        break;

        case 0:
        exit(0);
        break;

        default:
        printf("Invalid choice\n");
    }
   }
}
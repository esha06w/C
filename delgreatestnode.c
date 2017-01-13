#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
static struct node* head = NULL;
void add(int item)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    if(head == NULL)
    {
         head = temp;
    }
    else
    {
         struct node* temp1 = head;
         while(temp1->next != NULL)
         {
              temp1 = temp1->next;
         }
         temp1->next = temp;
     }
}
void delgreatest(int item)
{
    while(head != NULL && head->data > item)
    {
         head = head->next;
    }
    struct node* temp = head;
    while(temp != NULL && temp->next != NULL)
    {
         if(temp->next->data > item)
         {
               temp->next = temp->next->next;
         }
         else
         {
               temp = temp->next;
         }
     }
     printf("Deleted"); 
}
struct node* reverse(struct node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    struct node* newnode = head->next;
    struct node* nextnode = newnode->next;
    head->next = NULL;
    while(newnode != NULL)
    {
        newnode->next = head;
        head = newnode;
        newnode = nextnode;
        if(nextnode != NULL)
        {
             nextnode = nextnode->next;
        }
    }
    return head;
}
struct node* delgreaterright(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        if(temp->data > temp->next->data)
        {
             temp->next = temp->next->next;
        }
        else
        {
             temp = temp->next;
        }
    }
    return head;
}
void print(struct node* head)
{
    if(head == NULL)
    return;
    struct node* temp = head;
    while(temp != NULL)
    {
         printf("%d ",temp->data);
         temp = temp->next;
    }
}
int main()
{
    printf("Enter 10 numbers\n");
    int i,num;
    for(i = 0;i < 8;i++)
    {
         scanf("%d",&num);
         add(num);
    }
    print(head);   
/*    printf("\nEnter a number. Numbers greater than this number would be deleted\n");
    int n;
    scanf("%d",&n);
    delgreatest(n);
*/
    struct node* delGreRight =  reverse(head);
    printf("\n");
    delGreRight = delgreaterright(delGreRight);
    delGreRight = reverse(delGreRight);
    print(delGreRight);
}

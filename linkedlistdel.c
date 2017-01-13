#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node* next;
};
struct node* insert(struct node* head,int data)
{
   struct node* temp=head;
   struct node* curr=(struct node*)malloc(sizeof(struct node));
   curr->data=data;
   curr->next=NULL;
   if(head==NULL)
   {
       head=curr;
       return head;
   }
   while(temp->next!=NULL)
   {
       temp=temp->next;
   }
   temp->next=curr;
   return head;
}
void print(struct node* head)
{
   struct node* temp=head;
   while(temp!=NULL)
   {
       printf("%d ",temp->data);
       temp=temp->next;
   }
}
struct node* del(struct node* head,int x)
{
   struct node* temp;
   if(head==NULL)
   return head;
   while(head->data > x)
   {
      head=head->next;
      if(head==NULL)
      {
         return head;
      }
   }
   temp=head;
   while(temp->next!=NULL)
   {
      if(temp->next->data > x)
      {
          temp->next=temp->next->next;
      }
      else
      {
 //         curr=curr->next;
          temp=temp->next;
      }
   }
   return head;
}
main()
{
   struct node* head=NULL;
   head=insert(head,50);
   head=insert(head,40);
   head=insert(head,50);
   head=insert(head,23);
   head=insert(head,530);
   head=del(head,40);
   print(head);
}

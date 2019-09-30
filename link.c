#include<stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *addatbeg (struct node *start, int data)
{
  struct node *tmp;
  tmp = (struct node*)malloc(sizeof (struct node));
  tmp->info = data;
  tmp->link =start;
  start = tmp;
  return start;
  printf("temp is %p\n", tmp);
}
struct node *addatend(struct node*start,int data){
  struct node *tmp,*p;
  tmp = (struct node*)malloc(sizeof(struct node));
  tmp->info =data;
  p = start;
  while (p->link != NULL) {
    p= p->link;
  }
  tmp->link = p->link;
  p->link = tmp;
  return start;
}

struct node *addbefore(struct node *start,int data, int item){
struct node *p,*tmp;

  if (start == NULL)
  {
    printf("list is empty");
  }
  if (start->info == item){
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
  }
  p = start;
  while(p->link!=NULL){
    if (p->link->info == item){
      tmp = (struct node*)malloc(sizeof(struct node));
      tmp->info = data;
      tmp->link = p->link;
      p->link = tmp;
      return start;
    }
    p = p->link;
  }
  printf("item not in the list");
  return start;
}

struct node *addafter(struct node *start,int data,int item){
  struct node *p,*tmp;
  if (start == NULL){
    printf("list is empty");
  }
p = start;
while (p->link!=NULL){
  if (p->info == item){
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = p->link;
    p->link = tmp;
    return start;
  }

  p = p->link;
}
if (p->info == item && p->link ==NULL){
  tmp = (struct node*)malloc(sizeof(struct node));
  tmp->info = data;
  p->link = tmp;
  tmp->link = NULL;
}
return start;
}

void display(struct node* start){
struct node *p;
p=start;
while (p!=NULL) {
  printf("%d", p->info);
  p = p->link;
}

}
int main (){
struct node *start = NULL;
int data[]={4,5,6,7,8};
//printf ("Enter data ");
//scanf("%d",&data);
start = addatbeg(start,6);

//display(start);
//printf("\nEnter at the end");
//scanf("%d",data);
start = addatend(start,8);
start = addbefore(start,5,8);
start = addafter(start,7,8);
display(start);
}

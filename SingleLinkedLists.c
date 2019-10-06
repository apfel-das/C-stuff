#include <stdio.h>
#include <stdlib.h>
struct list {
 int value;
 short id;
 struct list *next;
};
int PrintMenu();
struct list *CreateList();
struct list *InsertNodeList(int val,short ID,struct list *head); /*Inserts a new node at the end of the
existing list and the returns the HEAD of the list-bare in mind that if the the list is empty the node
will be inserted at the start*/
void PrintAllinHierarchy(struct list *head);
void PrintSpecificElement(struct list *head);
struct list *DeleteElement(struct list *head,int v);
void PrintListAdrress(struct list *head);
void PrintListElementAdress(struct list *head);
int main()
{
struct list *node = (struct list *)NULL;
int choice;
int num;
int i=0,j=0,b;
int v;
 do{
 choice = menuPrint();
 if(choice == 1){
 node = CreateList();
 }
 else if(choice == 2){
 printf("Give the value to be inserted\n");
 scanf("%d",&v);
 node=InsertNodeList(v,i+1,node);
 PrintAllinHierarchy(node);
 i++;
 }
else if(choice == 3){
printf("Give the value to be deleted\n");
scanf("%d",&v);
node=DeleteElement(node,v);
PrintAllinHierarchy(node);
}
else if(choice == 4){
SeekandPrint(node);
}
else if(choice == 5){
b=PrintListSize(node);
}
else if(choice == 6){
PrintAllinHierarchy(node);
PrintListElementAdress(node);
}
else if(choice == 7){
PrintListAdrress(node);
}
else if(choice == 8){
PrintSpecificElement(node);
}
else if(choice == 9){
PrintListSizeinBytes(node);
}
}while(choice != 10);
 system("PAUSE");
return 0;
}
struct list *CreateList(){
struct list *ptr=NULL;
return(ptr);
}
struct list *InsertNodeList(int val,short ID, struct list *head){
struct list *ptr=NULL;
struct list *n1=head;  /* n1 will indicate the next position */
struct list  *n2=head;   /* n2 will indicate the previous position */
ptr=(struct list *)malloc(sizeof(struct list));
ptr->value=val;
ptr->id=ID;
ptr->next=NULL;

if( n1 == NULL){
    return ptr; /* ptr is the head of the new list */
}
while ((n1 != NULL) && (val > n1->value))   /*while the list has elements  && those elements have a value less than this of the newly aloccated node proceed */
{
n2=n1; /*assign a pointer to the previous node */
n1=n1->next; /* then proceed to the next-if there isn't any this will just hit a NULLPointer when rechecking the expression and terminate the while loop */
}

if(n1 == head){
    ptr->next=head;
    return ptr;
}

n2->next=ptr;
ptr->next=n1;
return head;


}
void PrintAllinHierarchy(struct list *head){
struct list *ptr=head;
while(ptr != NULL){
 printf("VALUE= %d ID= %d \n",ptr->value,ptr->id);
 ptr=ptr->next;
}
}
void PrintSpecificElement(struct list *head){
struct list *ptr=head;
int pos;
int ctr=0;
printf("Insert the place of the node you wish to print: \n");
fflush(stdin);
scanf("%d",&pos);
while(ctr < pos){
 if((ctr == (pos-1)) && (ptr != NULL)){
 printf("Node at position %d found with value= %d and ID= %d\n",ctr+1,ptr->value,ptr->id);
 printf("The size of the whole node in byte arithmetic is: %d\n",sizeof(struct list));
 printf("Crucial size should be: %d\n",sizeof(ptr->id)+sizeof(ptr->value)+sizeof(ptr->next));
 }
 ctr++;
 ptr=ptr->next;
}
}
int PrintListSize(struct list *head){
struct list *ptr=head;
int ctr=0;
while(ptr != -1){
 ctr++;
 ptr=ptr->next;
}
printf("The list has %d elements \n",ctr);
return(ctr);
}
void PrintListElementAdress(struct list *head){
struct list *ptr=head;
int pos;
int ctr=0;
printf("Insert the place of the node in the list you wish to print: \n");
fflush(stdin);
scanf("%d",&pos);
while(ctr<pos){
 if((ctr==(pos-1)) && (ptr!= (struct list *)NULL)){
 printf("NODE INFO: Node at position %d found with value= %d and ID= %d \n",ctr+1,ptr->value,ptr->id);
 printf("Node's Addresses: Value's Address= %d ID's Address= %d \n",&ptr->value,&ptr->id);
 }

 ctr++;
 ptr=ptr->next;
}
if(ptr =(struct list *) NULL ){
    printf("Unable to find element");

 }
}
void PrintListAdrress(struct list *head){
struct list *ptr=head;
printf("Address of List is the address which head-ptr is linked in= %d ",&head);
}
void SeekandPrint(struct list *head){
struct list *ptr=head;
if(head == NULL){
    printf("Action cant be performed-Empty List Error\n");
    return (head);
}
int v;
printf("Insert the value you seek for\n");
fflush(stdin);
scanf(" %d",&v);
while((ptr != NULL) && (ptr->value != v)){
    ptr=ptr->next;
}
if(ptr == NULL){
  printf("Element not found- NonExistentElement Error \n");
  return;
}
  printf("Element found value=%d id=%d \n",ptr->value,ptr->id);

}
void PrintListSizeinBytes(struct list *head){
struct list *ptr=head;
int k;
k=PrintListSize(ptr);
(k==0)? printf("The list is Empty \n") : printf("The list has size of = %dbytes \n",sizeof(struct list)*k);
}
struct list *DeleteElement(struct list *head,int v){
struct list *ptr;
struct list *n1=head;
struct list *n2=head;
if(head==NULL){
 printf("Unable to Delete/EMPTY LIST\n");
 return (head);
}
if(head->next == NULL)
{  /*list of one element */
    if(v == n1->value )
    {
        free(head);
        head=NULL;
    }
    else
    {
        printf("Unable to perform deletion - Value not found\n");

    }

        return (head);
}
else {
 while((n1->next != NULL) &&(n1->value != v)) { /* search node to delete via value criteria */

 n2=n1;
 n1=n1->next;
 }
 if((n1->value != v)){

    printf("Element non existent \n");
    return head;

 }
 if (n1== head){   /* if we need to delete the head we have to reassign it */
  ptr=head;
  head=n1->next;
  free(ptr);
  return head;



 }
 ptr=n1;
 n2->next=n1->next; /* if we have to delete an inbetween node we have to reassure that the linkage will be re-made */
 free(ptr);

return (head);
}
}
int menuPrint(){
int ch;
printf("Please enter your choice (1-10)");
printf("\n\n\n\nCreate a Simple Linked List (1)\n");
printf("Insert a node on the List (2)\n");
printf("Delete the a node with some value (3)\n");
printf("Search for a node with some value (4)\n");
printf("Print the size of the list-number of elements (5)\n");
printf("Print the address of an item (6)\n");
printf("Print the address of list (7)\n");
printf("Print the size of item- in bytes (8)\n");
printf("Print the size of list- in bytes (9)\n");
printf("Exit (10)\n");
fflush(stdin);
scanf("%d",&ch);
return ch;
}



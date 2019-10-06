#include <stdio.h>
#include <stdlib.h>



struct list{

int procId;
struct list *prev;
struct list *next;

};


//function prototypes

struct list *InsertAtEnd(struct list *someHead,int id,struct list **someTail);
void  PrintList(struct list *someHead,struct list *someTai);

int main()
{

struct list *ptb[2]; //An array to hold base-addresses
struct list *ptbb[2];



//Initialize pointers
struct list *head = NULL;
struct list *tail = NULL;

// Insert some elements manually to play with

head = InsertAtEnd(head,4,&tail);
head = InsertAtEnd(head,6,&tail);
head = InsertAtEnd(head,5,&tail);


//store the base addresses in an Array

ptb[0] = head;
ptbb[0] = tail;


// create another List

head=NULL;
tail = NULL;
head = InsertAtEnd(head,44,&tail);
head = InsertAtEnd(head,66,&tail);
head = InsertAtEnd(head,55,&tail);



ptb[1] = head;
ptbb[1] = tail;

// print the setup to user

printf("\n\nProcess List A: \n");

PrintList(ptb[0],ptbb[0]);

printf("\n\nProcess List B: \n");
PrintList(ptb[1],ptbb[1]);









return 0;
}



struct list *InsertAtEnd(struct list *someHead,int id,struct list **someTail)
{

struct list *ptr = someHead;
//allocate space for a node, and initialize

struct list *node = (struct list *)malloc(sizeof(struct list));
node->procId = id;
node->next = NULL;
node->prev = NULL;

// empty list case
if(someHead == NULL)
    {

    someHead = node;
    return (someHead);


    }

// one-element list
if( someHead->next == NULL)
    {


    someHead->next = node;
    node->prev = someHead;
    return (someHead);



    }
// multiple elements scenario

//iterate the list until last node is found
while(ptr-> next != NULL)
{
    ptr = ptr->next;




}

// fix the linkage
ptr->next = node;
node->prev = ptr;

//mark the tail
*someTail = node;  //reference call and double-pointer notation let's us mark tail and actually returning without a return();


return (someHead);


}



void  PrintList(struct list *someHead,struct list *someTail)
{


    printf("Iterate from start to end: \n\n");

    // Iterate from start
    while(someHead != NULL)
        {



        printf("process id = %d\n",someHead->procId);
        someHead = someHead->next;


        }

   // Iterate from end

     printf("Iterate from end to start: \n\n");

      while(someTail != NULL)
        {



        printf("process id = %d\n",someTail->procId);
        someTail = someTail->prev;


        }




}


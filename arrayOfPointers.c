#include <stdio.h>
#include <stdlib.h>

int main()
{

int A[4]={1,2,3,4}; //an Arrays of Integers
int B[4]= {11,22,33,44}; //a second Array of Integers
int *C[2]; // an Array to store Arrays (base addresses)


printf("Adderesses of A and B = %p, %p\n",A,B);

// Store base-addresses on C

C[0] = A;
C[1] = B;




printf("Addresses stored in C:\n");
for(int i=0; i<2; i++)
    {


    printf("Base Addr. = %p\n",*(C+i));  //just print the base - addresses stored in C
    for(int j=0; j<4; j++)
    {

        printf("%d\n",*(*(C+i)+j)); //iterate the whole array (A or B) using the outer array (C)


    }
    }





return 0;
}


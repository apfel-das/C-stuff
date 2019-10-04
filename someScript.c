#include <stdio.h>
#include <stdlib.h>

int triangleCheck(int num);
int inputMenu(int n);
int EvenOddChecker(int num);
int *multiply(int *A,int *B);

int main()
{
   int A[5],C[5];
   int ch = 0;
   int i = 0;





   ch=inputMenu(0);

   while (ch != 4)
{

   if(ch == 1)
   {

       printf("Insert a top-limit %d\n");
       fflush(stdin);
       scanf("%d"  ,&i);
       i=triangleCheck(i);
       printf("The sum of all printed elements is = %d\n",i);
   }
   if(ch == 2)
    {
        //Task is to check whether is an even or odd number
        printf("Insert any number (negatives will also do) \n");
        scanf("%d", &i);
        i=EvenOddChecker(i);

        if ( i == 0)
        {
            printf("Number is Even \n");
        }
        else
        {

            printf("Number is Odd \n");
        }
            printf("Result produced with bitwise and (num & 1) \n");
        }


   if(ch == 3)
   {
        //Task is to multiply by 5 contents of A, without using multiplication

        printf("Old Arrays has: \n");
        for(int i=0; i<5; i++)
        {
                    A[i]=i;
                    printf("A[%d] = %d\n",i,A[i]);

        }

        int *c=multiply(A,C);

        printf("New array has: \n");
        for(int j=0; j<5; j++)
        {
            printf("C[%d] = %d\n",j,*(c+j));  //pointer notation used here
        }

   }
   ch=inputMenu(ch);
}
}

int triangleCheck(int num){

int sum=0;
for(int i=1; i<=num; i++){
    for(int j=1; j<=i; j++){

        printf("%4d",j);  //formating made via %4d
        sum = sum + j;

    }
printf("\n");



}
return(sum);

}
int inputMenu(int n){


fflush(stdout);

printf("Please Enter a choice (1-4)\n");
printf("1 - Formatted Triangle print\n");
printf("2 - Even or Odd?\n");
printf("3 - Transferring data with Arrays\n");
printf("4 - Terminate\n");

scanf("%d",&n);
return n;


}

int EvenOddChecker(int num)
{

int retval = 0;

if(  (num & 1) == 1)
{
            retval = 1;

}
return (retval);

}


int* multiply(int A[],int B[]){

for(int i=0; i<5; i++){
    B[i]=0;
    for(int j=0; j<5; j++){
        B[i]=A[i]+B[i];
    }




}
return (B);




}




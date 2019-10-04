#include <stdio.h>
#include <stdlib.h>

int main()
{
 int A[4];
 int pairs,s;


 //Initialise array
  for(int i =0; i<4; i++)
    {

    printf("Insert value in matrix: \n");
    scanf("%d",&A[i]);


    }
//Print Array just for optical confirmation
  for(int i =0; i<4; i++)
    {

    printf("Arr[%d] = %d \n",i,A[i]);



    }

// Possible sum as input    

    printf("Insert the sum you wish to find \n");
    scanf("%d",&s);
    pairs = sumFinder(s,A,4); //call by value


//check the outcome
  if(pairs != 0)
    {

    printf("Found %d pair",pairs);

    }
   else
    {

    printf("No pair was found");

    }


  return 0;
}
int sumFinder(int sum, int Arr[], int n)
{
    int count =0;
    int curr,prev;
    int  next=  1;
    curr = 0;

    while (next < n)
        {

        if( Arr[curr] + Arr[next] == sum )   //base case
        {
            count +=1; //count = count +1;


        }
        next++;
        if((next == n) && (curr != n))  // if next pointer reaches end, this combination doesnt work so reassign to next pair.
            {

            curr++;
            next = curr + 1;


            }



        }

 return count;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subFinder(char A[],char B[],int alen,int blen);

int main()
{

    char A[100];
    char B[100];
    int alen,blen;
    fflush(stdin);
    printf("Insert substring: ");
    scanf("%s",&A);
    printf("Insert string: ");
    scanf("%s",&B);
    alen=strlen(A);
    blen=strlen(B);
    printf("You inserted: \n%s (%d)\n%s (%d)\n",A,alen,B,blen);
    int n=subFinder(A,B,alen,blen);
    printf("Times Found: %d",n);

}
int subFinder(char A[],char B[],int alen,int blen)
{

int wordCount=alen;
int digCount=0;
int totkeys=0;
int j=0;
for(int i=0; i<blen; i++)
    {


       if(A[j] == B[i])
        {
        j++;
        digCount++;
        if(digCount == wordCount)
            {

            totkeys=totkeys+1;
            digCount=0;
            j=0;
            }


        }
        else
            {
            j=j-digCount;

            digCount=0;

            }

   }
return totkeys;
    }

























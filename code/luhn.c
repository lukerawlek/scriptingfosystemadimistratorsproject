#include <string.h>
#include <stdio.h>
#include <math.h>
int luhn(int cc[])
{	
    int i, odd,even,computed, oddsum = 0,evensum=0, sum = 0;
    for (i = 0; i <16; i++) 
    {
        int digit = cc[15-i];
        odd=digit;
        even = 2*digit;
        computed=even%10+even/10;
        if ((i+1)%2)
            oddsum+=odd;
        else
        {
            evensum+=computed;
        }
     printf("\n\nDigit: %d\nOdd: %d\nEven: %d\nComputed: %d\nOddSum: %d\nEvenSum: %d\n\n" ,digit,odd,even,computed,oddsum,evensum);
     }
    sum = oddsum+evensum;
    printf("Sum: %d\n",sum);
    int answer =sum % 10 == 0;
    printf("Answer: %d\n",answer);
    return answer;
}

int main()
{
    int number[16];
    int * n;
    printf("Enter credit card number: ");
    scanf("%d",n);
    for(int i=0;i<16;i++)
    {
    	int mod=(int)(pow(10,i));
    	number[i]=(*n % mod );
    }
    printf("\n%s",  luhn(number) ? "ok" : "not ok");
    return 0;
 }

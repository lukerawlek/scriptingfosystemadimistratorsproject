#include <string.h>
#include <stdio.h>
#include <math.h>
int luhn(int cc[])
{	
    int i, odd,even,computed, oddsum = 0,evensum=0, sum = 0;
    for (i = 0; i <16; i++) 
    {
        int digit = cc[i];
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
   	int  n;
    int mod;
    printf("Enter credit card number 4 digits at a time: ");
    for(int i=0;i<4;i++)
    {
        scanf("%d",&n);
    	number[0+4*i]=(n/1000);
    	number[1+4*i]=(n/100)-number[0+4*i]*10;
    	number[2+4*i]=(n/10)-number[0+4*i]*100-number[1+4*i]*10;
    	number[3+4*i]=n-number[0+4*i]*1000-number[1+4*i]*100-number[2+4*i]*10;
    	
    }
    int swp;
   	for (int i=0;i<8;i++)
 		{
 		swp=number[i];
 		number[i]=number[15-i];
 		number[15-i]=swp;
 		}
   	printf("\n%s",  luhn(number) ? "ok" : "not ok");
    return 0;
 	
 }

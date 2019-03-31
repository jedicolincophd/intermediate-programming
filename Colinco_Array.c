/*
Name: Colinco, Jedidiah Jan L.
Date Started: July 3, 2015
Date Finished: July 4,2015

Write a program that accepts as input at most 10
integers. The program then determines and outputs 
the largest among the elements the user had inputted
as well as the average of those elements. If the 
user inputs more than 10 elements, your program should
warn the user that the array is already full.
*/

#include <stdio.h>
#include <conio.h>
#define MAX 10
 
int getNum(int,int a[]);
int calcLargest(int a[],int);
float calcAve(int a[],int,int);
void displayRes(int a[],int,int,float);

int main(void)
{
    int ar[MAX];
    int c=0,num,l=0,n=0;
    float average=0;
    char choice;
    
    do
    {
        printf("a)Input\nb)Largest\nc)Average\nd)Display\ne)Exit\n\nChoice: ");
        scanf(" %c",&choice);

        switch(choice)
        {
            case 'a':
                c++;
                if(c>10)
                {
                    printf("The array is already full.\n\n");
                }
                else
                {
                    getNum(n,ar);
                    n++;
                }
                break;
            case 'b':
                l=calcLargest(ar,n);
                break;
            case 'c':
                average=calcAve(ar,n,c);
                break;
            case 'd':
                displayRes(ar,l,n,average);
                break;
            case 'e':
                printf("Exiting. . .");
                break;
            default:
                printf("Invalid choice. . .\n");
                break;
        }
    }while(choice=='a'||choice=='b'||choice=='c');
    
    getch();
    return 0;
}//end of main

//Function definitions
int getNum(int n,int ar[])
{
    int num;
    printf("Input an integer: ");
    scanf("%d",&num);
    ar[n]=num;
    return;
}
int calcLargest(int ar[],int n)
{
    int j,k,temp,large=0;
    for(j=0;j<n;j++)
    {
        if(ar[j]>ar[j+1])
        {
            if(ar[j]>large)
                temp=j;
        }
        else
        {
            if(ar[j+1]>large)
                temp=j+1;
        }
        large=ar[temp];
        j++;
    }
    return large;
}
float calcAve(int ar[],int c,int n)
{
    int m,t,u,v=0,s=0;
    float ave;
    for(m=0;m<n;m++)
    {
        t=ar[m];
        u=ar[m+1];
        s=t+u;
        v=v+s;
        m++;
    }
    ave=v/c;
    return ave;
}
void displayRes(int ar[],int l,int n,float average)
{
    int i;
    printf("Elements of the array:");
    for(i=0;i<n;i++)
    {
        printf(" %d",ar[i]);
    }
    printf("\nLargest: %d\n",l);
    printf("Average: %.1f",average);
}

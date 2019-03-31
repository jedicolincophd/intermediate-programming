/* 
This program simulates a simple inventory system implemented using linked-list.

Name: Jedidiah Jan L. Colinco
Date Started: Sept. 11, 2015
Date Finished: Sept. 13, 2015
*/

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>

#define FLUSH while(getchar()!='\n')
#define MAX 20

typedef struct node *nd;
struct node
    {
        int itmnum;
        char itmname[30];
        short qnty;
        float pr;
        nd next;
    }NODE;

void getData(nd *);
void getItem(nd *);
void delItem(nd *);
void getSales(nd *);
void getGoods(nd *);
void dispItems(nd,int);

int main(void)
{
    int choice,count=0;
    nd head=NULL;
    
    do
    {
        system("cls");
        printf("Colinco Enterprise\n");
        printf("1]Add New Item\n");
        printf("2]Edit Item Information\n");
        printf("3]Delete Item\n");
        printf("4]Sales\n");
        printf("5]Goods Receipt\n");
        printf("6]Display All Items\n");
        printf("7]Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: count++;
                    getData(&head);
                    break;
            case 2: getItem(&head);
                    break;
            case 3: count--;
                    delItem(&head);
                    break;
            case 4: getSales(&head);
                    break;
            case 5: getGoods(&head);
                    break;
            case 6: dispItems(head,count);
                    break;
            case 7: printf("Exiting. . .");
                    getch();
                    break;
            default:printf("Invalid choice. . .please try again.");
                    getch();
                    break;
        }
    }while(choice!=7);
    return 0;
}//end of main 

/*Functions*/
void getData(nd *head)
{
    int inum;
    char iname[30];
    float sp;
    short qty;
    nd temp,tp,tpr=NULL;

    system("cls");
    printf("ADD NEW ITEM\n");
    printf("Input item number: ");
    scanf("%d",&inum);
    printf("Input item name: ");
    scanf("%s",&iname);
    FLUSH;
    printf("Input quantity: ");
    scanf("%hd",&qty);
    printf("Input selling price: ");
    scanf("%f",&sp);
    
    temp=malloc(sizeof(NODE));
    temp->itmnum=inum;
    strcpy(temp->itmname,iname);
    temp->qnty=qty;
    temp->pr=sp;
    temp->next=NULL;
    
    if(*head!=NULL)
    {
        tp=*head;
        while(tp!=NULL)
        {
            tpr=tp;
            tp=tp->next;
        }
        if (tpr==NULL)
        {
            temp->next=*head;
            *head=temp;
        }
        else if (tp==NULL)
            tpr->next=temp;
        else
        {
            tpr->next=temp;
            temp->next=tp;
        }
    }
    else
    {
        *head=temp;
    }
    temp=NULL;
    tp=NULL;
    tpr=NULL;
    return;
}

void getItem(nd *head)
{
    nd tp;
    int num1;
    char newitem[30];
    float newprice;
    bool found=false;
    
    do
    {
        tp=*head;
        system("cls");
        printf("EDIT ITEM INFORMATION\n");
        printf("Input the item number: ");
        scanf("%d",&num1);
        while(tp!=NULL)
        {    
            if(tp->itmnum==num1)
            {
                found=true;
                printf("Enter new item name: ");
                scanf("%s",&newitem);
                strcpy(tp->itmname,newitem);
                printf("Enter new selling price: ");
                scanf("%f",&newprice);
                tp->pr=newprice;
                break;     
            }
            tp=tp->next;
        }
        if(found==false)
        {
            printf("Error: the inputted item number does not exist.");
            getch();
        }
    }while(found==false);
    return;
}

void delItem(nd *head)
{
    nd tp,tpr;
    int num6;
    bool found4=false;
    
    do
    {
        tp=*head;
        tpr=NULL;
        system("cls");
        printf("DELETE ITEM\n");
        printf("Input the item number: ");
        scanf("%d",&num6);
        while(tp!=NULL)
        {
            if(tp->itmnum==num6)
            {
                found4=true;
                if(tpr==NULL)
                {
                    *head=tp->next;
                }
                else
                {
                    tpr->next=tp->next;
                }    
                free(tp);
                printf("Item successfully deleted!");
                getch();
                break;
            }
            else
            {    
                tpr=tp;
                tp=tp->next;
            }
        }
        if(found4==false)
        {
            printf("Error: The item number is not in the list.");
            getch();
        }
    }while(found4==false);
}

void getSales(nd *head)
{
    nd tp;
    int num2;
    short num3;
    bool found2=false;
    
    do
    {
        tp=*head;
        system("cls");
        printf("SALES\n");
        printf("Input the item number: ");
        scanf("%d",&num2);
        while(tp!=NULL)
        {
            if(tp->itmnum==num2)
            {
                found2=true;
                printf("Input the quantity bought: ");
                scanf("%hd",&num3);
                if(tp->qnty<=0)
                {
                    printf("Error: The quantity on hand is already zero or negative.");
                    getch();
                    break;
                }
                else
                {
                    tp->qnty=tp->qnty-num3;
                }
            }
            tp=tp->next;
        }
        if(found2==false)
        {
            printf("Error: The inputted item number does not exist.");
            getch();
        }
    }while(found2==false);
    return;
}

void getGoods(nd *head)
{
    nd tp;
    int num4;
    short num5;
    bool found3=false;
    
    while(found3==false)
    {
        tp=*head;
        system("cls");
        printf("GOODS RECEIPT");
        printf("\nInput the item number: ");
        scanf("%d",&num4);
        while(tp!=NULL)
        {
            if(tp->itmnum==num4)
            {
                found3=true;
                printf("Input the quantity received: ");
                scanf("%hd",&num5);
                if(num5<0)
                {
                    printf("Error: The quantity received is negative.");
                    getch();
                    break;
                }
                else
                {
                    tp->qnty=tp->qnty+num5;
                }
            }
            tp=tp->next;
        }
        if(found3==false)
        {
            printf("Error: The inputted item number does not exist.");
            getch();
        }
    }
    return;
}

void dispItems(nd head,int count)
{
    nd tp=head;
    
    if(count==0)
    {
        printf("Empty List: There are no items to display.");
        getch();
    }
    else
    { 
        system("cls");
        printf("DISPLAY ALL ITEMS\n\n");
        while(tp!=NULL)
        {
            printf("\nItem number: %d\n",tp->itmnum);
            printf("Item name: ");
            puts(tp->itmname);
            printf("Quantity: %hd\n",tp->qnty);
            printf("Selling price: $%0.2f\n",tp->pr);
            tp=tp->next;
        }
    }
    getch();
    return;
}

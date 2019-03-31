/*
This program simulates a simple student dormitory residence information system.

Name: Jedidiah Jan L. Colinco
Date Started: October 2, 2015
Date Finished: October 7, 2015
*/

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define FLUSH while(getchar()!='\n')

typedef struct
{
    char lname[20];
    char fname[30];
    char mi[2];
    char address[50];
    char course[12];
    char mother[40];
    char father[40];
    char inOut[4];
}RESIDENT;

void addDorm(FILE *,RESIDENT);
void inLog(FILE *,RESIDENT);
void outLog(FILE *,RESIDENT);
void trackDorm(FILE *,RESIDENT);
void searchDorm(FILE *,RESIDENT);
void delDorm(FILE *,RESIDENT);
void dispDorm(FILE *,RESIDENT);

int main()
{
    int choice,log;
    RESIDENT stud;
    FILE *fp;
    
    do
    {
        system("cls");
        printf("Student Information System\n\n");
        printf("1] Add New Dorm Resident\n");
        printf("2] Log Dorm Resident\n");
        printf("3] Track Dorm Resident\n");
        printf("4] Search Dorm Resident\n");
        printf("5] Delete Dorm Resident\n");
        printf("6] Display All Dorm Residents\n");
        printf("7] Exit\n\n");
        printf("Choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: system("cls");
                    addDorm(fp,stud);
                    break;
            case 2: system("cls");
                    printf("Do you want to: \n");
                    printf("1] Log-in a resident?\n");
                    printf("2] Log-out a resident?\n");
                    scanf("%d",&log);
                    if(log==1)
                        inLog(fp,stud);
                    else
                        outLog(fp,stud);
                    break;
            case 3: system("cls");
                    trackDorm(fp,stud);
                    break;
            case 4: system("cls");
                    searchDorm(fp,stud);
                    break;
            case 5: system("cls");
                    delDorm(fp,stud);
                    break;
            case 6: system("cls");
                    dispDorm(fp,stud);
                    break;
            case 7: system("cls");
                    printf("Exiting...");
                    getch();
                    break;
            default:printf("Invalid choice...");
                    getch();
                    break;
        }
    }while(choice!=7);
    
    return 0;
}

//Functions
void addDorm(FILE *fp,RESIDENT stud)
{  
    if((fp=fopen("d:/final project/Student.dat","ab"))==NULL)
    {
        printf("Error opening file...");
        getch();
        exit(1);
    }
    
    system("cls");
    printf("Add New Dorm Resident\n\n");
    printf("Input the following:");
    FLUSH;
    printf("\nLast Name: ");
    gets(stud.lname);
    printf("First Name: ");
    gets(stud.fname);
    printf("Middle Initial: ");
    gets(stud.mi);
    printf("Address: ");
    gets(stud.address);
    printf("Course: ");
    gets(stud.course);
    printf("Mother's name: ");
    gets(stud.mother);
    printf("Father's name: ");
    gets(stud.father);
    fwrite(&stud,sizeof(RESIDENT),1,fp);
    
    fclose(fp);
    return;
}
void inLog(FILE *fp,RESIDENT stud)
{
    char statIn[4]="In";
    char inLast[30];
    char inFirst[20];
    char inMid[2];
    bool searchIn=false;
    
    FLUSH;
    printf("Resident's last name: ");
    gets(inLast);
    printf("Resident's first name: ");
    gets(inFirst);
    printf("Resident's middle initial: ");
    gets(inMid);
    
    if((fp=fopen("d:/final project/Student.dat","rb+"))==NULL)
    {
        printf("Error opening file...");
        getch();
        exit(1);
    }
    
    while(fread(&stud,sizeof(RESIDENT),1,fp)!=0)
    {
        if(strcmpi(stud.lname,inLast)==0)
        {
            if(strcmpi(stud.fname,inFirst)==0)
            {
                if(strcmpi(stud.mi,inMid)==0)
                {        
                    searchIn=true;
                    fseek(fp,-(sizeof(RESIDENT)),SEEK_CUR);
                    fseek(fp,(sizeof(RESIDENT))-4,SEEK_CUR);
                    fwrite(&statIn,sizeof(statIn),1,fp);
                    break;
                }
            }
        }   
    }
    
    if(searchIn==true)
    {
        printf("Status change successful!");
        getch();
    }
    else
    {
        printf("Error: Name not found...");
        getch();
    }
    
    fclose(fp);
    return;
}
void outLog(FILE *fp,RESIDENT stud)
{
    char statOut[4]="Out";
    char outLast[30];
    char outFirst[20];
    char outMid[2];
    bool searchOut=false;
    
    FLUSH;
    printf("Resident's last name: ");
    gets(outLast);
    printf("Resident's first name: ");
    gets(outFirst);
    printf("Resident's middle initial: ");
    gets(outMid);
    
    if((fp=fopen("d:/final project/Student.dat","rb+"))==NULL)
    {
        printf("Error opening file...");
        getch();
        exit(1);
    }
    
    while(fread(&stud,sizeof(RESIDENT),1,fp)!=0)
    {
        if(strcmpi(stud.lname,outLast)==0)
        {
            if(strcmpi(stud.fname,outFirst)==0)
            {
                if(strcmpi(stud.mi,outMid)==0)
                {
                    searchOut=true;
                    fseek(fp,-(sizeof(RESIDENT)),SEEK_CUR);
                    fseek(fp,(sizeof(RESIDENT))-4,SEEK_CUR);
                    fwrite(&statOut,sizeof(statOut),1,fp);
                    break;
                }
            }
        }   
    }
    
    if(searchOut==true)
    {
        printf("Status change successful!");
        getch();
    }
    else
    {
        printf("Error: Name not found...");
        getch();
    }
    
    fclose(fp);
    return;
}
void trackDorm(FILE *fp,RESIDENT stud)
{
    char trackLast[30];
    char trackFirst[20];
    char trackMid[2];
    bool tSearch=false;
    
    FLUSH;
    printf("Track Dorm Resident\n\n");
    printf("Resident's last name: ");
    gets(trackLast);
    printf("Resident's first name: ");
    gets(trackFirst);
    printf("Resident's middle initial: ");
    gets(trackMid);
    
    if((fp=fopen("d:/final project/Student.dat","rb"))==NULL)
    {
        printf("Error opening file...");
        getch();
        exit(1);
    }
    
    while(fread(&stud,sizeof(RESIDENT),1,fp)!=0)
    {
        if(strcmpi(stud.lname,trackLast)==0)
        {
            if(strcmpi(stud.fname,trackFirst)==0)
            {
                if(strcmpi(stud.mi,trackMid)==0)
                {
                    tSearch=true;
                    fseek(fp,-(sizeof(RESIDENT)),SEEK_CUR);
                    fseek(fp,(sizeof(RESIDENT))-4,SEEK_CUR);
                    printf("Resident's status: ");
                    puts(stud.inOut);
                    break;
                }
            }
        }   
    }
    
    if(tSearch==true)
    {
        getch();
    }
    else
    {
        printf("Error: Name not found...");
        getch();
    }
    
    fclose(fp);
    return;
}
void searchDorm(FILE *fp,RESIDENT stud)
{
    char searchLast[30];
    char searchFirst[20];
    char searchMid[2];
    bool sSearch=false;
    
    FLUSH;
    printf("Search Dorm Resident\n\n");
    printf("Resident's last name: ");
    gets(searchLast);
    printf("Resident's first name: ");
    gets(searchFirst);
    printf("Resident's middle initial: ");
    gets(searchMid);
    
    if((fp=fopen("d:/final project/Student.dat","rb"))==NULL)
    {
        printf("Error opening file...");
        getch();
        exit(1);
    }
    
    while(fread(&stud,sizeof(RESIDENT),1,fp)!=0)
    {
        if(strcmpi(stud.lname,searchLast)==0)
        {
            if(strcmpi(stud.fname,searchFirst)==0)
            {
                if(strcmpi(stud.mi,searchMid)==0)
                {
                    sSearch=true;
                    fseek(fp,-(sizeof(RESIDENT)),SEEK_CUR);
                    printf("\n\nResident's information:\n");
                    printf("Last Name: %s\n",stud.lname);
                    printf("First Name: %s\n",stud.fname);
                    printf("Middle Initial: %s\n",stud.mi);
                    printf("Address: %s\n",stud.address);
                    printf("Course: %s\n",stud.course);
                    printf("Mother's name: %s\n",stud.mother);
                    printf("Father's name: %s\n",stud.father);
                    printf("Status: %s",stud.inOut);
                    break;
                }
            }
        }   
    }
    
    if(sSearch==true)
    {
        getch();
    }
    else
    {
        printf("Error: Name not found...");
        getch();
    }
    
    fclose(fp);
    return;
}
void delDorm(FILE *fp,RESIDENT stud)
{
    char delLast[30];
    char delFirst[20];
    char delMid[2];
    char ans;
    bool delSucceed;
    bool sDel=false;
    long int pos1,pos2;
    FILE *fp1;
    
    FLUSH;
    printf("Search Dorm Resident\n\n");
    printf("Resident's last name: ");
    gets(delLast);
    printf("Resident's first name: ");
    gets(delFirst);
    printf("Resident's middle initial: ");
    gets(delMid);
    
    if((fp=fopen("d:/final project/Student.dat","rb"))==NULL)
    {
        printf("Error opening file...");
        getch();
        exit(1);
    }
    
    while(fread(&stud,sizeof(RESIDENT),1,fp)!=0)
    {
        if(strcmpi(stud.lname,delLast)==0)
        {
            if(strcmpi(stud.fname,delFirst)==0)
            {
                if(strcmpi(stud.mi,delMid)==0)
                {
                    sDel=true;
                    fseek(fp,-(sizeof(RESIDENT)),SEEK_CUR);
                    pos1=ftell(fp);
                    printf("\n\nResident's information:\n");
                    printf("Last Name: %s\n",stud.lname);
                    printf("First Name: %s\n",stud.fname);
                    printf("Middle Initial: %s\n",stud.mi);
                    printf("Address: %s\n",stud.address);
                    printf("Course: %s\n",stud.course);
                    printf("Mother's name: %s\n",stud.mother);
                    printf("Father's name: %s\n",stud.father);
                    printf("Status: %s\n",stud.inOut);
                    break;
                }
            }
        }   
    }
    fclose(fp);
    
    if(sDel==true)
    {
        printf("\nAre you sure you want to delete (Y/N)?");
        scanf(" %c",&ans);
        ans=toupper(ans);
        if(ans=='Y')
        {
            if((fp=fopen("d:/final project/Student.dat","rb"))==NULL)
            {
                printf("Error opening file...");
                getch();
                exit(1);
            }
            if((fp1=fopen("d:/final project/Student1.dat","wb"))==NULL)
            {
                printf("Error opening file...");
                getch();
                exit(1);
            }
            
            while(fread(&stud,sizeof(RESIDENT),1,fp)!=0)
            {
                pos2=ftell(fp);
                if(pos2!=(pos1+sizeof(RESIDENT)))
                {
                    fwrite(&stud,sizeof(RESIDENT),1,fp1);
                }
            }
            fclose(fp);
            fclose(fp1);
            
            if((fp=fopen("d:/final project/Student.dat","wb"))==NULL)
            {
                printf("Error opening file...");
                getch();
                exit(1);
            }
            if((fp1=fopen("d:/final project/Student1.dat","rb"))==NULL)
            {
                printf("Error opening file...");
                getch();
                exit(1);
            }
            
            while(fread(&stud,sizeof(RESIDENT),1,fp1)!=0)
            {
                fwrite(&stud,sizeof(RESIDENT),1,fp);
            }
            fclose(fp);
            fclose(fp1);
            delSucceed=true;
            if(delSucceed=true)
            {
                printf("\n\nResident successfully deleted!");
                getch();
            }
            else
            {   
                printf("\n\nError while deleting...");
                getch();
            }
        }
        else
        {
            delSucceed=false;
            printf("Resident not deleted...");
            getch();
        } 
    }
    else
    {
        printf("Error: Name not found...");
        getch();
    }
    
    return;
}
void dispDorm(FILE *fp,RESIDENT stud)
{
    if((fp=fopen("d:/final project/Student.dat","rb"))==NULL)
    {
        printf("Error opening file...");
        getch();
        exit(1);
    }
    
    printf("Displaying All Dorm Residents\n\n");
    while(fread(&stud,sizeof(RESIDENT),1,fp)!=0)
    {
        printf("\nFull Name: %s %s %s \n",stud.lname,stud.fname,stud.mi);
        printf("Address: %s\n",stud.address);
    }
    
    getch();
    fclose(fp);
    return;
}

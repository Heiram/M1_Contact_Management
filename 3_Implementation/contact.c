/**
 * @file contact.c
 * @author Heiram N (heiram.18eee@sonatech.ac.in)
 * @brief This is the main program where the projet is run
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void test_contact();
struct contact
{
    long ph;
    char name[20],address[20],email[30];
} list;
char query[20],name[20],c;
FILE *fp, *ft;
int i,n,ch,l,found;
/* Start of the application */
/**
 * @brief main program
 * 
 * @return int 
 */
int main()
{
    main:
    printf("\n\t\t\t\t\t******************************************");
    printf("\n\t\t\t\t\t*!                                      !*");
    printf("\n\t\t\t\t\t*!     ==>  WELCOME TO CONTACTS  <==    !*");
    printf("\n\t\t\t\t\t*!                                      !*");
    printf("\n\t\t\t\t\t****************************************** \n\n");
    printf("\n\t\t\t### MAIN MENU ###\n\n\t\t------------------------------------------------");
    printf("\n\t\t| Add a new Contact    [Enter --> 1]           |");
    printf("\n\t\t|______________________________________________|");
    printf("\n\t\t| Edit a Contact       [Enter --> 2]           |");
    printf("\n\t\t|______________________________________________|");
    printf("\n\t\t| Search for Contacts  [Enter --> 3]           |");
    printf("\n\t\t|______________________________________________|");
    printf("\n\t\t| List of all Contacts [Enter --> 4]           |");
    printf("\n\t\t|______________________________________________|");
    printf("\n\t\t| Delete a Contact     [Enter --> 5]           |");
    printf("\n\t\t|______________________________________________|");
    printf("\n\t\t| Exit                 [Enter --> 0]           |\n\t\t------------------------------------------------\n\t\t\t\t\t\t\t\t");
    printf("\n\n\t\tENTER A VALID NUMBER :");
    scanf("%d",&ch);
    switch(ch)
 {
    case 0:
        printf("\n\n\t\tAre you sure you want to exit?");
        break;
    case 1:
        system("cls");
        fp=fopen("contact.dll","a");
        for (;;)
        {
            fflush(stdin);
            printf("//To exit enter BLANK SPACE in the name input\nName (Identical):");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
            break;
            fflush(stdin);
            printf("Phone:");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("address:");
            scanf("%[^\n]",&list.address);
            fflush(stdin);
            printf("email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }        break;
     case 2:
         system("cls");
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("\n\t\t\t\t\t=======================");
        printf("\n\t\t\t\t\t!     EDIT CONTACT    !");
        printf("\n\t\t\t\t\t======================= \n\nEnter the name of contact to edit:");
        scanf("%[^\n]",name);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::Name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::Phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("..::address:");
        scanf("%[^\n]",&list.address);
        fflush(stdin);
        printf("..::email address:");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
    case 3:
        system("cls");
        do
        {
            found=0;
            printf("\n\t\t\t\t\t==========================");
            printf("\n\t\t\t\t\t!   SEARCH FOR CONTACTS  !");
            printf("\n\t\t\t\t\t========================== \n\n\nName of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l=strlen(query);
            fp=fopen("contact.dll","r");
            system("cls");
            printf("\n\nSEARCH RESULT FOR '%s' \n<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n",query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0)
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.address,list.email);
                    found++;
                    if (found%4==0)
                    {
                        printf("Press any key to continue...");
                        getch();
                    }
                }
            }
            if(found==0)
                printf("\n Oops match not found!");
            else
                printf("\n %d match(s) found!",found);
            fclose(fp);
            printf("\n  Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
  while(ch==1);
        break;
    case 4:
        system("cls");
        printf("\n\t\t\t\t\t=======================");
        printf("\n\t\t\t\t\t!   LIST OF CONTACTS  !");
        printf("\n\t\t\t\t\t======================= \n");
        printf("\n________________________________________________\n\n");
        for(i=97; i<=122; i=i+1)
        {
            fp=fopen("contact.dll","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==i || list.name[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,
                           list.ph,list.address,list.email);
                    printf("\n");
                    found++;
                }
            }
            if(found!=0)
            {
                printf("________________________________________________[%c]-(%d)\n\n",i-32,found);
                getch();
            }
            fclose(fp);
        }
    case 5:
        system("cls");
        fflush(stdin);
        printf("\n\t\t\t\t\t=======================");
        printf("\n\t\t\t\t\t!   DELETE A CONTACT  !");
        printf("\n\t\t\t\t\t======================= \n\n\nEnter the name of contact to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
    default:
        printf("Invalid choice");
        break;
    }
    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
    return 0;
}


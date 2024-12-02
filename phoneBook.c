#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct contact
{
    char name[30];
    char phone[50];
    char gmail[50];
    char address[50];
    char dob[50];
    char bg[50];

} info;
FILE *cfile;
long size =sizeof(info);
void main()
{
    int c1;
    printf("\n\t\t\t\t____________________\n");
    printf("\n\t\t\t\tWelcome To Phonebook\n");
    printf("\n\t\t\t\t_____________________\n\n\n");
    printf("\n\t\t\t\tpress any key to continue...");
    getch();
    display();
}
display()
{
    int c1;
    while(c1!=7)
    {
        system("cls");
        printf("\n\n\t\t\t\t__________________________________\n");
        printf("\n\t\t\t\t\t** Main Menu **\n");
        printf("\n\n\t\t\t\t__________________________________\n");
        printf("\nChose An Option\n");
        printf("1 : Add Contact 2 : Show Contact list 3 : Search Contact 4: Delete Contact 5:Modify Contact 6:Exit\n");
        scanf("%d",&c1);
        switch(c1)
        {
        case 1:
            system("cls");

            addcontact();
            break;
        case 2:
            system("cls");

            showContactlist();
            break;
        case 3:
            system("cls");

            searchContact();
            break;
        case 4:
            system("cls");

            delete_contact_info();
            break;
        case 5:
            system("cls");

            modify_contact_info();
            break;
        case 6:
            exit(1);
        default:
            printf("wrong choice");
        }
    }
    printf("\n\nEnter any key to continue...");
    getch();
}
void addcontact()
{


    cfile = fopen("addcontact.txt","ab");
    if(cfile==NULL)
    {
        printf("\nFile is empty");
        printf("\n\nPress any key to continue");
        getch();
    }
    printf("\t*Enter Contact information*\n\n");
    fflush(stdin);
    printf("Enter contact name: ");
    gets(info.name);
    printf("Enter contact phonenumber: ");
    gets(info.phone);
    printf("Enter contact address: ");
    gets(info.address);
    printf("Enter contact Gmail: ");
    gets(info.gmail);
    printf("Enter contact Blood group: ");
    gets(info.bg);
    printf("Enter contact date of birth: ");
    gets(info.dob);
    fwrite(&info,size,1,cfile);

    printf("Contact Information Saved Successfully...");
    fclose(cfile);
    printf("\n\nEnter Any Key To Continue...");
    getch();
}
void showContactlist()
{

    cfile = fopen("addcontact.txt","rb");
    if(cfile==NULL)
    {
        printf("\nFile is empty");
        printf("\n\nPress any key to continue");
        getch();
    }
    printf("%-30s %-15s %-20s %-20s %-15s\n","Name","Phone","Address","Blood group","Date of Brith");
    while(fread(&info,size,1,cfile)==1)
    {
        printf("%-30s %-15s %-20s %-20s %-15s\n",info.name,info.phone,info.address,info.bg,info.dob);
    }
    fclose(cfile);
    printf("\n\nEnter Any Key To Continue...");
    getch();
}
void searchContact()
{
    int choice;

    while(1)
    {
        system("cls");
        printf("\t\t\t<<--SEARCH-->>\t\t\t\n");
        printf("1 : Search By Name \n2 : Search By Phonenumber \n3 : Back TO Main Menu\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            search_by_name();
            break;
        case 2:
            search_by_phonenumber();
            break;
        case 3:
            display();
        default:
            printf("Invalid Choice");
            break;
        }

    }
    printf("\n\nEnter Any Key To Continue...");
    getch();
}
void search_by_name()
{
    int flag=0;
    char name[50];
    printf("Enter Contact name For Search : ");
    fflush(stdin);
    gets(name);
    cfile = fopen("addcontact.txt","rb");
    printf("%-30s %-15s %-20s %-20s %-15s\n","Name","Phone","Address","Blood group","Date of Brith");
    if(cfile==NULL)
    {
        printf("\nFile is empty");
        printf("\n\nPress any key to continue");
        getch();
    }
    while(fread(&info,size,1,cfile)==1)
    {
        if(strcmpi(name,info.name)==0)
        {
            flag =1;
            printf("%-30s %-15s %-20s %-20s %-15s\n",info.name,info.phone,info.address,info.bg,info.dob);
            break;
        }
    }
    fclose(cfile);
    if(flag==0)
    {
        printf("Name not found");
    }
    else
    {
        printf("\n\nContact found\n");
    }

    printf("\n\nEnter Any Key To Continue...");
    getch();
}
void search_by_phonenumber()
{
    int flag;
    char number[50];

    printf("Enter Contact Phonenumber For Search : ");
    fflush(stdin);
    gets(number);

    cfile = fopen("addcontact.txt","rb");
    printf("%-30s %-15s %-20s %-20s %-15s\n","Name","Phone","Address","Blood group","Date of Brith");
    if(cfile==NULL)
    {
        printf("\nFile is empty");
        printf("\n\nPress any key to continue");
        getch();

    }
    while(fread(&info,size,1,cfile)==1)
    {
        if(strcmpi(number,info.phone)==0)
        {
            flag=1;
            printf("%-30s %-15s %-20s %-20s %-15s",info.name,info.phone,info.address,info.bg,info.dob);
            break;

        }

    }
    fclose(cfile);

    if(flag==0)
        {
            printf("\nPhonenumber not found");
        }

    printf("\n\nEnter Any Key To Continue...");
    getch();
}
void delete_contact_info()
{
    int flag=0;
    char number[50];

    printf("Enter Contact Phonenumber For Search : ");
    fflush(stdin);
    gets(number);
    FILE *tfile;
    cfile = fopen("addcontact.txt","rb");

    if(cfile==NULL)
    {
        printf("\nFile is empty");
        printf("\n\nPress any key to continue");
        getch();
    }
    tfile = fopen("temp.txt","ab+");

    while(fread(&info,size,1,cfile)==1)
    {
        if(strcmp(number,info.phone)==0)
        {
            flag=1;
            printf("Contact deleted successfully\n");
            fwrite(&info,size,1,tfile);
            remove("addcontact.txt");
            rename("temp.txt","addcontact.txt");
            fclose(cfile);
            fclose(tfile);
            break;
        }

    }
    if(flag==0)
    {
        printf("Name not found");
    }
    printf("\n\npress any key to continue...");
    getch();
}
void modify_contact_info()
{
    int flag=0;
    char number[50];

    printf("Enter Contact Phonenumber For Modify : ");
    fflush(stdin);
    gets(number);
    cfile = fopen("addcontact.txt","rb+");

    if(cfile==NULL)
    {
        printf("\nFile is empty");
        printf("\n\nPress any key to continue");
        getch();
    }
    while(fread(&info,size,1,cfile)==1)
    {
        if(strcmpi(number,info.phone)==0)
        {
            int choice;
            flag=1;
            printf("\n\nPrevious Info : \n");
            printf("%-30s %-15s %-20s %-20s %-15s\n","Name","Phone","Address","Blood group","Date of Brith");
            printf("%-30s %-15s %-20s %-20s %-15s",info.name,info.phone,info.address,info.bg,info.dob);
            printf("\n\n0 : To Edit All Info\n");
            printf("1 : To Edit Name\n");
            printf("2 : To Edit Phonenumber\n");
            printf("3 : To Edit Address\n");
            printf("4 : To Edit Gmail\n");
            printf("5 : To Edit Date of Birth\n");
            printf("6 : To Edit Blood Group\n");
            printf("\n\n");
            printf("Chose An Option : \n");
            scanf("%d",&choice);
            if(choice==0)
            {
                printf("Enter Contact New Name : ");
                fflush(stdin);
                gets(info.name);
                printf("Enter new Phonenumber : ");
                fflush(stdin);
                gets(info.phone);
                printf("Enter new Gmail : ");
                fflush(stdin);
                gets(info.gmail);
                printf("Enter new Address : ");
                fflush(stdin);
                gets(info.address);
                printf("Enter new Date of Birth : ");
                fflush(stdin);
                gets(info.dob);
                printf("Enter new Blodd group : ");
                fflush(stdin);
                gets(info.bg);
            }
            if(choice==1)
            {
                printf("Enter Contact new Name : ");
                fflush(stdin);
                gets(info.name);
            }
            if(choice==2)
            {
                printf("Enter new Phonenumber : ");
                fflush(stdin);
                gets(info.phone);
            }
            if(choice==3)
            {
                printf("Enter new Address : ");
                fflush(stdin);
                gets(info.address);
            }
            if(choice==4)
            {
                printf("Enter new Gmail : ");
                fflush(stdin);
                gets(info.gmail);
            }
            if(choice==5)
            {
                printf("Enter new Date of birth : ");
                fflush(stdin);
                gets(info.dob);
            }
            if(choice==6)
            {
                printf("Enter new Blood group : ");
                fflush(stdin);
                gets(info.bg);
            }
            fseek(cfile,-size,1);
            fwrite(&info,size,1,cfile);
            printf("Contact modified successfully");
        }
    }
    if(flag==0)
    {
        printf("Something went wrong");
    }
    fclose(cfile);

    printf("\n\nEnter Any Key To Continue...");
    getch();
}
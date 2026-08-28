#include<stdio.h>
#include<string.h>
#include "contact.h"

void sort_name(AddressBook *address)
{
    void convert(char *);
    Contact temp;
    char name1[50],name2[50];
    for(int i=0;i<address->contactCount-1;i++)
    {
        for(int j=0;j<address->contactCount-i-1;j++)
        {
            strcpy(name1,address->contacts[j].name);
            strcpy(name2,address->contacts[j+1].name);
            convert(name1);
            convert(name2);
            if(strcmp(name1,name2)>0)
            {
                temp=address->contacts[j];
                address->contacts[j]=address->contacts[j+1];
                address->contacts[j+1]=temp;
            }
        }
    }
}
void sort_phone(AddressBook *address)
{
    Contact temp;
    for(int i=0;i<address->contactCount-1;i++)
    {
        for(int j=0;j<address->contactCount-i-1;j++)
        {
            if(strcmp(address->contacts[j].phone,address->contacts[j+1].phone)>0)
            {
                temp=address->contacts[j];
                address->contacts[j]=address->contacts[j+1];
                address->contacts[j+1]=temp;
            }
        }
    }
}
void sort_email(AddressBook *address)
{
    Contact temp;
    for(int i=0;i<address->contactCount-1;i++)
    {
        for(int j=0;j<address->contactCount-i-1;j++)
        {
            if(strcmp(address->contacts[j].email,address->contacts[j+1].email)>0)
            {
                temp=address->contacts[j];
                address->contacts[j]=address->contacts[j+1];
                address->contacts[j+1]=temp;
            }
        }
    }
}
void editfield(AddressBook *addressBook,int choice2,int *match,int choice1)
{
        switch(choice2)
        {
            case 1: printf("Enter your new name: ");
        scanf(" %[^\n]",addressBook->contacts[match[choice1-1]].name);
        while(validate_name(addressBook->contacts[match[choice1-1]].name)==0)
    {
        printf("Enter a valid name with only alphanumeric characters and space: ");
        scanf(" %[^\n]",addressBook->contacts[match[choice1-1]].name);
    }
    break;
    case 2: 
    char temp1[50];
        printf("Enter your new number: ");
        scanf(" %[^\n]",temp1);
        int err;
    while((err=validate_phone(temp1,addressBook))!=0)
    {
        if(err==4 && strcmp(addressBook->contacts[match[choice1-1]].phone,temp1)==0)
        break;
        switch(err)
        {
        case 1: printf("Enter only 10 digits: ");
        break;
        case 2: printf("First digit should be greater than 5 Re-enter valid phone number: ");
        break;
        case 3: printf("Enter only digits: "); 
        break;
        case 4:  printf("phone no should be unique: ");
        break;
        }
        scanf(" %s",temp1);
    }
    strcpy(addressBook->contacts[match[choice1-1]].phone,temp1);
        break;
        case 3:  char temp[50];
        printf("Enter your new email: ");
        scanf(" %[^\n]",temp);
       while((err=validate_email(temp,addressBook))!=0)
    {
        if(err==7 && strcmp(addressBook->contacts[match[choice1-1]].email,temp)==0)
        break;
        switch(err)
        {
            case 1: printf("email should not contain uppercase characters re enter valid email: ");
            break;
            case 2: printf("email should not contain any space re enter valid email: ");
            break;
            case 3: printf("First character should be alnum re enter valid email: ");
            break;
            case 4: printf("Enter atleast one character between @ and .com: ");
            break;
            case 5: printf("There should be one @ character in email: ");
            break;
            case 6: printf("Last four characters must be .com: ");
            break;
            case 7: printf("email should be unique: ");
            break;
        }
        scanf(" %[^\n]",temp);
    }
    strcpy(addressBook->contacts[match[choice1-1]].email,temp);
        break;
        default: printf("Please re enter valid choice only in the above range: ");
        scanf("%d",&choice2);
        editfield(addressBook,choice2,match,choice1);
}
}
/*int search_name(const char *sub,const AddressBook *main,int i)
{
        for(int j=0;main->contacts[i].name[j]!=0;j++)
        {
            int flag=0;
            if((main->contacts[i].name[j]==sub[0])||(main->contacts[i].name[j]+32==sub[0])||(main->contacts[i].name[j]-32==sub[0]))
            {
                for(int k=j+1,p=1;sub[p]!=0;k++,p++)
                {
                    if((main->contacts[i].name[k]==sub[p])||(main->contacts[i].name[k]+32==sub[p])||(main->contacts[i].name[k]-32==sub[p]))
                    continue;
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    return 1;
                }
            }
        }
        return 0;
    
}
int search_phone(const char *sub,const AddressBook *main,int i)
{
        for(int j=0;main->contacts[i].phone[j]!=0;j++)
        {
            int flag=0;
            if(main->contacts[i].phone[j]==sub[0])
            {
                for(int k=j+1,p=1;sub[p]!=0;k++,p++)
                {
                    if(main->contacts[i].phone[k]==sub[p])
                    continue;
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                   return 1;
                }
            }
        }
        return 0;
}
int search_email(const char *sub,const AddressBook *main,int i)
{
    
        for(int j=0;main->contacts[i].email[j]!=0;j++)
        {
            int flag=0;
            if((main->contacts[i].email[j]==sub[0])||(main->contacts[i].email[j]+32==sub[0])||(main->contacts[i].email[j]-32==sub[0]))
            {
                for(int k=j+1,p=1;sub[p]!=0;k++,p++)
                {
                    if((main->contacts[i].email[k]==sub[p])||(main->contacts[i].email[k]+32==sub[p])||(main->contacts[i].email[k]-32==sub[p]))
                    continue;
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    return 1;
                }
            }
        }
        return 0;
}*/
#include<stdio.h>
#include<string.h>
#include "contact.h"

void sort_name(AddressBook *address)
{
    Contact temp;
    for(int i=0;i<address->contactCount-1;i++)
    {
        for(int j=0;j<address->contactCount-i-1;j++)
        {
            if(strcmp(address->contacts[j].name,address->contacts[j+1].name)>0)
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
int search_name(const char *sub,const AddressBook *main,int i)
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
}
#include<stdio.h>
#include<string.h>
#include "contact.h"

void delete(AddressBook *main,int i)
{
    for(int j=i;j<main->contactCount-1;j++)
    {
        main->contacts[j]=main->contacts[j+1];
    }
    main->contactCount--;
}
void convert(char *str)
{
    for(int i=0;str[i]!=0;i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        str[i]+=32;
    }
}
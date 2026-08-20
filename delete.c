#include<stdio.h>
#include<string.h>
#include "contact.h"

void delete(char *str,AddressBook *main,int i)
{
    for(int j=i;j<main->contactCount-1;j++)
    {
        main->contacts[j]=main->contacts[j+1];
    }
    main->contactCount--;
}
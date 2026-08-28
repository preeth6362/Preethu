#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    int choice;
    printf("How do you want to sort the contacts: \n");
    printf("1.By name\n2.By phone number\n3.By email id\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: sort_name(addressBook);
        break;
        case 2: sort_phone(addressBook);
        break;
        case 3:sort_email(addressBook);
        break;
        default: printf("Displaying as it is:\n");

    }
    printf("List of contacts:  \n");
    printf("Name\t\tphone\t\temail\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%s\t\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	printf("1. Enter name: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    while(validate_name(addressBook->contacts[addressBook->contactCount].name)==0)
    {
        printf("Enter a valid name with only alphanumeric characters and space: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    }

    printf("2. Enter phone number: ");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    int err;
    while((err=validate_phone(addressBook->contacts[addressBook->contactCount].phone,addressBook))!=0)
    {
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
        scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    }
    
    printf("3. Enter emailid: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
    while((err=validate_email(addressBook->contacts[addressBook->contactCount].email,addressBook))!=0)
    {
        switch(err)
        {
            case 1: printf("email should not contain uppercase characters re enter valid email: ");
            break;
            case 2: printf("email should not contain any space re enter valid email: ");
            break;
            case 3: printf("First character should not be @ re enter valid email: ");
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
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
    }
    printf("Contact created successfully.\n");
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    char sub[50];int choice;
    printf("Enter how you want to search: \n");
    printf("1.By name\n2.By phone number\n3.By email\n");
    scanf("%d",&choice);
    printf("Enter what you want to search: ");
    scanf(" %[^\n]",sub);
    switch(choice)
    {
        case 1: 
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcasestr(addressBook->contacts[i].name,sub)!=NULL)
            printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        break;
        case 2:
         for(int i=0;i<addressBook->contactCount;i++)
        { 
         if(strcasestr(addressBook->contacts[i].phone,sub)!=NULL)
          printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        break;
        case 3: 
        for(int i=0;i<addressBook->contactCount;i++)
        {
          if(strcasestr(addressBook->contacts[i].email,sub)!=NULL)
          printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        break;
        default: printf("Enter valid option\n");
    } 
}

void editContact(AddressBook *addressBook)
{
    int choice,choice1,choice2;
    char str[50];int match[100];
	printf("Enter how you want to search : \n");
    printf("1.By name\n2.By number\n3.By email\n");
    scanf("%d",&choice);
	printf("what you want to edit: ");
    scanf(" %[^\n]",str);
    switch(choice)
    {
        case 1: int n=0;
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcasestr(addressBook->contacts[i].name,str)!=NULL)
            {
            printf("%d] %s\t\t%s\t\t%s\n",n+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            match[n++]=i;
            }
        }
        printf("Which contact do you want to edit? ");
        scanf("%d",&choice1);
        printf("Which field do you want to edit: \n1] name\n2]phone\n3]email\n");
        scanf("%d",&choice2);
        editfield(addressBook,choice2,match,choice1);
        break;
        case 2: int p=0;
        for(int i=0;i<addressBook->contactCount;i++)
        { 
         if(strcasestr(addressBook->contacts[i].phone,str)!=NULL)
         {
          printf("%d] %s\t\t%s\t\t%s\n",p+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
          match[p++]=i;
         }
        }
        printf("Which contact do you want to edit? ");
        scanf("%d",&choice1);
         printf("Which field do you want to edit: \n1] name\n2]phone\n3]email\n");
        scanf("%d",&choice2);
        editfield(addressBook,choice2,match,choice1);
        break;
        case 3: int e=0;
        for(int i=0;i<addressBook->contactCount;i++)
        {
          if(strcasestr(addressBook->contacts[i].email,str)!=NULL)
          {
          printf("%d] %s\t\t%s\t\t%s\n",e+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
          match[e++]=i;
          }
        }
        printf("Which contact do you want to edit? ");
        scanf("%d",&choice1);
         printf("Which field do you want to edit: \n1] name\n2]phone\n3]email\n");
        scanf("%d",&choice2);
        editfield(addressBook,choice2,match,choice1);
        break;
        default: printf("Enter valid option\n");
    }
    printf("Contact updated successfully.\n");
}

void deleteContact(AddressBook *addressBook)
{
    int choice,choice1;
    char str[50];int match[100];
	printf("Enter how you want to search : \n");
    printf("1.By name\n2.By number\n3.By email\n");
    scanf("%d",&choice);
    printf("what you want to delete: ");
    scanf(" %[^\n]",str);
    switch(choice)
    {
        case 1: int n=0;
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcasestr(addressBook->contacts[i].name,str)!=NULL)
            {
            printf("%d] %s\t\t%s\t\t%s\n",n+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            match[n++]=i;
            }
        }
        printf("Which contact do you want to delete? ");
        scanf("%d",&choice1);
        delete(addressBook,match[choice1-1]);
        break;
        case 2: int p=0;
        for(int i=0;i<addressBook->contactCount;i++)
        { 
         if(strcasestr(addressBook->contacts[i].phone,str)!=NULL)
         {
          printf("%d] %s\t\t%s\t\t%s\n",p+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
          match[p++]=i;
         }
        }
        printf("Which contact do you want to delete? ");
        scanf("%d",&choice1);
        delete(addressBook,match[choice1-1]);
        break;
        case 3: int e=0;
        for(int i=0;i<addressBook->contactCount;i++)
        {
          if(strcasestr(addressBook->contacts[i].email,str)!=NULL)
          {
          printf("%d] %s\t\t%s\t\t%s\n",e+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
          match[e++]=i;
          }
        }
        printf("Which contact do you want to delete? ");
        scanf("%d",&choice1);
        delete(addressBook,match[choice1-1]);
        break;
        default: printf("Enter valid option\n");
    }
    printf("Contact deleted successfullyy\n");
}

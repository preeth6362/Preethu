#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    int choice;
    void sort_name(AddressBook *);
    void sort_phone(AddressBook *);
    void sort_email(AddressBook *);
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
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    int validate_name(char *);
	printf("1. Enter name: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    while(validate_name(addressBook->contacts[addressBook->contactCount].name)==0)
    {
        printf("Enter a valid name with only alphanumeric characters and space: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    }
    int validate_phone(char *);
    printf("2. Enter phone number: ");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    while(validate_phone(addressBook->contacts[addressBook->contactCount].phone)!=0)
    {
        if(validate_phone(addressBook->contacts[addressBook->contactCount].phone)==1)
        {
        printf("Enter only 10 digits: ");
        scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
        }
        else if(validate_phone(addressBook->contacts[addressBook->contactCount].phone)==2)
        {
            printf("First digit should be greater than 5 Re-enter valid phone number: ");
            scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
        }
        else if(validate_phone(addressBook->contacts[addressBook->contactCount].phone)==3)
        {
            printf("Enter only digits: "); 
            scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
        }
    }
    int validate_email(char *);
    printf("3. Enter emailid: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
    while(validate_email(addressBook->contacts[addressBook->contactCount].email)!=0)
    {
       if(validate_email(addressBook->contacts[addressBook->contactCount].email)==1)
       {
       printf("email should not contain uppercase characters re enter valid email: ");
       scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
       }
       else if(validate_email(addressBook->contacts[addressBook->contactCount].email)==2)
       {
        printf("email should not contain any space re enter valid email: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
       }
       else if(validate_email(addressBook->contacts[addressBook->contactCount].email)==3)
       {
        printf("First character should not be @ re enter valid email: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
       }
       else if(validate_email(addressBook->contacts[addressBook->contactCount].email)==4)
       {
        printf("Enter atleast one character between @ and .com: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
       }
       else if(validate_email(addressBook->contacts[addressBook->contactCount].email)==5)
       {
        printf("There should be one @ character in email: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
       }
       else if(validate_email(addressBook->contacts[addressBook->contactCount].email)==6)
       {
        printf("Last four characters must be .com: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
       }
    }
    printf("Contact created successfully.\n");
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    int search_name(const char *,const AddressBook *,int);
    int search_phone(const char *,const AddressBook *,int);
    int search_email(const char *,const AddressBook *,int);
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
            if(search_name(sub,addressBook,i)==1)
            printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        break;
        case 2:
         for(int i=0;i<addressBook->contactCount;i++)
        { 
         if(search_phone(sub,addressBook,i)==1)
          printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        break;
        case 3: 
        for(int i=0;i<addressBook->contactCount;i++)
        {
          if(search_email(sub,addressBook,i)==1)
          printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        break;
        default: printf("Enter valid option\n");
    } 
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
    int search_name(const char *,const AddressBook *,int);
    int search_phone(const char *,const AddressBook *,int);
    int search_email(const char *,const AddressBook *,int);
    void delete(char *,AddressBook *,int);
    int choice;
    char str[50];
	printf("Enter how you want delete: \n");
    printf("1.By name\n2.By number\n3.By email\n");
    scanf("%d",&choice);
    printf("what you want to delete: ");
    scanf(" %[^\n]",str);
    switch(choice)
    {
        case 1: 
        for(int i=0;i<addressBook->contactCount;)
        {
          if(search_name(str,addressBook,i)==1)
           delete(str,addressBook,i);
          else
           i++;
        }
        break;
        case 2: 
        for(int i=0;i<addressBook->contactCount;)
        {
          if(search_phone(str,addressBook,i)==1)
           delete(str,addressBook,i);
          else
           i++;
        }
        break;
        case 3: 
        for(int i=0;i<addressBook->contactCount;)
        {
          if(search_email(str,addressBook,i)==1)
           delete(str,addressBook,i);
          else
           i++;
        }
        break;
        default: printf("Enter valid option\n");
    }
    printf("Contact deleted successfullyy\n");
}

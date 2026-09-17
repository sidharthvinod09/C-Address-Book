#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

//-------------------Function to list Contacts-------------------------//
void listContacts(AddressBook *addressBook) 
{
   // Sort contacts based on the chosen criteria

    // List contact list
    printf("\033[1;37m+----+--------------------------------------------------+--------------------+--------------------------------------------------+\033[0m\n");
    printf("\033[1;37m|\033[1;33m%-4s|%-50s|%-20s|%-50s\033[1;37m|\033[0m\n",
           "No.", "Name", "Phone No.", "Email");
    printf("\033[1;37m+----+--------------------------------------------------+--------------------+--------------------------------------------------+\033[0m\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("\033[1;37m|\033[1;36m%-4d|%-50s|%-20s|%-50s\033[1;37m|\033[0m\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
    }

    printf("\033[1;37m+----+--------------------------------------------------+--------------------+--------------------------------------------------+\033[0m\n");
    printf("\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

//--------------------Function  to Create Contacts--------------------//
void createContact(AddressBook *addressBook)
{
   char name[50];
   char phone[20];
   char email[50];

   // Call function for name validaton
   validateByName(name);

   // Call function for phone no. validation
   //validateByPhone(phone);

   phoneUniqueValidation(addressBook, phone);

   // Call function for email validation
   validateByEmail(email);

   strcpy(addressBook->contacts[addressBook->contactCount].name, name);
   strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
   strcpy(addressBook->contacts[addressBook->contactCount].email, email);

   addressBook->contactCount++;
}

//------------------Function to Search Contact-------------------------//
int searchContact(AddressBook *addressBook) 
{
   /* Define the logic for search */
   int choice;
   printf("Search by:\n");
   printf("1.Name\n2.Phone no.\n3.Email id\n");
   scanf("%d",&choice);

   switch (choice)
   {
        case 1:
           return searchByName(addressBook);
           break;
        case 2:
            return searchByPhone(addressBook);
            break;
        case 3:
            return searchByEmail(addressBook);
            break;
        default:
            printf("\033[1;31mInvalid choice !\033[0m\n");
            return 0;
            break;
    }
}

//-----------------------Function to edit Contact-------------------------//
void editContact(AddressBook *addressBook)
{
   /* Define the logic for Editcontact */
   int choice;
   int index;
   char name[50];
   char phone[20];
   char email[50];
   int found = searchContact(addressBook);

   if (found == 0)
   {
      return;
   }

   printf("Enter the index number : ");
   scanf("%d", &index);

   if (index < 1 || index > addressBook->contactCount)
   {
       printf("\033[1;31mInvalid index !\033[0m\n");
       printf("\n");
       return;
    }

   printf("Edit by:\n");
   printf("1.Name\n2.Phone no.\n3.Email id\n");
   scanf("%d",&choice);

   switch (choice)
   {
        case 1:
           validateByName(name);
           strcpy(addressBook->contacts[index -1].name,name);
           break;
        case 2:
            phoneUniqueValidation(addressBook, phone);
            strcpy(addressBook->contacts[index -1].phone,phone);
            break;
        case 3:
            validateByEmail(email);
            strcpy(addressBook->contacts[index -1].email,email);
            break;
        default:
            printf("\033[1;31mInvalid choice !\033[0m\n");
            break;
    }  
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char name[50];
    int count = 0;
    int index;

    // Read the name you want to delete 
    printf("Enter the Name: ");
    scanf(" %49[^\n]",name);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(name,addressBook->contacts[i].name) == 0)
        {
            count++;
            index = i;
        }
    }
    
    // If name not exist
    if (count == 0)
    {
       printf("\033[1;31mName not found !\033[0m\n");
       printf("\n");
    }
    else if(count == 1)    // if only one name exist in the contact list
    {
        for (int i = index; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }

        addressBook->contactCount--;

        printf("\033[1;32mContact deleted successfully.\033[0m\n");
        printf("\n");
    }
    else if (count > 1)
    {
        printf("\033[1;37m┏━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\033[0m\n");
        printf("\033[1;37m┃\033[1;33m%-4s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[1;33m%-20s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[0m\n",
               "No.", "Name", "Phone No.", "Email");
        printf("\033[1;37m┣━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\033[0m\n");
        
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, name) == 0)
            {
                
                printf("\033[1;37m┃\033[1;36m%-4d\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[1;36m%-20s\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[0m\n",
                       i + 1,
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
            }
        }
        printf("\033[1;37m┗━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m\n");

        printf("Enter the index: ");
        scanf(" %d",&index);

        // Check if index less than 1 or greater than contactCount
        if (index < 1 || index > addressBook->contactCount)
        {
            printf("\033[1;31mInvalid index.\033[0m\n");
            printf("\n");
        }
        else if(strcmp(addressBook->contacts[index-1].name, name) != 0)
        {
            printf("\033[1;31mPlese select an index from displayed contacts.\033[0m\n");
            printf("\n");
        }
        else
        {
           for (int i = index - 1; i < addressBook->contactCount - 1; i++)
           {
               addressBook->contacts[i] = addressBook->contacts[i+1];
            }
            addressBook->contactCount--;

            printf("\033[1;32mContact deleted successfully.\033[0m\n");
            printf("\n");
        }   
    }

   
}

//---------------------Function to Search By Name-------------------------//
int searchByName(AddressBook *addressBook)
{
   char name[50];
   int flag = 0;
   //Read Name from user
   printf("Enter the name: ");
   scanf(" %49[^\n]",name);
   printf("\n");

   printf("\033[1;37m┏━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\033[0m\n");
   printf("\033[1;37m┃\033[1;33m%-4s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[1;33m%-20s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[0m\n",
          "No.", "Name", "Phone No.", "Email");
   printf("\033[1;37m┣━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\033[0m\n");

   // Search for Name using loop
   for (int i = 0; i < addressBook->contactCount; i++)
   {
       // If the user typed name found from the contact list
       if (strcmp(name,addressBook->contacts[i].name) == 0)
       {    
            printf("\033[1;37m┃\033[1;36m%-4d\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[1;36m%-20s\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[0m\n",
                   i + 1,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);

            flag = 1;
        }
    }

    printf("\033[1;37m┗━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m\n");
            
   // If the user typed name is not found from the contact list
   if (flag == 0)
   {
       printf("\033[1;31mName Not Found !\033[0m\n");
       printf("\n");
       return 0;
    }
    return 1;
}
//---------------------------------------------------------------------//

//---------------------Function to Search By Phone number-------------------------//
int searchByPhone(AddressBook *addressBook)
{
   char phone[20];
   int flag = 0;
   // Read Phone no. from user
   printf("Enter the Phone No.: ");
   scanf(" %[^\n]",phone);
   printf("\n");

   printf("\033[1;37m┏━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\033[0m\n");
   printf("\033[1;37m┃\033[1;33m%-4s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[1;33m%-20s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[0m\n",
          "No.", "Name", "Phone No.", "Email");
   printf("\033[1;37m┣━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\033[0m\n");

   // Search for phone No. using loop
   for (int i = 0; i < addressBook->contactCount; i++)
   {
       // If the user typed Phone no. is found in the contact list
       if (strcmp(phone,addressBook->contacts[i].phone) == 0)
       {
            printf("\033[1;37m┃\033[1;36m%-4d\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[1;36m%-20s\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[0m\n",
                   i + 1,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            
            flag = 1;
        }
    }

    printf("\033[1;37m┗━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m\n");
   
    // If the user typed Phone no. is not found in the contact list
   if (flag == 0)
   {
       printf("\033[1;31mPhone No. Not Found !\033[0m\n");
       printf("\n");
       return 0;
    }
    return 1;
}
//----------------------------------------------------------------------------//

//---------------------Function to Search By Email Id-------------------------//
int  searchByEmail(AddressBook *addressBook)
{
   char email[50];
   int flag = 0;
   // Read Email id from user
   printf("Enter the Email Id: ");
   scanf(" %[^\n]",email);
   printf("\n");

   printf("\033[1;37m┏━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\033[0m\n");
   printf("\033[1;37m┃\033[1;33m%-4s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[1;33m%-20s\033[1;37m┃\033[1;33m%-50s\033[1;37m┃\033[0m\n",
          "No.", "Name", "Phone No.", "Email");
   printf("\033[1;37m┣━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\033[0m\n");

   //Search for Email id using loop
   for (int i = 0; i < addressBook->contactCount; i++)
   {
       // If the user typed email id is found in the contact list 
       if (strcmp(email,addressBook->contacts[i].email) == 0)
       {
            printf("\033[1;37m┃\033[1;36m%-4d\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[1;36m%-20s\033[1;37m┃\033[1;36m%-50s\033[1;37m┃\033[0m\n",
                   i + 1,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
        
            flag = 1;
            break;
        }
    }

    printf("\033[1;37m┗━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m\n");

   // If the user typed email id is not found in the contact list 
   if (flag == 0)
   {
       printf("\033[1;31mEmail Id Not Found !\033[0m\n");
       printf("\n"); 
       return 0;
    }
    return 1;
}
//--------------------------------------------------------------------------//

//-------------------Function to Validate by name----------------------------//
void validateByName(char name[])
{
   int flag;
   do
   {
       flag = 0;

       // Read new name from user
       printf("Enter the New name : ");
       scanf(" %49[^\n]",name);
        
       for (int i = 0; name[i] != '\0';i++)
       {
            if ((name[i] >= 'A' && name[i] <='Z')||
               (name[i] >='a' && name[i] <= 'z')||
                name[i] == ' ')
           {
               flag = 1;
            }
           else
           {
               printf("\033[31mPlease enter a real name.\033[0m\n");
               printf("\n");
               flag = 0;
               break;
            }
        }
    }
    while(flag == 0);
}
//--------------------------------------------------------------------//

//-----------------Function to Validate by Phone-----------------------//
void validateByPhone(char phone[])
{
   int flag;

   do
   {
       flag = 0;

       // Read phone number from user
       printf("Enter the Phone No. : ");
       scanf(" %19[^\n]",phone);
        
       for (int i = 0; phone[i] != '\0'; i++)
       {
           if (phone[i] >= '0' && phone[i] <= '9')
           {
               flag = 1;
            }
           else
           {
               flag = 0;
               break;
            }
        }

        // Check phone no. wether contain 10 digits or not
        if (strlen(phone) != 10)
        {
           printf("\033[31mPhone number should be exactly 10 digits.\033[0m\n");
           flag = 0;
           printf("\n");
        }

        // Check phone no. contan any alphabets rather than digits
        if (flag == 0 && strlen(phone)==10)
        {
           printf("\033[31mPhone number should contain only digits.\033[0m\n\n");
           printf("\n");
        }
    }
    while (flag == 0);
}
//-------------------------------------------------------------------------------------//

//---------------------Function to validate by email----------------------------------//
void validateByEmail(char email[])
{
   int flag;

   do
    {
       int dot_count = 0, at_count = 0;
       flag = 1;

       // Read email from user
       printf("Enter Email Id : ");
       scanf(" %49[^\n]",email);

       for(int i = 0; email[i] != '\0'; i++)
       {
           if (email[i] == '@')
           {
               at_count = 1;
            }

           if(email[i] == '.')
           {
               dot_count = 1;
            }
        }

       if (at_count == 0 || dot_count == 0)
       {
           printf("\033[31mEmail address invalid.\033[0m\n");
           printf("\n");
           flag = 0;
        }
    }
    while (flag == 0);
}
//------------------------------------------------------------------------//

//---------------Function to check phone no. is unique or not---------------//
void phoneUniqueValidation(AddressBook *addressBook, char phone[])
{
    int flag;
    
   do
   {
       flag = 1;
       
       // Call function to check the phone number contain 10 digits or not / contain non digits or not
       validateByPhone(phone);

       for (int i = 0; i < addressBook->contactCount; i++)
       {
           if (strcmp(addressBook->contacts[i].phone, phone) == 0)
           {
               printf("\033[31mPhone number already exist !\033[0m\n");
               printf("\n");
               flag = 0;
               break;
            }
        }
    } 
   while(flag == 0);
}
//---------------------------------------------------------------------------------//
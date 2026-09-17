#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    //------------------------Print title-------------------------------------//  
      printf("\033[1;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\033[0m\n");
      printf("\033[1;37m┃\033[1;33m%8s%s%9s\033[1;37m┃\033[0m\n",
             "",
             "ADDRESS BOOK MANAGEMENT BY SIDHARTH VINOD",
             "");
      printf("\033[1;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m\n");

    //----------------------Print Address book menu using loop----------------------------// 
    do {
        printf("\033[1;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\033[0m\n");
        printf("\033[1;37m┃\033[1;32m%18s%s%23s\033[1;37m┃\033[0m\n",
               "",
               "Address Book Menu",
               "");
        printf("\033[1;37m┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\033[0m\n");
        printf("\033[1;37m┃\033[1;36m 1. Create contact                                        \033[1;37m┃\033[0m\n");
        printf("\033[1;37m┃\033[1;36m 2. Search contact                                        \033[1;37m┃\033[0m\n");
        printf("\033[1;37m┃\033[1;36m 3. Edit contact                                          \033[1;37m┃\033[0m\n");
        printf("\033[1;37m┃\033[1;36m 4. Delete contact                                        \033[1;37m┃\033[0m\n");
        printf("\033[1;37m┃\033[1;36m 5. List all contacts                                     \033[1;37m┃\033[0m\n");
        printf("\033[1;37m┃\033[1;36m 6. Exit                                                  \033[1;37m┃\033[0m\n");
        printf("\033[1;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                // printf("Select sort criteria:\n");
                // printf("1. Sort by name\n");
                // printf("2. Sort by phone\n");
                // printf("3. Sort by email\n");
                // printf("Enter your choice: ");
                // int sortChoice;
                // scanf("%d", &sortChoice);
                listContacts(&addressBook);
                break;
            case 6:
                printf("\033[1;32mSaving and Exiting...\033[0m\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
    while (choice != 6);
    
    return 0;
}

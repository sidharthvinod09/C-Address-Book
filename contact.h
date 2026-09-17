#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int searchByName(AddressBook *addressBook);
int searchByPhone(AddressBook *addressBook);
int searchByEmail(AddressBook *addressBook);
void validateByName(char name[]);
void validateByPhone(char phone[]);
void validateByEmail(char email[]);
void phoneUniqueValidation(AddressBook *AddressBook, char phone[]);

#endif

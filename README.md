# C Address Book Management System

A menu-driven **Address Book Management System developed in C** as part of my Embedded Systems learning journey at Emertxe.

This project allows users to create, search, edit, delete, and list contacts. It also uses file handling to save and load contact information from a text file.

## 📌 Features

The application provides the following operations:

1. **Create Contact**

   * Add a new contact with:

     * Name
     * Phone Number
     * Email ID
   * Validates contact information.
   * Checks phone number uniqueness.

2. **Search Contact**

   * Search contacts using:

     * Name
     * Phone Number
     * Email ID

3. **Edit Contact**

   * Modify existing contact details.

4. **Delete Contact**

   * Delete a contact from the Address Book.
   * Supports selecting a contact when multiple contacts have the same name.

5. **List All Contacts**

   * Displays all contacts in a structured table.

6. **Exit**

   * Saves the current contacts to the file before exiting the application.

## 🛠️ Technologies & Concepts Used

* C Programming
* Structures
* Functions
* Pointers
* Arrays
* Strings
* String Handling
* File Handling
* Input Validation
* Searching
* Header Files
* Multiple Source Files
* Menu-Driven Programming

## 📂 Project Structure

```text
C-Address-Book/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── populate.c
├── populate.h
├── addressbook.txt
└── README.md
```

## 💾 File Handling

The project uses `addressbook.txt` to store contact information.

When the application starts, existing contacts are loaded from the file.

When the user selects **Exit**, the current contact information is saved back to the file.

The stored format is:

```text
Number of contacts
Name,Phone,Email
```

## ▶️ How to Compile

Make sure GCC is installed on your system.

Compile the project using:

```bash
gcc main.c contact.c file.c populate.c -o addressbook
```

Run the application:

```bash
./addressbook
```

## 📋 Address Book Menu

```text
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
```

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

* Implementing a multi-file C project
* Using structures to organize contact data
* Working with pointers and functions
* Handling strings and user input
* Performing contact searching and editing
* Implementing file read/write operations
* Applying input validation
* Building a menu-driven application
* Organizing C programs using `.c` and `.h` files

## 🚀 Future Improvements

Possible improvements for the project include:

* Adding contact sorting
* Improving input handling
* Adding more advanced search options
* Improving the user interface
* Adding additional data fields

---

**Developed by Sidharth Vinod**

As part of my Embedded Systems learning journey at **Emertxe Technologies**.

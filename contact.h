#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#include<ctype.h>

typedef struct {//
    char name[50];
    char phone[20];
    char email[50];
} Contact;// contect  sore all things like name,phone,mail.

typedef struct {
    Contact contacts[100];
    int contactCount;// sotre tha contect 
} AddressBook;//store address book


void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void saveAndExit(AddressBook *addressBook);



int validname(AddressBook *addresBook,char *name);
  int validphone(AddressBook *addresBook,char *phone);
   int validmail(AddressBook*addressBook,char *email);


   // sreach contect function definition:
     void searchname(AddressBook *addressBook);
     
      void searchphone(AddressBook *addressBook);
      
      void searchemail(AddressBook *addressBook);


      // edit contect function definition:
      void editname(AddressBook *addressBook,char *name);
      void editphone(AddressBook *addressBook,char *phone);
      void editmail(AddressBook *addressBook,char *email);


      //delete function call.

        


#endif


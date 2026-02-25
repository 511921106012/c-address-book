#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE * ptr=fopen("contact.csv","w");// file oening mood 
    fprintf(ptr,"%d\n",addressBook->contactCount);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(ptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(ptr);
}

void loadContactsFromFile(AddressBook *addressBook) {
     FILE * ptr=fopen("contact.csv","r");// file oening mood
        fscanf(ptr,"%d\n",&addressBook->contactCount);
    
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(ptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(ptr);
}
    





    


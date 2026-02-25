#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

int arr[100];

int count;

void listContacts(AddressBook *addressBook) 
{
	for(int i=0;i<addressBook->contactCount;i++)
	{
		printf("%-25s",addressBook->contacts[i].name);
		printf("%-15s",addressBook->contacts[i].phone);
		printf("%-25s\n",addressBook->contacts[i].email);
	}
	// Sort contacts based on the chosen criteria
}

void initialize(AddressBook *addressBook) {
	addressBook->contactCount = 0;
	// populateAddressBook(addressBook);

	// Load contacts from file during initialization (After files)
	loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
	saveContactsToFile(addressBook);
}


void createContact(AddressBook *addressBook)
{
	char name[20];
	int ret;
	ret=  validname(addressBook,name);
	while(ret != 1)
	{
		ret=validname(addressBook,name);
	}
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);

	char phone[15];
	ret=validphone(addressBook,phone);

	while(ret!=1)
	{
		ret =validphone(addressBook,phone);
	}
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);

	char mail[50];
	ret = validmail(addressBook,mail);
	while(ret!=1)
	{
		ret= validmail(addressBook,mail);

	}
    strcpy(addressBook->contacts[addressBook->contactCount].email,mail);

    addressBook->contactCount++;
	printf("\n\n   😍contact create success ❤️\n\n");

	/* Define the logic to create a Contacts */

}

void  searchContact(AddressBook *addressBook) 
{
	// int count=0;
	int chosse;

	//printf("enter the searches : \n");
	printf("1 : search the name \n");
	printf("2 : search the phone \n");
	printf("3 : search the email \n");
    printf("choose the option  any in one  : ");
	scanf("%d",&chosse);
	switch (chosse)
	{
		case 1:
			{
				searchname(addressBook);
				break;
			}
		case 2:
			searchphone(addressBook);
			break;
		case 3:
			{
				searchemail(addressBook);
			}
			break;

		default:
			break;
	}
	// return count;


}

void editContact(AddressBook *addressBook)
{
	int chosse,i;
	int serialnumber=1;
	searchContact(addressBook);
	if(count>1)
	{
		printf("contact have smiler name what you want to edit \n");
		printf(" which one you want enter your serial number : ");
		scanf("%d",&serialnumber);

	}
	printf(" enter the serial number which you want  \n");
	// take the user input
	printf("1 : edit the name \n");     
	printf("2 : edit the phone \n");
	printf("3 : edit the email\n");            
	scanf("%d",&chosse);

	switch (chosse)
	{
		case 1:
        {
            char name[50];
            editname(addressBook,name);
			strcpy(addressBook->contacts[arr[serialnumber - 1]].name,name);
			break;
        }	
        case 2:
        {
            
            char phone[50];
            editphone(addressBook,phone);
			strcpy(addressBook->contacts[arr[serialnumber - 1]].phone,phone);
			break;

            break;
        }
        case 3:
        {
            
            char email[50];
            editmail(addressBook,email);
			strcpy(addressBook->contacts[arr[serialnumber - 1]].email,email);
			break;

            break;
        }
        default:
        {
            printf("INVALID CHOICE\n");
            break;
        } 
	}
}


void deleteContact(AddressBook *addressBook)
{
    
	
	int serialnumber=1;
	
    searchContact(addressBook);
	
    if (count > 1)
    {
        printf("Similar contacts found\n");
        printf("Enter serial number to delete : ");
        scanf("%d", &serialnumber);
    

    }
   // int arr[serialnumber-1];
    for(int i=arr[serialnumber-1];i<addressBook->contactCount-1;i++)
    {

        Contact temp;

      strcpy(temp.name,addressBook->contacts[i].name);
      
      strcpy(temp.phone,addressBook->contacts[i].phone);
      
      strcpy(temp.email,addressBook->contacts[i].email);
      strcpy( addressBook->contacts[i].name,addressBook->contacts[i+1].name);
      strcpy( addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
      strcpy( addressBook->contacts[i].email,addressBook->contacts[i+1].email);
      strcpy( addressBook->contacts[i+1].name,temp.name);
      strcpy( addressBook->contacts[i+1].phone,temp.phone);
      strcpy( addressBook->contacts[i+1].email,temp.email);

    }
    addressBook->contactCount--;
	//printf(" delete successfully 👍");
   
    
}



int validname(AddressBook *addresBook,char *name)
{

	printf("enter the name : ");
	scanf(" %[^\n]",name);
	for(int i=0;name[i];i++)
	{
		if( isalpha(name[i])==0 && name[i] != ' ')
		{
			printf(" ☹️ -->name should be  contain only alphabits\n");
			return 0;
		}

	}
	return 1;
}




int validphone(AddressBook *addresBook,char *phone)
{
	printf("enter the mobile number : ");
	scanf(" %s",phone);

	if(strlen(phone)!=10)
	{
		printf("❌ you should enter 10 digit \n");
		return 0;

	}

	for(int i=0;phone[i];i++)

	{
		if(isdigit(phone[i])==0)
		{
			printf(" 😢 ->enter the number digit should  be\n");
			return 0;
		}
	}
	for(int i=0;i<addresBook->contactCount;i++)
	{
		if (strcmp(phone,addresBook->contacts[i].phone)==0)
		{
			printf("😒-->number should be unique\n");
			return 0;
		}

	}
	return 1;



}
int validmail(AddressBook*addressBook,char *email)
{
	// int i;
	//   char *p=".com";
	printf("enter the email :");
	scanf(" %[^\n]",email);

	while(!strchr(email,'@'))
	{

		printf(" 🥲-->you should enter the @ in the mail\n");
		return 0;

	}
	// char *p=".com";
	while(!strstr(email,".com"))
	{
		printf(" 😐-->mail should contain .com\n");
		return 0;
	}
	char *ptr1=strchr(email,'@');
	char *ptr2=strstr(email,".com");
	ptr1--;
	ptr2--;
	if(!isalnum(*ptr1))
	{
		printf(" 🙄-->you should enter the before @ alpha \n");
		return 0;
	}
	if(!isalpha(*ptr2))
	{
		printf(" 🫥-->should enter before .com alphabit only\n");
		return 0;
	}
	if (*(ptr2+5) != '\0')
	{
		printf(" 😐-->.com should be \n");
		return 0;
	}
	int count=0;

	for(int i=0;email[i];i++)
	{
		if(email[i]=='.')
			count++;

	}
	if (count!=1)
	{
		printf("😒-->give the correct mail\n");
		return 0;
	}
	// printf("sdfg\n");
	for(int i=0;i<addressBook->contactCount;i++)
	{
		if (strcmp(email,addressBook->contacts[i].email)==0)
		{
			printf("😒-->mail should be unique\n");
			return 0;
		}

	}
	return 1;

}


void searchname(AddressBook *addressBook)
{
	char name[50];
	int i,flag=0;
	count=0;
	printf("enter the name to search :");
	scanf(" %[^\n]",name);
	for( i=0;i<addressBook->contactCount;i++)
	{

		if (strcmp(name,addressBook->contacts[i].name)==0)
		{
			printf("%d . ",count+1);
			
		printf("%-25s",addressBook->contacts[i].name);
		printf("%-15s",addressBook->contacts[i].phone);
		printf("%-25s\n",addressBook->contacts[i].email);
			
			flag=1;
            arr[count++] = i;
		}
	}
	if(count==0)
	{
		printf("contact not fount\n");
	}
	// return count;

	// if(flag==0)
	// {
	//     printf("contact not found\n");
	//     return -1;
	// }
	// return 1;



}



void searchphone(AddressBook *addressBook)
{
	char phone[50];
	int i;
    count = 0;
	printf(" 👍  enter the phone to search :");
	scanf("%s",phone);

	for( i=0;i<addressBook->contactCount;i++)
	{
		if (strcmp(phone,addressBook->contacts[i].phone)==0)
		{
			
		printf("%-25s",addressBook->contacts[i].name);
		printf("%-15s",addressBook->contacts[i].phone);
		printf("%-25s\n",addressBook->contacts[i].email);

            arr[count++] = i;
            return;
		}

	}
	// if(i==addressBook->contactCount)
	// {
	//     printf("contact not found\n");
	//     return -1;
	// }
	printf("contact not found\n");
	// return 1;
}



void searchemail(AddressBook *addressBook)
{
	char email[50];
	int i;
    count = 0;
	printf("enter the email to search :");
	scanf("%s",email);

	for( i=0;i<addressBook->contactCount;i++)
	{
		if (strcmp(email,addressBook->contacts[i].email)==0)
		{
			
		printf("%-25s",addressBook->contacts[i].name);
		printf("%-15s",addressBook->contacts[i].phone);
		printf("%-25s\n",addressBook->contacts[i].email);
			arr[count++] = i;
            return;

		}

	}
	printf("email not found\n");
	// return 1;
}


//edit the contect ;
void editname(AddressBook *addressBook, char *name)
{
    int ret;
	ret= validname(addressBook,name);
	while(ret != 1)
	{
		ret = validname(addressBook,name);
	} 
}
void editphone(AddressBook *addressBook, char *phone)
{
    int ret;
	ret= validphone(addressBook,phone);
	while(ret != 1)
	{
		ret = validphone(addressBook,phone);
	} 
}
void editmail(AddressBook *addressBook, char *email)
{
    int ret;
	ret= validmail(addressBook,email);
	while(ret != 1)
	{
		ret = validmail(addressBook,email);
	} 
}



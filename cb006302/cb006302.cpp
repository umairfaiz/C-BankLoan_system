#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;/*Using C++ library*/

#define SIZE 100
int option;
int ID[SIZE];
char customerName[40];
int i = 0;
int pass;
int hold;
int custID;
int search;
char address[70];



struct loanDetails{
	char loanType[40];
	char loanDuration[40];
	int loanAmount;
	char status;
	struct loanDetails*LoanDetailPtr;
};

typedef struct loanDeatails LoanDetails;
typedef LoanDetails *nextPtr;






struct details
{
	char customerName[40];
	char address[70];
	int age;
	char gender;
	int NIC;
	int custID;

};
struct details d;/*Calling the structure method*/
/* self-referential structure */
struct listNode {
	char customerName[40];/* each listNode contains a character */
	char address[70];
	int age;
	char gender;
	int NIC;
	int custID;

	struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */

typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */
ListNodePtr startPtr = NULL; /* initially there are no nodes */

/*fucntion prototypes */
void MainMenu(); 
int customerRegistration();
int linearSearch(const int array[], int NIC, int size);
int customerID();
void insert(ListNodePtr *sPtr, char customerName[40], char address[70], int age, char gender, int NIC, int custID);
void printCustList(ListNodePtr currentPtr);
void viewAllCustomers();
void viewCustomer();
void removeCustomer();
void updateCustomer();
void applyLoan();
void updateLoanStatus();
void viewApprovedCustomer();
void viewPendingCustomer();
void viewRejectedCustomer();
void bubbleSort(int arr[]);
int binarySearch(const int b[], int searchKey, int low, int high);
void viewSingleCustomer(ListNodePtr *sPtr, int custID);
char removeSingleCustomer(ListNodePtr *sPtr, int custID);
int isEmpty(ListNodePtr sPtr);
void updateCus(ListNodePtr *sPtr, int custID, char address[70]);


int main(void){//beginning main function
	
	printf("\n**********************************************************************\n");
	printf("\t**** Welcome to Peoples Bank loan processing centre ****");
	printf("\n**********************************************************************\n");
	MainMenu();
	
	scanf("%d");
	return 0;
}//end of main function

void MainMenu(){//beginning mainMenu function
	

	printf("\nPlease select an option to proceed...\n\n\n1. Register customer\n\n"
		"2. Un-register customer\n\n3. Update customer\n\n4. View customer\n\n5. View all customers\n\n"
		"6. Apply for a loan\n\n7. Update loan status\n\n8. Loan status\n\n9. Exit portal\n\n\n\n");
	printf("Enter your option: ");
	scanf("%d", &option);
	
		switch (option){
		case 1:
			customerRegistration();
			i++;
			break;
		case 2:
			removeCustomer();
			break;
		case 3:
			updateCustomer();
			break;
		case 4:
			viewCustomer();
			break;	
		case 5:
			viewAllCustomers();
			break;
		case 6:
			applyLoan();
			break;
		case 7:
			updateLoanStatus();
			break;
		case 8:
			viewApprovedCustomer();
			break;
		case 9:
			exit(0);
			break;
		default:
			printf("\nInvalid option selected!\n");
		}

}//end of mainMenu function

int customerID(){
	srand(time(NULL));
	int ID =rand() % 100;
	return ID;
}

int customerRegistration(){

	int x; /* counter for initializing elements 0-99 of array a */
	int NICnum; /* value to locate in array a */
	int element; /* variable to hold location of NIC or -1 */
	

	printf("\n\nEnter your NIC number: ");
	scanf("%d", &d.NIC);

	element = linearSearch(ID, d.NIC, SIZE);
	d.custID = customerID();
	/* display results */
	if (element != -1) {
		printf("\nYou already have been registered\n", element);
		
		

	} /* end if */
	else{


		ID[i] = d.NIC;

		printf("\n\n\n\n\n\n\n************Please fill in the below fields***********\n\n\n\n\n");

		printf("\nCustomer name: ");
		scanf("%s", &d.customerName);
		printf("\nCustomer address: ");
		scanf("%s", &d.address);
		printf("\nCustomer age: ");
		scanf("%d", &d.age);
		printf("\nCustomer gender: ");
		scanf("%s", &d.gender);
		printf("\nCustomer ID: %d ", d.custID);
		

		insert(&startPtr, d.customerName, d.address, d.age, d.gender, d.NIC, d.custID); /* insert item in list */

		 /* end for */
		printf("\n\nYou have been successfully registered!\n");
	} /* end else */
	MainMenu();
	
	return 0; /* indicates successful termination */
		
} /* end */

int linearSearch(const int array[], int key, int size)
{
	/* loop through array */
	for (int n = 0; n < size; ++n) {
		if (array[n] == key) {
			return n; /* return location of NIC */
		} /* end if */
	} /* end for */
	return -1; /* NIC not found */
} /* end function linearSearch */


void insert(ListNodePtr *sPtr, char customerName[40],  char address[70],  int age, char gender, int NIC, int custID){
	ListNodePtr newPtr; /* pointer to new node */
	ListNodePtr previousPtr; /* pointer to previous node in list */
	ListNodePtr currentPtr; /* pointer to current node in list */

	newPtr = new ListNode;/*Create a node, substitute for malloc*/

	if (newPtr != NULL) { /* is space available */
		strncpy(newPtr->customerName, customerName, 40); /* places values in node */
		strncpy(newPtr->address, address, 70);
		newPtr->age = age;
		newPtr->gender = gender;
		newPtr->NIC = NIC;
		newPtr->custID = custID;
		newPtr->nextPtr = NULL; /* node does not link to another node */
		previousPtr = NULL;
		currentPtr = *sPtr;
		/* loop to find the correct location in the list */
		while (currentPtr != NULL && customerName > currentPtr->customerName) {
			previousPtr = currentPtr; /* walk to ... */
			currentPtr = currentPtr->nextPtr; /* ... next node */
		} /* end while */
		/* insert new node at beginning of list */
		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} /* end if */
		else { /* insert new node between previousPtr and currentPtr */
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		} /* end else */
	}
	else {
		printf("%c not inserted. No memory available.\n", customerName);
		printf("%c not inserted. No memory available.\n", address);
		printf("%c not inserted. No memory available.\n", age);
		printf("%c not inserted. No memory available.\n", gender);
		printf("%c not inserted. No memory available.\n", NIC);
		printf("%c not inserted. No memory available.\n", custID);
	} /* end else */
}
void printCustList(ListNodePtr currentPtr){
	//ListNodePtr currentPtr;
	/* if list is empty */
	if (currentPtr == NULL) {
		printf("\n");
		printf("List is empty.\n\n");
	} /* end if */
	else {
		printf("All customers registered\n\n");
		printf("%s%13s\n", "Customer ID", "Name");
		/* while not the end of the list */
		while (currentPtr != NULL) {
			
			printf("%7d%18s\n", currentPtr->custID, currentPtr->customerName);
			//printf("customer ID:%d --> ", currentPtr->custID);
			//printf("customer name:%c --> ", currentPtr->customerName);
			printf("\n");
			currentPtr = currentPtr->nextPtr;
		} /* end while */

		printf("\n");
	} /* end else */
	
	
} /* end function printList */

void viewAllCustomers(){
	printf("\n");
	printCustList(startPtr);
	MainMenu();
}
void viewCustomer(){
	bubbleSort(ID);
	printf("\nEnter Customer ID: ");
	scanf("%d", &d.custID);
	
	search = binarySearch(ID, d.custID, 0,SIZE - 1);
	if (search != -1){
		printf("Customer %d couldn't be found\n", d.custID);
		
	}
	else{
		printf("\nCustomer registration details");
		viewSingleCustomer(&startPtr, d.custID);
	}
	MainMenu();
}
void removeCustomer(){
	if (!isEmpty(startPtr)) {/* if list is not empty */
		printf("\nEnter customer ID to be deleted: ");
		scanf("\n%d", &d.custID);

		/* if character is found, remove it*/
		if (removeSingleCustomer(&startPtr, d.custID)) { /* remove item */
		  printf("Customer %d was deleted successfully.\n", d.custID);
		} /* end if */
		else {
		  printf("%d Customer was not found.\n\n", d.custID);
		} /* end else */
	} /* end if */
	else {
	printf("List is empty.\n\n");
	} /* end else */
	MainMenu();
}
void updateCustomer(){
	bubbleSort(ID);
	printf("\nEnter Customer ID: ");
	scanf("%d", &d.custID);

	search = binarySearch(ID, d.custID, 0, SIZE - 1);
	if (search != -1){
		printf("There was an error in updating customer %d\n", d.custID);

	}
	else{
		printf("\nUpdated customer details\n\n");

		printf("\n");
		printf("Enter the new address: ");
		scanf("%s", &d.address);

		updateCus(&startPtr, d.custID, d.address);
		printf("\n Updating customer was successful\n\n\n");
	}
	MainMenu();

}

void applyLoan(){

}
void updateLoanStatus(){

}
void viewApprovedCustomer(){

}
void viewPendingCustomer(){

}
void viewRejectedCustomer(){

}

void bubbleSort(int arr[]){

	/* loop to control number of passes */
	for (pass = 1; pass < SIZE; pass++) {
		/* loop to control number of comparisons per pass */
		for (i = 0; i < SIZE - 1; i++) {
			/* compare adjacent elements and swap them if first
			element is greater than second element */
			if (arr[i] > arr[i + 1]) {
				hold = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = hold;
			} /* end if */

		} /* end inner for */
	} /* end outer for */
}

int binarySearch(const int b[], int searchKey, int low, int high){
	int middle; /* variable to hold middle element of array */

	/* loop until low subscript is greater than high subscript */
	while (low <= high) {
		/* determine middle element of subarray being searched */
		middle = (low + high) / 2;
		/* display subarray used in this loop iteration */

		/* if searchKey matched middle element, return middle */
		if (searchKey == b[middle]) {
			return middle;
		} /* end if */

		/* if searchKey less than middle element, set new high */
		else if (searchKey < b[middle]) {
			high = middle - 1; /* search low end of array */
		} /* end else if */
		/* if searchKey greater than middle element, set new low */
		else {
			low = middle + 1; /* search high end of array */
		} /* end else */
	} /* end while */
	return -1; /* searchKey not found */
} /* end function binarySearch */

void viewSingleCustomer(ListNodePtr *sPtr, int custID){
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;

	if (custID == (*sPtr)->custID) {
		printf("\n\n Customer ID : %d \n\n Customer name : %s \n\n Customer Address : %s \n\n Customer age :%d \n\n Customer gender : %c \n\n NIC - %d\n", (*sPtr)->custID, (*sPtr)->customerName, (*sPtr)->address, (*sPtr)->age, (*sPtr)->gender, (*sPtr)->NIC);

	}
	else{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		while (currentPtr != NULL && currentPtr->custID != custID) {   /*If the ID is not the first node of the linked list*/
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if (currentPtr != NULL) {
			printf("\n\n Customer ID : %d \n\n Customer name : %s \n\n Customer Address : %s \n\n Customer age :%d \n\n Customer gender : %c \n\n NIC - %d\n", currentPtr->custID, currentPtr->customerName, currentPtr->address, currentPtr->age, currentPtr->gender, currentPtr->NIC);
				
		}
	}

}
char removeSingleCustomer(ListNodePtr *sPtr, int custID){

	ListNodePtr previousPtr; /* pointer to previous node in list */
	ListNodePtr currentPtr; /* pointer to current node in list */
	ListNodePtr tempPtr; /* temporary node pointer */
	/* delete first node */
	if (custID == (*sPtr)->custID) {
		tempPtr = *sPtr; /* hold onto node being removed */
		*sPtr = (*sPtr)->nextPtr; /* de-thread the node */
		free(tempPtr); /* free the de-threaded node */
		return custID;
	} /* end if */
	else {
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		/* loop to find the correct location in the list */
		while (currentPtr != NULL && currentPtr->custID != custID) {
			previousPtr = currentPtr;         /* walk to ...   */
			currentPtr = currentPtr->nextPtr; /* ... next node */
		} /* end while */

		/* delete node at currentPtr */
		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return custID;
		} /* end if */
	} /* end else */
	return '\0';//returns a null character is not found in the list
}/*end unregister*/

int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
} /* end function isEmpty */


void updateCus(ListNodePtr *sPtr, int custID, char address[70]){
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;

	if (custID == (*sPtr)->custID) { /*if the ID is the first node of the linked list*/
		strncpy((*sPtr)->address, address , 70); /*Updating the address of the structure with a new address*/
	}
	else {
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		while (currentPtr != NULL && currentPtr->custID != custID) {   /*If the ID is not the first node of the linked list*/
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL) {
			strncpy(currentPtr->address, address, 70); /*Replacing after finding the address*/
		}
		else{
			printf("Invalid Customer");
		}
	}
}

//void updateCustList(ListNodePtr *sPtr, int value){
//	ListNodePtr previousPtr;
//	ListNodePtr currentPtr;
	/* if list is empty */
//	if (currentPtr == NULL) {
//		printf("List is empty.\n\n");
//	} /* end if */
//	else {
//		while (currentPtr != NULL && currentPtr->custID == value) {
			//previousPtr = currentPtr;         /* walk to ...   */
//			currentPtr = currentPtr->nextPtr; /* ... next node */
			/* end while */
//			printf("The list is:\n");
			/* while not the end of the list */


//			printf("\nCustomer ID: %d ", currentPtr->custID);
//			printf("\nCustomer Name: %s ", currentPtr->customerName);
//			printf("\nCustomer Address: %s ", currentPtr->address);
//			printf("\nCustomer Age: %d ", currentPtr->age);
//			printf("\nGender: %c ", currentPtr->gender);
//			printf("\nNIC Number: %d ", currentPtr->NIC);
//			printf("\n");
//			currentPtr = currentPtr->nextPtr;
			/* end while */
//		} /* end else */
//	} /* end function printList */
//}

#include <stdio.h>
#include <string.h>

struct date{
	int day;
	int month;
	int year;
	
};
struct book{
	int id;
	char name[100];
	struct date publish;
};
struct user{
	int id;
	char name[100];
	int borrowedBookId;
};
void scanBook(struct book b[],int n){
	for (int i = 0 ; i < n ; i++){
		printf("enter book id \n");
		scanf("%d",&b[i].id);
		printf("enter book name \n");
		scanf("%s",b[i].name);
		printf("enter publish day \n");
		scanf("%d",&b[i].publish.day);
		printf("enter publish month \n");
		scanf("%d",&b[i].publish.month);
		printf("enter publish year \n");
		scanf("%d",&b[i].publish.year);
	}
}
void sortBook(struct book b[],int n){
	for(int i = 0 ; i < n - 1 ; i++){
		for (int j = 0 ; j < n-1-i ; j++){
			if(b[j].id > b[j+1].id){
				struct book temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
}
void searchBook(struct book b[],int n){
	int flag = 0;
	char k[100];
	printf("enter the book name you're searching for \n");
	scanf("%s",k);
	for (int i = 0 ; i < n ; i++){
			if(strcmp(k,b[i].name) == 0){
			flag = 1;
		}
	}
	if (flag == 1){
		printf("available \n");
	}

}
void findOldest(struct book b[],int n){
	int oldest = b[0].publish.year;
	//search oldest year
	for (int i = 1 ; i < n ; i++){
		if (oldest > b[i].publish.year){
			oldest = b[i].publish.year;
		}
	}
	//print books which fullfill the oldest var.
	printf("the oldest are : \n ");
	for(int i = 0 ; i < n ; i++){
		if (b[i].publish.year == oldest){
			puts(b[i].name);
		}
	}
}
void scanUserFromFile(struct user scannedUsers[],int numberOfUsers){
	
	FILE* f;
	f = fopen("users.txt","r");
	if (f == NULL){
		printf("ERROR\n");
		return;
	}
	while (!feof(f)){
		for (int i = 0 ; i < numberOfUsers ; i++){
		fscanf(f,"%d",&scannedUsers[i].id);
		fscanf(f,"%s",scannedUsers[i].name);
		fscanf(f,"%d",&scannedUsers[i].borrowedBookId);
		}
	}
	fclose(f);
}
void scanBookFromFile(struct book scanBookFromFile[],int numberOfScannedBooks){
	FILE* f;
	f = fopen("books.txt","r");
	if (f == NULL){
		printf("ERROR \n");
		return;
	}
	while (!feof(f)){
		for (int i = 0 ; i < numberOfScannedBooks ; i++){
		fscanf(f,"%d",&scanBookFromFile[i].id);
		fscanf(f,"%s",scanBookFromFile[i].name);
		fscanf(f,"%d",&scanBookFromFile[i].publish.day);
		fscanf(f,"%d",&scanBookFromFile[i].publish.month);
		fscanf(f,"%d",&scanBookFromFile[i].publish.year);
		}
	}
	fclose(f);
}
void printAllBooks(struct book b[],int n,struct book scanBookFromFile[],int numberOfScannedBooks){
	FILE *f= fopen("books.txt","a");
	for (int i = 0 ; i < n ; i++){
		fprintf(f,"%d \t",b[i].id);
		fprintf(f,"%s \t",b[i].name);
		fprintf(f,"%d \t",b[i].publish.day);
		fprintf(f,"%d \t",b[i].publish.month);
		fprintf(f,"%d ",b[i].publish.year);
	}
	for (int i = 0 ; i < numberOfScannedBooks ; i++){
		fprintf(f,"%d \t",scanBookFromFile[i].id);
		fprintf(f,"%s \t",scanBookFromFile[i].name);
		fprintf(f,"%d \t",scanBookFromFile[i].publish.day);
		fprintf(f,"%d \t",scanBookFromFile[i].publish.month);
		fprintf(f,"%d ",scanBookFromFile[i].publish.year);
	}
	fclose(f);
}
void printEvenusers(struct user scannedUsers[], int numberOfUsers){
	FILE * f = fopen("users2.txt","w");
	for (int i = 0 ; i < numberOfUsers ; i++){
		if (scannedUsers[i].id % 2 == 0){
			fprintf(f,"%s \t",scannedUsers[i].name);
			fprintf(f,"%d \t",scannedUsers[i].id);
		}
	}
	fclose(f);
}
void printSpecificUsers(struct user scannedUsers[], int numberOfUsers){
	for (int i = 0 ; i < numberOfUsers ; i++){
		if (scannedUsers[i].borrowedBookId == 7){
			printf("%s",scannedUsers[i].name);
			printf("%d",scannedUsers[i].id);
		}
	}
}
int main(){
	int n;
	printf("Enter number of books \n");
	scanf("%d",&n);
	struct book b[n];
	int choice;
	int numberOfScannedBooks;
	printf("Enter number of books in text file \n");
	scanf("%d",&numberOfScannedBooks);
	struct book scannedBooks[numberOfScannedBooks];
	int numberOfUsers;
	printf("Enter number of users in the text file \n");
	scanf("%d",&numberOfUsers);
	struct user scannedUsers[numberOfUsers];
while (true){
	printf("1. Scan N books \n");
	printf("2. Sort books \n");
	printf("3. Search for book by using book name \n");
	printf("4. Display books name with oldest year of publication \n");
	printf("5. Scan n books with all their details from a text file \n");
	printf("6. Scan n users with all their variables from a text file \n");
	printf("7. Print all books from their array to a text file \n");
	printf("8. Print all users from their array to a text file called that have even ids \n");
	printf("9. Print the name and id of all users that have borrowed book with id= 7 \n");
	printf("10 end the program \n");
	printf("choose a number : ");
	scanf("%d",&choice);
	if (choice == 10){
		break;
	}
	else if (choice == 1){
		scanBook(b,n);
	}
	else if (choice == 2){
		sortBook(b,n);
	}
	else if (choice == 3){
		searchBook(b,n);
	}
	else if (choice ==4){
		findOldest(b,n);
	}
	else if (choice == 6){
		scanUserFromFile(scannedUsers,numberOfUsers);
		}
	else if (choice == 5){
		scanBookFromFile(scannedBooks,numberOfScannedBooks);
		}
	else if (choice == 7){
		
		printAllBooks(b,n,scannedBooks,numberOfScannedBooks);
	}
	else if (choice == 8){
		printEvenusers(scannedUsers,numberOfUsers);
	}
	else if (choice == 9){
		printSpecificUsers(scannedUsers,numberOfUsers);
	}
	}
	
}

	


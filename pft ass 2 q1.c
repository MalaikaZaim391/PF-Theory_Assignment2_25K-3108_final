#include<stdio.h> 
#define max_books 100
#define max_booktitle 100
//global arrays/variables waghera used everywhere
char ch='y';
void askto_continue(){
    printf("\t\t\t =======================================\n");
    printf("Do you want to continue? Press Y if yes: ");
    scanf(" %c", &ch);
    getchar(); 
}
int count_books=0;
long long int isbns[max_books];
char titles[max_books][max_booktitle];
float prices[max_books];
int quantities[max_books];
//all functions below (before main)
void addbook(){
	long long int isbn; int i,j , quantity; float price; char title[max_booktitle];
	if(count_books>=max_books){
		printf("Inventory already full. Cannot add more books\n");
		return;
	}
	printf("Enter isbn: ");
	scanf("%lld", &isbn);
	for(i=0; i<count_books; i++){
		if(isbns[i]==isbn){
			printf("\nDuplicate ISBN. Book already in inventory\n");
			return;
		}
	}
	getchar();
	printf("Enter book title: ");
	fgets(title, max_booktitle, stdin);
	int k = 0;
	while (title[k] != '\0') {
    	if (title[k] == '\n') {
			title[k] = '\0';
			break; }
		k++; }
// above while loop instead of strcspn: title[strcspn(title, "\n")]='\0';
	printf("Enter price: ");
	scanf(" %f", &price);
	printf("Enter quantity: ");
	scanf(" %d", &quantity);
	isbns[count_books]=isbn;
	for(j=0; title[j]!='\0'; j++){
		titles[count_books][j]=title[j];
	}
	titles[count_books][j]='\0';
	prices[count_books]=price;
	quantities[count_books]=quantity;
	count_books++ ;
	printf("\t\tBook added successfully!\n");
}
void process_sale(){
	long long int isbn; int copies, i, found=0;
	printf("Enter ISBN of book to sell: ");
	scanf(" %lld", &isbn);
	for(i=0;i<count_books; i++){
		if(isbns[i]==isbn){
			found=1;
			printf("Book found: %s\n", titles[i]);
			printf("Book quantity in stock: %d\n", quantities[i]);
			printf("Enter copies do you want to sell: ");
			scanf("%d", &copies);
			if(copies<=0){
				printf("Invalid number of copies. \n");
				return;
			}
			if(copies>quantities[i]){
				printf("Not enough stock. Stock currently available: %d\n", quantities[i]);
			} else{
				quantities[i]-=copies;
				printf("Sale processed Successfully. Remaining stock: %d\n", quantities[i]);
			}
			break;
		}
	}
	if(!found){
		printf("No book found with ISBN %lld. Try again.\n", isbn);
	}
}
void generate_stockreport(){
	int i, found=0;
	printf("\n\t\tLow Stock Report (Quantity<5)\n");
	for(i=0;i<count_books;i++){
		if(quantities[i]<5){
			printf("ISBN: %lld\t|\tTitle: %s\t|\tQuantity: %d\n", isbns[i], titles[i], quantities[i]);
			found=1;
		}
	}
	if(!found){
		printf("\t\tNo low stock books, all books in good stock.\n");
	}
}
void displaybooks(){
	int i;
	if(count_books==0){
		printf("No books in inventory.\n");
		return;
	}
	printf("\n\t\t==Book Inventory==\n\n");
	for(i=0;i<count_books;i++){
		printf("\t%d. ISBN: %lld\tTitle: %s\tPrice: %.2f\tQuantity: %d\n\n",
		i+1, isbns[i], titles[i], prices[i], quantities[i]);
	}
}
void exitsystem(){
	printf("\nExiting the program...\n");
    printf("Thank you for using Liberty Books Inventory System!\n");
    ch='n';
}
//main begins here
int main(){
	int j;
	isbns[0] = 9780306406157; 
	char temp0[] = "Physics for Beginners";
	int len;
	for(len=0; temp0[len]!='\0'; len++) titles[0][len] = temp0[len];
	titles[0][len] = '\0';  
	prices[0] = 350.50; 
	quantities[0] = 10;
	isbns[1] = 9780140449136;
	char temp1[] = "Ancient History";
	for(len=0; temp1[len]!='\0'; len++) titles[1][len] = temp1[len];
	titles[1][len] = '\0';
	prices[1] = 250.00; 
	quantities[1] = 4;
	isbns[2] = 9780679783268;
	char temp2[] = "Modern Literature";
	for(len=0; temp2[len]!='\0'; len++) titles[2][len] = temp2[len];
	titles[2][len] = '\0';
	prices[2] = 450.00;
	quantities[2] = 6;
	count_books = 3;  
	int choice;
	do{
		printf("\n\t\t\t ***********Liberty Books Inventory Management System*********** \n");
		printf("\n1. Add new book");
		printf("\n2. Process a Sale");
		printf("\n3. Generate low stock report");
		printf("\n4. Display all books");
		printf("\n5. Exit system");
		printf("\n\t\t\t =======================================\n\t\tEnter your choice (1-5): ");
		scanf(" %d", &choice);
		switch(choice){
			case 1:
				addbook();
				askto_continue();				
				break;
			case 2:
				process_sale();
				askto_continue();	
				break;
			case 3:
				generate_stockreport();
				askto_continue();	
				break;
			case 4:
				displaybooks();
				askto_continue();	
				break;
			case 5:
				exitsystem();
				break;
			default:
				printf("Invalid choice. Please try again\n");
				askto_continue();
				break;
		}
	}while(ch=='y'|| ch=='Y');
	return 0;
}

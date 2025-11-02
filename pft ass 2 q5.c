#include<stdio.h>
char ch='y';
void askto_continue(){
    printf("\t\t\t =======================================\n");
    printf("Do you want to continue? Press Y if yes: ");
    scanf(" %c", &ch);
    getchar(); 
}
void trim_newline(char message[]){
	int i = 0;
	while (message[i] != '\0') {
    if (message[i] == '\n') {
		message[i] = '\0';
		break; 
		}
	i++; 
	}
}
void encode(char message[]){
	int length=0, i;
	while(message[length]!='\0') {
		length++;
	}
	for(i=0; i<length/2; i++){
		char temp=message[i];
		message[i]=message[length-i-1];
		message[length-i-1] = temp;
	}
	for(i=0; message[i]!='\0'; i++){
		message[i]=message[i]^18;
	}
	printf("Encoded message: %s\n", message);
}
void decode(char message[]){
	int length=0, i;
	while(message[length]!='\0') {
		length++;
	}
	for(i=0; message[i]!='\0'; i++){
		message[i]=message[i]^18;
	}
	for(i=0; i<length/2; i++){
		char temp=message[i];
		message[i]=message[length-i-1];
		message[length-i-1] = temp;
	}
	printf("Decoded message: %s\n", message);
}
void exitsystem(){
	printf("\nExiting the program...\n");
    printf("Thank you for using TCS Secure message system!\n");
    ch='n';
}
int main(){
	int choice, i; char message[200];
	do{
		printf("\n\t\t\t ***********TCS Secure Message System*********** \n");
		printf("\n1. Encode message");
		printf("\n2. Decode message");
		printf("\n3. Exit system");
		printf("\n\t\t\t =======================================\n\t\tEnter your choice (1-3): ");
		scanf(" %d", &choice);
		getchar();
		switch(choice){
			case 1:
				printf("\nMessage to encode goes here: ");
				fgets(message, 200, stdin);
				trim_newline(message);
				encode(message);
				askto_continue();
				break;
			case 2:
				printf("\nMessage to decode goes here: ");
				fgets(message, 200, stdin);
				trim_newline(message);
				decode(message);
				askto_continue();
				break;
			case 3:
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

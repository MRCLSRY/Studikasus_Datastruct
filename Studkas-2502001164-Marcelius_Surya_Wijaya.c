// 2502001165 - Marcelius Surya Wijaya
// Library import
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Declare node
struct node{
    long long int nim; 
	char name[50]; 
    char time[50];
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

// create New Node
struct node *createNewNode(long long int nim, char name[50], char timeNode[50]){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->nim = nim;
	strcpy(newNode->name, name); 
    strcpy(newNode->time, timeNode);

	newNode->left = NULL;
	newNode->right = NULL;
    
	return newNode;
}

// input student data
struct node *inputStudent(struct node *node, long long int nim){
	if(node == NULL){
		char name[50]; 
		char timess[50];

		printf("Student Name : "); 
        scanf("%[^\n]", name); 
        getchar();

		time_t times;
		time(&times);
		strcpy(timess, ctime(&times));
		printf("Attandance time	: %s\n", timess);
		
		return createNewNode(nim, name, timess);
	}

	if(nim < node->nim)
		node->left = inputStudent(node->left, nim);

    else if(nim > node->nim)
		node->right = inputStudent(node->right, nim);

	return node;
}

// display data
void display(struct node *root){
	if(root==NULL)
        return;

    else{
   	display(root->left);
        printf("Student ID         : %lld\n", root->nim);
        printf("Student Name       : %s\n", root->name);
        printf("Time of Attandance : %s\n", root->time);
    display(root->right);	
	}
}

// search nim
int found;
void nimSearch(struct node *node, long long int searchId){
	found = 0;
	if(node == NULL)
		return;

    else {
		nimSearch(node->left, searchId);

		// If nim and search nim compered and its same
		if(node->nim == searchId){
            found = 1;
            printf("Found !\n");
            printf("Name            : %s\n", node->name);
            printf("Time attandance : %s\n", node->time);
		}

		nimSearch(node->right, searchId);
	}
}

int main(){
	// Declare Variabel
	int id;
	int input;
	long long int searchNim;

	// Do 1 times, and loop if the condition is true
	do{
		system("cls");
        puts("Data Structure class");
		puts("-------------------------------");
        puts("1. Input student attendance");
        puts("2. Show student attendance");
        puts("3. Search student by Student ID");;
        puts("0. Exit");
		printf("Input : ");

		// Scan the input
		scanf("%d", &input);
        getchar();
		
		// Switch case
		switch (input)
		{
		// If user input 1
		case 1:
			puts("Input Data");
			
			printf("Student ID : ");
        	scanf("%lld", &id); 
        	getchar();

			root = inputStudent(root, id);
			break;
		
		// If user input 2
		case 2:
			system("cls");
			puts("Present students");
				
			if(root == NULL)
				puts("No Student Present!");
            else
				display(root);
			break;

		// If User input 3
		case 3:
			system("cls");
			printf("Student ID : ");
			scanf("%lld", &searchNim); 
            getchar();
			
			// call the function
			nimSearch(root, searchNim);
			
			// if not found
			if(found != 1)
				puts("Student was not present!");

			break;
		}

        printf("Press Enter to Continue");
		getchar();

	}while(input!=0);
}
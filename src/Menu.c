
/*
* 
* Mon Jun 15 16:51:12 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
* 
*/

#include "headers/Menu.h"

void runMenu(Database *db) {
	while(1) {
		printMenu();
		char *input = inputReader();
		int op = atoi(input);
		free(input);

		if(op == 0) break;

		switchOperation(op, db);
	}
}

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void printMenu() {
	clearScreen();
	printf("1. Create new table\n");
	printf("2. Insert into table\n");
	printf("3. Browse all from table\n");
	printf("4. Browse one at time from table\n");
	printf("5. Browse by field\n");
	printf("6. Match and Browse multiples fields\n");
	printf("7. Merge and Browse multiples fields\n");
	printf("8. Delete by field\n");
	printf("0. Save and quit\n");


	printf("\n\nType a number: ");
}

void switchOperation(int op, Database *db) {
	clearScreen();
	switch(op) {
		case 1: createNewTable(db);
				break;
		case 2: insertNewRecordIntoTable(db);
				break;
		case 3: browseAllRecords(db);
				break;
		case 4: browseOneAtATime(db);
				break;
		case 5: browseByField(db);
				break;
		case 6: findMultipleFields(db, op);
				break;
		case 7: findMultipleFields(db, op);
				break;
		case 8: deleteByField(db);
				break;
		default:	printf("Invalid operation.\n");
	}

	printf("Hit <ENTER> to get back to menu\n");
	char *input = inputReader();
	free(input);
}

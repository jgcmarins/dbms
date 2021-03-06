
/*
* 
* Sun Jun 14 17:50:52 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
* 
*/

#ifndef _TABLEMANAGER_H_
#define _TABLEMANAGER_H_

#include "Table.h"
#include "InsertionHandler.h"
#include "SelectionHandler.h"
#include "DeletionHandler.h"

#define TABLESEXTENSION ".tables"

typedef struct TableManager {
	char *fileName;
	char *path;
	ArrayList *names;
	ArrayList *tables;
	ArrayList *insert;
	ArrayList *select;
	ArrayList *deleter;
} TableManager;

TableManager *newTableManager(char *fileName);

void deleteTableManager(TableManager *tm);

TableManager *updateTableManager(TableManager *tm, char *fileName);

char *buildNameToTablesFiles(char *fileName, const char *extension);

void selectTables(TableManager *tm);

void buildTableManager(TableManager *tm);

void createTable(TableManager *tm, char *tableName);

void saveTables(TableManager *tm);

Table *getTable(TableManager *tm, char *tableName);

InsertionHandler *getInsertionHandler(TableManager *tm, char *tableName);

SelectionHandler *getSelectionHandler(TableManager *tm, char *tableName);

DeletionHandler *getDeletionHandler(TableManager *tm, char *tableName);

void insertIntoTable(TableManager *tm, char *tableName, ArrayList *record);

ArrayList *selectAllFromTable(TableManager *tm, char *tableName);

ArrayList *selectBySecondaryIndexFromTable(TableManager *tm, char *tableName, int position, SecondaryIndex *si);

ArrayList *match(SelectionHandler *sh, ArrayList *index);

ArrayList *merge(SelectionHandler *sh, ArrayList *index);

void deleteBySecondaryIndexFromTable(TableManager *tm, char *tableName, int position, long offset);

#endif

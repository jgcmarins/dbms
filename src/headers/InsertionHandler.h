
/*
* 
* Sun Jun  7 00:54:32 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
* 
*/

#ifndef _INSERTIONHANDLER_H_
#define _INSERTIONHANDLER_H_

#include "Table.h"

typedef struct InsertionHandler {
	Table *t;
	BinaryFileWriter *bfw;
	BinaryFileReader *bfr;
	int fragment;
	long previousOffset;
} InsertionHandler;

InsertionHandler *newInsertionHandler(Table *t);

void deleteInsertionHandler(InsertionHandler *ih);

void insert(InsertionHandler *ih, ArrayList *record);

long insertInt(InsertionHandler *ih, char *record, long offset);

long insertLong(InsertionHandler *ih, char *record, long offset);

long insertFloat(InsertionHandler *ih, char *record, long offset);

long insertDouble(InsertionHandler *ih, char *record, long offset);

long insertChar(InsertionHandler *ih, char *record, long offset);

long insertString(InsertionHandler *ih, char *record, long offset);

long findWorstFit(InsertionHandler *ih, ArrayList *record);

int calculateRecordSize(InsertionHandler *ih, ArrayList *record);

#endif

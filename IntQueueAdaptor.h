#ifndef _INT_QUEUE_ADAPTOR_H
#define _INT_QUEUE_ADAPTOR_H

#include "QueueCode.h"
#include "IntQueue.h"

QC IntQueue_Enqueue(IntQueue *q, int *element);
QC IntQueue_Dequeue(IntQueue *q, int **element);
QC IntQueue_Peek(IntQueue *q, int **element);

void IntQueue_Clear(IntQueue *q);
size_t IntQueue_Capacity(const IntQueue *q);
int IntQueue_Size(const IntQueue *q);
int IntQueue_IsEmpty(const IntQueue *q);
int IntQueue_IsFull(const IntQueue *q);
void *IntQueue_Search(const IntQueue *q, const void *element);
void IntQueue_Terminate(IntQueue *q);
QC IntQueue_ForEach(const IntQueue *q, QC (*func)(void *));


#endif

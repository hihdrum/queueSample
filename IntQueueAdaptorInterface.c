#include "Queue.h"
#include "IntQueueAdaptor.h"

const struct queueInterface IntQueueAdaptorIF =
{
  .enqueue = (QC (*)(Queue *, void *))IntQueue_Enqueue,
  .dequeue = (QC (*)(Queue *, void **))IntQueue_Dequeue,
  .peek = (QC (*)(Queue *, void **))IntQueue_Peek,
  .clear = (void (*)(Queue *))IntQueue_Clear,
  .capacity = (size_t (*)(const Queue *))IntQueue_Capacity,
  .size = (int (*)(const Queue *))IntQueue_Size,
  .isEmpty = (int (*)(const Queue *))IntQueue_IsEmpty,
  .isFull = (int (*)(const Queue *))IntQueue_IsFull,
  .search = (void *(*)(const Queue *, const void *))IntQueue_Search,
  .terminate = (void (*)(Queue *queue))IntQueue_Terminate,
  .forEach = (QC (*)(const Queue *, QC (*)(void *)))IntQueue_ForEach,
};

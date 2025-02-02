#include "Queue.h"
#include "FixedLengthQueue.h"

const struct queueInterface fixedLengthQueueIF =
{
  .enqueue = (QC (*)(Queue *, void *))FixedLengthQueue_Enqueue,
  .dequeue = (QC (*)(Queue *, void **))FixedLengthQueue_Dequeue,
  .peek = (QC (*)(Queue *, void **))FixedLengthQueue_Peek,
  .clear = (void (*)(Queue *))FixedLengthQueue_Clear,
  .capacity = (size_t (*)(const Queue *))FixedLengthQueue_Capacity,
  .size = (int (*)(const Queue *))FixedLengthQueue_Size,
  .isEmpty = (int (*)(const Queue *))FixedLengthQueue_IsEmpty,
  .isFull = (int (*)(const Queue *))FixedLengthQueue_IsFull,
  .search = (void *(*)(const Queue *, const void *))FixedLengthQueue_Search,
  .terminate = (void (*)(Queue *))FixedLengthQueue_Terminate,
  .forEach = (QC (*)(const Queue *, QC (*func)(void *)))FixedLengthQueue_ForEach,
};



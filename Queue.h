#ifndef _QUEUE_H
#define _QUEUE_H

#include <stddef.h>
#include "QueueCode.h"

struct queue
{
  void * const q;
  const struct queueInterface * const qif;
};

typedef struct queue Queue;

struct queueInterface
{
  QC (*enqueue)(Queue *queue, void *element);
  QC (*dequeue)(Queue *queue, void **element);
  QC (*peek)(Queue *queue, void **element);
  void (*clear)(Queue *queue);
  size_t (*capacity)(const Queue *queue);
  int (*size)(const Queue *queue);
  int (*isEmpty)(const Queue *queue);
  int (*isFull)(const Queue *queue);
  void *(*search)(const Queue *queue, const void *element);
  void (*terminate)(Queue *queue);
  QC (*forEach)(const Queue *q, QC (*func)(void *));
};


QC Queue_enqueue(Queue *q, void *element);
QC Queue_dequeue(Queue *q, void **element);
QC Queue_peek(Queue *q, void **element);
void Queue_clear(Queue *q);
size_t Queue_capacity(const Queue *q);
int Queue_size(const Queue *q);
int Queue_isEmpty(const Queue *q);
int Queue_isFull(const Queue *q);
void *Queue_search(const Queue *q, const void *element);
void Queue_terminate(Queue *q);
QC Queue_forEach(const Queue *q, QC (*func)(void *));

#endif

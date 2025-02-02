#include <string.h>
#include "Queue.h"

QC Queue_enqueue(Queue *q, void *element)
{
  return q->qif->enqueue(q->q, element);
}

QC Queue_dequeue(Queue *q, void **element)
{
  return q->qif->dequeue(q->q, element);
}

QC Queue_peek(Queue *q, void **element)
{
  return q->qif->peek(q->q, element);
}

void Queue_clear(Queue *q)
{
  return q->qif->clear(q->q);
}

size_t Queue_capacity(const Queue *q)
{
  return q->qif->capacity(q->q);
}

int Queue_size(const Queue *q)
{
  return q->qif->size(q->q);
}

int Queue_isEmpty(const Queue *q)
{
  return q->qif->isEmpty(q->q);
}

int Queue_isFull(const Queue *q)
{
  return q->qif->isFull(q->q);
}

void *Queue_search(const Queue *q, const void *element)
{
  return q->qif->search(q->q, element);
}

void Queue_terminate(Queue *q)
{
  return q->qif->terminate(q->q);
}

QC Queue_forEach(const Queue *q, QC (*func)(void *))
{
  return q->qif->forEach(q->q, func);
}

#include <stdio.h>
#include <string.h>
#include "FixedLengthQueueInterface.h"
#include "FixedLengthQueue.h"

#include "IntQueue.h"
#include "IntQueueAdaptorInterface.h"

struct v3
{
  int x;
  int y;
  int z;
};

QC v3_print(struct v3 *v)
{
  printf("{ %d, %d, %d}\n", v->x, v->y, v->z);
  return QC_OK;
}

QC i_print(int *x)
{
  printf("%d\n", *x);
  return QC_OK;
}

int main(void)
{
  struct fixedLengthQueue fxq;
  memset(&fxq, 0x00, sizeof(fxq));

  QC ret = FixedLengthQueue_Initialize(&fxq, sizeof(struct v3), 3);
  if(QC_OK != ret)
  {
    printf("初期化に失敗しました。\n");
    return 1;
  }

  Queue q = { .q = &fxq, .qif = &fixedLengthQueueIF };

  struct v3 val1 = { 1, 2, 3};
  ret = Queue_enqueue(&q, &val1);

  struct v3 val2 = { 4, 5, 6};
  ret = Queue_enqueue(&q, &val2);

  struct v3 val3 = { 7, 8, 9};
  ret = Queue_enqueue(&q, &val3);

  printf("IsFull = %d\n", Queue_isFull(&q));

  struct v3 val4 = { 10, 11, 12};
  ret = Queue_enqueue(&q, &val4);

  ret = Queue_forEach(&q, (QC (*)(void *))v3_print);

  struct v3 *pval = NULL;
  ret = Queue_peek(&q, (void **)&pval);
  printf("*pval = {%d, %d, %d}\n", pval->x, pval->y, pval->z);

  struct v3 *pval2 = NULL;
  ret = Queue_dequeue(&q, (void **)&pval2);
  v3_print(pval2);

  struct v3 *pval3 = Queue_search(&q, &val3);
  if(NULL != pval3)
  {
    v3_print(pval3);
  }

  ret = Queue_peek(&q, (void **)&pval);
  printf("*pval = {%d, %d, %d}\n", pval->x, pval->y, pval->z);

  printf("capacity = %zd\n", Queue_capacity(&q));
  printf("size = %d\n", Queue_size(&q));
  printf("IsEmpty = %d\n", Queue_isEmpty(&q));

  Queue_clear(&q);
  printf("IsEmpty = %d\n", Queue_isEmpty(&q));

  struct v3 *pval4 = NULL;
  Queue_dequeue(&q, (void **)&pval4);

  Queue_terminate(&q);

  printf("queue = %p\n", ((const FXQ *)q.q)->storage);

  Queue_terminate(&q);

  /*-------------------------------------*/

  IntQueue intQueue;
  if(Initialize(&intQueue, 10) == -1)
  {
    puts("キューの生成に失敗しました。");
    return 1;
  }

  Queue q2 = { .q = &intQueue, .qif = &IntQueueAdaptorIF };

  int v1 = 10;
  ret = Queue_enqueue(&q2, &v1);

  int v2 = 20;
  ret = Queue_enqueue(&q2, &v2);

  int v3 = 30;
  ret = Queue_enqueue(&q2, &v3);

  printf("IsFull = %d\n", Queue_isFull(&q2));

  int v4 = 40;
  ret = Queue_enqueue(&q2, &v4);

  ret = Queue_forEach(&q2, (QC (*)(void *))i_print);

  int *pv1 = NULL;
  ret = Queue_peek(&q2, (void *)&pv1);
  i_print(pv1);

  int *pv2 = NULL;
  ret = Queue_dequeue(&q2, (void **)&pv2);
  i_print(pv2);

  int *pv3 = Queue_search(&q2, &v3);
  if(NULL != pv3)
  {
    i_print(pv3);
  }

  ret = Queue_peek(&q2, (void *)&pv1);
  i_print(pv1);

  printf("capacity = %zd\n", Queue_capacity(&q2));
  printf("size = %d\n", Queue_size(&q2));
  printf("IsEmpty = %d\n", Queue_isEmpty(&q2));

  Queue_clear(&q2);
  printf("IsEmpty = %d\n", Queue_isEmpty(&q));

  struct v3 *pv4 = NULL;
  Queue_dequeue(&q, (void **)&pv4);

  Queue_terminate(&q2);

  printf("queue = %p\n", ((const IntQueue *)q.q)->que);

  Queue_terminate(&q2);

  return 0;
}


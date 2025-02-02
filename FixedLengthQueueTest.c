#include <stdio.h>
#include <string.h>
#include "FixedLengthQueue.h"

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

  ret = FixedLengthQueue_Initialize(&fxq, sizeof(struct v3), 3);
  if(QC_INITIALIZED == ret)
  {
    printf("初期化済みです。\n");
  }

  struct v3 val1 = { 1, 2, 3};
  ret = FixedLengthQueue_Enqueue(&fxq, &val1);

  struct v3 val2 = { 4, 5, 6};
  ret = FixedLengthQueue_Enqueue(&fxq, &val2);

  struct v3 val3 = { 7, 8, 9};
  ret = FixedLengthQueue_Enqueue(&fxq, &val3);

  printf("IsFull = %d\n", FixedLengthQueue_IsFull(&fxq));

  struct v3 val4 = { 10, 11, 12};
  ret = FixedLengthQueue_Enqueue(&fxq, &val4);

  ret = FixedLengthQueue_ForEach(&fxq, (QC (*)(void *))v3_print);

  struct v3 *pval = NULL;
  ret = FixedLengthQueue_Peek(&fxq, (void *)&pval);
  printf("*pval = {%d, %d, %d}\n", pval->x, pval->y, pval->z);

  struct v3 *pval2 = NULL;
  ret = FixedLengthQueue_Dequeue(&fxq, (void **)&pval2);
  v3_print(pval2);

  struct v3 *pval3 = FixedLengthQueue_Search(&fxq, &val3);
  if(NULL != pval3)
  {
    v3_print(pval3);
  }

  ret = FixedLengthQueue_Peek(&fxq, (void *)&pval);
  printf("*pval = {%d, %d, %d}\n", pval->x, pval->y, pval->z);

  printf("capacity = %zd\n", FixedLengthQueue_Capacity(&fxq));
  printf("size = %d\n", FixedLengthQueue_Size(&fxq));
  printf("IsEmpty = %d\n", FixedLengthQueue_IsEmpty(&fxq));

  FixedLengthQueue_Clear(&fxq);
  printf("IsEmpty = %d\n", FixedLengthQueue_IsEmpty(&fxq));

  struct v3 *pval4 = NULL;
  FixedLengthQueue_Dequeue(&fxq, (void **)&pval4);

  FixedLengthQueue_Terminate(&fxq);

  printf("queue = %p\n", fxq.storage);

  FixedLengthQueue_Terminate(&fxq);

  return 0;
}


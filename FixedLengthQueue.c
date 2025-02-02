#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log.h"
#include "FixedLengthQueue.h"

QC FixedLengthQueue_Initialize(FXQ *q, size_t elementSize, size_t max)
{
  LOG_ENT("\n");

  QC ret = QC_INITIALIZED;

  if(NULL != q->storage)
  {
    LOG_INF("記憶領域確保済み。");
    goto END;
  }

  q->elementSize = elementSize;
  q->max = 0;
  q->num = 0;
  q->front = 0;
  q->rear = 0;
  q->storage = NULL;

  void *storage = calloc(elementSize, max);
  if(NULL == storage)
  {
    LOG_ERR("メモリ(element = %zd, max = %zd)の確保に失敗しました。\n", elementSize, max);
    q->max = 0;
    ret = QC_ERR;
    goto END;
  }

  q->max = max;
  q->storage = storage;

  ret = QC_OK;

END:
  LOG_RET("ret = %s\n", Queue_CodeStr(ret));
  return ret;
}

QC FixedLengthQueue_Enqueue(struct fixedLengthQueue *q, void *element)
{
  LOG_ENT("\n");

  QC ret = QC_ERR;

  if(q->num >= q->max)
  {
    LOG_INF("最大容量(num = %d, max = %zd)のためEnqueueできません。\n", q->num, q->max);
    goto END;
  }

  q->num++;

  void *rear = q->storage + (q->elementSize * q->rear);
  memcpy(rear, element, q->elementSize);

  q->rear++;
  ret = QC_OK;

  END:

  LOG_RET("ret = %s, num = %d, max = %zd\n", Queue_CodeStr(ret), q->num, q->max);
  return ret;
}

QC FixedLengthQueue_Dequeue(struct fixedLengthQueue *q, void **element)
{
  LOG_ENT("\n");

  QC ret = QC_ERR;
  if(q->num <= 0)
  {
    LOG_INF("要素が無いためデキューできません。(num = %d)\n", q->num);
    goto END;
  }

  q->num--;
  *element = q->storage + (q->elementSize * q->front);
  q->front++;

  /* リングバッファのポインタを調整する。*/
  if(q->front == q->max)
  {
    q->front = 0;
  }

  ret = QC_OK;

END:
  LOG_RET("ret = %s, num = %d, max = %zd\n", Queue_CodeStr(ret), q->num, q->max);
  return ret;
}

QC FixedLengthQueue_Peek(const struct fixedLengthQueue *q, void **element)
{
  LOG_ENT("\n");

  QC ret = QC_ERR;

  if(q->num <= 0)
  {
    LOG_INF("要素が無いためピークできません。(num = %d)\n", q->num);
    goto END;
  }

  *element = q->storage + (q->elementSize * q->front);
  ret = QC_OK;

END:
  LOG_RET("ret = %s, front = %d\n", Queue_CodeStr(ret), q->front);
  return ret;
}

void FixedLengthQueue_Clear(struct fixedLengthQueue *q)
{
  LOG_ENT("\n");

  q->num = 0;
  q->front = 0;
  q->rear = 0;

  LOG_RET("\n");
}

size_t FixedLengthQueue_Capacity(const struct fixedLengthQueue *q)
{
  LOG_ENT("\n");
  LOG_RET("\n");
  return q->max;
}

int FixedLengthQueue_Size(const struct fixedLengthQueue *q)
{
  LOG_ENT("\n");
  LOG_RET("\n");
  return q->num;
}

int FixedLengthQueue_IsEmpty(const struct fixedLengthQueue *q)
{
  LOG_ENT("\n");
  LOG_RET("\n");
  return q->num == 0;
}

int FixedLengthQueue_IsFull(const struct fixedLengthQueue *q)
{
  LOG_ENT("\n");
  LOG_RET("\n");
  return q->num == q->max;
}

void *FixedLengthQueue_Search(const struct fixedLengthQueue *q, const void *element)
{
  LOG_ENT("\n");

  for(int i = 0; i < q->num; i++)
  {
    void *obj = q->storage + (q->elementSize * ((i + q->front) % q->max));
    if(0 == memcmp(element, obj, q->elementSize))
    {
      LOG_INF("i = %d\n", i);
      return obj;
    }
  }

  LOG_RET("\n");
  return NULL;
}

QC FixedLengthQueue_ForEach(const struct fixedLengthQueue *q, QC (*func)(void *))
{
  LOG_ENT("\n");

  QC ret_all = QC_OK;

  for(int i = 0; i < q->num; i++)
  {
    void *obj = q->storage + (q->elementSize * (i % q->max));
    QC ret  = func(obj);
    if(QC_ERR == ret)
    {
      LOG_INF("i = %d, ret = %s\n", i, Queue_CodeStr(ret));
      if(QC_OK == ret_all)
      {
        ret_all = QC_ERR;
      }
    }
  }

  LOG_RET("\n");
  return ret_all;
}

void FixedLengthQueue_Terminate(struct fixedLengthQueue *q)
{
  LOG_ENT("\n");

  if(NULL != q->storage)
  {
    free(q->storage);
    q->storage = NULL;

    LOG_INF("記憶領域を開放しました。\n");
  }
  else
  {
    LOG_INF("記憶領域は開放済みです。\n");
  }

  q->max = 0;
  q->num = 0;
  q->front = 0;
  q->rear = 0;

  LOG_RET("\n");
}

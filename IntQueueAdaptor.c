#include "log.h"
#include "IntQueueAdaptor.h"

QC IntQueue_Enqueue(IntQueue *q, int *element)
{
  LOG_ENT("\n");
  QC ret = QC_ERR;

  int iRet = Enque(q, *element);
  if(-1 == iRet)
  {
    LOG_INF("最大容量(num = %d, max = %d)のためEnqueueできません。\n", q->num, q->max);
    goto END;
  }

  ret = QC_OK;

END:
  LOG_RET("ret = %s\n", Queue_CodeStr(ret));
  return ret;
}

/* Dequeueの型上実現ができないので、内部構造を知っている体で対応する。*/
QC IntQueue_Dequeue(IntQueue *q, int **element)
{
  LOG_ENT("\n");
  QC ret = QC_ERR;

  if(q->num <= 0)
  {
    goto END;
  }

  q->num--;
  *element = &q->que[q->front++];

  /* リングバッファのポインタを調整する。*/
  if(q->front == q->max)
    q->front = 0;

  ret = QC_OK;

END:
  LOG_RET("ret = %s\n", Queue_CodeStr(ret));
  return ret;
}

/* Peekの型上実現ができないので、内部構造を知っている体で対応する。*/
QC IntQueue_Peek(IntQueue *q, int **element)
{
  LOG_ENT("\n");
  QC ret = QC_ERR;

  if(q->num <= 0)
  {
    goto END;
  }

  *element = &q->que[q->front];

  ret = QC_OK;

END:
  LOG_RET("ret = %s\n", Queue_CodeStr(ret));
  return ret;
}

void IntQueue_Clear(IntQueue *q)
{
  LOG_ENT("\n");
  Clear(q);
  LOG_RET("\n");
}

size_t IntQueue_Capacity(const IntQueue *q)
{
  LOG_ENT("\n");
  size_t ret = (size_t)Capacity(q);

  LOG_RET("\n");
  return ret;
}

int IntQueue_Size(const IntQueue *q)
{
  LOG_ENT("\n");
  int ret = Size(q);

  LOG_RET("\n");
  return ret;
}

int IntQueue_IsEmpty(const IntQueue *q)
{
  LOG_ENT("\n");
  int ret = IsEmpty(q);

  LOG_RET("\n");
  return ret;

}

int IntQueue_IsFull(const IntQueue *q)
{
  LOG_ENT("\n");
  int ret = IsFull(q);

  LOG_RET("\n");
  return ret;
}

void *IntQueue_Search(const IntQueue *q, const void *element)
{
  LOG_ENT("\n");
  void *ret = NULL;

  int index = Search(q, *(int *)element);
  if(-1 == index)
  {
    goto END;
  }

  ret = q->que + sizeof(int) * index;

END:
  LOG_RET("\n");
  return ret;
}

void IntQueue_Terminate(IntQueue *q)
{
  LOG_ENT("\n");
  Terminate(q);

  /* Terminateバグ対応 */
  q->que = NULL;

  LOG_RET("\n");
}

QC IntQueue_ForEach(const IntQueue *q, QC (*func)(void *))
{
  LOG_ENT("\n");

  QC ret_all = QC_OK;

  for(int i = 0; i < q->num; i++)
  {
    QC ret = func(&q->que[i]);
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

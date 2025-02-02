#include "IntQueue.h"

/* int型キュー IntQueue (ソース部) */
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

/*--- キューの初期化 ---*/
int Initialize(IntQueue *q, int max)
{
  q->num = 0;
  q->front = 0;
  q->rear = 0;
  q->que = NULL;

  int *queue = calloc(max, sizeof(int));
  if(NULL == queue)
  {
    q->max = 0;
    return -1;
  }

  q->max = max;
  q->que = queue;

  return 0;
}

/*--- キューにデータをエンキュー ---*/
int Enque(IntQueue *q, int x)
{
  if(q->num >= q->max)
  {
    return -1;
  }

  /* else */

  q->num++;
  q->que[q->rear++] = x;

  /* リングバッファのポインタを調整する。*/
  if(q->rear == q->max)
  {
    q->rear = 0;
  }

  return 0;
}

/*--- キューからデータをデキュー ---*/
int Deque(IntQueue *q, int *x)
{
  if(q->num <= 0)
  {
    return -1;
  }

  q->num--;
  *x = q->que[q->front++];

  /* リングバッファのポインタを調整する。*/
  if(q->front == q->max)
    q->front = 0;

  return 0;
}

/*--- キューからデータをピーク ---*/
int Peek(const IntQueue *q, int *x)
{
  if(q->num <= 0)
    return -1;

  *x = q->que[q->front];
  return 0;
}

/*--- 全データを削除 ---*/
void Clear(IntQueue *q)
{
  q->num = 0;
  q->front = 0;
  q->rear = 0;
}

/*--- キューの容量 ---*/
int Capacity(const IntQueue *q)
{
  return q->max;
}

/*--- キューに蓄えられているデータ数 ---*/
int Size(const IntQueue *q)
{
  return q->num;
}

/*--- キューは空か ---*/
int IsEmpty(const IntQueue *q)
{
  return q->num == 0;
}

/*--- キューは満杯か ---*/
int IsFull(const IntQueue *q)
{
  return q->num == q->max;
}

/*--- キューからの探索 ---*/
int Search(const IntQueue *q, int x)
{
  int i, idx;
  for(i = 0; i < q->num; i++)
  {
    if(q->que[idx = (i + q->front) % q->max] == x)
      return idx;
  }

  return -1;
}

/*--- 全データの表示 ---*/
void Print(const IntQueue *q)
{
  int i;
  for(i = 0; i < q->num; i++)
  {
    printf("%d ", q->que[(i + q->front) % q->max]);
  }
  putchar('\n');
}

/*--- キューの後始末 ---*/
/* この関数2回呼び出したら、異常終了するのでは? */
void Terminate(IntQueue *q)
{
  if(q->que != NULL)
    free(q->que);

  q->max = q->num = q->front = q->rear = 0;
}

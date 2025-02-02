#ifndef _FIXED_LENGTH_QUEUE
#define _FIXED_LENGTH_QUEUE

#include "Queue.h"

/* 固定サイズデータ長のキュー */

struct fixedLengthQueue
{
  size_t elementSize; /* 1件の要素のサイズ 各要素は固定長であるとする。 */
  size_t max;         /* 保存可能最大要素数 */
  int num;            /* 現在保存している要素数 */
  int front;          /* リングバッファ フロント側ポイント用 */
  int rear;           /* リングバッファ リア側ポイント用 */
  void *storage;      /* キュー記憶領域へのポインタ */
};

typedef struct fixedLengthQueue FXQ;

QC FixedLengthQueue_Initialize(FXQ *q, size_t elementSize, size_t max);
QC FixedLengthQueue_Enqueue(FXQ *q, void *element);
QC FixedLengthQueue_Dequeue(FXQ *q, void **element);
QC FixedLengthQueue_Peek(const FXQ *q, void **element);
void FixedLengthQueue_Clear(FXQ *q);
size_t FixedLengthQueue_Capacity(const FXQ *q);
int FixedLengthQueue_Size(const FXQ *q);
int FixedLengthQueue_IsEmpty(const FXQ *q);
int FixedLengthQueue_IsFull(const FXQ *q);
void *FixedLengthQueue_Search(const FXQ *q, const void *element);
void FixedLengthQueue_Terminate(FXQ *q);
QC FixedLengthQueue_ForEach(const FXQ *q, QC (*func)(void *));

#endif

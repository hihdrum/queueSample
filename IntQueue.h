/* int型キュー IntQueue (ヘッダ部) */

#ifndef ___IntQueue
#define ___IntQueue

/* キューを実現する構造体 */
typedef struct {
  int max;
  int num;
  int front;
  int rear;
  int *que;
} IntQueue;

/*--- キューの初期化 ---*/
int Initialize(IntQueue *q, int max);

/*--- キューにデータをエンキュー ---*/
int Enque(IntQueue *q, int x);

/*--- キューからデータをデキュー ---*/
int Deque(IntQueue *q, int *x);

/*--- キューからデータをピーク ---*/
int Peek(const IntQueue *q, int *x);

/*--- 全データを削除 ---*/
void Clear(IntQueue *q);

/*--- キューの容量 ---*/
int Capacity(const IntQueue *q);

/*--- キューに蓄えられているデータ数 ---*/
int Size(const IntQueue *q);

/*--- キューは空か ---*/
int IsEmpty(const IntQueue *q);

/*--- キューは満杯か ---*/
int IsFull(const IntQueue *q);

/*--- キューからの探索 ---*/
int Search(const IntQueue *q, int x);

/*--- 全データの表示 ---*/
void Print(const IntQueue *q);

/*--- キューの後始末 ---*/
void Terminate(IntQueue *q);

#endif

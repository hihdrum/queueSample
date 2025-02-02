/* int型キュー IntQueueの利用例 ---*/
#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
  IntQueue que;
  if(Initialize(&que, 64) == -1)
  {
    puts("キューの生成に失敗しました。");
    return 1;
  }

  while(1)
  {
    int m, x;
    printf("現在のデータ数 : %d / %d\n", Size(&que), Capacity(&que));
    printf("(1)エンキュー (2)デキュー (3)ピーク (4)表示 (0)終了 : ");
    scanf("%d", &m);

    if(0 == m) break;

    switch(m)
    {
      case 1: /*--- エンキュー ---*/
        printf("データ : "); scanf("%d", &x);
        if(Enque(&que, x) == -1)
          puts("\aエラー:エンキューに失敗しました。");
        break;
      case 2: /*--- デキュー ---*/
        if(Deque(&que, &x) == -1)
        {
          puts("\aエラー:デキューに失敗しました。");
        }
        else
        {
          printf("デキューしたデータは%dです。\n", x);
        }
        break;
      case 3: /*--- ピーク ---*/
        if(Peek(&que, &x) == -1)
        {
          puts("\aエラー:ピークに失敗しました。");
        }
        else
        {
          printf("ピークしたデータは%dです。\n", x);
        }
        break;
      case 4: /*--- 表示 ---*/
        Print(&que);
        break;
    }
  }

  Terminate(&que);
  return 0;
}

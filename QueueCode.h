#ifndef _QUEUE_CODE_H
#define _QUEUE_CODE_H

enum queueCode
{
  QC_OK,          /* 正常 */
  QC_INITIALIZED, /* 初期化済み */
  QC_ERR,         /* 異常 */
};

typedef enum queueCode QC;

const char *Queue_CodeStr(QC v);

#endif

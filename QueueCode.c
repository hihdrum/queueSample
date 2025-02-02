#include "QueueCode.h"

const char *Queue_CodeStr(QC v)
{
  static const char *valueStr[] =
  {
    "QC_OK",
    "QC_INITIALIZED",
    "QC_ERR"
  };

  return valueStr[v];
}

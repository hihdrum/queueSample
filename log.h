#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>

#ifdef LOG_DEBUG

#define LOG_DBG(fmt, ...) printf("%s,%05d,%s:DBG:" fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_INF(fmt, ...) printf("%s,%05d,%s:INF:" fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...) printf("%s,%05d,%s:ERR:" fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#define LOG_ENT(fmt, ...) printf("%s,%05d,%s:ENT:" fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_RET(fmt, ...) printf("%s,%05d,%s:RET:" fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#else

#define LOG_DBG(fmt, ...)
#define LOG_INF(fmt, ...)
#define LOG_ERR(fmt, ...)

#define LOG_ENT(fmt, ...)
#define LOG_RET(fmt, ...)

#endif

#endif

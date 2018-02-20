#ifndef _LIBICONV_H
#define _LIBICONV_H
#include <stddef.h>
#if defined _WIN32 || _WIN64
# ifdef WINICONV_EXPORTS
#define DLLSPEC __declspec(dllexport)
# else
#define DLLSPEC __declspec(dllimport)
# endif
#endif

#ifndef WINICONV_CONST
# ifdef ICONV_CONST
#  define WINICONV_CONST ICONV_CONST
# else
#  define WINICONV_CONST const
# endif
#endif
#ifdef __cplusplus
extern "C" {
#endif
typedef void* iconv_t;
DLLSPEC iconv_t iconv_open(const char *tocode, const char *fromcode);
DLLSPEC int iconv_close(iconv_t cd);
DLLSPEC size_t iconv(iconv_t cd, WINICONV_CONST char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft);
#ifdef __cplusplus
}
#endif
#endif
#ifdef WIN32
#undef DLLSPEC
#endif
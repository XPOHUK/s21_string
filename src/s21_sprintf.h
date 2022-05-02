#ifndef _SRC_S21_SPRINTF_H_
#define _SRC_S21_SPRINTF_H_

#include <stdarg.h>

typedef struct fmt{
    fmt* next;
    char* begin;
    char* end;
    int flag_left;
    int flag_sign;
    int flag_space;
    int width;
    int precision;
    char length;
    char specifier;
} fmt_t;

int _parse_fmt(fmt* fmt, const char** from);
fmt* _new_fmt();
int _get_flags(fmt* fmt, const char** from);
int _out_int(fmt* fmt, va_list ptr, char* str);
int _out_float(fmt* fmt, va_list ptr, char* str);
int _out_char(fmt* fmt, va_list ptr, char* str);
int _out_string(fmt* fmt, va_list ptr, char* str);

#endif // _SRC_S21_SPRINTF_H_ 

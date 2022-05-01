#ifndef _SRC_S21_SPRINTF_H_
#define _SRC_S21_SPRINTF_H_

#include <stdarg.h>

typedef struct {
    int flag_left;
    int flag_sign;
    int flag_space;
    int width;
    int precision;
    char length;
    char specifier;
} fmt;

int _parse_fmt(fmt* parsed, char** from);
fmt* _new_fmt();
int _out_int(fmt* fmt, va_list ptr, char* str);
int _out_float(fmt* fmt, va_list ptr, char* str);
int _out_char(fmt* fmt, va_list ptr, char* str);
int _out_string(fmt* fmt, va_list ptr, char* str);

#endif // _SRC_S21_SPRINTF_H_ 

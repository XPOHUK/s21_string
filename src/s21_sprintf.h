#ifndef _SRC_S21_SPRINTF_H_
#define _SRC_S21_SPRINTF_H_

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

#endif // _SRC_S21_SPRINTF_H_ 

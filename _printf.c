#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

int _printf(const char* format, ...){
int chars_printed;
va_list arguments;
va_start(arguments, format);

while(*format != '\0'){
if (*format == '%'){
format++; 
}else{
/* regular character, just output it */
putchar(*format);
chars_printed++;
format++;
}
}
/* move past the '%' */
switch (*format){
case 'c':
/* output a character argument */
putchar(va_arg(arguments, int));
chars_printed++;
break;
case 's':
/* output a string argument */
fputs(va_arg(arguments, const char*), stdout);
chars_printed += strlen(va_arg(arguments, const char*));
break;
case '%':
/* output a literal '%' */
putchar('%');
chars_printed++;
break;
default:
/* unsupported format specifier, print as is */
putchar('%');
putchar(*format);
chars_printed += 2;
break;
}
va_end(arguments);
return chars_printed;
}


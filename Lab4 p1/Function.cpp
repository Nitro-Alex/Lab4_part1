#include <Windows.h>
#include "Function.h"

char rusmas[256];
char* rus(const char* text)
{
    CharToOemA(text, rusmas);
    return rusmas;
}

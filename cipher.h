#ifndef CIPHER_H
#define CIPHER_H
#include <wchar.h>
int letterToNumber(wchar_t letter);
wchar_t numberToLetter(int number);
int shift(int number, int shiftValue);
void encrypt(wchar_t* text, int shiftValue);
void decrypt(wchar_t* text, int shiftValue);
#endif
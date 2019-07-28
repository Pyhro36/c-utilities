#ifndef STRINGEXTEND_H_INCLUDED
#define STRINGEXTEND_H_INCLUDED

char* delCharInString(char* str, char argc);
char* delNonAlphaNum(char* str);
char* delDouble(char* str, char c);

int letterCountInString(char *str, char argc);
int wordCount(const char* str);

char* invertString(char* str);
char* getAnagramm(char* anagramm, const char* str);

int isPalindrome(const char* str);

int binToDec(const char* bin);

#endif // STRING_H_INCLUDED

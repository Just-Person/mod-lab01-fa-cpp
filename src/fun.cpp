// Copyright 2022 UNN-IASR
#include <iostream>
#include <math.h>
#include <cctype>
#include "fun.h"

unsigned int faStr1(const char* str) {
int count = 0;
int inWord = 0;
int iterator = 0;
while (*(str + iterator)) {
if (*(str + iterator) != ' '
&& !isdigit(*(str + iterator)) && !finWord(inWord)) {
count++;
inWord = 1;}
else if (*(str + iterator) == ' '
&& finWord(inWord)) inWord = 0;
else if (isdigit(*(str + iterator))
&& inWord == 0) inWord = 2;
else
if (isdigit(*(str + iterator)) && inWord == 1) {
inWord = 2;
count--;}
iterator++;
}
return count;
}
unsigned int faStr2(const char* str) {
int count = 0;
int inWord = 0;
int iterator = 0;
while (*(str + iterator)) {
if (isupper(*(str + iterator)) && inWord == 0) {
count++;
inWord = 1;}
else if (!islowermy(*(str + iterator))
&& !finWord(inWord)) inWord = 2;
else if (*(str + iterator) == ' '
&& finWord(inWord)) inWord = 0;
else
if (!islowermy(*(str + iterator)) && inWord == 1) {
inWord = 2;
count--;}
iterator++;
}
return count;
}
unsigned int faStr3(const char* str) {
int count = 0;
int sum = 0;
bool inWord = false;
int iterator = 0;
while (*(str + iterator)) {
if (*(str + iterator) != ' ' && inWord == false) {
count++;
inWord = true;
} else if (*(str + iterator) == ' ' && inWord == true) {
inWord = false;}
if (inWord == true)
sum++;
iterator++;
}
count = round(double(sum) / double(count));
return count;
}
bool finWord(int inWord) {
if (inWord != 0)
return true;
else
return false;
}
bool islowermy(char a) {
if (int(a) >= 97 && int(a) <= 122)
return true;
else
return false;
}

// Copyright 2022 UNN-IASR
#include <iostream>
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
 inWord = 1;
 }
 else if (*(str + iterator) == ' ' && finWord(inWord))
 inWord = 0;
 else if (isdigit(*(str + iterator)) && inWord == 0)
 inWord = 2;
 else if (isdigit(*(str + iterator)) && inWord == 1) {
 inWord = 2;
 count--;
 }
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
 inWord = 1;
 }
 else if (islower(*(str + iterator)) && !finWord(inWord))
 inWord = 2;
 else if (*(str + iterator) == ' ' && finWord(inWord))
 inWord = 0;
 else if (isupper(*(str + iterator)) && inWord == 1) {
 inWord = 2;
 count--;
 }
 iterator++;
 }
 return count;
}
unsigned int faStr3(const char* str) {
 int count = 0;
 int buffersum = 0;
 int sum = 0;
 bool inWord = false;
 int iterator = 0;
 while (*(str + iterator)) {
 if (*(str + iterator) != ' ' && inWord == false) {
 count++;
 inWord = true;
 }
 else if (*(str + iterator) == ' ' && inWord == true) {
 inWord = false;
 sum += buffersum;
 buffersum = 0;
 }
 if (inWord == true)
 buffersum++;
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

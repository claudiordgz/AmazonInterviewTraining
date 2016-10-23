#include "ch01/ex1_2.hpp"


void Reverse(char *str) {
  if(str){
    char *end = str;
    while(*end) {
      ++end;
    }
    --end;
    char tmp;
    while(str < end) {
      tmp = *str;
      *str++ = *end;
      *end--  = tmp;
    }
  }
}

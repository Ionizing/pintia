/* Written by mht */

#include<time.h>

int main(){
  clock_t begin = clock();
  clock_t end;
  while(1){
    end = clock();
    if ((end - begin) > 380000 )
      break;
  }
  return 0;
}
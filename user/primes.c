#include "user/user.h"

int main(int argc, char *argv[]){
  int p[2];
  pipe(p);
  for (int i = 2; i <=35; i++) {
    write(p[1], &i, sizeof(i));
  }


  return 0;
}
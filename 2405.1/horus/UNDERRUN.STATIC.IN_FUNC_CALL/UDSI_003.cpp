#include <string.h>

/* UDSI_003 - simple memmove */
int UDSI_003_function1(int offset) {
  if(offset > 0)  {
    return ++offset;
  }
  
  return -1;
}
void UDSI_003_function2(int flag, int offset) {
  char str[] = "0123456789"; //sizeof(src) == 11
  if(flag == 1) {
    memmove(str + 5, str + 2, 5); //It's ok.
  }
  else {
    if(offset < 3) {
      memmove(str + 3, str + UDSI_003_function1(offset), 3); //@violation UNDERRUN.STATIC.IN_FUNC_CALL
    }
  }
}
#include <string.h>

/* UDDI_003 - simple memmove */
int UDDI_003_function1(int offset) {
  if(offset > 0)  {
    return ++offset;
  }
  
  return -1;
}
void UDDI_003_function2(int flag, int offset) {
  char str[] = "0123456789"; //sizeof(src) == 11
  char* dst = new char[11];
  if(dst == 0) {
    return;
  }
  memcpy(dst, str, sizeof(str));

  if(flag == 1) {
    memmove(dst + 5, dst + 2, 5); //It's ok.
  }
  else {
    if(offset < 3) {
      memmove(dst + UDDI_003_function1(offset), dst + 2, 3); //@violation UNDERRUN.DYNAMIC.IN_FUNC_CALL
    }
  }

  delete[] dst;
}

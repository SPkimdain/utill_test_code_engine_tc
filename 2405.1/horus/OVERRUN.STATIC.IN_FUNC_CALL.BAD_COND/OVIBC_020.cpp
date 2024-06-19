#include <string.h>

/* OVIBC_020 - multiple strncat */
void OVIBC_020_function(int flag, int offset) {
  float value = 10.5F;
  char src[] = "abcde"; //sizeof(src) == 6, len = 5
  char src2[] = "fghi"; //sizeof(src2) == 5, len = 4
  char dst[20] = { 0, };
  char* ret = 0;
  strcpy(dst, src2); //It's ok. len = 4 + 1

  strncat(dst, src2, 3); //It's ok. len = 4 + 3 + 1
  strncat(dst, src, 4); //It's ok. len = 4 + 3 + 4 + 1
  strncat(dst, src, 5); //It's ok. len = 4 + 3 + 4 + 5 + 1

  if(offset < 6) {
    //len = 4 + 3 + 4 + 5 + 5 + 1 = 22
    strncat(dst, src, offset); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}


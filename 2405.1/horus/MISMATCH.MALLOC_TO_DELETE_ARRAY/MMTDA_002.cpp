#include <stdlib.h>

/* MMTDA_002 - assign */
void MMTDA_002_function(char* src, int flag){
  char* p = (char*)malloc(10);
  
  char* ptr = 0;
  if(flag > 0) {
    ptr = src;
    free(p);
  }
  else {
    ptr = p; //This flow.
  }

  delete[] ptr;  //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}

#include <stdlib.h>

/* MMTDA_008 - field */
class MMTDA_008_Class {
public:
  MMTDA_008_Class() : value(0) {}

  void setValue(int* v) {
    value = v;
  }

  void release() {
    if(value != 0) {
      delete[] value;
      value = 0;
    }
  }

private:
  int* value;
};

void MMTDA_008_function(){
  int* data = new int[10];
  int* data2 = (int*)malloc(sizeof(int) * 5);
  
  MMTDA_008_Class obj;

  obj.setValue(data);
  obj.release(); //It's ok.

  obj.setValue(data2);
  obj.release(); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}



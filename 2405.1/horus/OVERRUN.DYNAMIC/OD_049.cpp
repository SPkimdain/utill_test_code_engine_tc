
/* OD_049 - trygraphs */
void OD_049_function(int flag) {
  int* p = new int[10];
  if(p == 0) {
    return;
  }
  int value = 10;
  int index = (flag == 10) ? 5 : 10;
  
  p[index] = 100; //@violation OVERRUN.DYNAMIC

  delete[] p;
}

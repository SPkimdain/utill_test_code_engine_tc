
/* TOS_016 - Shift operator value */
struct TOS_016_Struct {
  int i;
  char c;
  long l;
  int p[5];
};

void TOS_016_function() {
  int value = 1;
  TOS_016_Struct sb;
  int* ptr = sb.p;
  int ret = 0;

  value = value << 2; // 4
  value = value >> 1; // 2

  ptr = sb.p + 6;
  
  //Impossible path.
  ret = *ptr; //@violation TYPE_OVERRUN.STATIC
}


/* TOS_019 - short circuit2 */
struct TOS_019_Struct {
  int i;
  char c;
  long l;
  int p[5];
};


void TOS_019_function() {
  TOS_019_Struct sb;
  sb.p[0] = 0;
  int* ptr = sb.p;
  int x = 10;
  int compareValue = 20;
  int ret = 0;

  ret = *ptr; //It's ok.

  ptr = sb.p;

  if(compareValue > *(ptr + 10)) { // @violation TYPE_OVERRUN.STATIC
    x++;
  }
}

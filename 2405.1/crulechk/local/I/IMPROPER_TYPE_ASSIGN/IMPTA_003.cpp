//@checker IMPROPER_TYPE_ASSIGN

void IMPTA_003_function() {  
  unsigned int u32a = 0;
  unsigned int u32b = 3000; //It's ok.
  
  short s16a = 10; //It's ok.
  int s32a = 10; //It's ok.
  unsigned int u32d = 1; //It's ok.
  unsigned short u16a = 5; //It's ok.

  u32a = u16a; //It's ok.
  u16a = u32a; //@violation IMPROPER_TYPE_ASSIGN
}

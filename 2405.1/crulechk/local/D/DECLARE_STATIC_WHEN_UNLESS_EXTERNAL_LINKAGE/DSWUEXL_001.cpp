//@checker DECLARE_STATIC_WHEN_UNLESS_EXTERNAL_LINKAGE
extern int wrong_DSWUEXL_001; //@violation DECLARE_STATIC_WHEN_UNLESS_EXTERNAL_LINKAGE

void DSWUEXL_001_function() {
  wrong_DSWUEXL_001 = 1;
}

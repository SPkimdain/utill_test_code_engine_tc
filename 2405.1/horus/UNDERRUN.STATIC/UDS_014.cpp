

/* UDS_014 - call by reference */
void UDS_014_function1(int* ptr, int* ptr2) {
  int* pValue = 0;
  int* pValue2 = 0;

  int ret = 0;

  pValue = ptr;
  pValue2 = ptr2;
  ret += pValue[1]; //No Problem  
  ret += pValue2[-4];
}

void UDS_014_function2() {
  int pData[3] = { 1, 2, 3 };
  int pData2[3] = { 4, 5, 6 };

  UDS_014_function1((int*)pData, (int*)pData2);	//@violation UNDERRUN.STATIC
}
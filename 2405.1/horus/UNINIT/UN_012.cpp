
//TODO: for���� 1���� �ݺ��ϱ� ������ value�� ���� 1�� �ǴܵǾ� ���� ����.

/* UN_012 - for */
void UN_012_function() {
  int value = 0;
  int arg;
  for(int i = 0; i < 10; i++) {
    value++;
  }

  value += arg; //@violation UNINIT
  
}


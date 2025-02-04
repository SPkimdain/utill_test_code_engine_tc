#include <stdio.h>

/* LR_015 - fopen example  */
#include<string.h>

#define SIZE 1
#define NUMELEM 5

int LR_015_function(void) {
  FILE* fd = 0;
  char buff[100];
  memset(buff, 0, sizeof(buff));

  fd = fopen("test.txt", "rw+");

  if(0 == fd)
  {
    printf("\n fopen() Error!!!\n");
    return 1;
  }

  printf("\n File opened successfully through fopen()\n");

  if(SIZE*NUMELEM != fread(buff, SIZE, NUMELEM, fd))
  {
    printf("\n fread() failed\n");
    fclose(fd);
    return 1;
  }

  printf("\n Some bytes successfully read through fread()\n");

  printf("\n The bytes read are [%s]\n", buff);

  if(0 != fseek(fd, 11, SEEK_CUR))
  {
    printf("\n fseek() failed\n");
    fclose(fd);
    return 1;
  }

  printf("\n fseek() successful\n");

  if(SIZE*NUMELEM != fwrite(buff, SIZE, strlen(buff), fd))
  {
    printf("\n fwrite() failed\n");
    return 1;
  } //@violation LEAK.RESOURCE

  printf("\n fwrite() successful, data written to text file\n");

  fclose(fd); 

  printf("\n File stream closed through fclose()\n");

  return 0; 
}


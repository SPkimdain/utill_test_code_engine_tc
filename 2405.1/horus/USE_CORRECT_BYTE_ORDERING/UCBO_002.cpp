
/* UCBO_002 - simple case2 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <string.h>

#ifdef _WIN32

#include <winsock.h>

#else 

#include <sys/socket.h>
#include <arpa/inet.h>
#include <byteswap.h>
#include <unistd.h>

#endif /* _WIN32 */

/* ���߿� �ɰ��°ɷ� �ϰ� �ϴ� ���⼭ �۾�. */

unsigned int UCBO_002_function(int sock, int server) {
  unsigned int num = 0;
  int error = 0;
  if(server) {
    num = 0x17;
    if(send(sock, (const char*)(void *)&num, sizeof(num), 0) < (unsigned)sizeof(num)) { //@violation USE_CORRECT_BYTE_ORDERING
      error = 1;
    }
    return 0;
  }
  return 0;
}

unsigned int UCBO_002_function2(int sock, int server) {
  unsigned int num = 0;
  int error = 0;
  if(server) {
    num = 0x17;

    num = htonl(num);
    if(send(sock, (const char*)(void *)&num, sizeof(num), 0) < (unsigned)sizeof(num)) { //It's ok.
      error = 0;
    }
    return 0;
  }

  return 0;
}


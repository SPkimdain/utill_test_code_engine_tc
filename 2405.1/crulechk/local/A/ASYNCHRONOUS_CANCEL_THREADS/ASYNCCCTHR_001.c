//@checker ASYNCHRONOUS_CANCEL_THREADS
#define NULL 0
#include "ASYNCCCTHR_001.h"

volatile int a = 5;
volatile int b = 10;
 
/* Lock to enable threads to access a and b safely */
pthread_mutex_t global_lock = PTHREAD_MUTEX_INITIALIZER;
 
void* ASYNCCCTHR_001_thread(void* dummy) {
  int i;
  int c;
  int result;
 
  if ((result = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,&i)) != 0) {	//@violation ASYNCHRONOUS_CANCEL_THREADS
    /* handle error */
  }
 
  while (1) {
    if ((result = pthread_mutex_lock(&global_lock)) != 0) {
      /* handle error */
    }
    c = b;
    b = a;
    a = c;
    if ((result = pthread_mutex_unlock(&global_lock)) != 0) {
      /* handle error */
    }
  }
  return NULL;
}
 
 
int ASYNCCCTHR_001_function(void) {
  int result;
  pthread_t worker;
 
  if ((result = pthread_create( &worker, NULL, ASYNCCCTHR_001_thread, NULL)) != 0) {
    /* handle error */
  }
 
  /* .. Do stuff...meanwhile worker thread runs for some time */
 
  /* since we don't know when the character is read in, the program could continue at any time */
  if ((result = pthread_cancel(worker)) != 0) {
    /* handle error */
  }
  /* pthread_join waits for the thread to finish up before continuing */
  if ((result = pthread_join(worker, 0)) != 0) {
    /* handle error */
  }
 
  if ((result = pthread_mutex_lock(&global_lock)) != 0) {
    /* handle error */
  }
  //printf("a: %i | b: %i", a, b);
  if ((result = pthread_mutex_unlock(&global_lock)) != 0) {
    /* handle error */
  }
 
  return 0;
}

//@checker FORMAT_STRING_ARGUMENT_NUMBER_MISMATCH
typedef struct _iobuf
{
 char* _ptr;  
 int _cnt;    
 char* _base; 
 int _flag; 
 int _file; 
 int _charbuf; 
 int _bufsiz;  
 char* _tmpfname; 
} FILE;

extern int fprintf ( FILE * stream, const char * format, ... );
extern int printf ( const char * format, ... );
extern int sprintf ( char * str, const char * format, ... );
extern int fscanf ( FILE * stream, const char * format, ... );

int getint()
{
	return 0;
}

char* getstring()
{
	return (char*)0;
}

void f(const char *str, int str_len)
{
  printf("%.*s\n", str_len, str);
  printf("%.*s\n", str_len ); //@violation FORMAT_STRING_ARGUMENT_NUMBER_MISMATCH
}

struct file_info
{
	int st_size	;
};

 
void get_data(const char *msg ) {	
	
	
  struct file_info fi;

  FILE* stdin;
	
  char buf[2048];	
  char filename[128];
  
  fprintf("test","%d|%d|%s|%s",msg,fi.st_size,fi.st_size,"filetest"); 
  fprintf("test","%d|%d|%s",msg,fi.st_size,fi.st_size,"filetest"); //@violation FORMAT_STRING_ARGUMENT_NUMBER_MISMATCH
  fprintf("test","%d|%d|%s|%s",msg,fi.st_size,fi.st_size); //@violation FORMAT_STRING_ARGUMENT_NUMBER_MISMATCH
  sprintf(filename, "%123s.txt", msg,123); //@violation FORMAT_STRING_ARGUMENT_NUMBER_MISMATCH
  
  sprintf(filename, "%s.txt", msg);	
  
  fscanf(stdin, "%2000s %d", buf, 123);	
  fscanf(stdin, "%s %d", msg, 123);	
  fscanf(stdin, "%123s", buf);
  fscanf(stdin, "%s", buf);	
  
}

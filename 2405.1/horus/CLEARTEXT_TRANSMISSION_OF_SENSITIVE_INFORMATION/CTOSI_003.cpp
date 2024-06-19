
/* CTOSI_003 - different path check1 */

typedef enum {
  EX_RT_OK = 0,
  EX_RT_NOT_OK = 1,
} Ex_ReturnType;

struct EscAesContext {};

extern unsigned char publishCANTPData(unsigned char* payload);
extern Ex_ReturnType EscAesCbc_Init(EscAesContext* ctx,
  unsigned char* key, unsigned char* iv);
extern Ex_ReturnType EscAesCbc_Encrypt(EscAesContext* ctx,
  unsigned char* priv, unsigned char* cipher, int byte);


void CTOSI_003_function1(unsigned char* privKey,
  unsigned char* key, unsigned char* iv, unsigned char* cipherBuf, int size) {
  EscAesContext ctx;
  Ex_ReturnType result = EscAesCbc_Init(&ctx, key, iv);
  if(result == EX_RT_OK) {
    //encrypt function.
    result = EscAesCbc_Encrypt(&ctx, privKey, cipherBuf, size);
    if(result == EX_RT_OK) {
      publishCANTPData(cipherBuf); //It's ok.
    }
  }
  else { 
    cipherBuf = privKey;
    publishCANTPData(cipherBuf); //@violation CLEARTEXT_TRANSMISSION_OF_SENSITIVE_INFORMATION
  }
}
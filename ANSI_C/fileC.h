#ifdef _FILE_B
#define FILE_C_EXTERN
#else
#define FILE_C_EXTERN extern
#endif

FILE_C_EXTERN int x;
void functionName (void);
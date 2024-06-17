/*x exist everywhere in this program, when it is defined as int x; including fileA.c*/
#define _FILE_B
#include "fileC.h"

static int y;

void functionName (void);

void functionName(void){
    unsigned char i;

    for (i=0; i<10; i++){
        int j = 23;
        

        x += j+i;
    }

}
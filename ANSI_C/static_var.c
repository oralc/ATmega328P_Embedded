#include <stdio.h>;

static j = 0;

// prototypes
void up(void);
void down(void);


int main(void){
    int i;
    
    // call the "up" func 3 times then "down" 2 times

    for(i = 0; i < 3 ; i++){
        up();
    }
    for(i = 0 ; i < 2 ; i++){
        down();
    }
    return 0;
};

void up(void){
    static int k = 0;
    j++ ;
    k++ ;
    printf("up called k=%2d, j=%2d \n", k, j); 

}

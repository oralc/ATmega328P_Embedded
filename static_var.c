#include <stdio.h>

//declare static variable
// static datatype var = value;
// by default value = 0 ;
static int i = 1 ;

int counter();

int main(){
    counter();
    counter();
    counter();
}

int counter(){

    int x;
    printf("Value of x as in enters the func %d\n ", x);

    x++;
    printf("Incremented values of x: %d\n", x);

}
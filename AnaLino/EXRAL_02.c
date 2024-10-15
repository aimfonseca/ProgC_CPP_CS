#include<stdio.h>

int main ()
{
    static int i = 1;

    if(i--) {

 printf("%d ", i);

 main();
}

    return 0;
}
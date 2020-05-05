#include <stdio.h>
#include <stdlib.h>

void f (int *a)
{
    *a = *a+1;
}

int main()
{

    printf("Hello world!\n");
    float a;
    unsigned b;
    scanf("%f %d", &a, &b);
    printf("\nA is: %f\nB is: %d", a,b);
    f(&b);
    printf("\nA is: %.2f\nB is: %d", a, b);

    return 0;
}

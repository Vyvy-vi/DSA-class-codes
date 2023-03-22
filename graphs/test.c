#include "stdio.h"

void val1()
{
    printf("%d\n", 1);
}

int val2()
{
    printf("%d\n", 2);
}

int main(void)
{
    val1();
    val2();
    printf("%d\n", 3);
}
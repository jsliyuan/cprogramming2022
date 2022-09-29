#include <stdio.h>

int main() 
{
    int my_num = 7;
    {
        int my_num;
        my_num = 10;
        printf("my_num is %d\n", my_num);
    }

    printf("my_num is %d\n", my_num);
    
    return 0;
}

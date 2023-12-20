#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 演示 do-while 循环：计算用户输入的十个浮点数的总和 */
int main()
{
    float this_is_a_number, total;
    int i;

    total = 0;
    i = 0;

    /* do-while 循环执行，直到 i 的值达到 10 */
    do
    {
        printf("请输入一个数字：\n");
        scanf("%f", &this_is_a_number); /* 读取输入的数字 */
        total = total + this_is_a_number;
        i++;
    } while (i < 10);

    printf("总和为：%f\n", total);

    return 0;
}

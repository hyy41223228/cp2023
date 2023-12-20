##define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 演示 for 循环：计算用户输入的十个浮点数的总和 */
int main()
{
    float this_is_a_number, total;
    int i;

    total = 0;

    /* for 循环执行 10 次 */
    for (i = 0; i < 10; i++)
    {
        printf("请输入一个数字：\n");
        scanf("%f", &this_is_a_number); /* 读取输入的数字 */
        total = total + this_is_a_number;
    }

    printf("总和为：%f\n", total);

    return 0;
}

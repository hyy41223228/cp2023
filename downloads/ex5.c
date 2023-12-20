#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 除法：计算两个浮点数的商 */
int main()
{
    float this_is_a_number1, this_is_a_number2, total;

    printf("请输入一个数字：\n");
    scanf("%f", &this_is_a_number1); /* 读取输入的数字 */
    printf("你输入了 %f\n", this_is_a_number1);

    printf("请输入另一个数字：\n");
    scanf("%f", &this_is_a_number2); /* 读取输入的数字 */
    printf("你输入了 %f\n", this_is_a_number2);

    total = this_is_a_number1 / this_is_a_number2; /* 计算两个数字的商 */
    printf("商为 %f\n", total);

    return 0;
}
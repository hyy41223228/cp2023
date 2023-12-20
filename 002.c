#include <stdio.h>

int main(int argc, char** argv) {
    // 检查C标准版本
    #if __STDC_VERSION__ >=  201710L
        printf("我们正在使用 C18 标准!\n");
    #elif __STDC_VERSION__ >= 201112L
        printf("我们正在使用 C11 标准!\n");
    #elif __STDC_VERSION__ >= 199901L
        printf("我们正在使用 C99 标准!\n");
    #else
        printf("我们正在使用 C89/C90 标准!\n");
    #endif

    // 表示程序成功执行
    return 0;
}

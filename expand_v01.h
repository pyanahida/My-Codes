// H author: 爱玩各种游戏的初中生
// Uploaded on https://github.com/pyanahida/My-Codes/blob/C/expand_v01.h

#ifndef EXPAND_V01
#define EXPAND_V01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printbr(const char *str);
void ms_sleep(int x);
int randint(int a, int b);
int intinput(const char *prompt);

// 换行输出
void printbr(const char *str) {
    printf("%s", str);
    printf("\n");
}

// 毫秒级延时
void ms_sleep(int x) {
    usleep(x * 1000);
}

// 生成随机整数
int randint(int a, int b) {
    return a + rand() % (b - a + 1);
}

// 获取整数输入
int intinput(const char *prompt) {
    char buffer[100];  // 存储用户输入的缓冲区
    int number;
    char *endptr;
    
    while (1) {
        // 显示提示信息
        printf("%s", prompt);
        
        // 获取用户输入
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("读取输入失败，请重试。\n");
            continue;
        }
        
        // 去除末尾的换行符
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // 检查是否为空输入
        if (buffer[0] == '\0') {
            printf("输入不能为空，请重新输入。\n");
            continue;
        }
        
        // 尝试将字符串转换为整数
        number = strtol(buffer, &endptr, 10);
        
        // 检查转换是否成功（endptr 应该指向字符串末尾，且没有剩余非法字符）
        if (*endptr != '\0') {
            printf("输入无效，请输入一个有效的整数。\n");
            continue;
        }
        
        // 输入有效，跳出循环
        break;
    }
    
    return number;
}

#endif
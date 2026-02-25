#include "expand_v01.h"
#include <time.h>
#include <stdio.h>

// DeepSeek provides .py code, 爱玩各种游戏的初中生 converts .py to the current .c

char *hr = "==============================";

int main() {
    srand((unsigned int)time(NULL));
    
    printf("%s\n", hr);
    printbr("数学迷宫探索者");
    printf("%s\n", hr);
    ms_sleep(1000);
    
    int score = 0;
    int round_num = 1;
    
    while (round_num <= 5) {
        printf("\n--- 第 %d 层 ---\n", round_num);
        
        int target = randint(1, 20);
        int attempts = 3;
        int guessed = 0;
        
        while (attempts > 0) {
            printf("猜测数字 (1-20)，剩余%d次机会\n", attempts);
            int guess = intinput("");
            
            if ((guess < 1) || (guess > 20)) {
                printbr("请输入1-20之间的数字！");
                continue;
            }
            
            if (guess == target) {
                int points = attempts * 10;
                score += points;
                printf("✓ 正确！获得%d分\n", points);
                ms_sleep(800); // 猜中时停顿庆祝
                guessed = 1;
                break;
            } else { if (guess < target) {
                printbr("↑ 猜小了");
            } else {
                printbr("↓ 猜大了");
            }}
            
            attempts--;
        }
        
        /* It was wrong
        if (attempts == 0) {
            printf("× 答案就是 %d\n", target);
            ms_sleep(800); // 失败时停顿反思
        }
        */
        if (!guessed) {
            printf("× 答案就是 %d\n", target);
            ms_sleep(800);
        }
        
        round_num++;
    }
    
    printf("\n%s\n", hr);
    printbr("游戏结束");
    printf("%s\n", hr);
    printf("最终得分: %d\n", score);
    ms_sleep(500);
    
    printf("评价: ");
    if (score >= 120) {
        printbr("迷宫大师");
    } else { if (score >= 80) {
        printbr("熟练探索者");
    } else {
        printbr("初学者");
    }}
    
    printf("%s\n", hr);
    ms_sleep(1000); // 看完评价再退出
    return 0;
}
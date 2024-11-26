#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void getNext(const char* pattern, int* next) {
    next[0] = -1;
    int len = strlen(pattern);
    int j = 0;
    int k = -1;
    while (j < len - 1) {// 最后一个j不用取，因此是判断j-1的位置和k的位置
        if (k == -1 || pattern[k] == pattern[j]) {
            next[++j] = k++;
        } else {
            k = next[k]; // 回溯k指针
        }
    }
}

void getNextval(const char* pattern, int* nextval) {
    nextval[0] = -1;
    int len = strlen(pattern);
    int j = 0;
    int k = -1;
    while (j < len - 1) {// 最后一个j不用取，因此是判断j-1的位置和k的位置
        if (k == -1 || pattern[k] == pattern[j]) {
            j++, k++;
            if (pattern[k] != pattern[j]) {
                nextval[j] = k; 
            } else {
                nextval[j] = nextval[k]; // 如果一样，j失配，直接去找k的上一个，都没有必要对比k找个位置
            }
        } else {
            k = nextval[k]; // 回溯k指针
        }
    }
}

int KMP(const char* text, const char* pattern, int* next) {
    getNext(pattern, next);
    int tlen = strlen(text);
    int plen = strlen(pattern);
    int i = 0, j = 0;

    while (i < tlen && j < plen) {
        if (j == -1 || text[i] == pattern[j]) { // j == -1 表示此时模式串和子串都需要从下一个位置开始匹配
            i++, j++;
        } else {
            j = next[j];
        }
    }
    return j == plen ? i - j : -1; // 最后j会在模式串末尾的后一位
}

int main() {
    char text[MAX_SIZE];
    char pattern[MAX_SIZE];
    int next[MAX_SIZE];

    printf("Input text string: ");
    scanf("%s", text);

    printf("Input pattern string: ");
    scanf("%s", pattern);
    
    int index = KMP(text, pattern, next);
    printf("Matching index: %d", index);
    return 0;
}
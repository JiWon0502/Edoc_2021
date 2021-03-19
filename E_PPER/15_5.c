#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//ASCII CODE 사용 시 훨씬 간편하다 'A' = 65, 'Z' = 90

char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(10000);
    //코드를 작성해주세요
    int indx = 0;
    int tmp = 1;
    int i = 0;
    if(s[0] == 1) answer[indx++] = '1';
    while(s[i]){
        if(s[i] == s[1+i]){
            tmp++;
        }
        else {
            if(tmp>=27) answer[indx++] = 90;
            else answer[indx++] = tmp+64;
            tmp = 1;
        }
        i++;
    }
    return answer;
}

int main() {
    char s[10000] = "";
    char *answer;

    scanf("%s", s);
    answer = solution(s);
    printf("%s\n", answer);
}


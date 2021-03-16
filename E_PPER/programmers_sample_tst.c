#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// v_row_len은 2차원 배열 v의 행(세로) 길이입니다.
// v_col_len은 2차원 배열 v의 열(가로) 길이입니다.
// v[i][j]는 v의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int **v, size_t v_row_len, size_t v_col_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*2);
    if(v[0][0] == v[2][0])
        answer[0] = v[1][0];
    else if(v[0][0] == v[1][0])
        answer[0] = v[2][0];
    else answer[0] = v[0][0];
    
    if(v[1][1] == v[2][1])
        answer[1] = v[0][1];
    else if(v[1][1] == v[0][1])
        answer[1] = v[2][1];
    else answer[1] = v[1][1];
    
    return answer;
}
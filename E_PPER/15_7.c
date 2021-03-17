#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
int solution(int s[], int e[], int N){
    int answer = 0;
    int n[1000];
    int e_n[1000];
    int i, j, tmp = 0, e1 = -1, e2 = -1;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(e[j] < e[tmp]) tmp = j;
						else if(e[j] == e[tmp] && s[j]<s[tmp]) tmp = j;
        }
        e_n[tmp] = e[tmp];
        e[tmp] = 86400;
        n[i] = tmp;
    }

	
    for(i = 0; i < N; i++){
        if(s[n[i]] >= e1){
          answer++;
          e1 = e_n[n[i]];
        }
        else if(s[n[i]] >= e2){
          answer++;
					e2 = e1;
          e1 = e_n[n[i]];
        }
    }
    return answer;
}


int main() {
    int s[1000];
    int e[1000];
    int N = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &s[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &e[i]);
	
    printf("%d", solution(s, e, N));
    return 0;
}


// 실제 시험에서는 Solution 클래스의 solution 함수를 사용합니다. 이를 감안하여 풀이해주세요.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct V{
    int num;
    char arr[22];
};
struct V voca[100001] = {0,};

int compare_num(const void* a, const void* b){
    struct V *pa = (struct V *)a;
    struct V *pb = (struct V *)b;
    if(pa->num > pb->num)
        return 1;
    else if (pa->num < pb->num)
        return -1;
    else return 0;
}

int compare_voca(const void* a, const void* b){
    struct V *pa = (struct V *)a;
    struct V *pb = (struct V *)b;
    return strcmp(pa->arr, pb->arr);
}

int check(char s){
    int i = 0;
    while(1){
        if(voca[i].arr[0] == s) return i;
        else i++;
    }
}

int main() {
    int K, N;
    char s;
    
    scanf("%d %d", &K, &N);
    
    for(int i = 0; i<K; i++) {
        scanf("%s\n", voca[i].arr);
        voca[i].num = 0;
    }
    
    for(int i = 0; i<N; i++){
        qsort(voca, K, sizeof(voca[0]), compare_voca);
        qsort(voca, K, sizeof(voca[0]), compare_num);
        s = getchar();
        printf("%s\n", voca[check(s)].arr);
        voca[check(s)].num++;
        s = getchar();
    }
    
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int comp(const void * a, const void * b){
    if(*((int*)a) > *((int*)b) ) return 1;
    else if(*((int*)a) < *((int*)b) ) return -1;
    else return 0;
}

int main(){
    int N, min=200000, arr[200000] = {0};
    scanf("%d", &N);
    for(int i = 0; i < 2*N; i++) scanf("%d", &arr[i]);
    qsort(arr, 2*N, sizeof(*arr), comp);
    //for(int i = 0; i < 2*N; i++) printf("%d", arr[i]);
        
    for(int j = 0; j < N; j++){
        if(arr[j]+arr[2*N-1-j] < min) min = arr[j] + arr[2*N-1-j];
    }
    printf("%d", min);
    return 0;
}

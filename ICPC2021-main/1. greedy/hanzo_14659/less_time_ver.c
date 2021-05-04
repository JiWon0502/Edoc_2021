#include<stdio.h>

int main(){
    int N, arr[30000]={0,}, i, j, temp, max = 0;
    scanf("%d", &N);
    for(j = 0; j<N; j++) scanf("%d", &arr[j]);
    for(i = 0; i<N;){
        temp = 0;
        for(j = 1; arr[i]>arr[i+j] && j<N-i; j++){
            temp++;
        }
        if(max<temp) max = temp;
        if(j==1) i++;
        else i+= j-1;
    }
    printf("%d", max);
}


#include<stdio.h>
long long arr[2][100000] = {0,};
typedef int type_arr;
int arr[1001];

void q_sort(int low, int high){
    if(low >= high) return;
    type_arr pivot = arr[low];
    int left = low +1;
    int right = high;
    int temp;
    while(left<=high){
        if(arr[left]<= pivot){
            left++;
            continue;
        }
        if(arr[right]>= pivot){
            right--;
            continue;
        }
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    temp = arr[right];
    arr[right] = pivot;
    arr[low] = temp;
    q_sort(low, right-1);
    q_sort(right+1, high);
    return;
}

/*int closed_time(long long strt, int N){
    long  min = 2147483647;
    //input start time && return closed time
    //if none can be started return -1;
    for(int i = 0; i<N; i++){
        if(arr[0][i] > strt && min > arr[1][i]) min = arr[1][i];
    }
    return min;
}*/

int main(){
    int N, num;
    long long tmp;
    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        scanf("%lld %lld", &arr[0][i], &arr[1][i]);
    tmp = closed_time(0, N);
    while(1){
        if(tmp == 2147483647) break;
        else {
            num++;
            tmp = closed_time(tmp, N);
        }
    }
    printf("%d", num);   
}

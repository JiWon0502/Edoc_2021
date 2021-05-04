#include <stdio.h>
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

int main(){
    int N;
    scanf("%d", &N);
    for(int i =0; i<N; i++) scanf("%d", &arr[i]);
    q_sort(0, N);
    for(int j = 0; j<N; j++) printf(" %d", arr[j]);
    return 0;
}

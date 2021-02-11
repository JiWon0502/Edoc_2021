#include<stdio.h>

int in[100000]={0,}, pst[100000]={0,}, pre[100000]={0,}; // 0에서 시작
int pre_index = 0;

void find_root(int in_l, int in_r, int pst_l, int pst_r){
    int root_index = 0;
    if(pst_l<=pst_r){
        while(pst[pst_r] != in[root_index]) {
            root_index++; //find root index
        }
        pre[pre_index++] =  in[root_index];
        if(root_index!=0){
            find_root(in_l, root_index-1, pst_l, pst_l+root_index-in_l-1);
            find_root(root_index + 1, in_r, pst_r - in_r + root_index, pst_r-1);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++) scanf("%d", &in[i]);
    for(int i = 0 ; i < n; i++) scanf("%d", &pst[i]);

    find_root(0,n-1,0,n-1);
    
    for(int i = 0; i<n; i++) printf("%d ", pre[i]);
    return 0;
}

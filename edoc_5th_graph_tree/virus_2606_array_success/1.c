#include<stdio.h>
int vertex[101][101] = {0,}; // [1][2] == 1 :  1 -> 2
int visited[101] = {0, };

void dfs_vir(int i, int ver_num){
    visited[i]=1;
    for(int j = 1; j<=ver_num; j++){
        if(vertex[i][j] == 1 && visited[j] != 1){
            dfs_vir(j, ver_num);
        }
    }
    return;
}

int main(){
    int ver_num, edge_num, vir_num = 0; //vertex num, edge num, virus num
    scanf("%d", &ver_num);
    scanf("%d", &edge_num);
    for(int i = 0; i < edge_num; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        // Add edge from s to d
        vertex[a][b] = 1;
        // Add edge from d to s
        vertex[b][a] = 1;
    }
    dfs_vir(1, ver_num);
    for(int i = 2; i<=ver_num; i++){
        if(visited[i] == 1)
            vir_num++;
    }
    printf("%d", vir_num);
    return 0;
}

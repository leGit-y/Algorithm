#include <iostream>
using namespace std;

int order;

int main(){
    int N,M,R;
    order=1;
    scanf("%d %d %d",&N,&M,&R);

    //메모리 할당
    int **G = new int* [N+1];
    for(int i=1;i<=N;i++){
        G[i]= new int[N+1]{};  // 0으로 초기화
    }

    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        G[u][v]=1;
    }

    DFS(G,N,1);
    
    for(int i=1;i<=N;i++){
        printf("%d\n",G[i][i]);
    }


    //메모리 해제
    for(int i=1;i<=M;i++){
        delete[] G[i];
    }
    delete[] G;

}

void DFS(int **G, int e,int r){
    G[r][r]=order++;
    for(int i=1;i<=e;i++){
        if(G[r][i]){
            if(!G[i][i]){
                DFS(G,e,i);
            }
        }
    }
}
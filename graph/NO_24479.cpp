#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//2차원 배열 사용시--> 512mb 메모리 사용량 초과
// int order;
// void DFS(int **G, int e,int r);

// int main(){
//     int N,M,R;
//     order=1;
//     scanf("%d %d %d",&N,&M,&R);

//     //메모리 할당
//     int **G = new int* [N+1];
//     for(int i=1;i<=N;i++){
//         G[i]= new int[N+1]{};  // 0으로 초기화
//     }

//     for(int i=0;i<M;i++){
//         int u,v;
//         scanf("%d %d",&u,&v);
//         G[u][v]=1;
//         G[v][u]=1;
//     }

//     DFS(G,N,R);
    
//     for(int i=1;i<=N;i++){
//         printf("%d\n",G[i][i]);
//     }


//     //메모리 해제
//     for(int i=1;i<=M;i++){
//         delete[] G[i];
//     }
//     delete[] G;

// }

// void DFS(int **G, int e,int r){
//     G[r][r]=order++;
//     for(int i=e;i>=1;i--){
//         if(G[r][i]){ //인접한 정점이고
//             if(!G[i][i]){  //해당 정점을 방문하지 않았다면
//                 DFS(G,e,i);
//             }
//         }
//     }
// }



//리스트 사용
int order=1;
vector<int> visited; 
vector <vector<int>> G;  //전역변수로 둬야 메모리 초과가 안남... 왜지?

void DFS(  int r);

int main(){
    int N,M,R;
    //vector <vector<int>> G;
   
    scanf("%d %d %d",&N,&M,&R);
    G.resize(N+1);
    visited.resize(N+1,0);

    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1;i<=N;i++){               //<---정렬을 여기서 돌리는게 더 총 시간 적게 걸림..이것도 왜지?
        sort(G[i].begin(),G[i].end());  //오름차순 정렬
    }

    DFS(R);

    for(int i=1;i<=N;i++){
        printf("%d\n",visited[i]);
    }

}

void DFS(  int r){
    visited[r]=order++;
    
    //sort(G[r].begin(),G[r].end());  //<---정렬을 여기서 돌리는 것보다

    for(int i=0;i<G[r].size();i++){
   
        int node = G[r][i];
        if(!visited[node]){  //해당 정점을 방문하지 않았다면
            DFS(node);
        }
        
    }
}
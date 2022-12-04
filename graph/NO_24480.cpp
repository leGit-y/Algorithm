#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//리스트 사용
int order=1;
vector<int> visited; 
vector <vector<int>> G;  

void DFS(  int r);
bool compare(int i,int j);

int main(){
    int N,M,R;
   
    scanf("%d %d %d",&N,&M,&R);
    G.resize(N+1);
    visited.resize(N+1,0);

    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1;i<=N;i++){              
        sort(G[i].begin(),G[i].end(),compare);  //내림차순 정렬
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

bool compare(int i,int j){

    return j<i;

}
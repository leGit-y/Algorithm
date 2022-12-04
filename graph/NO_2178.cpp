#include<iostream>
using namespace std;

int **visited;
int main(){
    int N,M;
    int **maze;
    scanf("%d %d",&N,&M);

    
    visited = new int*[N+1];
    //maze 입력받기
    maze = new int*[N+1];
    for(int i=1;i<=N;i++){
        maze[i] = new int[M+1];
        visited[i] = new int[M+1]{}; //0으로 초기화
        for(int j=1;j<=M;j++){
            scanf("%d",maze[i][j]);
        }
    }

}

void DFS(int x,int y){
    visited[x][y]=1;
    int right = 
}
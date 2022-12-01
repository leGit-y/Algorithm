#include <iostream>
#define MAX 9   // 의 N,M범위 : 1~8
using namespace std;

int N,M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void dfs(int cnt)
{
    if(cnt == M){
        for(int i = 0; i < M; i++)
            printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    
    for(int i = 1; i <= N; i++)
    { 
        visited[i] = true;
        arr[cnt] = i;
        dfs(cnt+1);
        visited[i] = false;
    }
}

int main() {
    scanf("%d %d",&N,&M);
    dfs(0);
}
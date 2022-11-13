#include <iostream>
#define MAX(a,b) a>b ? a:b
#define maxstairs 301
using namespace std;

int N;
int ar[maxstairs];
int DP[maxstairs];

int main(){
    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        scanf("%d",&ar[i]);
    }

    DP[1]=ar[1];
    DP[2]=DP[1]+ar[2];

    for(int i=3;i<=N;i++){
        DP[i] = MAX(DP[i-2]+ar[i], DP[i-3]+ar[i-1]+ar[i]);

    }

    printf("%d",DP[N]);
}

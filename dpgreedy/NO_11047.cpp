#include <iostream>
using namespace std;



int main(){
    int N,K;
    int *coin;
    scanf("%d %d",&N,&K);
    coin = new int[N];

    for(int i=0;i<N;i++){
        scanf("%d",&(coin[i]));
    }

    int count=0;
    for(int i=N-1;i>=0;i--){
        count += K/coin[i];
        K = K % coin[i];
    }

    printf("%d",count);

}
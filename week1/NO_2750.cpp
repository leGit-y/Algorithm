//수 정렬하기
//삽입정렬 사용함
#include <iostream>
using namespace std;

int main(){
    int N,i,j,key;
    int *ar=NULL;
    scanf("%d",&N); 

    ar = new int[N];

    for(i=0;i<N;i++){
        scanf("%d",&ar[i]);
    }

    for(j=1;j<N;j++){
        key = ar[j];
        i=j-1;
        while(i >= 0 && ar[i] > key ){
            ar[i+1] = ar[i];
            --i;
        }
        ar[i+1] = key;
    }

    for(i=0;i<N;i++){
        printf("%d ",ar[i]);
    }
}

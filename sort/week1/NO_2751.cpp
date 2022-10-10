//수 정렬하기2
//합병정렬 사용함

#include<iostream>
using namespace std;
#define INFINITY 1000001;

void merge(int *ar,int p, int q, int r){

    int n1 = q-p+1;
    int n2 = r-q;
    int *L,*R;
    L = new int[n1+1];
    R = new int[n2+1];

    for(int i = 0; i < n1; i++){
        L[i] = ar[p+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = ar[q+i+1];
    }
    L[n1] = INFINITY;
    R[n2] = INFINITY;

    int i=0;
    int j=0;
    for(int k = p; k <= r ;k++){
        if(L[i] <= R[j]){
            ar[k] = L[i];
            ++i;
        }
        else{
            ar[k] = R[j];
            ++j;
        }
    }

    delete[] L;
    delete[] R;
    
}


void mergeSort(int *ar,int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergeSort(ar,p,q);
        mergeSort(ar,q+1,r);
        merge(ar,p,q,r);
    }
    
}

int main(){
    int N;
    int *ar;

    scanf("%d",&N);
    ar = new int[N];

    for(int i=0; i<N; i++){
        scanf("%d",&ar[i]);
    }

    mergeSort(ar,0,N-1);

    for(int i=0;i<N;i++){
        printf("%d\n",ar[i]);
    }

    delete[] ar;
}
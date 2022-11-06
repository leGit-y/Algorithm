#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N,value;
    int i,j=1;
    int re,cnt=0;
    int flag =0;
    char *answer;
    stack<int> s;

    cin >> N;

    answer = new char[N];

    for(i=0; i < N; i++){
        cin >> value;

        while(j<=value){
            s.push(j);
            answer[cnt++]='+';
            j++;
        }
           
        re = s.top();
        if(re == value){
            s.pop();
            answer[cnt++]='-';
        }
        else{
            flag =1;
        }
        
    }

    if(flag){
        printf("NO\n");
        
    }
    else{
        for(i=0;i<cnt;i++){
            printf("%c\n",answer[i]);
        }
    }

   // delete[] answer;

}
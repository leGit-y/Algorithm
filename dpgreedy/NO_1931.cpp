#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int N,begin,end;

    vector<pair<int,int>> schedule;

    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d %d",&begin,&end);
       
        schedule.push_back(make_pair(end,begin));
    }

    sort(schedule.begin(),schedule.end());

    int time = schedule[0].first;
    int count = 1;

    for(int i=1;i<N;i++){

        if(time <= schedule[i].second){
            ++count;
            time = schedule[0].first;
        }
       
    }
    printf("%d",count);
}
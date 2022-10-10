//수 정렬하기 3
//수의 범위가 작다면 카운팅 정렬을 사용하여 더욱 빠르게 정렬할 수 있습니다.'


//counting sort
#include <iostream>
using namespace std;

int main()
{
    int i, j, N;
    int value;
    int cnt[10000 + 1]={0,};

    scanf("%d", &N);
    
    for (i = 0; i < N; i++)
    {
        scanf("%d", &value);
        ++cnt[value];
    }

    for (i = 1; i < 10001; i++)
    {
        for (j = 0; j < cnt[i]; j++)
        {
            printf("%d\n", i);
        }
    }
}

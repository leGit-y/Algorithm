#include <iostream>
#include <queue>
using namespace std;

//sol 1)  <--이게 4ms 더 빠름
int main()
{

    queue<int> q;
    int N;
    int i;

    cin >> N;

    for (i = 1; i <= N; i++)
    {
        q.push(i);
    }

    for(i=0 ; i<(2*N-2);i++)  //반복하는 횟수의 규칙성을 찾아
    {

        if (i%2!=0)
        {
            q.push(q.front());
        }
        q.pop();

    }

    printf("%d", q.front());
}


//sol 2)

// #include <iostream>
// #include <queue>
// using namespace std;

// int main()
// {

//     queue<int> q;
//     int N;
//     int flag = 0;

//     cin >> N;

//     for (int i = 1; i <= N; i++)
//     {
//         q.push(i);
//     }

//     while(q.size()!=1)
//     {
//         if (flag)
//         {
//             q.push(q.front());
//         }
//         q.pop();
//         flag = !flag;
//     }
    
//     printf("%d", q.front());
// }
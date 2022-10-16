#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int data[100001];
    int size;
} PriorityQueue;

void insert(PriorityQueue *pq, int x);
int deleteMax(PriorityQueue *pq);

int main()
{
    int N, x;
    PriorityQueue pq;
    pq.size = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            printf("%d\n", deleteMax(&pq));
        }
        else
        {
            insert(&pq, x);
        }
    }
}

void insert(PriorityQueue *pq, int x)
{
    int i;

    for (i = ++(pq->size); pq->data[i / 2] < x; i /= 2)
    {
        if (i / 2 == 0)
            break;
        pq->data[i] = pq->data[i / 2];
    }

    pq->data[i] = x;
}
int deleteMax(PriorityQueue *pq)
{
    int i, child;
    int max_element, last_element;

    if (pq->size == 0)
        return 0;

    max_element = pq->data[1];
    last_element = pq->data[pq->size--];

    /* percolating down */
    for (i = 1; i * 2 <= pq->size; i = child)
    {
        child = i * 2;
        if (child < pq->size && pq->data[child + 1] > pq->data[child])
        {
            child++;
        }
        if (last_element < pq->data[child])
        {
            pq->data[i] = pq->data[child];
        }
        else
        {
            break;
        }
    }
    pq->data[i] = last_element;
    return max_element;
}
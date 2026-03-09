#include <stdio.h>
#include <string.h>

int pq[100];
int size = 0;

void insert(int x)
{
    pq[size++] = x;
}

int findMinIndex()
{
    if(size == 0) return -1;

    int min = 0;
    for(int i=1;i<size;i++)
    {
        if(pq[i] < pq[min])
            min = i;
    }
    return min;
}

void deleteElement()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);

    for(int i=minIndex;i<size-1;i++)
        pq[i] = pq[i+1];

    size--;
}

void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        char op[10];
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            int x;
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0)
        {
            deleteElement();
        }
        else if(strcmp(op,"peek")==0)
        {
            peek();
        }
    }

    return 0;
}
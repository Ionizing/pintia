#include <cstdio>
#define MAXSIZE 100000

struct Node
{
    int Data;
    int Next;
};

void Print( Node Arr[], const int Head );
int ListReverse( Node Arr[], int Head, const int N , const int k );
int Count( Node Arr[], const int Head );

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int HeadAddr, N, k;
    scanf("%d%d%d", &HeadAddr, &N, &k);
    struct Node Arr[MAXSIZE];
    for(int i=0; i!=N; ++i){
        int tmpAddr;
        scanf( "%d", &tmpAddr );
        scanf( "%d%d", &Arr[tmpAddr].Data, &Arr[tmpAddr].Next );
    }
    int Head = ListReverse(Arr, HeadAddr, Count(Arr, HeadAddr) , k);
    Print(Arr, Head);
    return 0;
}

void Print( Node Arr[], const int Head )
{
    int curr = Head;
    while( Arr[curr].Next != -1 ){
        printf("%05d %d %05d\n", curr, Arr[curr].Data, Arr[curr].Next);
        curr = Arr[curr].Next;
    }
    printf("%05d %d %d\n", curr, Arr[curr].Data, Arr[curr].Next);
}

int Count( Node Arr[], const int Head )
{
    int count = 0;
    int curr = Head;
    while( curr != -1 ){
        ++count;
        curr = Arr[curr].Next;
    }
    return count;
}

int ListReverse( Node Arr[], int Head, const int N , const int k )
{
    int prevNode = -1;
    int currNode = Head;
    int nextNode = Arr[currNode].Next;
    int lastHead, head = -1;
    for(int i=0; i!=N/k; ++i){
        lastHead = head;
        head = currNode;
        for(int j=0; j!=k; ++j){
            Arr[currNode].Next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = Arr[nextNode].Next;
        }
        if( 0 == i){
            Head = prevNode;
        }else{
            Arr[lastHead].Next = prevNode;
        }
    }
    Arr[head].Next = currNode;
    return Head;
}

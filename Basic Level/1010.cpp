#include<iostream>
//#include<fstream>

using namespace std;

typedef struct LNode* LinkList;
struct LNode{
    int x;
    int n;
    struct LNode* next;
};

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
//    ofstream out( "out.txt" );
//    cout.rdbuf( out.rdbuf() );
    LinkList Head, rear;
    Head = new LNode;
    Head->next = nullptr;
    rear = Head;
    int num = -1;
    while( !cin.eof() ){
        struct LNode* p = new LNode;
        p->next = nullptr;
        cin >> p->x >> p->n;
        rear->next = p;
        rear = p;
        ++num;
    }
    rear = Head->next;
    while( rear ){
        if( rear->n && rear->x ){
            cout << rear->n * rear->x << " " << rear->n - 1;
            break;
        }
        rear = rear->next;
    }
    if( !rear ) {
        cout << "0 0" << endl;
        return 0;
    }
    rear = rear->next;
    while( rear ){
        if( rear->n && rear->x ){
            cout << " " << rear->n * rear->x << " " << rear->n - 1;
        }
        rear = rear->next;
    }
    cout << endl;
    return 0;
}

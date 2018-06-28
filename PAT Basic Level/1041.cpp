#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

struct Person{
    string ID;
    int test;
    int exam;
};

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    Person *P = new Person[n+1];
    for(int i=0; i!=n; ++i){
        Person tmp;
        cin >> tmp.ID >> tmp.test >> tmp.exam;
        P[tmp.test] = tmp;
    }
    cin >> n;
    for(int i=0; i!=n; ++i){
        int tmp;
        cin >> tmp;
        cout << P[tmp].ID << " " << P[tmp].exam << endl;
    }
    return 0;
}

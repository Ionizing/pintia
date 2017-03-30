#include<iostream>
#include<vector>
//#include<fstream>

using namespace std;

struct Keys
{
    int Key;
    bool Occured = false;
};

void fun( Keys KeyNum[], const int n )
{
    for(int i=0; i<n; ++i){
        int tmp = KeyNum[i].Key;
        while( tmp != 1 ){
            if( tmp % 2 == 0 ){
                tmp /= 2;
            }else{
                tmp = ( 3*tmp + 1 )/2;
            }
            for(int j=0; j<n; ++j){
                if ( tmp == KeyNum[j].Key ){
                    if( KeyNum[j].Occured == true ){
                        goto label;
                    }else{
                        KeyNum[j].Occured = true;
                    }
                }
            }
        }
        label: ;
    }
}

void Sort_Print( vector<int> &T )
{
    const int N = T.size();
    for(int i=0; i<N; ++i){
        int Max = T[i];
        int MaxIndex = i;
        for(int j=i; j<N; ++j){
            if ( Max < T[j] ){
                Max = T[j];
                MaxIndex = j;
            }
        }
        int tmp = T[i];
        T[i] = T[MaxIndex];
        T[MaxIndex] = tmp;
    }
    for(int i=0; i<N-1; ++i){
        cout << T[i] << " ";
    }
    cout << T[N-1] << endl;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    struct Keys* KeyNum = new Keys[n];
//    Keys KeyNum[20];
    for( int i=0; i<n; ++i ){
        cin >> KeyNum[i].Key;
    }
    fun( KeyNum, n );
    vector<int> NotOccured;
    for(int i=0; i<n; ++i){
        if(KeyNum[i].Occured == false){
//            cout << KeyNum[i].Key << " ";
            NotOccured.push_back( KeyNum[i].Key );
        }
    }
    Sort_Print( NotOccured );
    return 0;
}

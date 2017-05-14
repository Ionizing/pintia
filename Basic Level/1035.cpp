#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    int *Orig = new int[N];
    for(int i=0; i!=N; ++i){
        cin >> Orig[i];
    }
    int *tmp = new int[N];
    for(int i=0; i!=N; ++i){
        cin >> tmp[i];
    }
    int k(0);
    for(int i=k; i!=N-1; ++i){
        if( tmp[i] > tmp[i+1] ){
            k = i;
            break;
        }
    }
    bool IsInsertion(true);
    for(int i=++k; i!=N; ++i){
        if( tmp[i] != Orig[i] ){
            IsInsertion = false;
            break;
        }
    }
    if( IsInsertion ){
        cout << "Insertion Sort" << endl;
        for(int i=k; i!=0; --i){
            if( tmp[i] < tmp[i-1] ){
                int t = tmp[i];
                tmp[i] = tmp[i-1];
                tmp[i-1] = t;
            }else break;
        }
        for(int i=0; i!=N-1; ++i){
            cout << tmp[i] << " ";
        }cout << tmp[N-1] << endl;
    }else{
        cout << "Merge Sort" << endl;
        bool Identified = false;
        for(int l=2; l<=N; l*=2){
            for(int i=l; i<N; i += 2*l){
                if( tmp[i-1] > tmp[i] ){
                    Identified = true;
                    break;
                }
            }
            if( Identified ){
                k = l;
                break;
            }
        }
//        cout << "k = " << k << endl;
        for(int i=0; i<N; i+=k*2){
            int *tmpArr = new int[k*2];
            int lef = i;
            const int mid = ( lef+k < N ) ? lef+k : N;
            const int rig = ( mid+k < N ) ? mid+k : N;
            int cur = mid;
            int j=0;
            while( lef < mid and cur < rig ){
                if( tmp[lef] < tmp[cur] ){
                    tmpArr[j++] = tmp[lef++];
                }else{
                    tmpArr[j++] = tmp[cur++];
                }
            }
            while( lef < mid ){
                tmpArr[j++] = tmp[lef++];
            }
            while( cur < rig ){
                tmpArr[j++] = tmp[cur++];
            }
            for(int t=0; t!=j; ++t){
                tmp[i+t] = tmpArr[t];
            }
            delete[] tmpArr;
        }
        for(int i=0; i!=N-1; ++i){
            cout << tmp[i] << " ";
        }cout << tmp[N-1] << endl;
    }
    return 0;
}

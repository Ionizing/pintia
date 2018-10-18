#include <iostream>
#include <string>
#include <vector>
//#include <fstream>

using namespace std;

bool IsUnique( const string Name, const vector<string> List )
{
    int Size = List.size();
    for(int i=0; i!=Size; ++i){
        if( List[i] == Name ) return false;
    }
    return true;
}

int main()
{
//    ifstream in( "in.txt" );
//    cin.rdbuf( in.rdbuf() );
    int Total, Interval, FirstNum;
    cin >> Total >> Interval >> FirstNum;
    vector<string> totalList( Total );
    for(int i=0; i!=Total; ++i){
        cin >> totalList[i];
    }
    --FirstNum;
    vector<string> awardedList;
    for(int i=FirstNum; i<Total; i+=Interval){
        if( IsUnique(totalList[i], awardedList) ){
            awardedList.push_back( totalList[i] );
            cout << totalList[i] << endl;
        }else{
            i -= Interval - 1;
        }
    }
    if( awardedList.size() == 0 )
        cout << "Keep going..." << endl;
    return 0;
}

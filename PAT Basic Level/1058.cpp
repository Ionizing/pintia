#include <iostream>
#include <vector>
#include <string>
//#include <fstream>

using namespace std;

struct Questions
{
    int Score = 0;
    int ChNum = 0;
    int CoNum = 0;
    bool Corr[5] = {false};
};

void Judge( const string Stu, const vector<Questions> Q, vector<int> &Mistakes )
{
    unsigned int ScoreSum = 0;
//    cout << Stu << endl;
    size_t len = Stu.length();
    unsigned int cnt = 0;
    for(size_t i=0; i!=len; ++i){
        if( Stu[i] == '(' ){
//            cout << "@23" << endl;
            bool IsTrue = true;
            while( Stu[i] != ')' ){
                char tmp = Stu[i];
                if( tmp >= '0' and tmp <= '9' ){
                    IsTrue = IsTrue and ( ( tmp - '0' ) == Q[cnt].CoNum );
                }else if( tmp >= 'a' and tmp <= 'e' ){
//                    cout << "Mistakes[" << cnt << "] = " << Mistakes[cnt] <<endl;
                    IsTrue = IsTrue and ( Q[cnt].Corr[tmp-'a'] == true );
                }
                ++i;
//                cout << i << " ";
            }
            Mistakes[cnt] += IsTrue ? 0 : 1;
            ScoreSum += IsTrue*Q[cnt].Score;
//            cout << ScoreSum << endl;
            ++cnt;
        }
    }
    cout << ScoreSum << endl;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N, M;
    cin >> N >> M;
    vector<Questions> Q(M);
    for(int i=0; i!=M; ++i){
        cin >> Q[i].Score >> Q[i].ChNum >> Q[i].CoNum;
        for(int j=0; j!= Q[i].CoNum; ++j){
            char tmp;
            cin >> tmp;
            Q[i].Corr[ tmp-'a' ] = true;
        }
//        cout << "@53" << endl;
    }
    string Stu;
    vector<int> Mistakes(M,0);
    getline(cin, Stu);
//    cout << "@56" << endl;
    for(int i=0; i!=N; ++i){
        getline(cin, Stu);
        Judge(Stu, Q, Mistakes);
//        cout << "@61" << endl;
    }
    // Fine Max;
    int Max = 0;
    for(int i=0; i!=M; ++i){
        Max = ( Mistakes[i] > Max ) ? Mistakes[i] : Max;
    }
    if( 0 == Max ){
        cout << "Too simple" << endl;
        return 0;
    }else{
        cout << Max;
        for(int i=0; i!=M; ++i){
            if( Max == Mistakes[i] ){
                cout << " " << 1+i;
            }
        }
        cout << endl;
    }
    return 0;
}

#include<iostream>
#include<string>
//#include<fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    ofstream out("out.txt");
//    cin.rdbuf(in.rdbuf() );
//    cout.rdbuf(out.rdbuf());
    int sum = 0;
    string dig_pinyin[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string input;
    cin >> input;
    for(auto i : input){
        sum += i-'0';
    }
    int num[100], i;
    for(i=0; sum/10 != 0 || sum%10 !=0; ++i, sum /= 10){
        num[i] = sum%10;
//        cout << num[i] << " ";
    }
    for(--i ; i>0; --i){
        cout << dig_pinyin[ num[i] ] << ' ';
    } cout << dig_pinyin[ num[i] ] << endl;
    return 0;
}

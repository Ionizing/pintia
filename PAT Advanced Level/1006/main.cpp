#include <iostream>
#include <string>
//#include <algorithm>
//#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Accounts
{
private:
    string ID = "";
    int Login_time = -1;
    int Logout_time = -1;
public:
    void get_data( const string &ID, const int &login, const int &logout )
    {
        this->ID = ID;
        Login_time = login;
        Logout_time = logout;
    }
    string showID() { return ID; }
    int put_login() { return Login_time; }
    int put_logout() { return Logout_time; }
};

int TimeToInt( const int HH, const int MM, const int SS )
{
    return ( HH*3600 + MM*60 + SS );
}

int main()
{
//    std::ifstream cin("in.txt");
    int M;
    cin >> M;
    Accounts *A = new Accounts[M];
    string ID;
    int HH, MM, SS;
    char tmp;
    int login_time, logout_time;
    for(int i=0; i!=M; ++i){
        cin >> ID >> HH >> tmp >> MM >> tmp >> SS;
        login_time = TimeToInt(HH, MM, SS);
        cin >> HH >> tmp >> MM >> tmp >> SS;
        logout_time = TimeToInt( HH, MM, SS );
        A[i].get_data(ID, login_time, logout_time );
    }

    int login_first_index(-1), logout_last_index(-1);
    int max_time(0), min_time(999999);
    for(int i=0; i!=M; ++i){
        if( A[i].put_login() < min_time ){
            login_first_index = i;
            min_time = A[i].put_login();
        }

        if( A[i].put_logout() > max_time ){
            logout_last_index = i;
            max_time = A[i].put_logout();
        }
    }

    cout << A[ login_first_index ].showID() << " " << A[ logout_last_index ].showID();
    return 0;
}

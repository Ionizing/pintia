#include <iostream>
#include <string>
//#include <vector>
//#include <fstream>

using namespace std;

struct Person
{
    string name;
    string Birthday;
};

bool IsValid( const string S )
{
    string InvBir1 = "1814/09/06", InvBir2 = "2014/09/06";
    return ( S >= InvBir1 and S <= InvBir2 );
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    size_t n;
    cin >> n;
//    vector<Person> Input;
    Person Max, Min;
    size_t validnum = 0;
    for(size_t i=0; i!=n; ++i){
        Person tmp;
        cin >> tmp.name >> tmp.Birthday;
        if( !IsValid( tmp.Birthday ) ){
            continue;
        }
//        Input.push_back(tmp);
        ++validnum;
        if( validnum == 1 ){
            Max = Min = tmp;
        }else{
            Max = (Max.Birthday < tmp.Birthday) ? Max : tmp;
            Min = (Min.Birthday > tmp.Birthday) ? Min : tmp;
        }
    }
    if( validnum == 0 ){
        cout << validnum << endl;
        return 0;
    }
    cout << validnum << " " << Max.name << " " << Min.name << endl;
    return 0;
}

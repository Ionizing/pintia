#include <iostream>
#include <set>
#include <map>
#include <string>
#include <iomanip>

#ifndef ONLINE_JUDGE
    #include <fstream>
#endif // ONLINE_JUDGE

using std::cin;
using std::endl;
using std::cout;

class Books
{
private:
    std::map< std::string, std::set<int> > Title;
    std::map< std::string, std::set<int> > Author;
    std::map< std::string, std::set<int> > Keywords;
    std::map< std::string, std::set<int> > Publisher;
    std::map< std::string, std::set<int> > Year;

public:
    Books(){}
    void get_info( std::istream& pstrm )
    {
        auto& istrm = pstrm;
        int ID(-1);
        istrm >> ID;
        pstrm.get();

        std::string tmp;
        getline(istrm, tmp);
//        cout << "@34 " << tmp << endl;
        Title[tmp].insert(ID);

        getline(istrm, tmp);
        Author[tmp].insert(ID);

        while (istrm >> tmp) {
            Keywords[tmp].insert(ID);
            char c;
            c = istrm.get();
            if( '\n' == c ) break;
        }

        getline(istrm, tmp);
        Publisher[tmp].insert(ID);

        getline(istrm, tmp);
        Year[tmp].insert(ID);
    }

    void query(std::map<std::string, std::set<int>> &m,
               const std::string &str)
    {
        if(m.find(str) != m.end()){
            for(auto i=m[str].begin(); i!=m[str].end(); ++i){
                cout << std::setw(7) << std::setfill('0') << *i << endl;
            }
        } else {
            cout << "Not Found" << endl;
        }
    }

    void query_main(std::istream& pstrm)
    {
        auto& istrm = pstrm;
        int num;
        std::string tmp;
        istrm >> num;
        istrm.get();
        istrm.get();

        getline(istrm, tmp);
        cout << num << ": " << tmp << endl;
        switch (num)
        {
            case 1: query(Title, tmp); break;
            case 2: query(Author, tmp); break;
            case 3: query(Keywords, tmp); break;
            case 4: query(Publisher, tmp); break;
            case 5: query(Year, tmp); break;
//            default: break;
        }
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        std::ifstream cin("in.txt");
    #endif // ONLINE_JUDGE
    Books B;
    int N;
    cin >> N;
    for(int i=0; i!=N; ++i){
        B.get_info( cin );
    }
    int qnum;
    cin >> qnum;
//    cout << "@89 " << qnum << endl;
    for(int i=0; i!=qnum; ++i){
       B.query_main( cin );
//       break;
    }
    return 0;
}
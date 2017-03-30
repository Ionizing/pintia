#include<iostream>
#include<string>
//#include<fstream>

using namespace std;
struct Person
{
    string Name;
    string ID;
    int Score;
};

inline int cmp( Person a, Person b )
{
    return (a.Score >= b.Score) ? true : false;
}

void Sort(Person* Student, int n)
{
    for(int i=0; i<n; ++i){
        int MaxScore = Student[i].Score;
        int MaxIndex = i;
        for(int j=i; j<n; ++j){
            if( Student[j].Score > MaxScore ){
                MaxScore = Student[j].Score;
                MaxIndex = j;
            }
        }
        auto tmp = Student[i];
        Student[i] = Student[MaxIndex];
        Student[MaxIndex] = tmp;
    }
}

inline void print( Person Student )
{
    cout << Student.Name << " " << Student.ID << endl;
    return;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n; cin >> n;
    struct Person* Student = new Person[n];
    for(int i=0; i<n; ++i){
        cin >> Student[i].Name >> Student[i].ID >> Student[i].Score;
    }
//    if( n == 1 ){
//        print(Student[0]);
//        return 0;
//    }
    Sort(Student,n);
    print(Student[0]);
    print(Student[n-1]);
    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    size_t n, p;
    scanf("%d%d",&n,&p);
    unsigned int* arr = new unsigned int[n];
    for(size_t i=0; i!=n; ++i){
        scanf("%d",&arr[i]);
    }
    sort(arr, arr+n);
//    for(size_t i=0; i!=n; ++i){
//        cout << arr[i] << " ";
//    }
    size_t M, m;
    size_t MaxLen = 1;
    for(size_t i=0; i<n; ++i){
        for(size_t j=i+MaxLen-1; j<n; ++j){
            M = arr[j]; m = arr[i];
            if( M <= m * p ) MaxLen = (j-i+1 > MaxLen) ? j-i+1 : MaxLen;
            else break;
        }
    }

    printf("%d\n",MaxLen);
    return 0;
}

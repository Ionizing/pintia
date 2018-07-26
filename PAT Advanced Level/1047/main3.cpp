#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char *> name[26*26*26*10+5];
vector<int> course[2500];

int string2int(char *str) {
    int res = 0;
    res += (str[3]-'0');
    res += (str[2]-'A')*10;
    res += (str[1]-'A')*26*10;
    res += (str[0]-'A')*26*26*10;
    return res;
}

int cmp(int a, int b) {
    return a < b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

    int n, k;
    scanf("%d %d", &n, &k);
    char *tmpname;
    int num, index, tmp;
    for (int i=0; i<n; i++) {
        tmpname = (char *)malloc(sizeof(char)*5);
        scanf("%s %d", tmpname, &num);
        tmp = string2int(tmpname);
        name[tmp].push_back(tmpname);
        for (int j=0; j<num; j++) {
            scanf("%d", &index);
            course[index-1].push_back(tmp);
        }
    }
    for (int i=0; i<k; i++) {
        num = course[i].size();
        printf("%d %d\n", i+1, num);
        if (num != 0)
        {
            sort(course[i].begin(), course[i].end(), cmp);
            for (int j=0; j<num; j++)
                printf("%s\n", name[course[i][j]][0]);
        }
    }
    return 0;
}
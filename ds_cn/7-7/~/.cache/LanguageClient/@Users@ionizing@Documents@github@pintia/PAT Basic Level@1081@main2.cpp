#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 

    string psw;
    int n; cin >> n; cin.get();
    while (n--) {
        getline(cin, psw);
        bool dig = false, Char = false, dot = false, other = false;
        for (size_t i = 0; i < psw.size(); ++i) {
            if (isdigit(psw[i]))dig = true;
            else if (isalpha(psw[i]))Char = true;
            else if ('.' == psw[i]) dot = true;
            else other = true;
        }

        if (psw.size() < 6) cout << "Your password is tai duan le.\n";
        else if (!other) {
            if (dig && Char) cout << "Your password is wan mei.\n";
            else if (!dig && Char) cout << "Your password needs shu zi.\n";
            else if (!Char && dig) cout << "Your password needs zi mu.\n";
        }
        else cout << "Your password is tai luan le.\n";

    }
    return 0;
}
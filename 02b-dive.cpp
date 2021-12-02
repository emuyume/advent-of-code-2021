#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int dep = 0, hori = 0, aim = 0;
    for (int i = 1; i <= N; ++i){
        string cmd; int x; cin >> cmd >> x;
        if (cmd == "forward") hori += x, dep += aim * x;
        if (cmd == "down") aim += x;
        if (cmd == "up") aim -= x;
    }
    cout << dep * hori << '\n';
}

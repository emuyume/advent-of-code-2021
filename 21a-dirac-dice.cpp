#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0; int N;
const string file = "test.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int p1 = 4, p2 = 5;
    int s1 = 0, s2 = 0;
    for (int i = 3; ; i += 3){
        p1 = (p1 + 3 * i - 3);
        p1 = (p1 - 1) % 10 + 1;
        s1 += p1;
        if (s1 >= 1000){
            cout << i * s2 << '\n';
            break;
        }
        swap(p1, p2); swap(s1, s2);
    }
}

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
    int T = countlines(); freopen(file.c_str(), "r", stdin);
    int ans = 0;
    while (T--){
        string s;
        for (int i = 1; i <= 10; ++i) cin >> s;
        cin >> s;
        for (int i = 1; i <= 4; ++i){
            cin >> s;
            if (s.size() != 5 && s.size() != 6){
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1001; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int cnt[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    for (int i = 1; i <= N; ++i){
        int x1, y1, x2, y2;
        char _, __; string ___;
        cin >> x1 >> _ >> y1 >> ___ >> x2 >> __ >> y2;
        if (x1 == x2){
            if (y2 < y1) swap(y2, y1);
            for (int j = y1; j <= y2; ++j){
                cnt[x1][j]++;
            }
        }
        else if (y1 == y2){
            if (x2 < x1) swap(x2, x1);
            for (int j = x1; j <= x2; ++j){
                cnt[j][y1]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < MN; ++i){
        for (int j = 0; j < MN; ++j){
            ans += cnt[i][j] >= 2;
        }
    }
    cout << ans << '\n';
}

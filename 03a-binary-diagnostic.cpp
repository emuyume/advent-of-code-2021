#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MM = 12; int N;
const string file = "txt.in";
int countlines(){ int c = 0; string l; ifstream f(file); while (getline(f, l)) c++; return c; }

int cnt[MM][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    N = countlines(); freopen(file.c_str(), "r", stdin);
    int M;
    for (int i = 1; i <= N; ++i){
        string s; cin >> s;
        M = s.size();
        reverse(s.begin(), s.end());
        for (int j = 0; j < s.size(); ++j) cnt[j][s[j] - '0']++;
    }
    int gamma = 0, epsilon = 0;
    for (int i = 0; i < M; ++i){
        if (cnt[i][0] > cnt[i][1]) epsilon += (1 << i);
        else gamma += (1 << i);
    }
    cout << gamma * epsilon << '\n';
}

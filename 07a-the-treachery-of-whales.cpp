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
    vector<int> v;
    string s; cin >> s; s += ',';
    while (s.length()){
        int idx = s.find(',');
        v.push_back(stoi(s.substr(0, idx)));
        s = s.substr(idx + 1);
    }
    N = v.size();
    sort(v.begin(), v.end());
    int cen = v[N / 2];
    int ans = 0;
    for (int x : v){
        ans += abs(x - cen);
    }
    cout << ans << '\n';
}

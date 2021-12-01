#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("txt.in", "r", stdin);
    string line;
    int last = 0x3f3f3f3f;
    int ans = 0;
    while (getline(cin, line)){
        int cur = stoi(line);
        ans += cur > last;
        last = cur;
    }
    cout << ans << '\n';
}
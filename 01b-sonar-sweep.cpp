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
    vector<int> v;
    while (getline(cin, line)){
        v.push_back(stoi(line));
    }
    vector<int> arr;
    for (int i = 2; i < v.size(); ++i){
        arr.push_back(v[i] + v[i - 1] + v[i - 2]);
    }
    int ans = 0;
    for (int i = 1; i < v.size(); ++i){
        ans += arr[i] > arr[i - 1];
    }
    cout << ans << '\n';
}

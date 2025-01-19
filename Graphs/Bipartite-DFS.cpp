#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include<numeric>
#include<queue>
#include<map>
#include<iterator>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<set>
 
using namespace std;
//#define int long long
#define ll long long
#define ull unsigned long long
#define all(v) v.begin(), v.end()
#define Rall(v) v.rbegin(), v.rend()
#define L '\n'
#define pb push_back
#define oo = LONG_LONG_MAX;
#define EPS 1e-9
const ll MOD = 1e9 + 7;
string di[] = {"D", "L", "U", "R", "UL", "UR", "DL", "DR"};
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
 
void NeedForSpeed() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
template<typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}
 
template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const auto &x: v) {
        out << x << " ";
    }
    return out;
}
 
int N = 1e5, M = 1e5;
vector<vector<int>> adj(N);
vector<int> vis;
vector<int> color(N, -1);
 
bool BipartiteGraph(int node, int c) {
    vis[node] = 1;
    color[node] = c;
    for (int child: adj[node]) {
        if (!vis[child]) {
            if (!BipartiteGraph(child, c ^ 1)) {
                return false;
            }
        } else {
            if (color[node] == color[child]) {
                return false;
            }
        }
    }
    return true;
}
 
void solve() {
    cin >> N >> M;
    adj.clear();
    adj.resize(N + 2);
    vis.clear();
    vis.resize(N + 2, 0);
    color.clear();
    color.resize(N + 2, -1);
 
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    bool flag = true;
    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            if (!BipartiteGraph(i, 0)) {
                flag = false;
                break;
            }
        }
    }
    if (!flag) { cout << "IMPOSSIBLE";
        return; }
    for (int i = 1; i <= N; ++i) {
        cout << color[i] + 1 << " ";
    }
}
 
signed main() {
    NeedForSpeed();
    IO();
    ll t = 1;
    // cin >> t;
 
    while (t--) {
        solve();
        cout << "\n";
    }
}

using namespace std;
#include <bits/stdc++.h>
using ll = long long;
using lli = long long int;
const lli INF = LONG_LONG_MAX;
const ll MOD = 1e9 + 7;

// #define int long long
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define pi pair<int, int>
#define pl pair<ll, ll>
#define M_PI 3.141592653589793
#define ull unsigned long long
#define all(v) v.begin(), v.end()
#define Rall(v) v.rbegin(), v.rend()
#define L '\n'
#define pb push_back
#define EPS 1e-9
#define OO LONG_LONG_MAX
#define sz(x) int(x.size())
#define rz(n) resize(n)
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define eb emplace_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define addMod(a, b, m) (((a % m) + (b % m)) % m)
#define subMod(a, b, m) (((a % m) - (b % m)) % m)
#define mulMod(a, b, m) (((a % m) * (b % m)) % m)
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / gcd(a, b) * (b))
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define per1(i, n) for (int i = n; i >= 1; i--)
string di[] = {"D", "L", "U", "R", "UL", "UR", "DL", "DR"};
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))

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
    for (auto &x: v)
        in >> x;
    return in;
}

template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const auto &x: v) {
        out << x << " ";
    }
    return out;
}

void Prefix1D() {
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << L;
    }
}

void Pefix2D() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll> > v(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
        }
    }
    //Sum all Rows
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            v[i][j] += v[i][j - 1];
        }
    }
    //Sum all Columns
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            v[i][j] += v[i - 1][j];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll sum = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1];
        cout << sum << L;
    }
}

signed main() {
    IO();
    NeedForSpeed();
    int t = 1;
    // cin >> t;

    while (t--) {
        // cout << L;
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <numeric>
#include <queue>
#include <map>
#include <iterator>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <set>

#define ll long long
using lli = long long int;
const lli INF = 0xFFFFFFFFFFFFFFFLL;
const ll mod = 1e9 + 7;
using namespace std;
// #define int long long
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
#define OO LONG_LONG_MAX
#define sz(x) int(x.size())
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)

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


bool IsPrime(ll n) {
    //TC = O(log n)
    if (n == 2)return true;
    if (n <= 1 || n % 2 == 0)return false;

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


void Sieve(ll Range) {
    //TC = O(N * log(log(N)))
    vector<ll> Primes(Range + 1, 1);
    Primes[0] = Primes[1] = 0;
    for (int i = 3; i * i <= Range; i += 2)
        if (Primes[i]) {
            for (int j = i * i; j <= Range; j += i)
                Primes[j] = 0;
        }
}

vector<int> divisors(int n) {
    vector<int> div;
    int i;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            div.push_back(i);
            div.push_back(n / i);
        }
    }
    if (i * i == n)
        div.push_back(i);
    return div;
}


void solve() {
  
}


signed main() {
    NeedForSpeed();
    IO();
    ll t = 1;

    //    cin >> t;

    while (t--) {
        solve();
        //        cout << "\n";
    }
}

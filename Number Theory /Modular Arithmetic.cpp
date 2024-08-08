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
using lli = long long int;
const lli INF = 0xFFFFFFFFFFFFFFFLL;
using namespace std;
// #define int long long
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

int modAdd(int a, int b, int m)
{
    return ((a % m) + (b % m)) % m;
}

// Function to perform Modular Subtraction
int modSub(int a, int b, int m)
{
    return ((a % m) - (b % m) + m) % m; // Adding m to handle negative numbers
}

// Function to perform Modular Multiplication
int modMul(int a, int b, int m)
{
    return ((a % m) * (b % m)) % m;
}

int fastPower(int base, int power) { // Binary Exponentiation ( Recursive )
// using Power Rule x ^ n = (x ^ 2) ^ (n / 2) if n is even .
// if n is odd x ^ n = (x ^ 2) ^ (n / 2) * x
    if (power == 0) return 1;
    int halfPower = fastPower(base, power / 2);
    int ans = halfPower * halfPower;
    if (power & 1)
        ans *= base;
    return ans;
}

ll fastPower(ll base, ll power) { // Binary Exponentiation ( iterative )
// using Power Rule x ^ n = (x ^ 2) ^ (n / 2) if n is even .
// if n is odd x ^ n = (x ^ 2) ^ (n / 2) * x
    ll result = 1;
    while (power > 0) {
        if (power & 1)
            result *= base;
        base *= base;
        power /= 2;
    }
    return result;
}

ll ModExponentiation(ll base, ll power, ll mod) { // fast Power With Multiplication Mod Rule ( Recursive )
// using Power Rule x ^ n = (x ^ 2) ^ (n / 2) if n is even .
// if n is odd x ^ n = (x ^ 2) ^ (n / 2) * x
// using Multiplication Mod Rule to avoid overflow
    if (power == 0) return 1;
    ll halfPower = ModExponentiation(base, power / 2, mod);
    ll ans = (halfPower % mod * halfPower % mod) % mod;
    if (power & 1)
        ans = ((ans % mod) * (base % mod)) % mod;
    return ans;
}

ll ModExponentiation(ll base, ll power, ll mod) {  // fast Power With Multiplication Rule ( iterative )
// using Power Rule x ^ n = (x ^ 2) ^ (n / 2) if n is even .
// if n is odd x ^ n = (x ^ 2) ^ (n / 2) * x
// using Multiplication Mod Rule to avoid overflow
    ll result = 1;
    while (power > 0) {
        if (power & 1)
            result = (result % mod * base % mod) % mod;
        base = (base % mod * base % mod) % mod;
        power /= 2;
    }
    return result;
}


int multiplyRecursive(int A, int B, int ans = 0 , int mod = 1e9) {//function to multiply to very large numbers
    if (B == 0) {
        return ans;
    }
    if (B & 1) {
        ans = (ans + A) % mod;
    }
    A = (A + A) % mod;
    return multiplyRecursive(A, B >> 1, ans);
}


int multiplyIterative(int A, int B) { // function to multiply to very large numbers
    int ans = 0;
    while(B) {
        if(B & 1) {
            ans = (ans + A) % mod;
        }
        A = (A + A) % mod;
        B >>= 1;
    }
    return ans;
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

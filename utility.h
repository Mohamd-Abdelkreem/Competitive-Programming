#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<iterator>
#include<unordered_map>
#include<set>
#define ll long long
using namespace std;
class utility {
public:
    bool isPowerOfTwo(ll n){
        // 2^31=1e9
        if (n == 0)
            return false;
        return (ceil(log2(n)) == floor(log2(n)));
    }
    ll sumOdd(ll n){
        ll res = (n+1)/2;
        ll finRes= res*res;
        return finRes;
    }
    ll sumEven(ll n){
        ll res = (n*(n+1));
        return res;
    }
    ll countDigit(ll n){
        return floor(log10(n)+1);
    }
    vector<ll>GetMultiples(int n ,int x){
        vector<long long>v;
        for(int i =x ; i<=n ;i += x){
            v.push_back(i);
        }
        return v;
    }
    ll fastPower(ll base, ll power, ll mod = 1000000007) {
        if (power == 0) {
            return 1;
        }
//    base %= mod;
        ll halfPower = fastPower(base, power / 2, mod);

//    halfPower %= mod;
        ll result = (halfPower * halfPower) % mod;

        if (power & 1) {
            result = (result * base);//% mod;
        }

        return result;
    }


    void sieve() {
        int limit=10000005;
        vector<bool> isPrime(limit, true);
        // ****NOTES****
        // N * log(log(N))
        // is used for preprocessing if you want to answer quires for o(1)
        // use to range 1e7
        isPrime[0] = isPrime[1] = false;
        for (int i = 2 ; i <= limit / i; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    bool Prime(int n){
        // ****NOTE****
        // O(sqrt(n))
        // divisors <= sqrt(n)
        if (n==2)return true;
        if (n<=1 || n%2==0 ) return false;
        for (int i = 3 ; i <= n/i ; i+=2) {
            if (n%i==0){
                return false;
            }
        }
        return true;
    }

    int GCD(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    int lcm(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        return abs(a / GCD(a, b)) * b;
    }

    vector<int> divisors(int n){
        vector<int>div;
        int i;
        for (i = 1 ; i  < n/i ; ++i) {
            if (n%i==0) {
                div.push_back(i);
                div.push_back(n / i);
            }
        }
        if(i*i==n)div.push_back(i);
        return div;
    }

    vector<int> primeFactorization(int n) {
        vector<int> factors;
        for (int i = 2 ; i  <= n/i ; ++i) {
            while (n % i == 0) {
                // ****NOTE****
                // FIRST DIVISOR FOR ANY NUMBER (COMPOSITE OR PRIME) IS A PRIME NUMBER
                factors.push_back(i);
                n /= i;
            }
        }
        if (n > 1) {
            factors.push_back(n);
        }
        return factors;
    }

    vector<int>div(int n){
        vector<int>v;
        int i;
        for ( i = 1 ; i < n/i ; ++i) {
            if (n%i==0){
                v.push_back(i),v.push_back(n/i);
            }
        }
        if (i*i==n){
            v.push_back(i);
        }
        return v;

    }

    ll powmod(ll a,ll b,ll m)
    {
        ll ans=1;
        while(b>0)
        {
            if(b&1) ans=(ans*a)%m;
            a=(a*a)%m;
            b>>=1;
        }
        return ans;
    }

};


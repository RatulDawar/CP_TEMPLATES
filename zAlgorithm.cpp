#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define debugs(x,n) cerr << #x <<" "; _print(x,n); cerr << endl;
#else
#define debug(x);
#define debugs(x,n);
#endif
 
using ll = long long;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const ll LINF = 2e18L + 5;
const int INF = 1e9 + 5;


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T> void _print(T p[],int n);
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(T p[],int n){cerr<<"[ ";for(int i =0;i<n;i++){cerr<<p[i]<<" ";}cerr<<"]";} 
 
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/* -------------------------------------------------------------------------------------------------------------------------- - */
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
string numberToString(ull n) {ostringstream geek; geek << n; string s = geek.str(); return s;}
ll stringToNumber(string s) {stringstream stream(s); ll x = 0; stream >> x; return x;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void calFact( ll n,ll *fact,ll *ifact,ll mod){ fact[0] = 1;ifact[0] = mminvprime(1,mod);for(ll i = 1;i<n;i++){fact[i] = (fact[i-1]*i)%mod;ifact[i] = mminvprime(fact[i],mod);}}
void yes(){cout<<"YES"<<nline;}
void no(){cout<<"NO"<<nline;}


struct Matrix {
    int n;
    vector<vector<ll>> a;
    Matrix(int n){
        this->n = n;
        this->a = vector<vector<ll>>(n, vector<ll>(n, 0));
    } 
	Matrix operator *(Matrix other) {
		Matrix product(n);
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++){
				for(int k = 0;k<n;k++){
					product.a[i][k] +=  (a[i][j]*other.a[j][k])%MOD;
                    product.a[i][k] %= MOD;
				}
			}
		}
		return product;
	}
    void print(){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cerr<<this->a[i][j]<<' ';
			}
			cerr<<nline;
		}
	}
};
Matrix expo_power(Matrix a, long long k) {
    int n = a.n;
	Matrix res = Matrix(n);
	for(int i = 0; i < n; ++i) {
		res.a[i][i] = 1;
	}
	while(k) {
		if(k % 2) {
			res = res * a;
		}
		k /= 2;
		a = a * a;
	}
	return res;
}

struct bitTree{
    ll n;
    ll *bit;
    bitTree(ll n){
        this->n = n;
        bit = new ll[n+1];
        for(int i = 0;i<=n;i++)bit[i] = 0;
    }
    void update(ll i, ll val){
        i++;
        while(i <= n){
            bit[i] += val;
            i += (i&(-i));
        }
    }
    ll sum(ll i){
        i++;
        ll ans = 0;
        while(i > 0){
            ans += bit[i];
            i -= (i&(-i));
        }
        return ans;
    }
    ll query(ll l, ll r){
        return sum(r) - sum(l - 1);
    }
};

/* --------------------------------------------------------------------------------------------------------------------------* /

********     *    *     *****    *****   ******   ********  
*       *    *    *       *        *     *        *       * 
********     *    *       *        *     ****     ********
*       *    *    *       *        *     *        *       * 
********      ****        *        *     ******   *       *


*****  *    *  *****  *****   *  *  ******  **    *
*      *    *    *    *       * *   *       * *   *
*      ******    *    *       **    ****    *  *  *
*      *    *    *    *       * *   *       *   * *
*****  *    *  *****  *****   *  *  ******  *    **


/*-----------------------------------------------------------------------------------------------------------------------------*/

vector<ll> zArray(string &s){
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0,r = 0;
    for(int i = 1;i<n;i++){
        if(i < r){
            z[i] = min(r - i,z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;

}

void solve(){
    string s;cin>>s;
    vector<ll> z = zArray(s);
    vector<ll> ans;
    for(int i = 0;i<s.size();i++){
        ll rem = s.size() - i;
        if(z[i] == rem){
            ans.push_back(rem);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<" "; 
}
int main()
{
 
   fastio(); 
   int t = 1;
   //sieve();
   //calFact(MAXN,fact,ifact,MOD1);
   //cin>>t;
   int testCase = 0;
   while(testCase++ < t){
      //google(testCase);
      solve();
      cout<<nline;
   }
} 

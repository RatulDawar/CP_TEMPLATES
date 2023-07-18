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
#define INF 1e9
#define LINF 1e18
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define debugs(x,n) cerr << #x <<" "; _print(x,n); cerr << endl;
#else
#define debug(x);
#define debugs(x,n);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
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
template <class T> void _print(queue<T> q){cerr<<"[ ";while(!q.empty()){cerr<<q.front()<<" ";q.pop();}cerr<<" ]";}
 
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
ll crt(vector<pll> &v){ll ans = 0;int n = v.size();ll m = 1;for(int i = 0;i<n;i++)m*=v[i].first;for(int i = 0;i<n;i++){ll t = 1;for(ll j = 0;j<i;j++){t*= v[j].first;t*= mminv(v[j].first,v[i].first);t %= m;}ans += (t*(v[i].second + m - ans))%m;ans %= m;}return ans;} // O(N*N)
void make_prefix(vector<vector<ll>> &v){int n = v.size();int m = v[0].size();for(int i = 1;i<n;i++){for(int j = 0;j<m;j++){v[i][j] += v[i-1][j];}}for(int i = 0;i<n;i++){for(int j = 1;j<m;j++){v[i][j] += v[i][j-1];}}}
ll sum(vector<vector<ll>> &v,int x2,int y2,int x1,int y1){return (v[x2][y2] - (x1 - 1>=0?v[x1-1][y2]:0) - (y1-1>=0?v[x2][y1-1]:0) + (x1-1>=0 && y1-1>= 0 ?v[x1-1][y1-1]:0));}
void yes(){cout<<"YES"<<nline;}
void no(){cout<<"NO"<<nline;}

//void calFact(){ fact[0] = 1;ifact[0] = mminvprime(1,MOD1);for(ll i = 1;i<maxN;i++){fact[i] = (fact[i-1]*i)%MOD1;ifact[i] = mminvprime(fact[i],MOD1);}}
/* --------------------------------------------------------------------------------------------------------------------------* /
//1.DP se soch
//2.DP se soch
//3.DP se soch
//graph, gcd, BS, seive
//if NOTA,then
//brute force hi optimal h
/*-----------------------------------------------------------------------------------------------------------------------------*/
const int maxN = 1e5 + 5;
ll a[maxN];
ll seg[4*maxN + 5];

void buildTree(int l,int r,int ind){
   if(l == r){
      seg[ind] = a[l];
      return;
   }
   int mid = l + (r-l)/2;
   buildTree(l,mid,2*ind+1);
   buildTree(mid+1,r,2*ind+2);
   seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

void update(int l,int r,int point,int val,int ind){
   if(point < l || point > r)return;
   if(l == r && l == point){
      seg[ind] = val;
      return;
   }
   int mid = l + (r-l)/2;
   update(l,mid,point,val,2*ind+1);
   update(mid+1,r,point,val,2*ind+2);
   seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}
ll query(int l,int r,int qL,int qR,int ind){
   if(qR < l || r < qL) return 0;
   if(l >= qL && r <= qR)return seg[ind];
   int mid = l + (r-l)/2;
   ll left = query(l,mid,qL,qR,2*ind+1);
   ll right = query(mid+1,r,qL,qR,2*ind+2);
   return left + right;
}

void solve() 
{
   ll n,m;cin>>n>>m;
   for(int i = 0;i<n;i++)cin>>a[i];
   buildTree(0,n-1,0);
   for(int i = 0;i<m;i++){
      int type,x,y;cin>>type>>x>>y;
      if(type == 1){
         update(0,n-1,x,y,0);
      }else{
         cout<<query(0,n-1,x,y-1,0)<<nline;
      }
   }
}

int main()
{
 
   fastio(); 
   int t = 1;
   //cin>>t;
   //sieve();
   int testCase = 0;
   while(testCase++ < t){
      //google(testCase);
      solve();
      cout<<nline;
   }
}   
 
 
/*
 
 
 
*/
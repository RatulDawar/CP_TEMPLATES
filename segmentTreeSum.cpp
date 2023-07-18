#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
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
#else
#define debug(x);
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
void yes(){cout<<"YES"<<nline;}
void no(){cout<<"NO"<<nline;}
/* --------------------------------------------------------------------------------------------------------------------------* /
//1.DP se soch
//2.DP se soch
//3.DP se soch
//graph, gcd, BS, seive
//if NOTA,then
//brute force hi optimal h
/* ---------------------------------------------------------------------------------------------------------------------------- - */
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.ff != b.ff){
        return (a.ff<b.ff);
    }else{
        return(a.ss>b.ss);
    }
}
const int maxN = 100000;
vector<ll> v(maxN+5);
vector<ll> seg(4*maxN + 5);
vector<ll> lazy(4*maxN + 5);
void build_tree(ll l,ll r,ll ind){
   if(l == r){
       seg[ind] = v[l];
       return ;
   }
   int mid = l+ (r-l)/2;
   build_tree(l,mid,2*ind+1);
   build_tree(mid+1,r,2*ind+2);
   seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}
ll query(ll start,ll end,ll qStart,ll qEnd,ll ind){
     if(lazy[ind] != 0){
        seg[ind] += (r - l + 1)*lazy[ind];
        if(l != r){
            lazy[2*ind + 1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(qStart >end || qEnd<start)return 0;
    if(qStart <= start && qEnd >= end)return seg[ind];
    int mid = start + (end - start)/2;

    ll  left = query(start,mid,qStart,qEnd,2*ind+1);
    ll right  = query(mid+1,end,qStart,qEnd,2*ind+2);
    return left + right;
}
void update(ll l,ll r,ll point, ll val,ll ind){
    
    int mid = l+ (r-l)/2;
    if(l == r){
        seg[ind] = val;
        v[point] =  val;
        return;
    }
    if(point<= mid){
        update(l,mid,point,val,2*ind+1);
    }else{
        update(mid+1,r,point,val,2*ind+2);
    }
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    
}
void rangeUpdate(ll l,ll r, ll uL,ll uR,ll val,ll ind){
    if(lazy[ind] != 0){
        seg[ind] += (r - l + 1)*lazy[ind];
        if(l != r){
            lazy[2*ind + 1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(r< uL || uR< l)return;
    if(uL <= l  && r <= uR){
        seg[ind] += (r-l + 1)*val;
        if(l != r){
            lazy[2*ind + 1] += val;
            lazy[2*ind + 2] += val;
        }
        return;
    }
    ll mid = l + (r-l)/2;
    rangeUpdate(l,mid,uL,uR,val,2*ind+1);
    rangeUpdate(mid+1,r,uL,uR,val,2*ind+2);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}
void solve() 
{
    ll n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    build_tree(0,n-1,0);
    ll ans = query(0,n-1,0,2,0);
    debug(ans);
    update(0,n-1,0,4,0);
    ans = query(0,n-1,0,2,0);
    debug(ans);
    cout<<ans;
}
int main()
{
    fastio();
   int t = 1;
   //cin>>t;
   
   while(t--){
       solve();
       cout<<nline;
   }

} 
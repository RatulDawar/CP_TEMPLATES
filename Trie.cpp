#define ll long long

class Trie{
    static const int BIT_SIZE = 32;
    public:
    vector<Trie*> child;
    Trie(): child(2) {}
    void insert(ll val){
        Trie * curr = this;
        for(int i = BIT_SIZE - 1;i >= 0;i--){
            int v = ((1LL<<i)&val) != 0;
            if(!curr->child[v])curr->child[v] = new Trie();
            curr = curr->child[v];
        }
    }
    ll search(ll val){
        //cout<<"val "<<val<<endl;
        Trie * curr = this;
        ll ans = 0;
        for(int i = BIT_SIZE - 1;i >= 0;i--){
            if(!curr)break;
            int v = ((1LL<<i)&val) != 0;
            if(curr->child[v^1]){
                curr = curr->child[v^1];
                ans |= (1LL<<i);
            }else{
                curr = curr->child[v];
            }
        }
        return ans;
    }
};

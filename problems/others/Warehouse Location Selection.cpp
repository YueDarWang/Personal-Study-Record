#include<bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define mian main
#define retrun return
#define endl '\n'

using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    priority_queue<ll, vector<ll>, less<ll>> pq1;       // 大根堆
    priority_queue<ll, vector<ll>, greater<ll>> pq2;    // 小根堆
    for(ll i=0;i<N;++i){
        ll x;
        cin >> x;
        a[i] = x;
        if(pq1.empty() || x <= pq1.top()){
            pq1.push(x);
        }else{
            pq2.push(x);
        }
        // 平衡两个堆的大小
        if(pq1.size() > pq2.size() + 1){
            pq2.push(pq1.top());
            pq1.pop();
        }else if(pq2.size() > pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    ll x=pq1.top();
    ll ans=0;
    for(ll i=0;i<N;++i){
        ans+=abs(x-a[i]);
    }
    cout << ans << endl;
}

#undef int

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
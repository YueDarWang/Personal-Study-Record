#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//动态维护中位数

void solve(){
    ll p;
    cin >> p;
    vector<vector<ll>> ans(p);
    for(auto&q:ans){
        ll m;
        cin >> m;
        q.push_back(m);
        cin >> m;
        for(ll i=0;i<m;++i){
            ll x;
            cin >> x;
            q.push_back(x);
        }
    }

    priority_queue<ll, vector<ll>, less<ll>> pq1;       // 大根堆
    priority_queue<ll, vector<ll>, greater<ll>> pq2;    // 小根堆
    for(ll i=0;i<p;++i){
        ll m;
        cin >> m;
        for(int j=0;j<m;++j){
            ll x;
            cin >> x;
            if(pq1.empty() || x <= pq1.top()){
                pq1.push(x);
            }else{
                pq2.push(x);
            }
            // 动态平衡两个堆的大小
            if(pq1.size() > pq2.size() + 1){
                pq2.push(pq1.top());
                pq1.pop();
            }else if(pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
            if(pq1.size() == pq2.size()){
                cout << (pq1.top() + pq2.top()) / 2;
            }
            else{
                if(pq1.size() > pq2.size()){
                    cout << pq1.top();
                }else{
                    cout << pq2.top();
                }
            }
            cout<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
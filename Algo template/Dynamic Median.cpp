#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//动态维护中位数

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto&p:a) cin >> p;
    priority_queue<ll, vector<ll>, less<ll>> pq1;       // 大根堆
    priority_queue<ll, vector<ll>, greater<ll>> pq2;    // 小根堆
    for(ll i=0;i<n;++i){
        ll x = a[i];
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
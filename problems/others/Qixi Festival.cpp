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
    ll n,m,t;
    cin>>n>>m>>t;
    vector<ll> r(n+1),c(m+1);
    for(ll i=0;i<t;++i){
        ll x,y;
        cin>>x>>y;
        r[x]++;
        c[y]++;
    }
    bool R=false,C=false;
    ll ans=0;
    if(t%n==0){
        R=true;
        ll ave = t/n;
        for(ll i=1;i<=n;++i){
            r[i]-=ave;
        }
        for(ll i=2;i<=n;++i){
            r[i]+=r[i-1];
        }
        sort(++r.begin(),r.end());
        ll x=r[(n+1)/2];
        for(ll i=1;i<=n;++i){
            ans+=abs(r[i]-x);
        }
    }
    if(t%m==0){
        C=true;
        ll ave = t/m;
        for(ll i=1;i<=m;++i){
            c[i]-=ave;
        }
        for(ll i=2;i<=m;++i){
            c[i]+=c[i-1];
        }
        sort(++c.begin(),c.end());
        ll x=c[(m+1)/2];
        for(ll i=1;i<=m;++i){
            ans+=abs(c[i]-x);
        }
    }
    if(R&&C){
        cout<<"both "<<ans;
    }
    else{
        if(R){
            cout<<"row "<<ans;
        }
        else if(C){
            cout<<"column "<<ans;
        }
        else{
            cout<<"impossible";
        }
    }
}

#undef int

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
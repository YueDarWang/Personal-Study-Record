#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD=1000000007;
const ll MAXN=2e5+10;

ll fac[MAXN],inv[MAXN];     //阶乘和逆元数组

ll fast_pow(ll a,ll b){     //快速幂
    ll res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

void init(){        //预处理阶乘和逆元
    fac[0]=1;
    for(ll i=1;i<MAXN;i++) fac[i]=fac[i-1]*i%MOD;
    inv[MAXN-1]=fast_pow(fac[MAXN-1],MOD-2);   
    for(ll i=MAXN-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%MOD;
}

ll perm(ll n,ll m){     //A(n,m)
    if(m>n) return 0;
    return fac[n]*inv[n-m]%MOD;
}

ll comb(ll n,ll m){     //C(n,m)
    if(m>n) return 0;
    return fac[n]*((inv[m]*inv[n-m])%MOD)%MOD;
}

int main(){
    init();
    ll n,m;
    cin >> n >> m;
    cout << perm(n,m) << " " << comb(n,m) << endl;
}
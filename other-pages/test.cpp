#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define MP make_pair
#define fr(i,n) for (i = 0; i < n; ++i) 
#define rep(i,k,n) for (i = k; i <= n; ++i) 
#define repr(i,k,n) for (i = k; i >= n; --i) 
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
 
const ll MAX =1e9+7;
 
void fastscan(ll &x)
    {
        bool neg=false;
        register ll c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }

ll cnt(ll x){
    ll c=0;
    while(x>0){
        x>>=1;
        c++;
    }
    return c;
}

int main()
{
    IOS;  

    ll t;
    cin>>t;
    while(t--){
        ll a,b,n,i,j;
        cin>>a>>b>>n;
        vector<ll> xo;

        ll count=max(cnt(a),cnt(b));
        ll ans=a^b;
        xo.pb(a);
        xo.pb(b);
        xo.pb(max(ans,ans^((1LL<<count)-1)));
        



       if(n%3==1){
           cout<<xo[0]<<"\n";
       }else if(n%3==2){

           cout<<xo[1]<<"\n";
       }else
       {
            
           cout<<xo[2]<<"\n";
       }
       
        

        
            
        //cout<<c;

 
 
 
    }
    
    return 0;
}
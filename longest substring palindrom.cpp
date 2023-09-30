#include<bits/stdc++.h>
#define DilligentArch() ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define testcase(t) int t; cin>>t; while(t--)
#define pb push_back
typedef long long ll;
using namespace std;
#define  ll    long long
#define  LIM   1000000
#define  base1 129
#define  MOD1  1000000009

string s;
ll pow1[LIM+5];
void calPower(){
    pow1[0] = 1;
    for(int i = 1; i < LIM; i++){
        pow1[i] = (pow1[i-1]*base1)%MOD1;

    }
}
int getHash(){
    ll hash1 = 0,  revhash1 = 0;
    int maxi = 1;
    for(int i = 0; s[i]; i++){
        hash1 = ((hash1*base1)%MOD1 + (s[i]-'a' + 1))%MOD1;

        revhash1 = (revhash1 + ((s[i]-'a' + 1)*pow1[i])%MOD1)% MOD1;

        if(hash1 == revhash1 ) maxi = max(maxi, i+1);
    }
    return maxi;
}
int main(){
    calPower();
    int t; cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>s;

        int maxi = getHash();
        int matched = maxi;

    
        cout<< "Case "<<i<<": "<<maxi<<endl;

    }
}

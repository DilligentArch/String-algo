#include<bits/stdc++.h>
#define DilligentArch() ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define testcase(t) int t; cin>>t; while(t--)
#define pb push_back
typedef long long ll;
using namespace std;

void solve()
{
   string s,pat;
   cin>>s>>pat;
   ll m=pat.size();
        ll n=s.size();
        ll lps[m];
        auto computeLPS=[&]()->void{
            ll len=0;
            ll i=1;
            lps[0]=0;
            while(i<m){
                if(pat[i]==pat[len]){
                    len++;
                    lps[i]=len;
                    i++;
                }
                else {
                    if(len!=0){
                        len=lps[len-1];
                    }
                    else {
                        lps[i]=len;
                        i++;
                    }
                }
            }


        };
    auto kmp=[&]()-> ll{
        computeLPS();
        ll i=0,j=0,count=0;
        while(i<n){
            if(pat[j]==s[i]){
                i++;
                j++;
            }
            if(j==m){
                j=lps[j-1];
                count++;
            }
            else if(i<n and pat[j]!=s[i]){
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        return count;
    };
    cout<<kmp()<<endl;
}

int main()

{

    DilligentArch()

    testcase(t){

        solve();

    }

}



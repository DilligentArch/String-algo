#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 31;  // You can choose any suitable base for hashing.

// Function to check if a substring is a palindrome using hashing
bool isPalindrome(const string& s, int left, int right, vector<int>& hash, vector<int>& base_powers) {
    int len = right - left + 1;
    long long hash1 = (hash[right] - (left > 0 ? hash[left - 1] : 0) + MOD) % MOD;
    long long hash2 = (hash[right] * base_powers[len]) % MOD;

    return hash1 == hash2;
}

// Function to find the index of the maximum palindromic substring
pair<int, int> findMaxPalindromeIndex(const string& s) {
    int n = s.length();
    if (n == 0) {
        return make_pair(-1, -1);
    }

    vector<int> hash(n, 0);
    vector<int> base_powers(n, 1);
    hash[0] = s[0];
    for (int i = 1; i < n; ++i) {
        hash[i] = (hash[i - 1] * BASE + s[i]) % MOD;
        base_powers[i] = (base_powers[i - 1] * BASE) % MOD;
    }
    ///for(auto u :hash)cout<<u << " ";
    ///cout<<endl;
   ///  for(auto u :base_powers)cout<<u << " ";
   /// cout<<endl;

    int maxLen = 0;
    int startIndex = 0;

    for (int i = 0; i < n; i++) {
        int left = i;
        int right = i;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIndex = left;
            }
            --left;
            ++right;
        }

        left = i;
        right = ++i;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIndex = left;
            }
            --left;
            ++right;
        }
    }

    return make_pair(startIndex, startIndex + maxLen - 1);
}

void solve {
    string s;

    cin >> s;

    pair<int, int> result = findMaxPalindromeIndex(s);
    int startIndex = result.first;
    int endIndex = result.second;

    if (startIndex == -1) {
        cout << "No palindrome found." << endl;
    } else {
        cout << "Maximum palindromic substring: " << s.substr(startIndex, endIndex - startIndex + 1) << endl;
        cout << "Start index: " << startIndex << endl;
        cout << "End index: " << endIndex << endl;
    }

    return 0;
}
int main(){


    int t;
    cin>>t;
    for(int i=1;i<n;i++){
        cout<< "Case "<<i<< ": ";
        solve();
    }







}

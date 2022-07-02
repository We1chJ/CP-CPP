#include "bits/stdc++.h"

using namespace std;

using ll = long long;
const ll P = 29, M1 = 1e9+7, M2 = 1e9+9;

int freq1[26], freq2[26];
string s1, s2;
int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> s1 >> s2;
    if(s1.length() > s2.length()){ cout << 0 << endl; return 0;}

    set<pair<ll, ll>> s;
    ll poly1 = 0, poly2 = 0, pow1 = 1, pow2 = 1;
    for(int i = 0; i < s1.size(); i++){
        freq1[s1[i] - 'a'] ++ ;
        freq2[s2[i] - 'a'] ++;
        poly1 = (poly1* P + (s2[i] - 'a')) % M1;
        poly2 = (poly2* P + (s2[i] - 'a')) % M2;

        pow1 = pow1*P %M1;
        pow2 = pow2*P %M2;
    }
    
    bool match = true;
    for(int i = 0; i < 26; i++){
        match &= freq1[i] == freq2[i];
    }
    if(match ) s.insert({poly1, poly2});

    for(int i = s1.size(); i < s2.size(); i++){
        freq2[s2[i] - 'a']++;
        freq2[s2[i - s1.size()] - 'a']--;

        poly1 = (poly1 * P - pow1 * (s2[i - s1.size()] - 'a')% M1 + (s2[i] - 'a') + M1) % M1;
        poly2 = (poly2 * P - pow2 * (s2[i - s1.size()] - 'a')% M2 + (s2[i] - 'a') + M2) % M2;

        bool match = true;
        for(int j = 0; j < 26; j++){
            match &= freq1[j] == freq2[j];
        }
        if(match)
        { 
            s.insert({poly1, poly2}); 
        }
    }

    cout << s.size() << endl;
    
}
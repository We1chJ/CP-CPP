// #include "bits/stdc++.h"

// using namespace std;
// using ll = long long;
// int main(){

//     cin.tie(0) -> sync_with_stdio(0);

//     int n, x;
//     cin >> n >> x;
//     vector<int> vec(n);
//     unordered_map<ll, ll> left, right;

//     for(int i = 0; i < n; i ++){
//         cin >> vec[i];
//     }

//     for(int i = 0; i < (1 << (n/2)); i++){
//         ll sum = 0;
//         for(int j = 0; j < n/2; j++){
//             if(i & (1 << j)){
//                 sum += vec[j];
//             }
//         }
//         left[sum]++;
//     }
//     for(int i = 0; i < (1 << (n-n/2)); i++){
//         ll sum = 0;
//         for(int j = 0; j < (n-n/2); j++){
//             if(i & (1 << j)){
//                 sum += vec[j + n/2];
//             }
//         }
//         right[sum]++;
//     }

//     ll ans = 0;
//     for(auto num : left){
//         ans += right[x - num.first] * num.second;
//     }
//     cout << ans << endl;
// }



#include "bits/stdc++.h"

using namespace std;
using ll = long long;
int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    vector<ll> left, right;

    for(int i = 0; i < n; i ++){
        cin >> vec[i];
    }

    for(int i = 0; i < (1 << (n/2)); i++){
        ll sum = 0;
        for(int j = 0; j < n/2; j++){
            if(i & (1 << j)){
                sum += vec[j];
            }
        }
        left.push_back(sum);
    }
    for(int i = 0; i < (1 << (n-n/2)); i++){
        ll sum = 0;
        for(int j = 0; j < (n-n/2); j++){
            if(i & (1 << j)){
                sum += vec[j + n/2];
            }
        }
        right.push_back(sum);
    }

    sort(left.begin(), left.end()); 
	sort(right.begin(), right.end());
    ll ans = 0;
    for(ll num : left){
        ans += (upper_bound(right.begin(), right.end(), x - num) - right.begin()) - (lower_bound(right.begin(), right.end(), x - num) - right.begin());
    }
    cout << ans << endl;
}
#include "bits/stdc++.h"

using namespace std;

int ask(string s, int i, int j){
    cout << s << " " << i << " " << j << endl;
    cout.flush();
    int a;
    cin >> a;
    return a;
}

int sum(int i, int j){
    int s = 0;
    s += ask("or", i, j);
    s += ask("and", i, j);
    return s;
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    // begin
    vector<int> nums (n+1, 0);
    int s12 = sum(1, 2);
    int s23 = sum(2, 3);
    int s13 = sum(1, 3);

    nums[1] = (s12 + s13 - s23)/2;
    nums[2] = s12 - nums[1];
    nums[3] = s13 - nums[1];

    for(int i = 4; i <= n; i++){
        nums[i] = sum(1, i) - nums[1];
    }

    sort(nums.begin(), nums.end());
    cout << "finish " << nums[k] << endl;
    
}
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
vector<int> labels[N];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    for(int i =0 ; i <n; i++){
        int c;
        cin >> c;
        labels[c].push_back(i);
    }
    int sq = (int)sqrt(n); // how fast // why sqrt

    vector<int> smallans(n+1, 0);
    vector<int> largeans(n+1, 0);


    for(int label = 1; label<= n; label++){
        auto &v = labels[label];
        int cnt = v.size();
        if(cnt > sq){
            // large labels
            vector<int> nxt(n+1, 0);
            for(int i : v) nxt[i] = i;
            nxt[n]=n;
            for(int x = n-1; x >= 0; x--){
                if(nxt[x] == 0)
                    nxt[x] = nxt[x+1];
            }

            for(int x = 1; x <= n; x++){
                int sz = 0;

                int pos = v[0];
                while(pos < n){
                    sz++;
                    if(pos + x + 1 >= n) break;
                    pos = nxt[pos+x+1];
                }

                largeans[x] += sz;
            }
        }else{

            for(int group = 1; group <= cnt; group ++){
                int l = 0, r = n+1; // searching over max x
                while(l < r){
                    int mid = (l + r + 1) / 2;

                    int sz = 0;
                    int left = 0, right = 0;
                    while(left < cnt){
                        while(right < cnt && v[right] - v[left] + 1 <= mid) right++;
                        sz++;
                        left = right;
                    }

                    if(sz < group){ // too few groups, too big of x, shrink
                        r = mid - 1;
                    }else{
                        l = mid; // too many groups, too small of x, expand
                    }
                }
                smallans[1] ++;
                if(l <= n)smallans[l]--;
            }
        }
        
    }
    for(int i =2; i <=n; i++){
        smallans[i] += smallans[i-1];
    }

    for(int i = 1; i <= n; i++){
        cout << smallans[i] + largeans[i] << endl;
    }
    
}
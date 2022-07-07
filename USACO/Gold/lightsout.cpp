#include "bits/stdc++.h"

using namespace std;
int n ;



int opt[201];

int assign(int prevx, int prevy, int curx, int cury, int lastx, int lasty){
    if(curx == prevx){
        if(prevy < cury){
            if(lastx > curx) return -1;
            else return -2;
        }else{
            if(lastx < curx) return -1;
            else return -2;
        }
    }else{
        if(prevx < curx){
            if(lasty < cury) return -1;
            else return -2;
        }else{
            if(lasty > cury) return -1;
            else return -2;
        }
    }
}

int main(){

    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }

    vector<int> String (1, 0);
    for(int i = 0; i < n; i++){
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        String.push_back(abs(A[i].first - A[j].first) + abs(A[i].second - A[j].second));

        String.push_back(assign(A[i].first, A[i].second, A[j].first, A[j].second, A[k].first, A[k].second));
    }
    String.back() = 0;

    for(int i = 0; i < n; i++){
        opt[i+1] = opt[i] + String[2*i+1];
    }
    opt[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        opt[i] = min(opt[i], opt[i + 1] + String[2 * i + 1]);
    }
    multiset<vector<int> > st;
    for (int i = 0; i < String.size(); i += 2) {
        for (int ln = 1; i + ln <= String.size(); ln += 2) {
            st.insert(vector<int>(String.begin() + i, String.begin() + i + ln));
        }
    }
    int result = 0;
    for (int i = 2; i + 2 < String.size(); i += 2) {
        int ln;
        int cost = 0;
        for (ln = 1; ; ln += 2) {
            if (st.count(vector<int>(String.begin() + i, String.begin() + i + ln)) == 1) {
                break;
            }
            cost += String[i + ln];
        }
        result = max(result, cost + opt[(i + ln) / 2] - opt[i / 2]);
    }
    
    cout << result << endl;
}
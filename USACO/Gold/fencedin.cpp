#include "bits/stdc++.h"

using namespace std;

int A, B, N, M;
const int MAXNODE = 2001*2001+10;
int uf[MAXNODE];

int find(int node){
    if(uf[node] != node)
        uf[node] = find(uf[node]);
    return uf[node];
}

void unite(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    if (rand() % 2) {
        uf[rootB] = rootA;
    } else {
        uf[rootA] = rootB;
    }
}

bool merge(int a, int b){
    if(find(a) == find(b))  return false;
    unite(a, b);
    return true;
}

int ind(int r, int c){
    return r*M + c;
}

int main(){
    ifstream cin("fencedin.in");
	ofstream cout("fencedin.out");
    cin >> A >> B >> N >> M;

    vector<int> temp;

    vector<int> ver;
    vector<int> hor;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        temp.push_back(num);
    }
    sort(begin(temp), end(temp));
    int prev = 0;
    for(int i = 0; i < N; i++){
        int num = temp[i];
        ver.push_back(num - prev);
        prev= num;
    }
    ver.push_back(A - prev);
    temp.clear();
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        temp.push_back(num);
    }
    sort(begin(temp), end(temp));
    prev = 0;
    for(int i = 0; i < M; i++){
        int num = temp[i];
        hor.push_back(num - prev);
        prev= num;
    }
    hor.push_back(B - prev);

    for(int i = 0; i < MAXNODE; i++){
        uf[i] = i;
    }

    sort(begin(ver), end(ver));
    sort(begin(hor), end(hor));

    long long ans = 0;
    M++, N++;

    for(int vi = 0, hi = 0; vi < N || hi < M;){
        if(hi == M || (vi < N && ver[vi] < hor[hi])){
            for(int i = 0; i +1 < M; i++){
                if(merge(ind(vi, i), ind(vi, i+1)))
                    ans += ver[vi];
            }
            vi++;
        }else {
            for(int i = 0; i +1 < N; i++){
                if(merge(ind(i, hi), ind(i+1, hi)))
                    ans += hor[hi];
            }
            hi++;
        }
    }

    cout << ans << endl;
}
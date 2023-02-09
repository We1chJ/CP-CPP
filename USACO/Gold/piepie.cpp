#include "bits/stdc++.h"

using namespace std;
int A[200000], B[200000];
int dis[200000];
struct cmpA{
    bool operator()(int a, int b)const{
        return B[a] < B[b];
    }
};
struct cmpB{
    bool operator()(int a, int b)const{
        return A[a] < A[b];
    }
};
int n, d;

multiset<int, cmpA> sA;
multiset<int, cmpB> sB;

int que[200000];
int cur, len;

int main(){
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> d;
    for(int i =0 ; i < 2*n; i++){
        cin >> A[i] >> B[i];
        A[i] = -A[i];
        B[i] = -B[i];
        dis[i] = -1;
    }
    for(int i =0; i < n; i++){
        if(B[i] == 0)
            que[len++] = i, dis[i] = 1;
        else
            sA.insert(i);
        if(A[n+i] == 0)
            que[len++] = n+i, dis[n+i] = 1;
        else 
            sB.insert(n+i);
    }

    multiset<int, cmpA>::iterator itA;
    multiset<int, cmpB>::iterator itB;
    while(cur < len){
        int i = que[cur];
        if(i < n){
            while(1){
                itB = sB.lower_bound(i);
                if(itB == sB.end() || A[*itB] > A[i] + d)
                    break;
                dis[*itB] = dis[i] + 1;
                que[len++] = *itB;
                sB.erase(itB);
            }
        }else{
            while(1){
                itA = sA.lower_bound(i);
                if(itA == sA.end() || B[*itA] > B[i] + d)
                    break;
                    dis[*itA] = dis[i] + 1;
                    que[len++] = *itA;
                    sA.erase(itA);
            }
        }
        cur++;
    }

    for(int i = 0; i < n; i++)
        cout << dis[i] << endl;

}
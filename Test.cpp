#include "bits/stdc++.h"

using namespace std;
int cow[] = {2,1,4,-5,6};
auto compare = [](int a, int b){
    return cow[a] > cow[b];
};
int main(){
     
    priority_queue<int, vector<int>, decltype(compare) > pq(compare);
    for(int i = 0 ; i < 5; i++)
        pq.push(i);

    for(int i = 0; i < 5; i ++){
        cout << cow[pq.top()] << endl;
        pq.pop();
    }

}
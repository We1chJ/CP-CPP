#include "bits/stdc++.h"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int minX = 100, maxX = -1;
        int minY = 100, maxY = -1;
        int total = 0;
        for(int i = 0; i < n;i++){
            string str;
            cin >> str;
            for(int j = 0; j < n; j++){
                if(str[j] == '1'){
                    minX = min(minX, j);
                    minY = min(minY, i);
                    maxX = max(maxX, j);
                    maxY = max(maxY, i);
                    total ++;
                }
            }
        }
        
        int height = maxY - minY + 1;
        int width = maxX - minX + 1 ;
        
        if(total == height*(height+1)-height && width == height*2-1)
            cout << "TRIANGLE" << endl;
        else if(total == height*width && height == width)
            cout << "SQUARE" << endl;
        else 
            cout << -1 << endl;
    }
}
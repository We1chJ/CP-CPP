#include "bits/stdc++.h"

using namespace std;

int T, n;

int light;
int switches;

int ans;

void toggleSwtichBit(int pos){
    switches ^= (1 << pos);
}

void updateLight(){
    light ^= switches;
}

void shiftSwitch(){
    switches = (switches >> 1) + (switches & 1) * (1 << (n-1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> n;

    while(T--){
        string s1, s2;
        cin >> s1 >> s2;
        light = stoi(s1, 0, 2);
        switches = stoi(s2, 0, 2);
        ans = 0;

        while(light != 0){
            if(light == switches){
                // toggle right most 1 bit
                switches ^= switches & (-switches);
            }else{
                int lbit = 31 - __builtin_clz(light ^ switches);
                toggleSwtichBit(lbit);
            }
            updateLight();
            shiftSwitch();
            ans ++;
        }

        cout << ans << endl;
    }
    
}

/*
S_light
S_switch

To Win:
S_switch differs from S_light only by 1 bit
Check this before operation 1

Operation: O(1)
1. S_switch - 2^x
2. result for S_light == S_light ^ (XOR) S_switch
3. S_switch >> 1 and then add the last bit to the front 
============================

greedy:
always toggle the leftmost bit on the switch that is different from the bit from the light
when they are the same, toggle the rightmost bit that is 1

============================


======================================
Have the switch sequence matches the light sequence

Either go to 000000 for switch first and then to lights, 

or directly to light
    - all the switches have to match the light at the same time in the next cycle of move

- 110100... about the transition 10, 01, 11, 00 difference

110 001
----------
1.
110 000
+ 3
==4

2. 
110 101 -> 011 110
011 111 -> 100 111
100 110 -> 010 011
010 010 
===4

3.
110 001 orignal
110 101 -> 011 110
011 010 -> 001 001


========================
110 011
--------
1. 
110 010 -> 100 001
100 000 
100 100
=====3

2.
110 001 -> 111 100
111 110 -> 001 011
001 001
=====3



*/
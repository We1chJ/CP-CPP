#include "bits/stdc++.h"

using namespace std;
using ll = long long;
struct Node
{
    ll cost = 0;
    bool TF = false;
    int len = 0;
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    string rootLetter;
    cin >> rootLetter;

    vector<vector<Node>> tree;
    int nextrow = 1;

    for (int i = 0; i < n; i++)
    {
        vector<Node> v;
        int cnt = 0;
        for (int j = 0; j < nextrow; j++)
        {
            string c;
            cin >> c;
            Node node;
            if (c == "T" || c == "F")
            {
                node.TF = (c == "T");
                node.len = 0;
                node.cost = 1;
            }
            else
            {
                node.len = stoi(c);
                node.cost = LLONG_MAX;
                cnt += node.len;
            }
            v.push_back(node);
        }
        nextrow = cnt;
        tree.push_back(v);
    }
    
    // computing answers

    for (int i = n - 2; i >= 0; i--)
    {
        vector<Node> &curRow = tree[i];
        vector<Node> &nextRow = tree[i + 1];

        bool isAnd;
        if ((i + 1) % 2 == 1)
        { // odd level
            isAnd = (rootLetter == "A");
        }
        else
        { // even level
            isAnd = !(rootLetter == "A");
        }

        int nextRowInd = 0;
        for (int j = 0; j < curRow.size(); j++)
        {
            // if its a number
            if (curRow[j].len > 0)
            {
                bool curVal = nextRow[nextRowInd].TF;

                for (int t = 0; t < curRow[j].len; t++)
                {
                    if (isAnd)
                    {
                        curVal &= nextRow[t + nextRowInd].TF;
                    }
                    else
                    {
                        curVal |= nextRow[t + nextRowInd].TF;
                    }
                }

                // cerr << "curVal: " << (curVal ? "true" : "false") << '\n';

                ll cost = LLONG_MAX;
                if (isAnd)
                {
                    for (int t = 0; t < curRow[j].len; t++)
                    {
                        if (curVal)
                        { // AND T->F
                            if (nextRow[t + nextRowInd].TF)
                                cost = min(cost, nextRow[t + nextRowInd].cost);
                        }
                        else
                        { // AND F->T
                            if (nextRow[t + nextRowInd].TF == false){
                                if(cost == LLONG_MAX){
                                    cost = 0;
                                }
                                cost += (nextRow[t + nextRowInd].cost);
                            }
                        }
                    }
                }
                else
                {
                    for (int t = 0; t < curRow[j].len; t++)
                    {
                        if (curVal)
                        { // OR T->F
                            if (nextRow[t + nextRowInd].TF){
                                if(cost == LLONG_MAX){
                                    cost = 0;
                                }
                                cost += nextRow[t + nextRowInd].cost;
                            }
                        }
                        else
                        { // OR F->T
                            if (nextRow[t + nextRowInd].TF == false)
                                cost = min(cost, nextRow[t + nextRowInd].cost);
                        }
                    }
                }
                curRow[j].cost = cost;
                curRow[j].TF = curVal;
                nextRowInd += curRow[j].len;
            }
        }
    }

    cout << tree[0][0].cost << endl;
}

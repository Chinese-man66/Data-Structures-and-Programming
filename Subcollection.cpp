#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class SubCollection
{
private:
    vector<int> subres;
public:
    SubCollection()
    {
        subres.clear();
    }

    void findSubCollection(vector<int> &Candidates, int target, int index)
    {
        if(target == 0)

        {
            for(auto it : subres)
                cout << it << " ";
            cout << endl;
            return;     
        }
        else if(index > Candidates.size() || target < 0)
            return;
        else
        {     
            findSubCollection(Candidates, target, index + 1);
            subres.push_back(Candidates[index]);
            findSubCollection(Candidates, target - Candidates[index], index + 1);
            subres.pop_back();
        }
    }
};

int main()
{
    cout << "2125120058 申顺琦" << endl;
    vector<int> Candidates = {1, 2, 3, 4, 5, 6, 7};
    int target = 10; 

    SubCollection sc;
    sc.findSubCollection(Candidates, target, 0);

    return 0;
}
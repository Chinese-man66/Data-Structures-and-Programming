#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Activity
{
public:
    Activity(int s, int e, int i) : start(s), end(e), index(i){}
    int start;
    int end;
    int index;
};

class ActivitiesChoes
{
public:
    ActivitiesChoes(vector<Activity>& v) : vec(v){}
    vector<int> solve(vector<Activity> vec)
    {
        vector<int> res;
        
        sort(vec.begin(), vec.end(), [](Activity a, Activity b)
        {
            return a.end < b.end;
        });
        res.push_back(vec[0].index);
        for(int i = 1; i < vec.size(); i++)
        {
            if(vec[i].start >= vec[res.back()].end)
                res.push_back(vec[i].index);
        }
        return res;
    }
private:
    vector<Activity> vec;
};

int main()
{
    cout << "2125120058申顺琦" << endl;

    vector<Activity> act = {
        {1, 4, 1}, {3, 5, 2}, {0, 6, 3}, {5, 7, 4}, {3, 8, 5},
        {5, 9, 6}, {6, 10, 7}, {8, 11, 8}, {8, 12, 9}, {2, 13, 10}, {12, 14, 11}
    };
    ActivitiesChoes ac(act);
    vector<int> res = ac.solve(act);

    for(auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
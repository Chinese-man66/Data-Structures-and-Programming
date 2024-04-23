#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Goods
{

public:
    Goods(){}

    Goods(int weight, int value) : _weight(weight) , _value(value) {}

    int getWeight() 
    {
        return this->_weight;
    }

    int getValue()
    {
        return this->_value;
    }

private:
    int _weight;
    int _value;
};

class Greedy
{
public:
    void greedySolve(vector<Goods> &vec, int cap)
    {
        int temp = cap;
        int index = 0, value = 0;
        sort(vec.begin(), vec.end(), [](Goods a, Goods b)
        {
            return 1.0*(a.getValue()/a.getWeight()) > 1.0*(b.getValue()/b.getWeight());
        });
        while(cap > 0)
        {
            if(cap > vec[index].getWeight())
            {
                cap -= vec[index].getWeight();
                cout << "商品: "  << index << " 商品价值: " << vec[index].getValue() << " 放入比率 : 1 " << endl;
                value += vec[index].getValue();
                index++;
                continue;
            }

            cout << "商品: "  << index << " 商品价值: " << vec[index].getValue() << " 放入比率 : " << 1.0 * cap / vec[index].getWeight() << endl;
            value += (1.0 * cap / vec[index].getWeight()) * vec[index].getValue();
            cap = 0;
        }
        cout << "背包内商品总价值 : " << value << endl;
    }
};

int main()
{
    cout << "2125120058 申顺琦 " << endl;

    int cap = 50;
    Goods a(20, 60);
    Goods b(30, 120);
    Goods c(10, 50);

    vector<Goods> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);

    Greedy g;
    g.greedySolve(vec, cap);
    return 0;
}

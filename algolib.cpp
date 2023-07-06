#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto isGreaterThan(int amount)
{
    return [amount](int value)
    {
        return value > amount;
    };
}
int main(void)
{
    vector<int> v = {1, 2, 3, 3, 5};
    vector<int> copyVector(5);
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());

    if (it != v.end())
        cout << "First occurrence of consecutive identical element = " << *it << endl;

    v[3] = 4;

    it = adjacent_find(v.begin(), v.end());

    if (it == v.end())
        cout << "There are no cosecutive identical elemens" << endl;

    if (any_of(v.begin(), v.end(), isGreaterThan(4)))
    {
        cout << "There are values greater than 4" << endl;
    }

    copy_if(v.begin(), v.end(), copyVector.begin(), isGreaterThan(3));
    for_each(copyVector.begin(), copyVector.end(), [](int value)
             { cout << value << ", "; });

    return 0;
}
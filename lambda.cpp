/* Dynamic Programming C/C++ implementation of LCS problem */
#include <iostream>
#include <vector>
#include <functional>

auto getIncreaseLambda(float increaseAmount)
{
    return [increaseAmount](float &item)
    { item += increaseAmount; };
}

int transformToInt(float x)
{
    return (int)x;
}

int main()
{
    int n = 20;

    std::vector<float> array(n);

    std::fill(array.begin(), array.end(), 1.0f);

    std::for_each(array.begin(), array.end(), getIncreaseLambda(1.5f));

   
    std::for_each(array.begin(), array.end(), [](float &item)
                  { printf("%.1f, ", item); });

    std::transform(array.begin(), array.end(), array.begin(), transformToInt);

    std::for_each(array.begin(), array.end(), [](float &item)
                  { printf("%.1f, ", item); });
    return 0;
}
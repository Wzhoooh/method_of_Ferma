#include <iostream>
#include <set>
#include <queue>
#include <exception>
#include <cmath>

int64_t nevFunction(int64_t& n, int64_t& a, int64_t& b)
{
    return n - (a-b)*(a+b);
}

std::multiset<int64_t> methodFerma(int64_t&& number)
{
    if (number % 2 == 0)
        throw new std::runtime_error("parity number");

    std::multiset<int64_t> result;
    result.insert(number);
    result.insert(1);

    std::queue<int64_t> nQue;
    nQue.push(number);

    while (!nQue.empty())
    {
        int64_t recentNumber = nQue.front();
        nQue.pop();
        int64_t a = (int64_t)std::sqrt((long double)recentNumber), b = 0;

        while (nevFunction(recentNumber, a, b) != 0)
        {
            if (nevFunction(recentNumber, a, b) > 0) a++;
            else b++;
        }

        int64_t firstDevider = a-b, secondDevider = a+b;
        if (firstDevider == 1)
            result.insert(secondDevider);
        else
        {
            nQue.push(firstDevider);
            nQue.push(secondDevider);
        }
    }
    return result;
}

int main()
{
    std::multiset<int64_t> deviders = methodFerma(63098587303949);
    for(auto i : deviders)
        std::cout << i << " ";
}

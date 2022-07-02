#include <iostream>
using namespace std;

int solution(int n)
{
    int dist[4] = { 0, 1, 1, 2 };

    int rest = 0;
    while (n > 3)
    {
        if (n % 2 == 1) ++rest;

        n /= 2;
    }

    int ans = dist[n] + rest;

    return ans;
}
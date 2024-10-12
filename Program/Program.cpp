#include <iostream>
#include <cmath>
#include <vector>

const double PI = 3.141592654;

std::vector<double> dct(std::vector<int> data)
{
    double f, s;
    int k, n;
    int N = data.size();
    std::vector<double> cof(N);

    for (k = 0; k < N; k++)
    {
        if (k == 0)
        {
            f = 1 / std::sqrt(4 * N);
        }
        else
        {
            f = 1 / std::sqrt(2 * N);
        }

        s = 0;
        for (n = 0; n < N; n++)
        {
            s += data[n] * std::cos(PI * k * (2 * n + 1) / (2 * N));
        }

        cof[k] = 2 * f * s;
    }

    return cof;
}

void print(std::vector<double> input)
{
    for (auto i : input)
    {
        std::cout << i << " ";
    }
}

int main()
{
    std::vector<int> data = {1, 2, 3, 4};
    int N = data.size();
    std::vector<double> output = dct(data);
    print(output);

    return 0;
}
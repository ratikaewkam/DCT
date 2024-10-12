#include <iostream>
#include <cmath>

const double PI = 3.141592654;

void dct(int data[], double cof[], int N)
{
    double f, s;
    int k, n;

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
}

int main()
{
    int data[] = {1, 2, 3, 4};
    int N = sizeof(data) / sizeof(data[0]);
    double *output = new double[N];

    dct(data, output, N);

    // Print cof
    int i;
    for (i = 0; i < N; i++)
    {
        std::cout << output[i] << " ";
    }

    return 0;
}
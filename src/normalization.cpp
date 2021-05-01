#include <limits>
#include <iostream>
#include <float.h>
#include <vector>

using namespace std;

// inputが1次元の場合
void normalized(vector<double> &input)
{
    double max = -FLT_MAX, min = FLT_MAX;
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (max < input[i])
            max = input[i];
        if (min > input[i])
            min = input[i];
    }
    double den = max - min;
    for (size_t i = 0; i < input.size(); ++i)
        input[i] = (input[i] - min) / den;
}

// inputが多次元の場合
void vecNormalized(vector<vector<double>> &input)
{
    size_t dimention = input[0].size(); //次元数
    vector<double> max(dimention, -FLT_MAX), min(dimention, FLT_MAX);
    for (size_t i = 0; i < input.size(); ++i)
    {
        for (size_t j = 0; j < dimention; ++j)
        {
            if (max[j] < input[i][j])
                max[j] = input[i][j];
            if (min[j] > input[i][j])
                min[j] = input[i][j];
        }
    }
    for (size_t j = 0; j < dimention; ++j)
    {
        double den = max[j] - min[j];
        for (size_t i = 0; i < input.size(); ++i)
            input[i][j] = (input[i][j] - min[j]) / den;
    }
}

int main()
{
    vector<double> test1 = {0, 2, 0.4, -10, 3, 10};
    normalized(test1);
    for (double d : test1)
    {
        cout << d << ", ";
    }
    cout << endl;
    /* result
        0.5, 0.6, 0.52, 0, 0.65, 1, 
    */
    vector<vector<double>> test2 = {{2, 1, 5},
                                    {3, 5.9, 6},
                                    {7, 3, -10}};
    vecNormalized(test2);
    for (vector<double> vd : test2)
    {
        for (double d : vd)
        {
            cout << d << ", ";
        }
        cout << endl;
    }
    /*result
        0, 0, 0.9375,
        0.2, 1, 1,
        1, 0.408163, 0,
    */
    return 0;
}
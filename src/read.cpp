#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void read(string datafilePath, vector<vector<string>> &result)
{
    ifstream ifs(datafilePath);
    if (ifs.fail())
    {
        cerr << "Failed to open file : " << datafilePath << endl;
        exit(1);
    }
    string line;
    result.clear();
    while (getline(ifs, line))
    {
        replace(line.begin(), line.end(), ',', ' '); // 区切り文字','の設定
        istringstream iss(line);
        vector<string> tokens;
        string str;
        while (iss >> str)
            tokens.push_back(str);
        // もし，文字列以外で受け取るなら(下はdoubleで受け取る例)
        // while (iss >> str)
        //     tokens.push_back(atof(str.c_str()));
        result.push_back(tokens);
    }
}

int main()
{
    string testDataPath;
    testDataPath = "../data/readTest1.dat";
    // testDataPath = "../data/readTest2.dat";

    cout << "reading data is " << testDataPath << endl;
    vector<vector<string>> data;
    read(testDataPath, data);
    for (vector<string> token : data)
    {
        for (string val : token)
            cout << val << ",";
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
int main()
{
    int N;
    cin >> N;

    vector<vector<int>> Y(N);
    vector<int> X(N);

    int token;
    for (int i = 0; i < N; i++)
    {
        for (int n = 0; n < N; n++)
            cin >> X.at(n);
        Y.at(i) = X;
    }
    for (int i = 0; i < N; i++)
    {
        for (int n = 0; n < N; n++)
        {
            cout << Y.at(i).at(n) << " ";
        }
    }

    return 0;
}
int move(int y, int x, vector<vector<int>> &Y, vector<int> &X){
    Y + y;
    X + x;
}

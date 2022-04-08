#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> factor(int n)
{
    if (n == 1)
        return vector<int>(1, 1); // n=1인 경우에는 예외로 한다.
    vector<int> ret;
    for (int div = 2; n > 1; ++div)
        while (n % div == 0)
        {
            n /= div;
            ret.push_back(div);
            factor(n);
        }
    return ret;
}

int main(void)
{
    int n;
    vector<int> fac;
    cin >> n;
    fac = factor(n);

    for (int t : fac)
    {
        cout << t << endl;
    }

    return 0;
}

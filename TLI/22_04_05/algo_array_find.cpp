#include <iostream>
#include <string>
#include <vector>

using namespace std;

int firstIndex(const vector<int> &array, int element) // array[i] =element인 첫 i를 반환한다. 만약 일치하는 값이 없으면 -1을 반환한다.
{
    for (int i = 0; i < array.size(); i++)
        if (array[i] == element)
            return i;
    return -1;
}
int main(void)
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element, result;
    cin >> element;
    result = firstIndex(array, element);

    cout << "element 값은 : " << element << endl;
    cout << element << "는 array " << result << "번 째에 있습니다. ";
    return 0;
}
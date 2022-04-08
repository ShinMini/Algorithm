#include <iostream>
#include <vector>

using namespace std;
void selectionSort(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < A.size(); ++j)
        {
            if (A[minIndex] > A[j])
                minIndex = j;
            swap(A[i], A[minIndex]);
        }
    }
}

void insertionSort(vector<int> &B)
{
    for (int i = 0; i < B.size(); ++i)
    {
        // B[0..i-1]에 B[i]를 끼워넣음.
        int j = i;
        while (j > 0 && B[j - 1] > B[j]) // B[j -1] > B[j]를 만족할 때까지 반복해야한다.
        {                                // 따라서 초기 입력값에 따라 비교횟수가 달라진다.
            swap(B[j - 1], B[j]);
            --j; // j를 하나 줄여서 다시 반복.
        }
    }
}

int main(void)
{
    vector<int> A = {1, 9, 4, 2, 6, 7, 3};
    vector<int> B = {2, 1, 5, 3, 7, 8, 4};
    selectionSort(A); // 선택정렬 알고리즘.
    insertionSort(B); // 삽입정렬 알고리즘.

    cout << "sorted A : ";
    for (int i : A)
        cout << i << " ";
    cout << "\n----------------\n";
    cout << "sorted B : ";
    for (int i : B)
        cout << i << " ";
    return 0;
}
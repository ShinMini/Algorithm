#include <iostream>
#include <vector>

using namespace std;

const int MIN = numeric_limits<int>::min();
// A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도 : O(N^3)
int inefficientMaxSum(const vector<int> &A) // 비효율적인 알고리즘.
{
    int N = A.size(), ret = MIN;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        { // 구간 A[i, j]의 합을 구한다.
            int sum = 0;
            for (int k = i; k <= j; ++k)
                sum += A[k];
            ret = max(ret, sum);
        }
    return ret;
}

// a[]의 연속된 부분 구간의 최대 합을 구한다. 시간복잡도: O(N^2)
int betterMaxSum(const vector<int> &A)
{
    int N = A.size(), ret = MIN;
    for (int i = 0; i < N; ++i)
    {
        int sum = 0;
        for (int j = 0; j < N; ++j)
        { // 구간 A[i, j]의 합을 구한다.
            sum += A[j];
            ret = max(ret, sum);
        }
    }
    return ret;
}

// 최대 연속 부분 구간의 최대 합을 구하는 시간복잡도 O(nlgn)인 알고리즘 예시.
// A[lo..hi]의 연속된 부분 구간의 최대 합을 구한다. 시간복잡도 : O(nlgn)
int fastMaxSum(const vector<int> &A, int lo, int hi)
{
    // 기저 사례: 구간의 길이가 1일 경우,
    if (lo == hi)
        return A[lo];
    // 배열을 A[lo..mid], A[mid+1..hi]의 두 조각을 분할.
    int mid = (lo + hi) / 2;
    // 두 부분에 모두 걸쳐 있는 최대 합 구간을 찾는다. 이 구간은
    // A[i..mid]와 A[mid+1..j]형태를 갖는 구간의 합으로 이루어진다.
    // A[i..mid] 형태를 갖는 최대 구간을 찾는다.
    int left = MIN, right = MIN, sum = 0;
    for (int i = mid; i >= lo; --i)
    {
        sum += A[i];
        left = max(left, sum);
    }
    // A[mid+1..j]형태를 갖는 최대 구간을 찾는다.
    sum = 0;
    for (int j = mid + 1; j <= hi; ++j)
    {
        sum += A[j];
        right = max(right, sum);
    }
    // 최대 구간이 두 조각 중 하나에만 속해 있는 경우의 답을 재귀 호출로 찾는다.
    int single = max(fastMaxSum(A, lo, mid),
                     fastMaxSum(A, mid + 1, hi));
    // 두 경우 중 최대치를 반환한다.
    return max(left + right, single);
}

/* 마지막으로 이 문제를 선형 시간에 푸는 방법을 동적 계획 법을 사용해 풀이하는 경우,
A[i]를 오른쪽 끝으로 갖는 구간의 최대 합을 반환하는 함수 maxAt(i)를 정의해 보자.

이때, A[i]에서 끝나는 최대 합 부분 구간은 항상 A[i]하나만으로 구성되어 있거나, A[i-1]를 오른쪽 끝으로 갖는
최대 합 부분 구간의 오른쪽에 A[i]를 형태로 되어 있음을 증명할 수 있다.
따라서 maxAt()을 다음과 같은 점화식으로 표현할 수 있다.
maxAt(i) = max(0, maxAt(i-1)) + A[i]
위 식을 반복적 동적 계획 법으로 구현하면, 아래와 같다.  */
// A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도: O(n) 
int fastestMaxSum(const vector<int> & A) {
    int N = A.size(), ret = MIN, psum = 0;
    for(int i=0; i<N; ++i) {
        psum = max(psum, 0) + A[i];
        ret = max(psum, ret);
    }
    return ret;
}// 와 진짜 깔끔하게 코드 구현을 잘하는구나.
// 특히 인상깊었던 부분은, 변수 선언 부이다. 
// for문의 반복용 변수를 제외하고(이마저도 가장 대표적인, i, j를 사용한다.)
// 모든 변수가 각자 맡은 역할을 분명히 나타내고 있고, 함수 또한 예외가 아니다. 
// 또한 코드 길이를 줄이기 위해, for문 의 중괄호를 최소화하고, 변수 선언 시 같은 type을 쉼표로 구분해 선언하며
// 가독성을 높힌 것 또한 아름다웠다. 

int main(void)
{
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int blueHole(int x, int y, vector<int> &hole, vector<int> &firstBlue, vector<int> &red, vector<vector<int>> &DotPoint);
bool calDistance(int i, vector<char> &totalMoving, vector<int> &red, vector<int> &hole, vector<int> &Dot, vector<vector<int>> &DotPoint);

int main()
{

    size_t N, M;
    int dotCount = 0;
    cin >> N >> M;
    char input;
    vector<vector<char>> Point_Y(N); // 세로
    vector<char> Point_X(M);         // 가로

    vector<char> totalMoving(N * M, 'A');

    vector<int> red = {0, 0};
    vector<int> blue = {0, 0};
    vector<int> hole = {0, 0};
    vector<int> init_red(red);
    vector<int> init_blue(blue);
    vector<int> init_hole(hole);
    for (int i = 0; i < N; i++)
    {
        for (int t = 0; t < M; t++)
        {
            cin >> input;
            if (input == '.')
                dotCount++;
            Point_X.at(t) = input;
        }
        Point_Y.at(i) = Point_X;
    }

    vector<vector<int>> DotPoint(dotCount);
    vector<int> Dot = {0, 0};

    vector<vector<int>> init_DotPoint(dotCount);
    int u = 0, loopCount = 0;
    vector<string> shortest(dotCount);
    char Direction = 'A';
    int movingCount = 0;

    vector<int> firstBlue(2);
    firstBlue.at(0) = blue.at(0);
    firstBlue.at(1) = blue.at(1);

    dotCount = 0;
    for (int i = 0; i < N; i++)
    {
        for (int t = 0; t < M; t++)
        {
            if (Point_Y[i][t] == 'R')
            {
                red[0] = i;
                red[1] = t;
            }
            if (Point_Y[i][t] == 'B')
            {
                blue[0] = i;
                blue[1] = t;
            }
            if (Point_Y[i][t] == 'O')
            {
                hole[0] = i;
                hole[1] = t;
            }
            if (Point_Y[i][t] == '.')
            {
                Dot[0] = i;
                Dot[1] = t;
                DotPoint.at(dotCount) = Dot;
                init_DotPoint.at(dotCount) = Dot;
                dotCount++;
            }
        }
    }

    // cout << "RED Point =>" << red[0] << ", " << red[1] << "\n";
    // cout << "BLUE Point =>" << blue[0] << ", " << blue[1] << "\n";
    // cout << "HOLE Point =>" << hole[0] << ", " << hole[1] << "\n";
    // 만약, red, blue, hole 의 위치가 일직선 상에 놓여있고, blue와 red사이의 장애물이 없다면,
    // -1을 print한뒤, 종료.

    int blueissue = 0;
    // blue 좌, 우측과 hole이, dot과 red를 포함한 지점과 일치하는지 찾아봐야함./ // 먼저 좌측부터 ,
    if (red.at(0) == hole.at(0) && blue.at(0) == red.at(0))
    {                                                         // x축이 같은 경우
        if (blue.at(1) < red.at(1) && red.at(1) < hole.at(1)) // y축이 파랑, 빨강, 구멍 순으로 있는 경우,
            blueissue = blueHole(0, 1, red, hole, firstBlue, DotPoint);

        if (blue.at(1) > red.at(1) && red.at(1) > hole.at(1)) // y축이 구멍, 빨강, 파랑 순으로 있는 경우,
            blueissue = blueHole(0, -1, red, hole, firstBlue, DotPoint);
    }

    if (red.at(1) == hole.at(1) && blue.at(1) == red.at(1))
    {                                                         // x축이 같은 경우
        if (blue.at(0) < red.at(0) && red.at(0) < hole.at(0)) // x축이 파랑, 빨강, 구멍 순으로 있는 경우,
            blueissue = blueHole(1, 0, red, hole, firstBlue, DotPoint);

        if (blue.at(0) > red.at(0) && red.at(0) > hole.at(0)) // x축이 구멍, 빨강, 파랑 순으로 있는 경우,
            blueissue = blueHole(-1, 0, red, hole, firstBlue, DotPoint);
    }
    bool whilecontinue = true;
    if (blueissue == 1)
    {
        cout << -1 << endl;
        whilecontinue = false;
        return 0;
    }

    init_red.at(0) = red.at(0);
    init_red.at(1) = red.at(1);
    init_blue.at(0) = blue.at(0);
    init_blue.at(1) = blue.at(1);
    init_hole.at(0) = hole.at(0);
    init_hole.at(1) = hole.at(1);

    while (whilecontinue)
    {
        if (calDistance(u, totalMoving, red, hole, Dot, DotPoint))
            break;
        else if (u + 1 == DotPoint.size())
        {
            u = 0;
            loopCount++;
            calDistance(u, totalMoving, red, hole, Dot, DotPoint);
        }
        else if (loopCount == dotCount)
        {                  // 일정 횟수 이상 반복할 경우,
            loopCount = 0; // 카운트 초기화 및
            // 마지막 레드 좌표지점 삭제, (없는 길 취급)
            for (int k = 0; k < init_DotPoint.size(); k++)
            {
                if (red[0] == init_DotPoint.at(k)[0] && red[1] == init_DotPoint.at(k)[1])
                {
                    init_DotPoint.at(k).at(0) = -1;
                    init_DotPoint.at(k).at(1) = -1;
                }
            }

            for (int c = 0; c < init_DotPoint.size(); c++)
            {
                DotPoint.at(c).at(0) = init_DotPoint.at(c).at(0);
                DotPoint.at(c).at(1) = init_DotPoint.at(c).at(1);
            }
            red.at(0) = init_red.at(0);
            red.at(1) = init_red.at(1);
            u = 0;
            for (int k = 0; k < totalMoving.size(); k++)
            {
                totalMoving.at(k) = 'A';
            }
            calDistance(u, totalMoving, red, hole, Dot, DotPoint);
        }
        u++;
    }

    for (int i = 0; i < totalMoving.size(); i++)
    {
        if (Direction != totalMoving.at(i))
        {
            movingCount++;
        }
        Direction = totalMoving.at(i);
    }

    if (movingCount > 10)
        cout << -1 << endl;
    else
        cout << movingCount << endl;

    return 0;
}

bool calDistance(int i, vector<char> &totalMoving, vector<int> &red, vector<int> &hole, vector<int> &Dot, vector<vector<int>> &DotPoint)
{
    // 0-> Y축, 1 -> X축

    // 도착시
    if ((red.at(0) - hole.at(0)) == 0 && (red.at(1) - hole.at(1)) == 1)
    {
        totalMoving.push_back('x');
        return true;
    }
    if ((red.at(0) - hole.at(0)) == 0 && (red.at(1) - hole.at(1)) == -1)
    {
        totalMoving.push_back('X');
        return true;
    }
    if ((red.at(0) - hole.at(0)) == 1 && (red.at(1) - hole.at(1)) == 0)
    {
        totalMoving.push_back('y');
        return true;
    }
    if ((red.at(0) - hole.at(0)) == -1 && (red.at(1) - hole.at(1)) == 0)
    {
        totalMoving.push_back('Y');
        return true;
    }

    if ((red.at(0) - DotPoint.at(i)[0]) == 0 && (red.at(1) - DotPoint.at(i)[1]) == 1)
    {
        // X축으로 -1만큼 이동 가능
        if (totalMoving.back() != 'X')
        {
            red.at(0) = DotPoint.at(i)[0];
            red.at(1) = DotPoint.at(i)[1];
            totalMoving.push_back('x');
            calDistance(0, totalMoving, red, hole, Dot, DotPoint);
            // cout << "red moved left: " << red.at(0) << ", " << red.at(1) << "\n";
        }
    }
    if ((red.at(0) - DotPoint.at(i)[0]) == 0 && (red.at(1) - DotPoint.at(i)[1]) == -1)
    {
        if (totalMoving.back() != 'x')
        {
            // X축으로 +1만큼 이동 가능
            red.at(0) = DotPoint.at(i)[0];
            red.at(1) = DotPoint.at(i)[1];
            totalMoving.push_back('X');
            calDistance(0, totalMoving, red, hole, Dot, DotPoint);
            // cout << "red moved right: " << red.at(0) << ", " << red.at(1) << "\n";
        }
    }
    // 한칸 아래로 이동
    if ((red.at(0) - DotPoint.at(i)[0]) == 1 && (red.at(1) - DotPoint.at(i)[1]) == 0)
    {
        if (totalMoving.back() != 'Y')
        {
            red.at(0) = DotPoint.at(i)[0];
            red.at(1) = DotPoint.at(i)[1];
            totalMoving.push_back('y');
            calDistance(0, totalMoving, red, hole, Dot, DotPoint);
            // cout << "red moved top: " << red.at(0) << ", " << red.at(1) << "\n";
        }
    }
    // 한칸 위로 이동
    if ((red.at(0) - DotPoint.at(i)[0]) == -1 && (red.at(1) - DotPoint.at(i)[1]) == 0)
    {
        if (totalMoving.back() != 'y')
        {
            red.at(0) = DotPoint.at(i)[0];
            red.at(1) = DotPoint.at(i)[1];
            totalMoving.push_back('Y');
            calDistance(0, totalMoving, red, hole, Dot, DotPoint);
            // cout << "red moved bottom: " << red.at(0) << ", " << red.at(1) << "\n";
        }
    }

    // if ((fabs(red.at(0) - Dot.at(0)) + fabs(red.at(1) - Dot.at(1))) == 1)
    //  {
    //  cout << Dot.at(0) << ", " << Dot.at(1) << "\n";
    // }
    // 만일 세번 반복했는데 못찾았을 경우,
    // 마지막 선택지를 지우고 다시 반복하자.
    // 먼저 최단거리부터 구하고 계산하자 그러면
    // 그냥 여러번 계산한 뒤에 가장 최단거리 값을 출력하는 방향으로 해보자.
    // red의 시작점, hole의 도착지점, 중간까지의  dot최단거리.

    return false;
}

// ex) blueHole(0, 1, hole, firstBlue, DotPoint)// x좌표가 동일하고, y좌표가 +1된 곳으로 이동.
int blueHole(int x, int y, vector<int> &hole, vector<int> &firstBlue, vector<int> &red, vector<vector<int>> &DotPoint)
{
    for (int i = 0; i < DotPoint.size(); i++)
    { // 아래방향으로 한칸씩 이동하며 벽이 있는 지확인하자.

        if ((firstBlue.at(0) - DotPoint.at(i).at(0)) == x && (firstBlue.at(1) - DotPoint.at(i).at(1)) == y)
        {
            if (x == 0)
                firstBlue.at(1) = DotPoint.at(i).at(1); // blue 공의 y좌표를 해당 좌표로 옮겨준뒤 계속 진행.,
            if (y == 0)
                firstBlue.at(0) = DotPoint.at(i).at(0); // blue 공의 y좌표를 해당 좌표로 옮겨준뒤 계속 진행.,
            i = 0;                                      // i초기화 이후 재검색.
        }

        if ((firstBlue.at(0) - red.at(0)) == x && (firstBlue.at(1) - red.at(1)) == y) // red point와 blue또한 교환 가능.
        {
            if (x == 0)
                firstBlue.at(1) = red.at(1); // blue 공의 y좌표를 해당 좌표로 옮겨준뒤 계속 진행.,
            if (y == 0)
                firstBlue.at(0) = red.at(0); // blue 공의 y좌표를 해당 좌표로 옮겨준뒤 계속 진행.,
            i = 0;                           // i초기화 이후 재검색.
        }
    }

    // 위에서 탐색 이후 홀과 블루공이 일치하지 않았을 경우, 통과,
    // 하지만 홀과 블루공이 일치했다면, -1 return이후 종료.
    if ((firstBlue.at(0) - hole.at(0)) == x && (firstBlue.at(1) - hole.at(1)) == y) // red point와 blue또한 교환 가능.
        return 1;
    return 0;
}

// 마지막 시도 끝에 원하는 결과는 결국 구하지 못한채 종료되었다. '
/*
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

bool moveBlue(int y, int x, vector<int> blue, vector<int> hole, vector<int> red, vector<vector<int>> Dot_P);
int checkBlue(int y, int x, vector<vector<int>> &Dot_P, vector<int> &blue, vector<int> &hole, int B_result);
bool cal_D(string T_move, vector<int> &red, vector<int> &blue, vector<int> &hole, vector<int> &Dot, vector<vector<int>> &Dot_P, int B_result);
bool Move_P(int y, int x, int i, vector<int> &red, vector<int> &blue, vector<int> &hole, vector<vector<int>> &Dot_P, string T_move, char move, char cant, int B_result);

int main()
{
    size_t N, M;
    cin >> N >> M;
    string T_move;

    vector<int> red(2);
    vector<int> blue(2);
    vector<int> hole(2);

    vector<vector<int>> Dot_P(N * M);

    vector<int> Dot(2);

    string input;
    getline(cin, input);
    int Y_count = 0, DotP_index = 0;
    for (int i = 0; i < N; i++)
    {
        getline(cin, input);

        for (char put : input)
        {
            if (put == 'R')
            {
                red.at(0) = i;
                red.at(1) = Y_count;
                Dot.at(0) = i;
                Dot.at(1) = Y_count;
                Dot_P.at(DotP_index) = Dot;
                DotP_index++;
            }
            if (put == 'B')
            {
                blue.at(0) = i;
                blue.at(1) = Y_count;
            }
            if (put == 'O')
            {
                hole.at(0) = i;
                hole.at(1) = Y_count;
            }
            if (put == '.')
            {
                Dot.at(0) = i;
                Dot.at(1) = Y_count;
                Dot_P.at(DotP_index) = Dot;
                DotP_index++;
            }
            Y_count++;
        }
        Y_count = 0;
    }
    Dot_P.resize(DotP_index);

    vector<int> i_red = red;
    vector<int> i_blue = blue;

    int B_result = 0;
    int loop = 0, LB = 0;
    while (true)
    {
        if (cal_D(T_move, red, blue, hole, Dot, Dot_P, B_result) || LB == 3)
        { // while문 탈출조건
            break;
        }
        if (loop == N + M)
        {             // 일정 횟수 이상 반복할 경우,
            LB++;     // break 조건절 하나 추가
            loop = 0; // 카운트 초기화 및 마지막 레드 좌표지점 삭제, (없는 길 취급)
            for (vector<int> dot : Dot_P)
            {
                loop++; // 변수 재활용좀 할게용
                if (red.at(0) == dot.at(0) && red.at(1) == dot.at(1))
                {
                    Dot_P.at(loop).at(0) = -1;
                    Dot_P.at(loop).at(1) = -1;
                }
            }
            loop = 0;
            // 점 좌표 초기화 작업
            red = i_red;
            blue = i_blue;

            T_move.erase(T_move.begin(), T_move.end());
            cal_D(T_move, red, blue, hole, Dot, Dot_P, B_result);
        }
        loop++;
    }
    int move_Y = 0, move_X = 0;

    char D = T_move.at(0);
    int move_C = 0;
    for (int i = 0; i < T_move.size(); i++)
    {
        if (D != T_move.at(i))
        {
            move_C++;
            D = T_move.at(i);
        }
    }
    if (move_C == 0 || move_C > 10)
        cout << -1;
    else
        cout << move_C;

    return 0;
}
//  if (
//             ((blue.at(0) + x == Dot_P.at(i)[0]) && (blue.at(1) + y == Dot_P.at(i)[1]) || (blue.at(0) + x == hole.at(0)) && (blue.at(1) + y == hole.at(1))) && ((red.at(0) != blue.at(0) + x) && (red.at(1) != blue.at(1) + y)))
//         {
//             blue.at(0) += x;
//             blue.at(1) += y;
//         }
// // int checkBlue(int y, int x, vector<vector<int>> &Dot_P, vector<int> &blue, vector<int> &hole, int B_result)
// {
//     for (vector<int> i : Dot_P)
//     {
//         if (i.at(0) - blue.at(0) == y && i.at(1) - blue.at(1) == x)
//         {
//             blue.at(0) += y;
//             blue.at(1) += x;
//             checkBlue(y, x, Dot_P, blue, hole, B_result);
//         }
//     }
//     if (hole.at(0) - blue.at(0) == y && hole.at(1) - blue.at(1) == x)
//     {
//         B_result = 1;
//     }
//     return B_result;
// }
bool cal_D(string T_move, vector<int> &red, vector<int> &blue, vector<int> &hole, vector<int> &Dot, vector<vector<int>> &Dot_P, int B_result)
{
    for (int i = 0; i < Dot_P.size(); i++)
    {
        if (red.at(0) == hole.at(0) && red.at(1) == hole.at(1))
        { // 도착할 경우. 레드좌표 초기화 이후, 마지막으로 한번 더 돌려줌. blue hole in check
            red.at(0) = -1;
            red.at(1) = -1;
        }
        if (Move_P(1, 0, i, red, blue, hole, Dot_P, T_move, 'x', 'X', B_result))
            i = 0;
        if (Move_P(-1, 0, i, red, blue, hole, Dot_P, T_move, 'X', 'x', B_result))
            i = 0;
        if (Move_P(0, 1, i, red, blue, hole, Dot_P, T_move, 'y', 'Y', B_result))
            i = 0;
        if (Move_P(0, -1, i, red, blue, hole, Dot_P, T_move, 'Y', 'y', B_result))
            i = 0;
        if (red.at(0) == -1 && red.at(1) == -1 && blue.at(0) != hole.at(0) && blue.at(1) != hole.at(1)) // 도착할 경우.
            return true;
    }
    return false;
}
// T_move를 string으로 바꾼뒤 , if(T_move.back() != cant) T_move.push_back() = move; 이런식으로 설정하면 될것같다.

bool moveBlue(int y, int x, vector<int> blue, vector<int> hole, vector<int> red, vector<vector<int>> Dot_P)
{
    for (vector<int> dot : Dot_P)
    {
        if (hole.at(0) == blue.at(0) + y && hole.at(1) == blue.at(1) + x)
            return true;

        if (dot.at(0) == blue.at(0) + x && dot.at(1) == blue.at(1) + y && red.at(0) != blue.at(0) && red.at(1) != blue.at(1))
        {
            blue.at(0) = dot.at(0);
            blue.at(1) = dot.at(1);
            moveBlue(y, x, blue, red, Dot_P);
        }
    }
    return false;
}
bool Move_P(int y, int x, int i, vector<int> &red, vector<int> &blue, vector<int> &hole, vector<vector<int>> &Dot_P, string T_move, char move, char cant, int B_result)
{
    if ((red.at(0) - hole.at(0)) == x && (red.at(1) - hole.at(1)) == y || (red.at(0) - Dot_P.at(i)[0]) == x && (red.at(1) - Dot_P.at(i)[1]) == y && T_move.back() != cant)
    {
        red.at(0) -= x;
        red.at(1) -= y;
        T_move.push_back(move);

        if (T_move.back() == 'y')
            moveBlue(-1, 0, blue, hole, Dot_P);
        if (T_move.back() == 'Y')
            moveBlue(1, 0, blue, hole, Dot_P);
        if (T_move.back() == 'x')
            moveBlue(0, -1, blue, hole, Dot_P);
        if (T_move.back() == 'X')
            moveBlue(0, 1, blue, hole, Dot_P);

        return true;
    }

    return false;
}
*/
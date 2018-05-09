/**************************************************************
    Problem: 2261
    User: wizny8206
    Language: C++
    Result: Success
    Time:253 ms
    Memory:4376 kb
****************************************************************/
 
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
typedef struct _node
{
    int n;
    vector<int> path;
}node;
 
node queue[1001];
bool check[1001];
 
int wp, rp;
 
int N, K;
int A, B;
 
string s[1001];
 
void Enqueue(node n)
{
    queue[wp++] = n;
}
 
node Dequeue()
{
    return queue[rp++];
}
 
bool IsEmpty()
{
    if (wp == rp)
        return false;
 
    return true;
}
 
bool chk(node _n, int idx)
{
    int cnt = 0;
    // 해밍경로가 될 수 있는지 판별
    for (int i = 0; i < K; ++i)
    {
        if (s[_n.n][i] != s[idx][i])
            ++cnt;
    }
 
    // cnt가 1초과면 해밍경로 x
    return cnt > 1 ? false : true;
}
 
vector<int> FindAnswer()
{
    node n = { A };
    // 지금까지의 경로
    n.path.push_back(A);
 
    Enqueue(n);
    // 중복으로 못들어가게 체크
    check[A] = true;
 
    while (IsEmpty())
    {
        n = Dequeue();
        for (int i = 1; i <= N; ++i)
        {
            // 큐에 이미 들어있는 곳? && 해밍경로가 될 수 있는가?
            if (check[i] == false && chk(n, i))
            {
                node temp = { i,n.path };
                // 경로 추가
                temp.path.push_back(i);
 
                if (i == B)
                {
                    // 도착지이면 리턴
                    return temp.path;
                }
 
                Enqueue(temp);
                check[i] = true;
            }
        }
    }
 
    // 답이 없으면 지우고 리턴
    n.path.clear();
    return n.path;
}
 
int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s[i];
    }
 
    cin >> A >> B;
    wp = rp = 0;
 
    vector<int> answer = FindAnswer();
 
    if (answer.size() != 0)
    {
        for(int i = 0; i < answer.size(); ++i)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
        return 0;
    }
 
    cout << "-1" << endl;
 
}
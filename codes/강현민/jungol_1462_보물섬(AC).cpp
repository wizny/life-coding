/**************************************************************
    Problem: 1462
    User: wizny8206
    Language: C++
    Result: Success
    Time:114 ms
    Memory:1752 kb
****************************************************************/
 
 
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
 
typedef pair<int, int> point;
char row[51][51];
int visited[51][51];
vector<point> startpoint;
 
int main() {
    int R, C;
    cin >> R >> C;
 
    for (int i = 0; i < R; ++i) {
        cin >> row[i];
    }
 
    //L인 곳을 찾고 
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (row[i][j] == 'L') {
                startpoint.push_back(point(i, j));
            }
        }
    }
    const int di[] = { -1, 0, 0, 1 };
    const int dj[] = { 0, 1, -1, 0 };
 
    //L인곳을 하나씩 선택해서 이동해가면서 맵에 값 저장하고
    int n = startpoint.size();
    int maximum = 0;
 
    for (int i = 0; i < n; ++i) {
        memset(visited, -1, sizeof(visited));
        point start = startpoint[i];
        queue<point> q;
        q.push(start);
        visited[start.first][start.second] = 0;
        while (!q.empty()) {
            point here = q.front();
            //cout << "here " << here.first << " " << here.second << " " << visited[here.first][here.second] << endl;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                //there
                int ni = here.first + di[k];
                int nj = here.second + dj[k];
                char c = row[ni][nj];
                if (ni < 0 || ni >= R)continue;
                if (nj < 0 || nj >= C)continue;
                if (c == 'L'&& visited[ni][nj] == -1) {
                    visited[ni][nj] = visited[here.first][here.second] + 1;
                    if (visited[ni][nj] > maximum) maximum = visited[ni][nj];
                    q.push(point(ni, nj));
                }
            }
        }
    }
    cout << maximum << endl;
    return 0;
}
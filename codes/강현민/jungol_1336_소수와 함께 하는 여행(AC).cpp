/**************************************************************
    Problem: 1336
    User: wizny8206
    Language: C++
    Result: Success
    Time:33 ms
    Memory:60572 kb
****************************************************************/
 
 
#include <stdio.h>
#include <iostream>
 
int S, E;
void Read_Input() {
    std::cin >> S >> E;
    //scanf_s("%d %d", &S, &E);
}
// 1062는 모든 소수의 개수
int A[1062];
int visit[1062];
#define LENGTH 1061
#define YES 1
#define NO 0
void Init_Table() {
    int idx = 1;
    for (int i = 1009; i <= 9973; i++) {
        int prime = YES;
        for (int j = 2; j < i; j++)
            if (i % j == 0) {
                prime = NO;
                break;
            }
        if (prime == YES)
            A[idx++] = i;
             
    }
}
 
typedef struct {
    int depth;
    int num;
} Node;
 
Node queue[14 * 14 * 14 * 14 * 14 * 14];
int Wp, Rp;
void EnQueue(Node node) { queue[Wp++] = node; }
Node DeQueue() { return queue[Rp++]; }
int IsEmpty() { return (Wp == Rp) ? YES : NO; }
 
int CanGo(Node node, int next) {
    int cnt = 0;
    if (node.num / 1000 == next / 1000)
        cnt++;
    if ((node.num % 1000) / 100
        == (next % 1000) / 100)
        cnt++;
    if ((node.num % 100) / 10
        == (next % 100) / 10)
        cnt++;
    if ((node.num % 10) / 1
        == (next % 10) / 1)
        cnt++;
    return (cnt == 3) ? YES : NO;
}
 
int Do_BFS() {
    Node node = { 0, S };
    EnQueue(node);
 
    while (IsEmpty() == NO) {
        node = DeQueue();
        for (int i = 1; i <= LENGTH; i++) {
            if (visit[i] == NO && CanGo(node, A[i]) == YES) {
                if (A[i] == E)
                    return node.depth + 1;
                Node _node = { node.depth + 1, A[i] };
                EnQueue(_node);
                visit[i] = YES;
            }
        }
    }
    return -1;
}
 
int main() {
    Read_Input();
    Init_Table();
    int ret = Do_BFS();
    printf("%d\n", ret);
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// ================= 代码实现开始 =================
const int N = 300005;
int Father[N], Rank[N];
//查找节点x所在集合的根
int find(int x) {
	return Father[x] == x ? x : Father[x] = find(Father[x]);
}
// n：变量个数
// m：约束个数
// A：大小为m的数组，表示m条约束中的a
// B：大小为m的数组，表示m条约束中的b
// E：大小为m的数组，表示m条约束中的e
// 返回值：若能找出一种方案，返回"Yes"；否则返回"No"
string getAnswer(int n, int m, vector<int> A, vector<int> B, vector<int> E) {
	for (int i = 1; i <= n; ++i) {
		Father[i] = i;
		Rank[i] = 0;
	}
	//交换，不适用于前面一堆0000000的
	/*for(int i=1; i<m; ++i)
	if(E[i] == 1&&E[i-1]==0) {
	swap(E[i], E[i-1]);
	swap(A[i], A[i-1]);
	swap(B[i], B[i-1]);

	}*/

	int cnt = 0;
	for (int i = 0; i<m; ++i)  //将e=1的操作提到e=0的操作前
		if (E[i] == 1) {
			swap(E[i], E[cnt]);
			swap(A[i], A[cnt]);
			swap(B[i], B[cnt]);
			++cnt;
		}
	for (int i = 0; i<m; ++i) {
		int setA = find(A[i]);
		int setB = find(B[i]);
		if (E[i] == 0) {
			if (setA == setB) {
				return "No";
			}
		}
		else {
			if (setA != setB) {
				if (Rank[setA] > Rank[setB])
					swap(setA, setB);
				Father[setA] = setB;
				if (Rank[setA] == Rank[setB])
					Rank[setB] += 1;
			}
		}
	}
	return "Yes";
}
// ================= 代码实现结束 =================

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> A, B, E;
        for (int i = 0; i < m; ++i) {
            int a, b, e;
            scanf("%d%d%d", &a, &b, &e);
            A.push_back(a);
            B.push_back(b);
            E.push_back(e);
        }
        printf("%s\n", getAnswer(n, m, A, B, E).c_str());
    }
    return 0;
}

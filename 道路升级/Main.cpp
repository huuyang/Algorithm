#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================
const int N = 500005;
//并查集
class UnionSet {
public:
	int f[N];
	//初始化父节点   n：节点数量   开始每个节点的父节点是它自己本身
	void init(int n) {
		for (int i = 1; i <= n; i++)
			f[i] = i;
	}
	//查找节点x所在集合的根（路径压缩）
	//x：节点x
	//返回值：根
	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}
	//将x节点与y节点所在集合合并
	//x：一个节点
	//y：一个节点
	//返回值：返回true表示成功合并，返回false表示已经在一个集合里了
	bool merge(int x, int y) {
		int setX = find(x);
		int setY = find(y);
		if (setX != setY) {
			f[setX] = setY;
			return true;
		}
		return false;
	}
}us;
// 给定一个n个点m条边的无向图，第i条边边权为i，求所有需要升级的边
// n：n个点
// m：m条边
// U：大小为m的数组，表示m条边的其中一个端点
// V：大小为m的数组，表示m条边的另一个端点
// 返回值：所有需要升级的边，从小到大排列；第一小问的答案自然即为返回值的size，所以你不必考虑如何返回size
vector<int> getAnswer(int n, int m, vector<int> U, vector<int> V) {
	vector<int> ans;
	us.init(n);
	//构造最大生成树，找权值最大的边
	for (int i = m - 1; i >= 0; --i)
		if (us.merge(U[i], V[i]))
			ans.push_back(i + 1);//加入边，从1开始的
	reverse(ans.begin(), ans.end());
	return ans;
}
// ================= 代码实现结束 =================

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> U, V;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        U.push_back(u);
        V.push_back(v);
    }
    vector<int> ans = getAnswer(n, m, U, V);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < int(ans.size()); ++i)
        printf("%d\n", ans[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
    
const int N = 100005;

struct node {
	int val, l, r;
}t[N];

int root, cnt;

int insert(int v, int x) {
	if (x == 0)
	{
		cnt = cnt + 1;
		x = cnt;
		t[x].val = v;
		t[x].l = 0;
		t[x].r = 0;
		return x;
	}
	if (t[x].val > v)
	{
		t[x].l = insert(v, t[x].l);
	}
	else
	{
		t[x].r = insert(v, t[x].r);
	}
	return x;
}

void dlr(int x, vector<int> &ans) {//前序遍历
	if (x != 0) {
		//加入x节点的val到ans中，递归求解左右子树
		ans.push_back(x);
		dlr(t[x].l, ans);
		dlr(t[x].r, ans);
	}
}

void lrd(int x, vector<int> &ans) {
	if (x != 0) {
		//递归求解左右子树，加入x节点的val到ans中
		lrd(t[x].l, ans);
		lrd(t[x].r, ans);
		ans.push_back(x);
	}
}
// 给定一个1到n的排列，依次插入到二叉树中，返回前序遍历和后序遍历
// n：如题意
// sequence：给定的排列，大小为n
// 返回值：将要输出的元素依次加入到返回值中
vector<int> getAnswer(int n, vector<int> sequence) {
	/* 请在这里设计你的算法 */
	for (int i = 0; i < int(sequence.size()); i++)
		root = insert(sequence[i], root);
	vector<int> ans;
	dlr(root, ans);
	lrd(root, ans);
	return ans;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sequence.push_back(x);
    }
    vector<int> ans = getAnswer(n, sequence);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[n + i], " \n"[i == n - 1]);
    return 0;
}

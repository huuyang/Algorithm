#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================
//ans:总答案
//allOne：用于二进制&的全1数
int ans, allOne;
//搜索（用二进制来优化）
//pos:其二进制上的某个位置的1表示当前所在行的相应的位置（列）已经放了一个皇后
//left:其二进制上的某个位置的1表示当前所在行的相应的位置（是由于右对角线上已经有皇后），不能放置皇后
//right：其二进制上的某个位置的1表示当前所在行的相应的位置（是由于左对角线上已经优皇后），不能放置皇后
void dfs(int pos,int left, int right){
    if(pos == allOne){//当且仅当每一列都放了一个皇后，那么整个棋盘已经放了n个合法皇后，故要终止
        ++ans;
        return;
    }
    for(int t = allOne & (~(pos | left | right)); t>0;){//t代表可以放的集合对应的二进制数
        int p = t & -t;//low bit: 二进制中最右边的1
        dfs(pos | p, ((left | p) << 1) & allOne, (right | p) >> 1);
        t ^= p;
    }
}
//一个n*n的棋盘，在棋盘上摆n个皇后，求满足任意两个皇后不能在同一行，同一列或同一斜线上的方案数
//n：上述n
//返回值：方案数
int getAnswer(int n){
    ans = 0;
    allOne = (1 << n) - 1;
    dfs(0, 0, 0);
    return ans;
}
// ================= 代码实现结束 =================

int main() {
    int n;
	cin >> n;
	cout << getAnswer(n) << endl;
	return 0;
}

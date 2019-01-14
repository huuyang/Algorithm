#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
string stackArray[100000];
int top_pos = 0;
// 压入栈顶
// name：被压入的人的姓名
void push(string name) {
    /* 请在这里设计你的算法 */
	stackArray[top_pos] = name;
	top_pos++;
}

// 弹出栈顶
// 返回值：被弹出人的姓名
string pop() {
    /* 请在这里设计你的算法 */
	if (top_pos == 0)
	{
		return "栈已空";
	}
	else
	{
		top_pos--;
		return stackArray[top_pos];
	}
}

// 询问栈中某个位置上的人的姓名（栈底位置为1，向栈顶方向的位置依次递增）
// pos：询问的位置
// 返回值：pos位置上人的姓名
string query(int position) {
    /* 请在这里设计你的算法 */
	if (1 <= position && position <= top_pos)
	{
		return stackArray[position-1];
	}
	else
	{
		return "该位置不在栈内";
	}
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    char name[20];
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s", name);
            push(name);
        } else if (op == 2) {
            printf("%s\n", pop().c_str());
        } else {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", query(pos).c_str());
        }
    }
    return 0;
}

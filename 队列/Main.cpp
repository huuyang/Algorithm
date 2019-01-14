#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
string queueArray[100000];
int length = 0;
// 队尾入队
// name：入队人的姓名
void enqueue(string name) {
    /* 请在这里设计你的算法 */
	queueArray[length] = name;
	length++;
}

// 队首出队
// 返回值：队首的姓名
string dequeue() {
    /* 请在这里设计你的算法 */
	if (length == 0)
	{
		return "队列已空";
	}
	else
	{
		string temp = queueArray[0];
		for (int i = 0; i < length; i++)
		{
			queueArray[i] = queueArray[i + 1];
		}
		length--;
		return temp;
	}
}

// 询问队列中某个位置上的人的姓名（队首位置为1，往后位置依次递增）
// pos：询问的位置
// 返回值：pos位置上人的姓名
string query(int postion) {
    /* 请在这里设计你的算法 */
	if (1 <= postion && postion <= length)
	{
		return queueArray[postion-1];
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
    for (; n--; ) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s", name);
            enqueue(name);
        } else if (op == 2) {
            printf("%s\n", dequeue().c_str());
        } else {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", query(pos).c_str());
        }
    }
    return 0;
}

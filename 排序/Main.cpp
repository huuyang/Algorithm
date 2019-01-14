#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================
vector<int> heap, result;
/* 请在这里定义你需要的全局变量 */
void downFilter(int index) {
	//for (int i = 0; i < heap.size(); i++) {
	//	cout << "heap[" << i << "]:" << heap[i] << endl;
	//}
	int left_kid = index * 2 + 1, right_kid = (index + 1) * 2;
	if ((index + 1) * 2 < heap.size()) {//若有两个孩子
		if (heap[left_kid] <= heap[right_kid]) {//若左孩子较小
			if (heap[index] > heap[left_kid]) {//若a[index]比左孩子大
				int temp = heap[index];//把a[index]和左孩子交换
				heap[index] = heap[left_kid];
				heap[left_kid] = temp;
				downFilter(left_kid);
			}
		}
		else {//若右孩子较小
			if (heap[index] > heap[right_kid]) {//若a[index]比右孩子大
				int temp = heap[index];//把a[index]和右孩子交换
				heap[index] = heap[right_kid];
				heap[right_kid] = temp;
				downFilter(right_kid);
			}
		}
	}
	else if ((index + 1) * 2 == heap.size()) {//若只有左孩子
		if (heap[index] > heap[left_kid]) {//若a[index]比左孩子大
			int temp = heap[index];//把a[index]和左孩子交换
			heap[index] = heap[left_kid];
			heap[left_kid] = temp;
			downFilter(left_kid);
		}
	}
	else if (index * 2 + 1 >= heap.size()) {//若没有孩子
		
	}
}
void deleteMin() {
	heap[0] = heap[heap.size() - 1];//用堆尾元素占据堆顶
	heap.pop_back();//将原堆尾元素删除
	downFilter(0);//对heap[0]做下滤
}

// 将给定数组a升序排序
// n：数组大小
// a：所给数组，大小为n
// 返回值：排序后的数组
vector<int> getAnswer(int n, vector<int> a) {
    /* 请在这里设计你的算法 */
	//构建最小堆
	heap = a;
	for (int i = a.size() / 2 - 1; i >= 0; i--) {
		downFilter(i);
	}
	//排序
	while (heap.size()>0)
	{
		result.push_back(heap[0]);
		deleteMin();
	}
	return result;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    a = getAnswer(n, a);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}

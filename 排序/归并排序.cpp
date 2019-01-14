#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================
/* 请在这里定义你需要的全局变量 */
vector<int> result;
void Sort(int l_idx, int r_idx){
	if(l_idx == r_idx)
		return;
	vector<int> temp;
	int mid = (l_idx+r_idx)>>2;
	Sort(l_idx,mid);
	Sort(mid+1,r_idx);
	while(l_idx<=mid && mid+1<=r_idx){
		if(a[l_idx]>a[mid]){
			temp.append(a[mid]);
			l_idx++;
		}
		else{
			temp.append(a[l_idx]);
		}
	}
}
// 将给定数组a升序排序
// n：数组大小
// a：所给数组，大小为n
// 返回值：排序后的数组
vector<int> getAnswer(int n, vector<int> a) {    /* 请在这里设计你的算法 */
	
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

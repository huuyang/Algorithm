#include <bits/stdc++.h>
using namespace std;
//#include "stdafx.h"
//#include <stdio.h>
//#include <iostream>
// ================= 代码实现开始 =================

typedef long long ll;
const int N = 300005;

// 存储二维平面点
struct ip {
    int x, y, i;
    ip(int x = 0, int y = 0) : x(x), y(y), i(0) { }
    void ri(int _i) {
        scanf("%d%d", &x, &y);
        i = _i;
    }
};

/* 请在这里定义你需要的全局变量 */
int lastIndex = 0;
int answer = 1;

int ToLeftTest(ip p, ip q, ip s) {//s在p→q的左边
	return s.x * p.y + p.x * q.y + s.y * q.x - q.x * p.y - s.y * p.x - q.y * s.x;
}//大于0为true,等于0为共线，小于0为false

// 计算二维点数组a的凸包，将凸包放入b数组中，下标均从0开始
// a, b：如上
// n：表示a中元素个数
// 返回凸包元素个数
int convex(ip *a, ip *b, int n) {
    /* 请在这里设计你的算法 */
	ip ltl = a[0];
	for (int i = 1; i < n; i++) {//i∈[1,9]
		if (a[i].x < ltl.x) {
			ltl = a[i];
		}
		else if (a[i].x == ltl.x){
			if (a[i].y < ltl.y) {
				ltl = a[i];
			}
		}
	}//确定ltl
	b[0] = ltl;
	a[ltl.i - 1] = a[n - 1];//用最后一个点覆盖ltl，a[]长度-1
	
	
	for (int i = 1; i < n; i++) {
		int good_j = 0;
		b[i] = a[0];
		for (int j = 1; j < n - i; j++) {
			if (ToLeftTest(b[i-1], b[i], a[j]) < 0) {
				b[i] = a[j];
				good_j = j;
			}
		}
		a[good_j] = a[n - i - 1];
		if (i>=2 && ToLeftTest(b[i - 1], b[i], b[0]) == 0) {
			lastIndex = i;
			break;
		}
		else if (i >= 2 && ToLeftTest(b[i - 1], b[i], b[0]) < 0) {
			lastIndex = (i - 1);
			break;
		}
	}

	for (int i = 0; i <= lastIndex; i++) {
		answer = answer * b[i].i;
	}
	answer = answer * (lastIndex + 1);
	return answer % (n+1);
}

// ================= 代码实现结束 =================

ip a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        a[i].ri(i + 1);
    
    printf("%d\n", convex(a, b, n));
    return 0;
}
/*
int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
		a[i].ri(i + 1);
	int result = convex(a, b, n);
	for (int i = 0; i <= lastIndex; i++) {
		cout << "(" << b[i].x << "," << b[i].y << ")" << endl;
	}
	cout << result << endl;
	system("pause");
	return 0;
}
*/
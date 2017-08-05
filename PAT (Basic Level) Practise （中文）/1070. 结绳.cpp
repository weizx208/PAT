/*1070. 结绳
给定一段一段的绳子，你需要把它们串成一条绳。每次串连的时候，是把两段绳子对折，再如下图所示套接在一起。这样得到的绳子又被当成是另一段绳子，可以再次对折去跟另一段绳子串连。每次串连后，原来两段绳子的长度就会减半。


给定N段绳子的长度，你需要找出它们能串成的绳子的最大长度。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出正整数N (2 <= N <= 104)；第2行给出N个正整数，即原始绳段的长度，数字间以空格分隔。所有整数都不超过104。

输出格式：

在一行中输出能够串成的绳子的最大长度。结果向下取整，即取为不超过最大长度的最近整数。

输入样例：
8
10 15 12 3 4 13 1 15
输出样例：
14
*/
//居然一遍过，和哈夫曼树还是挺像的，不过只要换位就好了
//打卡成功！！！！！
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void swap(double *a, double *b)
{
	double temp = *a;
	*a = *b;
	*b = *a;
}
int main()
{
	int n;
	cin >> n;
	double *a = new double[n+1];
	a[n] = 1000000;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	double now = (a[0] + a[1])/2;
	for (int i = 2; i < n; i++)
	{
		if (now > a[i + 1])
			swap(now, a[i + 1]);
		now = (a[i] + now) / 2;
	}
	cout << (int)now;

	system("pause");
	return 0;
}

/*1018. 锤子剪刀布
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
输入格式：
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B*/
//我也不知道为什么他就这么多行了。。
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct Per
{
	int win = 0;
	int draw = 0;
	int lost = 0;
	int resA[3] = { 0 };
	int resB[3] = { 0 };
};
Per per;
void score(char a, char b)
{
	if (a == 'C' && b == 'J')
	{
		per.win++;
		per.resA[1]++;
	}
	if (a == 'C' && b == 'B')
	{
		per.lost++;
		per.resB[0]++;
	}
	if (a == 'C' && b == 'C')
	{
		per.draw++;
	}
	if (a == 'B' && b == 'C')
	{
		per.win++;
		per.resA[0]++;
	}
	if (a == 'B' && b == 'J')
	{
		per.lost++;
		per.resB[2]++;
	}
	if (a == 'B' && b == 'B')
	{
		per.draw++;
	}
	if (a == 'J' && b == 'B')
	{
		per.win++;
		per.resA[2]++;
	}
	if (a == 'J' && b == 'C')
	{
		per.lost++;
		per.resB[1]++;
	}
	if (a == 'J' && b == 'J')
	{
		per.draw++;
	}
}
int main()
{
	char tempa, tempb;
	int max1, max2, max3,max4;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tempa >> tempb;
		score(tempa, tempb);
	}
	cout << per.win << " " << per.draw << " " << per.lost << endl;
	cout << per.lost << " " << per.draw << " " << per.win << endl;
	max2 = max4 = 0;
	max1 = per.resA[0];
	max3 = per.resB[0];
	for (int i = 1; i <= 2; i++)
	{
		if (max1 < per.resA[i])
		{
			max1 = per.resA[i];
			max2 = i;
		}
		if (max3 < per.resB[i])
		{
			max3 = per.resB[i];
			max4 = i;
		}
	}
		switch (max2)
		{
		case 0: cout << "B ";
			break;
		case 1: cout << "C ";
			break;
		case 2: cout << "J ";
			break;
		}
		switch (max4)
		{
		case 0: cout << "B";
			break;
		case 1: cout << "C";
			break;
		case 2: cout << "J";
			break;
		}
		return 0;
}

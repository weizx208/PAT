/*1033. 旧键盘打字
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/
//应该有键盘没坏的情况
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	int length1 = str1.length();
	int length2 = str2.length();
	for (int i = 0; i < length1; i++)
	{
		if (str1[i] == '+')
		{
			for (int j = 0; j < length2; j++)
			{
				if (str2[j] <= 'Z' && str2[j] >= 'A')
					str2[j] = ' ';
			}
		}
		for (int j = 0; j < length2; j++)
		{
			if (str1[i] == str2[j] || tolower(str1[i]) == str2[j])
			{
				str2[j] = ' ';
			}
			
		}
	}
	for (int j = 0; j < length2; j++)
	{
		if (str2[j] != ' ')
			cout << str2[j];
	}
	system("pause");
	return 0;
}
// Find_Anagrams_in_string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <map>

using namespace std;
/*
438题目：给定一个字符串s和一个非空字符串p，字符串全部由小写字母组成。
	在S中找出所有p对应的anagrams（颠倒）字符串的子串，返回这些子串的起始索引
	如s="cbaebabacd"  p="abc", 返回结果[0,6]
	如s="abab" p="ba",返回[0,1,2]
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> tarVec;
		int len1 = s.length();
		int len2 = p.length();

		if (len1 < len2||s.empty()||p.empty())
		{
			return tarVec;
		}

		vector<int>pFreq(26,0); //存放p对应字符对应频率

		vector<int>sFreq(26, 0);  //存放待比较字符串的频率

		for (int i = 0; i < len2; i++)
		{
			pFreq[p[i]-'a']++;
			sFreq[s[i] - 'a']++;
		}

		//只有定义了vector类型的两个数组，才可以直接用==等号来判断是否相等
		if (sFreq==pFreq)
		{
			tarVec.push_back(0);
		}

		for (int i = len2; i < len1 ; i++)
		{
			//设置了一个len2大小的窗口，后面向后遍历一个，前面删除一个
			//最终sFreq中总是存放s字符串对应len2长度的一段中，每个字符的频率
			sFreq[s[i] - 'a']++;
			sFreq[s[i - len2] - 'a']--;

			if (sFreq==pFreq)
			{
				tarVec.push_back(i-len2+1);
			}
		}

		return tarVec;
	}
};

int main()
{
	string s = "cbaebabacd";
	string p = "abc";

	vector<int> vec = Solution().findAnagrams(s, p);

	for (int i=0;i<vec.size();i++)
	{
		cout << vec[i]<<" ";
	}
	cout << endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

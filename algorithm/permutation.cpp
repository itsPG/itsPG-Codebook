/*
	permutation 
	by PG @ SENSE lab / Copyright(c) 2013
	Released under the MIT License
	
	不重複的排列組合
	主要的想法是同一層遞迴中不取同樣的數字
	這東西很簡單，以前高中時代寫過，但今天想實作的時候才發現方法早忘光了，只剩下模糊的概念
	網路上查了一下，大陸網站上相關作法很多，可是卻沒有一個是我想要的解法。

	最後是靠自己摸出寫法的，希望沒問題...

	關於是否是正解而非用剪枝方法的偽解的一個簡單的判斷方法
	輸入aaaaaaaaaaaaaaaaaaab，正確解答的話馬上就會跑出答案，
	錯誤的方法要多次剪枝，輸出上會稍微延遲

*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string src,dst;
bool used[100];

void permutation(int depth)
{
	if (depth == src.size())
	{
		cout << dst << endl;
		return ;
	}
	char last = -128;
	for (int i = 0; i < src.size(); i++)
	{
		if (src[i] <= last || used[i]) continue;
		last = src[i];

		used[i] = true;
		dst[depth] = src[i];
		permutation(depth+1);
		used[i] = false;
	}

}

int main()
{
	string q;
	while (cin >> q)
	{
		sort(src.begin(), src.end());
		src = dst = q;
		memset(used, 0, sizeof(used));
		permutation(0);

	}

}
// two_sum.cpp : 定义控制台应用程序的入口点。
//
//Description
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//Example:
//Given nums = [2, 7, 11, 15], target = 9,

//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].

//思路是遍历数组，对于i=0~n,j=i+1~n;如果满足a[i]+a[j]=target就把i,j存到一个vector中
//算法时间复杂度为n^2
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		//vector<pair<int, int>> result;
		//用vector<int> res作为存储下标i，j的数组，便于元素的插入；
		vector<int> res;
		for (auto i = nums.begin(); i != nums.end(); i++)
			for (auto j = i+1; j != nums.end(); j++)
				if (*i + *j == target)
				{
					res.push_back(i - nums.begin());
					res.push_back(j - nums.begin());
				}
		return res;
	}
};
//Function test
//a[] = {1,2,3,4,5},target = 7
int main()
{
	vector<int> a{ 1,2,3,4,5 },b;
	Solution s;
	b = s.twoSum(a, 7);
	//print the index i,j
	if (b.size() != 0)
	{
		cout << "[";
		for (auto &i : b)
			cout << i << ",";
		cout << "]" << endl;
	}
	else
		cout << "no such result!" << endl;

    return 0;
}


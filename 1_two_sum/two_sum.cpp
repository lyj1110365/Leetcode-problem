// two_sum.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Description
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//Example:
//Given nums = [2, 7, 11, 15], target = 9,

//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].

//˼·�Ǳ������飬����i=0~n,j=i+1~n;�������a[i]+a[j]=target�Ͱ�i,j�浽һ��vector��
//�㷨ʱ�临�Ӷ�Ϊn^2
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
		//��vector<int> res��Ϊ�洢�±�i��j�����飬����Ԫ�صĲ��룻
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


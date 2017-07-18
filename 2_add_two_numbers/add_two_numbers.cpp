// add.cpp : 定义控制台应用程序的入口点。


//Description
//You are given two non-empty linked lists representing two non - negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8

#include "stdafx.h"
#include<iostream>
#include<list>
#include<math.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//一次遍历，对应位置相加，之和超过10则进位；
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		
		ListNode *h1 = l1, *h2 = l2, *ph1 = h1;
		//默认L1比l2长
		for (;h1 != NULL || h2 != NULL;h1 = h1->next,h2 = h2->next)
		{
			//如果发现l1先等于NUll则将h2的后面的数据和l1连接起来
			if (h1 == NULL)
			{
				ph1->next = h2;
				break;
			}
			//如果发现l2先结束，退出即可
			if (h2 == NULL)
				break;
				
			//将l1和l2对应位置相加
			h1->val += h2->val;
			//如果结果超过9，进位，如果后一位进位后也大于9，继续进位，直到当前位置不大于9
			for(ListNode *temp = h1; temp != NULL && temp->val>9;temp = temp->next)
			{
				//如果进位的下一位没有，则新建一个节点，值为1，如果有则+1；
				if (temp->next == NULL)
					temp->next = new ListNode(1);
				else
					temp->next->val += 1;
				//当前节点的元素值减1；
				temp->val -= 10;
			}
			ph1 = h1;
		}
		return l1;

	}
	//第二种方法与第一种基本相同，有两点差异
	//1.同时维护L1和L2，当L1长度小于L2时，直接另L1=L2；
	//2.最后再一起进行进位操作；
	ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2)
	{
		ListNode *h1 = l1, *h2 = l2;
		for(;h1 != NULL || h2 != NULL;h1=h1->next,h2=h2->next)
		{
			if (h1 == NULL)
			{
				l1 = l2;
				break;
			}
			if (h2 == NULL)
				break;
			//同时另L1，L2的值为为对应位置的和
			h1->val += h2->val;
			h2->val = h1->val;
		}
		//最后再检查需不需要进位
		for (h1 = l1; h1 != NULL ; h1 = h1->next)
		{
			if (h1->val > 9)
			{
				if (h1->next == NULL)
					h1->next = new ListNode(1);
				else
					h1->next->val += 1;
				h1->val -= 10;
			}
				
		}
		return l1;
	}
};
//将链表内容转化为数字，然后再转换为链表
//有明显的溢出问题，不推荐使用
class Solution1
{
public:
	ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2)
	{
		unsigned long long il1 = 0, il2 = 0,count=0;
		for (; l1 != NULL; l1 = l1->next,count++)
			//有可能overflow
			il1 += (l1->val)*pow(10,count);
		count = 0;
		for (; l2 != NULL; l2 = l2->next,count++)
			il2 += (l2->val) * pow(10, count);
		int res = il1 + il2;
		ListNode *r = new ListNode(res % 10) , *temp;
		res = res / 10;
		temp = r;
		while (res != 0)
		{
			temp->next = new ListNode(res % 10);
			res = res / 10;
			temp = temp->next;
		}
		return r;
	}
	int listToint(ListNode *l1)
	{
		int il1 = 0,count=0;
		for (; l1 != NULL; l1 = l1->next,count++)
			il1 += (l1->val) * pow(10,count);
		return il1;
	}
};
//function test
int main()
{
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(9);
	Solution s;
	ListNode *res = s.addTwoNumbers(l1, l2);
	for (ListNode *temp = res; temp != NULL; temp = temp->next)
		cout << temp->val << " ";
	cout << endl;
	
	getchar();
    return 0;
}


// add.cpp : �������̨Ӧ�ó������ڵ㡣


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
//һ�α�������Ӧλ����ӣ�֮�ͳ���10���λ��
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		
		ListNode *h1 = l1, *h2 = l2, *ph1 = h1;
		//Ĭ��L1��l2��
		for (;h1 != NULL || h2 != NULL;h1 = h1->next,h2 = h2->next)
		{
			//�������l1�ȵ���NUll��h2�ĺ�������ݺ�l1��������
			if (h1 == NULL)
			{
				ph1->next = h2;
				break;
			}
			//�������l2�Ƚ������˳�����
			if (h2 == NULL)
				break;
				
			//��l1��l2��Ӧλ�����
			h1->val += h2->val;
			//����������9����λ�������һλ��λ��Ҳ����9��������λ��ֱ����ǰλ�ò�����9
			for(ListNode *temp = h1; temp != NULL && temp->val>9;temp = temp->next)
			{
				//�����λ����һλû�У����½�һ���ڵ㣬ֵΪ1���������+1��
				if (temp->next == NULL)
					temp->next = new ListNode(1);
				else
					temp->next->val += 1;
				//��ǰ�ڵ��Ԫ��ֵ��1��
				temp->val -= 10;
			}
			ph1 = h1;
		}
		return l1;

	}
	//�ڶ��ַ������һ�ֻ�����ͬ�����������
	//1.ͬʱά��L1��L2����L1����С��L2ʱ��ֱ����L1=L2��
	//2.�����һ����н�λ������
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
			//ͬʱ��L1��L2��ֵΪΪ��Ӧλ�õĺ�
			h1->val += h2->val;
			h2->val = h1->val;
		}
		//����ټ���費��Ҫ��λ
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
//����������ת��Ϊ���֣�Ȼ����ת��Ϊ����
//�����Ե�������⣬���Ƽ�ʹ��
class Solution1
{
public:
	ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2)
	{
		unsigned long long il1 = 0, il2 = 0,count=0;
		for (; l1 != NULL; l1 = l1->next,count++)
			//�п���overflow
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


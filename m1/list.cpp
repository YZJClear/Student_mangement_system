#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

PSTU_INFO_LIST head;

STU_INFO_LIST *insert_node(STU_INFO_LIST* head, STU_INFO* stu)
{
	STU_INFO_LIST *h = head;
	STU_INFO_LIST *p = (STU_INFO_LIST*)malloc(sizeof(STU_INFO_LIST));//初始化节点

	//安全性判断，如果为空则返回错误
	if(p == NULL)
	{
		return NULL;
	}
	memset(p, 0, sizeof(STU_INFO_LIST));

	p->data = *stu;
	p->average_score = 0;

	//判断是否为第一个节点，如果不是，则重定义尾节点的指针域
	if(h == NULL)
	{
		h = p;
		h->next = h;
		h->pre = p;
	}
	else
	{
		STU_INFO_LIST *q = h;
		while( q->next !=h )
		{
			q = q->next;
		}

		q->next = p;
		p->next = h;
		p->pre = q;
	}

	return h;
}


#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

PSTU_INFO_LIST head;

STU_INFO_LIST *insert_node(STU_INFO_LIST* head, STU_INFO* stu)
{
	STU_INFO_LIST *h = head;
	STU_INFO_LIST *p = (STU_INFO_LIST*)malloc(sizeof(STU_INFO_LIST));//��ʼ���ڵ�

	//��ȫ���жϣ����Ϊ���򷵻ش���
	if(p == NULL)
	{
		return NULL;
	}
	memset(p, 0, sizeof(STU_INFO_LIST));

	p->data = *stu;
	p->average_score = 0;

	//�ж��Ƿ�Ϊ��һ���ڵ㣬������ǣ����ض���β�ڵ��ָ����
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


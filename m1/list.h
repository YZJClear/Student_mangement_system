#pragma once

typedef struct _STU_INFO
{
	unsigned int iNum;			//ѧ��
	unsigned int iClass;		//�༶
	float		 fcScore;		//C���Գɼ�;
	float		 fmScore;		//�����ɼ�
	float		 feScore;		//Ӣ��ɼ�
	char		 szName[50];	//����

}STU_INFO;

typedef struct _STU_INFO_LIST
{
	STU_INFO data;
	float	 average_score;
	struct _STU_INFO_LIST *pre;
	struct _STU_INFO_LIST *next;

}STU_INFO_LIST, *PSTU_INFO_LIST;

STU_INFO_LIST *insert_node(STU_INFO_LIST* head, STU_INFO* stu);
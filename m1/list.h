#pragma once

typedef struct _STU_INFO
{
	unsigned int iNum;			//学号
	unsigned int iClass;		//班级
	float		 fcScore;		//C语言成绩;
	float		 fmScore;		//高数成绩
	float		 feScore;		//英语成绩
	char		 szName[50];	//姓名

}STU_INFO;

typedef struct _STU_INFO_LIST
{
	STU_INFO data;
	float	 average_score;
	struct _STU_INFO_LIST *pre;
	struct _STU_INFO_LIST *next;

}STU_INFO_LIST, *PSTU_INFO_LIST;

STU_INFO_LIST *insert_node(STU_INFO_LIST* head, STU_INFO* stu);
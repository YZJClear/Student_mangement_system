#include "func.h"
#include "list"
#include <iostream>
#include <string.h>


//录入指定学生
STU_INFO_LIST* insert_info(STU_INFO_LIST *head)
{
	STU_INFO stu;

	std::cout << "请输入学号：";
	std::cin >> stu.iNum;

	std::cout << "请输入姓名：";
	std::cin >> stu.szName;

	std::cout << "请输入班级：";
	std::cin >> stu.iClass;

	std::cout << "请输入C语言成绩：";
	std::cin >> stu.fcScore;

	std::cout << "请输入高等数学成绩：";
	std::cin >> stu.fmScore;

	std::cout << "请输入英语成绩：";
	std::cin >> stu.feScore;

	STU_INFO_LIST *ret = insert_node(head, &stu);
	
	calcutor_scroce(ret);
	sort_list(ret, 1);

	return ret;
}



//修改指定学生
void modify_info(STU_INFO_LIST *head)
{
	int iNum = 0;
	std::cout << "请输入指定学生的学号:";
	std::cin >> iNum;

	STU_INFO_LIST *p = head;

	std::cout << "\n\n该学生信息如下：\n";
	do 
	{
		p = p->next;
		if(p->data.iNum == iNum)
		{
			std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName << "\t班级："<<  p->data.iClass 
				<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
				<< "\t英语成绩：" << p->data.feScore << std::endl;

			std::cout << "\n请输入该学生的新信息：\n";
			STU_INFO stu;

			std::cout << "请输入学号：";
			std::cin >> stu.iNum;

			std::cout << "请输入姓名：";
			std::cin >> stu.szName;

			std::cout << "请输入班级：";
			std::cin >> stu.iClass;

			std::cout << "请输入C语言成绩：";
			std::cin >> stu.fcScore;

			std::cout << "请输入高等数学成绩：";
			std::cin >> stu.fmScore;

			std::cout << "请输入英语成绩：";
			std::cin >> stu.feScore;

			p->data = stu;
			std::cout << "\n修改完毕\n";
			std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName << "\t班级："<<  p->data.iClass 
				<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
				<< "\t英语成绩：" << p->data.feScore << std::endl;
		}
		


	} while (p != head);

}



//删除指定学生
void delete_info(STU_INFO_LIST *head)
{
	int iNum = 0;
	std::cout << "请输入指定学生的学号:";
	std::cin >> iNum;

	STU_INFO_LIST *p = head;
	do 
	{
		p = p->next;
		if(p->data.iNum == iNum)
		{
			p->next->pre = p->pre;
			p->pre->next = p->next;
			std::cout << "已删除！！！！！\n";
			break;
		}

	} while (p != head);


}


//计算平均成绩
void calcutor_scroce(STU_INFO_LIST *head)
{
	STU_INFO_LIST *p = head;

	std::cout << "\n\n每个学生的平均分如下:\n";
	do 
	{
		p = p->next;
		p->average_score = (p->data.fcScore + p->data.feScore + p->data.fmScore) / 3;

		std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName << "\t班级："<<  p->data.iClass 
			<< "\t平均成绩：" << p->average_score <<std::endl;

	} while (p != head);
	std::cout << "\n\n";
}


void sort_list(STU_INFO_LIST *head, int dir)
{
	if(head == NULL) 
		return;

	STU_INFO_LIST *now_item = head;
	STU_INFO_LIST *next_item = NULL;

	float av_tmp = 0;
	STU_INFO st_tmp = {0};

	do
	{
		next_item = now_item->next;

		//比较平均分
		while(next_item != NULL && next_item->pre != head && (next_item->pre->average_score > next_item->average_score) ^ dir)
		{
			/*交换*/
			av_tmp = next_item->average_score;
			st_tmp = next_item->data;

			next_item->average_score = next_item->pre->average_score;
			next_item->data = next_item->pre->data;

			next_item->pre->average_score = av_tmp;
			next_item->pre->data = st_tmp;

			next_item = next_item->pre;
		}

		now_item = now_item->next;

	}while(next_item != head);
}



//选择方式查询
void query_info(STU_INFO_LIST *head)
{
	int iUserop = 0;
	std::cout << "输入1：按学号查询\n输入2：按姓名查询\n输入3 ：按班级查询\n\
输入4：按C语言成绩查询\n输入5：按高等数学成绩查询\n输入6：按英语成绩查询\n\n";
	std::cin >> iUserop;

	int iNum = 0;
	int iClass = 0;
	char szName[50] = {'\0'};
	float		 fcScore;		//C语言成绩;
	float		 fmScore;		//高数成绩
	float		 feScore;		//英语成绩

	switch(iUserop)
	{
	case 1:
		std::cout << "请输入学号：";
		std::cin >> iNum;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n查询的匹配结果如下：\n";
			do 
			{
				p = p->next;
				if(p->data.iNum == iNum)
				{
					std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName 
						<< "\t班级："<<  p->data.iClass 
						<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
						<< "\t英语成绩：" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 2:
		std::cout << "请输入姓名：";
		std::cin >> szName;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n查询的匹配结果如下：\n";
			do 
			{
				p = p->next;
				if(strcmp(p->data.szName, szName) == 0)
				{
					std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName 
						<< "\t班级："<<  p->data.iClass 
						<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
						<< "\t英语成绩：" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 3:
		std::cout << "请输入班级：";
		std::cin >> iClass;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n查询的匹配结果如下：\n";
			do 
			{
				p = p->next;
				if(p->data.iClass == iClass)
				{
					std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName 
						<< "\t班级："<<  p->data.iClass 
						<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
						<< "\t英语成绩：" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 4:
		std::cout << "请输入C语言成绩：";
		std::cin >> fcScore;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n查询的匹配结果如下：\n";
			do 
			{
				p = p->next;
				if(p->data.fcScore == fcScore)
				{
					std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName 
						<< "\t班级："<<  p->data.iClass 
						<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
						<< "\t英语成绩：" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 5:
		std::cout << "请输入高等数学：";
		std::cin >> fmScore;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n查询的匹配结果如下：\n";
			do 
			{
				p = p->next;
				if(p->data.fmScore == fmScore)
				{
					std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName 
						<< "\t班级："<<  p->data.iClass 
						<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
						<< "\t英语成绩：" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 6:
		std::cout << "请输入英语成绩：";
		std::cin >> feScore;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n查询的匹配结果如下：\n";
			do 
			{
				p = p->next;
				if(p->data.feScore == feScore)
				{
					std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName 
						<< "\t班级："<<  p->data.iClass 
						<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
						<< "\t英语成绩：" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;
	}


}


//显示所有信息
void display_info(STU_INFO_LIST *head)
{
	//traversal_list(STU_INFO_LIST* head)
	STU_INFO_LIST *p = head;

	std::cout << "\n\n";

	if(p == NULL)
	{
		std::cout << "没有信息\n"; 
		return;
	}

	do 
	{
		p = p->next;	
		std::cout << "学号：" << p->data.iNum << "\t姓名："<< p->data.szName 
			<< "\t班级："<<  p->data.iClass 
			<< "\tC语言成绩："  << p->data.fcScore << "\t高等数学成绩：" << p->data.fmScore 
			<< "\t英语成绩：" << p->data.feScore << std::endl;
	} while (p != head);
	std::cout << "\n\n";

}
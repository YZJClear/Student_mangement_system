#include "func.h"
#include "list"
#include <iostream>
#include <string.h>


//¼��ָ��ѧ��
STU_INFO_LIST* insert_info(STU_INFO_LIST *head)
{
	STU_INFO stu;

	std::cout << "������ѧ�ţ�";
	std::cin >> stu.iNum;

	std::cout << "������������";
	std::cin >> stu.szName;

	std::cout << "������༶��";
	std::cin >> stu.iClass;

	std::cout << "������C���Գɼ���";
	std::cin >> stu.fcScore;

	std::cout << "������ߵ���ѧ�ɼ���";
	std::cin >> stu.fmScore;

	std::cout << "������Ӣ��ɼ���";
	std::cin >> stu.feScore;

	STU_INFO_LIST *ret = insert_node(head, &stu);
	
	calcutor_scroce(ret);
	sort_list(ret, 1);

	return ret;
}



//�޸�ָ��ѧ��
void modify_info(STU_INFO_LIST *head)
{
	int iNum = 0;
	std::cout << "������ָ��ѧ����ѧ��:";
	std::cin >> iNum;

	STU_INFO_LIST *p = head;

	std::cout << "\n\n��ѧ����Ϣ���£�\n";
	do 
	{
		p = p->next;
		if(p->data.iNum == iNum)
		{
			std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName << "\t�༶��"<<  p->data.iClass 
				<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
				<< "\tӢ��ɼ���" << p->data.feScore << std::endl;

			std::cout << "\n�������ѧ��������Ϣ��\n";
			STU_INFO stu;

			std::cout << "������ѧ�ţ�";
			std::cin >> stu.iNum;

			std::cout << "������������";
			std::cin >> stu.szName;

			std::cout << "������༶��";
			std::cin >> stu.iClass;

			std::cout << "������C���Գɼ���";
			std::cin >> stu.fcScore;

			std::cout << "������ߵ���ѧ�ɼ���";
			std::cin >> stu.fmScore;

			std::cout << "������Ӣ��ɼ���";
			std::cin >> stu.feScore;

			p->data = stu;
			std::cout << "\n�޸����\n";
			std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName << "\t�༶��"<<  p->data.iClass 
				<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
				<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
		}
		


	} while (p != head);

}



//ɾ��ָ��ѧ��
void delete_info(STU_INFO_LIST *head)
{
	int iNum = 0;
	std::cout << "������ָ��ѧ����ѧ��:";
	std::cin >> iNum;

	STU_INFO_LIST *p = head;
	do 
	{
		p = p->next;
		if(p->data.iNum == iNum)
		{
			p->next->pre = p->pre;
			p->pre->next = p->next;
			std::cout << "��ɾ������������\n";
			break;
		}

	} while (p != head);


}


//����ƽ���ɼ�
void calcutor_scroce(STU_INFO_LIST *head)
{
	STU_INFO_LIST *p = head;

	std::cout << "\n\nÿ��ѧ����ƽ��������:\n";
	do 
	{
		p = p->next;
		p->average_score = (p->data.fcScore + p->data.feScore + p->data.fmScore) / 3;

		std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName << "\t�༶��"<<  p->data.iClass 
			<< "\tƽ���ɼ���" << p->average_score <<std::endl;

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

		//�Ƚ�ƽ����
		while(next_item != NULL && next_item->pre != head && (next_item->pre->average_score > next_item->average_score) ^ dir)
		{
			/*����*/
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



//ѡ��ʽ��ѯ
void query_info(STU_INFO_LIST *head)
{
	int iUserop = 0;
	std::cout << "����1����ѧ�Ų�ѯ\n����2����������ѯ\n����3 �����༶��ѯ\n\
����4����C���Գɼ���ѯ\n����5�����ߵ���ѧ�ɼ���ѯ\n����6����Ӣ��ɼ���ѯ\n\n";
	std::cin >> iUserop;

	int iNum = 0;
	int iClass = 0;
	char szName[50] = {'\0'};
	float		 fcScore;		//C���Գɼ�;
	float		 fmScore;		//�����ɼ�
	float		 feScore;		//Ӣ��ɼ�

	switch(iUserop)
	{
	case 1:
		std::cout << "������ѧ�ţ�";
		std::cin >> iNum;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n��ѯ��ƥ�������£�\n";
			do 
			{
				p = p->next;
				if(p->data.iNum == iNum)
				{
					std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName 
						<< "\t�༶��"<<  p->data.iClass 
						<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
						<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 2:
		std::cout << "������������";
		std::cin >> szName;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n��ѯ��ƥ�������£�\n";
			do 
			{
				p = p->next;
				if(strcmp(p->data.szName, szName) == 0)
				{
					std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName 
						<< "\t�༶��"<<  p->data.iClass 
						<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
						<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 3:
		std::cout << "������༶��";
		std::cin >> iClass;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n��ѯ��ƥ�������£�\n";
			do 
			{
				p = p->next;
				if(p->data.iClass == iClass)
				{
					std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName 
						<< "\t�༶��"<<  p->data.iClass 
						<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
						<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 4:
		std::cout << "������C���Գɼ���";
		std::cin >> fcScore;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n��ѯ��ƥ�������£�\n";
			do 
			{
				p = p->next;
				if(p->data.fcScore == fcScore)
				{
					std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName 
						<< "\t�༶��"<<  p->data.iClass 
						<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
						<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 5:
		std::cout << "������ߵ���ѧ��";
		std::cin >> fmScore;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n��ѯ��ƥ�������£�\n";
			do 
			{
				p = p->next;
				if(p->data.fmScore == fmScore)
				{
					std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName 
						<< "\t�༶��"<<  p->data.iClass 
						<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
						<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;


		//---------------------------------------------------
	case 6:
		std::cout << "������Ӣ��ɼ���";
		std::cin >> feScore;
		{
			STU_INFO_LIST *p = head;

			std::cout << "\n\n��ѯ��ƥ�������£�\n";
			do 
			{
				p = p->next;
				if(p->data.feScore == feScore)
				{
					std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName 
						<< "\t�༶��"<<  p->data.iClass 
						<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
						<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
				}

			} while (p != head);
		}
		break;
	}


}


//��ʾ������Ϣ
void display_info(STU_INFO_LIST *head)
{
	//traversal_list(STU_INFO_LIST* head)
	STU_INFO_LIST *p = head;

	std::cout << "\n\n";

	if(p == NULL)
	{
		std::cout << "û����Ϣ\n"; 
		return;
	}

	do 
	{
		p = p->next;	
		std::cout << "ѧ�ţ�" << p->data.iNum << "\t������"<< p->data.szName 
			<< "\t�༶��"<<  p->data.iClass 
			<< "\tC���Գɼ���"  << p->data.fcScore << "\t�ߵ���ѧ�ɼ���" << p->data.fmScore 
			<< "\tӢ��ɼ���" << p->data.feScore << std::endl;
	} while (p != head);
	std::cout << "\n\n";

}
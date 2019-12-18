#include <iostream>
#include "func.h"
#include "list.h"
#include "storge.h"


//��ʾ�˵�
void display_menu()
{
	std::cout << "\t\t1:¼��ָ��ѧ��" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t2:�޸�ָ��ѧ��" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t3:ɾ��ָ��ѧ��" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t4:����ƽ���ɼ�" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t5:����ƽ���ɼ�" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t6:ѡ��ʽ��ѯ" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t7:��ʾ������Ϣ" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t8:������Ϣ�ļ�" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t0:�˳�����ϵͳ" << std::endl;
	std::cout << "\n\t\t������ָ�";
}


//����������ں���
int main()
{
	unsigned int userop = 0;
	STU_INFO_LIST *head = NULL;

	std::cout << "\t��ӭʹ��ѧ������ϵͳ!!!!!  " << std::endl;
	std::cout << "\t\t\t���ߣ��������1802�� Ҧ���  " << std::endl;
	head = load(head);

	while(true)
	{
		display_menu();
		std::cin >> userop;
		std::cin.clear();
		std::cin.sync();
		//std::cin.ignore();
		switch (userop)
		{
		case 1:
			head = insert_info(head);
			break;
		case 2:
			modify_info(head);
			break;
		case 3:
			delete_info(head);
			break;
		case 4:
			calcutor_scroce(head);
			break;
		case 5:
			//sort_info(head);
			sort_list(head, 1);
			break;
		case 6:
			query_info(head);
			break;
		case 7:
			display_info(head);
			break;
		case 8:
			save(head);
			break;
		case 0:
			save(head);
			exit(0);
			break;
		default:
			std::cout << "�������ȷָ��" << std::endl;
			break;
		}
	}

	save(head);
	return 1;
}
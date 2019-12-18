#include <iostream>
#include "func.h"
#include "list.h"
#include "storge.h"


//显示菜单
void display_menu()
{
	std::cout << "\t\t1:录入指定学生" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t2:修改指定学生" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t3:删除指定学生" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t4:计算平均成绩" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t5:排序平均成绩" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t6:选择方式查询" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t7:显示所有信息" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t8:保存信息文件" << std::endl;
	std::cout << "\t\t---------" << std::endl;
	std::cout << "\t\t0:退出管理系统" << std::endl;
	std::cout << "\n\t\t请输入指令：";
}


//主函数，入口函数
int main()
{
	unsigned int userop = 0;
	STU_INFO_LIST *head = NULL;

	std::cout << "\t欢迎使用学籍管理系统!!!!!  " << std::endl;
	std::cout << "\t\t\t作者：软件技术1802班 姚震杰  " << std::endl;
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
			std::cout << "请输出正确指令" << std::endl;
			break;
		}
	}

	save(head);
	return 1;
}
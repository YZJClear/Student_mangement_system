#include "storge.h"
#include "list.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

const char *szFilename = "info.data";


//保存信息文件
int save(STU_INFO_LIST *head)
{
	FILE *fp;
	fopen_s(&fp, szFilename, "w+");
	if(!fp)
	{
		std::cout << "文件打开失败" << std::endl;
		return 0;
	}


	STU_INFO_LIST *p = head;
	do 
	{
		p = p->next;	
		fwrite(&p->data, sizeof(STU_INFO), 1, fp);
	} while (p != head);

	
	fclose(fp);
	return 1;
}

//获取文件大小
int file_size(const char* filename)//获取文件名为filename的文件大小。
{
	FILE *fp;
	fopen_s(&fp, filename, "rb");//打开文件。
	int size;
	if(fp == NULL) // 打开文件失败
		return -1;
	fseek(fp, 0, SEEK_END);//定位文件指针到文件尾。
	size=ftell(fp);//获取文件指针偏移量，即文件大小。
	fclose(fp);//关闭文件。
	return size;
}

//初次启动时，加载信息文件
STU_INFO_LIST * load(STU_INFO_LIST *head)
{
	FILE *fp;
	fopen_s(&fp, szFilename, "r");
	if(!fp)
	{
		std::cout << "文件打开失败" << std::endl;
	}

	STU_INFO stu;
	STU_INFO_LIST *h = head;

	int iFileSize = file_size(szFilename);
	if(iFileSize == 0)
	{
		return NULL;//如果文件大小为0，则不读取任何信息
	}


	long filePoint = 0;



	while(iFileSize != filePoint) //判断是否读取到结尾，因为feof会多读取一次，故使用此方法判断是否读取到结尾
	{
		fread(&stu, sizeof(STU_INFO), 1, fp);
		h = insert_node(h, &stu);
		filePoint = ftell(fp);  //获取文件指针
	}

	fclose(fp);

	return h;
}


#include "storge.h"
#include "list.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

const char *szFilename = "info.data";


//������Ϣ�ļ�
int save(STU_INFO_LIST *head)
{
	FILE *fp;
	fopen_s(&fp, szFilename, "w+");
	if(!fp)
	{
		std::cout << "�ļ���ʧ��" << std::endl;
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

//��ȡ�ļ���С
int file_size(const char* filename)//��ȡ�ļ���Ϊfilename���ļ���С��
{
	FILE *fp;
	fopen_s(&fp, filename, "rb");//���ļ���
	int size;
	if(fp == NULL) // ���ļ�ʧ��
		return -1;
	fseek(fp, 0, SEEK_END);//��λ�ļ�ָ�뵽�ļ�β��
	size=ftell(fp);//��ȡ�ļ�ָ��ƫ���������ļ���С��
	fclose(fp);//�ر��ļ���
	return size;
}

//��������ʱ��������Ϣ�ļ�
STU_INFO_LIST * load(STU_INFO_LIST *head)
{
	FILE *fp;
	fopen_s(&fp, szFilename, "r");
	if(!fp)
	{
		std::cout << "�ļ���ʧ��" << std::endl;
	}

	STU_INFO stu;
	STU_INFO_LIST *h = head;

	int iFileSize = file_size(szFilename);
	if(iFileSize == 0)
	{
		return NULL;//����ļ���СΪ0���򲻶�ȡ�κ���Ϣ
	}


	long filePoint = 0;



	while(iFileSize != filePoint) //�ж��Ƿ��ȡ����β����Ϊfeof����ȡһ�Σ���ʹ�ô˷����ж��Ƿ��ȡ����β
	{
		fread(&stu, sizeof(STU_INFO), 1, fp);
		h = insert_node(h, &stu);
		filePoint = ftell(fp);  //��ȡ�ļ�ָ��
	}

	fclose(fp);

	return h;
}


#pragma once

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

//���͵Ķ���
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];//�����ӽ������˵���Ϣ
	int sz; //��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
}Contact;

//��������
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ӡ��ϵ����Ϣ
void PrintContact(const Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//������ϵ����Ϣ
void ModifyContact(Contact* pc);

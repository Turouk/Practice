#define _CRT_SECURE_NO_WARNINGS 1
/*
	ʱ�䣺2023/7/16
	�ص㣺����¥110
	��Ŀ��ģ��qsort����ʵ��һ��ð�������ͨ���㷨
	˼·��

*/

#include <stdio.h>

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int cmp_int(const void* e1, const void* e2)
{
	return  *(int*)e1 - *(int*)e2;
}

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base,
				 int sz,
				 int width,//���/����
				 int (*cmp)(const void* e1 , const void * e2 )//�����ĵ�ַ/����ָ��
				)
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{   //һ������
		int j =0 ;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//����Ԫ�رȽ�
			if (cmp( (char*)base + j * width , (char*)base + (j+1) * width )>0)//��������Ԫ�صĵ�ַ
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width ,width);
			}
		}
	}
}


struct Stu
{
	char name[20];
	int age;
};

int sort_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int sort_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

//
//void test3()
//{
//	//������������
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}

void test4()
{
	//ʹ���Զ��庯������ṹ������
	struct Stu s[3] = { {"zhangsan ",30},{"lisi",25},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	//������������
	//bubble_sort(s, sz, sizeof(s[0]), sort_by_age);
	//��������������
	bubble_sort(s, sz, sizeof(s[0]), sort_by_name);
}

int main()
{
	//test3();
	test4();
	return 0;
}
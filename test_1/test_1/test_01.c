#define _CRT_SECURE_NO_WARNINGS 1
/*
	ʱ�䣺2023/7/16
	�ص㣺����¥110
	��Ŀ�����������������Ϊ����
	˼·��
		  ����һ��ð�����򷨣�
			1.��������bubble_sort();����Ĳ�������������鳤��
			2.����forѭ���Ƚ��������Ԫ��֮��Ĵ�С�����н���
			3.���forѭ�������������������
			4.�ڲ�forѭ����������һ���������������Ľ���
		  ��������ʹ�ÿ⺯��qsort();������������
			1.��������Ԫ�ص�ַ�����ݵĸ������������ݵĳ��ȣ��Ƚϴ����������е�����Ԫ�صĺ���������ָ�룩��ַ�������
			2.�����Ƚϵĺ������������κ�����
			3.���ص�ʱ������������Ľ������>0��<0��=0������Щ������⺯��ʹ��
			3.���ظ�qsort()����ʱ��Ҫ������ǿ������ת���ٽ�����
*/
#include <stdio.h>
#include <stdlib.h>

////ð�������㷨
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	//ð�����������
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tem = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tem;
//			}
//		}
//	}
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print_arr(arr, sz);
//	bubble_sort(arr, sz);
//	print_arr(arr, sz);
//	return 0;
//}



//qsort�⺯��������ʹ�ã���������
//void qsort(void* base,                      base�д�ŵ��Ǵ����������е�һ������ĵ�ַ
//			 size_t num,					  ������������Ԫ�صĸ���
//			size_t size,					  ������������һ��Ԫ�صĴ�С����λ���ֽ�
//			int (*compar)(const void*, const void*)); �Ƚϴ���������������Ԫ�صĺ���

int cmp_int(const void* e1, const void* e2)
{
	return  *(int*)e1 - *(int*)e2;
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test1()
{
	//������������
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print_arr(arr, sz);
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
	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
}

void test2()
{
	//ʹ��qsort��������ṹ������
	struct Stu s[3] = { {"zhangsan ",30},{"lisi",25},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	//������������
	//qsort(s, sz, sizeof(s[0]), sort_by_age);
	//��������������
	qsort(s, sz, sizeof(s[0]), sort_by_name);
}

int main()
{
	//test1();������������
	test2();//����ṹ������
	return 0;

}
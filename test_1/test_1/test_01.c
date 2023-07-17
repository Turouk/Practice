#define _CRT_SECURE_NO_WARNINGS 1
/*
	时间：2023/7/16
	地点：立言楼110
	题目：将降序的数字排序为升序
	思路：
		  方法一：冒泡排序法：
			1.建立函数bubble_sort();传入的参数是数组和数组长度
			2.利用for循环比较两个相近元素之间的大小，进行交换
			3.外层for循环用来控制排序的趟数
			4.内层for循环用来控制一趟下来，两个数的交换
		  方法二：使用库函数qsort();函数快速排序：
			1.将数据首元素地址，数据的个数，单个数据的长度，比较待排序数据中的两个元素的函数（函数指针）地址传入参数
			2.建立比较的函数，参数是任何类型
			3.返回的时两个数据相减的结果：有>0；<0；=0，将这些结果给库函数使用
			3.返回给qsort()函数时，要将参数强制类型转换再解引用
*/
#include <stdio.h>
#include <stdlib.h>

////冒泡排序算法
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	//冒泡排序的趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟冒泡排序
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



//qsort库函数函数的使用，快速排序
//void qsort(void* base,                      base中存放的是待排序数据中第一个对象的地址
//			 size_t num,					  待排序数据中元素的个数
//			size_t size,					  待排序数据中一个元素的大小，单位是字节
//			int (*compar)(const void*, const void*)); 比较待排序数据中两个元素的函数

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
	//排序整形数据
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
	//使用qsort函数排序结构体数据
	struct Stu s[3] = { {"zhangsan ",30},{"lisi",25},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	//按照年龄排序
	//qsort(s, sz, sizeof(s[0]), sort_by_age);
	//按照名字来排序
	qsort(s, sz, sizeof(s[0]), sort_by_name);
}

int main()
{
	//test1();排序整形数据
	test2();//排序结构体数据
	return 0;

}
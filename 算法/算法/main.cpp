#include"SeqList.h"


int main()
{
	int arr[5] = { 1,2,3,4,5 };
	SeqList<int> vec(arr, 5);
	vec.PrintList();
}
#include <stdio.h>
#include <string.h>

void heaplify(int *arr, int len, int pos)
{
	int left = pos * 2 + 1;
	int right = pos * 2 + 2;
	int max = 0;
	int temp = 0;
	
	if( left < len  && arr[left] > arr[pos])
	{
		max = left;
	}
	else
	{
		max = pos;	
	}
	if( right < len && arr[right] > arr[max])
	{
		max = right;
	}
	
	if( max != pos)
	{
		temp = arr[max];
		arr[max]= arr[pos];
		arr[pos] = temp;
		
		heaplify(arr, len, max);
	}

}

void buildHeap(int *arr, int len)
{
	for(int i = len / 2 - 1; i>=0 ; i--)
	{
		heaplify(arr, len, i);
	}
}

int * heapSort(int *arr, int len)
{

	buildHeap(arr, len);

	for( int i = len - 1; i > 0 ; i--)
	{
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		
		heaplify(arr, i , 0);
	}
	
	return arr;
}

void printArray(int *arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%-2d",arr[i]);
	}
	printf("\n");
}

void Test_1()
{
	struct T
	{
		int st[10] ;
		int end[10];
	} test[] =
	{
		{7,4,1,3,8,5,6,2,0,9,
		0,1,2,3,4,5,6,7,8,9},
	};
	if(0 == memcmp(test[0].end,heapSort(test[0].st, 10),sizeof(int) * 10))
	{
		printf("PASS! \n");
		printArray(test[0].st,10);
	}
	else
	{
		printf("FAILED! \n");
		printArray(test[0].st,10);
	}
	
}

int main()
{

	Test_1();
	
	return 0;
}












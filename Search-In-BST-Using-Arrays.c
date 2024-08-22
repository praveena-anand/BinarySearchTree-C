// PRAVEENA ANAND [CH.SC.U4CSE23044]

#include <stdio.h>
void sortArray(int arr[], int n)
{
	int i, j;
	
	for (i = 0; i < n-1; i++)
	{
		int flag = 0;
		for (j = 0; j < n-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

int search(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		
		if (key == arr[mid])
			return mid;
			
		else if (key < arr[mid])
			high = high - 1;
			
		else if (key > arr[mid])
			low = mid + 1;
	}
	
	return -1;
}

int main()
{
	int n, i;
	
	printf("Enter the Numbr of Elements : ");
	scanf("%d", &n);
	
	if (n <= 0)
	{
		printf("Invalid Input!\n");
		return 0;
	}
	
	int arr[n];
	
	for (i = 0; i < n; i++)
	{
		printf("Element %d : ", i);
		scanf("%d", &arr[i]);
	}
	
	sortArray(arr, n);
	
	int key;
	printf("Enter the Key : ");
	scanf("%d", &key);
	
	int result = search(arr, 0, n-1, key);
	
	if (result != -1)
		printf("%d Found!\n", key);
		
	else
		printf("%d Not Found!\n", key);
		
	return 0;
}

#include <stdio.h>
void insertSortTest(int a[], int size) {
	for (int i = 0; i < size; i++) {
		// 有序区间 [0, i)
		// 无序区间 [i, size)

		// 抓的哪张牌？[i]

		// 去有序区间选择插入位置（从后往前找）
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (a[i] >= a[j]) {
				break;
			}
		}
		int index = j + 1;
		// 再把 [i] 插入到合适的下标
		int k = a[i];

		// k 插入到 index 位置
		for (int t = i - 1; t >= index; t--) {
			a[t + 1] = a[t];
		}
		a[index] = k;
	}
}

// 稳定性：稳定
// 时间复杂度
// 最好			最坏			平均
// O(n)			O(n^2)			O(n^2)
// 有序			逆序			随机的
// 空间复杂度	O(1)
void insertSort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		// 有序 [0, i)
		// 无序 [i, size)
		int k = a[i];
		int j;
		for (j = i - 1; j >= 0 && k < a[j]; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = k;
	}
}

void insertSortWithGap(int a[], int size, int gap) {
	for (int i = 0; i < size; i++) {
		// 有序 [0, i)
		// 无序 [i, size)
		int k = a[i];
		int j;
		for (j = i - gap; j >= 0 && k < a[j]; j -= gap) {
			a[j + gap] = a[j];
		}
		a[j + gap] = k;
	}
}

// 稳定性：不稳定
// 时间复杂度
// 最好			最坏			平均
// O(n)			O(n^2)			O(n^1.2-1.3)
// 有序			逆序			随机的
// 空间复杂度	O(1)
void shellSort(int a[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;	// gap = gap / 2
		insertSortWithGap(a, size, gap);
		if (gap == 1) {
			break;
		}
	}
}

// 通过遍历无序区间，找到无序区间的最大的数的下标
// 交换 无序区间最大的数 和 无序区间的最后一个数
// 稳定性：不稳定
// 时间复杂度	O(n^2)	数据不敏感
// 空间复杂度	O(1)
void selectSort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		// 无序区间 [0,size - i)
		// 有序区间 [size - i,size)

		int max = 0;
		for (int j = 1; j < size - i; j++) {
			if (a[j] > a[max]) {
				max = j;
			}
		}

		int t = a[max];
		a[max] = a[size - i - 1];
		a[size - i - 1] = t;
	}
}

void heapify(int a[], int size, int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size) {
		return;
	}

	int max = left;
	if (right < size && a[right] > a[left]) {
		max = right;
	}

	if (a[index] >= a[max]) {
		return;
	}

	int t = a[max];
	a[max] = a[index];
	a[index] = t;

	heapify(a, size, max);
}

void createHeap(int a[], int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) {
		heapify(a, size, i);
	}
}

// 稳定性：不稳定
// 时间复杂度	O(n * log(n))	数据不敏感
// 空间复杂度	O(1)
void heapSort(int a[], int size) {
	// 1. 建堆
	createHeap(a, size);

	// 2. 需要 size 次
	for (int i = 0; i < size; i++) {
		// 无序区间 [0,size - i)
		// 有序区间 [size - i,size)

		int t = a[0];
		a[0] = a[size - i - 1];
		a[size - i - 1] = t;

		heapify(a, size - i - 1, 0);
	}
}

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[] = { 5, 3, 2, 9, 1, 4, 8, 7, 3, 9, 6 };
	int size = sizeof(a) / sizeof(int);
	heapSort(a, size);

	printArray(a, size);
}
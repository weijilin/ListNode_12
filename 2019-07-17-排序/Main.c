#include <stdio.h>
void insertSortTest(int a[], int size) {
	for (int i = 0; i < size; i++) {
		// �������� [0, i)
		// �������� [i, size)

		// ץ�������ƣ�[i]

		// ȥ��������ѡ�����λ�ã��Ӻ���ǰ�ң�
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (a[i] >= a[j]) {
				break;
			}
		}
		int index = j + 1;
		// �ٰ� [i] ���뵽���ʵ��±�
		int k = a[i];

		// k ���뵽 index λ��
		for (int t = i - 1; t >= index; t--) {
			a[t + 1] = a[t];
		}
		a[index] = k;
	}
}

// �ȶ��ԣ��ȶ�
// ʱ�临�Ӷ�
// ���			�			ƽ��
// O(n)			O(n^2)			O(n^2)
// ����			����			�����
// �ռ临�Ӷ�	O(1)
void insertSort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		// ���� [0, i)
		// ���� [i, size)
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
		// ���� [0, i)
		// ���� [i, size)
		int k = a[i];
		int j;
		for (j = i - gap; j >= 0 && k < a[j]; j -= gap) {
			a[j + gap] = a[j];
		}
		a[j + gap] = k;
	}
}

// �ȶ��ԣ����ȶ�
// ʱ�临�Ӷ�
// ���			�			ƽ��
// O(n)			O(n^2)			O(n^1.2-1.3)
// ����			����			�����
// �ռ临�Ӷ�	O(1)
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

// ͨ�������������䣬�ҵ�������������������±�
// ���� �������������� �� ������������һ����
// �ȶ��ԣ����ȶ�
// ʱ�临�Ӷ�	O(n^2)	���ݲ�����
// �ռ临�Ӷ�	O(1)
void selectSort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		// �������� [0,size - i)
		// �������� [size - i,size)

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

// �ȶ��ԣ����ȶ�
// ʱ�临�Ӷ�	O(n * log(n))	���ݲ�����
// �ռ临�Ӷ�	O(1)
void heapSort(int a[], int size) {
	// 1. ����
	createHeap(a, size);

	// 2. ��Ҫ size ��
	for (int i = 0; i < size; i++) {
		// �������� [0,size - i)
		// �������� [size - i,size)

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
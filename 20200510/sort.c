#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>



void merge(int* array, int begin,int mid, int end,int* tmp) {
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2) {
		if (array[begin1] < array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int)*(end2 - begin2 + 1));
	memcpy(array + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

void mergeSortNor(int* array, int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);
	int k = 1;
	while (k < n) {
		for (int i = 0; i < n; i += 2 * k) {

			int begin = i;
			int mid = i + k - 1;
			if (mid >= n - 1)
				continue;
			int end = i + 2 * k - 1;
			if (end > n - 1)
				end = n - 1;
			merge(array, begin, mid, end, tmp);
		}
		k = 2 * k;
	}
}
//计数排序
void countSort(int* array, int n) {
	//统计范围
	int min = array[0], max = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	//开空间
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int)*range);
	//将数组初始化为全0
	memset(countArr, 0, sizeof(int)*range);

	//计数
	for (int i = 0; i < range; i++) {
		countArr[array[i]-min]++;
	}
	//恢复数组
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (countArr[i]--)
			array[idx++] = i + min;
	}
	free(countArr);
}
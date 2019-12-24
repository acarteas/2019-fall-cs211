#pragma once


class QuickSort 
{
public:
	int partition(vector<string>& values, int left, int right) {
		int pivotIndex = left + (right - left) / 2;
		string pivotValue = values[pivotIndex];
		int i = left, j = right;
		string temp;
		while (i <= j) {
			while (values[i] < pivotValue) {
				i++;
			}
			while (values[j] > pivotValue) {
				j--;
			}
			if (i <= j) {
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
				i++;
				j--;
			}
		}
		return i;
	}
	void quicksort(vector<string>& values, int left, int right) {
		if (left < right) {
			int pivotIndex = partition(values, left, right);
			quicksort(values, left, pivotIndex - 1);
			quicksort(values, pivotIndex, right);
		}
	}
};

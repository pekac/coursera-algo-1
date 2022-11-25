#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void merge(int* array, int* tempArray, int lo, int mid, int hi);
void sort(int* array, int* tempArray, int lo, int hi);
void mergeSort(int* array, int n);

#endif
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include "insertion_sort.h"

using namespace std;

//merge arr[l...mid] and arr[mid+1....r]
template <typename T>
void __merge(T arr[], int l, int mid, int r){
	
	T aux[r-l+1];
	for(int i = l; i <= r; ++i)
		aux[i-l] = arr[i];

	int i = l, j = mid + 1;
	for(int k = l; k <= r; ++k){
		
		if(i > mid){
			arr[k] = aux[j-l];
			++j;
		}
		else if(j > r){
			arr[k] = aux[i-l];
			++i;
		}

		else if(aux[i-l] < aux[j-l]){
			arr[k] = aux[i-l];
			++i;
		}
		else{
			arr[k] = aux[j-l];
			++j;
		}
	}
}

//arr[l.....r]
template <typename T>
void __merge_sort(T arr[], int l, int r){
	
//	if(l >= r)
//		return ;
	if(r-l <= 15){
		insertion_sort(arr, l, r);
		return ;
	}

	int mid = (l+r)/2;
	__merge_sort(arr, l, mid);
	__merge_sort(arr, mid+1, r);
	if(arr[mid] > arr[mid+1])
		__merge(arr, l, mid, r);

}

template <typename T>
void merge_sort(T arr[], int n){
	__merge_sort(arr, 0, n-1);
}

#endif //MERGE_SORT_H

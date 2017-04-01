#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <algorithm>


template<typename T>
int __partition(T arr[], int l, int r){
	
	T v = arr[l];
	
	int j = l;
	for(int i = l+1; i <= r; ++i){
		if(arr[i] < v)
			swap(arr[++j], arr[i]);
	}
	swap(arr[l], arr[j]);

	return j;
}

template<typename T>
void __quick_sort(T arr[], int l, int r){
	if(l >= r)
		return;

	int p = __partition(arr, l, r);
	__quick_sort(arr, l, p-1);
	__quick_sort(arr, p+1, r);

}


template<typename T>
void quick_sort(T arr[], int n){
	__quick_sort(arr, 0, n-1);
}


#endif	//QUICK_SORT_H

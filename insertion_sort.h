#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


#include <iostream>

using namespace std;

template <typename T>
void insertion_sort(T arr[], int n){
	for(int i = 1; i < n; ++i){

		T e = arr[i];
		int j;
		
		for(j = i; j > 0; --j)
			if(arr[j-1] > e)
				arr[j] = arr[j-1];
			else 
				break;

		arr[j] = e;
	}
}


template<typename T>
void insertion_sort(T arr[], int l, int r){
	for(int i = l+1; i <= r; ++i){
		T e = arr[i];
		int j;
		for(j = i; j > l && arr[j-1] > e; --j)
			arr[j] = arr[j-1];
		arr[j] = e;
	}
}


#endif //INSERTION_SORT_H

#ifndef MERGE_SORT_BU_H
#define MERGE_SORT_BU_H

#include <iostream>
#include <algorithm>
#include "sort_test_helper.h>"
#include "merge_sort.h"

using namespace std;

template<typename T>
void merge_sort_bu(T arr[], int n){
	
	for(int sz = 1; sz <= n; sz += sz){
		for(int i = 0; i+sz < n; i += 2*sz)
			__merge(arr, i, i + sz - 1, min(i + 2*sz - 1));

	}
}

#endif	//MERGE_SORT_BU_H

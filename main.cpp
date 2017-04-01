#include <iostream>
#include <string>
#include "selection_sort.h"
#include "insertion_sort.h"
#include "sort_test_helper.h"
#include "merge_sort.h"
#include "quick_sort.h"

using namespace std;

int main(void){

	int n = 1000000;
	int *arr = sort_test_helper::generate_random_array(n, 0, n);
//	int *arr = sort_test_helper::generate_nearly_ordered_array(n, 10);
	int *arr2 = sort_test_helper::copy_array(arr, n);
//	selection_sort(arr, n);
//	sort_test_helper::print_array(arr, n);


	sort_test_helper::test_sort("merge sort", merge_sort, arr, n);
	sort_test_helper::test_sort("quick sort", quick_sort, arr2, n);

	delete[] arr;
	delete[] arr2;

	return 0;
}

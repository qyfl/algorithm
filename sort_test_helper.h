//#ifndef SORT_TEST_HELPER_H
//#define SORT_TEST_HELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace sort_test_helper{
	

	int *generate_random_array(int n, int rangeL, int rangeR){
			
			assert(rangeL <= rangeR);
			int *arr = new int[n];
			srand(time(NULL));
			for(int i = 0; i < n; ++i)
				arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
			
			return arr;
	}

	template<typename T>
	void print_array(T arr[], int n){
		for(int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}

	template<typename T>
	bool is_sorted(T arr[], int n){
		for(int i = 0; i < n-1; ++i)
			if(arr[i] > arr[i + 1])
				return false;
		return true;
	}

	template<typename T>
	void test_sort(string sort_name, void(*sort)(T[], int), T arr[], int n){

		clock_t start_time = clock();
		sort(arr, n);
		clock_t end_time = clock();

		assert(is_sorted(arr, n));
		cout << sort_name << " : " << double(end_time - start_time)/CLOCKS_PER_SEC << " s" << endl;
	}

	int* copy_array(int a[], int n){
		int* arr = new int[n];
		copy(a, a+n, arr);
		return arr;
	}

	int* generate_nearly_ordered_array(int n, int swap_times){
		int *arr = new int[n];
		for(int i = 0; i < n; ++i)
			arr[i] = i;

		srand(time(NULL));
		for(int i = 0; i < swap_times; ++i){
			int posx = rand()%n;
			int posy = rand()%n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}
}

//#endif //SORT_TEST_HELPER

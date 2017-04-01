#ifndef SELECTION_SORT
#define SELECTION_SORT

#include <algorithm>
using namespace std;

template <typename T>
void selection_sort(T arr[], int n){
	for(int i = 0; i < n; ++i){
		//find [i, n) min
		int min_index = i;

		for (int j = i+1; j < n; ++j)
			if (arr[j] < arr[min_index])
				min_index = j;
            
		swap(arr[i], arr[min_index]);

	}
}




#endif //SELETCION_SORT

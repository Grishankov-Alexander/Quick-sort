#include <iostream>
#include <cstdlib>
#include <chrono>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int *array, int left, int pivot)
{
	int low = left - 1;
	for (int j = left; j < pivot; ++j)
	{
		if (array[j] <= array[pivot])
		{
			swap(&array[++low], &array[j]);
		}
	}
	swap(&array[low + 1], &array[pivot]);
	return low + 1;
}

void quick_sort(int *array, int left, int pivot)
{
	if (left < pivot)
	{
		int new_pivot = partition(array, left, pivot);
		quick_sort(array, left, new_pivot - 1);
		quick_sort(array, new_pivot + 1, pivot);
	}
}


int main(int argc, char **argv)
{
	static constexpr int array_size = 9999;
	int *arr = new int[array_size];

	srand(1);
	for (int i = 0; i < array_size; ++i)
	{
		arr[i] = rand();
		//std::cout << arr[i] << "\t";
	}
	
	auto t1 = std::chrono::steady_clock::now();
	quick_sort(arr, 0, array_size - 1);
	auto t2 = std::chrono::steady_clock::now();
	auto duration = (t2 - t1);
	std::cout << "Quick sort took " << duration.count() / 1e9 << "[s]\n";
	/*std::cout << "\n\nArray after quick sort:\n";
	for (int i = 0; i < array_size; ++i)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << "\n\n";
	*/
	std::cin.get();
	delete[] arr;
	return 0;
}

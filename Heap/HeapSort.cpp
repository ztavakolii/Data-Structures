#include <vector>
using namespace std;

void heapSort(vector<int>& array, int start, int end) {
	for (int i = start + 1; i < end; i++) {
		int j = i, p;    // p = parentIndex
		while (j != start) {
			if (j % 2 == 0)
				p = (j - start - 2) / 2 + start;
			else p = (j - start - 1) / 2 + start;
			if (array[j] > array[p]) {
				int temp = array[p];
				array[p] = array[j];
				array[j] = temp;
				j = p;
			}
			else break;
		}
	}

	int endOfHeap = end - 1;
	for (int i = 0; i < end - start; i++) {
		int temp = array[start];
		array[start] = array[endOfHeap];
		array[endOfHeap] = temp;
		endOfHeap--;
		int j = start;
		while ((j - start) * 2 + 1 + start <= endOfHeap) {
			int lch = (j - start) * 2 + 1 + start, rch = (j - start) * 2 + 2 + start;
			
			int largest;
			if (rch <= endOfHeap && array[j] < array[rch])
				largest = rch;
			else largest = j;
			if (lch <= endOfHeap && array[largest] < array[lch])
				largest = lch;
			if (j != largest) {
				int temp = array[j];
				array[j] = array[largest];
				array[largest] = temp;
				j = largest;
			}
			else break;
		}

	}
}

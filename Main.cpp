#include <iostream>

#include "DynamicArray.h"

int main() {

	DynamicArray<int> arr(10);
	for (int i = 0; i < 10; ++i) {
		arr.append(i);
	}

	arr.pop();
	arr.removeAt(arr.size()-1);
	arr.removeAt(0);
	arr.remove(10);

	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr.get(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}
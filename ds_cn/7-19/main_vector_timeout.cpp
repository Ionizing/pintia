#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
	int K;
	std::vector<int> vec;
	std::cin >> K;
	int tmpData;
	std::cin >> tmpData;
	while (tmpData >= 0) {
		vec.push_back(tmpData);
		std::cin >> tmpData;
	}

	if (K > vec.size()) {
		std::cout << "NULL" << std::endl;
	} else {
		std::cout << vec[vec.size() - K] << std::endl;
	}
	return 0;
}
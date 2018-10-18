#include <iostream>
#include <string>
#include <sstream>

typedef int option;
option FindTrueAns(const std::string& ProbStr);

int main(int argc, char* argv[]) {
	int N;
	std::cin >> N;
	std::cin.get();
	std::string ProbStr;
	for (int i=0; i!=N; ++i) {
		std::getline(std::cin, ProbStr);
		// std::cout << " @14 ProbStr = " << ProbStr << std::endl;
		std::cout << FindTrueAns(ProbStr);
	}
	std::cout << std::endl;
	return 0;
}

option FindTrueAns(const std::string& ProbStr) {
	if (15 != ProbStr.length()) {
		return -1;
	}

	std::stringstream ss(ProbStr);
	std::string tmp;
	for (int i=0; i!=4; ++i) {
		ss >> tmp;
		if ('T' == tmp[2]) {
			return tmp[0] - 'A' + 1;
		}
	}
	return -1;
}
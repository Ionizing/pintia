#include <iostream>
#include <vector>

std::string fun(const int n);

int main(int argc, char* argv[]) {
	std::cout << fun(7);
	return 0;
}

std::string fun(const int n) {
	std::stringstream ss;
	if (1 == n) {
		ss << "1 ";
	} else {
		for (int i=1; i<=n/2; ++i) {
			ss << i << " + " << fun(n-i);
		}
	}

	return ss.str();
}
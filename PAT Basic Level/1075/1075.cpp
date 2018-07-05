/* Very slow. */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <tuple>
#include <fstream>
#include <vector>

using Node=std::tuple<std::string, int, std::string>;

int main() {
#ifndef ONLINE_JUDGE
	std::ifstream in("./in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif
	// std::cout << __FILE__ << std::endl;

	std::string Head;
	int N, K;
	std::cin >> Head >> N >> K;

	std::unordered_map<std::string, Node> List;
	Node tmp;
	for (int i=0; i!=N; ++i){
		std::cin >> std::get<0>(tmp) >> std::get<1>(tmp) >> std::get<2>(tmp);
		List[std::get<0>(tmp)] = tmp;
	}

	std::string p = Head;
	std::vector<std::vector<Node>> vec(3);
	while(std::string("-1") != p) {
		// std::cout << std::get<0>(List[p]) << ' ' << std::get<1>(List[p]) << ' ' << std::get<2>(List[p]) << std::endl;
		if (std::get<1>(List[p]) < 0) {
			vec[0].push_back(List[p]);
		} else if (std::get<1>(List[p]) <= K) {
			vec[1].push_back(List[p]);
		} else {
			vec[2].push_back(List[p]);
		}

		p = std::get<2>(List[p]);
	}

	bool is_first = true;
	for(size_t i=0; i!=vec.size(); ++i) {
		for (size_t j=0; j!=vec[i].size(); ++j) {
			Node tmp = vec[i][j];
			if (true == is_first) {
				std::cout << std::get<0>(tmp) << " " << std::get<1>(tmp) << " ";
				// std::cout << "\n" << __FILE__ << ": " << __LINE__ << std::endl;
				is_first = false;
			} else {
				std::cout << std::get<0>(tmp) << "\n" << std::get<0>(tmp) << " " << std::get<1>(tmp) << " ";
			}
		}
	} std::cout << "-1" << std::endl;
	return 0;
}
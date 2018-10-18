// #include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <fstream>
#include <iomanip>

// const int MaxLocations = 100, MaxTestees = 300;

struct Student {
	uint64_t ID;
	int score, localrank, location_number;

	Student() : ID(0), score(0), localrank(-1), location_number(-1) {};
	Student(const uint64_t _id, const int _score, const int _location_number) : 
			ID(_id), score(_score), location_number(_location_number) {};
	bool operator < (const Student& b) const { // a < b 表示 a 的优先级比 b 高。
		if (score != b.score) {
			return score > b.score;
		} else {
			return ID < b.ID;
		}
	}

	// bool operator > (const Student& b) const {
	// 	return !(*this < b);
	// }
};

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	// std::ifstream in("in.txt");
	// std::cin.rdbuf(in.rdbuf());
	freopen("in.txt", "r", stdin);
#endif

	int nLocation, nTestee;
	// std::cin >> nLocation;
	scanf("%d", &nLocation);
	std::vector<std::set<Student>> LocalSets(nLocation);
	std::set<Student> GlobalSet;

	uint64_t id;
	int score;
	for (int i=0; i!=nLocation; ++i) {
		// std::cin >> nTestee;
		scanf("%d", &nTestee);
		for (int j=0; j!=nTestee; ++j) {
			// std::cin >> id >> score;
			scanf("%zu%d", &id, &score);
			LocalSets[i].insert(Student(id, score, i + 1));
		}
		int last_score, last_rank, ind = 1;
		bool isFirst = true;
		for (auto elem : LocalSets[i]) {
			if (true == isFirst) {
				isFirst = false;
				elem.localrank = last_rank = 1;
				last_score = elem.score;
			} else {
				if (elem.score == last_score) {
					elem.localrank = last_rank;
				} else {
					elem.localrank = last_rank = ind;
					last_score = elem.score;
				}
			}
			// std::cout << "  @61 " << elem.ID << " " << elem.score 
			// 	<< " " << elem.localrank << std::endl;
			GlobalSet.insert(elem);
			++ind;
		}
	}

	// std::cout << GlobalSet.size() << std::endl;
	printf("%zu\n", GlobalSet.size());
	bool isFirst = true;
	int last_score, last_rank, ind = 1;
	for (const auto& elem : GlobalSet) {
		// std::cout << std::setw(13) << std::setfill('0') << elem.ID;
		printf("%0*zu", 13, elem.ID);
		if (true == isFirst) {
			isFirst = false;
			last_score = elem.score;
			last_rank = 1;
			// std::cout << " " << 1;
			printf(" 1");
		} else {
			if (elem.score == last_score) {
				// std::cout << " " << last_rank;
				printf(" %d", last_rank);
			} else {
				last_rank = ind;
				last_score = elem.score;
				// std::cout << " " << ind;
				printf(" %d", ind);
			}
		}
		// std::cout << " " << elem.location_number << " " << elem.localrank << std::endl;
		printf(" %d %d\n", elem.location_number, elem.localrank);
		++ind;
	}
	return 0;
}
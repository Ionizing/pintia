#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// #include <set>
#include <algorithm>
#include <unordered_map>

struct School {
	std::string Name;
	int tScore, aScore, bScore, Score, nStu;
	// std::unordered_set<std::string> Stus;

	School() : tScore(0), aScore(0), bScore(0), Score(0), nStu(0) {};
	// School(std::string name, int tscore, int ascore, int bscore, std::string stuname) : 
	// 	Name(name), tScore(tscore), aScore(ascore), bScore(bscore) {
	// 		Stus.insert(stuname);
	// 	};

	bool operator < (const School& b) {
		if (Score != b.Score) {
			return Score > b.Score;
		} else if (nStu != b.nStu) {
			return nStu < b.nStu;
		} else {
			return Name < b.Name;
		}
	}
	bool operator > (const School& b) {
		return !(*this > b);
	}
};

int main(int argc, char* argv[]) {
	std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif

	int N;
	std::cin >> N;
	std::unordered_map<std::string, School> Data;
	School tmp;
	for (int i=0; i!=N; ++i) {
		std::string id, school;
		int score;
		std::cin >> id >> score >> school;
		std::transform(school.begin(), school.end(), school.begin(), ::tolower);
		Data[school].Name = school;
		switch (id[0]) {
			case 'A': Data[school].aScore += score; break;
			case 'B': Data[school].bScore += score; break;
			case 'T': Data[school].tScore += score; break;
		}
		Data[school].nStu += 1;
	}

	std::vector<School> Vec;
	Vec.reserve(Data.size());
	for (auto& i : Data) {
		i.second.Score = static_cast<int>(i.second.bScore / 1.5 + i.second.aScore + i.second.tScore * 1.5);
		Vec.push_back(i.second);
	}

	std::sort(Vec.begin(), Vec.end());
	std::cout << Vec.size() << std::endl;
	int rank, lastScore;
	bool isFirst = true;
	for (size_t i=0; i!=Vec.size(); ++i) {
		if (isFirst) {
			isFirst = false;
			rank = 1;
			lastScore = Vec[i].Score;
		} else {
			if (Vec[i].Score != lastScore) {
				rank = i + 1;
				lastScore = Vec[i].Score;
			}
		}

		std::cout << rank << " " << Vec[i].Name << " " << Vec[i].Score
			<< " " << Vec[i].nStu << std::endl;
	}
	return 0;
}
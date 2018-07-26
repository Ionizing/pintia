#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <tuple>

struct Question {
	int FullScore, nOption, nCrOptn, nWrong;
	std::vector<char> CrrOptn;
	std::vector<int> OptWrong;

	Question(const int& _FullScore, const int& _nOption,
		const int& _nCrOptn, const std::vector<char>& _vec) :
		FullScore(_FullScore), nOption(_nOption), nWrong(0),
		nCrOptn(_nCrOptn), CrrOptn(_vec){};

	friend std::ostream& operator << (std::ostream& output, const Question& q) {
		output << "Question info: FullScore = " << q.FullScore << std::endl
			<< "                nOption  = " << q.nOption << std::endl
			<< "                nCrOptn  = " << q.nCrOptn << std::endl
			<< "                CrrOptn  = ";
			for (auto const& elem : q.CrrOptn) {
				output << elem;
			} output << std::endl;
		return output;
	};

	Question() : FullScore(-1), nOption(-1), nCrOptn(-1), 
			nWrong(0), CrrOptn() {};

	friend std::istream& operator >> (std::istream& input, Question& q) {
		char tmpch;
		input >> q.FullScore >> q.nOption >> q.nCrOptn;
		for (int i=0; i!=q.nCrOptn; ++i) {
			input >> /*tmpch >>*/ tmpch;
			q.CrrOptn.push_back(tmpch);
		}
		return input;
	}

	double Judge(const std::vector<char>& cho) {
		// bool partial_correct = false;
		double res = FullScore;
		OptWrong.resize(nOption, 0);

		// std::cout << " @48, cho & CrrOptn = : ";
		// for (auto i : cho) {
		// 	std::cout << i;
		// } std::cout << ' ';
		// for (auto i : CrrOptn) {
		// 	std::cout << i;
		// } std::cout << std::endl;

		if (cho.size() != CrrOptn.size()) {
			res = (double)FullScore / 2;
		}

		for (const auto& elem : cho) {
			// std::cout << " @61 " << elem << std::endl;
			if (CrrOptn.end() == std::find(CrrOptn.begin(), CrrOptn.end(), elem)) {
				res = .0;
				// std::cout << "   @63 wrong cho = " << elem << std::endl;
				++OptWrong[elem - 'a'];
			}
		}

		for (const auto& elem : CrrOptn) {
			if (cho.end() == std::find(cho.begin(), cho.end(), elem)) {
				++OptWrong[elem - 'a'];
			}
		}
		return res;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	std::ifstream in("in1.txt");
	std::cin.rdbuf(in.rdbuf());
#endif

	int nStu, nQues;
	std::cin >> nStu >> nQues;
	std::vector<Question> q;
	q.reserve(nQues);
	for (int i=0; i!=nQues; ++i) {
		// std::cout << " @51" << std::endl;
		Question tmp;
		std::cin >> tmp;
		q.push_back(tmp);
		// std::cout << tmp;
	}

	// for (auto const& elem : q) {
	// 	std::cout << elem;
	// }

	// judging
	char tmpch;
	std::vector<char> tmpchvec;
	int nCho(0);
	for (int i=0; i!=nStu; ++i) {
		double totScore(.0);
		for (int j=0; j!=nQues; ++j) {
			std::cin >> tmpch;  // tmpch == '('
			// std::cout << tmpch << std::endl;
			tmpchvec.resize(0);
			std::cin >> nCho;
			for (int k=0; k!=nCho; ++k) {
				std::cin >> tmpch;
				tmpchvec.push_back(tmpch);
			}
			// for (auto elem : tmpchvec) {
			// 	std::cout << elem;
			// }
			totScore += q[j].Judge(tmpchvec);
			std::cin >> tmpch;		// tmpch == ')'
			// std::cout << tmpch << std::endl;
		}
		std::cout << std::fixed << std::showpoint;
		std::cout << std::setprecision(1);
		std::cout << totScore << std::endl;
	}

	// processing errdata
	// tuple< errtime, queind, opt>
	std::vector<std::tuple<int, int, char>> ErrData;
	for (int i=0; i!=nQues; ++i) {
		for (int j=0; j!=q[i].nOption; ++j) {
			// if num of wrong != 0, add to ErrData
			if (0 != q[i].OptWrong[j]) {
				ErrData.push_back(std::tuple<int, int, char>(
					q[i].OptWrong[j], i+1, j+'a'));
			}
		}
	}

	if (0 == ErrData.size()) {
		std::cout << "Too simple" << std::endl;
	}

	std::sort(ErrData.begin(), ErrData.end(), 
		[](const std::tuple<int, int, char>& a, const std::tuple<int, int, char>& b){
			if (std::get<0>(a) != std::get<0>(b)) {
				return std::get<0>(a) > std::get<0>(b);
			} else if (std::get<1>(a) != std::get<1>(b)) {
				return std::get<1>(a) < std::get<1>(b);
			} else {
				return std::get<2>(a) < std::get<2>(b);
			}
		});

	int maxerrnum = std::get<0>(ErrData[0]);
	for (auto elem : ErrData) {
		if (maxerrnum != std::get<0>(elem)) {
			break;
		}
		std::cout << std::get<0>(elem) << " " << std::get<1>(elem) 
			<< "-" << std::get<2>(elem) << std::endl;
	}
	return 0;
}
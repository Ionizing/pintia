#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

struct Student {
	std::string Name;
	int Gp, Gm, Gf, G;

	Student() : Name(""), Gp(-1), Gm(-1), Gf(-1), G(-1) {};
	// Student(const std::string& name, const int gp, 
	// 	const int gm, const int gf, const int g) : 
	// 	Name(name), Gp(gp), Gm(gm), Gf(gf), G(g) {};
};

std::unordered_map<std::string, Student> Data;

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif

	int nP, nM, nF;
	std::cin >> nP >> nM >> nF;
	for (int i=0; i!=nP; ++i) {
		std::string name;
		int gp;
		std::cin >> name >> gp;
		Data[name].Gp = gp;
		Data[name].Name = name;
	}

	for (int i=0; i!=nM; ++i) {
		std::string name;
		int gm;
		std::cin >> name >> gm;
		Data[name].Gm = gm;
		Data[name].Name = name;
	}

	for (int i=0; i!=nF; ++i) {
		std::string name;
		int gf;
		std::cin >> name >> gf;
		Data[name].Gf = gf;
		Data[name].Name = name;
	}

	std::vector<Student> vec;
	Student tmp;
	vec.reserve(nF);
	for (const auto& elem : Data) {
		tmp = elem.second;
		if (tmp.Gp < 200 or -1 == tmp.Gf){
			continue;
		}

		if (tmp.Gm > tmp.Gf) {
			tmp.G = static_cast<int>(0.4*tmp.Gm + 0.6*tmp.Gf + 0.5);
		} else {
			tmp.G = tmp.Gf;
		}

		if (tmp.G < 60) {
			continue;
		}
		vec.push_back(tmp);
	}
	std::sort(vec.begin(), vec.end(), [](
		const Student& a, const Student& b){
		if (a.G != b.G) {
			return a.G > b.G;
		} else {
			return a.Name < b.Name;
		}
	});

	for (const auto& elem : vec) {
		std::cout << elem.Name << " " << elem.Gp << " " << elem.Gm
			<< " " << elem.Gf << " " << elem.G << std::endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

int main(int argc, char* argv[]) {
	std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif

	std::string champion, loser, current;
	int N;
	std::cin >> N;
	int x, y;
	double maxdist = 0, mindist = 999, dist;
	for (int i=0; i!=N; ++i) {
		std::cin >> current >> x >> y;
		dist = std::abs(sqrt(x*x + y*y));
		if (dist > maxdist) {
			loser = current;
			maxdist = dist;
		}
		if (dist < mindist) {
			champion = current;
			mindist = dist;
		}
	}

	std::cout << champion << " " << loser << std::endl;
	return 0;
}
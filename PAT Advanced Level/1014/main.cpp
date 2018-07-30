// inspired by `Mahuateng'

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <iomanip>

const int INF = 1 << 30;

struct Customer {
	int processing_time, end_time;  // minutes;
	int index;
	Customer() = default;
	Customer(const int _process_time, const int _index, const int _end_time) : 
		processing_time(_process_time),  end_time(_end_time) ,index(_index) {};
};

std::vector<std::queue<Customer>> Windows; // 每个窗口是一个队列
std::queue<Customer> qCust;	// 所有顾客组成的总体队列

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif

	int nWindow, nCapacity, nCustomer, nQuery;
	std::cin >> nWindow >> nCapacity >> nCustomer >> nQuery;

	std::vector<Customer> vecCustomer;
	vecCustomer.reserve(nCustomer);
	for (int i=0; i!=nCustomer; ++i) {
		int processing_time;
		std::cin >> processing_time;
		qCust.push(Customer(processing_time, i, -1));
		vecCustomer.push_back(Customer(processing_time, i, -1));
	}

	Windows.resize(nWindow); // 开始模拟前将用户填充满窗口队列
	int inqueue = 0;		// 已经在窗口队列的用户数量
	for (int i=0; i!=nCapacity; ++i) { // 当队列长度相同时按窗口序号升序填充
		for (int j=0; j!=nWindow; ++j) {
			if (inqueue >= nCustomer) {
				goto fill_complete;
			} else {
				Windows[j].push(qCust.front());
				qCust.pop();
			}
		++inqueue;
		}
	}
	fill_complete:	// 填充完成

	// 每个窗口上一个顾客离开的时间，这里取相对于开始上班的时间
	std::vector<int> last_complete_time(nWindow, 0); 
	while (true) {
		int minTime = INF, minWindow = -1;
		for (int i=0; i!=nWindow; ++i) { // 寻找所有窗口中第一个完成的
			if (!Windows[i].empty() and 
				Windows[i].front().processing_time 
					+ last_complete_time[i] < minTime) {
				minTime = Windows[i].front().processing_time 
					+ last_complete_time[i];
				minWindow = i;
			}
		}

		if (-1 == minWindow) { // 所有队列为空，即所有窗口的业务都完成
			break;
		} else {
			auto currCus = Windows[minWindow].front();
			Windows[minWindow].pop();
			// 顾客业务完成，退出队列，更新当前窗口上一个业务完成时间
			currCus.end_time = last_complete_time[minWindow] =
				last_complete_time[minWindow] + currCus.processing_time;
			vecCustomer[currCus.index] = currCus;

			// 填充新顾客到当前队列
			if (false == qCust.empty()) {
				Windows[minWindow].push(qCust.front());
				qCust.pop();
			}
		} // end else
	} // end while

	for (int i=0; i!=nQuery; ++i) {
		int ind;
		std::cin >> ind;
		--ind;

		int end_time = vecCustomer[ind].end_time;
		if (end_time - vecCustomer[ind].processing_time >= (17 - 8) * 60) {
			std::cout << "Sorry\n";
			continue;
		} else {
			int HH, MM;
			HH = 8 + end_time / 60;
			MM = end_time % 60;
			std::cout << std::setw(2) << std::setfill('0') << HH << ":" 
				<< std::setw(2) << std::setfill('0') << MM << std::endl;
		}
	}
	return 0;
}
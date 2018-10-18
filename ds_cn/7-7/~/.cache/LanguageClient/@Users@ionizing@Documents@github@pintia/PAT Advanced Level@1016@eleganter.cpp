#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

struct user {
	std::string name;
	int month, day, hour, minute;
	bool online;
	static std::vector<int> FeeUnit;

	user() = default;
	user(const std::string& _name, const int _month, const int _day,
		const int _hour, const int _minute, const bool _online) :
		name(_name), month(_month), day(_day), hour(_hour), minute(_minute),
		online(_online){};

	friend std::ostream& operator << (std::ostream& out, const user& t) {
		out << t.name << " " << t.month << " " << t.day << " " << t.hour 
			<< " " << t.minute << " " << t.online << std::endl;
		return out;
	}
	bool operator < (const user& b) {
		if (name != b.name) {
			return name < b.name;
		} else if (month != b.month) {
			return month < b.month;
		} else if (day != b.day) {
			return day < b.day;
		} else if (hour != b.hour) {
			return hour < b.hour;
		} else {
			return minute < b.minute;
		}
	}

	int operator - (const user& b) {
		if(name != b.name) {
			std::cerr << "User names are different." << std::endl;
			return -1;
		}
		int fee = 0, nMinutes = 0;
		// std::vector<int> call_distrib(24, 0);
		int daybeg = day, hourbeg = hour, minbeg = minute,
			dayend = b.day, hourend = b.hour, minend = b.minute;
		while (true) {
			if (dayend - daybeg > 1) { // 跨两个零点及以上
				int sumofunitfee = 0;
				for (int i=0; i!=24; ++i) {
					sumofunitfee += FeeUnit[i];
				}
				nMinutes += (dayend - daybeg - 1) * 24 * 60;
				fee += (dayend - daybeg - 1) * 60 * sumofunitfee;
				daybeg = dayend - 1;
			} else if (dayend - daybeg == 1) { // 跨一个零点
				nMinutes += (24 - hourbeg - 1) * 60 + (60 - minbeg);
				for (int i=hourbeg+1; i!=24; ++i) {
					fee += FeeUnit[i] * 60;
				}
				fee += (60 - minbeg) * FeeUnit[hourbeg];
				daybeg = dayend;
				hourbeg = minbeg = 0;
			} else { // 不垮零点
				if (hourbeg != hourend) {
					nMinutes += 60 - minbeg + (hourend - hourbeg - 1) * 60;
					fee += FeeUnit[hourbeg] * (60 - minbeg);
					for (int i=hourbeg+1; i!=hourend; ++i) {
						fee += FeeUnit[i] * 60;
					}
					minbeg = 0;
					hourbeg = hourend;

					// nMinutes += 60 - minbeg;
					// fee += FeeUnit[hourbeg] * (60 - minbeg);
					// minbeg = 0;
					// ++hourbeg;
				} else {
					nMinutes += minend - minbeg;
					fee += FeeUnit[hourbeg] * (minend - minbeg);
					break; // 费用和通话时间在这里计算完毕
				}
			} // end else
			// std::cout << " @87 nMinutes = " << nMinutes << std::endl;
		} // end while
		char timesep = ':';
		std::cout << std::setw(2) << day << timesep << std::setw(2) << hour << timesep << std::setw(2) << minute << ' '
			<< std::setw(2) << b.day << timesep << std::setw(2) << b.hour << timesep << std::setw(2) << b.minute << ' '
			<< nMinutes << ' '
			<< "$" << (fee + .0) / 100 << std::endl;
		return fee;
	}
};

std::vector<int> user::FeeUnit = std::vector<int>(24, 0);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif
	for (int i=0; i!=24; ++i) {
		std::cin >> user::FeeUnit[i];
	}

	int nRecord;
	std::cin >> nRecord;
	std::vector<user> rawData;
	user tmp; char tmpch;
	std::string status;
	for (int i=0; i!=nRecord; ++i) {
		std::cin >> tmp.name >> tmp.month >> tmpch >> tmp.day 
			>> tmpch >> tmp.hour >> tmpch >> tmp.minute >> status;
		tmp.online = ('n' == status[1]) ? true : false;
		rawData.push_back(tmp);
	}

	std::sort(rawData.begin(), rawData.end());
	// for (const auto& e : rawData) {
	// 	std::cout << e;
	// } std::cout << "\n\n\n";

	std::vector<user> filtered;
	filtered.reserve(20);
	int size = rawData.size();
	for (int i=0; i<size-1; ++i) {
		if (rawData[i].name == rawData[i+1].name and 
			(true == rawData[i].online and false == rawData[i+1].online)) {
			filtered.push_back(rawData[i]);
			filtered.push_back(rawData[i+1]);
			++i;
		}
	}

	std::cout << std::setprecision(2) << std::fixed << std::setfill('0');

	size = filtered.size();
	std::string lastname;
	int lastmonth = 0;
	int fee;
	for (int i=0; i<size; i+=2) {
		if (filtered[i].name != lastname or
			filtered[i].month != lastmonth) {
			if (0 != i) {
				std::cout << "Total amount: $" 
					<< (fee + .0) / 100 << std::endl;
					fee = 0;
			}
			lastname = filtered[i].name;
			lastmonth = filtered[i].month;
			std::cout << lastname << ' ' << std::setw(2) 
				<< std::setfill('0') << lastmonth << std::endl;
		}
		fee += filtered[i] - filtered[i+1];
	}
	std::cout << "Total amount: $"
		<< (fee + .0) / 100 << std::endl;

 	return 0;
}
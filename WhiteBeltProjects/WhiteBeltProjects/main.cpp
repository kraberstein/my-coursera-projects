#include "coursera.h"

//	enum MONTH { JAN = 31, FEB = 28, MAR = 31 };
//	≈жедневные дела реализовать через map<int, vector<string>>

int main() {
	map<string, vector<string>> buses_and_stops;
	map<int, string> queueBus;
	int queueBusNum = 0;
	bool isAnyStop = false;
	vector<string> stops;
	vector<string> interchBuses;
	string operation, bus, stop, stop_;
	int Q, stop_count, interchanges_count = 0;
	cin >> Q;
	for (int i = 0; i != Q; ++i) {
		cin >> operation;
		if (operation == "NEW_BUS") {
			stops.clear();
			cin >> bus >> stop_count;
			for (int i = 0; i != stop_count; ++i) {
				cin >> stop;
				buses_and_stops[bus].push_back(stop);
			}
			queueBus[++queueBusNum] = bus;
		}
		if (operation == "BUSES_FOR_STOP") {
			cin >> stop;
			for (const auto& buses : buses_and_stops) {
				for (const auto& stop_ : buses.second) {
					if (stop == stop_) {
						interchBuses.push_back(buses.first);
						isAnyStop = true;
					}		
				}
			}
			for (const auto& qB : queueBus) {
				for (const auto& iB : interchBuses) {
					if (qB.second == iB) {
						cout << iB << " ";
					}
				}
			}
			if (!isAnyStop) {
				cout << "No stop";
			}
			interchBuses.clear();
			isAnyStop = false;
			cout << endl;
		}
		if (operation == "STOPS_FOR_BUS") {
			cin >> bus;
			if (buses_and_stops.count(bus) == 0) {
				cout << "No bus" << endl;
			}
			else {
				for (const auto& buses : buses_and_stops) {
					if (buses.first == bus) {
						for (const auto& s : buses.second) {
							cout << "Stop " << s << ": ";
							for (const auto& stops_ : buses_and_stops) {
								if (count(begin(stops_.second), end(stops_.second), s) == 1 && 
									bus != stops_.first) {	
									interchBuses.push_back(stops_.first);
									++interchanges_count;
								}
							}
							for (const auto& qB : queueBus) {
								for (const auto& iB : interchBuses) {
									if (qB.second == iB) {
										cout << iB << " ";
									}
								}
							}
							if (interchanges_count == 0) {
								cout << "no interchange";
							}
							interchanges_count = 0;
							interchBuses.clear();
							cout << endl;
						}
					}
				}
			}
		}
		if (operation == "ALL_BUSES") {
			if (buses_and_stops.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (const auto& bus : buses_and_stops) {
					cout << "Bus " << bus.first << ": ";
					for (const auto& stop : bus.second) {
						cout << stop << " ";
					}
					cout << endl;
				}
			}
		}
	}

	return 0;
}

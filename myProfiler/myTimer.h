#pragma once

#include <chrono>
#include <iostream>
#include <vector>
#include <unordered_map>

namespace timer {
	typedef std::chrono::time_point<std::chrono::high_resolution_clock> timepoint_t;

	class Timer {
		public:
			void start() {
				startTime = std::chrono::high_resolution_clock::now();
			}
	
			void stop() {
		        endTime = std::chrono::high_resolution_clock::now();
				auto dur = std::chrono::duration<double, std::milli>(endTime - startTime);
	
				//std::cout << "Timer was alive for " << dur.count() << " ms" << std::endl;
				std::cout << "Timer stopped" << std::endl;
			}
	
			void stop(std::string name) {
				ended[name] = true;
		        auto endTime = std::chrono::high_resolution_clock::now();
				checkpointTimes[name].push_back(endTime);
			}
	
			void checkpoint(std::string name) {
				if (ended[name]) {
					std::cout << "WARNING: Trying to checkpoint time which has ended" << std::endl;
					return;
				}
				if (!checkpointTimes.count(name)) {
					ended[name] = false;
					order.push_back(name);
					int s = name.size();
					longestName = std::max(longestName, s);
				}
				checkpointTimes[name].push_back(std::chrono::high_resolution_clock::now());
			}
	
			void print(std::string name) {
				std::vector<timepoint_t> &times = checkpointTimes[name];
				auto totalDuration = std::chrono::duration<double, std::milli>(times[times.size() - 1] - times[0]);
				std::cout << name << " took " << totalDuration.count() << " ms" << std::endl;
			}
	
			void pad(int n, char c) {
				printf("%s", std::string(n, c).c_str());
			}
	
			template<typename T>
			auto getDuration(timepoint_t start, timepoint_t end) {
				return std::chrono::duration<double, T>(end - start);
			}
	
			void print() {
				// name | totalTime | iterations | average
				// pad appropriately
				pad(longestName - 4, ' ');
				printf("name |      time      | iterations |    average     | max \n");
				pad(longestName - 4, '-');
				printf("----------------------------------------------------------\n");
				
				auto totalTime = getDuration<std::milli>(startTime, endTime);
				std::string type = "(ms)";
				if (totalTime < std::chrono::milliseconds{1}) {
					totalTime = getDuration<std::micro>(startTime, endTime);
					type = "(μs)";
				}
				auto time = totalTime.count();
				pad(longestName - 11, ' ');
				printf("TIMER TOTAL | %9.5lf %s |            |                |\n", time, type.c_str());
	
				for (std::string name : order) {
					if (!ended[name])
						checkpoint(name);
	
					std::vector<timepoint_t> &times = checkpointTimes[name];
					pad(longestName - name.size(), ' ');

					auto longestTime = getDuration<std::milli>(times[0], times[1]);
					std::string longestType = "(ms)";
					int longestID = 0;
					for (int i=1; i<times.size()-1; i++) {
						auto temp_d = getDuration<std::milli>(times[i], times[i+1]);
						if (longestTime < temp_d) {
							longestTime = temp_d;
							longestID = i;
						}
					}
					if (longestTime < std::chrono::milliseconds{1}) {
						longestTime = getDuration<std::micro>(times[longestID], times[longestID + 1]);
						longestType = "(μs)";
					}
					
					auto totalTime = getDuration<std::milli>(times[0], times[times.size() - 1]);
					std::string type = "(ms)";
					if (totalTime < std::chrono::milliseconds{1}) {
						totalTime = getDuration<std::micro>(times[0], times[times.size() - 1]);
						type = "(μs)";
					}
	
					auto time = totalTime.count();
					printf("%s | %9.5lf %s | %10lu | %9.5lf %s | %9.5lf %s\n", name.c_str(), time, type.c_str(), times.size() - 1, time/(times.size() - 1), type.c_str(), longestTime.count(), longestType.c_str());
					//print(name);
				}
				printf("\n");
			}
	
		private:
			std::unordered_map<std::string, std::vector<timepoint_t>> checkpointTimes;
			timepoint_t startTime;
			timepoint_t endTime;
			std::vector<std::string> order;
			std::unordered_map<std::string, bool> ended;
			int longestName = 11;
	};

	Timer m_timer;
	void checkpoint(std::string name) {
		m_timer.checkpoint(name);
	}

	void print() {
		m_timer.print();
	}

	void print(std::string name) {
		m_timer.print(name);
	}

	void start() {
		m_timer.start();
	}

	void stop() {
		m_timer.stop();
	}

	void stop(std::string name) {
		m_timer.stop(name);
	}
}

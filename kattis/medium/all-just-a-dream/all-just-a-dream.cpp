#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <list>
#include <map>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	vector<string> events;  // events as they happen 
	map<string, int> eventMap;  // event : time the event occurred or -1

	int time = 0;
    for (int i = 0; i < n; i++) {
		string type;
		cin >> type;

		if (type == "E") {  // it is an event
			string event;
			cin >> event;
			events.push_back(event);
			eventMap[event] = time++;  // the event has happened
		} else if (type == "S") {  // it is a scenario, check for logical inconsistencies
			int scenarios;
			cin >> scenarios;
			int lower = INT32_MAX;
			int normal = -1;
			bool plotError = false;
			for (int j=0; j<scenarios; j++) {
				string scene;
				cin >> scene;

				if (plotError)
					continue;
				
				// Is the scene a `!` (not)?
				// remove the '!' from the scene
				
				if (scene[0] == '!') {
					string event = scene.substr(1, scene.length() - 1);
					map<string, int>::iterator it = eventMap.find(event);
					
					if (it != eventMap.end()) {
						lower = min(lower, it->second);
					}
				} else {
					map<string, int>::iterator it = eventMap.find(scene);
					
					if (it == eventMap.end()) {  // you are trying to find it but can't
						plotError = true;
						continue;
					} else {  // you found it
						normal = max(normal, it->second);
					}
				}
			}

			if (plotError || normal >= lower)
				printf("Plot Error\n");
			else {
				int diff = time - lower;
				if (diff > 0)
					printf("%d Just A Dream\n", diff);
				else
					printf("Yes\n");  // this is valid
			}
		} else if (type == "D") {
			// delete some dreams
			int num;
			cin >> num;
			
			for (int i=0; i < num; i++) {
				// delete this event
				string event = events.back();
				events.pop_back();

				// remove it from the map
				eventMap.erase(event);
			}
			time -= num;
		}
    }

    return 0;
}

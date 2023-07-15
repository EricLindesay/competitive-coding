#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

class Robot {
public:
	void move(int distance) {
		x += distance * sin(angle * (M_PI / 180.0));
		y += distance * cos(angle * (M_PI / 180.0));
	}

	void rotate(int degrees) {
		angle += degrees;
	}

	int distance(int x, int y) {
		return round(sqrt(pow(this->x - x, 2) + pow(this->y - y, 2)));
	}

	double x = 0;
	double y = 0;
	int angle = 0;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		Robot robot;
		while (n--) {
			// read in the specific line
			string command;
			int dist;
			cin >> command >> dist;
			if (command == "fd") {
				// read number
				robot.move(dist);
			} else if (command == "bk") {
				robot.move(-1 * dist);
			} else if (command == "lt") {
				robot.rotate(dist);
			} else if (command == "rt") {
				robot.rotate(-1 * dist);
			}
		}

		// find distance to start point, output rounded to nearest int
		cout << robot.distance(0, 0) << endl;		
	}

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

#define MARGIN_OF_ERROR pow(10, -10)

using namespace std;

int pyMod(int a, int b) {
	return (b + (a % b)) % b;
}

double round_to_digits(double value, int digits) {
    if (value == 0.0) // otherwise it will return 'nan' due to the log10() of zero
        return 0.0;

    double factor = pow(10.0, digits - ceil(log10(fabs(value))));
    return round(value * factor) / factor;
}

bool close_enough(double a, double b) {
	return abs(a - b) < MARGIN_OF_ERROR;
}

class Robot {
public:
	void parseCommand(string command, int amount) {
		if (command == "fd") {
			move(amount);
		} else if (command == "bk") {
			move(-1 * amount);
		} else if (command == "rt") {
			rotate(amount);
		} else if (command == "lt") {
			rotate(-1 * amount);
		}
	}

	void invertCommand(string command, int amount) {
		if (command == "fd") {
			move(-1 * amount);
		} else if (command == "bk") {
			move(amount);
		} else if (command == "rt") {
			rotate(-1 * amount);
		} else if (command == "lt") {
			rotate(amount);
		}
	}

	void move(int distance) {
		x += distance * sin(angle * (M_PI / 180));
		y += distance * cos(angle * (M_PI / 180));
	}

	void rotate(int rotation) {
		angle = pyMod(angle + rotation, 360);
	}

	double distance(Robot robot) {
		return sqrt(pow(robot.x - x, 2) + pow(robot.y - y, 2));
	}

	bool operator==(const Robot &robot) {
		if (!close_enough(x, robot.x))
			return false;

		if (!close_enough(y, robot.y))
			return false;

		if (robot.angle != angle)
			return false;

		return true;
	}

	bool pos_eq(const Robot &robot) {
		// compare abs values and see if they are close enough
		if (!close_enough(x, robot.x))
			return false;

		if (!close_enough(y, robot.y))
			return false;

		return true;
	}

	double x = 0;
	double y = 0;
	int angle = 0;  // angle in degrees
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		vector<pair<string, int>> afterQ;
		string questionCommand;

		Robot forwards;
		bool startAdding = false;
		while (n--) {
			string command;
			cin >> command;
			string amount;
			cin >> amount;

			if (amount == "?") {  // we need to start adding to the afterQ
				startAdding = true;
				questionCommand = command;
				continue;
			}

			if (startAdding) {  // start adding it to the afterQ
				afterQ.push_back({command, stoi(amount)});
			} else {  // otherwise, just get the forwards robot to do it
				forwards.parseCommand(command, stoi(amount));
			}
		}

		// Go through each possible angle
		for (int i=0; i<360; i++) {
			Robot robot;
			robot.angle = i;

			// Parse the commands for the robot
			for (auto it = afterQ.rbegin(); it != afterQ.rend(); it++) {
				robot.invertCommand(it->first, it->second);
			}

			// See if the robot matches the criteria, remember there is exactly one solution
			if (questionCommand == "fd" || questionCommand == "bk") {
				// the robot angle must be the same
				if (robot.angle != forwards.angle)  // not the same so try the next angle
					continue;

				// the angle is the same, calculate how much they have to move
				double dist = forwards.distance(robot);
				if (static_cast<int>(dist) == round_to_digits(dist, 10)) {
					// it is an integer
					// see if its the right direction by simulating it
					forwards.parseCommand(questionCommand, static_cast<int>(dist));
					if (forwards == robot) {
						cout << dist << endl;
						break;
					}  // it didn't work
					   // undo the movement
					forwards.parseCommand(questionCommand, -1 * static_cast<int>(dist));
				}
			} else if (questionCommand == "rt") {
				// make sure the position is the same
				if (!forwards.pos_eq(robot))
					continue;

				// find how much to rotate
				int rotationAmount = pyMod(robot.angle - forwards.angle, 360);
				cout << rotationAmount << endl;
				break;
			} else if (questionCommand == "lt") {
				// make sure the position is the same
				if (!forwards.pos_eq(robot))
					continue;

				// find how much to rotate
				int rotationAmount = pyMod(forwards.angle - robot.angle, 360);
				cout << rotationAmount << endl;
				break;
			}
		}
	}

    return 0;
}

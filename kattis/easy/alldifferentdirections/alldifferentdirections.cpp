#include <bits/stdc++.h>
#include <numeric>

typedef long long ll;

using namespace std;

double degToRad(double deg) {
	return deg * M_PI/180;
}

double radToDeg(double rad) {
	return rad * 180/M_PI;
}

double pyMod(double n, double m) {
	while (n < 0) {
		n += m; 
	}
	while (n > m) {
		n -= m;
	}

	return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

	string line;
	while (cin >> n && n) {
		getline(cin, line);  // for formatting
		vector<double> endX;
		vector<double> endY;
		while (n--) {
			getline(cin, line);
			cout << "line: " << line << endl;
			stringstream ss(line);

			string wordX;
			string wordY;
			getline(ss, wordX, ' ');
			getline(ss, wordY, ' ');
			double x = stod(wordX);
			double y = stod(wordY);

			string start;
			getline(ss, start, ' ');  // the start command
			getline(ss, start, ' ');  // the start angle value
			double angle = pyMod(stod(start), 360);
			
			string cmd;
			string valStr;
			double val;
			cout << '\t' << "Start x: " << x << " y: " << y << endl;
			while (getline(ss, cmd, ' ')) {
				getline(ss, valStr, ' ');
				val = stod(valStr);

				if (cmd == "walk") {
					cout << "Cos: " << ::cos(degToRad(angle)) << endl;
					cout << "Sin: " << ::sin(degToRad(angle)) << endl;
					x += val * ::cos(degToRad(angle));
					y += val * ::sin(degToRad(angle));
				} else if (cmd == "turn") {
					cout << "before: " << angle << endl;
					angle = pyMod(angle + val, 360);
					cout << "After: " << angle << endl;
				}
				cout << '\t' << "x: " << x << " y: " << y << endl;
			}
			cout << "Add " << "x: " << x << " y: " << y << endl;
			endX.push_back(x);
			endY.push_back(y);
		}

		// use endX and endY to find the average and then the distance to the worst
		double xAverage = accumulate(endX.begin(), endX.end(), 0) / (double) endX.size();
		double yAverage = accumulate(endY.begin(), endY.end(), 0) / (double) endY.size();
		double dist = 0;  // worst distance
		for (int i=0; i<endX.size(); i++) {
			double tdist = sqrt(pow(endX[i] - xAverage, 2) + pow(endY[i] - yAverage, 2));
			dist = max(dist, tdist);
		}
		printf("%.2lf %.2lf %.2lf\n", xAverage, yAverage, dist);
	}

    return 0;
}

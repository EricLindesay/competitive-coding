#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

class uint256_t {
public:
	uint32_t bits[8];
	uint32_t maxsize = UINT32_MAX;

	uint256_t() {
		memset(bits, 0, 8 * sizeof(uint32_t));
	}

	uint256_t operator*(uint64_t &other) {
		uint256_t result;
		// split the input into two 32 bit numbers
		// then multiply and store result in ll when doing calculations
		// do each multiplication as each bit of the number using mod and stuff
		// then add the results
	
		// multiplication operator

		// split the input into 32 bit number
		uint32_t input[2];
		input[1] = other / maxsize;
		//input[0] = other % maxsize;
		input[0] = (input[1]*maxsize) - other;

		// multiply in 32 bit blocks
		// when multiplying with input[1], offset it by a block
		
		// do input[0], multiply each block by input[0].
		// have to make sure it doesn't overflow
		for (int i=0; i<8; i++) {
			uint64_t multiplication = static_cast<uint64_t>(input[0]) * static_cast<uint64_t>(this->bits[i]);
			printf("%u * %u = %lu\n", input[0], this->bits[i], multiplication);
			printf("multiplication: %lu\n", multiplication);
			if (willOverflow(result.bits[i]+this->bits[i], multiplication)) {
				printf("bits[%d] is overflowing\n", i);
				// calculate how much should remain
				// add one to the next result
				uint64_t remaining = (multiplication - (maxsize - result.bits[i]));
				result.bits[i] += multiplication % maxsize;
				result.bits[i+1] += multiplication/maxsize;
				printf("%09u|%09u\n", result.bits[i+1], result.bits[i]);
				printf("\n");
			} else {
				printf("bits[%d] Won't overflow\n", i);
				result.bits[i] += multiplication;
			}
		}
		return result;
	}

	bool willOverflow(uint64_t bitsNum, uint64_t num) {
		cout << bitsNum << " " << num << " " << maxsize << endl;
		return (num > maxsize - bitsNum);
	}

	uint256_t operator+(const uint64_t &other) {  // other is guarateed to be positive in this 
		uint256_t res;
		for (int i=0; i<8; i++) {
			res.bits[i] = this->bits[i];
		}
		
		// split the input into two uint32_t
		uint32_t input[8];
		input[0] = other % maxsize;
		input[1] = other - other % maxsize;
		// fill the remaining with zeros
		memset(&input[2], 0, 6 * sizeof(uint32_t));

		if (willOverflow(res.bits[0], input[0])) {
		}
		uint64_t dist = maxsize - bits[0];
		if (other > dist) { // it is too large, overflow it into next bit
			uint64_t overflow = other - dist;
			// need to check overflow for the next 1
			res.bits[1] += overflow;
			res.bits[0] = other - overflow;
		} else {
			res.bits[0] += other;
		}
		return res;
	}
	
	void print() {
		for (int i=7; i > -1; i--) {
			printf("%09u|", bits[i]);
		}
		printf("\n");
	}
};

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n;
    cin >> n;

	//printf("\n\n%lu\n\n", static_cast<uint64_t>(UINT32_MAX) * static_cast<uint64_t>(UINT32_MAX));
	//printf("\n\n%lu\n\n", UINT64_MAX);

	uint256_t test;
	test.bits[0] = test.maxsize;
	test.print();
	uint64_t multiple = test.maxsize;
	test = test * multiple;
	test.print();

	return 0;
	
	// semifinals always take 1 bag each, finals and play for third both take a bag each
	ll output = 4;
	ll groupSize = n/4;
	ll perGroup = 0.5 * groupSize * (groupSize - 1);
	output += perGroup * 4;

	cout << output << endl;

    return 0;
}

#include <vector>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

class Solution
{
public:
	int longestArithSeqLength(vector<int> &nums)
	{
		// have an array of "starter positions". These are just the elements as you see them
		// have an array of valid sequences (key= the difference, value = vector of posible sequecnes, for each sequence, store the most recent position + length)
		// when you see a new element, compare it to each starter position, find the difference and increment the map
		vector<int> starter_positions;
		map<int, vector<pair<int, int>>> sequences; // difference : {most_recent, occurrences}
		int longest_sequence = 0;

		for (int num : nums)
		{
			// compare it to each starter position
			for (int starter_pos : starter_positions)
			{
				// get the difference
				int difference = num - starter_pos;

				// is there a key for that sequence yet?
				auto it = sequences.find(difference);
				if (it == sequences.end())
				{ // this key doesn't exist yet, create it
					sequences[difference] = vector<pair<int, int>>();
					sequences[difference].push_back({num, 1});
					longest_sequence = max(longest_sequence, 1);
				}
				else
				{ // this key already exists
					// look at each sequence in the thing and see if it follows on from the sequence
					vector<pair<int, int>> sequence = sequences[difference];
					for (int i = 0; i < sequence.size(); i++)
					{
						printf("Pair: <%d, %d>\n", sequence[i].first, sequence[i].second);

						// if it works for the sequence, increment the count
						if (num - sequence[i].first == difference)
						{
							sequences[difference][i].second++;
							sequences[difference][i].first = num;
							longest_sequence = max(longest_sequence, sequences[difference][i].second);
						}
						else
						{
							// Otherwise create a new sequence in this vector
							sequences[difference].push_back({num, 1});
							longest_sequence = max(longest_sequence, 1);
						}
					}
				}
			}

			// add it to the starter positions
			starter_positions.push_back(num);
		}
		return longest_sequence + 1; // plus 1 because you need to include the start element as well
	}
};

int main()
{
	vector<int> vect{83, 20, 17, 43, 52, 78, 68, 45};
	cout << Solution().longestArithSeqLength(vect) << endl;
}

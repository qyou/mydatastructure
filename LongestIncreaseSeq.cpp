#include <iostream>
#include <vector>
using namespace std;
/*

Input: 1 2 5 9 3 6 10
Output:1 2 5 9 10

 */

//O(n)
/* find the longest increase sequences from start index*/
void LIS(vector<int> input, int start, vector<int>& c, vector<string>& b) {
	int m = input.size();
	for (int i=0; i<start; ++i) {
		c.push_back(0);
		b.push_back("↑");
	}
	for (int i=start; i<m; ++i) {
		c.push_back(1);
		b.push_back("←");
	}

	for (int i=start+1; i<m; ++i) {
		if (input[c[i-1]-1] < input[i]) {
			c[i] = c[i-1]+1;
			b[i] = "←";
		} else {
			c[i] = c[i-1];
			b[i] = "↑";
		}
	}
}


int main() {
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(5);
	input.push_back(9);
	input.push_back(3);
	input.push_back(6);
	input.push_back(10);

	vector<int> c;
	vector<string> b;
	LIS(input, 0, c, b);
	for(vector<int>::iterator iter=c.begin(); iter!=c.end(); ++iter) {
			cout << *iter << " ";
	}
	cout << endl;

	for(vector<string>::iterator iter=b.begin(); iter!=b.end(); ++iter) {
			cout << *iter << " ";
	}
	cout << endl;

	cout << "Hello, world" << endl; // prints Hello, world
	return 0;
}

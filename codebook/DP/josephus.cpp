#include <bits/stdc++.h>

using namespace std;

int main() {

	int num_of_people;
	int num_to_count;

	cin >> num_of_people >> num_to_count;

	int last_people = 0;
	for(int i = 2 ; i < num_of_people ; i++) {

		last_people = (last_people+num_to_count)%i;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int i, num;
	vector <int> vi(0);
	cout << "the size is " << vi.size() << endl;
	for(i = 0; i < 5; i++) {
		cin >> num;
		vi.push_back(num);
	}
	cout << "the size is " << vi.size() << endl;
	vector <int> vm(0);
	for(i = 0; i < 5; i++) {
		cin >> num;
		vm.push_back(num);
	}
	vector <int> :: iterator pd;
	vi.insert(vi.begin(), vm.begin(), vm.end());
	cout << "the size is " << vi.size() << endl;
	sort(vi.begin(), vi.end());
	for(pd = vi.begin(); pd != vi.end(); pd++)
		cout << *pd << endl;
	cout << endl;
	string s1;
	getline(cin, s1);
	string s2("world");
	s1 += s2;
	cout << s1[s1.find("or")];
	cout << s1 << endl;
	return 0;
}

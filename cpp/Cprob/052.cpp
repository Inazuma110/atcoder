#include <iostream>
// #include <>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int count = 1;
	int SOSU = 1;

	while(num != count){
		if (count % num == 0)SOSU++;
		num += 1;
	}
	SOSU %= 1000000000 + 7;
	cout << SOSU << endl;
	
}
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int n,tmp;
	cin >> n;
	vector<int> vec;
	int sum = 0;
	int ave = 0;
	int result = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		vec.push_back(tmp);
		sum += vec[i];
	}

	if (sum % n != 0)
	{
		cout << "-1" << endl;
		exit(1);
	}
	
	ave = sum / n;


	for (int i = 0; i < n-1; i++)
	{
		if (vec[i] > ave)
		{
			vec[i+1] += (vec[i]-ave);
			vec[i] -= (vec[i]-ave);
			result++;
		}
	}

	for (int i = n-1; i > 0; i--)
	{
		if (vec[i] > ave)
		{
			vec[i-1] += (vec[i]-ave);
			vec[i] -= (vec[i]-ave);
			result++;
		}
	}

	cout << result << endl;
}
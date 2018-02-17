//パワーコードを書かないといけないので無理


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,b;
	cin >> a >> b;
	bool win = true;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '@' && 
			(b[i] == 'a' || b[i] == 't' || b[i] == 'c' 
				|| b[i] == 'o' || b[i] == 'd' || b[i] == 'e' || b[i] == 'r'))
		{
			win = true;
		}
		else if (a[i] != b[i])
		{
			win = false;
			break;
		}
	}

	if (win == true)
	{
		cout << "you can win" << endl;
	}else{
		cout << "you will lose";
	}
}
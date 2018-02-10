#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <sstream>
typedef long long ll;
using namespace std;

int main()
{
// input
  int x,k;
  cin >> x >> k;
//
  int result = 0;
  string tmp;

  if (k == 0) {
    result = x + 1;
    // exit(1);
  }
  else if (k > log10(x)) {
    result = pow(10,k);
  }
  else
  {
    stringstream ss;
    ss << x;
    tmp = ss.str();
    for(int i = 0; i < k; i++ )
    {
      tmp[sizeof(x)-(i+1)] = '0';
    }
    result = stoi(tmp);
    if (result <= x) {
      result += pow(10,k);
    }
  }

  std::cout << result << '\n';
}

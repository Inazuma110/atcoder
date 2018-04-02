#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> p;


int main()
{
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  vector<char> v(int(s.size()), 'a');
  for (int i = 0; i < int(s.size()); i++){
    v[i] = s[i];
  }
  set<char> set(v.begin(), v.end());
  vector<char> v2(set.begin(), set.end());
  

  for (int i = 0; i < int(v2.size())-1; i++){
    if (v2[i] == v2[i+1]) {
      continue;
    }
    char tmp = v2[i];
    tmp++;
    if (tmp != v2[i+1]) {
      cout << tmp << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}

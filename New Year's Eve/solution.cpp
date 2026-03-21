#include <algorithm>
#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int fahrten, bahn25, bahn50, bahn100;
  cin >> fahrten;
  cin >> bahn25;
  cin >> bahn50;
  cin >> bahn100;

  int kosten = fahrten * 100;

  std::array<std::pair<int, string>, 4> res;

  res[0] = {kosten - (kosten / 4) + bahn25, "Bahncard 25"};
  res[1] = {kosten - (kosten / 2) + bahn50, "Bahncard 50"};
  res[2] = {bahn100, "Bahncard 100"};
  res[3]  = {kosten, "no Bahncard"};

  sort(res.begin(), res.end());
  cout << res[0].second << endl;
  /*for (auto tmp : res) {
    cout << tmp.second << endl;
  }*/

  return 0;
}

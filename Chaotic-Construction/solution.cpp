#include <string>
#include <iostream>
#include <charconv>
#include <functional>
#include <cmath>
#include <set>
#include <map>

using namespace std;
set<unsigned int, greater<unsigned int>> Blockaden = {};


int main()
{
    long long n, q;
    cin >> n >> q;

    for (long i{0}; i < q; i++)
    {
        char event;
        cin >> event;
        if (event == '+')
        {
            //Remove old barricade
            unsigned int segment = 0;
            cin >> segment;
            //cout << "+ " << segment << endl;
            Blockaden.erase(segment);
        }
        else if (event == '-')
        {
            //Insert new barricade
            unsigned int segment = 0;
            cin >> segment;
            //cout << "- " << segment << endl;
            Blockaden.insert(segment);
        }
        else if (event == '?')
        {
            unsigned int a, b;
            cin >> a >> b;

            if (Blockaden.empty())
            {
                cout << "possible" << endl;
                continue;
            }

            // prüfen, ob a oder b direkt blockiert sind
            if (Blockaden.find(a) != Blockaden.end())
            {
                cout << "impossible" << endl;
                continue;
            }
            if (Blockaden.find(b) != Blockaden.end())
            {
                cout << "impossible" << endl;
                continue;
            }

            //ensuring that b is always greater than a
            if (b < a)
            {
                swap(a, b);
            }

            bool firstLanePossible = true;
            bool secondLanePossible = true;
            bool thirdLanePossible = true;

            auto BoundOne = Blockaden.lower_bound(a);
            auto BoundTwo = Blockaden.lower_bound(b);
            auto BoundThree = Blockaden.lower_bound(n);
            if (BoundOne != Blockaden.end())
            {
                firstLanePossible = false;
            }
            if (BoundTwo != Blockaden.end() && *BoundTwo > a )
            {
                secondLanePossible = false;
            }
            if (BoundThree != Blockaden.end() && *BoundThree > b)
            {
                thirdLanePossible = false;
            }

            if (!firstLanePossible && !secondLanePossible || !secondLanePossible && !thirdLanePossible)
            {
                cout << "impossible" << endl;
            }
            else
            {
                cout << "possible" << endl;
            }
        }
    }
    return 0;
}
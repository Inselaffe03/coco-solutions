#include <iostream>
#include <vector>
#include <format>
#include <algorithm>
#include <ranges>
#include <functional>
#include <cmath>
#include <set>
#include <map>

using namespace std;

long long a, m, k;
set<long long, greater<long long>> alleTeiler = {};
vector<long long> primeComponents;
map<long long, int> numOfDividersMap;


void addPrimeToComponents(long long prime)
{
    if (numOfDividersMap.find(prime) != numOfDividersMap.end())
    {
        primeComponents.emplace_back(prime);
        numOfDividersMap[prime]++;
    }
    else
    {
        primeComponents.emplace_back(prime);
        numOfDividersMap[prime] = 1;
    }
}


long long getNumOfDividers() {
    auto n = m;
    long long numOfDividers = 1;
    while (n % 2 == 0) {
        addPrimeToComponents(2);
        n = n / 2;
    }

    for (long long i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            addPrimeToComponents(i);
            n = n / i;
        }
    }

    if (n > 2)
    {
        addPrimeToComponents(n);
    }
    for (const auto& divider : numOfDividersMap)
    {
        numOfDividers *= (divider.second+1);
    }
    return numOfDividers;
}



void getTeilerPrimZahlZerlegung(long long maxZahl) {
    const auto numOfDividers = getNumOfDividers();

    if (numOfDividers < k) //not enough possible dividers. Don't waste time trying to find them.
    {
        return;
    }
    alleTeiler.insert(m);
    if (alleTeiler.size() == k) {
        return;
    }

    long long sizePrimeComponents = primeComponents.size();
    long long currentNumber = 0;
    // A
    alleTeiler.insert(1);
    for (int i = 0; i < sizePrimeComponents; i++) {
        alleTeiler.insert(primeComponents[i]);
        // B
        for (int j =0; j < sizePrimeComponents; j++) {
            for (long long l =1; l < 10000; l++) {
                currentNumber = primeComponents[i]* primeComponents[j]*l;
                if (currentNumber > maxZahl/2)
                {
                    continue;
                }
                if (maxZahl % currentNumber == 0) {
                    alleTeiler.insert(currentNumber);
                }
            }
        }
    }
    //cout << maxZahl << " has " << numOfDividers << " dividers of which " << alleTeiler.size() << " were found" << endl;

    //not all dividers found by loops above
    //find more by getting the larger dividers directly
    int factor = 1;
    vector<long long> temp;
    while(alleTeiler.size() < numOfDividers)
    {
        factor++;
        long long currentNumber = maxZahl / factor;
        if (maxZahl % currentNumber == 0)
        {
            alleTeiler.insert(currentNumber);
        }
    }
    //cout << maxZahl << " has " << numOfDividers << " dividers of which " << alleTeiler.size() << " were found" << endl;
}



int main() {
    cin >> a;
    cin >> m;
    cin >> k;
    //a, m, k (0 ≤ a < m ≤ 10^12, 1 ≤ k ≤ 10^6)

    getTeilerPrimZahlZerlegung(m);

    if (alleTeiler.size() < k) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << "possible" << endl;

    vector<long long> chosen;

    for (long long d : alleTeiler)   {
        chosen.push_back(d);
        if (chosen.size() == k) break;
    }
    for (const long long d : chosen) {
    cout << a % d << " " << d << "\n";
    }
}
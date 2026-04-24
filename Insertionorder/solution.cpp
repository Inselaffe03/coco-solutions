#include <iostream>
#include <vector>
#include <format>
#include <algorithm>
#include <charconv>
#include <ranges>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <format>


using namespace std;


void generateTree(int start, int end, string & solution){
    if(start == 0 && end == 0){
        //cout << format("'start == 0 && end == 0': start: {} | end: {}", start,end) << endl;
        return;
    }
    if(start == end){
        //cout << format("'start == end': start: {} | end: {}", start,end) << endl;
        return;
    }
    long middle = (end+start) / 2;
    //cout << format("start: {} | end: {} | middle: {}", start,end, middle) << endl;
    solution += " " + to_string(middle);
    generateTree(start, middle, solution);
    generateTree(middle+1, end, solution);
}

int main()
{
    int numOfNodes, depth;
    cin >> numOfNodes >> depth;

    auto availableNumOfNodes = pow(2, depth)-1;
    if (availableNumOfNodes > 200000) {
        availableNumOfNodes = 200000;
    }


    // check if big enough
    if ((availableNumOfNodes < numOfNodes) || depth > numOfNodes)
    {
        cout << "impossible" << endl;
    }
    else {

        // Sonderfall 1 1
        if (numOfNodes == 1 && depth == 1) {
            cout << 1 << endl;
            return 0;
        }

        int maximaleAnzahlProSeite {0};
        bool override = false;

        // Ab Tiefe 18 kann es keinen balanced tree mehr geben.
        if (depth > 18) { //18 selbst geht noch (Tiefe 17 pro Seite --> 131.072 --> eine Seite voll)
            override = true;
        }
        else {
            maximaleAnzahlProSeite = pow(2,depth-1)-1;
        }
        auto numRightSideNodes = min(numOfNodes,maximaleAnzahlProSeite); // perfectly balanced


        // 2. Rechte Seite des Baumes optimal füllen mit benötigter tiefe
        // Optimal packen
        if (numOfNodes > maximaleAnzahlProSeite && !override ) {
             //cout << "balanced" << endl;

            int startElem = 0;
            if (numOfNodes == pow(2, depth) -1) {
                startElem = pow(2, depth-1);
            }
            else {
                startElem = numOfNodes - numRightSideNodes;
            }

            string solution = "";
            startElem == 0 ? solution ="" : solution = to_string(startElem);
            generateTree(startElem+1, numOfNodes, solution);
            solution += " " + to_string(numOfNodes);
            if (startElem > 1) {
                generateTree(1, startElem, solution);
            }

            cout << solution << endl;
        }

        // Nicht optimal
        else {
            //start = n - k
            //cout << "unbalanced" << endl;
            string solution = " ";
            auto startElem = numOfNodes - depth;

            for (auto i {startElem+1}; i <= numOfNodes; i++) {
                solution +=" " + to_string(i);
            }

            generateTree(1, startElem+1, solution);
            cout << solution << endl;
        }
    }
    return 0;
}
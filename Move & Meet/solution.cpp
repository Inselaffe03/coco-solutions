#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <string>
using namespace std;

/*
 Testfälle:
 1. Gemeinsamer Punkt verfügbar n Figur 2-> Ausgabe gemeinsamer Punktkoordinaten

        // Wenn Distanz kleine
 2. (Beide Figuren an gleicher Position -> Ausgabe der Position) Nur, wenn alle Schritte gegangen
 3. Kein gemeinsamer erreichbarer Punkt -> impossible

 Regeln:
 1. Alle Schritte müssen genutzt werden
 2. Nicht diagonal gehen

 Vorgehensweise:
 1. 8 (2x4) Eckpunkte bestimmen
 2. Wenn Distanz von einem Eckpunkt A zum Zentrum B kleiner als Laufschritte B
 2.2.2. Prüfen Distanz % 2 == Laufstrecke % 2 --> beide gerade oder ungerade, dann passt das.
 2.2.2.1. Wenn nicht gleich, dann skip
 2.2.2.2 Wenn gleich, dann Punkt gefunden

 wiederholung nur mit Eckpunkten von Figur 2 und Postion Figur 1.


 2.2.2.3 wenn kein punkt gefunden impossible

 */

int main() {
    long long x1, y1, schritte1, x2, y2, schritte2;
    cin >> x1 >> y1 >> schritte1;

    cin >> x2 >> y2 >> schritte2;

    std::map<std::string, std::pair<long long, long long>> edgesA; //left, right, top, bottom (first --> x, second --> y)
    std::map<std::string, std::pair<long long, long long>> edgesB;

    // Bestimmen der Eckpunkte Figur 1
    edgesA["left"] = std::pair<long long, long long>(x1-schritte1, y1);
    edgesA["right"] = std::pair<long long, long long>(x1+schritte1, y1);
    edgesA["top"] = std::pair<long long, long long>(x1, y1+schritte1);
    edgesA["bottom"] = std::pair<long long, long long>(x1, y1-schritte1);

    // Bestimmen der Eckpunkte Figur 2
    edgesB["left"] = std::pair<long long, long long>(x2-schritte2, y2);
    edgesB["right"] = std::pair<long long, long long>(x2+schritte2, y2);
    edgesB["top"] = std::pair<long long, long long>(x2, y2+schritte2);
    edgesB["bottom"] = std::pair<long long, long long>(x2, y2-schritte2);

    constexpr long long MAX = 1000000000000; //10^12
    constexpr long long MIN = -1000000000000;

    // Durchlaufen aller Eckpunkte Form A
    for (const auto& entry : edgesA) {
        pair<long long, long long> currentCoords = entry.second;

        long long currentX = currentCoords.first;
        long long currentY = currentCoords.second;

        // Wenn Position außerhalb des gültigen Bereichs --> Skip
        if (currentX > MAX || currentX < MIN || currentY > MAX || currentY < MIN)
        {
            continue;
        }

        // berechnung der distanz zwischen aktuellem eckpunkt und Position von Figur 2
        long long distance = abs(currentX - x2) + abs(currentY - y2);


        // Wenn distanz <= schritte2
        if (distance <= schritte2){

            // Wenn distanz und schritte 2 beide gerade/ungerade dann cout position
            if (distance % 2 == schritte2 % 2)
            {
                cout << currentX << " " << currentY << endl;
                return 0;
            }

        }
    }


    // Durchlaufen aller Eckpunkte Form B
    for (const auto& entry : edgesB)
    {
        pair<long long, long long> currentCoords = entry.second;

        long long currentX = currentCoords.first;
        long long currentY = currentCoords.second;

        // Wenn Position außerhalb des gültigen Bereichs --> Skip
        if (currentX > MAX || currentX < MIN || currentY > MAX || currentY < MIN)
        {
            continue;
        }

        // berechnung der distanz zwischen aktuellem eckpunkt und Position von Figur 1
        long long distance = abs(currentX - x1) + abs(currentY - y1);


        // Wenn distanz <= schritte1
        if (distance <= schritte1){

            // Wenn distanz und schritte 1 beide gerade/ungerade dann cout position
            if (distance % 2 == schritte1 % 2)
            {
                cout << currentX << " " << currentY << endl;
                return 0;
            }

        }
    }



    // Bestimmen der Eckpunkte Figur 2

    //Durchlaufen aller Eckpunkte

        // Wenn Position außerhalb des Gültigen bereichs -> Skip

        // berechnung der distanz zwischen aktuellem eckpunkt und Position von Figur 1

        // Wenn distanz <= schritte1

            // Wenn distanz und schritte 21 beide gerade/ungerade dann cout position




    // Kein passender Punkt gefunden
    cout << "impossible" << endl;


    //cout << x1Index << " " << y1Index << endl


    return 0;
}
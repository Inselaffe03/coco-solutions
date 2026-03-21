#include <iostream>

using namespace std;

struct buch {
    long long l, w, h;
};

int main() {
    long long n, H;
    cin >> n >> H;

    long long l, w, h;
    long long totalWidth = 0;

    while (n) {
        cin >> l >> w >> h;

        if (l > H && w > H && h > H) {
            cout << "impossible" << endl;
            return 0;
        }

                                 //senkrecht (normal) //waagerecht (lying) //Book facing us
        buch orientierungen[6] = {{l,w,h}, {l, h, w}, {w, l, h}, {w, h, l}, {h, l, w}, {h, w, l}};

        long long bestWidth = 0xFFFFFFFF;
        for (const auto buch: orientierungen) {
           if (buch.h > H) {
               continue;
           }
           if (bestWidth > buch.w) {
               bestWidth = buch.w;
           }
        }
        totalWidth += bestWidth;

        n--;
    }

    cout << totalWidth << endl;
    return 0;
}

    // Grundidee:
    /*
       Brute-Force Alle Bücher durchgehen immer optimal Platzieren und die Breite summieren.

        1. Regal höhe informationen speichern
        2. Alle Bücher Daten Sammeln -> wenn ein in keiner dimension passt -> impossible
        3. For schleife über alle Bücher.
        3.1 Buch in allen 3 orientierungen prüfen ob möglich wenn eine möglich die kleinste wählen.
        3.2 breite summieren


     */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Errore: specificare il file di input!" << endl; // FIX: aggiunto messaggio
        return 1;
    }

    string filename = argv[1];
    ifstream ifs(filename);

    if (ifs.is_open()) {
        string location;
        double t1, t2, t3, t4;

        while (ifs >> location >> t1 >> t2 >> t3 >> t4) {
            double media = (t1 + t2 + t3 + t4) / 4.0;
            cout << location << " " << media << "\n";
        }
        ifs.close();
    } else {
        cerr << "Errore: impossibile aprire il file " << filename << "\n";
        return 1;
    }

    return 0;
}

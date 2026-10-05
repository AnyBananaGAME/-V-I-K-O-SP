#include <iostream>
#include <string>

using namespace std;

const double GBP_Bendras = 0.8729;
const double GBP_Pirkti = 0.8600;
const double GBP_Parduoti = 0.9220;

const double USD_Bendras = 1.1793;
const double USD_Pirkti = 1.1460;
const double USD_Parduoti = 1.2340;

const double INR_Bendras = 104.6918;
const double INR_Pirkti = 101.3862;
const double INR_Parduoti = 107.8546;

enum Valiuta {
  GBP,
  USD,
  INR,
};

double pirkti(Valiuta valiuta, double suma) {
  switch (valiuta) {
  case GBP:
    return suma / GBP_Pirkti;
    break;
  case USD:
    return suma / USD_Pirkti;
    break;
  case INR:
    return suma / INR_Pirkti;
    break;
  }
}

double parduoti(Valiuta valiuta, double suma) {
  switch (valiuta) {
  case GBP:
    return suma / GBP_Parduoti;
    break;
  case USD:
    return suma / USD_Parduoti;
    break;
  case INR:
    return suma / INR_Parduoti;
    break;
  }
}

int main() {
  cout << "------------------------------------------------" << endl;
  cout << "     " << "GBP: " << GBP_Bendras << ", "
       << "USD: " << USD_Bendras << ", "
       << "INR: " << INR_Bendras << endl;
  cout << "------------------------------------------------" << endl << endl;

  cout << "> Norint pirkti ivesti suma ir valiuta (+ 12 GBP)" << endl;
  cout << "> Norint parduoti ivesti suma ir valiuta (- 12 GBP)" << endl << endl;
  cout << "> Norint palyginti ivesti suma ir valiuta (= 12 GBP)" << endl << endl;

  string pasirinkimas;
  double suma;
  string valiutaText;
  // getline(cin, text);
  cin >> pasirinkimas >> suma >> valiutaText;

  cout << pasirinkimas << " " << suma << " " << valiutaText << endl;

  Valiuta valiuta = GBP;
  if (valiutaText == "USD")
    valiuta = USD;
  if (valiutaText == "INR")
    valiuta = INR;

  if (pasirinkimas == "+") {
    cout << "Nusipirkta " << suma << " " << valiutaText << " uz " << pirkti(valiuta, suma) << " EUR" << endl;
  } else {
    cout << "Parduota " << suma << " " << valiutaText << " uz " << parduoti(valiuta, suma) << " EUR" << endl;
  }

  return 0;
}

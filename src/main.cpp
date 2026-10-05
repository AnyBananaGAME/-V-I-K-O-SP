#include <iomanip>
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

string ToString(Valiuta valiuta) {
  switch (valiuta) {
  case GBP:
    return "GBP";
  case USD:
    return "USD";
  case INR:
    return "INR";
  default:
    return "Unknown";
  }
}

double pirkti(Valiuta valiuta, double suma) {
  switch (valiuta) {
  case GBP:
    return suma * GBP_Pirkti;
    break;
  case USD:
    return suma * USD_Pirkti;
    break;
  case INR:
    return suma * INR_Pirkti;
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

double kursas(Valiuta valiuta) {
  switch (valiuta) {
  case GBP:
    return GBP_Bendras;
    break;
  case USD:
    return USD_Bendras;
    break;
  case INR:
    return INR_Bendras;
    break;
  }
}

int main() {
  cout << "---------------------------------------------------------" << endl;
  cout << "     " << "GBP(1): " << GBP_Bendras << ", "
       << "USD(2): " << USD_Bendras << ", "
       << "INR(3): " << INR_Bendras << endl;
  cout << "---------------------------------------------------------" << endl
       << endl;

  cout << "! Veiksmui ivygditi ivesti +, -, = ir suma ir valiuta" << endl;
  cout << "> Norint pirkti ivesti suma ir valiuta (+ 12 1)" << endl;
  cout << "> Norint parduoti ivesti suma ir valiuta (- 12 1)" << endl;
  cout << "> Norint palyginti ivesti suma ir valiuta (= 12 1)" << endl << endl;
  cout << "---------------------------------------------------------" << endl;

  string pasirinkimas;
  double suma;
  int valiutaNr;
  // getline(cin, text);
  cin >> pasirinkimas >> suma >> valiutaNr;

  // cout << pasirinkimas << " " << suma << " " << valiutaNr << endl;

  if (valiutaNr > 3 || valiutaNr < 1) {
    cout << "! Neteisingas valiuta" << endl;
    return 0;
  }

  Valiuta valiuta = static_cast<Valiuta>(valiutaNr);

  if (suma < 0) {
    cout << "! Neteisinga suma" << endl;
    return 0;
  }

  cout << "---------------------------------------------------------" << endl;
  if (pasirinkimas == "+") {
    cout << fixed << setprecision(2) << "> Uz " << suma << " EUR nusipirkta "
         << pirkti(valiuta, suma) << " " << ToString(valiuta)
         << endl;
  } else if (pasirinkimas == "-") {
    cout << fixed << setprecision(2) << "> Parduota " << suma << " "
         << ToString(valiuta) << " uz " << parduoti(valiuta, suma) << " EUR"
         << endl;
  } else if (pasirinkimas == "=") {
    cout << fixed << setprecision(2) << "> " << suma << " EUR yra "
         << suma * kursas(valiuta) << " " << ToString(valiuta) << endl
         << "> 1 " << ToString(valiuta) << " yra "
         << 1.0 / kursas(valiuta) << " EUR" << endl;
  } else {
    cout << "! Neteisingas pasirinkimas" << endl;
  }
  cout << "---------------------------------------------------------" << endl;

  return 0;
}

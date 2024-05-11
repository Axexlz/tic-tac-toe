#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int verificare(int mat[4][4]){
  // HORIZONTALA ---
  if(mat[0][0] == 1 && mat[0][1] == 1 && mat[0][2] == 1)
    return 1;
  if(mat[1][0] == 1 && mat[1][1] == 1 && mat[1][2] == 1)
    return 1;
  if(mat[2][0] == 1 && mat[2][1] == 1 && mat[2][2] == 1)
    return 1;
  // DIAGONALA ---
  if(mat[0][0] == 1 && mat[1][1] == 1 && mat[2][2] == 1)
    return 1;
  if(mat[0][2] == 1 && mat[1][1] == 1 && mat[2][0] == 1)
    return 1;
  // VERTICALA ---
  if(mat[0][0] == 1 && mat[1][0] == 1 && mat[2][0] == 1)
    return 1;
  if(mat[0][1] == 1 && mat[1][1] == 1 && mat[2][1] == 1)
    return 1;
  if(mat[0][2] == 1 && mat[1][2] == 1 && mat[2][2] == 1)
    return 1;
  // HORIZONTALA ---
  if(mat[0][0] == 0 && mat[0][1] == 0 && mat[0][2] == 0)
    return 1;
  if(mat[1][0] == 0 && mat[1][1] == 0 && mat[1][2] == 0)
    return 1;
  if(mat[2][0] == 0 && mat[2][1] == 0 && mat[2][2] == 0)
    return 1;
  // DIAGONALA ---
  if(mat[0][0] == 0 && mat[1][1] == 0 && mat[2][2] == 0)
    return 1;
  if(mat[0][2] == 0 && mat[1][1] == 0 && mat[2][0] == 0)
    return 1;
  // VERTICALA ---
  if(mat[0][0] == 0 && mat[1][0] == 0 && mat[2][0] == 0)
    return 1;
  if(mat[0][1] == 0 && mat[1][1] == 0 && mat[2][1] == 0)
    return 1;
  if(mat[0][2] == 0 && mat[1][2] == 0 && mat[2][2] == 0)
    return 1;
  return 0;
}
int main(){

  int mat[4][4], s = 0 ,i ,j, nr = 0, aux, gasit = 0;
  int nrLinii = 3, nrColoane = 3;
  // mat[i][j] = -1, daca nu este pus nimic si vom afisa spatiu gol
  // mat[i][j] = 0, daca este pus O
  // mat[i][j] = 1 daca este X
  for(int i = 0; i <= 2; ++i)
    for(int j = 0; j <= 2; ++j)
      mat[i][j] = -1;
  cout << "-------------\n";
  for (int i = 0; i < 3; i++) {
      cout << "| ";
      for (int j = 0; j < 3; j++) {
          if(mat[i][j] == -1)
            cout << " " << " | ";
          else if(mat[i][j] == 1)
            cout << "X" << " | ";
          else
            cout << "O" << " | ";
      }
      cout << "\n-------------\n";
  }
  int valPusa = 1;
  for(int i = 1; i <= 9; ++i)
    {
      cout << "Introduceti linia si coloana : ";
      int linie, coloana;
      cin >> linie >> coloana;
      mat[linie][coloana] = valPusa;

      if(verificare(mat) == 1)
      {
        cout << "AI CASTIGAT!";
        break;
      }

      if(valPusa == 1)
        valPusa = 0;
      else valPusa = 1;

      cout << "-------------\n";
      for (int i = 0; i < 3; i++) {
          cout << "| ";
          for (int j = 0; j < 3; j++) {
              if(mat[i][j] == -1)
                cout << " " << " | ";
              else if(mat[i][j] == 1)
                cout << "X" << " | ";
              else
                cout << "O" << " | ";
          }
          cout << "\n-------------\n";
      }

    }
  return 0;
}

#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int verificare(int mat[4][4]){
  // HORIZONTALA ---
  if(mat[1][1] == 1 && mat[1][2] == 1 && mat[1][3] == 1)
    return 1;
  else if(mat[2][1] == 1 && mat[2][2] == 1 && mat[2][3] == 1)
    return 1;
  else if(mat[3][1] == 1 && mat[3][2] == 1 && mat[3][3] == 1)
    return 1;
  // DIAGONALA ---
  else if(mat[1][1] == 1 && mat[2][2] == 1 && mat[3][3] == 1)
    return 1;
  else if(mat[1][3] == 1 && mat[2][2] == 1 && mat[3][1] == 1)
    return 1;
  // VERTICALA ---
  else if(mat[1][1] == 1 && mat[2][1] == 1 && mat[3][1] == 1)
    return 1;
  else if(mat[1][2] == 1 && mat[2][2] == 1 && mat[3][2] == 1)
    return 1;
  else if(mat[1][3] == 1 && mat[2][3] == 1 && mat[3][3] == 1)
    return 1;
  // HORIZONTALA ---
  else if(mat[1][1] == 0 && mat[1][2] == 0 && mat[1][3] == 0)
    return 1;
  else if(mat[2][1] == 0 && mat[2][2] == 0 && mat[2][3] == 0)
    return 1;
  else if(mat[3][1] == 0 && mat[3][2] == 0 && mat[3][3] == 0)
    return 1;
  // DIAGONALA ---
  else if(mat[1][1] == 0 && mat[2][2] == 0 && mat[3][3] == 0)
    return 1;
  else if(mat[1][3] == 0 && mat[2][2] == 0 && mat[3][1] == 0)
    return 1;
  // VERTICALA ---
  else if(mat[1][1] == 0 && mat[2][1] == 0 && mat[3][1] == 0)
    return 1;
  else if(mat[1][2] == 0 && mat[2][2] == 0 && mat[3][2] == 0)
    return 1;
  else if(mat[1][3] == 0 && mat[2][3] == 0 && mat[3][3] == 0)
    return 1;
  else
    return 0;
  
}

int OK(int i, int j, int m[4][4])
{
  if(m[i][j] == -1 && i >= 1 && i <= 3 && j >= 1 && j <= 3)
    return 0;
  else return 1;
}
int main(){

  int mat[4][4], s = 0 ,i ,j, nr = 0, aux, gasit = 0, num = 1, win = -1;
  int nrLinii = 3, nrColoane = 3;
  // mat[i][j] = -1, daca nu este pus nimic si vom afisa spatiu gol
  // mat[i][j] = 0, daca este pus O
  // mat[i][j] = 1 daca este X
  for(int i = 1; i <= 3; ++i)
    for(int j = 1; j <= 3; ++j)
      mat[i][j] = -1;
  cout << "-------------\n"; 
  for (int i = 1; i <= 3; i++) { 
      cout << "| "; 
      for (int j = 1; j <= 3; j++) { 
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
  for(int i = 1; i <= 9 && win == -1; ++i)
    {
      if(num == 3)
        num = 1;
      int numarValid = 0;
      int linie, coloana;
      while(numarValid == 0)
        {
          cout << "Jucatorul " << num <<"\n";
          cout << "Introduceti linia si coloana : ";
          cin >> linie >> coloana;
          if(OK(linie, coloana, mat) == 0)
            numarValid = 1;
          else
          {
            cout << "Casuta pe care doresti sa pui nu este valida/libera!\n";
            cout << "Reincearca alta casuta!\n";
          }
    
        }
      ++num;

      mat[linie][coloana] = valPusa;
      if(valPusa == 1)
        valPusa = 0;
      else valPusa = 1;

      cout << "-------------\n"; 
      for (int i = 1; i <= 3; i++) { 
          cout << "| "; 
          for (int j = 1; j <= 3; j++) { 
              if(mat[i][j] == -1)
                cout << " " << " | "; 
              else if(mat[i][j] == 1)
                cout << "X" << " | ";
              else
                cout << "O" << " | ";
          } 
          cout << "\n-------------\n"; 
      } 
      if(verificare(mat) == 1)
        {
          cout << "Jucatorul " << num << "\n";
          cout << "A CASTIGAT!";
          win = num;

        }
      
    }

  // daca am iesit din for si nu avem niciun castigator inseamna ca cele 9
  // casute au fost umplute si este remiza
  if(win == -1)
    cout << "REMIZA! FELICITARI AMBILOR JUCATORI!";
  return 0;
}
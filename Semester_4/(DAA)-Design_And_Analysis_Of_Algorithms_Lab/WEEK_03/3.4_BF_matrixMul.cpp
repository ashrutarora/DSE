// Write a program to implement matrix multiplication using brute-force technique and analyze its time efficiency.

#include <iostream>
using namespace std;

int main(){

    int r1, c1, r2, c2;

    cout << "Enter the number of ROWS in the MATRIX 1: " << endl;
    cin >> r1;

    cout << "Enter the number of COLUMNS in the MATRIX 1 : " << endl;
    cin >> c1;

    cout << "Enter the number of ROWS in the MATRIX 2: " << endl;
    cin >> r2;

    cout << "Enter the number of COLUMNS in the MATRIX 2 : " << endl;
    cin >> c2;

    // Necessary condition for matrix multiplication
    if( r1 != c2){

        cout << "Matrix Multiplication not possible.";
    }
    else{

    // Matrix 1

    int matrix1[r1][c1];

    cout << "Enter elements in MATRIX 1" << endl;

    for(int i = 0; i < r1; i++){

        for(int j = 0; j < c1; j++){

            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Matrix 1: " << endl;

    for(int i = 0; i < r1; i++){

        for(int j = 0; j < c1; j++){

            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }


    // Matrix 2
    int matrix2[r2][c2];

    cout << "Enter elements in MATRIX 2" << endl;

    for(int i = 0; i < r2; i++){

        for(int j = 0; j < c2; j++){

            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    cout << "Matrix 2: " << endl;

    for(int i = 0; i < r2; i++){

        for(int j = 0; j < c2; j++){

            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    

    int matrix3[r1][c2];
    // Multiplying the matrices

        for(int i = 0; i < r1; i++){

            for(int j = 0; j < c2; j++){

                for(int k = 0 ; k < c1 ; k++){

                    matrix3[i][j] = matrix1[i][k] * matrix2[k][j];
                }  
            }
        }

            cout << "Matrix 3: " << endl;
            for(int i = 0; i < r1; i++){

                for(int j = 0; j < c2; j++){

                    cout << matrix3[i][j] << " ";
                }
                cout << endl;
            } 
    }
    return 69;
}

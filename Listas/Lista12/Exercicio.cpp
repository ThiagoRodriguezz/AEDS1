/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/


#include "mylib.hpp"
#include <windows.h>

using namespace std;

/*
===== FUNÇÔES =====
*/

/*
===== METODOS =====
*/

void method_01()
{

    int M = 0;
    int N = 0;
    string filename;

    cout << "Method 01 - v0.0\n"<< endl;

    cout << "Valor de M: ";
    cin >> M;
    cout << "Valor de N: ";
    cin >> N;

    cout << "Nome do arquivo que serão gravado os dados: ";
    cin >> filename;

    Matrix<int> matrix(M, N, 0); // cria a matriz com valores de M x N
    matrix.fillMatrixRV(1, 100); // preenche a matriz com valores aleatorios
    matrix.print();              // imprime na tela a matriz
    matrix.fprintf(filename);    // imprime em um arquivo a quantidade de dados, linhas, colunas e os elementos da matriz.

    system("pause");
}

void method_02()
{

    cout << "Method 02 - v0.0\n";

    Matrix<int> matrix1(3, 3, 0);
    Matrix<int> matrix2(3, 3, 0);

    cout << "\nMatriz Original:" << endl;
    matrix1.fread("DADOS1.TXT"); // monta a matriz com os valores presentes em DADOS
    matrix1.print();            // imprime na tela a matriz1

    cout << "Matriz com elementos multiplicados:" << endl;
    matrix2 = matrix1.scalar(3); // monta a matriz com os valores de matriz1 com todos seus elementos multiplicaods por 3.
    matrix2.print();             // imprime na tela a matriz2

    system("pause");
}

void method_03()
{

    cout << "Method 03 - v0.0\n"
         << endl;

    bool teste = false;
    Matrix<int> matrix1(3, 3, 0); // gera uma matriz
    matrix1.fread("DADOS.TXT");   // copia os dados de arquivo pra dentro da matriz

    matrix1.print();            // imprime na tela a matriz
    teste = matrix1.isIdenty(); // testa se a matriz é identidade
    if (teste == 1)
    {
        cout << "A matriz é identidade.\n"<< endl;
    }
    else
    {
        cout << "A matriz não é identidade.\n"<< endl;
    }

    system("pause");
}

void method_04()
{

    cout << "Method 04 - v0.0\n"<< endl;

    bool teste = false;
    string filename;

    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix2(filename);

    if (matrix1.getRows() == 0 || matrix2.getRows() == 0) // valida se são matrizes validas
    {
        cout << "Operação cancelada: arquivo inválido.\n"<< endl;
    }
    else
    {

        cout << "Matriz 1" << endl;
        matrix1.print();
        cout << "Matriz 2" << endl;
        matrix2.print();

        if (matrix1 == matrix2)
            cout << "São iguais!\n"<< endl;
        else
            cout << "São diferentes.\n"<< endl;
    }

    system("pause");
}

void method_05()
{

    string filename;
    cout << "Method 05 - v0.0\n"<< endl;

    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix2(filename);

    cout << endl;
    cout << "Matriz 1" << endl;
    matrix1.print();
    cout << "Matriz 2" << endl;
    matrix2.print();

    Matrix<int> soma = matrix1.add(matrix2);
    soma.print();

    system("pause");
}

void method_06()
{

    cout << "Method 06 - v0.0\n";

    string filename;
    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "\nMatriz original: " << endl;
    matrix1.print();

    cout << "Matrix operada: " << endl;
    matrix1.addRows(0, 1, -1);
    matrix1.print();

    system("pause");
}

void method_07()
{

    cout << "Method 07 - v0.0\n";

    string filename;
    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "\nMatriz original: " << endl;
    matrix1.print();

    cout << "Matrix operada: " << endl;
    matrix1.subtractRows(0, 1, 2);
    matrix1.print();

    system("pause");
}

void method_08()
{

    cout << "Method 08 - v0.0\n";

    string filename;
    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "\nMatriz original: " << endl;
    matrix1.print();

    int teste = matrix1.searchRows(65);

    if (teste > -1)
    {
        cout << "O valor aparece na linha: " << teste << endl;
        cout << endl;
    }

    system("pause");
}

void method_09()
{

    cout << "Method 09 - v0.0\n";

    string filename;
    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "\nMatriz original: " << endl;
    matrix1.print();

    int teste = matrix1.searchColumns(28);

    if (teste > -1)
    {
        cout << "O valor aparece na coluna: " << teste << endl;
        cout << endl;
    }

    system("pause");
}

void method_10()
{

    cout << "Method 10 - v0.0\n"<< endl;

    string filename;
    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "\nMatriz original:" << endl;
    matrix1.print();

    cout << "Matriz transposta:" << endl;
    Matrix<int> transposta = matrix1.transpose();
    transposta.print();

    system("pause");
}

void method_11()
{

    cout << "Extra 01 - v0.0\n"<< endl;

    string filename;
    cout << "Entre com o nome do arquivo: ";
    cin >> filename;
    Matrix<int> matrix1(filename);

    cout << "\nMatriz lida:" << endl;
    matrix1.print();

    bool teste = matrix1.isFilledByColumns();

    if (teste == true)
    {
        cout << "A matriz esta preenchida por colunas.\n"<< endl;
    }
    else
    {
        cout << "A matriz NAO esta preenchida por colunas.\n"<< endl;
    }

    system("pause");
}

void method_12()
{

    cout << "Extra 02 - v0.0\n"<< endl;

    int M = 0;
    int N = 0;

    cout << "Valor de M (linhas): ";
    cin >> M;
    cout << "Valor de N (colunas): ";
    cin >> N;

    // cria uma matriz MxN temporaria so para usar o metodo
    Matrix<int> base(M, N, 0);

    cout << "\nMatriz preenchida por colunas (ordem inversa de linhas):" << endl;
    Matrix<int> resultado = base.fillByColumnsReversed(1);
    resultado.print();

    system("pause");
}

// fim dos methods

int main() {

    SetConsoleOutputCP(CP_UTF8); // Corrige a UTF do compilador G++
    SetConsoleCP(CP_UTF8);  // Corrige a UTF do compilador G++
    srand(time(0));
    
    int x;

    do {

        cout << "\nExemplo0300 - Programa - v0.0\n";
        cout << "=+= Opções =+=\n\n";

        cout << " 0 - Parar\n\n";

        cout << " 1 - Método 01      6 - Método 06\n";
        cout << " 2 - Método 02      7 - Método 07\n";
        cout << " 3 - Método 03      8 - Método 08\n";
        cout << " 4 - Método 04      9 - Método 09\n";
        cout << " 5 - Método 05     10 - Método 10\n\n";
        cout << "11 - Extra  01     12 - Extra  02\n\n";

        cout << "Entrar com uma opção: ";
        cin >> x;

        switch ( x )
        {
            case  1: method_01 ( ); break;
            case  2: method_02 ( ); break;
            case  3: method_03 ( ); break;
            case  4: method_04 ( ); break;
            case  5: method_05 ( ); break;
            case  6: method_06 ( ); break;
            case  7: method_07 ( ); break;
            case  8: method_08 ( ); break;
            case  9: method_09 ( ); break;
            case 10: method_10 ( ); break;
            case 11: method_11 ( ); break;
            case 12: method_12 ( ); break;
            case  0: break;
            default:
                cout << "Valor diferente das opcoes [0-12]\n";
                system ( "pause" );
                break;
        } // end switch

    } while (x != 0);

    cout << "\nApertar ENTER para terminar\n";
    system("pause");

    return 0;
}
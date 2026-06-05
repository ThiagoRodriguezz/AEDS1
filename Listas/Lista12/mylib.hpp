#ifndef _MYLIB_H_
#define _MYLIB_H_ 

/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/


#include <cstdlib>  // rand e srand
#include <ctime>    // time

#include <iostream>
using std::cin  ;    // para entrada 
using std::cout;     // para saida 
using std::endl;     // para mudar de linha 
 
#include <iomanip> 
using std::setw;     // para definir espacamento 
 
#include <string> 
using std::string;   // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;  // para gravar arquivo 
using std::ifstream;  // para ler    arquivo


void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}



template <typename T>
class Matrix
{
    private:
    T optional;
    int rows;
    int columns;
    T** data;

    public:
    Matrix()
    {
        this->rows = 0;
        this->columns = 0;
        data = nullptr;
    } // end constructor


Matrix ( int linhas, int colunas, T initial)
{
    bool OK       = true;
    this->optional = initial;
    this->rows    = linhas;
    this->columns = colunas;

    // reservar area da matriz

    data = new T* [rows];
    if (data != nullptr)
    {
        for ( int x = 0; x < rows; x++)
        {
            data[x] = new T[columns];
            OK = OK && (data[x] != nullptr);

            for (int y = 0; y < columns; y++) 
            {
                data[x][y] = optional; // inicializa os valores com 0 pra evitar lixo de memoria;
            }
        } // fim do for
        if (!OK)
        {
            data = nullptr;
        } // fim if
    } // fim if
} // fim constructor


Matrix( string fileName )
{
    rows     = 0;
    columns  = 0;
    data     = nullptr;
    fread(fileName);

} // fim do constructor


int randomIntGenerate ( int inferior, int superior )
{
    int resultado = rand() % (superior - inferior + 1) + inferior;
    return ( resultado ); 
}

void fillMatrixRV ( int inferior, int superior)
{
    if ( inferior > superior )
    {
        cout << "ERROR: Intervalo invalido." << endl;
    }
    else
    {
        for ( int x = 0; x < rows; x++)
        {
            for ( int y = 0 ; y < columns; y++)
            {
                data[x][y] = randomIntGenerate(inferior, superior);
                
            }
        }
    }
}

void print ()
{
    cout<<endl;
    for ( int x = 0; x < rows; x=x+1)
    {
        for ( int y = 0; y < columns; y = y+1)
        {
            cout<< setw(6) << data[x][y];
        }
        cout << endl; 
    }
    cout << endl; 
}

void fprintf ( string filename )
{
    ofstream arquivo;
    arquivo.open (filename); // nome do arquivo
    arquivo << ( rows * columns ) << endl; // imprime a quantidade de dados a serem imprimidos
    arquivo << rows << endl; // imprime o numero de linha
    arquivo << columns << endl; // imprime o numero de colunas

    for ( int x = 0; x < rows; x=x+1)
    {
        for ( int y = 0; y < columns; y=y+1)
        {
            arquivo << data[x][y] << endl;
        } // fim for
    } // fim for
    arquivo.close();
}

void fread ( string fileName )
{
    ifstream arquivo;
    int linhas   = 0;
    int colunas  = 0;
    int numDados = 0;
    
    arquivo.open ( fileName );
    
    arquivo >> numDados;
    arquivo >> linhas;
    arquivo >> colunas;

    if (!arquivo)
    {
        cout<<"ERRO: Arquivo não encontrado." << endl;
    }
    else if ( linhas <= 0 || colunas <= 0 )
    {
        cout << "ERRO: Dimensões invalidas\n" << endl;
    }
    else
    {
        rows    = linhas;  // guarda o valor de linhas em rows
        columns = colunas; // guarda o valor de colunas em columns

        // reservar area
        data = new T* [ rows ];
        for (int x = 0; x < rows; x++)
        {
            data[x] = new T [ columns ];
        }
        for ( int x = 0; x < rows; x = x + 1)
        {
            for ( int y = 0; y < columns; y=y+1)
            {
                arquivo >> data[ x ][ y ]; // grava na matriz os valores que forem lidos na matriz
            } // end for
        } // end for
    } // end if

    arquivo.close();
}

Matrix<T> scalar ( int multiplicador )
{
    Matrix<T> resultado(rows, columns, 0);

    if ( rows <= 0 || columns <= 0 )
    {
        cout << "ERRO: Dimensões invalidas." <<endl;
    }
    else
    {
        for ( int x = 0; x < rows; x=x+1)
        {
            for ( int y = 0; y < columns; y=y+1)
            {
                resultado.data[x][y] = data[x][y] * multiplicador; // multiplica os elementos por 3 e atribui eles a matriz resultado.
            } // end for
        } // end for
    } // end if
    return(resultado);
}

bool isIdenty ()
{
    bool OK = true;
    if ( rows != columns )
    {
        OK = false;
    }
    else
    {
        int x = 0;
        while ( x < rows && OK)
        {
            int y = 0;
            while ( y < columns && OK)
            {
                if ( x == y )
                {
                    OK = (data[x][y] == 1); // checa se os valores da diagonal principal sao iguais a 1
                }
                else
                {
                    OK = (data[x][y] == 0); // checa se o restante e igual a 0
                } // end if
                y++;
            } // end while
        x++;
        } // end while
    } // end if
    return ( OK );
}

bool operator!= ( const Matrix<T> &other)
{
    bool result = false;
    int x = 0;
    int y = 0;

    if( other.rows    == 0 || rows    != other.rows ||
        other.columns == 0 || columns != other.columns )
    {
        cout << "ERRO: Dados invalidos." <<endl;
    }
    else
    {
        x = 0;
        while (x < rows && !result)
        {
            y = 0;
            while (y < columns && !result)
            {
                result = (data[x][y] != other.data[x][y]);
                y = y + 1;
            } // end while
            x = x + 1;
        } // end while
    } // end if
    return (result);
} // end operator!= ( )

bool operator== ( const Matrix<T> &other )
{
    if (rows == 0 || other.rows == 0)
        return false;

    if (rows != other.rows || columns != other.columns)
        return false;

    bool OK = true;
    
    int x = 0;
    while ( x < rows && OK )
    {
        int y = 0;
        while ( y < columns && OK)
        {
            OK = ( data[x][y] == other.data[x][y]);
            y= y + 1;
        } // end while
    x = x + 1;
    } // end while
    return ( OK );
}

Matrix<T> add(Matrix<T> &other)

{
    if( other.rows     < 0 || other.rows    != rows    ||
        other.columns  < 0 || other.columns != columns )
    {
        cout << "Dimensões invalidas." << endl; 
    }
    
    Matrix <T> resultado (rows, columns, 0);

    int x = 0;
    while ( x < rows )
    {
        int y = 0;
        while ( y < columns ) 
        {
            resultado.data[x][y] = this->data[x][y] + other.data[x][y];
            y = y + 1;
        }
        x = x + 1;
    }
    cout << "Soma das matrizes: " <<endl;
    return ( resultado );
}


Matrix<T> addRows( int pLinha, int sLinha, int multiplicando)
{

    // Cria o resultado como uma cópia exata do objeto atual (*this)
    Matrix<T> resultado = *this;

    if (rows <= 0 || columns <= 0 || pLinha < 0 || pLinha >= rows || sLinha < 0 || sLinha >= rows) {
        cout << "ERROR: Operacao invalida.\n" << endl;
        return resultado; // Retorna a cópia intacta em caso de erro
    }

    for ( int y = 0; y < columns; y = y + 1 )
    {
        resultado.data[pLinha][y] = this->data[pLinha][y] + this->data[sLinha][y] * multiplicando;
    }
    

    return ( resultado );

}

Matrix<T> subtractRows( int pLinha, int sLinha, int multiplicando)
{

    // Cria o resultado como uma cópia exata do objeto atual (*this)
    Matrix<T> resultado = *this;

    if (rows <= 0 || columns <= 0 || pLinha < 0 || pLinha >= rows || sLinha < 0 || sLinha >= rows) {
        cout << "ERROR: Operacao invalida.\n" << endl;
        return resultado; // Retorna a cópia intacta em caso de erro
    }

    for ( int y = 0; y < columns; y = y + 1 )
    {
        resultado.data[pLinha][y] = this->data[pLinha][y] - this->data[sLinha][y] * multiplicando;
    }
    

    return ( resultado );

}


int searchRows ( int procurado )
{
    bool encontrado = false;
    int linhaencontrada = -1;
    int x = 0;
    int y = 0;
    
    for ( x = 0; x < rows && !encontrado; x=x+1)
        {
        for ( y = 0; y < columns && !encontrado; y = y + 1)
            {
            if ( data[x][y] == procurado )
                {
                encontrado = true;
                linhaencontrada = x;
                } // end if
            } // end for
        } // end for

    if (!encontrado)
    {
        cout << "Valor não encontrado na matriz.\n" << endl;
    }
    
    return ( linhaencontrada );
}



int searchColumns ( int procurado )
{
    bool encontrado = false;
    int colunaencontrada = -1;
    int x = 0;
    int y = 0;
    
    for ( x = 0; x < rows && !encontrado; x=x+1)
        {
        for ( y = 0; y < columns && !encontrado; y = y + 1)
            {
            if ( data[x][y] == procurado )
                {
                encontrado = true;
                colunaencontrada = y;
                } // end if
            } // end for
        } // end for

    if (!encontrado)
    {
        cout << "Valor não encontrado na matriz.\n" << endl;
    }
    
    return ( colunaencontrada );
}

Matrix<T> transpose()
{
    // a transposta tem dimensoes invertidas: rows <-> columns
    Matrix<T> resultado(columns, rows, 0);

    for (int x = 0; x < rows; x = x + 1)
    {
        for (int y = 0; y < columns; y = y + 1)
        {
            resultado.data[y][x] = data[x][y]; // elemento [linha][coluna] vai para [coluna][linha]
        } // end for
    } // end for

    return (resultado);
}

bool isFilledByColumns()
{
    bool OK = true;

    // o primeiro elemento deve ser 1 para seguir o padrao dos exemplos
    // e os valores devem ser sequenciais percorrendo coluna por coluna
    int esperado = (int)data[0][0]; // pega o valor inicial da matriz

    int y = 0;
    while (y < columns && OK)
    {
        int x = 0;
        while (x < rows && OK)
        {
            OK = ((int)data[x][y] == esperado); // verifica se o valor bate com o esperado
            esperado = esperado + 1;            // proximo valor da sequencia
            x = x + 1;
        } // end while
        y = y + 1;
    } // end while

    return (OK);
}

Matrix<T> fillByColumnsReversed(int inicio)
{
    Matrix<T> resultado(rows, columns, 0);

    int valor = inicio; // valor inicial da sequencia

    // percorre coluna por coluna, mas preenche de baixo pra cima
    for (int y = 0; y < columns; y = y + 1)
    {
        for (int x = rows - 1; x >= 0; x = x - 1) // comeca da ultima linha
        {
            resultado.data[x][y] = (T)valor;
            valor = valor + 1;
        } // end for
    } // end for

    return (resultado);
}

int getRows ( )
{ return rows; }

int getColumns ( )
{ return columns; }

};
#endif
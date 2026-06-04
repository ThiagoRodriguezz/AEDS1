/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>

// inicio das funções
/*
    fprintDoubleMatrix - Grava em um arquivo valores flutuantes de uma matriz.
    @param Filename - Nome do arquivo.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/
void fprintDoubleMatrix ( chars fileName, int linha, int coluna, double matrix[][coluna] )
{

    FILE* arquivo;
    arquivo = fopen ( fileName, "wt");
    int x = 0;
    int y = 0;
    
    fprintf(arquivo, "%d\n", linha);
    fprintf(arquivo, "%d\n", coluna);

    for ( x = 0; x < linha; x++)
    {
        for ( y = 0; y < coluna; y++)
        {
            fprintf( arquivo, "%.2f\n", matrix[x][y]);
        } // fim for
    } // fim for

    fclose ( arquivo );
}

/*
    fscanfDoubleMatrix - Lê de um arquivo valores flutuantes de uma matriz.
    @param Filename - Nome do arquivo.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/
void fscanfDoubleMatrix ( chars fileName, int linha, int coluna, double matrix[][coluna] )
{
    FILE* arquivo;
    arquivo = fopen ( fileName, "rt");

    int    x = 0;
    int    y = 0;
    double z = 0.0;

    fscanf(arquivo, "%d", &x); // lê o valor da linha
    fscanf(arquivo, "%d", &y); // lê o valor da coluna

    if ( linha  <= 0 || linha > x ||
         coluna <= 0 || coluna > y )
    {
        printf("\nValores Invalidos.\n");
    }
    else
    {
        x = 0;
        while ( ! feof ( arquivo ) && x < linha )
        {
            y = 0;
            while ( ! feof ( arquivo ) && y < coluna )
            {
                fscanf(arquivo, "%lf", &z); // ler arquivo
                matrix[x][y] = z; // guardar valor
                y++; // passar para o proximo
            } // fim do while
            x++;
        } // fim do while
    } // fim do if

    fclose ( arquivo );
}

/*
    readDoubleMatrix - Lê matriz bidimensional com valores flutuantes.
    @param linha  - Numero de linhas da matriz
    @param Coluna - Numero de colunas da matriz
    @param Matrix - Grupo de valores flutuantes
*/
void readDoubleMatrix              ( int linha, int coluna, double matrix[][coluna] )
{
    // definir dados
    int x = 0;
    int y = 0;
    double z = 0.0;
    chars text = IO_new_chars ( STR_SIZE );

    for ( x = 0; x < linha; x++)
    {
        for ( y = 0; y < coluna; y++)
        {
            do {
                strcpy ( text, STR_EMPTY );
                z = IO_readdouble ( IO_concat (
                                IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ),
                                IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );
                if ( z < 0 )
                {
                    printf("\nInsira apenas valores positivos ou zeros.\n\n");
                }
            
            }
            while ( z < 0 );

            matrix[x][y] = z;
        } // fim do for
    } // fim do for

} // fim readDoubleMatrix

/*
    printDoubleMatrix - Imprime os valores flutuantes de uma matriz
    @param Linha - Numero de linhas
    @param Coluna - Numero de Colunas
    @param Matrix - Grupo de valores flutuantes
*/
void printDoubleMatrix             ( int linha, int coluna, double matrix[][coluna] )
{
    int x = 0;
    int y = 0;

    printf("\n");
    for ( x = 0; x < linha; x++ )
    {
        for ( y = 0; y < coluna; y++)
        {
            printf("%6.2f", matrix[x][y]);
        }
        printf("\n");
    }

}

/*
    printDiagonalDoubleMatrix - Imprime na tela os valores flutuantes na diagonal principal da matriz.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/
void printDiagonalDoubleMatrix     ( int linha, int coluna, double matrix[][coluna] )
{
    int x = 0;

    if ( linha != coluna ) // checa se a matrix é quadratica
        {
            printf("\nValores invalidos.\n");
        }
    else
    {
        for ( x = 0; x < linha; x++ )
        {
            printf("%6.2f", matrix[x][x]);
        }
    }
    printf("\n");

}

/*
    printDiagonalDoubleMatrix - Imprime na tela os valores flutuantes na diagonal secundaria da matriz.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/
void printSDiagonalDoubleMatrix    ( int linha, int coluna, double matrix[][coluna] )
{
    int x = 0;
    int y = 0;

    if ( linha != coluna ) // checa se a matrix é quadratica
        {
            printf("\nValores invalidos.\n");
        }
    else
    {
        for (x = 0; x < linha; x++)
        {
            printf("%6.2f", matrix[x][linha-1-x]);
        }
    }
    printf("\n");

}

/*
    printLDTriangleDoubleMatrix - Imprime na tela os valores flutuantes abaixo da diagonal principal da matriz.
    @attention Regra para valores abaixo da diagonal principal: Linha > Coluna.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/
void printLDTriangleDoubleMatrix   ( int linha, int coluna, double matrix[][coluna] )
{

    int x = 0;
    int y = 0;

    if ( linha != coluna)
    {
        printf("Valor invalido.\n");
    }
    else
    {
        for ( x = 0; x < linha; x++ )
        {
            for ( y = 0; y < x; y++)
            {
                printf("%6.2f", matrix[x][y]);
            } 
        }
    }
    printf("\n");
}

/*
    printLUTriangleDoubleMatrix - Imprime na tela os valores flutuantes acima da diagonal principal da matriz.
    @attention Regra para valores acima da diagonal principal: Linha < Coluna.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/
void printLUTriangleDoubleMatrix   ( int linha, int coluna, double matrix[][coluna] )
{

    int x = 0;
    int y = 0;

    if ( linha != coluna)
    {
        printf("Valor invalido.\n");
    }
    else
    {
        for ( x = 0; x < linha; x++ )
        {
            for ( y = 0; y < coluna; y++ )
            {
                if ( y > x ){
                    printf("%6.2f", matrix[x][y]);
                }
            }
        }
    }
    printf("\n");
}

/*
    printSLDTriangleDoubleMatrix - Imprime na tela os valores flutuantes abaixo da diagonal secundaria da matriz.
    @attention Regra para valores abaixo da diagonal secundaria: Linha + Coluna > Linha - 1.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/ 
void printSLDTriangleDoubleMatrix  ( int linha, int coluna, double matrix[][coluna] )
{

    int x = 0;
    int y = 0;

    if ( linha != coluna)
    {
        printf("Valor invalido.\n");
    }
    else
    {

        for ( x = 0; x < linha; x++)
        {
            for ( y = 0; y < coluna; y++)
            {
                if( x + y > linha - 1 )
                {
                    printf("%6.2f", matrix[x][y]);
                } // fim do if
            } // fim do for
        } // fim dor for

    } // fim if
    printf("\n");
}

/*
    printSLUTriangleDoubleMatrix - Imprime na tela os valores flutuantes acima da diagonal secundaria da matriz.
    @attention Regra para valores abaixo da diagonal secundaria: Linha + Coluna < Linha - 1.
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores flutuantes
*/
void printSLUTriangleDoubleMatrix  ( int linha, int coluna, double matrix[][coluna] )
{
    int x = 0;
    int y = 0;

    if ( linha != coluna)
    {
        printf("Valor invalido.\n");
    }
    else
    {

        for ( x = 0; x < linha; x++)
        {
            for ( y = 0; y < coluna; y++)
            {
                if( x + y < linha - 1 )
                {
                    printf("%6.2f", matrix[x][y]);
                } // fim do if
            } // fim do for
        } // fim dor for

    } // fim if
    printf("\n");
}

/*
    allZerosLTriangleDoubleMatrix - Testa se os valores inferiores da diagonal principal são iguais a zero.
    @return - false, se todos os dados forem iguais a zero;
    true, caso contrario
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param matrix - grupo de valores inteiros
*/
bool allZerosLTriangleDoubleMatrix ( int linha, int coluna, double matrix[][coluna] )
{
    int x = 0;
    int y = 0;
    bool result = false;

    if ( linha != coluna)
    {
        printf("Valor invalido.\n");
    }
    else
    {
        result = true;
        while (x < linha && result) {
            y = 0;
            while (y < coluna && result) {
                if (y < x && matrix[x][y] != 0.0) {
                    result = false;
                }
                y++;
            }
            x++;
        }

        return result;
    }
}

/*
    allZerosLTriangleDoubleMatrix - Testa se os valores superiores da diagonal principal não são iguais a zero.
    @return - true, se todos os dados forem iguais a zero;
    false, caso contrario
    @param Linha - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param matrix - grupo de valores inteiros
*/
bool allZerosUTriangleDoubleMatrix ( int linha, int coluna, double matrix[][coluna] )
{
    int x = 0;
    int y = 0;
    bool result = false;

    if ( linha != coluna)
    {
        printf("Valor invalido.\n");
    }
    else
    {
        result = true;
        while (x < linha && result) {
            y = 0;
            while (y < coluna && result) {
                if ( y > x && matrix[x][y] != 0.0) {
                    result = false;
                }
                y++;
            }
            x++;
        }

        return result;
    }
}

/*
    buildSeqIntMatrix - Monta uma matriz de inteiros com valores sequenciais da esquerda para direita, de cima para baixo.
    @param Linha  - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores inteiros
*/
void buildSeqIntMatrix             ( int linha, int coluna, int matrix[][coluna] )
{
    int x = 0;
    int y = 0;
 
    while ( x < linha )
    {
        y = 0;
        while ( y < coluna )
        {
            matrix[x][y] = x * coluna + y + 1;
            y++;
        } // fim do while
        x++;
    } // fim do while
}
 
/*
    buildRevIntMatrix - Monta uma matriz de inteiros com valores decrescentes da direita para esquerda, de baixo para cima.
    @param Linha  - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores inteiros
*/
void buildRevIntMatrix             ( int linha, int coluna, int matrix[][coluna] )
{
    int x = 0;
    int y = 0;
 
    while ( x < linha )
    {
        y = 0;
        while ( y < coluna )
        {
            matrix[x][y] = ( linha - x ) + linha * ( coluna - 1 - y );
            y++;
        } // fim do while
        x++;
    } // fim do while
}
 
/*
    printIntMatrix - Imprime os valores inteiros de uma matriz.
    @param Linha  - Numero de linhas.
    @param Coluna - Numero de Colunas.
    @param Matrix - Grupo de valores inteiros
*/
void printIntMatrix                ( int linha, int coluna, int matrix[][coluna] )
{
    int x = 0;
    int y = 0;
 
    printf("\n");
    while ( x < linha )
    {
        y = 0;
        while ( y < coluna )
        {
            printf("%4d", matrix[x][y]);
            y++;
        } // fim do while
        printf("\n");
        x++;
    } // fim do while
}
 
/*
    fprintIntMatrix - Grava em um arquivo valores inteiros de uma matriz.
    @param Filename - Nome do arquivo.
    @param Linha    - Numero de linhas.
    @param Coluna   - Numero de Colunas.
    @param Matrix   - Grupo de valores inteiros
*/
void fprintIntMatrix ( chars fileName, int linha, int coluna, int matrix[][coluna] )
{
    int x = 0;
    int y = 0;
 
    FILE* arquivo;
    arquivo = fopen ( fileName, "wt" );
 
    fprintf( arquivo, "%d\n", linha );
    fprintf( arquivo, "%d\n", coluna );
 
    while ( x < linha )
    {
        y = 0;
        while ( y < coluna )
        {
            fprintf( arquivo, "%d\n", matrix[x][y] );
            y++;
        } // fim do while
        x++;
    } // fim do while
 
    fclose ( arquivo );
}


// fim das funções

// inicio dos methods

void method_01 (void){

     
    IO_id("Method 01 - v0.0");

    int linha  = 0;
    int coluna = 0;
    double positiveMatrix [10][10]; // reserva 10x10 espaços na memoria;

    do {
        printf("Linhas: ");
        scanf("%d", &linha);
        if ( linha <= 0 )
        {
            printf("A dimensão não pode ser negativa ou nula.\n\n");
        }
    }
    while ( linha <= 0 );

    do {
        printf("Coluna: ");
        scanf("%d", &coluna);
        if ( coluna <= 0 )
        {
            printf("A dimensão não pode ser negativa ou nula.\n\n");
        }
    }
    while ( coluna <= 0 );
    
    printf("\n");
    readDoubleMatrix  (linha, coluna, positiveMatrix);
    printDoubleMatrix (linha, coluna, positiveMatrix);

     
    IO_pause("Aperte ENTER para terminar.");
}
void method_02 (void){

     
    IO_id("Method 02 - v0.0");

    int linha  = 0;
    int coluna = 0;
    double positiveMatrix [10][10]; // reserva 10x10 espaços na memoria;

    do {
        printf("Linhas: ");
        scanf("%d", &linha);
        if ( linha <= 0 )
        {
            printf("A dimensão não pode ser negativa ou nula.\n\n");
        }
    }
    while ( linha <= 0 ); // valida se a dimensão não é negativa

    do {
        printf("Coluna: ");
        scanf("%d", &coluna);
        if ( coluna <= 0 )
        {
            printf("A dimensão não pode ser negativa ou nula.\n\n");
        }
    }
    while ( coluna <= 0 ); // valida se a dimensão não é negativa
    
    printf("\n");
    
    positiveMatrix[linha][coluna]; // definição de dados

    // ler dados
    readDoubleMatrix ( linha, coluna, positiveMatrix );

    // gravar dados em arquivo
    fprintDoubleMatrix ( "MATRIX_01.TXT", linha, coluna, positiveMatrix);
    
    // ler os dados gravados no arquivo
    fscanfDoubleMatrix ( "MATRIX_01.TXT", linha, coluna, positiveMatrix );

    // mostra na tela os valores lidos
    printDoubleMatrix ( linha, coluna, positiveMatrix);

    IO_pause("Aperte ENTER para terminar.");
}
void method_03 (void){

     
    IO_id("Method 03 - v0.0");

    int linha  = 0;
    int coluna = 0;
    double positiveMatrix [10][10]; // reserva 10x10 espaços na memoria

    // garente que os valores sao maiores que 0 e, nesse caso, quadraticos
    do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa

    printf("\n");

    positiveMatrix[linha][coluna]; // guarda os valores de linha e coluna

    readDoubleMatrix(linha, coluna, positiveMatrix); // lê e grava na matriz os valores

    printf("\n");
    printDiagonalDoubleMatrix ( linha, coluna, positiveMatrix); // printa a diagonal principal

    IO_pause("Aperte ENTER para terminar.");
}
void method_04 (void){

     
    IO_id("Method 04 - v0.0");

    int linha  = 0;
    int coluna = 0;
    double positiveMatrix [10][10]; // reserva 10x10 espaços na memoria
     
    do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa
    printf("\n");

    positiveMatrix[linha][coluna];
    readDoubleMatrix( linha, coluna, positiveMatrix); // lê e grava na matriz os valores
    
    printf("\n");
    printSDiagonalDoubleMatrix ( linha, coluna, positiveMatrix);


    IO_pause("Aperte ENTER para terminar.");
}
void method_05 (void){

     
    IO_id("Method 05 - v0.0");

    int linha = 0;
    int coluna = 0;
    double positiveMatrix [10][10];

    do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa
    printf("\n");


    positiveMatrix[linha][coluna];
    readDoubleMatrix(linha, coluna, positiveMatrix); 

    printf("\n");
    printLDTriangleDoubleMatrix(linha, coluna, positiveMatrix);

     

    IO_pause("Aperte ENTER para terminar.");
}
void method_06 (void){

     
    IO_id("Method 06 - v0.0");

    int linha = 0;
    int coluna = 0;
    double positiveMatrix[10][10];

     do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa
    printf("\n");

    positiveMatrix[linha][coluna];
    readDoubleMatrix(linha, coluna, positiveMatrix);

    printf("\n");
    printLUTriangleDoubleMatrix(linha, coluna, positiveMatrix);

     
    IO_pause("Aperte ENTER para terminar.");
}
void method_07 (void){

     
    IO_id("Method 07 - v0.0");

    int linha = 0;
    int coluna = 0;
    double positiveMatrix[10][10];

     do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa
    printf("\n");

    positiveMatrix[linha][coluna];
    readDoubleMatrix(linha, coluna, positiveMatrix);

    printf("\n");
    printSLDTriangleDoubleMatrix( linha, coluna, positiveMatrix);
     
    IO_pause("Aperte ENTER para terminar.");
}
void method_08 (void){

     
    IO_id("Method 08 - v0.0");

    int linha = 0;
    int coluna = 0;
    double positiveMatrix[10][10];

     do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa
    printf("\n");

    positiveMatrix[linha][coluna];
    readDoubleMatrix( linha, coluna, positiveMatrix );
    printf("\n");
    printSLUTriangleDoubleMatrix( linha, coluna, positiveMatrix );
     
    IO_pause("Aperte ENTER para terminar.");
}
void method_09 (void){

     
    IO_id("Method 09 - v0.0");

    int resultado = 0;
    int linha = 0;
    int coluna = 0;
    double positiveMatrix[10][10];

     do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa
    printf("\n");

    positiveMatrix[linha][coluna];
    readDoubleMatrix( linha, coluna, positiveMatrix );
    printDoubleMatrix ( linha, coluna, positiveMatrix);
    resultado = allZerosLTriangleDoubleMatrix ( linha, coluna, positiveMatrix );
    printf("\n");
    if ( resultado == 1)
    {
        printf("Os valores abaixo da diagonal principal são iguais a 0.\n");
    }
    else
    {
        printf("Os valores abaixo da diagonal principal não são iguais a 0.\n");
    }

    IO_pause("Aperte ENTER para terminar.");
}
void method_10 (void){

     
    IO_id("Method 10 - v0.0");

    int resultado = 0;
    int linha = 0;
    int coluna = 0;
    double positiveMatrix[10][10];

     do {
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("\n");
    
        if ( linha != coluna)
        {
            printf("Linha e Coluna precisam ter os mesmos valores.\n");
        }

        if ( linha <= 0 || coluna <= 0 )
        {
            printf("As dimensões não podem ser negativas ou nulas.\n");
        }
    }
    while ( linha <= 0 || coluna <= 0 || linha != coluna ); // valida se a dimensão não é negativa
    printf("\n");

    positiveMatrix[linha][coluna];
    readDoubleMatrix( linha, coluna, positiveMatrix );
    printDoubleMatrix ( linha, coluna, positiveMatrix);
    resultado = allZerosUTriangleDoubleMatrix ( linha, coluna, positiveMatrix );
    printf("\n");
    if ( resultado == 1)
    {
        printf("Os valores acima da diagonal principal são iguais a 0.\n");
    }
    else
    {
        printf("Os valores acima da diagonal principal não são iguais a 0.\n");
    }
     
    IO_pause("Aperte ENTER para terminar.");
}
void method_E1 (void){
 
    IO_id("Method E1 - v0.0");
 
    int linha  = 0;
    int coluna = 0;
    int seqMatrix[10][10];
 
    do {
        printf("Linhas: ");
        scanf("%d", &linha);
        if ( linha <= 0 || linha > 10 )
        {
            printf("A dimensão deve ser entre 1 e 10.\n\n");
        }
    }
    while ( linha <= 0 || linha > 10 );
 
    do {
        printf("Coluna: ");
        scanf("%d", &coluna);
        if ( coluna <= 0 || coluna > 10 )
        {
            printf("A dimensão deve ser entre 1 e 10.\n\n");
        }
    }
    while ( coluna <= 0 || coluna > 10 );
 
    buildSeqIntMatrix ( linha, coluna, seqMatrix );
    printIntMatrix    ( linha, coluna, seqMatrix );
    fprintIntMatrix   ( "MATRIX_E1.TXT", linha, coluna, seqMatrix );
 
    printf("\nMatriz gravada em MATRIX_E1.TXT.\n");
 
    IO_pause("Aperte ENTER para terminar.");
}
void method_E2 (void){
 
    IO_id("Method E2 - v0.0");
 
    int linha  = 0;
    int coluna = 0;
    int revMatrix[10][10];
 
    do {
        printf("Linhas: ");
        scanf("%d", &linha);
        if ( linha <= 0 || linha > 10 )
        {
            printf("A dimensão deve ser entre 1 e 10.\n\n");
        }
    }
    while ( linha <= 0 || linha > 10 );
 
    do {
        printf("Coluna: ");
        scanf("%d", &coluna);
        if ( coluna <= 0 || coluna > 10 )
        {
            printf("A dimensão deve ser entre 1 e 10.\n\n");
        }
    }
    while ( coluna <= 0 || coluna > 10 );
 
    buildRevIntMatrix ( linha, coluna, revMatrix );
    printIntMatrix    ( linha, coluna, revMatrix );
    fprintIntMatrix   ( "MATRIX_E2.TXT", linha, coluna, revMatrix );
 
    printf("\nMatriz gravada em MATRIX_E2.TXT.\n");
 
    IO_pause("Aperte ENTER para terminar.");
}
 
// fim dos methods

int main ( int argc, char* argv [ ] ){

    SetConsoleOutputCP(CP_UTF8); // corrige o unicode do compilador
    SetConsoleCP(CP_UTF8);  // corrige o unicode do compilador

    int x;

    do {

    IO_id      ("\nExemplo0300 - Programa - v0.0");
    IO_println ("=+= Opções =+= \n ");
    IO_println (" 0 - Parar \n");

    printf("%s%s\n", " 1 - Método 01      ", " 6 - Método 06"); 
    printf("%s%s\n", " 2 - Método 02      ", " 7 - Método 07"); 
    printf("%s%s\n", " 3 - Método 03      ", " 8 - Método 08"); 
    printf("%s%s\n", " 4 - Método 04      ", " 9 - Método 09"); 
    printf("%s%s\n", " 5 - Método 05      ", "10 - Método 10"); 

    IO_println ("");
    printf("%s%s\n", "11 - Extra E1      ", "12 - Extra E2"); 


    IO_println ("");

    x = IO_readint("Entrar com uma opção: ");

    switch (x)
    {
        case 1:  method_01 ();  break;
        case 2:  method_02 ();  break;
        case 3:  method_03 ();  break;
        case 4:  method_04 ();  break;
        case 5:  method_05 ();  break;
        case 6:  method_06 ();  break;
        case 7:  method_07 ();  break;
        case 8:  method_08 ();  break;
        case 9:  method_09 ();  break;
        case 10: method_10 ();  break;
        case 11: method_E1 ();  break;
        case 12: method_E2 ();  break;

        default:
            IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
            IO_concat ( IO_toString_d ( x ), ")" ) ));
    } 
}
    while (x != 0);

    IO_pause ("Apertar ENTER para terminar");
    return(0);
}

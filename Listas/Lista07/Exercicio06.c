/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>

// funções


void multiplos_tres      ( int x ) // Mostra os multiplos de 3 de forma crescente.
{
    // IO_printf("1. X = %d\n", x);
    if ( x == 0 ){
        return;
    }

    multiplos_tres ( x - 1 ); // vai "empilhar" ate chegar em 0 e só depois rodar o printf
    printf("\n3 * %d = %d", x, 3*x); // printf depois pra ser executado na volta.
}
void multiplos_cinco     ( int x ) // Mostra os multiplos de 5 de forma decrescente.
{
    
    if ( x == 0 )
    {
        return;
    } 

    printf("\n5 * %d = %d", x, 5 * x); // Printf antes pra ser executado na ida.
    multiplos_cinco ( x - 1 );
}
void inv_multiplos_tres  ( int x )
{
    //IO_printf("X = %d\n", x);
    if ( x == 0 ) 
    {
        return; 
    }
    
    inv_multiplos_tres ( x - 1);
    printf("1/%d\n", 3*x);
}
void inv_multiplos_cinco ( int x )
{
    if ( x == 0 )
    {
        //printf("1/1");
        return;
    }

    IO_printf("1/%d\n", 5*x);
    inv_multiplos_cinco( x - 1);
}
void cadeiaCaracteres    ( char cadeia[], int i )
{
    if ( cadeia[i] != '\0' ){

        cadeiaCaracteres ( cadeia, i + 1 );
        printf("%c\n", cadeia[i]);
    }
}

int paresnaString   ( char cadeia[], int i)
    {
    
        if ( cadeia[i] == '\0')
        {
            return 0;
        }
    
        if ( cadeia[i] >= '0' && cadeia[i] <= '9'){
            if (( cadeia[i] - '0') % 2 == 0 ){
                return 1 + paresnaString(cadeia, i + 1);
                } // fim segudo if
            } // fim primeiro if
    
        return paresnaString(cadeia, i + 1); 
    }
int soma_impares    ( int n, int impar, int termo ){

    int soma = 0;

    if ( n > 0 ){

        soma = termo + soma_impares ( n - 1, impar + 2, termo + impar);

    } 
    
    return (soma);
   

}
int intervaloUpper  ( char cadeia[], int i)
{
    if ( cadeia[i] == '\0'){
    return 0;
    }

    if ( cadeia[i] > 'K' && cadeia[i] < 'P'){
    return 1 + intervaloUpper( cadeia, i + 1);
    }

    return intervaloUpper(cadeia, i + 1); 

}

double soma_pares   ( int n, double par_atual)
{
    if ( n == 0 ){
        return 0;
    }

    return par_atual + soma_pares(n - 1, 1 / (par_atual + 2) );
}

int fib             (int n) {
    if (n <= 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
int somaParFib      (int quantidade, int pos) {
    if (quantidade == 0)
        return 0;

    if (fib(pos) % 2 == 0)
        return fib(pos) + somaParFib(quantidade - 1, pos + 1);

    return somaParFib(quantidade, pos + 1);
}


double pot (double x, int exp) {
    if (exp == 0)
        return 1;
    return x * pot(x, exp - 1);
}
double f   (double x, int n, int exp) {
    if (n == 0)
        return 0;

    return pot(x, exp) + f(x, n - 1, exp == 0 ? 3 : exp + 2);
}


double fat    (int n) {
    if (n <= 1)
        return 1;
    return n * fat(n - 1);
}
double e_calc (int n, double num, int base, int inc) {
    if (n == 0)
        return 0;

    return (num / fat(base)) + e_calc(n - 1, num + inc, base * 3, inc + 1);
}


// fim funções

// inicio dos methods

void method_01 (void){

    // identificação
    IO_id("Method 01 - v0.0");

    int resultado = 0;
    int x = IO_readint("X = ");
    IO_println("");
    multiplos_tres(x); 
    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_02 (void){

    // identificação
    IO_id("Method 02 - v0.0");

    int x = 0;
    x = IO_readint("X = ");
    IO_println("");
    multiplos_cinco(x);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_03 (void){

    // identificação
    IO_id("Method 03 - v0.0");

    int x = 0;
    x = IO_readint("X = ");
    IO_println("");

    IO_printf("1/1\n");
    inv_multiplos_tres ( x - 1 );

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_04 (void){

    // identificação
    IO_id("Method 04 - v0.0");

    int x = 0;
    x = IO_readint("X = ");
    IO_println("");

    inv_multiplos_cinco( x - 1 );
    IO_printf("1/1\n");


    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_05 (void){

    // identificação
    IO_id("Method 05 - v0.0");

    int x         = 0;
    int resultado = 0;
    x = IO_readint("X = ");
    resultado = soma_impares ( x, 1, 3);

    printf("A soma dos numeros são: %d", resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_06 (void){

    // identificação
    IO_id("Method 06 - v0.0");

    int x         = 0;
    double resultado = 0;
    x = IO_readint("X = ");
    resultado = soma_pares ( x, 4 );

    IO_printf("O resultado da soma dos inversos multiplos de 4 é: %.2f", resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_07 (void){

    // identificação
    IO_id("Method 07 - v0.0");

    chars palavra = IO_readstring("Entre com uma palavra: ");
    printf("\n");
    cadeiaCaracteres(palavra, 0);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_08 (void){

    // identificação
    IO_id("Method 08 - v0.0");

    int quantidade = 0;
    chars palavra  = IO_readstring("Entre com uma palavra: ");
    printf("\n");

    quantidade = paresnaString(palavra, 0);
    printf("Quantidade de pares: %d\n", quantidade);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_09 (void){

    // identificação
    IO_id("Method 09 - v0.0");
    
    int quantidade = 0;
    chars palavra  = IO_readstring("Entre com uma palavra: ");
    printf("\n");

    quantidade = intervaloUpper(palavra, 0);
    printf("Letras maiusculas no intervalo (K:P): %d\n", quantidade);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_10 (void){

    // identificação
    IO_id("Method 10 - v0.0");

    printf("n=1 | %d\n", somaParFib(1, 1)); 
    printf("n=2 | %d\n", somaParFib(2, 1)); 
    printf("n=3 | %d\n", somaParFib(3, 1)); 
    printf("n=4 | %d\n", somaParFib(4, 1)); 

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}

void method_11 (void){

    // identificação
    IO_id("Extras 1");

    double x;
    int n;

    printf("x: "); scanf("%lf", &x);
    printf("n: "); scanf("%d",  &n);

    printf("f (%.1f, %d) = %.2f\n", x, n, f(x, n, 0));
    getchar();

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_12 (void){

    // identificação
    IO_id("Extra 2");

    int n;
    printf("n: "); scanf("%d", &n);

    printf("e(%d) = %.6f\n", n, e_calc(n, 1, 1, 1));

    getchar();
    // encerrar
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
    printf("%s%s\n", "11 - Extra 01       ", "12 - Extra 02"); 

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
        case 11: method_11 ();  break;
        case 12: method_12 ();  break;

        default:
            IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
             IO_concat ( IO_toString_d ( x ), ")" ) ));
    } 
}
    while (x != 0);

    IO_pause ("Apertar ENTER para terminar");
    return(0);
}

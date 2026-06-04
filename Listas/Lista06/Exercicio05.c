/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>
#include <math.h>

// inicio das funções

int potencia          ( int base, int expo ){

    int resultado = 1;

    for(int i = 1; i <= expo; i++){
        resultado = resultado * base;
    }
    return (resultado);
}
int multiplos         ( int x, int y ){
   return x * y;
}
int somainteiros      ( int x, int y ){
    
    int numero   = x;
    int fim      = y;
    int contador = 0;
    int soma     = 0; 
    
    while (contador < fim){
        soma = soma + numero;
        numero++;
        contador++;
    } 
    return(soma);
}
int somamultiplos  ( int x, int y, int n){ 
    
    int simMultiplo = x; // todos numeros que forem multiplos de x irão ser contabilizados
    int naoMultiplo = y; // todos numeros que forem multiplos de y NÃO irão ser contabilizados
    int contador = 0;
    int numero   = 0;
    int soma  = 0;
    
    while (contador < n){
        
        numero = numero + x; // seta a principio numero com o valor inserido pelo usuario e depois reintera o valor
        if (numero % simMultiplo == 0 && numero % naoMultiplo != 0){
            soma = soma + numero;
            contador++;
        }
    }
    return soma;
}


double inversoPot     ( double x, int i ){
    int expo = ( i - 1) * 2;
    double resultado = pow (x , expo);
    return (resultado);
}
double somainversomultiplos  ( int x, int y, int n){ 
    
    int simMultiplo = x; // todos numeros que forem multiplos de x irão ser contabilizados
    int naoMultiplo = y; // todos numeros que forem multiplos de y NÃO irão ser contabilizados
    int contador = 0;
    int numero   = 0;
    double soma  = 0;
    
    while (contador < n){
        
        numero = numero + x; // seta a principio numero com o valor inserido pelo usuario e depois reintera o valor
        if (numero % simMultiplo == 0 && numero % naoMultiplo != 0){
            soma = soma + (1.0 / numero);
            contador++;
        }
    }
    return soma;
}
double somainversos3  ( int n ){
    
    int controle       = 0;
    int aumento        = 1;
    int x              = 3;
    double soma        = 0.0;
    double numerador   = 1.0;
    double denominador = 1.0;

    while ( n > controle){

        soma = soma + numerador/(x * denominador);
        x = x + aumento;
        aumento++;
        n--;

    }
    return ( soma );
}


// fim das funções

// inicio dos methods

void method_01 (void){
    
    IO_id("Method 01 - v0.0"); // identificação

    IO_print("Multiplos de 3\n"); // informar ao usuario do que se trata o metodo
    int x = IO_readint("Entre com a quantidade de vezes: "); // solicitar entrada do usuario
    
    IO_print("Os multiplos de 3 em ordem crescente são: \n\n");

    int resultado = 1;
    for ( int i = 1; x >= i ; i++ ){ // loop crescente iterando i
        resultado = multiplos(3, i);
        printf("%d. %d\n", i, resultado);
    }
    

    IO_pause("Aperte ENTER para terminar.");
}
void method_02 (void){

// identificação
    IO_id("Method 02 - v0.0");

    IO_print("Multiplos de 3 e 5\n"); // informar ao usuario do que se trata o metodo
    int x = IO_readint("Entre com a quantidade de vezes: "); // pedir input do usuario
    IO_print("Os multiplos de 3 e 5 em ordem crescente são: \n\n");

    int resultado = 1;
    for ( int i = 1; x >= i ; i++ ){
        resultado = multiplos(15, i);
        printf("%d. %d\n", i, resultado);
    }

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_03 (void){

    int resultado = 1;

    IO_id("Method 03 - v0.0"); // identificação
    IO_printf("Potencias de base 3 em ordem decrescente. \n"); // informar ao usuario do que se trata o methodo
    int x = IO_readint("Entre com a quantidade de vezes: "); // pedir o valor ao usuario
    IO_println(""); // espaçamento

    int contador = x; // atribuir a x para fazer a contagem decrescente dentro do loop

    for ( int i = 1; contador >= i; --contador  ){
        resultado = potencia( 3, x );
        printf("%d. %d\n", contador, resultado);
        x--;
    }

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_04 (void){

    // identificação
    IO_id("Method 04 - v0.0");

    IO_print("Sequencia dos inversos multiplos de 3\n"); // informar ao usuario do que se trata o metodo
    int x = 1;
    int resultado = 1;
    x = IO_readint("Entre com a quantidade de vezes: "); // solicitar input do usuario
    IO_println("");

    IO_print("A sequencia dos inversos de 3 são: \n\n");

    for ( int i = 1; i <= x; i++){
        resultado = multiplos(3 , i);
        printf("%d. 1/%.4f\n", i , resultado);
    }

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_05 (void){

    
    IO_id("Method 05 - v0.0"); // identificação
    
    double resultado = 1;

    double x      = IO_readdouble("Entre com um valor real: "); // solicitar o input do usuario
    int n         = IO_readint("Entre com a quantidade de vezes: "); // solicitar o input do usuario
    IO_println("");

    for ( int i = 1; i <= n; i++){
        
        resultado = inversoPot(x, i);
        IO_printf("%d. 1/%.4f\n", i , resultado);
    }


    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_06 (void){

    IO_id("Method 06 - v0.0"); // identificação

    IO_printf("Soma de multiplos de 3 e não mutiplos de 5.\n");
    int x = IO_readint("Entre com a quantidade de vezes: ");
    int resultado = somamultiplos(3, 5, x);
    IO_printf("Soma: %d", resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_07 (void){

    
    IO_id("Method 07 - v0.0"); // identificação

    IO_printf("Soma dos inversos de multiplos de 4 e não mutiplos de 5.\n");
    int x = IO_readint("Entre com a quantidade de vezes: ");
    double resultado = somainversomultiplos(4, 5, x);
    IO_printf("Soma dos inversos: %.4f", resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_08 (void){

    int resultado = 0;
    
    // identificação
    IO_id("Method 08 - v0.0");

    IO_printf("Soma dos numeros inteiros a partir de 5.\n");
    int x = IO_readint("Entre com a quantidade de vezes: ");
    IO_println("");

    resultado = somainteiros(5, x);
    IO_printf("A soma dos numeros inteiros a partir de 5 ate %d, são: %d", x, resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_09 (void){

    int x = 1;
    int numero = 3;
    int resultado = 0;

    IO_id("Method 09 - v0.0");  // identificação
    IO_printf("Soma dos quadrados dos números naturais começando no valor 9\n");
    x = IO_readint("Entre a quantidade de vezes: ");
    IO_println("");

    for ( int i = 1; x >= i; i++){
        IO_printf("%d² = %d\n", numero, numero * numero);
        numero++;
        resultado = somainteiros(3 , x);
    }

    IO_printf("\nSoma dos quadrados: %d\n", resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_10 (void){

    // identificação
    IO_id("Method 10 - v0.0");
 
    int n = 0;
    n = IO_readint("Insira uma quantidade: ");
    IO_printf("%s%lf\n", "Soma dos inversos das adições de naturais terminando em 3: ", somainversos3(n));

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

        default:
            IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
             IO_concat ( IO_toString_d ( x ), ")" ) ));
    } 
}
    while (x != 0);

    IO_pause ("Apertar ENTER para terminar");
    return(0);
}

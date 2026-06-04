/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>

// inicio das funções

/**
Definicao de tipo arranjo com inteiros
baseado em estrutura
*/
    typedef
    struct s_int_Array
    {
    int length;
    ints data ;
    int ix ;
    }
    int_Array;



int RandomIntGenerate (int min, int max)
{

    int resultado = 0;

    if ( min > max )
    {
        printf("ERRO: Intervalo incorreto.");
        return 0;
    }

    

    return
}

// fim das funções

// inicio dos methods

void method_01 (void){

    int a = 0;
    int b = 0;
    int n = 0;
    int rand = 0;

    IO_id("Method 01 - v0.0");


    printf("Valor inferior do intervalo: ");
    scanf("%d", &a);
    printf("\nValor superior do intervalo: ");
    scanf("%d", &b);

    printf("Quantidade de valores (N): ");
    scanf("%d", &n);

    


    IO_pause("Aperte ENTER para terminar.");
}
void method_02 (void){

     
    IO_id("Method 02 - v0.0");


     
    IO_pause("Aperte ENTER para terminar.");
}
void method_03 (void){

     
    IO_id("Method 03 - v0.0");

     

    IO_pause("Aperte ENTER para terminar.");
}
void method_04 (void){

     
    IO_id("Method 04 - v0.0");

     
    IO_pause("Aperte ENTER para terminar.");
}
void method_05 (void){

     
    IO_id("Method 05 - v0.0");

     

    IO_pause("Aperte ENTER para terminar.");
}
void method_06 (void){

     
    IO_id("Method 06 - v0.0");


     
    IO_pause("Aperte ENTER para terminar.");
}
void method_07 (void){

     
    IO_id("Method 07 - v0.0");


     
    IO_pause("Aperte ENTER para terminar.");
}
void method_08 (void){

     
    IO_id("Method 08 - v0.0");


     
    IO_pause("Aperte ENTER para terminar.");
}
void method_09 (void){

     
    IO_id("Method 09 - v0.0");

     

    IO_pause("Aperte ENTER para terminar.");
}
void method_10 (void){

     
    IO_id("Method 10 - v0.0");


     
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

/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>

// inicio dos metodos

void method_01 (void){
    
    IO_id("Metodo 01");

    int y        = 0;
    int tamanho  = 0;
    int contador = 0;
    chars palavra = IO_new_chars( STR_SIZE );

    palavra = IO_readstring("Entre com uma palavra: ");
    tamanho = strlen(palavra);
    printf("%s", palavra);

    for ( y = 0 ; y < tamanho; ++y )
    {
        if ( (palavra[y] >= 'A' && palavra[y] <= 'Z') && palavra[y] < 'K' )
        {
            printf("%c", palavra[y]);
        } // fim do if
    }
     


    IO_pause("Apertar ENTER para continuar");
}
void method_02 (void){
    
     IO_id("Metodo 02");

    int y        = 0;
    int tamanho  = 0;
    int contador = 0;
    chars palavra = IO_readstring("Entre com uma palavra: ");   

    tamanho = strlen(palavra);
    printf("%s", palavra);
    for ( y = 0 ; y < tamanho; ++y )
    {
        if ( (palavra[y] >= 'a' && palavra[y] <= 'z') && palavra[y] > 'k' )
        {
            printf("[%d]: %c\n", contador, palavra[y]);
            contador++;
        } 
    }
    

    IO_pause("Apertar ENTER para continuar");
}
void method_03 (void){
   
    IO_id("Method_03 - v0.0");

    int y        = 0;
    int tamanho  = 0;
    int contador = 0;
    chars palavra = IO_new_chars(STR_SIZE);
    palavra = IO_readstring("Entre com uma palavra: ");

    tamanho = strlen(palavra) -1;
    contador = 0;
    printf("%s\n\n", palavra);

    for ( y = tamanho ; y >= 0 ; --y ){
        if ('A' <= palavra[y] && palavra[y] < 'K'){
            contador++;
            printf("[%d]: %c\n", contador, palavra[y]);
        }
    }


    IO_pause("Apertar ENTER para continuar");
}
void method_04 (void){
    
    // definição de varivaeis 

    IO_id("Method_04 - v0.0");
    int x        = 0;
    int tamanho  = 0;
    int contador = 0;
    chars palavra = IO_new_chars(STR_SIZE);

    palavra = IO_readstring("Insira uma palavra: ");
    printf("\n");
    tamanho = strlen(palavra) -1; // nao esquecer de colocar o -1 pra excluir o caractere oculto
    contador = 0;

    // fim definição de varivaeis 
    // inicio do for e condicionais

    for ( x = 0; x < tamanho; ++x){
        if((palavra[x] >= 'A' && palavra[x] <= 'Z') || 
           (palavra[x] >= 'a' && palavra[x] <= 'z')){

            contador++;
            printf("%d. %c\n", contador, palavra[x]);

        } // fim do if
} // fim do for

    IO_pause("Apertar ENTER para continuar");
}
void method_05 (void){
    
    IO_id("Method_05 - v0.0");

    // definição de variaveis

    int x        = 0;
    int tamanho  = 0;
    int contador = 0;
    chars palavra = IO_new_chars(STR_SIZE);
    palavra = IO_readstring("Insira uma palavra: ");
    tamanho = strlen(palavra) -1;

    // fim da definição de variaveis
    // inicio do for e if

    for ( x = tamanho ; x >= 0; --x){ // for com contagem decrescente
        if (((palavra[x] >= '0') && (palavra[x] <= '9')) && 
            ((palavra[x] - '0') % 2 == 0 )){  // forma mais conceitualmente correta de fazer o calculo se um numero é par ou impar.

            contador++;
            printf("%d. %c\n", contador, palavra[x]);

        } // fim do if
    } // fim dor for

    IO_pause("Apertar ENTER para continuar");
}
void method_06 (void){
    
    IO_id("Method_06 - v0.0");

    // inicialização das variaveis

    int x        = 0;
    int tamanho  = 0;
    int contador = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    palavra = IO_readstring("Entre com uma palavra: ");
    tamanho = strlen(palavra) -1;

    // fim da inicialização
    // inicio for e if

    for ( x = 0; x <= tamanho; x++){

        int eLetra = (palavra[x] >= 'A' && palavra[x] <= 'Z') || 
                 (palavra[x] >= 'a' && palavra[x] <= 'z'); // checa se a letra ta no intervalo de "A:Z" ou "a:z"

        int eNumero = ((palavra[x] >= '0' && palavra[x] <= '9') && 
                   (palavra[x] - '0') % 2 == 0);          // checa se o numero é par

        if (!( eLetra || eNumero)){ // negação da checagem de Letra e Numero, vai imprimir tudo o que nao estiver dentro da condição
            contador++;
            printf("%d. %c\n", contador, palavra[x]);
        
        } // fim do if
    } // fim do for

    IO_pause("Apertar ENTER para continuar");
}
void method_07 (void){
    
    IO_id("Method_07 - v0.0");

    // definição de varivaeis

    int a        = 0;
    int b        = 0;
    int n        = 0;
    int x        = 0; 
    int contador = 0; 

    a = IO_readint   ("Insira o valor inferior do intervalo: ");
    b = IO_readint   ("Insira o valor inferior do intervalo: ");
    n = IO_readint ("Quantidade de valores a serem testados: ");

    // fim da definição de varivaeis

    printf("\nIntervalo: [%d:%d] - Numero de testes: %d.\n", a, b, n);

    for ( n = n ; n > 0 ; n--){

        contador++;
        printf("\n%d. Insira um valor: ", contador);
        scanf("%d", &x);

        if (( x % 5 == 0 ) && ( (a <= x) && (x <= b))){ // verifica se resto de x é 0 e se x esta dentro do intervalo [a:b]

            printf("O valor %d é multiplo por 5 e esta dentro do intervalo.\n", x);
        
        } // fim do if
        else{
            
            printf("Não atende aos criterios.\n");
        
        } // fim do else
    } // fim do for

    IO_pause("Apertar ENTER para continuar");
    getchar();
}
void method_08 (void){
   
    IO_id("Method_08 - v0.0");

    // definição de varivaeis

    int a        = 0;
    int b        = 0;
    int n        = 0;
    int x        = 0; 
    int contador = 0; 

    a = IO_readint   ("Insira o valor inferior do intervalo: ");
    b = IO_readint   ("Insira o valor inferior do intervalo: ");
    n = IO_readint ("Quantidade de valores a serem testados: ");

    // fim da definição de varivaeis

    printf("\nIntervalo: [%d:%d] - Numero de testes: %d", a, b ,n);
    printf("\n");

    for ( n = n ; n > 0 ; n-- ){
        
        contador++;
        printf("\n%d. Insira um valor: ", contador);
        scanf("%d", &x);

        if  (( x % 15 == 0 )&& ( a <= x ) && ( x <= b )){ // checa se o numero é multiplo por 3 e 5 ao mesmo tempo
            printf("O numero é multiplo de 3 e 5 e esta dentro do intervalo [%d:%d].\n", a,b);
        }
        else{
            printf("Não atende aos criterios.\n ");
        }

    }


    IO_pause("Apertar ENTER para continuar");
    getchar();
}
void method_09 (void){
    
    IO_id("Method_09 - v0.0");
    // definição de varivaeis

    float a        = 0;
    float b        = 0;
    float x        = 0;
    int   n        = 0; 
    int   i        = 0;
    int   contador = 0; 

    a = IO_readfloat("Insira o valor inferior do intevalo: ");
    b = IO_readfloat("Insira o valor superior do intevalo: ");
        
        for (; a >= b;){
            IO_println("\nO valor inferior não pode ser menor que o superior\n");
            a = IO_readfloat("Insira o valor inferior do intevalo: ");
            b = IO_readfloat("Insira o valor superior do intevalo: ");
        }

    n = IO_readint("Quantidade de valores a serem testados: ");
        
    printf("\nIntervalo: [%d:%d] - Numero de testes: %d", a, b ,n);
    printf("\n");
    
        for ( n = n; n > 0; n-- ){

            contador++;
            printf("%d. Insira um valor: ", contador);
            scanf("%f", &x);
            int i = (int)x; // conversão de float para int

    // fim da denifição de variaveis

            if (( i % 2 == 0 ) && ( i < 6)){
                printf("\nO valor inserido pertence ao intervalo [%.2f:%.2f] e é par.\n", a, b);
            }
            else{
                printf("\nO valor não atende aos criterios.\n");
            }
            
        }


    IO_pause("Apertar ENTER para continuar"); getchar();
}
void method_10 (void){
    
    IO_id("Method_10 - v0.0");
    // definição de varivaeis

    float a        = 0;
    float b        = 0;
    float x        = 0;
    float fracao   = 0;
    int   n        = 0; 
    int   i        = 0;
    int   contador = 0; 

    do{ a = IO_readfloat("Insira o valor inferior do intevalo maior que 0 e menor que 1: ");}
    while(!(a > 0 && a < 1));

    do { b = IO_readfloat("Insira o valor superior do intevalo maior que 0 e menor que 1: ");}
    while(!(b > 0 && b < 1));

    n = IO_readint("Quantidade de valores a serem testados: ");

    printf("\nIntervalo: ]%.2f:%.2f[ - Numero de testes: %d", a, b, n);
    printf("\n");

    for ( n ; n > 0 ; n--) // pega o numero de testes (n) e repete ate que ele se iguale a 0
    {
        contador++;
        printf("\n%d. Insira um valor: ", contador);
        scanf("%f", &x);
        int i = (int)x;
        fracao = x - i;

        if ( fracao > a && fracao < b ){
            printf("O valor %.2f, esta dentro do intervalo ]%.2f:%.2f[", fracao, a, b);
        }
        else{
            printf("Não esta dentro do intervalo.");
        }

    }


    IO_pause("Apertar ENTER para continuar");
    getchar();
}
void method_11 (void){

    IO_id("Atividade Extra - 03E1.");

     // definição de variaveis

    int x         = 0;
    int j         = 0;
    int tamanho   = 0;
    
    chars resultado = IO_new_chars(STR_SIZE);
    chars frase     = IO_new_chars(STR_SIZE); // reserva 80 espaços na memoria pra char
    
    printf("Insira uma frase: ");
    fgets(frase, STR_SIZE, stdin); // armazena a frase completa
    frase [ strcspn(frase,"\n") ] = '\0'; // substitui o \n no fim da string por um \0
    tamanho = strlen(frase) -1; // verifica o tamanho da frase

    for ( x = tamanho ; x > 0 ; --x ){

        if (!( // exclui todas letras e numeros
              (frase[x] >= 'A') && (frase[x] <= 'Z') || 
              (frase[x] >= 'a') && (frase[x] <= 'z') || 
              (frase[x] >= '0') && (frase[x] <= '9')
            )){
                resultado[j++] = frase[x]; // reescreve o indice que estiver no parametro dentro de resultado 
              }
    }

    resultado[j] = '\0'; // finaliza a string colocando um /0 na ultima posição de [j]
    printf("%s\n", resultado);
    getchar();

}
void method_12 (void){

    IO_id("Atividade Extra - 03E2.");

     // definição de variaveis

    int x                = 0;
    int tamanho          = 0;
    int somente_simbolos = 1;
    
    chars frase     = IO_new_chars(STR_SIZE); // reserva 80 espaços na memoria pra char
    
    printf("Insira uma frase: ");
    fgets(frase, STR_SIZE, stdin); // armazena a frase completa
    frase [ strcspn(frase,"\n") ] = '\0'; // substitui o \n no fim da string por um \0
    tamanho = strlen(frase) -1; // verifica o tamanho da frase

    for (x = 0; x < tamanho; x++) {
        if (
        (frase[x] >= 'A' && frase[x] <= 'Z') || 
        (frase[x] >= 'a' && frase[x] <= 'z') || 
        (frase[x] >= '0' && frase[x] <= '9')
    ){
        somente_simbolos = 0;
        break;
    } // fim do if
    } // fim do for

    if (somente_simbolos)
        printf("Contem apenas simbolos.\n");
    else
        printf("Contem letras ou numeros.\n");

    printf("\nAperte ENTER para terminar.");
    getchar();

}

// fim dos metodos

int main ( int argc, char* argv [ ] ){

    SetConsoleOutputCP(CP_UTF8); // corrige o unicode do compilador
    SetConsoleCP(CP_UTF8);  // corrige o unicode do compilador

    int x;

    do {

    IO_id      ("\nExercicio - Programa - v0.0");
    IO_println ("=+= Opções =+= \n ");
    IO_println (" 0 - Parar ");
    IO_println (" 1 - Letras maiuculas menores que 'K' em uma string. ");
    IO_println (" 2 - Contagem de letras minusculas maiores que 'k' em uma string. ");
    IO_println (" 3 - Contagem decrescente de letras maiusculas menores que 'k' em uma string. ");
    IO_println (" 4 - Contagem crescente de letras maiusculas e minusculas em uma string. ");
    IO_println (" 5 - Contagem crescente de numeros pares em uma string. ");
    IO_println (" 6 - Contagem crescente de de simbolos e numeros impares em string. ");
    IO_println (" 7 - Contagem de valores multiplos de 5 dentro de um intervalo [a:b]. ");
    IO_println (" 8 - Contagem de valores multiplos de 5 e 3 dentro de um intervalo [a:b]. ");
    IO_println (" 9 - Contagem de valores fracionarios pares de um intervalo [a:b]. ");
    IO_println ("10 - Contagem de valores fracionarios subtraidos pelo valor interio em um intervalo [a:b]. ");
    IO_println ("\n=+= Atividades Extras =+= \n");
    IO_println ("11 - Atividade Extra 01. ");
    IO_println ("12 - Atividade Extra 02. ");

    x = IO_readint("\nEntrar com uma opção: ");

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
            IO_pause ( IO_concat ( "Valor diferente das opcoes [0 - 10] (",
             IO_concat ( IO_toString_d ( x ), ") - Aperte ENTER para continuar." ) ));
    } 
}
    while (x != 0);

    IO_pause ("Apertar ENTER para terminar");
    return(0);
}
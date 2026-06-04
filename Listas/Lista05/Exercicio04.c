/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>


// inicio das funções

bool noIntervalo ( int x, int inferior, int superior )
{
    bool result = false;
    if ( inferior < x && x < superior){
        result = true;
    }
    return (result);
}
bool isLowerCase ( char c){
    return ( c >= 'a' && c <= 'z');}
bool isUpperCase ( char c){
    return ( c >= 'A' && c <= 'Z');
}
bool isDigit     ( int c){
    return ( c >= '0' && c <= '9');
}
bool contadordeCadeia  ( char cadeia[]){
    int contador = 0;
    
    for ( int i = 0; cadeia[i] != '\0'; i++ ){
        
        if ( cadeia[i] > 'k' && 
             cadeia[i] < 'p' ){

            contador++;
        }
    }
    return contador;
}      
bool separadordeLetras ( char cadeia[], char resultado[]){
    
    resultado[0] = '\0';
    char temp[2];

    for ( int i = 0 ; cadeia[i] != '\0'; i++ ){
        if ( cadeia[i] > 'k' && 
             cadeia[i] < 'p' ){
            
            temp[0] = cadeia[i]; // salva o caractere
            temp[1] = '\0'; // transforma em string 
            strcat(resultado, temp); // concatena o resultado
            }
    }

}
bool MinusculaseMaiusculasIntervalo ( char cadeia[], char resultado[]){
    
    resultado[0] = '\0';
    char temp[2];

    for ( int i = 0 ; cadeia[i] != '\0'; i++ ){
        if (( cadeia[i] > 'K' && cadeia[i] < 'P')  ||
           ( cadeia[i] > 'k' && cadeia[i] < 'p' )){
            
            temp[0] = cadeia[i]; // salva o caractere
            temp[1] = '\0'; // transforma em string 
            strcat(resultado, temp); // concatena o resultado
            }
    }
    return resultado;

}
int OddDigitCounter ( char cadeia[]){

   int contador = 0;
   
    for ( int i = 0 ; cadeia[i] != '\0'; i++ ){
        if (cadeia[i] >= '1' && cadeia[i] <= '9'){
            if ((int) cadeia[i] % 2 != 0) {
            contador++;
        } // fim primeiro if
    } // fim segundo if

} // fim for
    return contador;
}
void isNotAlpha ( char cadeia[], char resultado[] ){

    resultado[0] = '\0';
    char temp[2];

    for ( int i = 0 ; cadeia[i] != '\0'; i++ ){
        if (!( isLowerCase(cadeia[i]) || isUpperCase(cadeia[i]) || isDigit(cadeia[i]))){
            
            temp[0] = cadeia[i]; // salva o caractere
            temp[1] = '\0'; // transforma em string 
            strcat(resultado, temp); // concatena o resultado
            } // fim o if 
    } // fim do for

}
void isAlpha ( char cadeia[], char resultado[] ){

    resultado[0] = '\0';
    char temp[2];

    for ( int i = 0 ; cadeia[i] != '\0'; i++ ){
        if (( isLowerCase(cadeia[i]) || isUpperCase(cadeia[i]) || isDigit(cadeia[i]))){
            
            temp[0] = cadeia[i]; // salva o caractere
            temp[1] = '\0'; // transforma em string 
            strcat(resultado, temp); // concatena o resultado
            } // fim o if 
    } // fim do for

}
int AlphaNumericCounter(char cadeia[]) {
    int contador = 0;

    for (int i = 0; cadeia[i] != '\0'; i++) {
        if (isLowerCase(cadeia[i]) || isUpperCase(cadeia[i]) || isDigit(cadeia[i])) {
            contador++;
        }
    }
    return contador;
}
// fim das funções

// inicio dos methods

void method_01 (void){

    // identificação
    IO_id("Method 01 - v0.0");

    double a;
    double b;
    double z;
    int n        = 0;
    int dentro   = 0;
    int fora     = 0;
    int contador = 0; 
    

    a = IO_readdouble("Entre com o valor inferior do intervalo: ");
    b = IO_readdouble("Entre com o valor superior do intervalo: ");
    n = IO_readint  ("Quantidade de valores: ");
    printf("\n");

    printf("Intervalo: [%.2f:%.2f]. Numero de testes: %d\n\n", a, b, n);

    int x = 0;
    while ( n > x )
    {
        contador++;
        printf("%d. Valores: ", contador);
        scanf("%f", &z);

        if (noIntervalo(z, a, b)){
        dentro++;
        }
        else{
        fora++;
        }
        n--;
    }

    IO_printf("\nValores dentro do intervalo: %d", dentro);
    IO_printf("\nValores fora do intervalo: %d", fora);
   
    // encerrar
    IO_pause("Aperte ENTER para terminar."); getchar();
}
void method_02 (void){

    // identificação
    IO_id("Method 02 - v0.0");

    chars palavra = IO_new_chars( STR_SIZE );
    int contador =  0;
    int i        =  0;;


    palavra = IO_readstring("\nEntre com uma sequencia de caracteres: ");
    printf("\n");
    printf("%s\n", palavra);


    
    while (palavra[i] != '\0') {
        if (isLowerCase(palavra[i]) &&
            palavra[i] > 'k' &&
            palavra[i] < 'p') {
            contador++;
            }
            i++;
    } // fim do while

    printf("Letras minusculas no intervalo [k:p]: %d", contador);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_03 (void){

    // identificação
    IO_id("Method 03 - v0.0");

    chars cadeia = IO_new_chars(STR_SIZE);
    cadeia = IO_readstring("Entrar com uma cadeia: ");

    int quantidade = contadordeCadeia(cadeia);
    printf("Letras minusculas: %d\n", quantidade);


    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_04 (void){

    // identificação
    IO_id("Method 04 - v0.0");

    chars cadeia = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    cadeia = IO_readstring("Entre com uma sequencia de caracteres: ");
    separadordeLetras(cadeia, resultado);

    printf("Letras encontradas: %s\n", resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_05 (void){

    // identificação
    IO_id("Method 05 - v0.0");

    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);
    palavra = IO_readstring("Entre com uma sequencia de caracteres: ");

    MinusculaseMaiusculasIntervalo(palavra, resultado);
    
    int contador = strlen(resultado);
    printf("Resultado: %d letras: %s", contador, resultado);
    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_06 (void){

    // identificação
    IO_id("Method 06 - v0.0");

    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);
    palavra = IO_readstring("Entre com uma sequencia de caracteres: ");

    MinusculaseMaiusculasIntervalo(palavra, resultado);
    printf("Letras: %s", resultado);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_07 (void){

    // identificação
    IO_id("Method 07 - v0.0");

    chars palavra = IO_new_chars(STR_SIZE);
    
    palavra = IO_readstring("Entre com uma cadeia de caracteres: ");
    
    int contador = OddDigitCounter(palavra);
    printf("Sua string tem %d numeros impares!", contador);

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_08 (void){

    // identificação
    IO_id("Method 08 - v0.0");
    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    palavra = IO_readstring("Entre com uma sequencia de caracteres: ");

    isNotAlpha(palavra, resultado);
    printf("Os simbolos nao alfanumericos da sua string são: %s", resultado);
    

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_09 (void){

    // identificação
    // identificação
    IO_id("Method 08 - v0.0");
    chars palavra = IO_new_chars(STR_SIZE);
    chars resultado = IO_new_chars(STR_SIZE);

    palavra = IO_readstring("Entre com uma sequencia de caracteres: ");

    isAlpha(palavra, resultado);
    printf("Os simbolos alfanumericos da sua string são: %s", resultado);
    

    // encerrar
    IO_pause("Aperte ENTER para terminar.");
}
void method_10 (void){

    // identificação
    IO_id("Method 10 - v0.0");

    int n = IO_readint("Quantas cadeias voce quer digitar? ");

    chars palavra = IO_new_chars(STR_SIZE);
    int total = 0;

    for (int i = 0; i < n; i++) {
    palavra = IO_readstring("Entre com uma cadeia: ");

    int quantidade = AlphaNumericCounter(palavra);
    printf("Palavra %d - '%s': %d simbolos alfanumericos\n", i+1, palavra, quantidade);

    total += quantidade;
}

    printf("\nTotal acumulado de todas as palavras: %d\n", total);

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

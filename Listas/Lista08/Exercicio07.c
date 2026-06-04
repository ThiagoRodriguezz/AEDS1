/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>

// inicio das funções

    // writeMultiple5 - Grava em um arquivo os multiplos de 5 impares ate certa quantidade.
    //@param filename - Nome do arquivo.
    //@param n - Quantidade de testes.
    void writeMultiple5( chars fileName, int n )
    {
        FILE *arquivo; // variavel
        arquivo = fopen ( fileName, "wt" ); // wt = write text // usa o fileName como parametro para criar 
                                                               // o arquivo com o nome inserido no procedimento
        
        fprintf(arquivo, "Multiplos de 5 impares.\n\n");
        for ( int i = 0; i < n; i++ ){
            fprintf( arquivo, "%d\n", 5 + ( i * 10 )); // funciona nesse caso pois os impares multiplos de 5 sempre somam 10: 5, 15, 25, 35...;
        }
        
        fclose(arquivo);
        
    }
    
    // writeMultiple3 - Grava em um arquivo os multiplos de 3 em ordem decrescente encerrando em 6 conforme certa quantidade.
    // @param fileName - Nome do arquivo.
    // @param n - Quantidade de testes.
    void writeMultiple3( chars fileName, int n )
    {
        FILE *arquivo;
        arquivo = fopen ( fileName, "wt"); // wt = write text
        
        int i         = 0;
        int resultado = 0;
        int contador  = n;

        fprintf(arquivo, "Multiplos de 3 pares em ordem descrescente encerrando em 6.\n\n");
        while ( i < contador )
        {
            resultado = 6 * contador;
            if ( resultado % 2 == 0 ){
                fprintf( arquivo, "%d\n", resultado);
                contador--;
            }
        }
        fclose(arquivo);
    }

    // writePower - Grava em um arquivo a potencia de um numero ate certa quantidade.
    // @param filename - Nome do arquivo.
    // @param n - Quantidade de testes.
    // @param base - Base da potencia.
    void writePower( chars fileName, int n, int base)
    {
        FILE *arquivo;
        arquivo = fopen(fileName, "wt"); // wt = write text

        int resultado = 0;
        int i         = 0;
        
        fprintf(arquivo, "Potencia de %d ate certa quantidade.\n\n", base);
        
        while ( n > i )
        {
            fprintf(arquivo, "%.f\n", pow((double)base, i));
            i++;
        } 

        fclose(arquivo);
    }

    // writeDecreasingExponents - Grava em um arquivo grava uma sequencia de potencia valores decrescentes ate certa quantidade.
    // @param fileName - Nome do arquivo.
    // @param n - Quantidade de testes.
    // @param base - Base da potencia. 
    void writeDecreasingExponents ( chars fileName, int n, int base)
    {
        FILE *arquivo;
        arquivo = fopen(fileName, "wt"); // wt = write text

        int resultado = 0;
        int i         = 1;
        int contador  = n - 1;
        
        fprintf(arquivo, "Sequencia dos inversos decrescente.\n\n", base);
        
        while ( contador >= i )
        {
            fprintf(arquivo, "1/%.f\n", pow((double)base, contador));
            contador--;
        } 
        fprintf(arquivo, "1");

        fclose(arquivo);
    }

    // writeSequencePowers - Grava em um arquivo um numero elevado os impares a partir de 3 ate certa quantidade.
    // @param fileName - Nome do arquivo.
    // @param n - Quantidade de testes.
    // @param base - Base da potencia. 
    void writeSequencePowers ( chars fileName, int n, double base)
    {
        FILE *arquivo; // variavel
        arquivo = fopen(fileName, "wt"); // wt = write text

        double resultado = 0;
        int i         = 1;
        int expo      = 1;

        fprintf(arquivo, "1\n");
        while ( i < n )
        {
            expo = expo + 2;
            resultado = pow(base, expo);
            fprintf(arquivo, "1/%.2lf ^ %d = %.2lf\n", base, expo, resultado);
            i++;
        }
        fclose(arquivo);
    }


    
    void copyText(chars fileOut, chars fileIn)
    {
        FILE* entrada = fopen(fileIn, "rt");
 
        // guarda: encerra se o arquivo de origem nao existir
        if ( entrada == NULL )
        {
            printf("Erro: arquivo '%s' nao encontrado. Execute o Metodo 05 primeiro.\n", fileIn);
            return;
        }
 
        FILE* saida = fopen(fileOut, "wt");
        chars linha = IO_new_chars(STR_SIZE);
 
        strcpy(linha, IO_freadln(entrada));
        while(! feof(entrada))
        {
            IO_fprintln(saida, linha);
            strcpy(linha, IO_freadln(entrada));
        }
 
        fclose(saida);
        fclose(entrada);
    }


    void valores_adicionados(chars fileName, int n)
    {

        FILE* arquivo = fopen(fileName, "at");
        chars palavra = IO_new_chars(STR_SIZE);


        while(n > 0)
        {
            strcpy(palavra, IO_readstring("Insira um valor: "));

            
            IO_fprintln(arquivo, palavra);
            n = n - 1;
        }

        fclose(arquivo);
    }


    // potencias_5 - Grava em um arquivo as potencias de 5 decrescentes encerrando em 1.
    // @param fileName - Nome do arquivo.
    // @param n - Quantidade de valores.
    void potencias_5( chars fileName, int n )
    {
        FILE *arquivo  = fopen(fileName, "wt");
        int controle   = 0;
        int potencia   = 1;
        int expoente   = n - 1;
 
        while ( expoente >= 0 )
        {
            if ( expoente >= 1 )
            {
                // calcular potencia sem pow
                for ( controle = 1; expoente >= controle; controle++ )
                {
                    potencia = potencia * 5;
                }
                fprintf(arquivo, "%d/%d\n", 1, potencia);
                potencia = 1; // resetar para proxima iteracao
                expoente--;
            }
            else
            {
                // ultimo elemento sempre e' 1
                fprintf(arquivo, "%d\n", 1);
                expoente--;
            }
        }
 
        fclose(arquivo);
    }
 
    // fibonacci - Calcula recursivamente um numero da sequencia de Fibonacci.
    // @param n - Posicao na sequencia.
    int fibonacci( int n )
    {
        if ( n == 0 ) return 0;
        else if ( n == 1 ) return 1;
        else return ( fibonacci(n - 1) + fibonacci(n - 2) );
    }
 
    // fibonacci_par - Grava em arquivo os numeros pares da sequencia de Fibonacci.
    // @param fileName - Nome do arquivo.
    // @param n - Quantidade de valores pares.
    void fibonacci_par( chars fileName, int n )
    {
        FILE *arquivo = fopen(fileName, "wt");
        int temp      = 0;
        int num       = 1; // exclui o fibonacci de zero
        int controle  = 0;
 
        while ( n > controle )
        {
            temp = fibonacci(num);
 
            if ( temp % 2 == 0 )
            {
                fprintf(arquivo, "%d\n", temp);
                controle++;
            }
 
            num++;
        }
 
        fclose(arquivo);
    }
 
    // maiusculas - Conta letras maiusculas em uma frase gravada em arquivo
    //              e adiciona o total ao final do mesmo arquivo.
    // @param fileName - Nome do arquivo.
    void maiusculas( chars fileName )
    {
        FILE *arquivoLeitura = fopen(fileName, "rt");
        char  linha[256];
        int   contador = 0;
        int   i        = 0;
 
        if ( fgets(linha, 255, arquivoLeitura) != NULL )
        {
            while ( linha[i] != '\0' )
            {
                if ( linha[i] >= 'A' && linha[i] <= 'Z' )
                {
                    contador++;
                }
                i++;
            }
        }
 
        fclose(arquivoLeitura);
 
        FILE *arquivoAdicionar = fopen(fileName, "at");
        fprintf(arquivoAdicionar, "%d", contador);
        fclose(arquivoAdicionar);
    }
 
    // digitos - Conta digitos maiores ou iguais a 3 em uma frase gravada em arquivo
    //           e adiciona o total ao final do mesmo arquivo.
    // @param fileName - Nome do arquivo.
    void digitos( chars fileName )
    {
        FILE *arquivoLeitura = fopen(fileName, "rt");
        char  linha[256];
        int   contador = 0;
        int   i        = 0;
 
        if ( fgets(linha, 255, arquivoLeitura) != NULL )
        {
            while ( linha[i] != '\0' )
            {
                if ( linha[i] >= '3' && linha[i] <= '9' )
                {
                    contador++;
                }
                i++;
            }
        }
 
        fclose(arquivoLeitura);
 
        FILE *arquivoAdicionar = fopen(fileName, "at");
        fprintf(arquivoAdicionar, "%d", contador);
        fclose(arquivoAdicionar);
    }
// fim das funções

// inicio dos methods

void method_01 (void){

     
    IO_id("Method 01 - v0.0");

    int x = 0;
    printf("Entre a quantidade de testes: ");
    scanf("%d", &x);

    writeMultiple5("Multiplos5.txt", x);

     
    IO_pause("Aperte ENTER para terminar.");
}
void method_02 (void){

     
    IO_id("Method 02 - v0.0");

    int x = 0;
    printf("Entre a quantidade de testes: ");
    scanf("%d", &x);

    writeMultiple3("Multiplos3.txt", x);
     
    IO_pause("Aperte ENTER para terminar.");
}
void method_03 (void){

     
    IO_id("Method 03 - v0.0");

    int x = 0;
    printf("Entre a quantidade de testes: ");
    scanf("%d", &x);

    writePower("Potencia.txt", x, 3);

    IO_pause("Aperte ENTER para terminar.");
}
void method_04 (void){

     
    IO_id("Method 04 - v0.0");

    int x = 0;
    printf("Entre a quantidade de testes: ");
    scanf("%d", &x);

    writeDecreasingExponents("PotenciaInversa.txt", x, 5);
     
    IO_pause("Aperte ENTER para terminar.");
}
void method_05 (void){

     
    IO_id("Method 05 - v0.0");

    int    n = 0;
    double x = 0;

    printf("Entre a quantidade de testes: ");
    scanf("%d", &n);
    printf("Entre com um valor real: ");
    scanf("%lf", &x);

    writeSequencePowers("SequenciaPotencia.txt", n, x);

    IO_pause("Aperte ENTER para terminar.");
}
void method_06 (void){

    int n = 0; 
    IO_id("Method 06 - v0.0");


    printf("Insira uma quantidade de valores para serem inseridos: ");
    scanf("%d", &n);

    //executar funcao
    copyText("RESULTADO06.TXT", "SequenciaPotencia.txt");
    valores_adicionados("RESULTADO06.TXT", n);


     
    IO_pause("Aperte ENTER para terminar.");
}
void method_07 (void){

     
    IO_id("Method 07 - v0.0");


    int n        = 0;
    double soma  = 0;

    int numerador   = 0;
    int denominador = 0;

    //identificar
    IO_id("\nMethod 0717");

    //ler do teclado
    n = IO_readint("Insira uma quantidade: ");

    potencias_5("RESULTADO07.TXT", n);

    FILE* arquivo = fopen("RESULTADO07.TXT", "rt");


    while(fscanf(arquivo, "%d/%d", &numerador, &denominador) == 2)
    {

        soma = soma + (double)numerador/(double)denominador;
    }

    fclose(arquivo);

    arquivo = fopen("RESULTADO07.TXT", "at");
    IO_fprintf(arquivo, "\n%lf", soma + 1.0);

    fclose(arquivo);
     
    IO_pause("Aperte ENTER para terminar.");
}

void method_08 (void){
 
     
    IO_id("Method 08 - v0.0");
 
    int n = 0;
 
    printf("Entre a quantidade de testes: ");
    scanf("%d", &n);
 
    //executar funcao: grava n numeros pares da sequencia de Fibonacci
    fibonacci_par("Fibonacci.txt", n);
 
    IO_pause("Aperte ENTER para terminar.");
}

void method_09 (void){
 
     
    IO_id("Method 09 - v0.0");
 
    char caracteres[256];
 
    //abrir arquivo para gravar a frase do usuario
    FILE *arquivo = fopen("RESULTADO09.TXT", "wt");
 
    printf("Insira uma cadeia de caracteres: ");
    fgets(caracteres, 255, stdin);
    fprintf(arquivo, "%s", caracteres);
 
    fclose(arquivo);
 
    //executar funcao: conta maiusculas e adiciona o total ao final do arquivo
    maiusculas("RESULTADO09.TXT");
 
    IO_pause("Aperte ENTER para terminar.");
}

void method_10 (void){
 
     
    IO_id("Method 10 - v0.0");
 
    char caracteres[256];
 
    //abrir arquivo para gravar a frase do usuario
    FILE *arquivo = fopen("RESULTADO10.TXT", "wt");
 
    printf("Insira uma cadeia de caracteres: ");
    fgets(caracteres, 255, stdin);
    fprintf(arquivo, "%s", caracteres);
 
    fclose(arquivo);
 
    //executar funcao: conta digitos >= 3 e adiciona o total ao final do arquivo
    digitos("RESULTADO10.TXT");
 
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

/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include <stdbool.h>
#include <windows.h>
// FUNCOES AUXILIARES
 
void method_01(void){
    IO_id("Procedimento 0211 - Programa - v0.0");

    int x;
    x = IO_readint("Insira um valor inteiro: ");

    if (x % 2 == 0) {
        IO_printf("O valor (%d) é par", x);
        if (x < 0)
            IO_printf(" e negativo");
        else if (x > 0)
            IO_printf(" e positivo");
        else
            IO_printf(" (zero)");
    } else {
        IO_printf("O valor (%d) é impar", x);
        if (x < 0)
            IO_printf(" e negativo");
        else
            IO_printf(" e positivo");
    }

    IO_pause("Apertar ENTER para terminar.");
}
void method_02(void){
    IO_id("Procedimento 0212 - Programa - v0.0");

    int x;
    x = IO_readint("Insira um valor inteiro: ");

    if (x % 2 == 0 && x > -12)
        IO_printf("O valor (%d) é par e maior que -12\n", x);
    else
        IO_printf("O valor (%d) nao é par e maior que -12\n", x);

    if (x % 2 != 0 && x < 25)
        IO_printf("O valor (%d) é impar e menor que 25\n", x);
    else
        IO_printf("O valor (%d) nao é impar e menor que 25\n", x);

    IO_pause("Apertar ENTER para terminar.");
}
void method_03(void){

    // identificar
    IO_id("Procedimento 0213 - Programa - v0.0");

    int x;
    x = IO_readint("Insira um valor inteiro: ");
    if ( x > 15 && x < 54 ){
      IO_printf("O valor (%d) pertence ao intervalo de (15:54).", x);
    }
    else{
      IO_printf("O valor (%d) não pertence ao intervalo de (15:54).",x );
    }
    // encerrar 
    IO_pause("Apertar ENTER para terminar.");
} 
void method_04(void){

     // identificar
    IO_id("Procedimento 0214 - Programa - v0.0");

    int x;
    x = IO_readint("Insira um valor inteiro: ");
    if (x >= 15 && x <= 54){
      IO_printf("O valor (%d) pertence ao intervalo de [15:54].", x);
    }
    else{
      IO_printf("O valor (%d) não pertence ao intervalo de [15:54].",x );
    }
    // encerrar 
    IO_pause("Apertar ENTER para terminar.");
} 
void method_05(void){

   // identificar
    IO_id("Procedimento 0215 - Programa - v0.0");

    int x = IO_readint("Insira um valor inteiro:");

    bool emA = (x >= 12 && x <= 24);
    bool emB = (x > 20 && x < 50);

    if (emA && emB)
    {
      IO_printf("Pertence a interseção");
      // interseção
    }
    else if (emA || emB)
    {
      IO_printf("Pertence somente a um deles");
      // somente um deles
    }
    else
    {
      IO_printf("Não pertence a A nem B");
      // nenhum
    }

    // encerrar 
    IO_pause("Apertar ENTER para terminar.");
} 
void method_06(void){

    // identificar
    IO_id("Procedimento 0216 - Programa - v0.0");
    int a, b;
    printf("Insira dois numeros inteiros ( Separe-os por virgula ): ");
    scanf("%d, %d", &a, &b);
    getchar();

    if ( a % 2 != 0 && b % 2 == 0 ){
      IO_printf("O numero %d é impar e o %d é par", a ,b);
    }
    else {
      IO_printf("Os valores não estao na ordem de impar ou par");
    }
    
    IO_pause("Apertar ENTER para terminar.");
} 
void method_07(void){
    IO_id("Procedimento 0217 - Programa - v0.0");

    int a, b;
    printf("Insira dois numeros inteiros ( Separe-os por virgula ): ");
    scanf("%d, %d", &a, &b);
    getchar();

    if (a % 2 != 0 && a > 0)
        IO_printf("O primeiro valor (%d) é impar e positivo\n", a);
    else
        IO_printf("O primeiro valor (%d) nao é impar e positivo\n", a);

    if (b % 2 == 0 && b < 0)
        IO_printf("O segundo valor (%d) é par e negativo\n", b);
    else
        IO_printf("O segundo valor (%d) nao é par e negativo\n", b);

    IO_pause("Apertar ENTER para terminar.");
} 
void method_08(void){

    // identificar
    IO_id("Procedimento 0218 - Programa - v0.0");

    float a, b, metadeB;
    printf("Insira dois valores reais ( Separe-os por virgula Ex.: 0.5, 1.5 : ");
    scanf("%f, %f", &a, &b);
    getchar();

    metadeB = b / 2;

    if (a == metadeB){
      IO_printf("%.2f é igual a %.2f", a , metadeB);
    }
    else if ( a > metadeB ){
      IO_printf("%.2f é maior que a metade de %.2f (%.2f) ", a , b, metadeB);
    }
    else {
      IO_printf("%.2f é menor que a metade de %.2f (%.2f) ", a , b, metadeB);
    }


    // encerrar 
    IO_pause("Apertar ENTER para terminar.");
} 
void method_09(void){

    // identificar
    IO_id("Procedimento 0219 - Programa - v0.0");

    float a, b, c;
    printf("Insira três valores reais ( Separe-os por virgula! Ex.: 0.75, 0.5, 1.8 ): ");
    scanf("%f, %f, %f", &a, &b, &c);
    getchar();
    
    if ( a != c){

    if (( a < b && b < c) || (c < b && b < a)){
      IO_printf("O valor %.2f esta entre A e C", b);
    }
    else {
      IO_printf("O valor %.2f não esta entre A e C", b);
    }
  }
  else{
      IO_printf("Os valores de A e C sao iguais");
    }

    // encerrar 
    IO_pause("Apertar ENTER para terminar.");
} 
void method_10(void){

    // identificar
    IO_id("Procedimento 0220 - Programa - v0.0");

    float a, b, c;
    printf("Insira três valores reais ( Separe-os por virgula! Ex.: 0.75, 0.5, 1.8 ): ");
    scanf("%f, %f, %f", &a, &b, &c);
    getchar();
    
    if (a != b && b != c && a != c ){

    if (( a < b && b < c) || (c < b && b < a)){
      IO_printf("O valor %.2f esta entre A e C", b);
    }
    else {
      IO_printf("O valor %.2f não esta entre A e C", b);
    }
  }
  else{
      IO_printf("Nem todos os valores são diferentes entre si");
    }

    // encerrar 
    IO_pause("Apertar ENTER para terminar.");
} 

// FIM DOS METODOS

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // corrigir a codificação de caracteres


  // definir dados / resultados

  int opcao = 0;

  // identificar
  printf("\n%s\n", "Exemplo0200 - Programa = v0.0");
  printf("%s\n", "Autor: Thiago de Araujo Rodrigues");
  printf("\n");

  // açoes

  // repetir
  do
  {
    // mostrar as opcoes
    printf("\n%s\n", "Opcoes:");
    printf("%s\n", "0 - Terminar");
    printf("%s\n", "1 - Metodo 01");
    printf("%s\n", "2 - Metodo 02");
    printf("%s\n", "3 - Metodo 03");
    printf("%s\n", "4 - Metodo 04");
    printf("%s\n", "5 - Metodo 05");
    printf("%s\n", "6 - Metodo 06");
    printf("%s\n", "7 - Metodo 07");
    printf("%s\n", "8 - Metodo 08");
    printf("%s\n", "9 - Metodo 09");
    printf("%s\n", "10 - Metodo 10");
    printf("\n");

    printf("\n%s", "Opcao = "); // ler a opcao do teclado
    scanf("%d", &opcao);
    getchar();

    // mostrar opcao lida
    printf("\n%s%d\n", "Opcao: ", opcao);

    // escolher acao dependente

    switch (opcao) // executar metodos
    {
    case 0:
      break;

    case 1:
      method_01();
      break;
    case 2:
      method_02();
      break;
    case 3:
      method_03();
      break;
    case 4:
      method_04();
      break;
    case 5:
      method_05();
      break;
    case 6:
      method_06();
      break;
    case 7:
      method_07();
      break;
    case 8:
      method_08();
      break;
    case 9:
      method_09();
      break;
    case 10:
      method_10();
      break;

    default:
      printf("\nERRO: Opcao invalida.\n"); // fazer nada
      break;
    }
  } while (opcao != 0);

  // encerrar
  printf("\nApertar ENTER para terminar.");
  getchar();
  return (0);
}
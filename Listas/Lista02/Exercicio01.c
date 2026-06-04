#include "io.h"
#include <windows.h>
#include <math.h>
#define M_PI 3.14159265358979323846

// inicio das funções
// fim das funções

// inicio dos methods

void method_01(void)
{

    IO_id("Method 01 - v0.0");

    int lado;
    printf("\n%s\n", "Exercicio0111 - Calculo do Area do Quadrado  - Programa = v0.0");

    printf("%s", "Digite um valor inteiro do lado: ");
    scanf("%i", &lado);

    int dobrolado = 2 * lado;
    int area = dobrolado * dobrolado;

    printf("\n%s%d\n", "O valor do dobro da area do quadrado é: ", area);
    IO_pause("Apertar ENTER para terminar.");
}
void method_02(void)
{

    IO_id("Method 02 - v0.0");

    float lado;

    printf("\n%s\n", "Exercicio0112 - Calculo 1/4 da Area original do Quadrado  - Programa = v0.0");

    printf("%s", "Digite o valor do lado: ");
    scanf("%f", &lado);

    float lado2 = (lado / 4);
    float peri = lado2 * 4;
    float area = lado2 * lado2;

    printf("\nArea do quadrado com 1/4 do lado original é: %.2f e seu perimetro é: %.2f", area, peri);

    IO_pause("Aperte ENTER para terminar.");
}
void method_03(void)
{

    IO_id("Method 03 - v0.0");

    int h;
    int l;

    printf("\n%s\n", "Exercicio0113 - Calculo do Area do Retangulo  - Programa = v0.0");
    printf("Digite a base: ");
    scanf("%i", &h);
    printf("Digite a altura: ");
    scanf("%i", &l);

    int area = (h * 4) * (l * 4);
    printf("\n%s%d\n", "O valor do quadruplo da area original do retangulo é: ", area);

    IO_pause("Aperte ENTER para terminar.");
}
void method_04(void)
{

    IO_id("Method 04 - v0.0");

    printf("\n%s\n", "Exercicio0114 - Calculo da Area de 1/3 do Retangulo  - Programa = v0.0");

    float l;
    float h;
    float area;
    float peri;

    printf("Digite a base: ");
    scanf("%f", &h);
    printf("Digite a altura: ");
    scanf("%f", &l);

    area = (h / 3) * (l / 3);
    peri = 2 * ((h / 3) + (l / 3));

    printf("A area de 1/3 do retagulo original é: %.2f e seu perimetro é: %.2f", area, peri);

    IO_pause("Aperte ENTER para terminar.");
}
void method_05(void)
{

    IO_id("Method 05 - v0.0");

    float b, h, area;

    printf("\n%s\n", "Exercicio0114 - Calculo da Area de um Triangulo com 3x a altura inicial  - Programa = v0.0");
    printf("Digite a base: ");
    scanf("%f", &b);
    printf("Digite a altura: ");
    scanf("%f", &h);

    area = ((b * (h * 3)) / 2);
    printf("A area do triangulo com 3x a altura original é: %.2f", area);

    IO_pause("Aperte ENTER para terminar.");
}
void method_06(void)
{

    IO_id("Method 06 - v0.0");

    double l1, l2, h, area, peri;

    printf("\n%s\n", "Exercicio0115 - Calculo de 3/5 da area original de um Triangulo Equilatero  - Programa = v0.0");
    printf("Digite um valor real (lado): ");
    scanf("%lf", &l1);

    l2 = l1 * (3.0 / 5.0);
    h = (sqrt(3) / 2) * l2;
    area = (l2 * h) / 2;
    peri = 3 * l2;

    printf("O altura do triangulo é: %.2f, sua area é: %.2f e seu perimetro é: %.2f!", h, area, peri);

    IO_pause("Aperte ENTER para terminar.");
}
void method_07(void)
{

    IO_id("Method 07 - v0.0");

    double l, lado, volume;

    // identificar
    printf("Exercicio0117 - Calculo de 1/6 do volume solido do valor original- Programa = v0.0\n");

    printf("\nInsira o tamanho do lado: ");
    scanf("%lf", &l);

    lado = (l / 6.0);
    volume = pow(lado, 3);

    printf("\nO volume do solido com 1/6 do valor do lado original é: %.2f", volume);

    IO_pause("Aperte ENTER para terminar.");
}
void method_08(void)
{

    IO_id("Method 08 - v0.0");

    double l, w, h, volume;
    // identificar
    printf("Exercicio0118 - Calculo do volume do solido com 5x o valor inicial - Programa = v0.0\n");

    printf("\nInsira o comprimento: ");
    scanf("%lf", &l);
    printf("Insira a largura: ");
    scanf("%lf", &w);
    printf("Insira a altura: ");
    scanf("%lf", &h);

    volume = (l * 5) * (w * 5) * (h * 5);
    printf("\nO valor do volume solido do paralelepípedo é: %.2f", volume);

    IO_pause("Aperte ENTER para terminar.");
}
void method_09(void)
{

    IO_id("Method 09 - v0.0");

    double r, area;
    // identificar
    printf("Exercicio0119 - Calculo de semicirculo com 10x o valor do raio - Programa = v0.0");
    printf("\nInsira o raio: ");
    scanf("%lf", &r);

    r = r * 10;
    area = (((r * r) * M_PI) / 2);

    printf("\n%s%.2f\n", "A area do semicirculo com 10x o raio original é: ", area);

    IO_pause("Aperte ENTER para terminar.");
}
void method_10(void)
{

    IO_id("Method 10 - v0.0");

    double r, volume;
    printf("Exercicio0120 -  - Programa = v0.0");
    printf("\nInsira o raio: ");
    scanf("%lf", &r);

    r = (r * 5.0) / 8.0;
    volume = ((4.0 * M_PI * pow(r, 3)) / 3.0);

    printf("\n%s%.2f\n", "O volume da esfera com 5/8 do raio original é: ", volume);

    IO_pause("Aperte ENTER para terminar.");
}

// fim dos methods

int main(int argc, char *argv[])
{

    SetConsoleOutputCP(CP_UTF8); // corrige o unicode do compilador
    SetConsoleCP(CP_UTF8);       // corrige o unicode do compilador

    int x;

    do
    {

        IO_id("\nExemplo0300 - Programa - v0.0");
        IO_println("=+= Opções =+= \n ");
        IO_println(" 0 - Parar \n");

        printf("%s%s\n", " 1 - Método 01      ", " 6 - Método 06");
        printf("%s%s\n", " 2 - Método 02      ", " 7 - Método 07");
        printf("%s%s\n", " 3 - Método 03      ", " 8 - Método 08");
        printf("%s%s\n", " 4 - Método 04      ", " 9 - Método 09");
        printf("%s%s\n", " 5 - Método 05      ", "10 - Método 10");

        IO_println("");

        x = IO_readint("Entrar com uma opção: ");

        switch (x)
        {
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
            IO_pause(IO_concat("Valor diferente das opcoes [0,1] (",
                               IO_concat(IO_toString_d(x), ")")));
        }
    } while (x != 0);

    IO_pause("Apertar ENTER para terminar");
    return (0);
}

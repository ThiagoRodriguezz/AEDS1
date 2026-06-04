/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <math.h>
#include <string.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// FUNCOES AUXILIARES

double sqr(double x)
{
  return (x * x);
}
double lg(double x)
{
  return (log10(x) / log10(2.0));
}
int max(int x, int y)
{
  int z = 0;
  if (x > y)
    z = x; // {} is optional, but recommended
  else
    z = y; // {} is optional, but recommended
  return (z);
}
int min(int x, int y)
{
  int z = x;
  if (y < x)
    z = y; // {} is optional, but recommended
  return (z);
}

void print_header(const char *message)
{
  // mostrar mensagem com formato
  printf("%s\n", message);
}
void print_footer(const char *message)
{
  // mostrar mensagem com formato
  printf("\n%s\n", message);
  getchar();
}

void print_array(int n, int *v)
{
  for (int x = 0; x < n; x = x + 1)
  {
    printf("%d ", v[x]);
  }
  printf("\n");
}
void scan_array(int n, int *v)
{
  for (int x = 0; x < n; x = x + 1)
  {
    scanf("%d", &v[x]);
    getchar();
  }
  printf("\n");
}

void print_matrix(int m, int n, int v[][n])
{
  for (int x = 0; x < m; x = x + 1)
  {
    for (int y = 0; y < n; y = y + 1)
    {
      printf("%d ", v[x][y]);
    }
    printf("\n");
  }
}
void scan_matrix(int m, int n, int v[][n])
{
  for (int x = 0; x < m; x = x + 1)
  {
    for (int y = 0; y < n; y = y + 1)
    {
      scanf("%d", &v[x][y]);
      getchar();
    }
    printf("\n");
  }
  printf("\n");
}

typedef struct s_array
{
  int n;
  int *data;
} Array;

void print_Array_1(Array v)
{
  for (int x = 0; x < v.n; x = x + 1)
  {
    printf("%d ", v.data[x]);
  }
  printf("\n");
}
void print_Array_2(Array *v)
{
  for (int x = 0; x < v->n; x = x + 1) // com ->
  {
    printf("%d ", v->data[x]);
  } // com ->
  printf("\n");
}

typedef struct s_matrix // descritor do tipo
{
  int rows;
  int columns;
  int **data;
} Matrix;

// definir enumeracao global (constantes em sequencia)
enum Semana
{
  Domingo,
  Segunda,
  Terca,
  Quarta,
  Quinta,
  Sexta,
  Sabado
};
// definir enumeracao como novo tipo global
typedef enum s_Semana // descritor
{
  domingo,
  segunda,
  terca,
  quarta,
  quinta,
  sexta,
  sabado
} Dias_da_Semana; // nome


// FIM FUNCOES AUXILIARES

// COMEÇO DOS METODOS

void method_01(void)
{

  // mostrar mensagem com formato
  printf("%s\n", "999999_AED1");

  // encerrar
  printf("\nApertar ENTER para continuar.\n");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1
Apertar ENTER para terminar.

*/


} // fim do metodo 01
void method_02(void)
{
  // definir dados
  char x = 'A';   // caractere 'A' (#65)
  int y = 5;      // inteiro
  double z = 1.2; // real

  // outros dados
  bool status = false;   // logico
  int contador = 0;      // inteiro
  float valor_1 = 0.00f; // real de precisao simples
  double valor_2 = 0.00; // real de precisao dupla
  char simbolo = '0';    // caractere zero (#48)

  // iniciar
  printf("%s\n", "999999_AED1");

  printf("\nConversoes entre tipos\n");
  // conformar tipos (type casting)
  y = (int)z; // truncar para parte inteira
  printf("z = %lf\t y = %d\n", z, y);
  y = (int)x; // obter codigo do simbolo
  printf("x = %c \t y = %d\n", x, y);
  y = x; // conformacao implicita
  printf("x = %c \t y = %d\n", x, y);
  printf("\n"); // mudar de linha

  x = (char)(32 + y); // obter simbolo a partir do codigo
  printf("y = %d \t x = %c\n", (32 + y), x);
  x = (char)(48 + (int)z);
  printf("z = %lf\t x = %c\n", z, x);
  printf("\n");

  z = z - (int)z; // isolar parte fracionaria
  printf("z = %lf\n", z);
  z = (double)x; // conformacao explicita
  printf("z = %lf\t x = %c\n", z, x);
  z = 1.0 * x; // conformacao implicita
  printf("z = %lf\t x = %c\n", z, x);
  printf("\n");

  printf("\nOperacoes\n");
  z = x / 2; // metade inteira
  printf("z = %lf\n", z);
  z = (double)(x / 2); // metade real
  printf("z = %lf\n", z);
  z = (double)x / 2; // numerador   real
  printf("z = %lf\n", z);
  z = x / (double)2; // denominador real
  printf("z = %lf\n", z);
  z = (double)x / (double)2; // reais
  printf("z = %lf\n", z);
  printf("\n");

  // mostrar valores com formatos
  printf("status  : %d \n", status);
  printf("contador: %d \n", contador);
  printf("valor_1 : %f \n", valor_1);
  printf("valor_2 : %lf\n", valor_2);
  printf("simbolo : %c \n", simbolo);
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
1. Teste simples
999999_AED1

Conversoes
z = 1.200000     y = 1
x = A    y = 65
x = A    y = 65

y = 97   x = a
z = 1.200000     x = 1

z = 0.200000
z = 49.000000    x = 1
z = 49.000000    x = 1

Operacoes
z = 24.000000
z = 24.000000
z = 24.500000
z = 24.500000
z = 24.500000

status  : 0
contador: 0
valor_1 : 0.000000
valor_2 : 0.000000
simbolo : 0

Apertar ENTER para terminar.

*/


}
void method_03(void)
{
  bool p = true;
  bool q = false;
  bool r = false;

  char a = 'A';
  char b = 'a';
  int x = 5;
  int y = 7;

  // mostrar mensagem com formato
  printf("%s\n", "999999_AED1");

  printf("\nDados:\n");
  printf("     p = %d\n", p);
  printf("     q = %d\n", q);
  printf("\n");

  printf("\nNegacao\n");
  r = !p; // NOT - logical negation
  printf(" !   p = %d\n", r);
  r = !q; // NOT - logical complement
  printf(" !   q = %d\n", r);
  r = not p; // NOT - logical negation
  printf("not  p = %d\n", r);
  printf("\n");

  printf("\nConjuncao\n");
  printf("0 && 0 = %d\n", (0 && 0));
  printf("0 && 1 = %d\n", (0 && 1));
  printf("1 && 0 = %d\n", (1 && 0));
  printf("1 && 1 = %d\n", (1 && 1));
  printf("\n");

  printf("\nDisjuncao\n");
  printf("0 || 0 = %d\n", (0 || 0));
  printf("0 || 1 = %d\n", (0 || 1));
  printf("1 || 0 = %d\n", (1 || 0));
  printf("1 || 1 = %d\n", (1 || 1));
  printf("\n");

  printf("\nDisjuncao exclusiva\n");
  printf("0 ^  0 = %d\n", (0 ^ 0));
  printf("0 ^  1 = %d\n", (0 ^ 1));
  printf("1 ^  0 = %d\n", (1 ^ 0));
  printf("1 ^  1 = %d\n", (1 ^ 1));
  printf("\n");

  printf("\nOperacoes logicas\n");
  r = p && q; // AND - logical conjunction
  printf("p &&  q = %d\n", r);
  r = p and q; // AND - logical conjunction
  printf("p and q = %d\n", r);
  r = p || q; // OR  - logical disjunction
  printf("p ||  q = %d\n", r);
  r = p or q; // AND - logical conjunction
  printf("p or  q = %d\n", r);
  printf("\n");

  r = p ^ q; // XOR - logical exclusive disjunction
  printf("p  ^  q = %d\n", r);
  r = p xor q; // XOR - logical exclusive disjunction
  printf("p xor q = %d\n", r);
  r = p ^ p; // XOR - logical exclusive disjunction
  printf("p  ^  p = %d\n", r);
  r = p xor p; // XOR - logical exclusive disjunction
  printf("p xor p = %d\n", r);
  printf("\n");

  printf("\nComparacoes\n");
  printf("   (%c==%c) = %d\n", a, a, (a == a));
  printf("   (%c!=%c) = %d\n", a, a, (a != a));
  printf("\n");

  r = !(a == a); // NOT - logical negation
  printf(" ! (%c==%c) = %d\n", a, a, r);
  r = !(a != a); // NOT - logical complement
  printf(" ! (%c!=%c) = %d\n", a, a, r);
  r = not(a == a); // NOT - logical negation
  printf("not(%c==%c) = %d\n", a, a, r);
  printf("\n");

  r = (x < y) && (x != 0); // AND - logical conjunction
  printf("(%d<%d)  && (%d!=0)= %d\n", x, y, x, r);
  r = (x < y) and(x != 0); // AND - logical conjunction
  printf("(%d<%d) and (%d!=0)= %d\n", x, y, x, r);
  r = (x >= y) || (x != 0); // OR  - logical disjunction
  printf("(%d>=%d) || (%d!=0)= %d\n", x, y, x, r);
  r = (x >= y) or(x != 0); // OR  - logical disjunction
  printf("(%d<%d)  or (%d!=0)= %d\n", x, y, x, r);
  r = (x <= y) && (x > 0); // AND - logical conjunction
  printf("(%d<%d)  && (%d> 0)= %d\n", x, y, x, r);
  r = (x <= y) and(x > 0); // AND - logical conjunction
  printf("(%d<%d) and (%d> 0)= %d\n", x, y, x, r);
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados:
     p = 1
     q = 0


Negacao
 !   p = 0
 !   q = 1
not  p = 0


Conjuncao
0 && 0 = 0
0 && 1 = 0
1 && 0 = 0
1 && 1 = 1


Disjuncao
0 || 0 = 0
0 || 1 = 1
1 || 0 = 1
1 || 1 = 1


Disjuncao exclusiva
0 ^  0 = 0
0 ^  1 = 1
1 ^  0 = 1
1 ^  1 = 0


Operacoes logicas
p &&  q = 0
p and q = 0
p ||  q = 1
p or  q = 1

p  ^  q = 1
p xor q = 1
p  ^  p = 0
p xor p = 0

Comparacoes
   (A==A) = 1
   (A!=A) = 0

 ! (A==A) = 0
 ! (A!=A) = 1
not(A==A) = 0

(5<7)  && (5!=0)= 1
(5<7) and (5!=0)= 1
(5>=7) || (5!=0)= 1
(5<7)  or (5!=0)= 1
(5<7)  && (5> 0)= 1
(5<7) and (5> 0)= 1

Apertar ENTER para terminar.

*/

}
void method_04(void)
{
  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  int opcao = 0;
  int valor = 0;

  // entrar dado
  printf("\nEntrar com valor: ");
  scanf("%d", &valor);
  getchar(); // ler e limpar

  // testar se valor negativo
  if (valor < 0)
  {
    printf("%d -> negativo\n", valor);
  }

  // testar se valor menor que 100
  if (valor < 100)
  {
    printf("%d menor que 100\n", valor);
  }
  else
  {
    // testar se igual a 100
    if (valor == 100)
    {
      printf("%d igual a 100\n", valor);
    }
    else
    {
      printf("%d diferente de 100\n", valor);
    }
  }
  printf("\n");

  // entrar com opcao

  printf("\n%s", "Opcao [0,1,2]: ");
  scanf("%d", &opcao);
  getchar();

  // escolher acao dependente da opcao
  switch (opcao)
  {
  case 0:
    printf("%s\n", "Opcao 0 escolhida");
    break;

  case 1:
    printf("%s\n", "Opcao 1 escolhida");
    break;

  case 2:
    printf("%s\n", "Opcao 2 escolhida");
    break;

  default: // caso for outra opcao
    printf("%s\n", "Outra opcao escolhida");
    break;
  }
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste com -5
999999_AED1

Entrar com valor: -5
-5 -> negativo
-5 menor que 100
Apertar ENTER para terminar.

2. Teste com 100
999999_AED1

Entrar com valor: 100
100 igual a cem
Apertar ENTER para terminar.

3. Teste com 105
999999_AED1

Entrar com valor: 105
105 diferente de 100

1. Teste com 1
999999_AED1

Opcao: 1
Opcao 1 escolhida
Apertar ENTER para terminar.

2. Teste com -1
999999_AED1

Opcao: -1
Outra opcao escolhida

Apertar ENTER para terminar.

*/

}
void method_05(void)
{
  // mostrar mensagem
  printf("%s\n", "999999_AED1");
  int opcao = 0;

  // repetir ate' escolher zero e parar
  do
  {
    // entrar com a opcao
    printf("\n%s", "Opcao: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 0:
      printf("%s\n", "Opcao 0 escolhida");
      break;

    case 1:
      printf("%s\n", "Opcao 1 escolhida");
      break;

    case 2:
      printf("%s\n", "Opcao 2 escolhida");
      break;

    default:
      printf("%s\n", "Outra opcao escolhida");
      break;
    }
  } while (opcao != 0);

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Opcao: 1
Opcao 1 escolhida

Opcao: 2
Opcao 2 escolhida

Opcao: 0
Opcao 0 escolhida
Apertar ENTER para terminar.

*/

}
void method_06(void)
{
  // definir dado
  int x = 0;

  // mostrar mensagem com formato
  printf("%s\n", "999999_AED1");

  // repetir enquanto condicao verdadeira
  printf("\n%s\n", "Repeticao crescente");
  while (x < 5)
  {
    // mostrar valor atual em linha separada
    printf("%d\n", x);
    // passar ao seguinte (em ordem crescente)
    x = x + 1;
  }

  // repetir enquanto condicao verdadeira
  printf("\n%s\n", "Repeticao decrescente");
  while (x > 0)
  {
    // mostrar valor atual na mesma linha
    printf("%d ", x);
    // passar ao seguinte (em ordem decrescente)
    x = x - 1;
  }
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
999999_AED1

Repeticao crescente
0
1
2
3
4

Repeticao decrescente
5 4 3 2 1
Apertar ENTER para terminar.

*/


}
void method_07(void)
{
  int x = 0;

  // mostrar mensagem com formato
  printf("%s\n", "999999_AED1");

  // repetir enquanto condicao verdadeira
  printf("\n%s\n", "Repeticao crescente");
  for (x = 0; x < 5; x = x + 1)
  {
    // mostrar valor em linha separada
    printf("%d\n", x);
  }

  // repetir enquanto condicao verdadeira
  printf("\n%s\n", "Repeticao decrescente");
  for (x = 5; x > 0; x = x - 1)
  {
    // mostrar valor na mesma linha
    printf("%d ", x);
  }
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
999999_AED1

Repeticao crescente
0
1
2
3
4

Repeticao decrescente
5 4 3 2 1
Apertar ENTER para terminar.

*/


}
void method_08(void)
{

  printf("\n%s\n", "chamada no main()");

  // chamar metodo
  print_header("999999_AED1 no metodo");

  // mostrar mensagem com formato (local)
  printf("%s\n", "de volta ao main()");

  // encerrar
  print_footer("Apertar ENTER para terminar.");

  /*
  Testes e observacoes:
1. Teste com metodo

chamada no main()
999999_AED1 no metodo
de volta ao main()

Apertar ENTER para terminar.

*/


}
void method_09(void)
{
  // mostrar mensagem com formato (local)
  printf("\n%s\n", "chamada no main()");

  // chamar metodo
  print_header("999999_AED1 no metodo");

  // mostrar mensagem com formato (local)
  printf("%s\n", "de volta ao main()");

  // encerrar
  print_footer("Apertar ENTER para terminar.");
 
 
 /* Testes e observacoes:
1. Teste com metodo

chamada no main()
999999_AED1 no metodo
de volta ao main()

Apertar ENTER para terminar.

*/

}
void method_10(void)
{

  int x = 0;
  int y = 0;
  int z = 0;
  double d = 1.5;

  // iniciar
  printf("%s\n", "999999_AED1");

  // aplicar funcoes
  printf("\nAplicar funcoes\n");
  printf("floor(%lf) = %lf\n",
         d, floor(d)); // piso
  printf("\n");
  printf("ceil(%lf)  = %lf\n",
         d, ceil(d)); // teto
  printf("\n");
  x = trunc(d); // truncar
  printf("trunc(%lf) = %d\n",
         d, x);
  printf("\n");
  x = round(d); // arredondar
  printf("round(%lf) = %d\n",
         d, x);
  printf("\n");

  // funcoes trigonometricas em radianos
  d = sin(30.0 * M_PI / 180.0); // seno
  printf("sin(30) = %5.2lf\n", d);
  d = cos(60.0 * M_PI / 180.0); // cosseno
  printf("cos(60) = %5.2lf\n", d);
  d = atan(1.00) * 180.0 / M_PI; // arco tangente
  printf("atan(1) = %5.2lf\n", d);
  printf("\n");

  d = pow(2.0, 3.0); // potencia
  printf("pow(2,3) = %5.0lf\n", d);
  d = lg(d); // logaritmo base 2
  printf("lg(8,2)  = %5.0lf\n", d);
  printf("\n");

  d = sqr(2.0); // quadrado
  printf("sqr(2)   = %5.0lf\n", d);
  d = sqrt(d); // raiz quadrada
  printf("sqrt(4)  = %5.0lf\n", d);

  // aplicar funcoes para comparacoes
  x = 3;
  y = 5;
  z = 7;
  printf("\nComparacoes\n");
  printf("maior(%d,%d) = %d\n",
         x, y, max(x, y));
  printf("\n");
  printf("maior(%d,%d,%d) = %d\n",
         x, y, z, max(x, max(y, z)));
  printf("\n");
  printf("menor(%d,%d) = %d\n",
         x, y, min(x, y));
  printf("\n");
  printf("menor(%d,%d,%d) = %d\n",
         x, y, z, min(min(x, y), z));
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Aplicar funcoes
floor(1.500000) = 1.000000

ceil(1.500000)  = 2.000000

trunc(1.500000) = 1

round(1.500000) = 2

sin(30) =  0.50
cos(60) =  0.50
atan(1) = 45.00

pow(2,3) =     8
lg(8,2)  =     3

sqr(2)   =     4
sqrt(4)  =     2

Comparacoes
maior(3,5) = 5

maior(3,5,7) = 7

menor(3,5) = 3

menor(3,5,7) = 3

Apertar ENTER para terminar.

*/


}
void method_11(void)
{
  char s1[] = "abc"; // cadeia de caracteres
  char s2[10];       // espaco para cadeia de caracteres
  strcpy(s2, "def"); // copiar caracteres
  char *s3 = "ghi";  // apontar para constante

  // iniciar
  printf("%s\n", "999999_AED1");

  // aplicar funcoes
  printf("\nAplicar funcoes\n");
  // mostrar valor e tamanho
  printf("s1 = [%s] (%d)\n", s1, strlen(s1));
  printf("s2 = [%s] (%d)\n", s2, strlen(s2));
  printf("s3 = [%s] (%d)\n", s3, strlen(s3));
  printf("\n");

  // mostrar valor apontado
  s3 = &s1[0]; // obter endereco do primeiro caractere
  printf("s1 = [%s] (%d)\n", s3, strlen(s3));
  s3 = &s2[0]; // obter endereco do primeiro caractere
  printf("s2 = [%s] (%d)\n", s3, strlen(s3));
  printf("\n");

  strcat(s2, s1); // concatenar
  printf("s1 = [%s] (%d)\n", s1, strlen(s1));
  printf("s2 = [%s] (%d)\n", s2, strlen(s2));
  printf("\n");

  s3 = s1; // identicos
  printf("s1 = [%s] (%d) (%p)\n",
         s1, strlen(s1), &s1[0]);
  printf("s3 = [%s] (%d) (%p)\n",
         s3, strlen(s3), s3);
  printf("\n");

  // reservar area para armazenar
  s3 = calloc(strlen(s1) + 1, sizeof(char));
  strcpy(s3, s1); // copiar conteudo

  printf("s1 = [%s] (%d) (%p)\n",
         s1, strlen(s1), &s1[0]);
  printf("s3 = [%s] (%d) (%p)\n",
         s3, strlen(s3), s3);
  printf("\n");

  s3 = strdup(s1); // duplicar
  printf("s1 = [%s] (%d) (%p)\n",
         s1, strlen(s1), &s1[0]);
  printf("s3 = [%s] (%d) (%p)\n",
         s3, strlen(s3), s3);
  printf("\n");

  // comparar
  if (strcmp(s1, s3) == 0) // pela igualdade
    printf("%s igual a %s\n", s1, s3);
  if (strcmp(s1, s3) != 0) // pela diferenca
    printf("%s igual a %s\n", s1, s3);
  if (strcmp(s1, s2) < 0) // antecessor
    printf("%s antecede a %s\n", s1, s2);
  if (strcmp(s2, s1) > 0) // sucessor
    printf("%s sucede a %s\n", s2, s1);
  printf("\n");

  // mostrar cada letra separadamente
  for (int x = 0; x < strlen(s1); ++x)
    printf("%c ", s1[x]);
  printf("\n");

  // mostrar cada letra separadamente
  // com apontador
  for (int x = 0; x < strlen(s1); x++)
    printf("%c ", *(s1 + x));
  printf("\n");

  // mostrar cada letra separadamente
  // com apontador operado aritmeticamente
  s3 = &s1[0];        // apontar para a primeira letra
  while (*s3 != '\0') // repetir enquanto diferente de '\0'
  {
    printf("%c ", *s3);
    s3++; // passar 'a proxima
  }
  printf("\n");

  // mostrar cada letra separadamente
  // em ordem inversa, com indexador
  for (int x = strlen(s1) - 1; x >= 0; --x)
    printf("%c ", s1[x]);
  printf("\n");
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Aplicar funcoes
s1 = [abc] (3)
s2 = [def] (3)
s3 = [ghi] (3)

s1 = [abc] (3)
s2 = [def] (3)

s1 = [abc] (3)
s2 = [defabc] (6)

s1 = [abc] (3) (000000D454DFFB88)
s3 = [abc] (3) (000000D454DFFB88)

s1 = [abc] (3) (000000D454DFFB88)
s3 = [abc] (3) (000002374EE2B260)

s1 = [abc] (3) (000000D454DFFB88)
s3 = [abc] (3) (000002374EE20750)

abc igual a abc
abc antecede a defabc
defabc sucede a abc

a b c
a b c
a b c
c b a

Apertar ENTER para terminar.

*/


}
void method_12(void)
{
  // definir dados
  int a[] = {1, 2, 3}; // arranjo com valores
  int b[3];            // espaco para arranjo
                       // definir valores iniciais
  b[0] = 4;
  b[1] = 5;
  b[2] = 6;
  // reservar espaco [3] inteiros
  int *c = malloc(3 * sizeof(int));
  // definir valores iniciais
  if (c != NULL) // se houver espaco reservado
    for (int x = 0; x < 3; x = x + 1)
    {
      c[x] = (x + 1) * 10;
    }

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // aplicar metodos sobre em arranjos
  printf("\nOperacoes com arranjos\n");
  printf("a:\n");
  print_array(3, a);
  printf("\n");

  printf("b:\n");
  print_array(3, b);
  printf("\n");

  printf("c:\n");
  print_array(3, c);
  printf("\n");

  // ler     dados para arranjo
  printf("Entrar dados:\n");
  scan_array(3, c);

  // mostrar dados em   arranjo
  printf("Dados lidos (c):\n");
  print_array(3, c);
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Operacoes com arranjos
a:
1 2 3

b:
4 5 6

c:
10 20 30

Entrar dados:
300 200 100

Dados lidos (c):
300 200 100

Apertar ENTER para terminar.

*/

}
void method_13(void)
{
  int a[][3] = {{1, 2, 3}, // definir com valores
                {4, 5, 6}};
  int b[2][3]; // espaco para matriz
               // definir valores iniciais
  b[0][0] = 6;
  b[0][1] = 5;
  b[0][2] = 4;
  b[1][0] = 3;
  b[1][1] = 2;
  b[1][2] = 1;

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // aplicar metodos sobre em matrizeos
  printf("\nOperacoes com matrizes\n");
  // mostrar dados
  printf("a:\n");
  print_matrix(2, 3, a);
  printf("\n");

  printf("b:\n");
  print_matrix(2, 3, b);
  printf("\n");

  // ler dados para matriz
  printf("Entrar dados:\n");
  scan_matrix(2, 3, a);
  printf("a:\n");
  print_matrix(2, 3, a);
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Operacoes com matrizes
a:
1 2 3
4 5 6

b:
6 5 4
3 2 1

Entrar dados:
9
8
7

6
5
4


a:
9 8 7
6 5 4

Apertar ENTER para terminar.

*/

}
void method_14(void)
{
  // definir dados
  srand(time(NULL));                // basta semear aleatoriedade uma vez
  FILE *a = fopen("DATA.TXT", "w"); // abrir para gravar
  int n = 6;
  int b = 0;

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // gravar valores
  fprintf(a, "%d\n", n); // guardar a quantidade
  for (int x = 0; x < n; x = x + 1)
  {
    fprintf(a, "%d\n", rand() % 100);
  }
  fclose(a); // fechar (INDISPENSAVEL)

  // ler valores
  a = fopen("DATA.TXT", "r"); // abrir para ler
  fscanf(a, "%d", &n);        // obter  a quantidade
  // ler e mostrar dados em arquivo
  printf("\nDados em arquivo:\n");
  for (int x = 0; x < n; x = x + 1)
  {
    fscanf(a, "%d", &b);
    printf("%d\n", b);
  }
  fclose(a); // fechar (RECOMNDAVEL)

  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados em arquivo:
35
77
29
36
76
94

Apertar ENTER para terminar.

OBS.:
Como os valores sao aleatorios,
as saidas poderao mudar a cada
execucao.

*/
  
}
void method_15(void)
{
  // definir dados
  FILE *a = fopen("DATA.TXT", "r");
  int n = 0;
  int *b = NULL;

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // ler valores
  a = fopen("DATA.TXT", "r");
  fscanf(a, "%d", &n);
  // reservar espaco para guardar dados [n] inteiros
  b = malloc(n * sizeof(int));
  for (int x = 0; x < n; x = x + 1)
  {
    fscanf(a, "%d", &b[x]);
  }
  fclose(a);

  // mostrar dados
  printf("\nDados em arquivo:\n");
  for (int x = 0; x < n; x = x + 1)
  {
    printf("%2d\n", b[x]);
  }
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados em arquivo:
35
77
29
36
76
94

Apertar ENTER para terminar.

OBS.:
Os dados dependem dos valores
gerados anteriormete.

*/

}
void method_16(void)
{
  FILE *a = fopen("DATA.TXT", "r");
  struct s_array b;

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // ler valores
  a = fopen("DATA.TXT", "r");
  fscanf(a, "%d", &b.n);
  b.data = malloc(b.n * sizeof(int));
  if (b.data != NULL)
  {
    // ler dados conforme quantidade
    for (int x = 0; x < b.n; x = x + 1)
    {
      fscanf(a, "%d", &b.data[x]);
    }
    fclose(a);

    // mostrar valores
    printf("\nDados guardados:\n");
    for (int x = 0; x < b.n; x = x + 1)
    {
      printf("%2d\n", b.data[x]);
    }
    printf("\n");
  }

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados em arquivo:
92
72
88
67
54

Apertar ENTER para terminar.

OBS.:
Como os valores sao aleatorios,
as saidas poderao mudar a cada
execucao.

*/
/*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados em arquivo:
35
77
29
36
76
94

Apertar ENTER para terminar.

OBS.:
Os dados dependem dos valores
gerados anteriormete.

*/



}
void method_17(void)
{

  // definir dados
  FILE *a = fopen("DATA.TXT", "r");
  Array *b = NULL;

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // ler valores
  a = fopen("DATA.TXT", "r");
  // reservar espaco para guardar dados
  b = malloc(1 * sizeof(Array));
  // testar se ha' espaco para guardar dados
  if (b != NULL)
  {
    // ler dados com apontadores
    fscanf(a, "%d", &(*b).n);
    (*b).data = malloc((*b).n * sizeof(int));
    for (int x = 0; x < (*b).n; x = x + 1)
    {
      fscanf(a, "%d", &(*b).data[x]);
    }
    fclose(a);

    // mostrar valores
    printf("\nDados guardados:\n");
    for (int x = 0; x < (*b).n; x = x + 1)
    {
      printf("%2d\n", (*b).data[x]);
    }
    printf("\n");
  }
  // dispensar area reservada
  free(b);
  printf("\n");

  // ler valores    (de novo, com outra notacao)
  a = fopen("DATA.TXT", "r");
  // reservar espaco para guardar dados
  b = malloc(1 * sizeof(Array));
  // testar se ha' espaco para guardar dados
  if (b != NULL)
  {
    // ler dados com apontadores (outra notacao)
    fscanf(a, "%d", &b->n);
    b->data = malloc(b->n * sizeof(int));
    for (int x = 0; x < b->n; x = x + 1)
    {
      fscanf(a, "%d", &b->data[x]);
    }
    fclose(a);

    // mostrar valores           (outra notacao)
    printf("\nDados guardados:\n");
    for (int x = 0; x < b->n; x = x + 1)
    {
      printf("%2d\n", b->data[x]);
    }
    printf("\n");
  }
  // dispensar area reservada
  free(b);
  printf("\n");

  // ler valores         (com mais outra notacao)
  a = fopen("DATA.TXT", "r");
  // reservar espaco para guardar dados
  b = malloc(1 * sizeof(Array));
  // testar se ha' espaco para guardar dados
  if (b != NULL)
  {
    // ler dados com apontadores (outra notacao)
    fscanf(a, "%d", &b->n);
    b->data = malloc(b->n * sizeof(int));
    for (int x = 0; x < b->n; x = x + 1)
    {
      fscanf(a, "%d", (b->data + x));
    } // sem &
    fclose(a);

    // mostrar valores           (outra notacao)
    printf("\nDados guardados:\n");
    for (int x = 0; x < b->n; x = x + 1)
    {
      printf("%2d\n", *(b->data + x));
    } // com *
    printf("\n");
  }
  // dispensar area reservada
  free(b);
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados em arquivo:
35
77
29
36
76
94

Dados em arquivo:
35
77
29
36
76
94

Dados em arquivo:
35
77
29
36
76
94

Apertar ENTER para terminar.

OBS.:
Os dados dependem dos valores
gerados anteriormente.

*/


}
void method_18(void)
{

  FILE *a = fopen("DATA.TXT", "r");
  Array *b = NULL;

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // ler valores
  a = fopen("DATA.TXT", "r");
  // reservar espaco para guardar dados
  b = malloc(1 * sizeof(Array));
  // testar se ha' espaco para guardar dados
  if (b != NULL)
  {
    // ler dados com apontadores (outra notacao)
    fscanf(a, "%d", &b->n);
    b->data = malloc(b->n * sizeof(int));
    for (int x = 0; x < b->n; x = x + 1)
    {
      fscanf(a, "%d", (b->data + x));
    } // sem &
    fclose(a);

    // mostrar valores por procedimento
    printf("\nDados guardados:\n");
    print_Array_1(*b); // com *
    printf("\n");
  }
  // dispensar area reservada
  free(b);
  printf("\n");

  // ler valores
  a = fopen("DATA.TXT", "r");
  // reservar espaco para guardar dados
  b = malloc(1 * sizeof(Array));
  // testar se ha' espaco para guardar dados
  if (b != NULL)
  {
    // ler dados com apontadores (outra notacao)
    fscanf(a, "%d", &b->n);
    b->data = malloc(b->n * sizeof(int));
    for (int x = 0; x < b->n; x = x + 1)
    {
      fscanf(a, "%d", &(b->data[x]));
    } // com &
    fclose(a);

    // mostrar valores por procedimento
    printf("\nDados guardados:\n");
    print_Array_2(b); // sem *
    printf("\n");
  }
  // dispensar area reservada
  free(b);
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados guardados:
35 77 29 36 76 94

Dados guardados:
35 77 29 36 76 94

Apertar ENTER para terminar.

OBS.:
Os dados dependem dos valores
gerados anteriormete.

*/

}
void method_19(void)
{
  // definir dados
  Matrix *a = NULL;

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // reservar espaco para descritor
  a = malloc(1 * sizeof(Matrix));
  // testar se ha' espaco reservado
  if (a == NULL)
  {
    // mostrar codigo de erro
    printf("Erro = %d\n", errno);
    perror("Error");
  }
  else
  {
    // reservar espaco para guardar linhas
    a->rows = 2;
    a->columns = 3;
    a->data = malloc(a->rows * sizeof(int *));
    // testar se ha' espaco para guardar dados
    if (a->data != NULL)
    {
      // reservar espaco para guardar colunas
      for (int x = 0; x < 2; x = x + 1)
      {
        a->data[x] = malloc(a->columns * sizeof(int));
        if (a->data[x])
        { // ler dados com apontadores
          printf("\nDados para a linha %d matriz:\n", x);
          for (int y = 0; y < a->columns; y = y + 1)
          {
            scanf("%d", &a->data[x][y]);
          }
        }
      }

      // mostrar valores
      printf("\nDados guardados:\n");
      for (int x = 0; x < a->rows; x = x + 1)
      {
        for (int y = 0; y < a->columns; y = y + 1)
        {
          printf("%2d\t", a->data[x][y]);
        }
        printf("\n");
      }
    }
  }
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
1. Teste simples
999999_AED1

Dados para a linha 0 matriz:
1
2
3

Dados para a linha 1 matriz:
4
5
6

Dados guardados:
 1       2       3
 4       5       6

Apertar ENTER para terminar.

*/
}
void method_20(void)
{
  // definir dados
  char Semana_str_1[7][8]; // para guardar lista de nomes

  strcpy(Semana_str_1[Domingo], "Domingo");
  strcpy(Semana_str_1[Segunda], "Segunda");
  strcpy(Semana_str_1[Terca], "Terca  ");
  strcpy(Semana_str_1[Quarta], "Quarta ");
  strcpy(Semana_str_1[Quinta], "Quinta ");
  strcpy(Semana_str_1[Sexta], "Sexta  ");
  strcpy(Semana_str_1[Sabado], "Sabado ");

  // definir dados
  char Semana_str_2[][8] // para guardar lista de nomes
      = {"domingo",
         "segunda",
         "terca  ",
         "quarta ",
         "quinta ",
         "sexta  ",
         "sabado "};

  // mostrar mensagem
  printf("%s\n", "999999_AED1");

  // mostrar valores
  printf("\nMostrar dias da semana:\n");
  for (enum Semana dia = Domingo; dia <= Sabado; dia = dia + 1)
  {
    printf("%d: %s\n", dia, Semana_str_1[dia]);
  }
  printf("\n");

  // mostrar valores
  printf("\nMostrar dias da semana:\n");
  for (Dias_da_Semana dia = Domingo; dia <= Sabado; dia = dia + 1)
  {
    printf("%d: %s\n", dia, Semana_str_2[dia]);
  }
  printf("\n");

  // encerrar
  printf("%s\n", "Apertar ENTER para terminar.");
  getchar();

  /*
  Testes e observacoes:
1. Teste simples
999999_AED1

Mostrar dias da semana:
0: Domingo
1: Segunda
2: Terca
3: Quarta
4: Quinta
5: Sexta
6: Sabado


Mostrar dias da semana:
0: domingo
1: segunda
2: terca
3: quarta
4: quinta
5: sexta
6: sabado

Apertar ENTER para terminar.

*/
}

// FIM DOS METODOS

int main(int argc, char *argv[])
{

  // definir dados / resultados

  int opcao = 0;

  // identificar
  printf("\n%s\n", "Exemplo00M0 - Programa = v0.0");
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
    printf("%s\n", "11 - Metodo 11");
    printf("%s\n", "12 - Metodo 12");
    printf("%s\n", "13 - Metodo 13");
    printf("%s\n", "14 - Metodo 14");
    printf("%s\n", "15 - Metodo 15");
    printf("%s\n", "16 - Metodo 16");
    printf("%s\n", "17 - Metodo 17");
    printf("%s\n", "18 - Metodo 18");
    printf("%s\n", "19 - Metodo 19");
    printf("%s\n", "20 - Metodo 20");
    printf("\n");

    printf("\n%s", "Opcao = "); // ler a opcao do teclado
    scanf("%d", &opcao);
    getchar();

    // mostrar opcao lida
    printf("\n%s%d", "Opcao: ", opcao);

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
    case 11:
      method_11();
      break;
    case 12:
      method_12();
      break;
    case 13:
      method_13();
      break;
    case 14:
      method_14();
      break;
    case 15:
      method_15();
      break;
    case 16:
      method_16();
      break;
    case 17:
      method_17();
      break;
    case 18:
      method_18();
      break;
    case 19:
      method_19();
      break;
    case 20:
      method_20();
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
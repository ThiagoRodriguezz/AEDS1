/*
Author: Thiago de Araujo Rodrigues
Pontifica Universidade Catolica - MG
AEDS I
*/

#include "io.h"
#include <windows.h>

// ============================================================
// inicio das funções
// ============================================================

/**
    ePar - Verifica se um número inteiro é par.
    @param n - Número inteiro a ser verificado
    @return 1 se par, 0 se ímpar
*/
int ePar(int n) {
    return (n % 2) == 0;
}

/**
    ePositivo - Verifica se um número inteiro é estritamente positivo.
    @param n - Número inteiro a ser verificado
    @return 1 se maior que zero, 0 caso contrário
*/
int ePositivo(int n) {
    return n > 0;
}

/**
    eDivisivelPorTres - Verifica se um número é divisível por 3.
    @param n - Número inteiro a ser verificado
    @return 1 se divisível por 3, 0 caso contrário
*/
int eDivisivelPorTres(int n) {
    return (n % 3) == 0;
}

/**
    eDivisivelPorCinco - Verifica se um número é divisível por 5.
    @param n - Número inteiro a ser verificado
    @return 1 se divisível por 5, 0 caso contrário
*/
int eDivisivelPorCinco(int n) {
    return (n % 5) == 0;
}

/**
    lerPares - Lê do teclado o tamanho de um arranjo e seus elementos,
               garantindo que apenas valores positivos e pares sejam aceitos.
               Rejeita tamanho nulo ou negativo.
    @param n      - Ponteiro para armazenar a quantidade de elementos lidos
    @param arranjo - Arranjo onde os valores válidos serão armazenados
    @return void (n retornado por referência)
*/
void lerPares(int *n, int arranjo[]) {
    do {
        *n = IO_readint("Informe o tamanho do arranjo (deve ser positivo): ");
        if (!ePositivo(*n))
            IO_println("Tamanho inválido! Deve ser maior que zero.");
    } while (!ePositivo(*n));

    int i = 0;
    while (i < *n) {
        int val = IO_readint("Informe um valor positivo e par: ");
        while (!(ePositivo(val) && ePar(val))) {
            IO_println("Valor inválido! Deve ser positivo e par.");
            val = IO_readint("Informe um valor positivo e par: ");
        }
        arranjo[i] = val;
        i++;
    }
}

/**
    gravarParesPositivos - Grava em arquivo somente os valores positivos e pares
                           de um arranjo. A primeira linha do arquivo contém a
                           contagem dos valores válidos, seguida de um por linha.
    @param n       - Quantidade de elementos no arranjo original
    @param arranjo - Arranjo com os valores a serem filtrados
    @param nome    - Nome do arquivo de destino
    @return void
*/
void gravarParesPositivos(int n, int arranjo[], char *nome) {
    int count = 0;
    int i = 0;
    while (i < n) {
        count += (ePositivo(arranjo[i]) && ePar(arranjo[i]));
        i++;
    }

    FILE *f = fopen(nome, "w");
    if (f == NULL) {
        IO_println("Erro: não foi possível abrir o arquivo para escrita.");
        return;
    }

    fprintf(f, "%d\n", count);
    i = 0;
    while (i < n) {
        if (ePositivo(arranjo[i]) && ePar(arranjo[i]))
            fprintf(f, "%d\n", arranjo[i]);
        i++;
    }
    fclose(f);
    IO_println("Dados gravados com sucesso.");
}

/**
    lerArquivo - Lê um arranjo de inteiros a partir de um arquivo.
                 A primeira linha do arquivo deve conter a quantidade de elementos.
    @param n      - Ponteiro para armazenar a quantidade de elementos lidos
    @param nome   - Nome do arquivo a ser lido
    @param arranjo - Arranjo onde os valores serão armazenados
    @return void (n e arranjo retornados por referência/parâmetro)
*/
void lerArquivo(int *n, char *nome, int arranjo[]) {
    FILE *f = fopen(nome, "r");
    if (f == NULL) {
        IO_println("Erro: não foi possível abrir o arquivo para leitura.");
        *n = 0;
        return;
    }
    fscanf(f, "%d", n);
    int i = 0;
    while (i < *n) {
        fscanf(f, "%d", &arranjo[i]);
        i++;
    }
    fclose(f);
}

/**
    gerarInt - Gera um valor inteiro aleatório dentro de um intervalo aberto
               [inferior, superior).
    @param inferior - Limite inferior do intervalo (incluído)
    @param superior - Limite superior do intervalo (excluído)
    @return Valor inteiro aleatório gerado no intervalo
*/
int gerarInt(int inferior, int superior) {
    int range = superior - inferior;
    return inferior + (rand() % range);
}

/**
    acharMenorPar - Procura o menor valor par em um arranjo.
                    Usa o primeiro par encontrado como referência inicial.
                    Retorna 0 se nenhum par existir.
    @param n       - Quantidade de elementos no arranjo
    @param arranjo - Arranjo de inteiros a ser pesquisado
    @return Menor valor par encontrado, ou 0 se não houver nenhum
*/
int acharMenorPar(int n, int arranjo[]) {
    int menor = 0;
    int i = 0;

    while (i < n && !ePar(arranjo[i]))
        i++;

    if (i < n) {
        menor = arranjo[i];
        i++;
        while (i < n) {
            if (ePar(arranjo[i]) && arranjo[i] < menor)
                menor = arranjo[i];
            i++;
        }
    }
    return menor;
}

/**
    acharMaiorParDivisivelPorTres - Procura o maior valor par, múltiplo de 3
                                    e não múltiplo de 5, em um arranjo.
                                    Usa o primeiro valor que satisfaz a condição
                                    como referência. Retorna 0 se não houver.
    @param n       - Quantidade de elementos no arranjo
    @param arranjo - Arranjo de inteiros a ser pesquisado
    @return Maior valor que satisfaz a condição, ou 0 se não houver
*/
int acharMaiorParDivisivelPorTres(int n, int arranjo[]) {
    int maior = 0;
    int i = 0;

    while (i < n && !(ePar(arranjo[i]) && eDivisivelPorTres(arranjo[i]) && !eDivisivelPorCinco(arranjo[i])))
        i++;

    if (i < n) {
        maior = arranjo[i];
        i++;
        while (i < n) {
            if (ePar(arranjo[i]) && eDivisivelPorTres(arranjo[i]) && !eDivisivelPorCinco(arranjo[i]) && arranjo[i] > maior)
                maior = arranjo[i];
            i++;
        }
    }
    return maior;
}

/**
    acharMedia - Calcula a média aritmética dos valores em um arranjo.
                 Trata o caso em que o arranjo está vazio retornando 0.0.
    @param n       - Quantidade de elementos no arranjo
    @param arranjo - Arranjo de inteiros
    @return Média dos valores como double, ou 0.0 se n for zero
*/
double acharMedia(int n, int arranjo[]) {
    if (n == 0) return 0.0;
    double soma = 0;
    int i = 0;
    while (i < n) {
        soma += arranjo[i];
        i++;
    }
    return soma / n;
}

/**
    eOrdenadoDecrescente - Verifica se um arranjo está ordenado em ordem
                           decrescente. Não usa break; percorre todos os elementos
                           acumulando a condição de desordem com OR lógico.
    @param n       - Quantidade de elementos no arranjo
    @param arranjo - Arranjo de inteiros a ser verificado
    @return 1 se ordenado em ordem decrescente, 0 caso contrário
*/
int eOrdenadoDecrescente(int n, int arranjo[]) {
    int desordenado = 0;
    int i = 0;
    while (i < n - 1) {
        desordenado = desordenado || (arranjo[i] < arranjo[i + 1]);
        i++;
    }
    return !desordenado;
}

/**
    acharValor - Verifica se um valor existe em um arranjo a partir
                 de uma posição inicial. Interrompe ao primeiro encontrado.
    @param procurado - Valor inteiro a ser procurado
    @param inicio    - Índice inicial da busca
    @param n         - Quantidade de elementos no arranjo
    @param arranjo   - Arranjo de inteiros a ser pesquisado
    @return 1 se o valor foi encontrado, 0 caso contrário
*/
int acharValor(int procurado, int inicio, int n, int arranjo[]) {
    int i = inicio;
    int encontrado = 0;
    while (i < n && !encontrado) {
        encontrado = (arranjo[i] == procurado);
        i++;
    }
    return encontrado;
}

/**
    acharPosicao - Encontra o índice da primeira ocorrência de um valor
                  em um arranjo, a partir de uma posição inicial.
    @param procurado - Valor inteiro a ser procurado
    @param inicio    - Índice inicial da busca
    @param n         - Quantidade de elementos no arranjo
    @param arranjo   - Arranjo de inteiros a ser pesquisado
    @return Índice da primeira ocorrência, ou -1 se não encontrado
*/
int acharPosicao(int procurado, int inicio, int n, int arranjo[]) {
    int i = inicio;
    while (i < n && arranjo[i] != procurado)
        i++;
    return (i < n) ? i : -1;
}

/**
    acharQuantos - Conta quantas vezes um valor aparece em um arranjo
                  a partir de uma posição inicial, percorrendo todos os elementos.
    @param procurado - Valor inteiro a ser contado
    @param inicio    - Índice inicial da busca
    @param n         - Quantidade de elementos no arranjo
    @param arranjo   - Arranjo de inteiros a ser pesquisado
    @return Número de ocorrências do valor no arranjo
*/
int acharQuantos(int procurado, int inicio, int n, int arranjo[]) {
    int i = inicio;
    int count = 0;
    while (i < n) {
        count += (arranjo[i] == procurado);
        i++;
    }
    return count;
}

/**
    strTamanho - Calcula o comprimento de uma string sem usar strlen.
    @param s - String a ser medida
    @return Número de caracteres antes do '\0'
*/
int strTamanho(char *s) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

/**
    eLetraF - Verifica se um caractere é 'f' ou 'F'.
    @param c - Caractere a ser verificado
    @return 1 se for 'f' ou 'F', 0 caso contrário
*/
int eLetraF(char c) {
    return (c == 'f') || (c == 'F');
}

/**
    calcularDivisoresImpares - Encontra todos os divisores ímpares de um número
                               e os armazena em um arranjo.
    @param num      - Número inteiro cujos divisores serão calculados
    @param divisores - Arranjo onde os divisores ímpares serão armazenados
    @return Quantidade de divisores ímpares encontrados
*/
int calcularDivisoresImpares(int num, int divisores[]) {
    int count = 0;
    int i = 1;
    while (i <= num) {
        if ((num % i == 0) && !ePar(i)) {
            divisores[count] = i;
            count++;
        }
        i++;
    }
    return count;
}

/**
    filtrarPalavrasSemF - Lê palavras de um arquivo e retorna as dez primeiras
                          que não comecem nem terminem com 'f' ou 'F'.
                          Supõe no máximo 100 palavras no arquivo.
    @param nome      - Nome do arquivo a ser lido
    @param resultado - Arranjo de strings onde as palavras filtradas são guardadas
    @return Quantidade de palavras que satisfazem a condição (máximo 10)
*/
int filtrarPalavrasSemF(char *nome, char resultado[][100]) {
    FILE *f = fopen(nome, "r");
    if (f == NULL) {
        IO_println("Erro: não foi possível abrir PALAVRAS.TXT.");
        return 0;
    }

    char palavra[100];
    int count = 0;
    int total = 0;

    while (total < 100 && count < 10 && fscanf(f, "%99s", palavra) == 1) {
        int tam = strTamanho(palavra);
        int valida = (tam > 0) && !eLetraF(palavra[0]) && !eLetraF(palavra[tam - 1]);
        if (valida) {
            int j = 0;
            while (palavra[j] != '\0') {
                resultado[count][j] = palavra[j];
                j++;
            }
            resultado[count][j] = '\0';
            count++;
        }
        total++;
    }
    fclose(f);
    return count;
}

// fim das funções

// inicio dos methods

void method_01(void) {
    IO_id("Method 01 - v1.0");

    int n;
    int arranjo[100];

    lerPares(&n, arranjo);

    IO_println("Valores lidos:");
    int i = 0;
    while (i < n) {
        printf("  arranjo[%d] = %d\n", i, arranjo[i]);
        i++;
    }

    IO_pause("Aperte ENTER para terminar.");
}

void method_02(void) {
    IO_id("Method 02 - v1.0");

    int n;
    int arranjo[100];

    do {
        n = IO_readint("Informe a quantidade de elementos a digitar: ");
        if (!ePositivo(n))
            IO_println("Quantidade inválida! Deve ser maior que zero.");
    } while (!ePositivo(n));

    IO_println("Digite os valores (qualquer inteiro; negativos e ímpares serão descartados ao gravar):");
    int i = 0;
    while (i < n) {
        arranjo[i] = IO_readint("Valor: ");
        i++;
    }

    char nome[100];
    printf("Nome do arquivo para gravar: ");
    scanf("%99s", nome);

    gravarParesPositivos(n, arranjo, nome);

    IO_println("Lendo de volta do arquivo:");
    int n2;
    int arranjo2[100];
    lerArquivo(&n2, nome, arranjo2);

    i = 0;
    while (i < n2) {
        printf("  arranjo[%d] = %d\n", i, arranjo2[i]);
        i++;
    }

    IO_pause("Aperte ENTER para terminar.");
}

void method_03(void) {
    IO_id("Method 03 - v1.0");

    srand((unsigned)time(NULL));

    int inferior = IO_readint("Informe o limite inferior do intervalo: ");
    int superior = IO_readint("Informe o limite superior do intervalo: ");

    while (superior <= inferior) {
        IO_println("O limite superior deve ser maior que o inferior!");
        superior = IO_readint("Informe o limite superior do intervalo: ");
    }

    int N;
    do {
        N = IO_readint("Informe a quantidade de valores a gerar (N): ");
        if (!ePositivo(N))
            IO_println("Quantidade deve ser positiva!");
    } while (!ePositivo(N));

    int arranjo[1000];
    int i = 0;
    while (i < N) {
        arranjo[i] = gerarInt(inferior, superior);
        i++;
    }

    FILE *f = fopen("DADOS.TXT", "w");
    if (f == NULL) {
        IO_println("Erro ao criar o arquivo DADOS.TXT.");
        IO_pause("Aperte ENTER para terminar.");
        return;
    }
    fprintf(f, "%d\n", N);
    i = 0;
    while (i < N) {
        fprintf(f, "%d\n", arranjo[i]);
        i++;
    }
    fclose(f);

    IO_println("Valores gerados e gravados em DADOS.TXT:");
    i = 0;
    while (i < N) {
        printf("  %d\n", arranjo[i]);
        i++;
    }

    IO_pause("Aperte ENTER para terminar.");
}

void method_04(void) {
    IO_id("Method 04 - v1.0");

    char nome[100];
    printf("Nome do arquivo: ");
    scanf("%99s", nome);

    int n;
    int arranjo[1000];
    lerArquivo(&n, nome, arranjo);

    int menor = acharMenorPar(n, arranjo);

    if (menor == 0)
        IO_println("Nenhum valor par encontrado no arranjo.");
    else
        printf("Menor valor par: %d\n", menor);

    IO_pause("Aperte ENTER para terminar.");
}

void method_05(void) {
    IO_id("Method 05 - v1.0");

    char nome[100];
    printf("Nome do arquivo: ");
    scanf("%99s", nome);

    int n;
    int arranjo[1000];
    lerArquivo(&n, nome, arranjo);

    int maior = acharMaiorParDivisivelPorTres(n, arranjo);

    if (maior == 0)
        IO_println("Nenhum valor par, múltiplo de 3 e não de 5 encontrado.");
    else
        printf("Maior valor par, divisível por 3 e não por 5: %d\n", maior);

    IO_pause("Aperte ENTER para terminar.");
}

void method_06(void) {
    IO_id("Method 06 - v1.0");

    int n;
    int arranjo[1000];
    lerArquivo(&n, "DADOS.TXT", arranjo);

    if (n == 0) {
        IO_println("Arranjo vazio. Nenhum dado para processar.");
        IO_pause("Aperte ENTER para terminar.");
        return;
    }

    double media = acharMedia(n, arranjo);
    printf("Média: %.2f\n", media);

    int cntMenores = 0, cntMaiores = 0;
    int i = 0;
    while (i < n) {
        if (arranjo[i] <= media) cntMenores++;
        else                      cntMaiores++;
        i++;
    }

    FILE *fMenores = fopen("MENORES.TXT", "w");
    FILE *fMaiores = fopen("MAIORES.TXT", "w");

    if (fMenores == NULL || fMaiores == NULL) {
        IO_println("Erro ao criar os arquivos de saída.");
        IO_pause("Aperte ENTER para terminar.");
        return;
    }

    fprintf(fMenores, "%d\n", cntMenores);
    fprintf(fMaiores, "%d\n", cntMaiores);

    i = 0;
    while (i < n) {
        if (arranjo[i] <= media) fprintf(fMenores, "%d\n", arranjo[i]);
        else                      fprintf(fMaiores, "%d\n", arranjo[i]);
        i++;
    }

    fclose(fMenores);
    fclose(fMaiores);
    IO_println("Separados em MENORES.TXT (<=media) e MAIORES.TXT (>media).");

    IO_pause("Aperte ENTER para terminar.");
}

void method_07(void) {
    IO_id("Method 07 - v1.0");

    int n;
    int arranjo[1000];
    lerArquivo(&n, "DADOS.TXT", arranjo);

    int resultado = eOrdenadoDecrescente(n, arranjo);

    if (resultado)
        IO_println("O arranjo ESTÁ ordenado em ordem decrescente.");
    else
        IO_println("O arranjo NÃO está ordenado em ordem decrescente.");

    IO_pause("Aperte ENTER para terminar.");
}

void method_08(void) {
    IO_id("Method 08 - v1.0");

    int n;
    int arranjo[1000];
    lerArquivo(&n, "DADOS.TXT", arranjo);

    int procurado = IO_readint("Informe o valor a ser procurado: ");

    int existe = acharValor(procurado, 0, n, arranjo);

    if (existe)
        printf("O valor %d FOI encontrado no arranjo.\n", procurado);
    else
        printf("O valor %d NÃO foi encontrado no arranjo.\n", procurado);

    IO_pause("Aperte ENTER para terminar.");
}

void method_09(void) {
    IO_id("Method 09 - v1.0");

    int n;
    int arranjo[1000];
    lerArquivo(&n, "DADOS.TXT", arranjo);

    int procurado = IO_readint("Informe o valor a ser procurado: ");

    int onde = acharPosicao(procurado, 0, n, arranjo);

    if (onde != -1)
        printf("O valor %d foi encontrado na posição %d.\n", procurado, onde);
    else
        printf("O valor %d NÃO foi encontrado no arranjo.\n", procurado);

    IO_pause("Aperte ENTER para terminar.");
}

void method_10(void) {
    IO_id("Method 10 - v1.0");

    int n;
    int arranjo[1000];
    lerArquivo(&n, "DADOS.TXT", arranjo);

    int procurado = IO_readint("Informe o valor a ser procurado: ");

    int vezes = acharQuantos(procurado, 0, n, arranjo);

    printf("O valor %d aparece %d vez(es) no arranjo.\n", procurado, vezes);

    IO_pause("Aperte ENTER para terminar.");
}


void Extra01(void) {
    IO_id("Extra 01");

    int num;
    do {
        num = IO_readint("Informe um número inteiro positivo: ");
        if (!ePositivo(num))
            IO_println("O número deve ser positivo!");
    } while (!ePositivo(num));

    // Pelo enunciado, no máximo 'num' divisores
    int divisores[10000];
    int qtd = calcularDivisoresImpares(num, divisores);

    printf("Quantidade de divisores ímpares de %d: %d\n", num, qtd);
    IO_println("Divisores ímpares:");
    int i = 0;
    while (i < qtd) {
        printf("  %d\n", divisores[i]);
        i++;
    }

    FILE *f = fopen("DIVISORES.TXT", "w");
    if (f == NULL) {
        IO_println("Erro ao criar DIVISORES.TXT.");
        IO_pause("Aperte ENTER para terminar.");
        return;
    }
    fprintf(f, "%d\n", qtd);
    i = 0;
    while (i < qtd) {
        fprintf(f, "%d\n", divisores[i]);
        i++;
    }
    fclose(f);
    IO_println("Divisores gravados em DIVISORES.TXT.");

    IO_pause("Aperte ENTER para terminar.");
}

void Extra02(void) {
    IO_id("Extra 02");

    char resultado[10][100];
    int qtd = filtrarPalavrasSemF("PALAVRAS.TXT", resultado);

    if (qtd == 0) {
        IO_println("Nenhuma palavra encontrada que satisfaça a condição.");
    } else {
        printf("Palavras sem 'f'/'F' no início ou fim (%d encontradas):\n", qtd);
        int i = 0;
        while (i < qtd) {
            printf("  %s\n", resultado[i]);
            i++;
        }
    }

    IO_pause("Aperte ENTER para terminar.");
}



// fim dos methods

int main ( int argc, char* argv [ ] ){

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int x;

    do {

    IO_id      ("\nExemplo0300 - Programa - v1.0");
    IO_println ("=+= Opções =+= \n ");
    IO_println (" 0 - Parar \n");

    printf("%s%s\n", " 1 - Método 01      ", " 6 - Método 06"); 
    printf("%s%s\n", " 2 - Método 02      ", " 7 - Método 07"); 
    printf("%s%s\n", " 3 - Método 03      ", " 8 - Método 08"); 
    printf("%s%s\n", " 4 - Método 04      ", " 9 - Método 09"); 
    printf("%s%s\n", " 5 - Método 05      ", "10 - Método 10"); 
    IO_println ("");
    printf("%s%s\n", "11 - Extras 01      ", "12 - Extras 02");
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
        case 11: Extra01   ();  break;
        case 12: Extra02   ();  break;

        default:
            IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
            IO_concat ( IO_toString_d ( x ), ")" ) ));
    } 
}
    while (x != 0);

    IO_pause ("Apertar ENTER para terminar");
    return(0);
}
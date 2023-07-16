/* Miguel Werneck Roale 2210457 Turma 3WA*/
/* Gabriel Pereira da Silva Araujo 2211136 Turma 3WA*/

#include "gera.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {

  unsigned char codigo[128];
  FILE *myfp1, *myfp2, *myfp3, *myfp4, *myfp5, *myfp6, *myfp7, *myfp8, *myfp9, *myfp10, *myfp11, *myfp12, *myfp13, *myfp14, *myfp15, *myfp16, *myfp17, *myfp18, *myfp19, *myfp20, *myfp21;
  funcp funcaoSimples;
  int res;
  int falha = 0;
  
/*------------- TESTE 1 - (ret) -----------*/
  
  /* Abre o arquivo fonte */
  if ((myfp1 = fopen("programa1.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 1");
    exit(1);
  }
  
  /* compila a função Simples */
  funcaoSimples = gera(myfp1, codigo);
  fclose(myfp1);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 100) {
    printf("Falhou no primeiro teste\n");
    falha++;
  }


/*------------- TESTE 2 - (variável < inteiro) -----------*/

   if ((myfp2 = fopen("programa2.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 2.");
    exit(1);
  }

  funcaoSimples = gera(myfp2, codigo);
  fclose(myfp2);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 99) {
    printf("Falhou no segundo teste.\n");
    falha++;
  }

/*------------- TESTE 3 - (variavel < variavel) ------------------*/

  if ((myfp3 = fopen("programa3.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 3.");
    exit(1);
  }

  funcaoSimples = gera(myfp3, codigo);
  fclose(myfp3);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 50) {
    printf("Falhou no terceiro teste.\n");
    falha++;
  }

/*------------- TESTE 4 - (usar 5 variáveis) ------------------*/

  if ((myfp4 = fopen("programa4.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 4.");
    exit(1);
  }

  funcaoSimples = gera(myfp4, codigo);
  fclose(myfp4);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 74) {
    printf("Falhou no quarto teste.\n");
    falha++;
  }

/*------------- TESTE 5 - (usar 1 parâmetro) ------------------*/

  if ((myfp5 = fopen("programa5.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 5.");
    exit(1);
  }

  funcaoSimples = gera(myfp5, codigo);
  fclose(myfp5);

  res = (*funcaoSimples)(15);  /* passando argumentos apropriados */
  if (res != 15) {
    printf("Falhou no quinto teste.\n");
    falha++;
  }

/*------------- TESTE 6 - (adição +/+) ------------------*/

  if ((myfp6 = fopen("programa6.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 6.");
    exit(1);
  }

  funcaoSimples = gera(myfp6, codigo);
  fclose(myfp6);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 35) {
    printf("Falhou no sexto teste.\n");
    falha++;
  }

/*------------- TESTE 7 - (subtração +/-) ------------------*/

  if ((myfp7 = fopen("programa7.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 7.");
    exit(1);
  }

  funcaoSimples = gera(myfp7, codigo);
  fclose(myfp7);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 5) {
    printf("Falhou no sétimo teste.\n");
    falha++;
  }

/*------------- TESTE 8 - (multiplicação +/+) ------------------*/

  if ((myfp8 = fopen("programa8.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 8.");
    exit(1);
  }

  funcaoSimples = gera(myfp8, codigo);
  fclose(myfp8);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 38) {
    printf("Falhou no oitavo teste.\n");
    falha++;
  }

/*------------- TESTE 9 - (adição +/-) ------------------*/

  if ((myfp9 = fopen("programa9.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 9.");
    exit(1);
  }

  funcaoSimples = gera(myfp9, codigo);
  fclose(myfp9);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != -15) {
    printf("Falhou no nono teste.\n");
    falha++;
  }

/*------------- TESTE 10 - (subtração -/-) ------------------*/

  if ((myfp10 = fopen("programa10.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 10.");
    exit(1);
  }

  funcaoSimples = gera(myfp10, codigo);
  fclose(myfp10);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != -5) {
    printf("Falhou no décimo teste.\n");
    falha++;
  }

/*------------- TESTE 11 - (multiplicação +/-) ------------------*/

  if ((myfp11 = fopen("programa11.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 11.");
    exit(1);
  }

  funcaoSimples = gera(myfp11, codigo);
  fclose(myfp11);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != -38) {
    printf("Falhou no décimo primeiro teste.\n");
    falha++;
  }

/*------------- TESTE 12 - (multiplicação -/-) ------------------*/

  if ((myfp12 = fopen("programa12.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 12.");
    exit(1);
  }

  funcaoSimples = gera(myfp12, codigo);
  fclose(myfp12);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 38) {
    printf("Falhou no décimo segundo teste.\n");
    falha++;
  }

/*------------- TESTE 13 - (3 parâmetros) ------------------*/

  if ((myfp13 = fopen("programa13.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 13.");
    exit(1);
  }

  funcaoSimples = gera(myfp13, codigo);
  fclose(myfp13);

  res = (*funcaoSimples)(15,20,-5);  /* passando argumentos apropriados */
  if (res != 30) {
    printf("Falhou no décimo terceiro teste.\n");
    falha++;
  }

/*------------- TESTE 14 - (iflez) ------------------*/

  if ((myfp14 = fopen("programa14.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 14.");
    exit(1);
  }

  funcaoSimples = gera(myfp14, codigo);
  fclose(myfp14);

  res = (*funcaoSimples)();  /* passando argumentos apropriados */
  if (res != 1) {
    printf("Falhou no décimo quarto teste.\n");
    falha++;
  }

/*------------- TESTE 15 - (iflez para posição anterior)) ------------------*/

  if ((myfp15 = fopen("programa15.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 15.");
    exit(1);
  }

  funcaoSimples = gera(myfp15, codigo);
  fclose(myfp15);

  res = (*funcaoSimples)(4);  /* passando argumentos apropriados */
  
  if (res != -1){
    printf("Falhou no décimo quinto teste.\n"); 
    falha++;
  }

/*------------- TESTE 16 - (Uma função elaborada) ------------------*/

  if ((myfp16 = fopen("programa16.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 16.");
    exit(1);
  }

  funcaoSimples = gera(myfp16, codigo);
  fclose(myfp16);

  res = (*funcaoSimples)(1,5,4);  /* passando argumentos apropriados */
  if (res != 3) {
    printf("Falhou no décimo sexto teste.\n");
    falha++;
  }

/*------------- TESTE 17 - (f(x) = x + 1) ------------------*/

  if ((myfp17 = fopen("programa17.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 17.");
    exit(1);
  }

  funcaoSimples = gera(myfp17, codigo);
  fclose(myfp17);

  res = (*funcaoSimples)(15);  /* passando argumentos apropriados */
  if (res != 16) {
    printf("Falhou no décimo sétimo teste.\n");
    falha++;
  }

/*------------- TESTE 18 - (avalia se seu argumento é negativo) ------------------*/

  if ((myfp18 = fopen("programa18.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 18.");
    exit(1);
  }

  funcaoSimples = gera(myfp18, codigo);
  fclose(myfp18);

  res = (*funcaoSimples)(-2);  /* passando argumentos apropriados */
  if (res != 1) {
    printf("Falhou no décimo oitavo teste.\n");
    falha++;
  }

/*------------- TESTE 19 - (f(x,y) = (x+y) * (x-y)) ------------------*/

  if ((myfp19 = fopen("programa19.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 19.");
    exit(1);
  }

  funcaoSimples = gera(myfp19, codigo);
  fclose(myfp19);

  res = (*funcaoSimples)(5,3);  /* passando argumentos apropriados */
  if (res != 16) {
    printf("Falhou no décimo nono teste.\n");
    falha++;
  }

/*------------- TESTE 20 - (3 parâmetros) ------------------*/

  if ((myfp20 = fopen("programa20.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 20.");
    exit(1);
  }

  funcaoSimples = gera(myfp20, codigo);
  fclose(myfp20);

  res = (*funcaoSimples)(9);  /* passando argumentos apropriados */
  if (res != 362880) {
    printf("Falhou no vigésimo teste.\n");
    falha++;
  }

  /*------------- TESTE 21 - (usando o segundo parametro, dps o primeiro (mudando ordem das variaveis)) ------------------*/

  if ((myfp21 = fopen("programa21.txt", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte 21.");
    exit(1);
  }

  funcaoSimples = gera(myfp21, codigo);
  fclose(myfp21);

  res = (*funcaoSimples)(20, 10);  /* passando argumentos apropriados */
  if (res != 30) {
    printf("Falhou no vigésimo primeiro teste.\n");
    falha++;
  }

/*-------------- RESULTADO -------------------*/
  
  printf("Resultado: %d falhas nos 21 testes. \n", falha);
  
}

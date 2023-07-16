#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gera.h"

static void error (const char *msg, int line) {
  fprintf(stderr, "erro %s na linha %d\n", msg, line);
  exit(EXIT_FAILURE);
}

union X {
  int val;
	unsigned char d[4];
} x;

struct offset {
  int ind; 
  int n;      
};
typedef struct offset Offset;

funcp gera(FILE *myfp, unsigned char codigo[]){
  int line = 1; int j = 4;
  int c; int lineVector[30] = {};
  
  Offset offsets_vetor[30];
  int cont_offsets = 0;

    codigo[0] = 0x55;
    codigo[1] = 0x48;
    codigo[2] = 0x89;
    codigo[3] = 0xe5; // pushq %rbp / movq %rsp, %rbp / (inicializa a pilha)
     
     while ((c = fgetc(myfp)) != EOF) {

      lineVector[line] = j; // adiciona a quantidade de comandos
       
      if ((c == 'v') || (c == 'v') || (c == 'i') || (c == 'r')){ // contagem de linhas
        line++;
      }
       
    switch (c) {
      case 'r': { /* retorno */
        char var0;
        int idx0;

        if (fscanf(myfp, "et %c%d", &var0, &idx0) != 2)
          error("comando invalido (ret)", line);

        int vi = - (36 - (4 * idx0)); // conta para botar na pilha
      
       if(var0 == '$'){
        codigo[j] = 0xb8; // mov to %eax
        j++;
        x.val = idx0; // passo como int o valor
        
        for(int i = 0; i < 4; i++){
          codigo[j] = x.d[i]; // coloco os bits do valor ali
          j++;
        }
        
        codigo[j] = 0xc9; // leave
        j++;
        codigo[j] = 0xc3; // ret
        j++;
        break;
       
      }
      else if (var0 == 'v'){ // incompleto
        codigo[j] = 0x8b; // movq
        j++;
        codigo[j] = 0x45; // mover para %eax
        j++;

        codigo[j] = vi;
        j++;
        codigo[j] = 0x5d; // pop
        j++;
        codigo[j] = 0xc3; // ret
        break;
      }
      
    }
      case 'v': {  // atribuicao e op. aritmetica 
        int idx0, idx1;
        char var0 = c, c0, var1;
        if (fscanf(myfp, "%d %c", &idx0, &c0) != 2)
          error("comando invalido (v)", line);

        if (c0 == '<') {  // atribuicao 
          
          if (fscanf(myfp, " %c%d", &var1, &idx1) != 2)
            error("comando invalido (<)", line);

           int vi2 = - (36 - (4 * idx0)); // var1 é v1, v2, v3, v4 ou v5, primeira variavel
          
          if (var1 == '$'){ // guardar inteiro na variavel
          
            codigo[j] = 0xc7; // c7 45 registrador inteiro
            j++;
            codigo[j] = 0x45; 
            j++;
            codigo[j] = vi2; 
            j++;

            x.val = idx1; // passo como int o valor inetiro
        for(int i = 0; i < 4; i++){
          codigo[j] = x.d[i]; // coloco os bits do valor ali
          j++;
        }
          }

          else if (var1 == 'v'){ // caso v1 < v2
            int vi3 = - (36 - (4 * idx1)); // quero o endereco da segunda variavel

            codigo[j] = 0x8b; 
            j++;
            codigo[j] = 0x45; 
            j++;
            codigo[j] = vi3; 
            j++;
            codigo[j] = 0x89; 
            j++;
            codigo[j] = 0x45; 
            j++;
            codigo[j] = vi2; // coloco v3 em v2
            j++;
            
          }
          // parametros
          else if (var1 == 'p'){ 
          int vi7 = - (36 - (4 * idx0)); // v < p1, p2 ou p3 / idx0 e v

          if (idx1 == 1){ // mover %edi, para vi / p1
            codigo[j] = 0x89;
            j++;
            codigo[j] = 0x7d;
            j++;
            codigo[j] = vi7;
            j++;
        }

          else if (idx1 == 2){ // mover %esi para vi / p2
            codigo[j] = 0x89;
            j++;
            codigo[j] = 0x75;
            j++;
            codigo[j] = vi7;
            j++;
          }
          else { // mover %edx para vi / p3
            codigo[j] = 0x89;
            j++;
            codigo[j] = 0x55;
            j++;
            codigo[j] = vi7;
            j++;
          }
        }

        }
         else if (c0 == '='){  
          char var2, op;
          int idx2;
          if (c0 != '=')
            error("comando invalido (=)", line);

          if (fscanf(myfp, " %c%d %c %c%d", &var1, &idx1, &op, &var2, &idx2) != 5)
            error("comando invalido (= apos)", line);

          if (var1 == 'v'){
            int vi4 = - (36 - (4 * idx1)); // poe no ecx

            codigo[j] = 0x8b;
            j++;
            codigo[j] = 0x4d;
            j++;
            codigo[j] = vi4;
            j++;
          }
          
          else if (var1 == '$'){
            codigo[j] = 0xb9; // joga pro %ecx
            j++;
            x.val = idx1;

            for(int i = 0; i < 4; i++){
            codigo[j] = x.d[i];
            j++;
          }
        }
        if (var2 == 'v'){
          int vi5 = - (36 - (4 * idx2)); 
          codigo[j] = 0x8b;
          j++;
          codigo[j] = 0x45;
          j++;
          codigo[j] = vi5;
          j++;
        }

        else if (var2 == '$'){
            codigo[j] = 0xb8; // joga pro %eax
            j++;

            x.val = idx2;
            for(int i = 0; i < 4; i++){
            codigo[j] = x.d[i];
            j++;
          }
        }
        // Fazer a operacao aritmetica
        if (op == '+'){
          codigo[j] = 0x01;
          j++;
          codigo[j] = 0xc1;
          j++;
        }
        if (op == '-'){
          codigo[j] = 0x29;
          j++;
          codigo[j] = 0xc1;
          j++;
        }
        if (op == '*'){
          codigo[j] = 0x0f;
          j++;
          codigo[j] = 0xaf;
          j++;
          codigo[j] = 0xc8;
          j++;
        }

        // Colocar ecx na variavel em que estava
        int vi6 = - (36 - (4 * idx0));
        codigo[j] = 0x89;
        j++;
        codigo[j] = 0x4d;
        j++;
        codigo[j] = vi6;
        j++;
        }
        continue;
      } // case v 
    
      case 'i': {  // desvio condicional 
        char var0;
        int idx0, n;
        if (fscanf(myfp, "flez %c%d %d", &var0, &idx0, &n) != 3){
          printf("Valores lidos: %c, %d, %d\n", var0, idx0, n);
          error("comando invalido (iflez)", line);
        }
          int vi7 = - (36 - (4 * idx0));

      codigo[j] = 0x83;
        j++;
      codigo[j] = 0x7d;
        j++;
      codigo[j] = vi7;
        j++;
      codigo[j] = 0x00;
        j++;

      // jmp
      codigo[j] = 0x7e;
        j++;

      if (n > line) {
        codigo[j++] = 0x00; // Valor qualquer que sera alterado
        offsets_vetor[cont_offsets].ind = (j - 1);
        offsets_vetor[cont_offsets++].n = n;
      } 
      else {
        // calculando offset
        int offset = lineVector[n] - (j + 1);
        codigo[j++] = offset;
        }
      
     } // switch case
    }  // while
     }
   for (int i = 0; i < cont_offsets; i++) { 
    int novo_offset = lineVector[offsets_vetor[i].n] - ((offsets_vetor[i].ind) + 1);
    codigo[offsets_vetor[i].ind] = novo_offset;
  }
return (funcp)codigo;
}


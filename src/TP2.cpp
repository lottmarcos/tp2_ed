#include "TP2.h"
#include "memlog.h"

using namespace std;

//FUNÇÕES GLOBAIS
void uso() {
   // -[o|O] : endereço do arquivo de saída
   // -[i|I] : arquivo de entrada
   // -[m|M] : Mediana de M elementos
   // -[s|S] : Uso de um algoritmo simples (Inserção e Seleção) para partições de menor tamanho
   
   cout << "\n-- OPÇÕES DE USO --\n";
   cout << "\t-[i|I] : arquivo de entrada" << endl;
   cout << "\t-[o|O] : endereço do arquivo de saída" << endl;
   cout << "\t-[m|M] : seleciona o valor M para o calculo do pivô da ordenação" << endl;
   cout << "\t-[s|S] : tamanho máximo das partições a usarem algoritmos simples" << endl;
   cout << endl;
}
string fix_word(string str) {
   string aux;
   //ASCII - upper[65 - 90] lower[97 - 122]
   int diff = 'a' - 'A';
   int x = str.length();
   for (int i = 0; i <= x; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') 
         aux += str[i] + diff;
      else if (str[i] >= 'a' && str[i] <= 'z') 
         aux += str[i];
      else if (str[i] == '-' && ((str[i+1] >= 'a' && str[i+1] <= 'z') || (str[i+1] >= 'A' && str[i+1] <= 'Z') || 
              (str[i-1] >= 'a' && str[i-1] <= 'z') || (str[i-1] >= 'A' && str[i-1] <= 'Z') )) 
         aux += str[i];
      else if (str[i] >= '0' && str[i] <= '9')
         aux += str[i];
   }
   
   return aux;
}
int count_words(string str) {
    stringstream s(str);
    string word;
 
    int count = 0;
    while (s >> word)
        count++;
    return count;
}


//FUNÇÕES SOBRE QUICKSORT
void particao (int esq, int dir, int *i, int *j, palavra *A, int M) {
   palavra x, w;
   *i = esq; *j = dir;
   
   int contador = 0;
   for (int p = *i; p < M; p++) {
      if ((esq + contador) < dir) {
         contador++;
      }
   }
   x = A[(*i + contador)/2]; // obtém o pivô x

   do {
    while (x.senha > A[*i].senha) (*i)++;  
    while (x.senha < A[*j].senha) (*j)--;  
    if (*i <= *j) {
      w = A[*i]; A[*i] = A[*j]; A[*j] = w;
      (*i)++; (*j)--;
    }
   } while (*i <= *j);
   
}
void ordena (int esq, int dir, palavra *A, int M) {
   int i, j;
   particao (esq, dir, &i, &j, A, M);
   if (esq < j) ordena (esq, j, A, M);
   if (i < dir) ordena (i, dir, A, M);
}
void quicksort (palavra *A, int n, int M) {
   ordena(0, n-1, A, M);
}

//FUNÇÕES SOBRE PALAVRAS

palavra::palavra() {
   count = 0;
}
void palavra::set_word(string s) {
   nome = s;
   count = 1;
}
void palavra::set_senha(char array[]) {
   string aux1 = nome;
   string aux2;
   int diff = 'a';
   int j;
   char c_aux;
   int x = aux1.length();
   for (int i = 0; i < x; i++) {
      if (aux1[i] == '-')
         aux2 += '-';
      
      else if (aux1[i] >= '0' && aux1[i] <= '9')
         aux2 += aux1[i];
      else {
         c_aux = aux1[i]; // pego o caractere
         for (j = 0; j < 26; j++) { // acha o indice do array
            if (array[j] == c_aux)
               break;
         }
         aux2 += diff + j;
      }
   }                    
   senha = aux2;
}


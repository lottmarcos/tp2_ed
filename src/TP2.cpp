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
void quickSort(palavra array[], int left, int right) {
   int i = left, j = right;
   palavra pivo = array[(left + right) / 2];
   /* partição */
   while (i <= j) {
         while (array[i].senha < pivo.senha)
               i++;
         while (array[j].senha > pivo.senha)
               j--;
         if (i <= j) {
               swap(array[i], array[j]);
               i++; j--;
         }
   };
   /* recursion */
   if (left < j)
         quickSort(&array[0], left, j);
   if (i < right)
         quickSort(&array[0], i, right);
}
void ordena_array(palavra array[], int n) {
   quickSort(&array[0], 0, n);
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
   int x = aux1.length();
   for (int i = 0; i < x; i++) {
      if (aux1[i] == '-')
         aux2 += '-';
      else
         aux2 += array[aux1[i] - diff];
   }
   senha = aux2;
}


#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <getopt.h>

using namespace std;

//palavras devem estar em caixa baixa
//O programa deve ser capaz de ignorar espaços em branco e elementos de 
//pontuação (“,”, “.”, “!”, “?”, “:”, “;” e “_”) no final das palavras. 

// CLASSE PALAVRA
class palavra {
   public:

   string nome;
   string senha;
   int count;

   palavra();
   void set_word(string s);
   void set_senha(char array[]);
};

// ALGORITMOS DE ORDENAÇÃO
void particao (int esq, int dir, int *i, int *j, palavra *A, int M);
void ordena (int esq, int dir, palavra *A, int M);
void quicksort (palavra *A, int n, int M);
void insertsort(palavra *array, int n);

// FUNÇÕES GLOBAIS
void parse_args(int argc,char ** argv);
void uso();
string fix_word(string str); // deixa todas as letras em lowercase e elimina caracteres especiais
int count_words(string str); // conta o numero de palavras em uma string


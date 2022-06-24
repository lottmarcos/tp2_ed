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

// FUNÇÕES GLOBAIS
void parse_args(int argc,char ** argv);
void uso();

//CLASSE WORD
class word {
   public:

   string nome;
   string palavra;
   int count;

   word();
   void set_word(string s);
};


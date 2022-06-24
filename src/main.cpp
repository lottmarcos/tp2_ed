#include <iostream>
#include <cstring>
#include "TP2.h"
#include "memlog.h"
#include "msgassert.h"

using namespace std;

// variaveis globais para as opções
char *name_input = NULL, *name_output = NULL;
int M, S;


// verifica passagem de argumentos
void parse_args(int argc,char ** argv) {
   // variaveis externas do getopt
   extern char * optarg;

   // variavel auxiliar
     int c;

   // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "i:I:o:O:m:M:S:s:h")) != EOF) {
      switch (c) {
         case 'i':
            name_input = optarg;
            break;
         case 'I':
            name_input = optarg;
            break;
         case 'o':
            name_output = optarg;
            break;
         case 'O':
            name_output = optarg;
            break;
         case 'm':
            M = atoi(optarg);
            break;
         case 'M':
            M = atoi(optarg);
            break;
         case 's':
            S = atoi(optarg);
            break;
         case 'S':
            S = atoi(optarg);
            break;

         case 'h':
         default:
                  uso();
      }
     }
         
}

int main(int argc, char **argv) {
   //avalia linha de comando
   parse_args(argc,argv);

   // verificacao da consistencia das opcoes
   if (argc == 1) {
      cout << "ERROR:\n\tnecessario escrever os nomes dos arquivos de entrada e saida" << endl;
      return 0;
   }

   // inicia registro de acesso
   string lognome = "memlog.out";
   int n = lognome.length();
   char char_array[n + 1];
   strcpy(char_array, lognome.c_str());
   iniciaMemLog(&char_array[0]);
   ativaMemLog();

   // verifica abertura dos arquivos
   ifstream input_file(name_input);
   ofstream output_file(name_output, ios::trunc);
   output_file.close();
   if (!input_file.is_open()) {
      cerr << "ERRO DE ABERTURA" << endl 
      << "O arquivo de entrada não encontrado" << endl;
      return 0;
   }

   // ----------------- INICIO DO PROGRAMA ----------------- //

   string ORDEM = "#ORDEM", TEXTO = "#TEXTO"; 
   string str, trash;
   while (input_file >> str) {
      if (str == ORDEM) {
         //armazena a ordem
      }

      if (str == TEXTO) {
         // armazena as palavras do texto
         //cria o array de words com as palavras em lowercase (palavra espaço palavra [count_words])
      }

   }

   //cria todas as new_words das words
   //ordena o array de words
   //imprime o resultado
   
   return 0;
}

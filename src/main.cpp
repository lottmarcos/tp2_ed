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

   // variáveis iniciais e auxiliares
   string ORDEM = "#ORDEM", TEXTO = "#TEXTO"; 
   bool ordemaux = false;
   string str, trash, aux;
   int diff = 'a' - 'A';

   // variáveis protagonistas
   char ordem[26];
   string texto;

   // armazena as informações nas devidas variaveis
   while (input_file >> str) {
      if (ordemaux) {
         //armazena a ordem
         ordem[0] = str[0] + diff;
         for (int i = 1; i < 26; i++) {
            input_file >> str;
            ordem[i] = str[0] + diff;
         }
      }

      if (str == ORDEM) {
         //armazena a ordem
         for (int i = 0; i < 26; i++) {
            input_file >> str;
            ordem[i] = str[0] + diff;
         }
      } 

      if (str == TEXTO) {
         // armazena as palavras do texto
         //cria o array de words com as palavras em lowercase (palavra espaço palavra [count_words])
         while (input_file >> str) {
            if (str == ORDEM) {
               ordemaux = true;
               break;
            }
            aux = fix_word(str);
            texto += aux;
            texto += " ";
         }
      }

   }
   input_file.close();

   // cria o array de palavras
   int array_counter = 0;
   int n_words = count_words(texto);
   bool add = true;
   palavra array_p[n_words];
   stringstream stream(texto);
   for (int i = 0; i < n_words; i++) {
      stream >> aux;
      for (int j = 0; j < n_words; j++) {
         if (array_p[j].nome == aux) {
            array_p[j].count++;
            add = false;
         }
      }
      if (add == true) {
         array_p[array_counter].set_word(aux);
         array_counter++;
      }

      add = true;
   }
   palavra palavras[array_counter];
   for (int i = 0; i < array_counter; i++) {
         palavras[i] = array_p[i];
   }
      
   //cria as senhas das palavras
   for (int i = 0; i < array_counter; i++) {
      palavras[i].set_senha(ordem);
   }

   //ordena o array de words
   //ordena_array(&palavras, array_counter);


   //imprime o resultado
   for (int i = 0; i < 26; i++) {
      cout << ordem[i] << " ";
   }
   cout << endl << endl;
   for (int i = 0; i < array_counter; i++) {
      cout << palavras[i].nome << ' ' << palavras[i].count << ' ' << palavras[i].senha << endl;
   }
   cout << endl << texto << endl;
   
   return 0;
}


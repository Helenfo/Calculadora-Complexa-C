#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Este programa realiza a função de uma calculadora complexa. Dado um arquivo de texto: entrada.txt, contendo uma série de expressões
complexas, este programa realiza as seguintes operações: soma, subtração, multiplicação, divisão, exponenciação ou mudança de
forma (polar para retangular ou de retangular para polar). Sendo as expressões e suas respectivas respostas retornadas em um
arquivo de texto: resultado.txt*/
#define PI 3.14159265
char *string;                 // inicializa string que recebe a expressão digitada pelo usuário
int indice = 0;               // variável que atua como indice da string
struct primeiro
    {
        float retangular_real1;       // esta variável armazena o valor real do primeiro número complexo, na forma retangular, digitado pelo usuario
        float retangular_imaginario1; // esta variável armazena o valor imaginário do primeiro número complexo, na forma retangular, digitado pelo usuário
        float modulo1;                // esta variável armazena o valor do módulo do primeiro número complexo, na forma polar, digitado pelo usuário.
        float angulo1;                // esta variável armazena o valor do ângulo do primeiro número complexo, na forma polar, digitado pelo usuário.
    };
struct segundo
    {
        float retangular_real2;       // esta variável armazena o valor real do segundo número complexo, na forma retangular, digitado pelo usuário
        float retangular_imaginario2; // esta variável armazena o valor imaginário do segundo número complexo, na forma retangular, digitado pelo usuário
        float modulo2;                // esta variável armazena o valor do módulo do segundo número complexo, na forma polar, digitado pelo usuário.
        float angulo2;                // esta variável armazena o valor do ângulo do segundo número complexo, na forma polar, digitado pelo usuário.
    };
struct resposta
 {
     float r_modulo;          // valor final do modulo do numero complexo
     float r_angulo;          // valor final do angulo do numero complexo
     float r_real;            // valor final da parte real do numero complexo na forma retangular
     float r_imaginario;      // valor final da parte imaginaria do numero complexo na forma retangular
 };

 padroniza_variavel1(struct primeiro complexo1, struct resposta *answer)
 {
      (*answer).r_modulo = complexo1.modulo1;
      (*answer).r_angulo = complexo1.angulo1;
      (*answer).r_real =  complexo1.retangular_real1;
      (*answer).r_imaginario = complexo1.retangular_imaginario1;
 }
 padroniza_variavel2(struct segundo complexo2, struct resposta *answer)
 {
      (*answer).r_modulo = complexo2.modulo2;
      (*answer).r_angulo = complexo2.angulo2;
      (*answer).r_real =  complexo2.retangular_real2;
      (*answer).r_imaginario = complexo2.retangular_imaginario2;
}
converter_polar(struct resposta *answer)
{
  float conversao_rg;
   (*answer).r_modulo = sqrt((((*answer).r_real) * ((*answer).r_real)) + (((*answer).r_imaginario) * ((*answer).r_imaginario))); // conversão de ret para polar: modulo=raiz quadrada(a^2 +b^2)
   conversao_rg = (((*answer).r_real)/((*answer).r_modulo));

   (*answer).r_angulo = acos(conversao_rg);    // conversao de ret para polar: angulo= arcos(a/modulo)

   (*answer).r_angulo =  ((*answer).r_angulo *180 )/PI;    // converte o angulo pra graus
   if(((*answer).r_imaginario<0)||(((*answer).r_imaginario<0)&&((*answer).r_real<0)))
     {
       // se estiver nos quadrantes onde cos é negativo, o ângulo deve ser negativo
       ((*answer).r_angulo)=((*answer).r_angulo)*(-1);
     }
}
converter_retangular(struct resposta *answer)
{
  float converte;
  converte =  (((*answer).r_angulo)*(PI))/180;    // converte o angulo de graus para radianos
  (*answer).r_real = ((*answer).r_modulo) * (cos(converte));          // conversão  de polar para retangular:  parte real= modulo*cos(angulo)
  (*answer).r_imaginario =  (*answer).r_modulo * (sin(converte));  // conversão de polar para retangular: parte imaginaria = modulo*sen(angulo)
}
int procura_algarismo(int *ponteiro_conta_erro)   //Esta função procura cada algarismo do número complexo digitado pelo usuário
{
   int valor=0;           //valor é a variável que armazena o valor encontrado do numero complexo.
switch(string[indice])
{
   case '0':                // se o algarismo digitado for igual a 0, a variável valor recebe 0
    {
       valor=0;
       break;
    }
   case '1':                // se o algarismo digitado for igual a 1, a variável valor recebe 1
    {
        valor=1;
        break;
    }
   case '2':                 // se o algarismo digitado for igual a 2, a variável valor recebe 2
    {
         valor=2;
         break;
    }
   case '3':                   // se o algarismo digitado for igual a 3, a variável valor recebe 3
    {
        valor=3;
        break;
    }
   case '4':                  // se o algarismo digitado for igual a 4, a variável valor recebe 4
    {
        valor=4;
        break;
    }
   case '5':                 // se o algarismo digitado for igual a 5, a variável valor recebe 5
    {
        valor=5;
        break;
    }
   case '6':                 // se o algarismo digitado for igual a 6, a variável valor recebe 6
    {
        valor=6;
        break;
    }
   case '7':                   // se o algarismo digitado for igual a 7, a variável valor recebe 7
    {
        valor=7;
        break;
    }
   case '8':                    // se o algarismo digitado for igual a 8, a variável valor recebe 8
    {
        valor=8;
        break;
    }
   case '9':                 // se o algarismo digitado for igual a 9, a variável valor recebe 9
    {
        valor=9;
        break;
    }
   case ' ':                   // se o algarismo digitado for igual a espaço, a variável valor recebe -1 que é o valor escolhido para desconsiderar na montagem do numero
    {
        valor=-1;
        break;
    }
    default:                    // se não foi nenhum dos anteriores foi porque algum caracter não permitido, como letras, foi digitado
    {
        *ponteiro_conta_erro=1;       // flag de erro
    }
}
return(valor);
}
int monta_numero(int *ponteiro_do_erro, int *ponteiro_contador)   // Esta função compõe o número complexo digitado peo usuário.
{
    int numero_pronto;             // inicializa variável que armazena o número digitado
    int potencia =10;              // essa variável auxilia na formação do número no quesito de sua grandeza de potencia.
    int conta_procura=0;           // conta o número de vezes que a função conta_procura foi chamada
    int algarismo1;                // recebe o algarismo digitado
    int sinal = 0;                 // variável que indica se o numero é positivo ou negativo

    for(;(string[indice]==' ');indice++)     // até que na expressao o proximo simbolo digitado não seja espaço, devemos averiguar se o simbolo digitado é um número, se não for, houve erro na digitação
  {
  }
  // se nao for espaço
  if(string[indice]=='-')    // se for o sinal de menos
  {
     sinal=-1;               // sinal negativo
     indice ++;              // próximo caracter da string
  }
  else if (string[indice]=='+')  // se for o sinal de mais
  {
      sinal=1;              // sinal positivo
      indice++;
  }
  else
  {
      if((*ponteiro_contador == 2)||(*ponteiro_contador ==4))   // o primeiro e o terceiro número podem não ser precedidos de sinal
     {
         *ponteiro_do_erro=1;      // se o caracter digitado antes do numero for diferente de espaço mas não foi um sinal, aciona o flag de erro
     }
     else
     {
         sinal=1;                 // se não houve sinal diggitado, o número é positivo
     }
  }
  while((string[indice]!='\0')&&(string[indice]!='+')&&(string[indice]!='i')&&(string[indice]!='p')&&(string[indice]!='-')&&(string[indice]!='/')&&(string[indice]!='*')&&(string[indice]!='^')&&(string[indice]!='='))
  {
 //enquanto nenhum caracter de encerramento do numero não foi digitado, faça a montagem do numero:

    algarismo1 = procura_algarismo(ponteiro_do_erro);    // chamada da função que encontra o algarismo digitado

    if((*ponteiro_do_erro==0)&&(algarismo1!=-1))           // se não houve erro e se o caracter digitado não for espaço
    {
      conta_procura++;                    // esta variável conta o numero de vezes que a função procura_numero foi chamada.
    }
    if((*ponteiro_do_erro==1)&&(algarismo1!=-1))            // se houve erro e se  o caracter digitado não for espaço
    {
      return (numero_pronto);                               // retorne o numero montado
    }
    if((conta_procura==1)&&(algarismo1!=-1))               // se a função de identificar o algarismo digitado foi chamada uma vez e se o algarismo não for espaço
    {
       numero_pronto= sinal*algarismo1 ;      // caso só exista um algarismo, a formula do primeiro número é dada pelo sinal*valor encontrado.
    }
    if((conta_procura>1)&&(algarismo1!=-1))     // caso exista mais de um algarismo no primeiro número, a formula do primeiro número é modificada. E se o algarismo não for espaço
      {
        if(sinal==1)                           // se for um número positivo
        {
           numero_pronto = (numero_pronto * potencia) + algarismo1;        // formula
        }
        if (sinal==-1)
        {
            numero_pronto = (numero_pronto * potencia) - algarismo1;        // formula
        }
      }
      indice++;
  }
  return(numero_pronto);
}
int main()
{
// inicialização do programa
  printf("Bem vindo a calculadora complexa!\n\n");
  int fim;                // variável que recebe o retorno da função feof, que indica se está no fim do arquivo em questão

  string = (char *) malloc(1000*sizeof(char));   // alocação dinâmica de memória para a string que recebe a expressao requerida
  if(string == NULL)                              // se não houver memória disponível no computador
    {
        printf("Erro: Memoria Insuficiente!\n");     // mostra a mensagem de erro ao usuário
        exit(1);
    }
  FILE *ponteiro_entrada;
  char expressao;
  ponteiro_entrada = fopen("entrada.txt","r+");      // abre o arquivo texto "entrada" para leitura e estrita
// verifica  se há erros
  if(ponteiro_entrada == NULL)           // se a função fopen retornar NULL, houve erro na abertura do arquivo
        {
           printf("Erro na abertura do arquivo. Fim de programa.\n");
           exit(1);
        }

  FILE *ponteiro_resultados;
  char resultado;
  ponteiro_resultados = fopen("saida.txt","wb");
// verifica  se há erros
  if(ponteiro_resultados== NULL)           // se a função fopen retornar NULL, houve erro na abertura do arquivo
        {
            printf("Erro na abertura do arquivo. Fim de programa.\n");
            exit(1);
        }

//inicialização das variáveis

    struct primeiro complexo1;
    struct segundo complexo2;
    struct resposta answer2;

    int FIRSTNUMBER, SECONDNUMBER, THIRDNUMBER, FOURTHNUMBER;           // variáveis que indicam o primeiro e segundo número digitado de cada operando
    int contagem_do_erro=0;                  // variável que indica se houve erro na expressao de entrada
    int operacoes=0;                         // esta variável indica qual foi a operação escolhida pelo usuário
    int forma_do_primeiro_numero, forma_do_segundo_numero = 0;
     // estas variáveis indicam qual foi a forma digitado pelo usuario. Se =1 a forma é a POLAR, se =2 a forma é RETANGULAR

    int conta_numeros ;                      // esta variável conta a quantidade de números de cada expressao de entrada

 while(fim= feof(ponteiro_entrada)==0)       // enquanto não tiver chegado ao fim do arquivo de entrada , leia as strings
 {
     expressao = fgets(string,100000,ponteiro_entrada); // lê a string no arquivo entrada, a string lida será armazenada na string
// montagem dos números:
//primeiro número:

     conta_numeros = 1;                           // esta no primeiro número
     FIRSTNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da função que monta o numero
//segundo número
     conta_numeros = 2;                           // esta no segundo número
     SECONDNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da função que monta o numero

// se está no segundo numero, este numero pode ser imaginario
  if(string[indice]=='i')
    {
        complexo1.retangular_imaginario1 = ceil(SECONDNUMBER);      // o segundo numero é imaginario
        complexo1.retangular_real1 = ceil(FIRSTNUMBER);            // o primeiro numero é real
        forma_do_primeiro_numero = 2;                        // a forma do primeiro numero é retangular
        indice++;                                   // próximo valor da string
    }
  else if(string[indice]=='p')
   // o numero esta na forma polar
    {
        complexo1.modulo1 = ceil(FIRSTNUMBER);         // o primeiro numero arredondado (função ceil)é o modulo do numero complexo
        complexo1.angulo1 = ceil(SECONDNUMBER);        // o segundo numeroarredondado (função ceil) é o angulo do numero complexo
        forma_do_primeiro_numero = 1;                  // indica que o primeiro numero esta na forma polar
        indice++;                                      // próximo valor da string
    }
  else
  {
      contagem_do_erro = 1;             // flag de erro
  }
    //terceiro número
  conta_numeros = 3;          // esta no terceiro número
  for(;(string[indice]==' ');indice++)     // até que na expressao o proximo simbolo digitado não seja espaço, devemos averiguar se o simbolo digitado é um número, se não for, houve erro na digitação
    {
    }
// se nao for espaço
  if((string[indice]!='+')&&(string[indice]!='-')&&(string[indice]!='*')&&(string[indice]!='/')&&(string[indice]!='=')&&(string[indice]!='^'))
    {
// se não houve a digitação da operação desejada, aciona o flag de erro.
      contagem_do_erro = 1;
    }
  else      // se a operação desejada f] digitada, armazena o indice da operação  e vai para o proximo caracter da string
    {
      operacoes=indice;
      if(string[indice]!='=')
      {
                indice++;
      }
    }
// só havera um terceiro numero quando a operação selecionada não foi a de conversão
  if(string[operacoes]!='=')
    {
      THIRDNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da função que monta o numero
    }
// quarto numero
conta_numeros = 4;              // esta no quarto numero
// só havera um quarto numero quando a operacao selecionada não for a quinta ou a sexta
  if((string[operacoes]!='^')&&(string[operacoes]!='='))
    {
      FOURTHNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da função que monta o numero
// se está no quarto numero, este numero  pode ser imaginario
  if(string[indice]=='i')
    {
// se este for um número imaginario
      complexo2.retangular_imaginario2 = ceil(FOURTHNUMBER);    // o quarto numero digitado é imaginario
      complexo2.retangular_real2 = ceil(THIRDNUMBER);          // o terceiro numero digitado é real
      forma_do_segundo_numero =2 ;                           // se a forma digitada pelo usuário foi a retangular, esta variavel é igual a 2
      indice++;
    }
  else if(string[indice]=='p')
      {
          complexo2.modulo2 = ceil(THIRDNUMBER);            // o terceiro numero digitado é o modulo do numero complexo na forma polar
          complexo2.angulo2 = ceil(FOURTHNUMBER);           // o quarto numero digitado é o angulo do numero complexo na forma polar
          forma_do_segundo_numero =1 ;                // se a forma digitada pelo usuário foi a polar, esta variavel é igual a 1
        indice ++;
      }
else
{
    contagem_do_erro = 1;
}
    }
    for(;(string[indice]==' ');indice++)     // até que na expressao o proximo simbolo digitado não seja espaço, devemos averiguar se o simbolo digitado é um número, se não for, houve erro na digitação
    {
    }
    // se nao for espaço
   if(string[indice]=='=')
   {
   }
   else
    {
        contagem_do_erro=1;               // aciona o flag de erro
    }
//verificação de erro
  if(contagem_do_erro==1)  // houve eerro
    {
        fprintf(ponteiro_resultados,"ERRO!\r\n");
        contagem_do_erro = 0;     // reinicia o flag de erro
    }
  else     // se não houve erro pode enviar as expressões de entrada para o arquivo de respostas
    {
        if(forma_do_primeiro_numero==2)
        {
            fprintf(ponteiro_resultados,"%.2f", complexo1.retangular_real1);  // imprime no arquivo de resposta o primeiro número
            if((complexo1.retangular_imaginario1>0)||(complexo1.retangular_imaginario1==0))
// se o segundo número digitado for maior ou igual a zero, a forma de impressão deste número é como a dada abaixo:
          {
               fprintf(ponteiro_resultados," +%.2fi", complexo1.retangular_imaginario1);
          }
        else
          {
               fprintf(ponteiro_resultados," %.2fi", complexo1.retangular_imaginario1);
          }
        }
        if(forma_do_primeiro_numero==1)
        {
            fprintf(ponteiro_resultados,"%.2f", complexo1.modulo1);  // imprime no arquivo de resposta o primeiro número
                 if((complexo1.angulo1>0)||(complexo1.angulo1==0))
// se o segundo número digitado for maior ou igual a zero, a forma de impressão deste número é como a dada abaixo:
        {
              fprintf(ponteiro_resultados," +%.2fp", complexo1.angulo1);
        }
      else
        {
               fprintf(ponteiro_resultados," %.2fp", complexo1.angulo1);
        }
        }
              fprintf(ponteiro_resultados," %c ", string[operacoes]);

        if(forma_do_segundo_numero==2)
        {
            fprintf(ponteiro_resultados,"%.2f", complexo2.retangular_real2);  // imprime no arquivo de resposta o terceiro número
                  if((complexo2.retangular_imaginario2>0)||(complexo2.retangular_imaginario2==0))
      {
// se o quarto número digitado for maior ou igual a zero, a forma de impressão deste número é como a dada abaixo:
          fprintf(ponteiro_resultados," +%.2fi", complexo2.retangular_imaginario2);
      }
      else
      {
          fprintf(ponteiro_resultados,"%.2fi", complexo2.retangular_imaginario2);
      }
                             fprintf(ponteiro_resultados," %c", string[indice]);

        }
        if(forma_do_segundo_numero==1)
        {
            fprintf(ponteiro_resultados,"%.2f", complexo2.modulo2);  // imprime no arquivo de resposta o terceiro número
                    if((complexo2.angulo2>0)||(complexo2.angulo2>0))
        {
// se o quarto número digitado for maior ou igual a zero, a forma de impressão deste número é como a dada abaixo:
            fprintf(ponteiro_resultados," +%.2fp", complexo2.angulo2);
        }
        else
        {
            fprintf(ponteiro_resultados," +%.2fp", complexo2.angulo2);
        }
                               fprintf(ponteiro_resultados," %c", string[indice]);
        }
// a realização das operações

 if((string[operacoes]=='+')||(string[operacoes]=='-'))
  {
    // se a operação desejada for de soma ou de subtração, o numero digitado deve estar na forma retangular:
    if(forma_do_primeiro_numero==1)    // se esta na forma polar, converta para a forma retangular
          {
               padroniza_variavel1(complexo1, &answer2);   // chamada da função que padroniza/prepara as variáveis para a função de conversão que virá em sequência
               converter_retangular(&answer2);             // chamada da função que converte as variáveis de entrada da forma polar para a retangular
               complexo1.retangular_real1 = answer2.r_real;
               complexo1.retangular_imaginario1 =  answer2.r_imaginario;
          }
    if(forma_do_segundo_numero==1)    // se esta na forma polar, converta para a forma retangular
          {
               padroniza_variavel2(complexo2, &answer2);   // chamada da função que padroniza/prepara as variáveis para a função de conversão que virá em sequência
               converter_retangular(&answer2);             // chamada da função que converte as variáveis de entrada da forma polar para a retangular
               complexo2.retangular_real2 = answer2.r_real;
               complexo2.retangular_imaginario2 = answer2.r_imaginario;
          }
  }
  if((string[operacoes]=='*')||(string[operacoes]=='/')||(string[operacoes]=='^'))
  {
      // se a operação desejada for de multiplicação, divisão ou exponenciação, o numero digitado deve estar na forma polar
        if (forma_do_primeiro_numero==2)        // se esta da forma retangular, converta para  forma polar
            {
               padroniza_variavel1(complexo1,&answer2);   // chamada da função que padroniza/prepara as variáveis para a função de conversão que virá em sequência
               converter_polar(&answer2);                 // chamada da função que converte as variáveis de entrada da forma retangular para a polar
               complexo1.modulo1 = answer2.r_modulo;
               complexo1.angulo1 = answer2.r_angulo;
            }
        if (forma_do_segundo_numero==2)        // se esta da forma retangular, converta para  forma polar
            {
               padroniza_variavel2(complexo2,&answer2);   // chamada da função que padroniza/prepara as variáveis para a função de conversão que virá em sequência
               converter_polar(&answer2);                 // chamada da função que converte as variáveis de entrada da forma retangular para a polar
               complexo2.modulo2 = answer2.r_modulo;
               complexo2.angulo2 = answer2.r_angulo;
            }
  }
  switch (string[operacoes])
    {
     case '+':     // soma foi a operação escolhida
      {
          answer2.r_imaginario = complexo2.retangular_imaginario2 + complexo1.retangular_imaginario1;   // respota da parte imaginaria = imaginaria 1 + imaginária 2
          answer2.r_real = complexo2.retangular_real2 + complexo1.retangular_real1;                      // resposta da parte real = real1 + real2.
    if(answer2.r_imaginario>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)  // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_polar(&answer2);      // chamada da função que converte para polar
              if(answer2.r_angulo>0)
              {
                fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                 fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se está na forma polar
          {
              converter_polar(&answer2);      // chamada da função que converte para polar
              fprintf(ponteiro_resultados," %.2f +%.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
          else      // está na forma retangular
          {
               fprintf(ponteiro_resultados," %.2f +%.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
    }
    else
    {
        if(forma_do_primeiro_numero != forma_do_segundo_numero)  // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_polar(&answer2);      // chamada da função que converte para polar
              if(answer2.r_angulo>0)
              {
                fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                 fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se está na forma polar
          {
              converter_polar(&answer2);      // chamada da função que converte para polar
              fprintf(ponteiro_resultados," %.2f %.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
          else      // está na forma retangular
          {
               fprintf(ponteiro_resultados," %.2f %.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
    }
          break;
      }
     case '-':       // a subtração foi a operação
      {

          answer2.r_imaginario = complexo1.retangular_imaginario1 - complexo2.retangular_imaginario2;   // respota da parte imaginaria = imaginaria 1 + imaginária 2
          answer2.r_real = complexo1.retangular_real1 - complexo2.retangular_real2;                      // resposta da parte real = real1 + real2.
if(answer2.r_imaginario>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
            {
              converter_polar(&answer2);      // chamada da função que converte para polar
              if(answer2.r_angulo>0)
                {
                      fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
                }
              else
              {
                    fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se está na forma polar
          {
              converter_polar(&answer2);      // chamada da função que converte para polar
              fprintf(ponteiro_resultados," %.2f +%.2fp\r\n",  answer2.r_modulo, answer2.r_angulo);
          }
          else          // esta na forma retangular
          {
               fprintf(ponteiro_resultados," %.2f +%.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
}
else
{
             if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
            {
              converter_polar(&answer2);      // chamada da função que converte para polar
              if(answer2.r_angulo>0)
                {
                      fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
                }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se está na forma polar
          {
              converter_polar(&answer2);      // chamada da função que converte para polar
              fprintf(ponteiro_resultados," %.2f %.2fp\r\n",  answer2.r_modulo, answer2.r_angulo);
          }
          else          // esta na forma retangular
          {
               fprintf(ponteiro_resultados," %.2f %.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
}
          break;
      }
     case '*':        // a multiplicação foi a operação escolhida
      {
            answer2.r_modulo = (complexo1.modulo1) * (complexo2.modulo2);     // multiplica-se o modulo do primeiro termo pelo modulo do segundo termo para obter o modulo equivalente.
            answer2.r_angulo = (complexo1.angulo1) + (complexo2.angulo2);      // soma-se o angulo do primeiro termo ao ângulo do seundo termo para obter o ângulo equivalente.
if(answer2.r_angulo>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);       // chamada da função que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                    fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==2)  // ou se está na forma retangular
          {
            converter_retangular(&answer2);   // chamada da função que converte para a forma retangular
            fprintf(ponteiro_resultados," %.2f +%.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
          else        // esta na forma polar
          {
              fprintf(ponteiro_resultados," %.2f +%.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
}
else
{
              if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);       // chamada da função que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                    fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==2)  // ou se está na forma retangular
          {
            converter_retangular(&answer2);   // chamada da função que converte para a forma retangular
            fprintf(ponteiro_resultados," %.2f %.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
          else        // esta na forma polar
          {
              fprintf(ponteiro_resultados," %.2f %.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
}
            break;
      }
     case'/':     // a divisão foi a operação escolhida
      {

            answer2.r_modulo = (complexo1.modulo1) / (complexo2.modulo2);     // multiplica-se o modulo do primeiro termo pelo modulo do segundo termo para obter o modulo equivalente.
            answer2.r_angulo = (complexo1.angulo1) - (complexo2.angulo2);      // soma-se o angulo do primeiro termo ao ângulo do seundo termo para obter o ângulo equivalente.
if(answer2.r_angulo>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);   //chamada da função que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                     fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
         else if(forma_do_primeiro_numero==2)  // ou se está na forma retangular
         {
              converter_retangular(&answer2);
              fprintf(ponteiro_resultados," %.2f +%.2fi\r\n", answer2.r_real, answer2.r_imaginario);
         }
         else   // esta na forma polar
          {
              fprintf(ponteiro_resultados," %.2f +%.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
}
else
{
              if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);   //chamada da função que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                     fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
         else if(forma_do_primeiro_numero==2)  // ou se está na forma retangular
         {
              converter_retangular(&answer2);
              fprintf(ponteiro_resultados," %.2f %.2fi\r\n", answer2.r_real, answer2.r_imaginario);
         }
         else   // esta na forma polar
          {
              fprintf(ponteiro_resultados," %.2f %.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
}
            break;
      }
     case '^':     // exponenciação foi a operação escolhida
      {
            answer2.r_modulo = pow(complexo1.modulo1, complexo2.modulo2);  // a função pow tem como base a variável modulo1 e eleva ela ao expoente, chamado modulo2
            answer2.r_angulo = complexo1.angulo1 * complexo2.modulo2;       // angulo final= primeiro angulo* segundo angulo

          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);   // chamada da função que converte para a forma retangular
              fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
          }
          else if(forma_do_primeiro_numero==2) // ou se está na forma retangular
          {
             converter_retangular(&answer2);   // chamada da função que converte para a forma retangular
             fprintf(ponteiro_resultados," %.2f +%.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
          else   // esta na forma polar
          {
              fprintf(ponteiro_resultados," %.2f + %.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
            break;
      }
     default :      // a conversão de formas foi a operação escolhida
      {
            if (forma_do_primeiro_numero==2)        // se esta da forma retangular, converta para  forma polar
            {
               padroniza_variavel1(complexo1, &answer2);    // chamada da função que padroniza/prepara as variáveis para a função de conversão que vem a seguir
               converter_polar(&answer2);                    // chamada da função que converte para a forma polar
               complexo1.modulo1 = answer2.r_modulo;
               complexo1.angulo1 = answer2.r_angulo;
               fprintf(ponteiro_resultados,"%.2f + %.2fp\r\n", complexo1.modulo1, complexo1.angulo1);
            }
            if(forma_do_primeiro_numero==1)                      // a forma digitada pelo usuário foi a polar logo, a conversão é da polar para a retangular
            {
               padroniza_variavel1(complexo1, &answer2);    // chamada da função que padroniza/prepara as variáveis para a função de conversão que vem a seguir
               converter_retangular(&answer2);              // chamada da função que converte para a forma retangular
               complexo1.retangular_real1 = answer2.r_real;
               complexo1.retangular_imaginario1 = answer2.r_imaginario;
                              fprintf(ponteiro_resultados,"%.2f + %.2fi\r\n",complexo1.retangular_real1, complexo1.retangular_imaginario1);

            }
      }
    }
    }
      indice=0;        // para ir para a próxima string do arquivo zere o indice da string de leitura
      forma_do_primeiro_numero, forma_do_segundo_numero = 0;
     //  Reinicia as variáveis  que indicam qual foi a forma digitado pelo usuario. Se =1 a forma é a POLAR, se =2 a forma é RETANGULAR
}
    fclose(ponteiro_entrada);     // fecha arquivo de entradas
    fclose(ponteiro_resultados);  // fecha arquivo de resultados
return 0;
}

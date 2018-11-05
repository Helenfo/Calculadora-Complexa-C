#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Este programa realiza a fun��o de uma calculadora complexa. Dado um arquivo de texto: entrada.txt, contendo uma s�rie de express�es
complexas, este programa realiza as seguintes opera��es: soma, subtra��o, multiplica��o, divis�o, exponencia��o ou mudan�a de
forma (polar para retangular ou de retangular para polar). Sendo as express�es e suas respectivas respostas retornadas em um
arquivo de texto: resultado.txt*/
#define PI 3.14159265
char *string;                 // inicializa string que recebe a express�o digitada pelo usu�rio
int indice = 0;               // vari�vel que atua como indice da string
struct primeiro
    {
        float retangular_real1;       // esta vari�vel armazena o valor real do primeiro n�mero complexo, na forma retangular, digitado pelo usuario
        float retangular_imaginario1; // esta vari�vel armazena o valor imagin�rio do primeiro n�mero complexo, na forma retangular, digitado pelo usu�rio
        float modulo1;                // esta vari�vel armazena o valor do m�dulo do primeiro n�mero complexo, na forma polar, digitado pelo usu�rio.
        float angulo1;                // esta vari�vel armazena o valor do �ngulo do primeiro n�mero complexo, na forma polar, digitado pelo usu�rio.
    };
struct segundo
    {
        float retangular_real2;       // esta vari�vel armazena o valor real do segundo n�mero complexo, na forma retangular, digitado pelo usu�rio
        float retangular_imaginario2; // esta vari�vel armazena o valor imagin�rio do segundo n�mero complexo, na forma retangular, digitado pelo usu�rio
        float modulo2;                // esta vari�vel armazena o valor do m�dulo do segundo n�mero complexo, na forma polar, digitado pelo usu�rio.
        float angulo2;                // esta vari�vel armazena o valor do �ngulo do segundo n�mero complexo, na forma polar, digitado pelo usu�rio.
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
   (*answer).r_modulo = sqrt((((*answer).r_real) * ((*answer).r_real)) + (((*answer).r_imaginario) * ((*answer).r_imaginario))); // convers�o de ret para polar: modulo=raiz quadrada(a^2 +b^2)
   conversao_rg = (((*answer).r_real)/((*answer).r_modulo));

   (*answer).r_angulo = acos(conversao_rg);    // conversao de ret para polar: angulo= arcos(a/modulo)

   (*answer).r_angulo =  ((*answer).r_angulo *180 )/PI;    // converte o angulo pra graus
   if(((*answer).r_imaginario<0)||(((*answer).r_imaginario<0)&&((*answer).r_real<0)))
     {
       // se estiver nos quadrantes onde cos � negativo, o �ngulo deve ser negativo
       ((*answer).r_angulo)=((*answer).r_angulo)*(-1);
     }
}
converter_retangular(struct resposta *answer)
{
  float converte;
  converte =  (((*answer).r_angulo)*(PI))/180;    // converte o angulo de graus para radianos
  (*answer).r_real = ((*answer).r_modulo) * (cos(converte));          // convers�o  de polar para retangular:  parte real= modulo*cos(angulo)
  (*answer).r_imaginario =  (*answer).r_modulo * (sin(converte));  // convers�o de polar para retangular: parte imaginaria = modulo*sen(angulo)
}
int procura_algarismo(int *ponteiro_conta_erro)   //Esta fun��o procura cada algarismo do n�mero complexo digitado pelo usu�rio
{
   int valor=0;           //valor � a vari�vel que armazena o valor encontrado do numero complexo.
switch(string[indice])
{
   case '0':                // se o algarismo digitado for igual a 0, a vari�vel valor recebe 0
    {
       valor=0;
       break;
    }
   case '1':                // se o algarismo digitado for igual a 1, a vari�vel valor recebe 1
    {
        valor=1;
        break;
    }
   case '2':                 // se o algarismo digitado for igual a 2, a vari�vel valor recebe 2
    {
         valor=2;
         break;
    }
   case '3':                   // se o algarismo digitado for igual a 3, a vari�vel valor recebe 3
    {
        valor=3;
        break;
    }
   case '4':                  // se o algarismo digitado for igual a 4, a vari�vel valor recebe 4
    {
        valor=4;
        break;
    }
   case '5':                 // se o algarismo digitado for igual a 5, a vari�vel valor recebe 5
    {
        valor=5;
        break;
    }
   case '6':                 // se o algarismo digitado for igual a 6, a vari�vel valor recebe 6
    {
        valor=6;
        break;
    }
   case '7':                   // se o algarismo digitado for igual a 7, a vari�vel valor recebe 7
    {
        valor=7;
        break;
    }
   case '8':                    // se o algarismo digitado for igual a 8, a vari�vel valor recebe 8
    {
        valor=8;
        break;
    }
   case '9':                 // se o algarismo digitado for igual a 9, a vari�vel valor recebe 9
    {
        valor=9;
        break;
    }
   case ' ':                   // se o algarismo digitado for igual a espa�o, a vari�vel valor recebe -1 que � o valor escolhido para desconsiderar na montagem do numero
    {
        valor=-1;
        break;
    }
    default:                    // se n�o foi nenhum dos anteriores foi porque algum caracter n�o permitido, como letras, foi digitado
    {
        *ponteiro_conta_erro=1;       // flag de erro
    }
}
return(valor);
}
int monta_numero(int *ponteiro_do_erro, int *ponteiro_contador)   // Esta fun��o comp�e o n�mero complexo digitado peo usu�rio.
{
    int numero_pronto;             // inicializa vari�vel que armazena o n�mero digitado
    int potencia =10;              // essa vari�vel auxilia na forma��o do n�mero no quesito de sua grandeza de potencia.
    int conta_procura=0;           // conta o n�mero de vezes que a fun��o conta_procura foi chamada
    int algarismo1;                // recebe o algarismo digitado
    int sinal = 0;                 // vari�vel que indica se o numero � positivo ou negativo

    for(;(string[indice]==' ');indice++)     // at� que na expressao o proximo simbolo digitado n�o seja espa�o, devemos averiguar se o simbolo digitado � um n�mero, se n�o for, houve erro na digita��o
  {
  }
  // se nao for espa�o
  if(string[indice]=='-')    // se for o sinal de menos
  {
     sinal=-1;               // sinal negativo
     indice ++;              // pr�ximo caracter da string
  }
  else if (string[indice]=='+')  // se for o sinal de mais
  {
      sinal=1;              // sinal positivo
      indice++;
  }
  else
  {
      if((*ponteiro_contador == 2)||(*ponteiro_contador ==4))   // o primeiro e o terceiro n�mero podem n�o ser precedidos de sinal
     {
         *ponteiro_do_erro=1;      // se o caracter digitado antes do numero for diferente de espa�o mas n�o foi um sinal, aciona o flag de erro
     }
     else
     {
         sinal=1;                 // se n�o houve sinal diggitado, o n�mero � positivo
     }
  }
  while((string[indice]!='\0')&&(string[indice]!='+')&&(string[indice]!='i')&&(string[indice]!='p')&&(string[indice]!='-')&&(string[indice]!='/')&&(string[indice]!='*')&&(string[indice]!='^')&&(string[indice]!='='))
  {
 //enquanto nenhum caracter de encerramento do numero n�o foi digitado, fa�a a montagem do numero:

    algarismo1 = procura_algarismo(ponteiro_do_erro);    // chamada da fun��o que encontra o algarismo digitado

    if((*ponteiro_do_erro==0)&&(algarismo1!=-1))           // se n�o houve erro e se o caracter digitado n�o for espa�o
    {
      conta_procura++;                    // esta vari�vel conta o numero de vezes que a fun��o procura_numero foi chamada.
    }
    if((*ponteiro_do_erro==1)&&(algarismo1!=-1))            // se houve erro e se  o caracter digitado n�o for espa�o
    {
      return (numero_pronto);                               // retorne o numero montado
    }
    if((conta_procura==1)&&(algarismo1!=-1))               // se a fun��o de identificar o algarismo digitado foi chamada uma vez e se o algarismo n�o for espa�o
    {
       numero_pronto= sinal*algarismo1 ;      // caso s� exista um algarismo, a formula do primeiro n�mero � dada pelo sinal*valor encontrado.
    }
    if((conta_procura>1)&&(algarismo1!=-1))     // caso exista mais de um algarismo no primeiro n�mero, a formula do primeiro n�mero � modificada. E se o algarismo n�o for espa�o
      {
        if(sinal==1)                           // se for um n�mero positivo
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
// inicializa��o do programa
  printf("Bem vindo a calculadora complexa!\n\n");
  int fim;                // vari�vel que recebe o retorno da fun��o feof, que indica se est� no fim do arquivo em quest�o

  string = (char *) malloc(1000*sizeof(char));   // aloca��o din�mica de mem�ria para a string que recebe a expressao requerida
  if(string == NULL)                              // se n�o houver mem�ria dispon�vel no computador
    {
        printf("Erro: Memoria Insuficiente!\n");     // mostra a mensagem de erro ao usu�rio
        exit(1);
    }
  FILE *ponteiro_entrada;
  char expressao;
  ponteiro_entrada = fopen("entrada.txt","r+");      // abre o arquivo texto "entrada" para leitura e estrita
// verifica  se h� erros
  if(ponteiro_entrada == NULL)           // se a fun��o fopen retornar NULL, houve erro na abertura do arquivo
        {
           printf("Erro na abertura do arquivo. Fim de programa.\n");
           exit(1);
        }

  FILE *ponteiro_resultados;
  char resultado;
  ponteiro_resultados = fopen("saida.txt","wb");
// verifica  se h� erros
  if(ponteiro_resultados== NULL)           // se a fun��o fopen retornar NULL, houve erro na abertura do arquivo
        {
            printf("Erro na abertura do arquivo. Fim de programa.\n");
            exit(1);
        }

//inicializa��o das vari�veis

    struct primeiro complexo1;
    struct segundo complexo2;
    struct resposta answer2;

    int FIRSTNUMBER, SECONDNUMBER, THIRDNUMBER, FOURTHNUMBER;           // vari�veis que indicam o primeiro e segundo n�mero digitado de cada operando
    int contagem_do_erro=0;                  // vari�vel que indica se houve erro na expressao de entrada
    int operacoes=0;                         // esta vari�vel indica qual foi a opera��o escolhida pelo usu�rio
    int forma_do_primeiro_numero, forma_do_segundo_numero = 0;
     // estas vari�veis indicam qual foi a forma digitado pelo usuario. Se =1 a forma � a POLAR, se =2 a forma � RETANGULAR

    int conta_numeros ;                      // esta vari�vel conta a quantidade de n�meros de cada expressao de entrada

 while(fim= feof(ponteiro_entrada)==0)       // enquanto n�o tiver chegado ao fim do arquivo de entrada , leia as strings
 {
     expressao = fgets(string,100000,ponteiro_entrada); // l� a string no arquivo entrada, a string lida ser� armazenada na string
// montagem dos n�meros:
//primeiro n�mero:

     conta_numeros = 1;                           // esta no primeiro n�mero
     FIRSTNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da fun��o que monta o numero
//segundo n�mero
     conta_numeros = 2;                           // esta no segundo n�mero
     SECONDNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da fun��o que monta o numero

// se est� no segundo numero, este numero pode ser imaginario
  if(string[indice]=='i')
    {
        complexo1.retangular_imaginario1 = ceil(SECONDNUMBER);      // o segundo numero � imaginario
        complexo1.retangular_real1 = ceil(FIRSTNUMBER);            // o primeiro numero � real
        forma_do_primeiro_numero = 2;                        // a forma do primeiro numero � retangular
        indice++;                                   // pr�ximo valor da string
    }
  else if(string[indice]=='p')
   // o numero esta na forma polar
    {
        complexo1.modulo1 = ceil(FIRSTNUMBER);         // o primeiro numero arredondado (fun��o ceil)� o modulo do numero complexo
        complexo1.angulo1 = ceil(SECONDNUMBER);        // o segundo numeroarredondado (fun��o ceil) � o angulo do numero complexo
        forma_do_primeiro_numero = 1;                  // indica que o primeiro numero esta na forma polar
        indice++;                                      // pr�ximo valor da string
    }
  else
  {
      contagem_do_erro = 1;             // flag de erro
  }
    //terceiro n�mero
  conta_numeros = 3;          // esta no terceiro n�mero
  for(;(string[indice]==' ');indice++)     // at� que na expressao o proximo simbolo digitado n�o seja espa�o, devemos averiguar se o simbolo digitado � um n�mero, se n�o for, houve erro na digita��o
    {
    }
// se nao for espa�o
  if((string[indice]!='+')&&(string[indice]!='-')&&(string[indice]!='*')&&(string[indice]!='/')&&(string[indice]!='=')&&(string[indice]!='^'))
    {
// se n�o houve a digita��o da opera��o desejada, aciona o flag de erro.
      contagem_do_erro = 1;
    }
  else      // se a opera��o desejada f] digitada, armazena o indice da opera��o  e vai para o proximo caracter da string
    {
      operacoes=indice;
      if(string[indice]!='=')
      {
                indice++;
      }
    }
// s� havera um terceiro numero quando a opera��o selecionada n�o foi a de convers�o
  if(string[operacoes]!='=')
    {
      THIRDNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da fun��o que monta o numero
    }
// quarto numero
conta_numeros = 4;              // esta no quarto numero
// s� havera um quarto numero quando a operacao selecionada n�o for a quinta ou a sexta
  if((string[operacoes]!='^')&&(string[operacoes]!='='))
    {
      FOURTHNUMBER = monta_numero(&contagem_do_erro, &conta_numeros);  // chamada da fun��o que monta o numero
// se est� no quarto numero, este numero  pode ser imaginario
  if(string[indice]=='i')
    {
// se este for um n�mero imaginario
      complexo2.retangular_imaginario2 = ceil(FOURTHNUMBER);    // o quarto numero digitado � imaginario
      complexo2.retangular_real2 = ceil(THIRDNUMBER);          // o terceiro numero digitado � real
      forma_do_segundo_numero =2 ;                           // se a forma digitada pelo usu�rio foi a retangular, esta variavel � igual a 2
      indice++;
    }
  else if(string[indice]=='p')
      {
          complexo2.modulo2 = ceil(THIRDNUMBER);            // o terceiro numero digitado � o modulo do numero complexo na forma polar
          complexo2.angulo2 = ceil(FOURTHNUMBER);           // o quarto numero digitado � o angulo do numero complexo na forma polar
          forma_do_segundo_numero =1 ;                // se a forma digitada pelo usu�rio foi a polar, esta variavel � igual a 1
        indice ++;
      }
else
{
    contagem_do_erro = 1;
}
    }
    for(;(string[indice]==' ');indice++)     // at� que na expressao o proximo simbolo digitado n�o seja espa�o, devemos averiguar se o simbolo digitado � um n�mero, se n�o for, houve erro na digita��o
    {
    }
    // se nao for espa�o
   if(string[indice]=='=')
   {
   }
   else
    {
        contagem_do_erro=1;               // aciona o flag de erro
    }
//verifica��o de erro
  if(contagem_do_erro==1)  // houve eerro
    {
        fprintf(ponteiro_resultados,"ERRO!\r\n");
        contagem_do_erro = 0;     // reinicia o flag de erro
    }
  else     // se n�o houve erro pode enviar as express�es de entrada para o arquivo de respostas
    {
        if(forma_do_primeiro_numero==2)
        {
            fprintf(ponteiro_resultados,"%.2f", complexo1.retangular_real1);  // imprime no arquivo de resposta o primeiro n�mero
            if((complexo1.retangular_imaginario1>0)||(complexo1.retangular_imaginario1==0))
// se o segundo n�mero digitado for maior ou igual a zero, a forma de impress�o deste n�mero � como a dada abaixo:
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
            fprintf(ponteiro_resultados,"%.2f", complexo1.modulo1);  // imprime no arquivo de resposta o primeiro n�mero
                 if((complexo1.angulo1>0)||(complexo1.angulo1==0))
// se o segundo n�mero digitado for maior ou igual a zero, a forma de impress�o deste n�mero � como a dada abaixo:
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
            fprintf(ponteiro_resultados,"%.2f", complexo2.retangular_real2);  // imprime no arquivo de resposta o terceiro n�mero
                  if((complexo2.retangular_imaginario2>0)||(complexo2.retangular_imaginario2==0))
      {
// se o quarto n�mero digitado for maior ou igual a zero, a forma de impress�o deste n�mero � como a dada abaixo:
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
            fprintf(ponteiro_resultados,"%.2f", complexo2.modulo2);  // imprime no arquivo de resposta o terceiro n�mero
                    if((complexo2.angulo2>0)||(complexo2.angulo2>0))
        {
// se o quarto n�mero digitado for maior ou igual a zero, a forma de impress�o deste n�mero � como a dada abaixo:
            fprintf(ponteiro_resultados," +%.2fp", complexo2.angulo2);
        }
        else
        {
            fprintf(ponteiro_resultados," +%.2fp", complexo2.angulo2);
        }
                               fprintf(ponteiro_resultados," %c", string[indice]);
        }
// a realiza��o das opera��es

 if((string[operacoes]=='+')||(string[operacoes]=='-'))
  {
    // se a opera��o desejada for de soma ou de subtra��o, o numero digitado deve estar na forma retangular:
    if(forma_do_primeiro_numero==1)    // se esta na forma polar, converta para a forma retangular
          {
               padroniza_variavel1(complexo1, &answer2);   // chamada da fun��o que padroniza/prepara as vari�veis para a fun��o de convers�o que vir� em sequ�ncia
               converter_retangular(&answer2);             // chamada da fun��o que converte as vari�veis de entrada da forma polar para a retangular
               complexo1.retangular_real1 = answer2.r_real;
               complexo1.retangular_imaginario1 =  answer2.r_imaginario;
          }
    if(forma_do_segundo_numero==1)    // se esta na forma polar, converta para a forma retangular
          {
               padroniza_variavel2(complexo2, &answer2);   // chamada da fun��o que padroniza/prepara as vari�veis para a fun��o de convers�o que vir� em sequ�ncia
               converter_retangular(&answer2);             // chamada da fun��o que converte as vari�veis de entrada da forma polar para a retangular
               complexo2.retangular_real2 = answer2.r_real;
               complexo2.retangular_imaginario2 = answer2.r_imaginario;
          }
  }
  if((string[operacoes]=='*')||(string[operacoes]=='/')||(string[operacoes]=='^'))
  {
      // se a opera��o desejada for de multiplica��o, divis�o ou exponencia��o, o numero digitado deve estar na forma polar
        if (forma_do_primeiro_numero==2)        // se esta da forma retangular, converta para  forma polar
            {
               padroniza_variavel1(complexo1,&answer2);   // chamada da fun��o que padroniza/prepara as vari�veis para a fun��o de convers�o que vir� em sequ�ncia
               converter_polar(&answer2);                 // chamada da fun��o que converte as vari�veis de entrada da forma retangular para a polar
               complexo1.modulo1 = answer2.r_modulo;
               complexo1.angulo1 = answer2.r_angulo;
            }
        if (forma_do_segundo_numero==2)        // se esta da forma retangular, converta para  forma polar
            {
               padroniza_variavel2(complexo2,&answer2);   // chamada da fun��o que padroniza/prepara as vari�veis para a fun��o de convers�o que vir� em sequ�ncia
               converter_polar(&answer2);                 // chamada da fun��o que converte as vari�veis de entrada da forma retangular para a polar
               complexo2.modulo2 = answer2.r_modulo;
               complexo2.angulo2 = answer2.r_angulo;
            }
  }
  switch (string[operacoes])
    {
     case '+':     // soma foi a opera��o escolhida
      {
          answer2.r_imaginario = complexo2.retangular_imaginario2 + complexo1.retangular_imaginario1;   // respota da parte imaginaria = imaginaria 1 + imagin�ria 2
          answer2.r_real = complexo2.retangular_real2 + complexo1.retangular_real1;                      // resposta da parte real = real1 + real2.
    if(answer2.r_imaginario>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)  // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
              if(answer2.r_angulo>0)
              {
                fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                 fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se est� na forma polar
          {
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
              fprintf(ponteiro_resultados," %.2f +%.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
          else      // est� na forma retangular
          {
               fprintf(ponteiro_resultados," %.2f +%.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
    }
    else
    {
        if(forma_do_primeiro_numero != forma_do_segundo_numero)  // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
              if(answer2.r_angulo>0)
              {
                fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                 fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se est� na forma polar
          {
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
              fprintf(ponteiro_resultados," %.2f %.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
          else      // est� na forma retangular
          {
               fprintf(ponteiro_resultados," %.2f %.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
    }
          break;
      }
     case '-':       // a subtra��o foi a opera��o
      {

          answer2.r_imaginario = complexo1.retangular_imaginario1 - complexo2.retangular_imaginario2;   // respota da parte imaginaria = imaginaria 1 + imagin�ria 2
          answer2.r_real = complexo1.retangular_real1 - complexo2.retangular_real2;                      // resposta da parte real = real1 + real2.
if(answer2.r_imaginario>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
            {
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
              if(answer2.r_angulo>0)
                {
                      fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
                }
              else
              {
                    fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se est� na forma polar
          {
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
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
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
              if(answer2.r_angulo>0)
                {
                      fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
                }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==1)  // ou se est� na forma polar
          {
              converter_polar(&answer2);      // chamada da fun��o que converte para polar
              fprintf(ponteiro_resultados," %.2f %.2fp\r\n",  answer2.r_modulo, answer2.r_angulo);
          }
          else          // esta na forma retangular
          {
               fprintf(ponteiro_resultados," %.2f %.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
}
          break;
      }
     case '*':        // a multiplica��o foi a opera��o escolhida
      {
            answer2.r_modulo = (complexo1.modulo1) * (complexo2.modulo2);     // multiplica-se o modulo do primeiro termo pelo modulo do segundo termo para obter o modulo equivalente.
            answer2.r_angulo = (complexo1.angulo1) + (complexo2.angulo2);      // soma-se o angulo do primeiro termo ao �ngulo do seundo termo para obter o �ngulo equivalente.
if(answer2.r_angulo>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);       // chamada da fun��o que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                    fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==2)  // ou se est� na forma retangular
          {
            converter_retangular(&answer2);   // chamada da fun��o que converte para a forma retangular
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
              converter_retangular(&answer2);       // chamada da fun��o que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                    fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
          else if(forma_do_primeiro_numero==2)  // ou se est� na forma retangular
          {
            converter_retangular(&answer2);   // chamada da fun��o que converte para a forma retangular
            fprintf(ponteiro_resultados," %.2f %.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
          else        // esta na forma polar
          {
              fprintf(ponteiro_resultados," %.2f %.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
}
            break;
      }
     case'/':     // a divis�o foi a opera��o escolhida
      {

            answer2.r_modulo = (complexo1.modulo1) / (complexo2.modulo2);     // multiplica-se o modulo do primeiro termo pelo modulo do segundo termo para obter o modulo equivalente.
            answer2.r_angulo = (complexo1.angulo1) - (complexo2.angulo2);      // soma-se o angulo do primeiro termo ao �ngulo do seundo termo para obter o �ngulo equivalente.
if(answer2.r_angulo>0){
          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);   //chamada da fun��o que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                     fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
         else if(forma_do_primeiro_numero==2)  // ou se est� na forma retangular
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
              converter_retangular(&answer2);   //chamada da fun��o que converte para a forma retangular
              if(answer2.r_imaginario>0)
              {
                     fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
              else
              {
                    fprintf(ponteiro_resultados," %.2f %.2fi ou %.2f %.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
              }
          }
         else if(forma_do_primeiro_numero==2)  // ou se est� na forma retangular
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
     case '^':     // exponencia��o foi a opera��o escolhida
      {
            answer2.r_modulo = pow(complexo1.modulo1, complexo2.modulo2);  // a fun��o pow tem como base a vari�vel modulo1 e eleva ela ao expoente, chamado modulo2
            answer2.r_angulo = complexo1.angulo1 * complexo2.modulo2;       // angulo final= primeiro angulo* segundo angulo

          if(forma_do_primeiro_numero != forma_do_segundo_numero)   // se houve duas formas distintas na expressao, a resposta deve ser dada em ambas as formas
          {
              converter_retangular(&answer2);   // chamada da fun��o que converte para a forma retangular
              fprintf(ponteiro_resultados," %.2f +%.2fi ou %.2f +%.2fp\r\n", answer2.r_real, answer2.r_imaginario, answer2.r_modulo, answer2.r_angulo);
          }
          else if(forma_do_primeiro_numero==2) // ou se est� na forma retangular
          {
             converter_retangular(&answer2);   // chamada da fun��o que converte para a forma retangular
             fprintf(ponteiro_resultados," %.2f +%.2fi\r\n", answer2.r_real, answer2.r_imaginario);
          }
          else   // esta na forma polar
          {
              fprintf(ponteiro_resultados," %.2f + %.2fp\r\n", answer2.r_modulo, answer2.r_angulo);
          }
            break;
      }
     default :      // a convers�o de formas foi a opera��o escolhida
      {
            if (forma_do_primeiro_numero==2)        // se esta da forma retangular, converta para  forma polar
            {
               padroniza_variavel1(complexo1, &answer2);    // chamada da fun��o que padroniza/prepara as vari�veis para a fun��o de convers�o que vem a seguir
               converter_polar(&answer2);                    // chamada da fun��o que converte para a forma polar
               complexo1.modulo1 = answer2.r_modulo;
               complexo1.angulo1 = answer2.r_angulo;
               fprintf(ponteiro_resultados,"%.2f + %.2fp\r\n", complexo1.modulo1, complexo1.angulo1);
            }
            if(forma_do_primeiro_numero==1)                      // a forma digitada pelo usu�rio foi a polar logo, a convers�o � da polar para a retangular
            {
               padroniza_variavel1(complexo1, &answer2);    // chamada da fun��o que padroniza/prepara as vari�veis para a fun��o de convers�o que vem a seguir
               converter_retangular(&answer2);              // chamada da fun��o que converte para a forma retangular
               complexo1.retangular_real1 = answer2.r_real;
               complexo1.retangular_imaginario1 = answer2.r_imaginario;
                              fprintf(ponteiro_resultados,"%.2f + %.2fi\r\n",complexo1.retangular_real1, complexo1.retangular_imaginario1);

            }
      }
    }
    }
      indice=0;        // para ir para a pr�xima string do arquivo zere o indice da string de leitura
      forma_do_primeiro_numero, forma_do_segundo_numero = 0;
     //  Reinicia as vari�veis  que indicam qual foi a forma digitado pelo usuario. Se =1 a forma � a POLAR, se =2 a forma � RETANGULAR
}
    fclose(ponteiro_entrada);     // fecha arquivo de entradas
    fclose(ponteiro_resultados);  // fecha arquivo de resultados
return 0;
}

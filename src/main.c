/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 *
 * Henrique Koji Miyamoto - RA 169614
 */

#include <stdio.h>

int main() {

  char c;         //Variavel que recebera o caractere
  int qtd = 0;    //Quantidade de palavras
  int estado = 0; //Estado do sistema

  c = 1;

  while (c != '\n') //Enquanto a string nao terminou
  {
    scanf("%c", &c); //Realiza leitura de um caractere
        
    //Se o caractere for uma letra valida
    if(((c >= 'a')&&(c <= 'z')) || ((c >= 'A')&&(c <= 'Z')))
    {
    	estado = 1; //Estado 1: esta lendo uma palavra
    }
    
    //Se o caractere for um algarismo
    else if((c>='0')&&(c<='9'))
    {
      if(estado == 3) 
        estado = 3; //Estado 3: esta lendo parte decimal de um numero
      else
        estado = 2; //Estado 2: esta lendo um numero
    }
    
    //Se o caractere for outro simbolo
    else
    {
    	if(estado == 1) //Se o ultimo caractere foi letra
    	{
    		qtd++;      //Incrementa quantidade de palavras
        estado = 0; //Estado 0: inicial
    	}
      
      else if(estado == 2)  //Se o ultimo caractere foi algarismo
    	{
    		if((c == '.')||(c == ',')) //O simbolo e . ou ,
        {
          estado = 3; //Estado 3: esta lendo parte decimal de um numero
        }
        else  //Outro simbolo
        {
          qtd++;      //Incrementa quantidade de palavras
          estado = 0; //Estado 0: inicial
        }
    	}
      
      else if(estado == 3) //Se o ultimo caractere foi parte decimal de um numero
      {
        qtd++;      //Incrementa quantidade de palavras
        estado = 0; //Estado 0: inicial
      }

    }

  }

  printf("%d\n", qtd); //Imprime quantidade total de palavras
  return 0;
}
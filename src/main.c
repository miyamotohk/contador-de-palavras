/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() {

  char c;
  int qtd = 0;
  int flag = 0;

  c = 1;

  while (c != '\n') {
    scanf("%c", &c); //Realiza leitura de um caractere
    
    //Se o caractere for uma letra valida
    if(((c >= 'a')&&(c <= 'z')) || ((c >= 'A')&&(c <= 'Z')))
    {
    	flag = 1; //Flag indica que o ultimo caractere foi uma letra
    }
    
    //Se o caractere for um algarismo
    else if((c>='0')&&(c<='9'))
    {
    	if(flag == 3)
    		flag = 3;
    	else
			flag = 2; //Flag indica que o ultimo caractere foi um algarismo  
    }
    
    //Se o caractere for outro simbolo
    else
    {
    	if(flag == 1) //Se o ultimo foi uma letra, incrementa quantidade de palavras
    	{
    		qtd++;
        flag = 0;
    	}
    	if(flag == 2) //Se foi um numero, incrementa a quantidade de palavras e altera a flag
    	{
    		//if((c == '.')||(c == ','))
        qtd++;
        flag = 0;
    	}

    }

  }

  printf("%d\n", qtd);
  return 0;
}

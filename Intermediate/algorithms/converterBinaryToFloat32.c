/**  *     @author: Letícia de Souza
	 *     @github: https://github.com/leticia-s
	 * --------------------------------------------------------------------------------------------------
	 * [Portuguese] conversor: binário para ponto flutuante - 32 bits precisão simples (padrão IEEE-754)
	 * [English] converter: binary to floating point - 32 bit simple precision (IEEE-754 standard)
	 * --------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
float potencia(float base, int expoente)
{
	if (expoente == 0)
		return 1;
	else if (expoente == 1)
		return base;

	else if (expoente < 0)
	{
		expoente *= -1;
		base = 1.0 / base;
	}
	return base * potencia(base, expoente - 1);
	 }

	 int char_int(char x){
	 	if(x == '1')
	 		return 1;
	 	else 
	 		return 0;
	 }

	 int sinal(char x){
	 	if(x == '1')
	 		return -1;
	 	else 
	 		return +1;
	 }

	 int expoente(char x[32]){
	 	int i,exp=0,posicao=0;
	 	for(i=8;i>=1;i--){
	 		exp+=char_int(x[i])*potencia(2,posicao);
	 		posicao++;

	 	}
	 	
	 	exp-=127;
	 	return exp;
	 }

	 float mantissa(char x[32],int expoente){
	 	int i,f,part_intei=0,posicao_i=0,posicao_f=-1,aux=9;
	 	float um,part_frac=0;
	 	if(expoente>=0||expoente==-127){
	 		posicao_i+=expoente;
	 		um=1*potencia(2,posicao_i);
	 		posicao_i--;
	 		aux+=posicao_i;

	 		for(i=9;i<=aux;i++){
	 			part_intei+=char_int(x[i])*potencia(2,posicao_i);
	 			posicao_i--;

	 		}
	 		aux++;
	 	}
	 	else{
	 		um=1*potencia(2,posicao_f);
	 		posicao_f--;
	 	}    
	 	
	 	for(f=aux;f<32;f++){
	 		part_frac+=char_int(x[f])*potencia(2,posicao_f);
	 		posicao_f--;

	 	} 

	 	return um+part_intei+part_frac;
	 }


	 float ponto_flutuante(){
	 	char x[32];
	 	scanf("%s",x);


	 	return sinal(x[0])*mantissa(x,expoente(x));
	 }
	 int main(){
		 printf("Enter a single-precision 32-bit binary in the IEEE-754 standard:\n");
		 printf("%+0.4f\n", ponto_flutuante());
		 return 0;
	 }
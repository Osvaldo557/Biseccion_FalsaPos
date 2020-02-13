#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float evalFunction (float value){
	return pow(value,3)+ 4*pow(value,2)-10;
}


float FalsaPosicion(float x_upper, float x_lower, float error_permitido,bool &terminado){
	float f_upper, f_lower, f_xr;
	float raiz;
	float xr_ant = 0,xr;
	float error;
	int contador = 1;
	terminado = false;



	/*Evaluando la función en el intervalo menor*/
	do{

	printf("El valor superior es: %0.2f \n",x_upper);
	printf("El valor inferior es: %0.2f",x_lower);

	f_lower = evalFunction(x_lower);
	if(f_lower == 0 )
		raiz == x_lower;

	/*Evaluando la función en el intervalo mayor*/
	f_upper = evalFunction(x_upper);
	if(f_upper == 0)
		raiz == x_upper;
	printf("\n\n");
	printf("El valor de f(%.2f) inferior es: %.2f",x_lower,f_lower);
	printf("     El valor de f(%.2f) superior es: %.2f",x_upper,f_upper);
	/*Calculando xr*/
	xr = ((x_upper*f_lower)-(x_lower*f_upper))/(f_lower-f_upper);




	f_xr = evalFunction(xr);
	printf("\n\n");
	printf("El valor de xr es: %0.2f",xr);
	printf("         El valor de f(xr) es %f\n\n",f_xr);
	/*calculando f(xr)*/
	

	/*Verificando de que lado queda la raiz*/
	if(f_xr == 0)
		raiz == xr;
	if (f_lower*f_xr < 0)
		x_upper = xr;
	else if (f_lower*f_xr == 0)
		raiz == xr;
	else
		x_lower = xr;

	/*Calculando el error*/
	error = abs(xr_ant - xr);
	printf("El error es: %f\n",error);
	
	if (error <= error_permitido){
		raiz = xr;
		printf("No. de iteraciones: %d\n\n",contador);
		terminado = true;
		break;
	}


	if(contador > 50){
		raiz == -1.0;
		terminado = false;
		break;
	}

	xr_ant = xr;
	contador += 1;

	}while(contador < 1000);

	return raiz;
}

int main(){
	bool terminado=false; 
	float raiz = FalsaPosicion(2.0,0.0,0.01,terminado);

	if (terminado){
		printf("El proceso convergio\n\n");
		printf("La raiz es: %f",raiz);
	}

	else {
		printf("El método no funcino\n\n");
	}
}

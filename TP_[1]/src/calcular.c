#include <stdio.h>
#include "calcular.h"

int CalcularDivision (float dividendoIngresado, float divisorIngresado, float* resultadoDivision)
{
	int retorno=-1;
	float resultado;
	if(divisorIngresado!=0)
	{
		resultado=dividendoIngresado/divisorIngresado;
		*resultadoDivision=resultado;
		retorno=0;
	}

	return retorno;
}
float CalcularMultiplicacion(float primerOperandoIngresado, float segundoOperandoIngresado)
{
	float resultado;
	resultado=primerOperandoIngresado*segundoOperandoIngresado;

	return resultado;
}
float CalcularSuma(float primerOperandoIngresado, float segundoOperandoIngresado)
{
	float resultado;
	resultado=primerOperandoIngresado+segundoOperandoIngresado;

	return resultado;
}
float CalcularResta(float primerOperandoIngresado, float segundoOperandoIngresado)
{
	float resultado;
	resultado=primerOperandoIngresado-segundoOperandoIngresado;

	return resultado;
}

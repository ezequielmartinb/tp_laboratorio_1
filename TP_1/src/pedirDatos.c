#include <stdio.h>
#include "pedirDatos.h"

int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int auxiliarNumeroIngresado;
	int retorno=-1;

	if(pNumeroIngresado!=NULL && maximo>minimo && reintentos>=0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			scanf("%d", &auxiliarNumeroIngresado);
			reintentos--;
			if(auxiliarNumeroIngresado>=minimo && auxiliarNumeroIngresado<=maximo)
			{
				*pNumeroIngresado=auxiliarNumeroIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				printf("CANTIDAD DE REINTENTOS: %d\n", reintentos);
			}
		}
	}


	return retorno;
}
int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float auxiliarNumeroIngresado;
	int retorno=-1;

	if(pNumeroIngresado!=NULL && maximo>minimo && reintentos>=0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			scanf("%f", &auxiliarNumeroIngresado);
			reintentos--;
			if(auxiliarNumeroIngresado>=minimo && auxiliarNumeroIngresado<=maximo)
			{
				*pNumeroIngresado=auxiliarNumeroIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				printf("CANTIDAD DE REINTENTOS: %d\n", reintentos);
			}
		}
	}

	return retorno;
}

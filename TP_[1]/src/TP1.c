/*
 ============================================================================
 TRABAJO PRACTICO 1

 Ezequiel Brañanova 1ºE
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"
#include "calcular.h"
#define PRECIO_BITCOIN 4606954.55
#define DESCUENTO 0.10
#define INTERES 0.25

int main(void)
{
	int opcionIngresada;
	float kilometrosIngresados;
	float precioAerolineasIngresado;
	float precioLatamIngresado;
	int opcionPreciosVuelos;
	float descuento;
	float precioConDescuentoAerolineas;
	float precioConDescuentoLatam;
	float interes;
	float precioConInteresAerolineas;
	float precioConInteresLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaDePrecio;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionCuatro;
	int banderaCalculos;
	int banderaAerolineas;
	int banderaLatam;
	int banderaCargaForzada;
	banderaOpcionUno=0;
	banderaOpcionDos=0;
	banderaOpcionCuatro=0;
	banderaCalculos=0;
	banderaAerolineas=0;
	banderaLatam=0;
	banderaCargaForzada=0;
	setbuf(stdout, NULL);

	while(opcionIngresada!=6)
	{
		printf("===========================================================================\n"
			   "		   	BIENVENIDO A LA APP VUELOS UTN								 \n"
			   "===========================================================================\n");
		if(banderaOpcionUno==0)
		{
			printf("1. Ingresar Kilometros: (km=x)\n");
		}
		else
		{
			printf("1. Ingresar Kilometros: (km=%.2f)\n", kilometrosIngresados);
		}
		if(banderaOpcionDos==0)
		{
			printf("2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n"
					"\t- Precio vuelo Aerolíneas:\n"
					"\t- Precio vuelo Latam:\n\n");
		}
		else
		{
			if(banderaAerolineas!=0 && banderaLatam==0)
			{
				printf("2. Ingresar Precio de Vuelos: (Aerolíneas=$ %.2f, Latam=x)\n"
												"\t- Precio vuelo Aerolíneas:\n"
												"\t- Precio vuelo Latam:\n\n", precioAerolineasIngresado);
			}
			else
			{
				if(banderaAerolineas==0 && banderaLatam!=0)
				{
					printf("2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=$ %.2f)\n"
					"\t- Precio vuelo Aerolíneas:\n"
					"\t- Precio vuelo Latam:\n\n", precioLatamIngresado);
				}
				else
				{
					printf("2. Ingresar Precio de Vuelos: (Aerolíneas=$ %.2f, Latam=$ %.2f)\n"
								"\t- Precio vuelo Aerolíneas:\n"
								"\t- Precio vuelo Latam:\n\n", precioAerolineasIngresado, precioLatamIngresado);

				}
			}

		}
		printf("3. Calcular todos los costos:\n"
					"\ta) Tarjeta de débito (descuento 10%c)\n"
					"\tb) Tarjeta de crédito (interés 25%c)\n"
					"\tc) Bitcoin (1BTC -> 4.606.954,55 Pesos Argentinos)\n"
					"\td) Mostrar precio por km (precio unitario)\n"
					"\te) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n\n",37,37);
		if(banderaOpcionCuatro==0)
		{
			printf("4. Informar Resultados\n"
						"Latam:\n"
						"\ta) Precio con tarjeta de débito: r\n"
						"\tb) Precio con tarjeta de crédito: r\n"
						"\tc) Precio pagando con bitcoin : r\n"
						"\td) Precio unitario: r\n\n"
						"Aerolíneas:\n"
						"\ta) Precio con tarjeta de débito: r\n"
						"\tb) Precio con tarjeta de crédito: r\n"
						"\tc) Precio pagando con bitcoin : r\n"
						"\td) Precio unitario: r\n"
						"\tLa diferencia de precio es : r\n");
		}
		else
		{
			printf("4. Informar Resultados\n"
						"Latam:\n"
						"\ta) Precio con tarjeta de débito: $ %.2f\n"
						"\tb) Precio con tarjeta de crédito: $ %.2f\n"
						"\tc) Precio pagando con bitcoin : BTC %.5f\n"
						"\td) Precio unitario: $ %.2f\n\n\n"
						"Aerolíneas:\n"
						"\ta) Precio con tarjeta de débito: $ %.2f\n"
						"\tb) Precio con tarjeta de crédito: $ %.2f\n"
						"\tc) Precio pagando con bitcoin : BTC %.5f\n"
						"\td) Precio unitario: $ %.2f\n"
						"\tLa diferencia de precio es : $ %.2f\n", precioConDescuentoLatam, precioConInteresLatam,
						precioBitcoinLatam, precioUnitarioLatam, precioConDescuentoAerolineas, precioConInteresAerolineas,
						precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaDePrecio);
		}
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n\n");
		if(banderaCargaForzada==1)
		{
			opcionIngresada=6;
		}
		else
		{
			if(getInt(&opcionIngresada, "Ingrese una opcion valida: ", "ERROR. OPCION INVALIDA. ",1, 6, 3)!=0)
			{
				printf("NO INGRESO UNA OPCIÓN VALIDA\n");
				break;
			}
		}

		switch(opcionIngresada)
		{
			case 1:
				if(getFloat(&kilometrosIngresados, "Ingrese una cantidad de kilometros validos: ", "ERROR. OPCION INVALIDA. ",1, 14200, 3)!=0)
				{
					printf("LOS KILOMETROS INGRESADOS SON INVALIDOS\n");
					break;
				}
				banderaOpcionUno=1;
				break;
			case 2:
				banderaOpcionDos=1;
				printf("2. Ingresar Precio de Vuelos\n"
						"\t- 1. Precio vuelo Aerolíneas:\n"
						"\t- 2. Precio vuelo Latam:\n\n");
				if(getInt(&opcionPreciosVuelos, "Ingrese una opcion valida: ", "ERROR. OPCION INVALIDA. ",1, 2, 3)!=0)
				{
					printf("SE INGRESO UNA OPCIÓN INVALIDA\n");
					break;
				}
				else
				{

					switch(opcionPreciosVuelos)
					{
						case 1:
							if(getFloat(&precioAerolineasIngresado, "Ingrese el precio de Aerolineas: ", "ERROR. PRECIO INVALIDA. ",1, 2147483647, 3)!=0)
							{
								printf("SE INGRESO UN PRECIO INVALIDO\n");
							}
							banderaAerolineas=1;
						break;
						case 2:
							if(getFloat(&precioLatamIngresado, "Ingrese el precio de LATAM: ", "ERROR. PRECIO INVALIDA. ",1, 2147483647, 3)!=0)
							{
								printf("SE INGRESO UN PRECIO INVALIDO\n");
							}
							banderaLatam=1;
							break;
					}
				}
				break;
			case 3:
				if(banderaOpcionUno==0 || banderaOpcionDos==0)
				{
					printf("Antes de calcular, primero hay que ingresar los kilometros y el precio\n");
				}
				else
				{
					if(banderaLatam==0)
					{
						printf("Antes de calcular, se debe ingresar el precio de costo de Latam\n");
					}
					else
					{
						if(banderaAerolineas==0)
						{
							printf("Antes de calcular, se debe ingresar el precio de costo de Aerolineas\n");
						}
						else
						{
							// DESCUENTO 10%
							descuento=CalcularMultiplicacion(precioAerolineasIngresado, DESCUENTO);
							precioConDescuentoAerolineas=CalcularResta(precioAerolineasIngresado, descuento);
							descuento=CalcularMultiplicacion(precioLatamIngresado, DESCUENTO);
							precioConDescuentoLatam=CalcularResta(precioLatamIngresado, descuento);

							// INTERES 25%
							interes=CalcularMultiplicacion(precioAerolineasIngresado, INTERES);
							precioConInteresAerolineas=CalcularSuma(precioAerolineasIngresado, interes);
							interes=CalcularMultiplicacion(precioLatamIngresado, INTERES);
							precioConInteresLatam=CalcularSuma(precioLatamIngresado, interes);

							// BITCOIN
							if(CalcularDivision(precioAerolineasIngresado, PRECIO_BITCOIN, &precioBitcoinAerolineas)!=0)
							{
								printf("NO se pudo calcular el precio en Bitcoin de Aerolineas\n");
							}
							if(CalcularDivision(precioLatamIngresado, PRECIO_BITCOIN, &precioBitcoinLatam)!=0)
							{
								printf("NO se pudo calcular el precio en Bitcoin de LATAM\n");
							}

							// PRECIO UNITARIO
							if(CalcularDivision(precioAerolineasIngresado, kilometrosIngresados, &precioUnitarioAerolineas)!=0)
							{
								printf("NO se pudo calcular el precio unitario de Aerolineas\n");
							}
							if(CalcularDivision(precioLatamIngresado, kilometrosIngresados, &precioUnitarioLatam)!=0)
							{
								printf("NO se pudo calcular el precio unitario de LATAM\n");
							}

							// DIFERENCIA PRECIO (LATAM-AEROLINEAS)
							diferenciaDePrecio=CalcularResta(precioUnitarioLatam, precioUnitarioAerolineas);

							printf("\nLos calculos fueron realizados de forma correcta\n");
							banderaCalculos=1;
						}
					}
				}
				break;
			case 4:
				if(banderaCalculos==0)
				{
					printf("Antes de mostrar los resultados, primero hay que realizar los calculos\n\n");
				}
				else
				{
					banderaOpcionCuatro=1;
				}
				break;
			case 5:
				kilometrosIngresados=7090;
				precioAerolineasIngresado=162965;
				precioLatamIngresado=159339;
				descuento=CalcularMultiplicacion(precioAerolineasIngresado, DESCUENTO);
				precioConDescuentoAerolineas=CalcularResta(precioAerolineasIngresado, descuento);
				descuento=CalcularMultiplicacion(precioLatamIngresado, DESCUENTO);
				precioConDescuentoLatam=CalcularResta(precioLatamIngresado, descuento);
				interes=CalcularMultiplicacion(precioAerolineasIngresado, INTERES);
				precioConInteresAerolineas=CalcularSuma(precioAerolineasIngresado, interes);
				interes=CalcularMultiplicacion(precioLatamIngresado, INTERES);
				precioConInteresLatam=CalcularSuma(precioLatamIngresado, interes);
				if(CalcularDivision(precioAerolineasIngresado, PRECIO_BITCOIN, &precioBitcoinAerolineas)!=0)
				{
					printf("NO se pudo calcular el precio en Bitcoin de Aerolineas\n");
				}
				if(CalcularDivision(precioLatamIngresado, 4606954.55, &precioBitcoinLatam)!=0)
				{
					printf("NO se pudo calcular el precio en Bitcoin de LATAM\n");
				}
				if(CalcularDivision(precioAerolineasIngresado, kilometrosIngresados, &precioUnitarioAerolineas)!=0)
				{
					printf("NO se pudo calcular el precio unitario de Aerolineas\n");
				}
				if(CalcularDivision(precioLatamIngresado, kilometrosIngresados, &precioUnitarioLatam)!=0)
				{
					printf("NO se pudo calcular el precio unitario de LATAM\n");
				}
				diferenciaDePrecio=CalcularResta(precioUnitarioLatam, precioUnitarioAerolineas);
				banderaOpcionUno=1;
				banderaOpcionDos=1;
				banderaAerolineas=1;
				banderaLatam=1;
				banderaOpcionCuatro=1;
				banderaCargaForzada=1;
				break;
			case 6:
				printf("===========================================================================\n"
					   "		   	GRACIAS POR USAR LA APP VUELOS UTN								 \n"
					   "===========================================================================\n");
				break;
		}
	}

	return EXIT_SUCCESS;
}

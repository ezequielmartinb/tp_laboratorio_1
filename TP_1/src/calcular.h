/*
 * calcular.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Ezequiel
 */

#ifndef CALCULAR_H_
#define CALCULAR_H_

/// @fn int CalcularDivision(float, float, float*)
/// @brief Pide dos numeros flotantes al usuario, verifica que el divisor no sea 0.
/// 	   En caso de no serlo, retorna 1 y guarda el resultado en la variable de puntero flotante.
///        En caso de ser 0 el divisor, retorna 0
///
///
/// @param dividendoIngresado Primer numero flotante ingresado
/// @param divisorIngresado Segundo numero flotante ingresado
/// @param resultadoDivision Guardo en la direccion de memoria de una variable el resultado de la division
/// @return Retorna 0 si la division pudo realizarse con exito.
///   		Retorna -1 si la division no pudo.
int CalcularDivision (float dividendoIngresado, float divisorIngresado, float* resultadoDivision);
/// @fn float CalcularMultiplicacion(int, int)
/// @brief Pide dos numeros flotantes, realiza la multiplicacion de los mismos y devuelve el resultado
///
/// @param Primer numero flotante ingresado
/// @param Segundo numero flotante ingresado
/// @return Retorna el resultado de la multiplicacion entre el primer numero flotante ingresado y el segundo flotante entero ingresado
float CalcularMultiplicacion(float primerOperandoIngresado, float segundoOperandoIngresado);
/// @fn int CalcularSuma(float, float)
/// @brief Pide dos numeros flotantes, realiza la suma de los mismos y devuelve el resultado

/// @param Primer numero flotante ingresado
/// @param Segundo numero flotante ingresado
/// @return Retorna el resultado de la suma entre el primer numero flotante ingresado y el segundo numero flotante ingresado
float CalcularSuma(float primerOperandoIngresado, float segundoOperandoIngresado);
/// @fn int CalcularResta(float, float)
/// @brief Pide dos numeros enteros, realiza la resta de los mismos y devuelve el resultado
///
/// @param Primer numero entero ingresado
/// @param Segundo numero entero ingresado
/// @return Retorna el resultado de la resta entre el primer numero flotante ingresado y el segundo numero flotante ingresado
float CalcularResta(float primerOperandoIngresado, float segundoOperandoIngresado);

#endif /* CALCULAR_H_ */

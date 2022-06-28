/*
 * funciones.c
 *
 *  Created on: 28 jun. 2022
 *      Author: matia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "validaciones.h"

#define BITCOIN 4606954.44


float Calculardebito(float precio)
{
	float resultadoDebito;

	resultadoDebito = precio -(precio * 0.10);

	return resultadoDebito;
}
float Calcularinteres(float precio)
{
	float resultadoCredito;

	resultadoCredito = precio + (precio * 0.25);

	return resultadoCredito;
}
float Calcularbitcoin(float precio)
{
	float resultadoBitcoin;

	resultadoBitcoin = precio / BITCOIN;

	return resultadoBitcoin;
}

float Calcularunitario(float precio,float km)
{
	float resultadoUnitario;

	resultadoUnitario = precio / km;

	return resultadoUnitario;
}

float Calculardiferencia(float precioA,float precioL)
{
	float resultadoDiferencia;

	resultadoDiferencia = precioA - precioL;

	return resultadoDiferencia;
}

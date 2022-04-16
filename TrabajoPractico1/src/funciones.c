/*
 * funciones.c
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define BITCOIN 4606954.44

float debito(float precio)
{
	float resultadoDebito;

	resultadoDebito = precio -(precio * 0.10);

	return resultadoDebito;
}
float interes(float precio)
{
	float resultadoCredito;

	resultadoCredito = precio + (precio * 0.25);

	return resultadoCredito;
}
float bitcoin(float precio)
{
	float resultadoBitcoin;

	resultadoBitcoin = precio / BITCOIN;

	return resultadoBitcoin;
}

float unitario(float precio,float km)
{
	float resultadoUnitario;

	resultadoUnitario = precio / km;

	return resultadoUnitario;
}

float diferencia(float precioA,float precioL)
{
	float resultadoDiferencia;

	resultadoDiferencia = precioA - precioL;

	return resultadoDiferencia;
}

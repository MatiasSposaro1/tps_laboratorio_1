/*
 * validaciones.c
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

int getInt(char* mensaje, int* pResultado)
{
    int retorno = -1;
    int retornoScanf;
    int auxInt;

    if(mensaje!=NULL && pResultado!=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        retornoScanf = scanf("%d", &auxInt);
        while(retornoScanf==0)
        {
            printf("ERROR: Ingrese solo numeros: ");
            fflush(stdin);
            retornoScanf = scanf("%d", &auxInt);
        }
        *pResultado = auxInt;
        retorno = 0;
    }
    return retorno;
}

int getFloat(char* mensaje, float* pResultado)
{
    int retorno = -1;
    int retornoScanf;
    float auxFloat;
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        retornoScanf = scanf("%f", &auxFloat);
        while(retornoScanf == 0)
        {
            printf("Error. Ingrese solo numeros: ");
            fflush(stdin);
            retornoScanf = scanf("%f", &auxFloat);
        }
        *pResultado = auxFloat;

        retorno = 0;
    }
    return retorno;
}

int getString(char* mensaje, char pResultado[])
{
    int retorno = -1;
    char auxCad[100];
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(auxCad);

        while(strlen(auxCad) > 50 || strlen(auxCad) < 1 || isdigit(*auxCad))
        {
            printf("Error. Ingrese solo caracteres: ");
            fflush(stdin);
            gets(auxCad);
        }

        strcpy(pResultado, auxCad);

        retorno = 0;
    }

    return retorno;
}

int getStringDigit(char* mensaje,char pResultado[])
{
	int retorno = 0;
	int auxWhile;
	char auxChar[30];

	if(mensaje!=NULL && pResultado !=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		gets(auxChar);

		do
		{
			auxWhile = 0;
			for(int i = 0; i<strlen(auxChar);i++)
			{
				if(isalpha(auxChar[i])!=0 || isdigit(auxChar[i]) == 0)
				{
					printf("ERROR! %s",mensaje);
					fflush(stdin);
					gets(auxChar);
					auxWhile = 1;
					break;
				}
			}
		}while(auxWhile==1);


		strcpy(pResultado,auxChar);
		retorno = 1;
	}
	return retorno;
}

int getEntero(int* integer, char* message, char* messageMistake, int min, int max)
{
	int ret= -1;
	int enteredNumber;

	if(integer != NULL && message != NULL &&  messageMistake != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enteredNumber);
		while(enteredNumber < min || enteredNumber > max)
		{
			printf("%s", messageMistake);
			fflush(stdin);
			scanf("%d", &enteredNumber);
		}

		*integer = enteredNumber;
		ret = 0;
	}

	return ret;
}

int setMayus(char vec[], int len)
{
    int checkStatus = 0;
    int i = 0;
    strlwr(vec);
    vec[0] = toupper(vec[0]);

    while(vec[i]!= '\0')
    {
        if (vec[i] == ' ')
        {
            vec[i + 1] = toupper(vec[i+1]);
            checkStatus = 1;
        }
        i++;
    }

    return checkStatus;
}

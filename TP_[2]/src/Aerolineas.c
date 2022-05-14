/*
 ============================================================================
 Name        : Aerolineas.c
 Author      : Matias Sposaro  1°DIV C
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Bibliotecas.h"
#include "ArrayPassenger.h"

#define TAMPASAJEROS 2000

int menu();

int main(void)
{
	setbuf(stdout,NULL);

	Passenger auxPasajero[TAMPASAJEROS];

	int respuesta;
	char opcion = 'N';
	int id = 1;
	int salir;

	int contadorPasajeros = 0;

	initPassengers(auxPasajero, TAMPASAJEROS);

	do
	{
		switch(menu())
		{
		case 1:
			if(contadorPasajeros < TAMPASAJEROS)
			{
				agregarPasajeros(auxPasajero, TAMPASAJEROS, &id);
				contadorPasajeros++;
			}
			else
			{
				printf("No hay lugar para cargar un pasajero \n");
			}
			break;
		case 2:
			if(contadorPasajeros > 0)
			{
				modificarPasajeros(auxPasajero, TAMPASAJEROS);
			}
			else
			{
				printf("No hay pasajeros para listar");
			}
			break;
		case 3:
			if(contadorPasajeros > 0)
			{
				printPassenger(auxPasajero, TAMPASAJEROS);
				respuesta = eliminarPasajero(auxPasajero,TAMPASAJEROS);

				if(!respuesta)
				{
					contadorPasajeros--;
				}
			}
			else
			{
				printf("No hay pasajeros para eliminar \n");
			}
			break;
		case 4:
			do
			{
				switch(subMenu())
				{
				case 1:
					if(contadorPasajeros > 0)
					{
						int orden;
						getInt("Ingrese el orden que desea:(1 ascendente y 2 descendente): \n", &orden, 1, 2);
						 sortPassengers(auxPasajero, TAMPASAJEROS, orden);
						printPassenger(auxPasajero, TAMPASAJEROS);
					}
					else
					{
						printf("No existe un pasajero...\n");
					}
					break;
				case 2:
					if(contadorPasajeros > 0)
					{
						informarPromedio(auxPasajero, TAMPASAJEROS);
						system("PAUSE");
					}
					else
					{
						printf("No hay pasajeros para informar el promedio.. \n");
					}
					break;
				case 3:
					if(contadorPasajeros > 0)
					{
						int orden;
						getInt("Ingrese el orden que desea:(1 ascendente y 2 descendente): \n", &orden, 1, 2);
						sortPassengersByCode(auxPasajero, TAMPASAJEROS, orden);
						printPassenger(auxPasajero, TAMPASAJEROS);
					}
					else
					{
						printf("No existe un pasajero...\n");
					}
					break;

				case 4:
					salir = 4;
					break;
				}


			}while(salir != 4);

			break;
		case 5:
			hardcodeoPasajeros(auxPasajero, &id, &contadorPasajeros);
			printPassenger(auxPasajero,TAMPASAJEROS);
			break;
		case 6:
			printf("Seguro desea salir S/N: ");
			fflush(stdin);
			scanf("%c",&opcion);
			opcion = toupper(opcion);

			while(opcion != 'S' && opcion != 'N')
				{
					printf("Opcion incorrecta.Ingrese nuevamente: ");
					fflush(stdin);
					scanf("%c",&opcion);
					opcion = toupper(opcion);
				}

				if(opcion == 'N')
					{
					  printf("Salir cancelado\n");
					}
			break;
		default:
			printf("Opcion incorrecta \n");
			break;
		}
		system("PAUSE");
	}while(opcion == 'N');
		printf("Salio...");

	return EXIT_SUCCESS;
}

int menu()
{
	int opcion;

	  	printf("=======================================================\n");
	    printf("                MENU DE PASAJEROS\n");
	    printf("=======================================================\n");
	    printf("    1 - ALTAS:\n");
	    printf("    2 - MODIFICAR:\n");
	    printf("    3 - BAJA:\n");
	    printf("    4 - INFORMAR:\n");
	    printf("    5 - ALTA FORZADA:\n");
	    printf("    6 - SALIR\n");
	    printf("=======================================================\n");

	    printf("Ingrese una opcion: ");
	    fflush(stdin);
	    scanf("%d",&opcion);

	    while(opcion < 1 || opcion > 6)
	    {
	    	printf("Error.Opcion incorrecta,Ingresa nuevamente: \n");
	    	scanf("%d",&opcion);
	    }

	return opcion;
}

int subMenu()
{
	int opcion = -1;


	printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
	printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
	printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ \n");
	printf("4. Volver");

	printf("Eliga una opcion: \n");
	scanf("%d",&opcion);

	while(opcion < 1 || opcion > 4)
	{
		printf("ERROR! Opcion incorrecta.Ingrese nuevamente: ");
		scanf("%d",&opcion);
	}
	return opcion;
}

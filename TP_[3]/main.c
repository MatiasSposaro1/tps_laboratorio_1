#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
	setbuf(stdout,NULL);

	int cargado = 0;
    int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    if(listaPasajeros == NULL)
    {
    	exit(1);
    }

    do{

    	option = menu();

        switch(option)
        {
            case 1:
            	if(!cargado)
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
            		printf("Cargado el archivo de texto con exito \n");
            		cargado = 1;
            	}
            	break;

            case 2:
            	if(!cargado)
            	{
            		controller_loadFromBinary("data.bin",listaPasajeros);
            		printf("Cargado el archivo binario con exito \n");
            		cargado = 1;
            	}
            	break;
            case 3:
            	if(cargado)
            	{
            		controller_addPassenger(listaPasajeros);
            	}else
            	{
            		printf("Primero cargue los pasajeros de los archivos \n");
            	}
            	break;
            case 4:
            	if(cargado)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Primero cargue los pasajeros de los archivos \n");
            	}
            	break;
            case 5:
            	if(cargado)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Primero cargue los pasajeros de los archivos \n");
            	}
            	break;

            case 6:
            	if(cargado)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Primero cargue los pasajeros de los archivos \n");
            	}
            	system("pause");
            	break;
            case 7:
            	if(cargado)
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Primero cargue los pasajeros de los archivos \n");
            	}
            	break;
            case 8:
            	if(cargado)
            	{
            		controller_saveAsText("data.csv", listaPasajeros);
            		printf("Guardado exitoso!!! \n");
            		cargado = 0;
            	}
            	else
            	{
            		printf("Primero cargue los pasajeros de los archivos \n");
            	}
            	break;
            case 9:
            	if(cargado)
            	{
            		controller_saveAsBinary("data.bin", listaPasajeros);
            		cargado = 0;
            	}
            	else
            	{
            		printf("Primero cargue los pasajeros de los archivos \n");
            	}
            	break;
            case 10:
            	break;

        }
    }while(option != 10);
    return 0;
}

int menu()
{
    int opcion;
    printf("Menu\n");
    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de pasajero.\n");
    printf("4. Modificar datos de pasajero.\n");
    printf("5. Baja de pasajero.\n");
    printf("6. Listar pasajeros.\n");
    printf("7. Ordenar pasajeros.\n");
    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf("Escoja su opcion: ");
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 10)
    {
        printf("Error. Opcion Incorrecta: ");
        scanf("%d", &opcion);
    }
    return opcion;
}


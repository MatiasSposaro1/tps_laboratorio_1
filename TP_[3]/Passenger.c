/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"



Passenger* Passenger_new()
{
	Passenger* newPassenger = (Passenger*) malloc(sizeof(Passenger));
	return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* tipoPasajeroStr,char* precioStr,char* codigoVueloStr,char* estadoVuelo)
{
	Passenger* newPassenger = Passenger_new();

	int idAux;
	float precioAux;


	if(newPassenger != NULL)
	{
		idAux = atoi(idStr);
		precioAux = atof(precioStr);

		Passenger_setId(newPassenger, idAux);
		Passenger_setNombre(newPassenger,nombreStr);
		Passenger_setApellido(newPassenger, apellidoStr);
		Passenger_setCodigoVuelo(newPassenger, codigoVueloStr);
		Passenger_setTipoPasajero(newPassenger,tipoPasajeroStr);
		Passenger_setPrecio(newPassenger,precioAux);
		Passenger_setEstadoVuelo(newPassenger,estadoVuelo);
	}
	return newPassenger;
}

void Passenger_delete(Passenger* this)
{
	free(this);
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;

		if(this != NULL && apellido != NULL)
		{
			strcpy(this->apellido,apellido);
			retorno = 1;
		}
		return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = 0;

	if(this != NULL && apellido != NULL)
	{
	    strcpy(apellido,this->apellido);
		retorno = 1;
	}

	return retorno;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 1;
	}
return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float *precio)
{
	int retorno = 0;

	if(this != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;

	if(this!=NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

int maxId(LinkedList* listaPasajeros)
{

    Passenger* auxPassenger = NULL;
    int mayor= 0;
    int id;
    if(listaPasajeros != NULL)
    {

        for( int i = 0; i < ll_len(listaPasajeros); i++)
        {
        	auxPassenger = (Passenger*) ll_get(listaPasajeros, i);
            Passenger_getId(auxPassenger, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }

    }
    return mayor;
}

int buscarPasajerosId(LinkedList* lista, int id)
{
	   int indice = -1;
	    int idAux;
	    Passenger* auxPassenger;

	    for (int i = 0; i < ll_len(lista); i++)
	    {
	    	auxPassenger = ll_get(lista, i);
	        if(Passenger_getId(auxPassenger, &idAux) && idAux == id)
	        {
	            indice = i;
	        }
	    }

	    return indice;
}

int ordenarPorNombre(void* a, void* b)
{

    int todoOk = 0;
    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;
    if(a != NULL && b != NULL)
    {
    	pasajero1 = (Passenger*) a;
    	pasajero2 = (Passenger*) b;

        if(strcmp(pasajero1->nombre, pasajero2->nombre) > 0)
        {
           todoOk = 1;
        }else if(strcmp(pasajero1->nombre, pasajero2->nombre) < 0)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}

int ordenarPorApellido(void* a, void* b)
{
		int todoOk = 0;
	    Passenger* pasajero1 = NULL;
	    Passenger* pasajero2 = NULL;
	    if(a != NULL && b != NULL)
	    {
	    	pasajero1 = (Passenger*) a;
	    	pasajero2 = (Passenger*) b;

	        if(strcmp(pasajero1->nombre, pasajero2->nombre) > 0)
	        {
	           todoOk = 1;
	        }else if(strcmp(pasajero1->nombre, pasajero2->nombre) < 0)
	        {
	            todoOk = -1;
	        }
	    }

	    return todoOk;
}

int ordenarPorPrecio(void* a, void* b)
{
    int todoOk = 0;

    Passenger* pasajero1 = NULL;
     Passenger* pasajero2 = NULL;

    if(a != NULL && b != NULL)
    {
    	pasajero1 = (Passenger*) a;
    	pasajero2 = (Passenger*) b;

        if(pasajero1->precio > pasajero2->precio)
        {
           todoOk = 1;

        }

        else if(pasajero1->precio < pasajero2->precio)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
int ordenarPorCodigoVuelo(void* a, void* b)
{
		int todoOk = 0;
	    Passenger* pasajero1 = NULL;
	    Passenger* pasajero2 = NULL;
	    if(a != NULL && b != NULL)
	    {
	    	pasajero1 = (Passenger*) a;
	    	pasajero2 = (Passenger*) b;

	        if(strcmp(pasajero1->codigoVuelo, pasajero2->codigoVuelo) > 0)
	        {
	           todoOk = 1;
	        }else if(strcmp(pasajero1->codigoVuelo, pasajero2->codigoVuelo) < 0)
	        {
	            todoOk = -1;
	        }
	    }

	    return todoOk;
}

int ordenarPorTipoPasajero(void* a, void* b)
{
		int todoOk = 0;
	    Passenger* pasajero1 = NULL;
	    Passenger* pasajero2 = NULL;
	    if(a != NULL && b != NULL)
	    {
	    	pasajero1 = (Passenger*) a;
	    	pasajero2 = (Passenger*) b;

	        if(strcmp(pasajero1->tipoPasajero, pasajero2->tipoPasajero) > 0)
	        {
	           todoOk = 1;
	        }else if(strcmp(pasajero1->tipoPasajero, pasajero2->tipoPasajero) < 0)
	        {
	            todoOk = -1;
	        }
	    }

	    return todoOk;
}

int ordenarPorEstadoVuelo(void* a, void* b)
{
		int todoOk = 0;
	    Passenger* pasajero1 = NULL;
	    Passenger* pasajero2 = NULL;
	    if(a != NULL && b != NULL)
	    {
	    	pasajero1 = (Passenger*) a;
	    	pasajero2 = (Passenger*) b;

	        if(strcmp(pasajero1->estadoVuelo, pasajero2->estadoVuelo) > 0)
	        {
	           todoOk = 1;
	        }else if(strcmp(pasajero1->estadoVuelo, pasajero2->estadoVuelo) < 0)
	        {
	            todoOk = -1;
	        }
	    }

	    return todoOk;
}


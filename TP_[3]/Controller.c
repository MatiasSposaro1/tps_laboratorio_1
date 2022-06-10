#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "funciones.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* archivo;
    archivo = fopen(path, "r");
    if(archivo != NULL && pArrayListPassenger != NULL && path != NULL)
    {
    	parser_PassengerFromText(archivo, pArrayListPassenger);
        retorno = 1;
    }
    fclose(archivo);
    return retorno;
}
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	FILE* p = NULL;

	p = fopen(path,"rb");

	if(p!=NULL && pArrayListPassenger != NULL)
	{
		parser_PassengerFromBinary(p, pArrayListPassenger);
		retorno = 1;
	}

	fclose(p);
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;

    Passenger* auxPassenger = NULL;

    int auxId;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigoVuelo[30];
    int auxtipoPasajero;
    char tipoPasajero[30];
    int auxestadoVuelo;
    char estadoVuelo[30];

    if(pArrayListPassenger != NULL)
    {
    	auxPassenger = Passenger_new();

    	auxId = maxId(pArrayListPassenger);
    	auxId++;

    	auxPassenger = Passenger_new();

    	if(auxPassenger != NULL )
    	{
    			printf("ALTA PASAJERO \n\n");

    			printf("ID:%d\n ",auxId);
    			Passenger_setId(auxPassenger, auxId);

    			getString("Ingrese el nombre: ",nombre);
    			setMayus(nombre, 50);

    		    	while(!Passenger_setNombre(auxPassenger, nombre))
    		    	{
    		    		getString("Error,reingrese el nombre: ",nombre);
    		    	}

    		    	getString("Ingrese el apellido: ",apellido);
    		    	setMayus(apellido,50);
    		    	while(!Passenger_setApellido(auxPassenger, apellido))
    		    	{
    		    		getString("Error,Reingrese el apellido: ",apellido);
    		    	}

    		    	getFloat("Ingrese el precio:$ ",&precio);

    		    	while(!Passenger_setPrecio(auxPassenger, precio))
    		    	{
    		    		getFloat("Error,Reingrese el precio:$ ",&precio);
    		    	}

    		    	printf("Ingrese el codigo de vuelo: \n");
    		    	scanf("%s",codigoVuelo);

    		    	for(int i = 0;codigoVuelo[i];i++)
    		    	{
    		    		codigoVuelo[i] =  toupper(codigoVuelo[i]);
    		    	}

    		    	while(!Passenger_setCodigoVuelo(auxPassenger, codigoVuelo))
    		    	{
    		    		printf("ERROR,Reingre el codigo de vuelo");
    		    		scanf("%s",codigoVuelo);
    		    	}


    		    	getEntero(&auxtipoPasajero, "Ingrese el tipo de pasajero:(1-FirstClass/2-ExecutiveClass/3-EconomyClass)", "Error!Reingrese el tipo de pasajero:(1-FirstClass/2-ExecutiveClass/3-EconomyClass)", 1, 3);

    		    	switch(auxtipoPasajero)
    		    	{
    		    	case 1:
    		    		strcpy(tipoPasajero,"FirstClass");
    		    		break;
    		    	case 2:
    		    		strcpy(tipoPasajero,"ExecutiveClass");
    		    		break;
    		    	case 3:
    		    		strcpy(tipoPasajero,"EconomyClass");
    		    		break;
    		    	}

    		    	Passenger_setTipoPasajero(auxPassenger, tipoPasajero);


    		    	getEntero(&auxestadoVuelo,"Ingrese el estado de vuelo:(1-Aterrizado/2-En Horario/3-En Vuelo/4-Demorado)","ERROR!Reingrese el estado de vuelo:(1-Aterrizado/2-En Horario/3-En Vuelo/4-Demorado)",1,4);

    		    	switch(auxestadoVuelo)
    		    	{
    		    	case 1:
    		    		strcpy(estadoVuelo,"Aterrizado");
    		    		break;
    		    	case 2:
    		    		strcpy(estadoVuelo,"En Horario");
    		    		break;
    		    	case 3:
    		    		strcpy(estadoVuelo,"En Vuelo");
    		    		break;
    		    	case 4:
    		    		strcpy(estadoVuelo,"Demorado");
    		    		break;
    		    	}

    		    	Passenger_setEstadoVuelo(auxPassenger, estadoVuelo);


    		    	ll_add(pArrayListPassenger, auxPassenger);
    		    	printf("Pasajero dado de alta exitosamente");
    		    	retorno = 0;
    	}

    }
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
     int retorno = -1;
	 int id;
	 int indice;
	 int opcion;
	 char nuevoNombre[50];
	 char nuevoApellido[50];
	 float nuevoPrecio;
	 char codigoVuelo[30];
	 int auxTipoPasajero;
	 char tipoPasajero[30];
	 int auxestadoVuelo;
	 char estadoVuelo[30];
	 int ultimoId;
	 char seguir = 's';
	 char confirma;
	 char salir;

	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	 {
		 printf("   *** MODIFICACION PASAJEROS  *** \n\n");

		controller_ListPassenger(pArrayListPassenger);

		ultimoId = maxId(pArrayListPassenger);

		getEntero(&id, "Ingrese el ID del pasajero a modificar: \n", "ERROR! Ingrese el ID del pasajero valido",  1, ultimoId);

		indice = buscarPasajerosId(pArrayListPassenger, id);

		if(indice != -1)
		{
			auxPassenger = ll_get(pArrayListPassenger, indice);

			do
			{
				getEntero(&opcion, "Menu de modificaciones:\n1.Nombre\n2.Apellido\n3.Precio\n4.CodigoVuelo\n5.TipoPasajero\n6.EstadoVuelo\n7.Volver\nIngrese su opcion: ", "ERROR!REINGRESE OPCION..: \n1.Nombre\n2.Apellido\n3.Precio\n4.CodigoVuelo\n5.TipoPasajero\n6.EstadoVuelo", 1, 7);

				switch(opcion)
				{
				case 1:
					getString("Ingrese el nuevo nombre: ",nuevoNombre);
					setMayus(nuevoNombre, 50);

					printf("Confirma cambio nombre? (S/N)\n");
					 scanf("%c", &confirma);
					confirma = toupper(confirma);
					if(confirma == 'S')
					{
						Passenger_setNombre(auxPassenger, nuevoNombre);
						printf("Nombre cambiado con exito \n");
					}
					else
					{
						printf("Edicion cancelada..\n");
					}
					break;
				case 2:
					getString("Ingrese el nuevo apellido: ",nuevoApellido);
					setMayus(nuevoApellido,50);

					printf("Confirma cambio de apellido? (S/N)\n");
					scanf("%c", &confirma);
					confirma = toupper(confirma);
						if(confirma == 'S')
						{
							Passenger_setApellido(auxPassenger, nuevoApellido);
							printf("Apellido cambiado con exito \n");
						}
						else
						{
							printf("Edicion cancelada..\n");
						}
						break;
				case 3:
					getFloat("Ingrese el nuevo precio:$ ",&nuevoPrecio);

					printf("Confirma cambio de precio$? (S/N)\n");
					 scanf("%c", &confirma);
					confirma = toupper(confirma);
						if(confirma == 'S')
						{
						 Passenger_setPrecio(auxPassenger, nuevoPrecio);
						 printf("Precio cambiado con exito \n");
						}
						else
						{
						 printf("Edicion cancelada..\n");
						}
						break;
				case 4:
					printf("Ingrese el nuevo codigo de vuelo: \n");
					scanf("%s",codigoVuelo);

					for(int i = 0;codigoVuelo[i];i++)
					{
					  codigoVuelo[i] =  toupper(codigoVuelo[i]);
					}

					printf("Confirma cambio de codigo de vuelo? (S/N)\n");
					 scanf("%c", &confirma);
					confirma = toupper(confirma);
						      if(confirma == 'S')
							{
							 Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
							 printf("codigo de vuelo cambiado con exito \n");
							}
							 else
							{
							 printf("Edicion cancelada..\n");
							}
					break;

				case 5:
					getEntero(&auxTipoPasajero,
							"Ingrese el tipo de pasajero:(1-FirstClass/2-ExecutiveClass/3-EconomyClass)",
							"Error!Reingrese el tipo de pasajero:(1-FirstClass/2-ExecutiveClass/3-EconomyClass)",
							1, 3);

					switch (auxTipoPasajero)
					{
					case 1:
						strcpy(tipoPasajero, "FirstClass");
						break;
					case 2:
						strcpy(tipoPasajero, "ExecutiveClass");
						break;
					case 3:
						strcpy(tipoPasajero, "EconomyClass");
						break;
					}
					printf("Confirma cambio de codigo de vuelo? (S/N)\n");
					 scanf("%c", &confirma);

					confirma = toupper(confirma);
					if (confirma == 'S')
					{
						Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
						printf("codigo de vuelo cambiado con exito \n");
					} else
					{
						printf("Edicion cancelada..\n");
					}
					break;


					case 6:
					getEntero(&auxestadoVuelo,
							"Ingrese el estado de vuelo:(1-Aterrizado/2-En Horario/3-En Vuelo/4-Demorado)",
							"ERROR!Reingrese el estado de vuelo:(1-Aterrizado/2-En Horario/3-En Vuelo/4-Demorado)",
							1, 4);

					switch (auxestadoVuelo)
						{
					case 1:
						strcpy(estadoVuelo, "Aterrizado");
						break;
					case 2:
						strcpy(estadoVuelo, "En Horario");
						break;
					case 3:
						strcpy(estadoVuelo, "En Vuelo");
						break;
					case 4:
						strcpy(estadoVuelo, "Demorado");
						break;
						}


					printf("Confirma cambio de estado de vuelo? (S/N)\n");
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S') {
						Passenger_setCodigoVuelo(auxPassenger, estadoVuelo);
						printf("estado de vuelo cambiado con exito \n");
					} else {
						printf("Edicion cancelada..\n");
					}
					break;

					case 7:
						 printf("ESTA SEGURO QUE DESA SALIR? (S/N)\n");
						 fflush(stdin);
						 scanf("%c", &salir);
						 salir = toupper(salir);

						 if (salir == 'S')
						    {
						      seguir = 'n';
						    }
						 else
						    {
						         break;
						    }
						break;

					default:
						printf("Opcion invalida\n");
						break;


				   }

			}while(seguir == 's');

		}
		retorno = 0;
	 }
		return retorno;
}




/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	 int retorno = -1;

	 int id;
	 int indice;

	 Passenger* auxPassenger;

	    if(pArrayListPassenger != NULL)
	    {
	        controller_ListPassenger(pArrayListPassenger);

	        printf("Seleccione el ID a borrar: ");
	        scanf("%d", &id);
	        for(int i = 0; i < ll_len(pArrayListPassenger); i++)
	        {
	        	auxPassenger = ll_get(pArrayListPassenger, i);
	            if(auxPassenger->id == id)
	            {
	                indice = i;
	                ll_remove(pArrayListPassenger, indice);
	                retorno = 0;
	                break;
	            }
	        }

	        if(retorno == 1)
	        {
	            printf("Error. No existe el empleado con ID: %d\n", id);
	        }else
	        {
	            printf("Empleado eliminado con exito\n");
	        }
	    }
	    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	Passenger* auxPasajero = NULL;
	int id;
	char nombre[30];
	char apellido[30];
	float precio;
	char codigoVuelo[30];
	char tipoPasajero[30];
	char estadoVuelo[30];

	if(pArrayListPassenger != NULL)
	{
		printf("<--LISTA DE PASAJEROS-->\n");
		printf("  ID   Nombre  \tApellido   Precio  CodigoVuelo  TipoPasajero  EstadoVuelo\n");

		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		   {
		     auxPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

		     Passenger_getId(auxPasajero, &id);
		     Passenger_getNombre(auxPasajero, nombre);
		     Passenger_getApellido(auxPasajero, apellido);
		     Passenger_getPrecio(auxPasajero, &precio);
		     Passenger_getCodigoVuelo(auxPasajero, codigoVuelo);
		     Passenger_getTipoPasajero(auxPasajero, tipoPasajero);
		     Passenger_getEstadoVuelo(auxPasajero, estadoVuelo);


		     printf("%4d%10s    %10s   %2.f  %10s %10s %10s \n", id, nombre, apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		    }
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	  	int retorno = -1;
	    int opcion;
	    int order;
	    if(pArrayListPassenger != NULL)
	    {
	        printf("Menu Ordenar:\n1.Por Nombre.\n2.Por Apellido.\n3.Por Precio.\n4.Por CodigoVuelo.\n5.Por TipoPasajero.\n6 Por EstadoVuelo.\n Escoja su opcion: ");
	        fflush(stdin);
	        scanf("%d", &opcion);

	        printf("Ordenar de manera:\n1 ascendente\n0 descendente: ");
	        fflush(stdin);
	        scanf("%d", &order);

	        switch(opcion)
	        {
	        case 1:
	            ll_sort(pArrayListPassenger, ordenarPorNombre, order);
	            break;
	        case 2:
	            ll_sort(pArrayListPassenger, ordenarPorApellido, order);
	            break;
	        case 3:
	            ll_sort(pArrayListPassenger, ordenarPorPrecio, order);
	            break;
	        case 4:
	            ll_sort(pArrayListPassenger, ordenarPorCodigoVuelo, order);
	            break;
	        case 5:
	        	ll_sort(pArrayListPassenger, ordenarPorTipoPasajero, order);
	        	 break;
	        case 6:
	        	ll_sort(pArrayListPassenger, ordenarPorEstadoVuelo, order);
	        	break;
	        }

	        controller_ListPassenger(pArrayListPassenger);
	        retorno = 1;
	    }
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile = fopen(path,"w");
	Passenger* auxPassenger;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[30];
	float precio;

	if (pFile !=NULL && pArrayListPassenger != NULL)
	{
        fprintf(pFile,"ID,NOMBRE,APELLIDO,PRECIO,TIPO PASAJERO,CODIGO VUELO,ESTADO VUELO\n");
        for(int i = 1; i < ll_len(pArrayListPassenger); i++)
        {
        		auxPassenger = ll_get(pArrayListPassenger, i);

            		Passenger_getId(auxPassenger, &auxId);
                    Passenger_getNombre(auxPassenger, auxNombre);
					Passenger_getApellido(auxPassenger, auxApellido);
					Passenger_getPrecio(auxPassenger, &precio);
					Passenger_getTipoPasajero(auxPassenger, tipoPasajero);
                    Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);
					Passenger_getEstadoVuelo(auxPassenger, estadoVuelo);



                fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", auxId, auxNombre, auxApellido,precio,tipoPasajero,codigoVuelo,estadoVuelo);

        }
        todoOk = 1;
        fclose(pFile);
	}
	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    Passenger* auxPassenger = NULL;
    FILE* f = NULL;
    f = fopen(path, "wb");
    if(f != NULL && pArrayListPassenger != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListPassenger); i++)
        {
        	auxPassenger = ll_get(pArrayListPassenger, i);
            if(auxPassenger != NULL)
            {
               fwrite(auxPassenger, 1 ,sizeof(Passenger), f);
            }
        }
    }

    fclose(f);
    return todoOk;
}

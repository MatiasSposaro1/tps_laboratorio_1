/*
 ============================================================================
 Name        : agenciaViaje.c
 Author      : Matias Sposaro  1°DIV C
 Version     : C
 Description : TrabajoPractico1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;

	float km = 0;

	//Aerolineas
	float precioAerolineas = 0;
	float resultadoDebitoAerolineas = 0;
	float resultadoCreditoAerolineas = 0;
	float resultadoBitcoinAerolineas = 0;
	float resultadoUnitarioAerolineas = 0;
	//Latam
	float precioLatam = 0;
	float resultadoDebitoLatam = 0;
	float resultadoCreditoLatam = 0;
	float resultadoBitcoinLatam = 0;
	float resultadoUnitarioLatam = 0;

	float resultadoDiferencia = 0;

	int flag = 0; //BANDERA 0(SIN CARGA) 1(CARGA)

	do
	{
		printf("***BIENVENIDOS A LA AGENCIA***\n \n");
					printf("1. Ingresar Kilometros: (KM = %f)\n", km);
					printf("2. Ingresar Precio de Vuelos: (Aerolineas = %f,Latam = %f)\n", precioAerolineas,precioLatam);
					printf("3. Calcular todos los costos: \n"
							"\t a) Tarjeta de debito (descuento 10%)\n"
							"\t b) Tarjeta de credito (interes  25%)\n"
							"\t c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
							"\t d) Mostrar precio por km (precio unitario)\n"
							"\t e) Mostrar diferencia de precio ingresada (Latam-Aerolineas)\n");
					printf("4. Informar resultados \n");
					printf("5. Carga forzada de datos\n");
					printf("6. Salir \n");

		printf("Ingrese la opcion que desea: \n");
		scanf("%d",&opcion);


		switch(opcion)
		{

			case 1:
					printf("Ingrese los Kilometros: \n");
					scanf("%f",&km);
					flag = 1;

					while(km <= -1)
					{
						printf("ERROR!,Ingrese kilometros positivos\n");
						scanf("%f",&km);
					}

				break;

			case 2:
				if(flag == 1)
				{
					printf("-Precio vuelo Aerolineas: \n");
					scanf("%f",&precioAerolineas);
					printf("-Precio vuelo Latam: \n");
					scanf("%f",&precioLatam);
					flag = 0;

					while(precioAerolineas < 0 || precioLatam <0)
					{
						printf("ERROR!,Reingrese Precio\n");
						printf("-Precio vuelo Aerolineas: \n");
						scanf("%f",&precioAerolineas);
						printf("-Precio vuelo Latam: \n");
						scanf("%f",&precioLatam);
					}
				}
				else
				{
					printf("Ingrese primero los Kilometros \n");
					system("pause");
				}
				break;

			case 3:
				if(flag == 0)
				{
					printf("CALCULANDO COSTOS..\n");
					system("pause");


					//Aerolineas
					resultadoDebitoAerolineas   = debito(precioAerolineas);
					resultadoCreditoAerolineas  = interes(precioAerolineas);
					resultadoBitcoinAerolineas  = bitcoin(precioAerolineas);
					resultadoUnitarioAerolineas = unitario(precioAerolineas,km);
					//Latam
					resultadoDebitoLatam   = debito(precioLatam);
					resultadoCreditoLatam  = interes(precioLatam);
					resultadoBitcoinLatam  = bitcoin(precioLatam);
					resultadoUnitarioLatam = unitario(precioLatam,km);

					resultadoDiferencia = diferencia(precioAerolineas,precioLatam);

					flag = 1;
				}
				else
				{
					printf("ERROR! Ingrese precios para poder calcular costos\n");
					system("pause");
				}
				break;
			case 4:
				if(flag == 1)
				{
					printf("Kilometros Ingresados: %.2f\n",km);

					printf("Precio Aerolineas: $%.2f \n"
					"\t a)Precio con tarjeta de debito:$ %.2f \n"
					"\t b)Precio con tarjeta de credito:$ %.2f \n"
					"\t c)Precio pagando con bitcoin: %f BTC \n"
					"\t d)Mostrar precio unitario: $ %.2f \n",precioAerolineas,resultadoDebitoAerolineas,resultadoCreditoAerolineas,resultadoBitcoinAerolineas,resultadoUnitarioAerolineas);

					printf("Precio Latam:$%.2f \n"
					"\t a)Precio con tarjeta de debito:$ %.2f  \n"
					"\t b)Precio con tarjeta de credito:$ %.2f \n"
					"\t c)Precio pagando con bitcoin:%f BTC \n"
					"\t d)Mostrar precio unitario: $ %.2f \n",precioLatam,resultadoDebitoLatam,resultadoCreditoLatam,resultadoBitcoinLatam,resultadoUnitarioLatam);


					printf("La diferencia de precio es: $ %.2f \n",resultadoDiferencia);
					flag = 0;
					system("pause");
				}
				else
				{
					printf("Cargue primero precios para calcular el costo \n");
					system("pause");
				}

				break;

			case 5:

				//Datos Harcodeados
				km = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;

				printf("CARGA FORZADA... \n");
				printf("--------------------\n");

				//Aerolineas
				resultadoDebitoAerolineas   = debito(precioAerolineas);
				resultadoCreditoAerolineas  = interes(precioAerolineas);
				resultadoBitcoinAerolineas  = bitcoin(precioAerolineas);
				resultadoUnitarioAerolineas = unitario(precioAerolineas,km);
				//Latam
				resultadoDebitoLatam   = debito(precioLatam);
				resultadoCreditoLatam  = interes(precioLatam);
				resultadoBitcoinLatam  = bitcoin(precioLatam);
				resultadoUnitarioLatam = unitario(precioLatam,km);

				printf("Kilometros Ingresados: %f\n",km);

				printf("Precio Aerolineas: $%.2f \n"
				"\t a)Precio con tarjeta de debito:$ %.2f \n"
				"\t b)Precio con tarjeta de credito:$ %.2f \n"
				"\t c)Precio pagando con bitcoin: %f BTC \n"
				"\t d)Mostrar precio unitario: $ %.2f \n",precioAerolineas,resultadoDebitoAerolineas,resultadoCreditoAerolineas,resultadoBitcoinAerolineas,resultadoUnitarioAerolineas);

				printf("Precio Latam:$%.2f \n"
				"\t a)Precio con tarjeta de debito:$ %.2f  \n"
				"\t b)Precio con tarjeta de credito:$ %.2f \n"
				"\t c)Precio pagando con bitcoin:%f BTC \n"
				"\t d)Mostrar precio unitario: $ %.2f \n",precioLatam,resultadoDebitoLatam,resultadoCreditoLatam,resultadoBitcoinLatam,resultadoUnitarioLatam);

				system("pause");

			break;
			case 6:
				printf("Saliendo..\n");
				break;

			default:
				printf("Opcion invalida!! \n");
				system("pause");

		}

	} while(opcion != 6);

	return EXIT_SUCCESS;
}

/*
Universidad Estatal a Distancia
Escuela de Ciencias Exactas y Naturales
Cátedra de Tecnología de Sistemas

00831 - Introducción a la Programación
Proyecto 2

Estudiante: Daniel Alonso Arce Madrigal
Número de cédula: 0207070451
Centro Universitario: 01 – San José
Grupo: 02

Primer cuatrimestre 2024
*/


/*

sistema_recetas.cpp

Programa para manejar las recetas de una farmacia.

*/

#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>

// Prototipos de función

void imprimir_menu_principal();
int evaluar_opcion(const std::string& entrada_usuario);
int convertir_hilera_entero(const std::string& hilera_usuario);
std::string seleccionar_mensaje_error(const int& codigo_error);
int seleccionar_opcion();
int obtner_codigo();

int main ()
{
    imprimir_menu_principal();
    seleccionar_opcion();
    return 0;
}

// funcióin que permite imprimir el menú en la pantalla

void imprimir_menu_principal()
{
    // Título del menú ajustado al centro de la pantalla
    std::cout << "\n==================================================================\n" << std::endl;
    std::cout << "\t\t SISTEMA DE RECETAS FARMACÉUTICAS \t\t" << std::endl;
    std::cout << "\n==================================================================\n" << std::endl;

    // Cabecera del menú principal
    std::cout << "Menú Principal" << std::endl;
    std::cout << "==============\n" << std::endl;

    // Opciones del menú
    std::cout << "1. Ingresar productos\n" << std::endl;
    std::cout << "2. Ingresar asociaciones con productos\n" << std::endl;
    std::cout << "3. Registrar una receta\n" << std::endl;
    std::cout << "4. Reporte de catálogo de productos\n" << std::endl;
    std::cout << "5. Reporte de impresión de la receta\n" << std::endl;
    std::cout << "6. Salir\n" <<std::endl;
}

// función que evalúa si la opción ingresada por el usuario es válida.
// si la opción es inválida, retorna un entero diferente a 0

int evaluar_opcion(const std::string& entrada_usuario)
{
    int largo_entrada_usuario = entrada_usuario.length();

    if (entrada_usuario.empty())
    {
        return 1;
    }

    else if(largo_entrada_usuario > 1)
    {
        return 2;
    }

    else if(isdigit(entrada_usuario[0]) == 0)
    {
        return 3;
    }

    else if(convertir_hilera_entero(entrada_usuario) < 1 || convertir_hilera_entero(entrada_usuario) > 6 )
    {
        return 4;
    }

    else
    {
        return 0;
    }
}

int convertir_hilera_entero(const std::string& hilera_usuario)
{
    int digito_opcion = stoi(hilera_usuario);
    return digito_opcion;
}

std::string seleccionar_mensaje_error(const int& codigo_error)
{

    std::string error = "";

    if(codigo_error == 1)
    {
        error = "No ingresó ninguna opción. ";
    }

    if(codigo_error == 2)
    {
        error = "Ingresó una entrada de dos o más dígitos/caracteres. ";
    }

    if(codigo_error == 3)
    {
        error = "Ingresó un caracter inválido. ";
    }

    if(codigo_error == 4)
    {
        error = "Ingresó una opción no especificada en el menú. ";
    }

    return error;
}

int seleccionar_opcion()
{
    std::string entrada_usuario = "";
    int codigo_entrada_usuario = 0;
    int opcion_numero = 0;

    std::cout << "Seleccione alguna de las opciones disponibles en el menú al entrar un número del 1 al 6: ";
    getline(std::cin, entrada_usuario);
    std::cout << "" << std::endl;
    codigo_entrada_usuario = evaluar_opcion(entrada_usuario);
    
    if(codigo_entrada_usuario == 0)
    {
        opcion_numero = convertir_hilera_entero(entrada_usuario);

        std::cout << "Usted ha elegido la opcion: " << opcion_numero << "\n" << std::endl;

        return opcion_numero;
    }

    else
    {
        std::string mensaje_error = "ERROR. " + seleccionar_mensaje_error(codigo_entrada_usuario) + "Por favor, inténtelo de nuevo.\n";
        std::cout << mensaje_error << std::endl;

        return 0;
    }
}

int obtner_codigo()
{
    std::string entrada_codigo = "";
    getline(std::cin, entrada_codigo);
    std::cout << "" << std::endl;

    
}
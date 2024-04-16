/*
Universidad Estatal a Distancia
Escuela de Ciencias Exactas y Naturales
Cátedra de Tecnología de Sistemas

00831 - Introducción a la Programación
Proyecto 1

Estudiante: Daniel Alonso Arce Madrigal
Número de cédula: 0207070451
Centro Universitario: 01 – San José
Grupo: 02

Primer cuatrimestre 2024
*/

/*
calculadora_imc.cpp

Calcula el Índice de Masa Corporal (IMC) de una persona según su edad y peso, y determina el diagóstico adecuado de esa persona (peso insuficiente, peso saludable, sobrepeso, obesidad)
*/

// se habilita el componente iostream para usar flujos de entrada, salida y error.
#include <iostream>
// se habilita el componente string.h para usar cadenas de texto.
#include <string.h>
using namespace std;

// Se declaran variables globales

string nombre{""};
string segundo_nombre{""};
string apellido1{""};
string apellido2{""};
string cedula{""};
string diagnostico{""};
double peso = 0;
double estatura = 0;
double imc = 0;

// función para obtener los datos personales del paciente.

void obtener_datos_personales()
{
    cin.ignore(); // se utiliza para pedir el input del primer dato.
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);

    // verificar si el usuario ingresó un dato, si no, debe de intentarlo de nuevo

    while(nombre == "")
    {
        cout << "Debe de ingresar su nombre. Inténtelo de nuevo." << endl;
        cout << "Ingrese su nombre: ";
        getline(cin, nombre);
    }

    cout << "Ingrese su segundo nombre. Si no tiene segundo nombre, presione ENTER: ";
    getline(cin, segundo_nombre);

    cout << "Ingrese su primer apellido: ";
    getline(cin, apellido1);

    // verificar si el usuario ingresó un dato, si no, debe de intentarlo de nuevo

    while(apellido1 == "")
    {
        cout << "Debe de ingresar su primer apellido. Inténtelo de nuevo." << endl;
        cout << "Ingrese su apellido: ";
        getline(cin, apellido1);
    }

    cout << "Ingrese su segundo apellido: ";
    getline(cin, apellido2);

    // verificar si el usuario ingresó un dato, si no, debe de intentarlo de nuevo

    while(apellido2 == "")
    {
        cout << "Debe de ingresar su segundo apellido. Inténtelo de nuevo." << endl;
        cout << "Ingrese su segundo apellido: ";
        getline(cin, apellido2);
    }

    cout << "Ingrese su número de cédula: ";
    getline(cin, cedula);

    // verificar si el usuario ingresó un dato, si no, debe de intentarlo de nuevo

    while(cedula == "")
    {
        cout << "Debe de ingresar su número de cédula. Inténtelo de nuevo." << endl;
        cout << "Ingrese su cédula: ";
        getline(cin, apellido2);
    }

    // Muestra un resumen de los datos ingresados
    cout << "Estos son los datos ingresados\n" << endl;
    cout << "Nombre: " << nombre << " " << segundo_nombre << endl;
    cout << "Apellidos: " << apellido1 << " " << apellido2 << endl;
    cout << "Número de cédula: " << cedula << endl;
    cout << "" << endl;
}

// función para obtener los datos físicos del paciente.

void obtener_datos_fisicos()
{
    cout << "Ingrese su peso en kilogramos: ";
    cin >> peso;

    // verificar si el usuario ingresó un dato, si no, debe de intentarlo de nuevo

    while(peso == 0.0)
    {
        cout << "Debe de ingresar su peso. Inténtelo de nuevo." << endl;
        cout << "Ingrese su peso en kilogramos: ";
        cin >> peso;
    }

    // verificar si el peso está entre los 30 kg y los 350 kg. Si no, debe de intentarlo de nuevo.

    while(peso < 30 || peso > 350)
    {
        cout << "El valor ingresado está fuera del rango. El peso debe de ser un valor entre los 30 y 350 kg. Inténtelo de nuevo.\n" << endl;
        cout << "Ingrese su peso en kilogramos: ";
        cin >> peso;
    }

    cout << "Ingrese su estatura en metros: ";
    cin >> estatura;

    // verificar si el usuario ingresó un dato, si no, debe de intentarlo de nuevo

    while(estatura == 0.0)
    {
        cout << "Debe de ingresar su estatura. Inténtelo de nuevo." << endl;
        cout << "Ingrese su estatura en metros: ";
        cin >> estatura;
    }

    // verificar si el peso está entre los 0.30 m y los 3.00 m. Si no, debe de intentarlo de nuevo.

    while(estatura < 0.30 || estatura > 3.00)
    {
        cout << "El valor ingresado está fuera del rango. La estatura debe de ser un valor entre los 0.30 y 3.00 m. Inténtelo de nuevo.\n" << endl;
        cout << "Ingrese su estatura en metros: ";
        cin >> estatura;
    }

    cout << "Estos son los datos ingresados\n" << endl;
    cout << "Peso (kg): " << peso << endl;
    cout << "Estatura (m): " << estatura << endl;
    cout << "" << endl;
}

// función para calcular el IMC

void calcular_imc()
{
    // se debe verificar si el usuario ha ingresado los datos de su peso. Si no, despliega un mensaje de error.
    if (peso == 0.0 || estatura == 0.0)
    {
        cout << "No ha ingresado datos físicos de la persona. Por favor, ingrese los datos necesarios en la opción 2 del menú principal." << endl;
    }
    else
    {
        imc = peso / (estatura * estatura);
        cout << "Su IMC ha sido calculado. En el menú principal, por favor, eliga la opción 4 para recibir su IMC con su diagnóstico respectivo." << endl;
    }
}

// función para generar el reporte del diagnóstico del paciente

void generar_reporte()
{
    // debe de verificar que el usuario haya entrado todos los datos necesarios. Si falta al menos uno, muestra un mensaje de error.

    if (peso == 0.0 || estatura == 0.0 || nombre == "" || apellido1 == "" || apellido2 == "" || cedula == "")
    {
        cout << "ERROR. Al menos un dato no ha sido reportado. Vuelva al menú principal y asegúrese de entrar todos los datos requeridos." << endl;
    }
    else
    {
        cout << "\n\t\tControl de Peso del paciente\n" << endl;
        cout << "Cédula:\t" << cedula << endl;
        cout << "Nombre:\t" << nombre << " " << apellido1 << " " << apellido2 << endl;
        cout << "" << endl;
        cout << "Peso\t Talla\t IMC" << endl;
        cout << peso << "\t" << estatura << "\t" << imc << "\n" << endl;
        cout << "\t\tDiagnóstico" << endl;

        // muestra el mensaje de diagnóstico de acuerdo al IMC obtenido

        if(imc < 18.5)
        {
            cout << "\t\tSe encuantra dentro del rango de peso insuficiente." << endl;
        }
        else if (imc >= 18.5 || imc <= 24.9)
        {
            cout << "\t\tSe encuantra dentro del rango de peso normal o saludable." << endl;
        }
        else if (imc >= 25.0 || imc <= 29.9)
        {
            cout << "\t\tSe encuantra dentro del rango de sobrepeso." << endl;
        }
        else
        {
            cout << "\t\tSe encuentra dentro del rango de obesidad." << endl;
        }
        cout << "" << endl;
    }

}

// función para reinciar los datos, para que otro usuario pueda entrar sus datos.

void reiniciar_datos()
{
    string nombre{""};
    string apellido1{""};
    string apellido2{""};
    string cedula{""};
    string diagnostico{""};
    double peso{0.0};
    double estatura{0.0};
    double imc{0.0};
}

// Función main que imprime el menú principal

int main ()
{
    int opcion{0}; // inicializa la variable opción para capturar la opción del usuario.
    do
    {
        // se utilizan escapes de retorno para mejor legibilidad del menú
        cout << "" << endl;
        cout << "\t\tCALCULADORA DE ÍNDICE DE MASA CORPORAL (IMC)" << endl;
        cout << "" << endl;
        cout << "MENÚ DE OPCIONES" << endl;
        cout << "" << endl;
        cout << "1) Ingresar datos de identificación" << endl;
        cout << "2) Ingresar datos físicos" << endl;
        cout << "3) Calcular el IMC" << endl;
        cout << "4) Desplegar reporte de la información del paciente" << endl;
        cout << "5) Salir" << endl;
        cout << "" << endl;

        // pide la entrada al usuario de la opción correspondiente
        cout << "¿Cuál opción desea seleccionar? ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                cout << "\nUsted eligió la opción 1." << endl;
                obtener_datos_personales();
                break;
            case 2: 
                cout << "\nUsted eligió la opción 2." << endl;
                obtener_datos_fisicos();
                break;
            case 3: 
                cout << "\nUsted eligió la opción 3." << endl;
                calcular_imc();
                break;
            case 4: 
                cout << "\nUsted eligió la opción 4." << endl;
                generar_reporte();
                break;
            case 5:
                cout << "\nUsted eligió la opción 5. Saliendo del programa." << endl;
                break;
            default:
                cout << "\nLa opción ingresada no es válida. Por favor, inténtelo de nuevo." << endl;
                break;
        }           
    } while (opcion != 5);

    // reinicia los datos para que se ingresen los datos de otro usuario.
    reiniciar_datos();

    return 0;
}
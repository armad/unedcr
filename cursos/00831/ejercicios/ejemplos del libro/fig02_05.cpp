// Fig. 2.5: fig02_05.cpp
// Programa de suma que muestra la suma de dos enteros.

#include <iostream> // habilita al programa para realizar operaciones de entrada y salida

// la función main comienza la ejecución del programa
int main() {
    // declarando e inicializando variables
    int numero1{0};
    int numero2{0};
    int suma{0};

    std::cout << "Escriba el primer entero: "; // solicitar datos al usuario
    std::cin >> numero1; // lee el primer entero del usuario y lo guarda en numero1
    

    std::cout << "Escriba el segundo entero: "; // solicitar datos al usuario
    std::cin >> numero2; // lee el segundo entero del usuario y lo guarda en numero2

    suma = numero1 + numero2; // suma los resultados; almacena el resultado en la suma

    std::cout << "La suma es " << suma << std::endl; // muestra suma; línea final
} // find de la función principal
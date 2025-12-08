// Trabajo POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

int main()
{
    int opcm;
    int opcc;
    int opcb;
    int opce;
    int opcj;
    std::cout << "########## Libreria Universitaria Central ##########" << std::endl;
    std::cout << "############ Que te gustaria realizar? ############" << std::endl;
    std::cout << "##### Opcion 1: Ver catalogo #####" << std::endl;
    std::cout << "##### Opcion 2: Ver usuario #####" << std::endl;
    std::cout << "##### Opcion 3: Salir #####" << std::endl;
    std::cin >> opcm;
    do {
        switch (opcm)
        {
        case 1:
            std::cout << "##### Catalogo #####" << std::endl;
            std::cout << "############ A que te gustaria acceder? ############" << std::endl;
            std::cout << "##### Opcion 1: Libro #####" << std::endl;
            std::cout << "##### Opcion 2: E-Book #####" << std::endl;
            std::cout << "##### Opcion 3: Diario #####" << std::endl;
            std::cout << "##### Opcion 4: Salir #####" << std::endl;
            std::cin >> opcc;
            do {
                switch (opcc)
                {
                case 1:
                    std::cout << "############ Libros? ############" << std::endl;
                    std::cout << "##### Opcion 1: anadir Libro #####" << std::endl;
                    std::cout << "##### Opcion 2: eliminar Libro #####" << std::endl;
                    std::cout << "##### Opcion 3: editar Libro #####" << std::endl;
                    std::cin >> opcb;
                    break;
                    switch (opcb)
                    {
                    case 1:

                        break;
                    case 2:

                        break;
                    case 3:

                        break;
                }
                case 2:
                    std::cout << "############ E-Book ############" << std::endl;
                    std::cout << "##### Opcion 1: anadir E-book #####" << std::endl;
                    std::cout << "##### Opcion 2: eliminar E-book #####" << std::endl;
                    std::cout << "##### Opcion 3: editar E-book #####" << std::endl;
                    std::cout << "##### Opcion 4: Salir #####" << std::endl;
                    std::cin >> opce;
                    do {


                        switch (opce)
                        {
                        case 1:

                            break;
                        case 2:

                            break;
                        case 3:

                            break;
                        }

                    } while (opce != 4);
                    break;
                case 3:
                    std::cout << "############ Diarios ############" << std::endl;
                    std::cout << "##### Opcion 1: anadir Diario #####" << std::endl;
                    std::cout << "##### Opcion 2: eliminar Diario #####" << std::endl;
                    std::cout << "##### Opcion 3: editar Diario #####" << std::endl;
                    std::cout << "##### Opcion 4: Salir #####" << std::endl;
                    std::cin >> opcj;
                    do {
                        switch (opcj)
                        {
                        case 1:

                            break;
                        case 2:

                            break;
                        case 3:

                            break;
                        }

                    } while (opcj != 4);
                    break;


                default:
                    std::cout << "Introduzca una opcion valida" << std::endl;
                    break;
                } 
               
                
            } while (opcc != 4);
                break;
            
            
        case 2:
            std::cout << "##### Usuario #####" << std::endl;
            std::cout << "############ Que te gustaria hacer? ############" << std::endl;
            std::cout << "##### ID de usuario: #####" << std::endl;
            std::cout << "##### Nombre de usuario: #####" << std::endl;
            std::cout << "##### Rol de usuario: #####" << std::endl;
            std::cout << "##### Prestamo activo: #####" << std::endl;
            std::cout << "##### Comienzo de prestamo: #####" << std::endl;
            std::cout << "##### Limite de prestamo: #####" << std::endl;
            std::cout << "##### Exceso del limite de prestamo: #####" << std::endl;
            std::cout << "##### Sancion: #####" << std::endl;
            std::cout << "##### Bloqueado: #####" << std::endl;
            std::cout << "##### Salir #####" << std::endl;
            
        deafult:
            std::cout << "Introduzca una opcion valida" << std::endl;
            break;

        }

    } while (opcm != 3);
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

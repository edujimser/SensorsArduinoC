#ifndef MENSAJE_RELASE_H
#define MENSAJE_RELASE_H

//Headers necesarios para Arduino
#include <Arduino.h> 

/**
 * @brief Imprime un mensaje de log enriquecido en el monitor serial.
 *
 * Esta función debe ser definida en el archivo fuente (.cpp) correspondiente.
 * Genera una salida estructurada que incluye:
 * - Fecha y hora de compilación
 * - Archivo fuente desde donde se llama
 * - Nombre de la función invocadora
 * - Mensaje personalizado
 *
 * El formato de salida es:
 * [fecha hora] archivo::funcion ➤ mensaje
 *
 * Ejemplo:
 * [Aug 7 2025 01:23:00] main.cpp::setup ➤ Iniciando sistema...
 *
 * @param mensaje  Texto personalizado que se desea imprimir
 * @param archivo  Nombre del archivo fuente (__FILE__)
 * @param funcion  Nombre de la función que llama (__FUNCTION__)
 * @param fecha    Fecha de compilación (__DATE__)
 * @param hora     Hora de compilación (__TIME__)
 */
void mensajeEstandar(const char* mensaje, const char* archivo, const char* funcion, const char* fecha, const char* hora);

#endif // MENSAJE_RELASE_H

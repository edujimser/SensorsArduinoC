#include "msg/msg.h"

/**
 * @brief Imprime un mensaje de log enriquecido en el monitor serial.
 *
 * Esta función genera una salida estructurada que incluye:
 * - La fecha y hora de compilación del programa
 * - El nombre del archivo fuente desde donde se llama
 * - El nombre de la función que invoca el mensaje
 * - El contenido del mensaje personalizado
 *
 * El formato de salida es el siguiente:
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
void mensajeEstandar(const char* mensaje, const char* archivo, const char* funcion, const char* fecha, const char* hora) {
  Serial.print("[");
  Serial.print(fecha);
  Serial.print(" ");
  Serial.print(hora);
  Serial.print("] ");
  Serial.print(archivo);
  Serial.print("::");
  Serial.print(funcion);
  Serial.print(" ➤ ");
  Serial.println(mensaje);
}

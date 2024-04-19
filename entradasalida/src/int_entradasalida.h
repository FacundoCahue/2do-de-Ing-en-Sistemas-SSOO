#ifndef INIT_ENTRADASALIDA_H
#define INIT_ENTRADASALIDA_H

#include <stdio.h>
#include <stdbool.h>
#include <commons/config.h>
#include <commons/string.h>
#include <commons/log.h>
#include <utils/socket.h>
#include <utils/shared.h>

typedef struct
{
  char* tipo_interfaz;
  int tiempo_unidad_trabajo;
  char* ip_kernel;
  int puerto_kernel;
  char* ip_memoria;
  int puerto_memoria;
  char* path_base_dialfs;
  int block_size;
  int block_count;
}t_config_k;

// Funcion para cargar configuraciones de I/O:
int cargar_configuraciones(t_config_k *config_entradasalida, t_log *logger);

// Funciones para manejo de clientes y conexiones del modulo:
int generar_conexiones(t_log *logger, t_config_k *config_entradasalida, int *md_memoria, int *md_kernel);

// Funciones de operaciones basicas del modulo:
void cerrar_programa(t_log *logger, t_config_k *config_entradasalida, int md_memoria, int md_kernel);

#endif // INIT_ENTRADASALIDA_H
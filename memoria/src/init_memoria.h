#ifndef INIT_MEMORIA_H
#define INIT_MEMORIA_H

#include <stdio.h>
#include <stdbool.h>
#include <commons/config.h>
#include <commons/string.h>
#include <commons/log.h>
#include <utils/socket.h>
#include <utils/shared.h>
#include <utils/estructuras_compartidas.h>
#include <pthread.h>

typedef struct 
{
    int puerto_escucha;
    int tam_memoria;
    int tam_pagina;
    char* path_instrucciones;
    int retardo_respuesta;
} t_config_memoria;

// Funcion para cargar configuraciones de Memoria:
int cargar_configuraciones(t_config_memoria *t_config_memoria, t_log *logger_memoria);

// Funciones para manejo de clientes y conexiones del modulo:
int crear_servidores(t_log* logger_memoria, t_config_memoria* config_memoria, int* md_generico);

// Funciones de operaciones basicas del modulo:
void iniciar_modulo(t_log* logger_memoria, t_config_memoria* t_config_memoria);
void cerrar_programa(t_log *logger_memoria, t_config_memoria *config_memoria);


#endif // INIT_MEMORIA_H
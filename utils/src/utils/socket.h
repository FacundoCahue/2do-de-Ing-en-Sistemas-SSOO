#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <commons/log.h>
#include <commons/collections/list.h>
#include <assert.h>
typedef enum
{
	MENSAJE,
	PAQUETE
} op_code;

typedef struct
{
	int size;
	void *stream;
} t_buffer;

typedef struct
{
	op_code codigo_operacion;
	t_buffer *buffer;
} t_paquete;




int crear_conexion(t_log *logger, const char *server_name, char *ip, char *puerto);
void enviar_mensaje(char *mensaje, int socket_cliente);
t_paquete *crear_paquete(void);
void agregar_a_paquete(t_paquete *paquete, void *valor, int tamanio);
void enviar_paquete(t_paquete *paquete, int socket_cliente);
void liberar_conexion(int socket_cliente);
void eliminar_paquete(t_paquete *paquete);
void *recibir_buffer(int *, int);
int iniciar_servidor(t_log *logger, const char *name, char *ip, char *puerto);
int esperar_cliente(t_log *logger, const char *name, int socket_servidor);
t_list *recibir_paquete(int);
void recibir_mensaje(int);
int recibir_operacion(int);
void atender_conexion(t_log* logger, char* server_name, int cliente_socket);

#endif /* UTILS_H_ */
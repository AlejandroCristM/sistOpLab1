#ifndef _PROCESS_H_
#define _PROCESS_H_

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
* Estructura para guardar el  process.pid
* @id: Identificaci[on del proceso]
* @name_process: Nombre identificacion del proceso
*/

typedef struct pds_p
{
	int id;
	char *name_process;
}pds_t;

/* Integer to ASCII for signed decimal integers. */
static int next;
static char qbuf[8];

// Declaracion prototipo de funciones
char *_itoa(int n);
int print_stack(pds_t *process, char **argv);
int assign_values(int id, char *name_process, char **argv);
char *nombre_process(int id);
int name_process_with_id(int id, char **argv);
int new_process(int argc, char **list, char **argv);
int array(int argc, char **argv);
int error_arguments(void);
int _strcmp(char *strings, char *string);
int init_room(int argc, char **argv);

#endif /*_PROCESS_H_*/

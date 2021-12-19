#include "process.h"

int assign_values(int id, char *name_process, char **argv){
	
	pds_t *name;
	name = malloc(sizeof(pds_t));
	if(name == NULL){
		free(name);
		return EXIT_FAILURE;
	}
	name->id = id;
	name->name_process = name_process;
	print_stack(name,argv);
	free(name);
	return EXIT_SUCCESS;
}
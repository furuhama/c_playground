#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>

#define STRSIZE 64

void dump(char *name);
void dump_local_section(void);

char not_initialized_global_section[STRSIZE];
char initialized_global_section[STRSIZE] = "initialized global section";

int main(int argc, char *argv[]) {
  static char not_initialized_static_section[STRSIZE];
  static char initialized_static_section[STRSIZE] = "initialized static section";
  char *malloc_section;
  int shmid;
  char *shared_memory_section;
  char *big_malloc_section;
  char *medium_malloc_section_1;
  char *medium_malloc_section_2;

  strcpy(not_initialized_global_section, "not initialized global section");

  strcpy(not_initialized_static_section, "not initialized static section");

  malloc_section = (char *) malloc(sizeof(char) * STRSIZE);
  strcpy(malloc_section, "malloc section");

  shmid = shmget(IPC_PRIVATE, sizeof(char) * STRSIZE, 0666 | IPC_CREAT);
  shared_memory_section = (char *) shmat(shmid, 0, 0);
  strcpy(shared_memory_section, "shared memory section");

  big_malloc_section = (char *) malloc(256 * 1024);
  strcpy(big_malloc_section, "big malloc section");

  medium_malloc_section_1 = (char *) malloc(131 * 1024 + 905);
  strcpy(medium_malloc_section_1, "medium malloc section 1");

  medium_malloc_section_2 = (char *) malloc(131 * 1024 + 904);
  strcpy(medium_malloc_section_2, "medium malloc section 2");

  dump(argv[1]);
  dump(not_initialized_global_section);
  dump(initialized_global_section);
  dump(not_initialized_static_section);
  dump(initialized_static_section);
  dump(malloc_section);
  dump(shared_memory_section);
  dump(big_malloc_section);
  dump(medium_malloc_section_1);
  dump(medium_malloc_section_2);
  dump_local_section();

  getchar(); // stop here

  free(malloc_section);
  shmdt(shared_memory_section);
  shmctl(shmid, IPC_RMID, 0);
  free(big_malloc_section);
  free(medium_malloc_section_1);
  free(medium_malloc_section_2);

  return 0;
}

void dump(char *name) {
  printf("dump, %s: 0x%016lx\n", name, name);
}

void dump_local_section(void) {
  char local_section[STRSIZE];

  strcpy(local_section, "local section");
  dump(local_section);
}

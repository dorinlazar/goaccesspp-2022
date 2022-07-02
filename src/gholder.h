#pragma once

#define MTRC_ID_COUNTRY 0
#define MTRC_ID_CITY 1
#define MTRC_ID_HOSTNAME 2

#include "commons.h"
#include "sort.h"

/* Default Anonymization Levels */
typedef enum GAnonymizeLevels_ {
  ANONYMIZE_DEFAULT = 1,
  ANONIMYZE_STRONG,
  ANONIMYZE_PEDANTIC,
} GAnonymizeLevels;

/* Function Prototypes */
GHolder* new_gholder(uint32_t size);
void* add_hostname_node(void* ptr_holder);
void free_holder_by_module(GHolder** holder, GModule module);
void free_holder(GHolder** holder);
void load_holder_data(GRawData* raw_data, GHolder* h, GModule module, GSort sort);
void load_host_to_holder(GHolder* h, char* ip);
int dup_key_list(void* val, GSLList** user_data);

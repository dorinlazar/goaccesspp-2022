#pragma once
#ifndef CSV_H_INCLUDED
#define CSV_H_INCLUDED

#include <stdio.h>
#include "parser.h"
#include "settings.h"

void output_csv(GHolder* holder, const char* filename);

#endif

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void game();
void getQuestion();
void setMoney();

void file_reader(const char* path, const char* flag);

extern char question[5][128];

#endif

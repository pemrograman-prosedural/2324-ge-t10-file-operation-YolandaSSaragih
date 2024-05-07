#ifndef DORM_H
#define DORM_H

#include "gender.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
  void (*print_dorm_all_detail)(struct dorm_t*,int size);
  int printed_before;
};

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);
void print_dorm_all_detail(struct dorm_t *dorms, int size);

#endif
#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
  char lines[32][256];
  int count;
} Block;

Block get_info();
char* get_logo();

#endif

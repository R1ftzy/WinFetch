#include <stdio.h>
#include <string.h>
#include "config.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

Block parse_logo(const char* path){
  Block logo;
  logo.count = 0;
  int width = 0;
  FILE* fp = fopen(path, "r");
  if (!fp) return logo;
  char buffer[256];
  while (fgets(buffer, sizeof(buffer), fp)) {
    buffer[strcspn(buffer, "\n")] = '\0';
    int len = strlen(buffer);
    if (len > width) width = len;
    
    strncpy(logo.lines[logo.count++], buffer, 256);
  }
  fclose(fp);

  for (int i = 0; i < logo.count; i++) {
    int len = strlen(logo.lines[i]);
    for (int j = len; j < width; j++) {
      logo.lines[i][j] = ' ';
    }
    logo.lines[i][width] = '\0';
  }
  return logo;
}

Block render(Block logo, Block info){
  Block output;
  output.count = MAX(logo.count, info.count);
  for (int i = 0; i < MIN(logo.count, info.count); i++) {
    snprintf(output.lines[i], 256, "%s   %s", logo.lines[i], info.lines[i]);
  }
  if (logo.count > info.count)
    for (int i = MIN(logo.count, info.count); i < MAX(logo.count, info.count); i++) 
      snprintf(output.lines[i], 256, "%s", logo.lines[i]);
  else
    for (int i = MIN(logo.count, info.count); i < MAX(logo.count, info.count); i++) 
      snprintf(output.lines[i], 256, "%s", info.lines[i]);
  return output;
}

#include "hardware.h"
#include "sysinfo.h"
#include "memory.h"
#include <stdio.h>

int main(){
  printf("|==============================================|\n");
  printf("Host:     %s@%s\n", get_user(), get_hostname());
  printf("Model:    %s\n", get_device_clean());
  printf("OS:       %s\n", get_os());
  printf("Shell:    %s\n", get_shell());
  printf("Terminal: %s\n", get_terminal());
  printf("|==============================================|\n");
  printf("CPU: %s (%s)\n", get_cpu(), get_logical_cores());
  printf("Architecture: %s\n", get_architecture());
  printf("Display: %s@%s\n", get_resolution_primary(), get_refresh_rate());
  printf("Memory: %s/%s (free)\n", get_ram_available(), get_ram_total());
  printf("|==============================================|\n");
}
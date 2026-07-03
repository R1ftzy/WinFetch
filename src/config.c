#include <stdio.h>
#include "hardware.h"
#include "sysinfo.h"
#include "memory.h"
#include "gpu.h"
#include "battery.h"

typedef struct {
  char lines[32][256];
  int count;
} Block;
// DONT ADD '\n', Instead create a new snprintf(...) line for each new line
// snprintf(info.lines[info.count++], 256, "");
Block get_info(){
  Block info;
  info.count = 0;
  snprintf(info.lines[info.count++], 256, "");
  snprintf(info.lines[info.count++], 256,"╔═══════════╤═══%s@%s═══════════════╗", get_user(), get_hostname());
  snprintf(info.lines[info.count++], 256,"  Model     │ %s", get_device_clean());
  snprintf(info.lines[info.count++], 256,"╠═══════════╪═══════════════════════════════════════╣");
  snprintf(info.lines[info.count++], 256,"  OS        │ %s", get_os_clean());
  snprintf(info.lines[info.count++], 256,"  Shell     │ %s", get_shell());
  snprintf(info.lines[info.count++], 256,"  Terminal  │ %s", get_terminal());
  snprintf(info.lines[info.count++], 256,"╠═══════════╪═══════════════════════════════════════╣");
  snprintf(info.lines[info.count++], 256,"  CPU       │ %s (%s)", get_cpu(), get_logical_cores());
  snprintf(info.lines[info.count++], 256,"  Arch      │ %s", get_architecture());
  snprintf(info.lines[info.count++], 256,"  Display   │ %s@%shz", get_resolution_primary(), get_refresh_rate());
  snprintf(info.lines[info.count++], 256,"  Memory    │ %s/%s (free)", get_ram_available(), get_ram_total());
  snprintf(info.lines[info.count++], 256,"  GPU       │ %s", get_gpu());
  snprintf(info.lines[info.count++], 256,"  VRAM      │ %s (total)", get_vram());
  snprintf(info.lines[info.count++], 256,"╠═══════════╪═══════════════════════════════════════╣");
  snprintf(info.lines[info.count++], 256,"  Battery   │ %s (%s) @ %s", get_battery_percentage(), get_battery_status(), get_battery_rate());
  snprintf(info.lines[info.count++], 256,"╚═══════════╧═══════════════════════════════════════╝");
  snprintf(info.lines[info.count++], 256, "");
  snprintf(info.lines[info.count++], 256, "");
  return info;
}

char* get_logo(){
  // write name of the logo txt file here
  // Alternatively can also add the name of logo when running winfetch as an cli argument
  return "windows_11.txt";
}
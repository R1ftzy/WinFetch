#include <stdio.h>
#include <windows.h>
#include <powrprof.h>

char* get_battery_status(){
  SYSTEM_POWER_STATUS s;
  GetSystemPowerStatus(&s);
  if (s.ACLineStatus == 0)
    return "Discharging";
  else if (s.ACLineStatus == 1)
    return "Charging";
  else
    return "unknown";
}

char* get_battery_percentage(){
  SYSTEM_POWER_STATUS s;
  GetSystemPowerStatus(&s);
  static char percent[8];
  snprintf(percent, sizeof(percent), "%i%%", s.BatteryLifePercent);
  return percent;
}

char* get_battery_life(){
  SYSTEM_POWER_STATUS s;
  GetSystemPowerStatus(&s);
  if (s.BatteryLifeTime == 0xFFFFFFFF)
    return "N/A";
  static char life[16];
  int lifeHR = s.BatteryLifeTime / 3600;
  int lifeMin = (s.BatteryLifeTime % 3600)/60;
  snprintf(life, sizeof(life), "%iHr %imin", lifeHR, lifeMin);
  return life;
}

char* get_battery_rate(){
  SYSTEM_BATTERY_STATE s;
  CallNtPowerInformation(SystemBatteryState, NULL, 0, &s, sizeof(s));
  static char ch[8];
  float rate = (float)s.Rate / 1000;
  if (rate < 0)
    snprintf(ch, sizeof(ch), "%.1fW", -rate);
  else
    snprintf(ch, sizeof(ch), "+%.1fW", rate);
  return ch;
}

// char* get_battery_health(){
//   SYSTEM_BATTERY_STATE s;
//   CallNtPowerInformation(SystemBatteryState, NULL, 0, &s, sizeof(s));
//   static char health[8];
//   snprintf(health, sizeof(health), "%.1f%%", (float)s.RemainingCapacity / (float)s.MaxCapacity * 100);
//   return health;
// }

// char* get_battery_capacity(){
//   SYSTEM_BATTERY_STATE s;
//   CallNtPowerInformation(SystemBatteryState, NULL, 0, &s, sizeof(s));
//   static char health[8];
//   snprintf(health, sizeof(health), "%.2fWh", (float)s.RemainingCapacity / 1000);
//   return health;
// }

char* get_battery_max_capacity(){
  SYSTEM_BATTERY_STATE s;
  CallNtPowerInformation(SystemBatteryState, NULL, 0, &s, sizeof(s));
  static char health[8];
  snprintf(health, sizeof(health), "%.2fWh", (float)s.MaxCapacity / 1000);
  return health;
}

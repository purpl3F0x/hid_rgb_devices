/*  
*   main.cpp
*   -------------------------
*   Enter Description
*   -------------------------
*   Stavros Avramidis	3/7/2019
*/

#include <stdio.h>

#include "aura_hid.hpp"
#include "galax_hof_link.hpp"

int main() {
  AuraHIDDevices aura_devs;

  auto n = detectAuraHIDDevice(aura_devs);


  if (!n) {
    printf("Didn't found any AURA ARGB devices\n");
    return 1;
  } else {
    printf("Found %d %s\n", n, (n==1 ? "device" : "devices"));
  }

  int     res;
  uint8_t buf[AURA_ARGB_MSG_LEN];
  #define MAX_STR 255
  wchar_t wstr[MAX_STR];
  hid_device* handle;

  printf("\nOpening Controller 1...\n");
  handle = hid_open(aura_devs[0].vendor_id, aura_devs[0].product_id, nullptr);
  if (!handle) {
    printf("unable to open device\n");
    return 1;
  }

  printf("Device Opened\n");

  // Read the Manufacturer String
  res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
  wprintf(L"\t%ls\n", wstr);


  // Create msg in buffer
  buf[0] = MSG_START;
  buf[1] = AURA_EFFECT_MODE;    // Control Mode
  buf[2] = 0x0;                 // Device
  buf[3] = 0x0;                 // Initial LED position
  buf[4] = AURA_MODE_STATIC;    // Effect

  for (auto v = 5; v < AURA_ARGB_MSG_LEN; v += 3) {
    buf[v]     = 90;
    buf[v + 1] = 60;
    buf[v + 2] = 90;
  }

  // Write to device
  hid_write(handle, buf, AURA_ARGB_MSG_LEN);

  // Close connection to device
  hid_close(handle);



  /* HOF link */
  HofLinks hof_links;

  if (detectHOFLinks(hof_links)) {
    hof_links[0].init();
    hof_links[0].setColor(90, 60, 90);
  }

}


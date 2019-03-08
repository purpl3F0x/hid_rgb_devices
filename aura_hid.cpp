/*
 *  @file:           aura_hid.cpp
 *  @Author:         Stavros Avramidis
 *  @date:           3/7/2019
*/

#include "aura_hid.hpp"

Aura_hid::Aura_hid(hid_device_info& base) : Ligthing_hid_device_info(base) {
  return;
}

uint8_t detectAuraHIDDevice(AuraHIDDevices& aura_devs) {
  uint8_t numOfDevs = 0;
  struct hid_device_info* devs, * cur_dev;

  devs    = hid_enumerate(0x0, 0x0);
  cur_dev = devs;
  while (cur_dev) {
    if (wcsncmp(cur_dev->product_string, L"AURA", 4)==0) {
      numOfDevs++;
      aura_devs.emplace_back(Aura_hid(*cur_dev));
    }
    cur_dev = cur_dev->next;
  }
  hid_free_enumeration(devs);
  hid_exit();
  return numOfDevs;
}
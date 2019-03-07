/*
 *  @file:           galax_hof_link.cpp
 *  @Author:         Stavros Avramidis
 *  @date:           3/7/2019
 */

#include "galax_hof_link.hpp"

Hof_link_hid::Hof_link_hid(hid_device_info& base) : Ligthing_hid_device_info(base) {
  return;
}

uint8_t detectHOFLinks(HofLinks& hof_devs) {
  uint8_t numOfDevs = 0;
  struct hid_device_info* devs, * cur_dev;

  devs    = hid_enumerate(0x0C45, 0x7302);
  cur_dev = devs;
  while (cur_dev) {
    numOfDevs++;
   hof_devs.emplace_back(Hof_link_hid(*cur_dev));
    cur_dev = cur_dev->next;
  }
  hid_free_enumeration(devs);
  hid_exit();
  return numOfDevs;
}
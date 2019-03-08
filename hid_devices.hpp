/*
 *  @file:           hid_devices.hpp
 *  @Author:         Stavros Avramidis
 *  @date:           3/7/2019
 *  @description:    Custom HID device class for addressable devices
 */

#pragma once

/* C */
#include <cinttypes>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
/* C++ */
#include <iostream>
#include <vector>
/* local  */
#include "hidapi.h"

#pragma comment(lib, "hidapi.lib")

struct Ligthing_hid_device_info : public hid_device_info {
  hid_device* handle;
  uint8_t numOfLeds;
  /* Constructor for copying hid_device_info obj */
  explicit Ligthing_hid_device_info(hid_device_info& base, uint8_t nOfLeds = 1);
  /* Constructor */
  ~Ligthing_hid_device_info();

  /* Opens HID handle */
  bool init();
};

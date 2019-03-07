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
  uint8_t numOfLeds;

  explicit Ligthing_hid_device_info(hid_device_info& base);
};

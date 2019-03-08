/*  
 *  @file:           hid_devices.cpp
 *  @Author:         Stavros Avramidis
 *  @date:           3/7/2019
 */

#include "hid_devices.hpp"

Ligthing_hid_device_info::Ligthing_hid_device_info(hid_device_info& base, uint8_t nOfLeds) : numOfLeds(nOfLeds), handle(
    nullptr) {
  size_t len;

  len = strlen(base.path);
  this->path = (char*) malloc((len + 1)*sizeof(char));
  strncpy(this->path, base.path, len + 1);
  this->path[len] = '\0';

  if (base.serial_number) {
    len = wcslen(base.serial_number);
    this->serial_number = (wchar_t*) malloc((len + 1)*sizeof(wchar_t));
    wcsncpy(this->serial_number, base.serial_number, len + 1);
    this->path[len] = '\0';
  }

  len = wcslen(base.manufacturer_string);
  this->manufacturer_string = (wchar_t*) malloc((len + 1)*sizeof(wchar_t));
  wcsncpy(this->manufacturer_string, base.manufacturer_string, len + 1);
  this->path[len] = '\0';

  len = wcslen(base.product_string);
  this->product_string = (wchar_t*) malloc((len + 1)*sizeof(wchar_t));
  wcsncpy(this->product_string, base.product_string, len + 1);
  this->path[len] = '\0';

  this->vendor_id        = base.vendor_id;
  this->product_id       = base.product_id;
  this->release_number   = base.release_number;
  this->usage_page       = base.usage_page;
  this->usage            = base.usage;
  this->interface_number = base.interface_number;
}

Ligthing_hid_device_info::~Ligthing_hid_device_info() {
  hid_close(handle);
}

bool Ligthing_hid_device_info::init() {
  this->handle = hid_open(vendor_id, product_id, nullptr);
  return handle!=nullptr;
}
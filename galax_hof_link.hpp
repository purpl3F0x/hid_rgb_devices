/*
 *  @file:           galax_hof_link.hpp
 *  @Author:         Stavros Avramidis
 *  @date:           3/7/2019
 *  @description:    struct for controlling Galax/KFA2 HOF LINK
 */

// TODO: fix hardcoded detection

#pragma once

#include "hid_devices.hpp"

struct Hof_link_hid: public Ligthing_hid_device_info{
  explicit Hof_link_hid (hid_device_info& base);
};

typedef std::vector<Hof_link_hid> HofLinks;

uint8_t detectHOFLinks(HofLinks& hof_devs);

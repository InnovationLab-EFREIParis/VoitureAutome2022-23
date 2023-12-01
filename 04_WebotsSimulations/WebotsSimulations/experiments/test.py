#!/usr/bin/env python3
from __future__ import print_function
import pyudev

context = pyudev.Context()

def device_by_id(id_vendor, id_product):
    match_devices = []
    for dev in context.list_devices(subsystem='tty'):
            
        try:
            idVendor = dev.properties['ID_VENDOR_ID']
            idProduct = dev.properties['ID_MODEL_ID']
        except :
                continue
        if idVendor == id_vendor and idProduct == id_product:
            match_devices.append(dev)
    return match_devices


def find_single_device(id_vendor, id_product):
    devs = device_by_id(id_vendor, id_product)
    if len(devs) == 0:
        msg = "Unable to find device with idVendor={} and idProduct={}"
        raise ValueError(msg.format(id_vendor, id_product))
    elif len(devs) > 1:
        msg = "Found multiple devices with idVendor={} and idProduct={}"
        raise ValueError(msg.format(id_vendor, id_product))
    else:
        return devs[0].device_node


ard = find_single_device('03eb', '2145')
print("Found ard on port", ard)

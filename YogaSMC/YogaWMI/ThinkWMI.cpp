//  SPDX-License-Identifier: GPL-2.0-only
//
//  ThinkWMI.cpp
//  YogaSMC
//
//  Created by Zhen on 6/27/20.
//  Copyright © 2020 Zhen. All rights reserved.
//

#include "ThinkWMI.hpp"
OSDefineMetaClassAndStructors(ThinkWMI, YogaWMI);

IOService *ThinkWMI::probe(IOService *provider, SInt32 *score)
{
    if (/* DISABLES CODE */ (false)) {
        IOLog("%s::%s not a valid ThinkPad WMI interface", getName(), provider->getName());
        return NULL;
    }
    // TODO: identify an appropritate interface to attach

    return super::probe(provider, score);
}

void ThinkWMI::stop(IOService *provider) {
    if (dev)
        dev->stop(vpc);
    super::stop(provider);
}

void ThinkWMI::free(void)
{
    if (dev)
        dev->free();
    super::free();
}

bool ThinkWMI::initVPC() {
    dev = ThinkVPC::withDevice(vpc, getPnp());
    return true;
}

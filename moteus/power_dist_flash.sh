#!/bin/bash

openocd \
    -f interface/stlink.cfg \
    -f target/stm32g4x.cfg \
    -c "init" \
    -c "reset_config none separate; program bazel-out/stm32f4-opt/bin/moteus/power_dist.bin verify 0x8000000 verify reset exit 0x8000000"

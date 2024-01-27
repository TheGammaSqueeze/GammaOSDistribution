#!/bin/sh

echo 950000 > /sys/kernel/debug/regulator/vdd_npu_s0/voltage
echo 600000000 > /sys/devices/platform/fb000000.gpu/devfreq/fb000000.gpu/min_freq
echo 1608000 > /sys/devices/system/cpu/cpufreq/policy1/scaling_min_freq
echo 1608000 > /sys/devices/system/cpu/cpufreq/policy4/scaling_min_freq

/system/bin/log -t "Svep" "CPU/GPU set performance complete!"

#!/system/bin/sh

echo "384000000" > /sys/devices/platform/soc/soc:mm/60000000.gpu/devfreq/60000000.gpu/min_freq
echo "850000000" > /sys/devices/platform/soc/soc:mm/60000000.gpu/devfreq/60000000.gpu/max_freq
echo "powersave" > /sys/devices/platform/soc/soc:mm/60000000.gpu/devfreq/60000000.gpu/governor

echo "614400" > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq
echo 0 > /sys/devices/system/cpu/cpufreq/policy0/scaling_fix_freq
echo "powersave" > /sys/devices/system/cpu/cpufreq/policy0/scaling_governor

echo "614400" > /sys/devices/system/cpu/cpufreq/policy6/scaling_min_freq
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy6/scaling_max_freq
echo 0 > /sys/devices/system/cpu/cpufreq/policy6/scaling_fix_freq
echo "powersave" > /sys/devices/system/cpu/cpufreq/policy6/scaling_governor

echo 0 > /sys/class/devfreq/scene-frequency/sprd-governor/scaling_force_ddr_freq
echo "userspace" > /sys/class/devfreq/scene-frequency/governor
echo "512" > /sys/class/devfreq/scene-frequency/userspace/set_freq
echo "50" > /sys/class/devfreq/scene-frequency/polling_interval

echo "0" > /sys/class/leds/sc27xx\:blue/brightness
echo "255" > /sys/class/leds/sc27xx\:green/brightness
echo "0" > /sys/class/leds/sc27xx\:red/brightness

( sleep 5s; echo "0" > /sys/class/leds/sc27xx\:blue/brightness ) &
( sleep 5s; echo "0" > /sys/class/leds/sc27xx\:green/brightness ) &
( sleep 5s; echo "0" > /sys/class/leds/sc27xx\:red/brightness ) &

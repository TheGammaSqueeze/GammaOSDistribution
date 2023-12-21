#!/system/bin/sh

echo "850000000" > /sys/devices/platform/soc/soc:mm/60000000.gpu/devfreq/60000000.gpu/min_freq
echo "850000000" > /sys/devices/platform/soc/soc:mm/60000000.gpu/devfreq/60000000.gpu/max_freq
echo "performance" > /sys/devices/platform/soc/soc:mm/60000000.gpu/devfreq/60000000.gpu/governor

echo "2002000" > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq
echo "userspace" > /sys/devices/system/cpu/cpufreq/policy0/scaling_governor
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy0/scaling_setspeed
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy0/scaling_fix_freq

echo "2002000" > /sys/devices/system/cpu/cpufreq/policy6/scaling_min_freq
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy6/scaling_max_freq
echo "userspace" > /sys/devices/system/cpu/cpufreq/policy6/scaling_governor
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy6/scaling_setspeed
echo "2002000" > /sys/devices/system/cpu/cpufreq/policy6/scaling_fix_freq

echo "userspace" > /sys/class/devfreq/scene-frequency/governor
echo "1866" > /sys/class/devfreq/scene-frequency/userspace/set_freq
echo "50" > /sys/class/devfreq/scene-frequency/polling_interval

echo "0" > /sys/class/leds/sc27xx\:blue/brightness
echo "0" > /sys/class/leds/sc27xx\:green/brightness
echo "255" > /sys/class/leds/sc27xx\:red/brightness

sh -c '( sleep 5s; echo "0" > /sys/class/leds/sc27xx\:blue/brightness; echo "0" > /sys/class/leds/sc27xx\:green/brightness; echo "0" > /sys/class/leds/sc27xx\:red/brightness ) & echo "Done"' &

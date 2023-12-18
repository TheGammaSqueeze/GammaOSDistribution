#!/system/bin/sh

killall rgp2xbox
ionice -c 2 -n 0 nice -n -20 /system/bin/rgp2xbox

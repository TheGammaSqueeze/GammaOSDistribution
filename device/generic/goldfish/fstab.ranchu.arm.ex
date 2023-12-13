# Android fstab file.
#<src>                                                  <mnt_point>         <type>    <mnt_flags and options>                              <fs_mgr_flags>
# The filesystem that contains the filesystem checker binary (typically /system) cannot
# specify MF_CHECK, and must come before any filesystems that do specify MF_CHECK
system   /system     ext4    ro,barrier=1     wait,logical,first_stage_mount
vendor   /vendor     ext4    ro,barrier=1     wait,logical,first_stage_mount
product  /product    ext4    ro,barrier=1     wait,logical,first_stage_mount
system_ext  /system_ext  ext4   ro,barrier=1   wait,logical,first_stage_mount
/dev/block/vdc   /data     ext4      noatime,nosuid,nodev,nomblk_io_submit,errors=panic   wait,check,quota,fileencryption=aes-256-xts:aes-256-cts,reservedsize=128M,fsverity,keydirectory=/metadata/vold/metadata_encryption,latemount
/dev/block/platform/a003c00.virtio_mmio/by-name/metadata    /metadata    ext4    noatime,nosuid,nodev    wait,formattable,first_stage_mount
/devices/*/block/vdf  auto  auto      defaults voldmanaged=sdcard:auto,encryptable=userdata

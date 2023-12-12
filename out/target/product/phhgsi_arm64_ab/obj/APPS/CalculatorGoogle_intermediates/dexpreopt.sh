#!/bin/bash

err() {
  errno=$?
  echo "error: $0:$1 exited with status $errno" >&2
  echo "error in command:" >&2
  sed -n -e "$1p" $0 >&2
  if [ "$errno" -ne 0 ]; then
    exit $errno
  else
    exit 1
  fi
}

trap 'err $LINENO' ERR

mkdir -p out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/oat/arm64

rm -f out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/oat/arm64/package.odex

target_sdk_version="$( out/soong/host/linux-x86/bin/manifest_check --extract-target-sdk-version $1 --aapt out/soong/host/linux-x86/bin/aapt )"

eval "$( out/soong/host/linux-x86/bin/construct_context  --target-sdk-version ${target_sdk_version}  --host-context-for-sdk 30 PCL[out/target/common/obj/JAVA_LIBRARIES/android.test.base_intermediates/javalib.jar] --target-context-for-sdk 30 PCL[/system/framework/android.test.base.jar] --host-context-for-sdk 29 PCL[out/target/common/obj/JAVA_LIBRARIES/android.hidl.manager-V1.0-java_intermediates/javalib.jar]#PCL[out/target/common/obj/JAVA_LIBRARIES/android.hidl.base-V1.0-java_intermediates/javalib.jar] --target-context-for-sdk 29 PCL[/system/framework/android.hidl.manager-V1.0-java.jar]#PCL[/system/framework/android.hidl.base-V1.0-java.jar] --host-context-for-sdk 28 PCL[out/target/common/obj/JAVA_LIBRARIES/org.apache.http.legacy_intermediates/javalib.jar] --target-context-for-sdk 28 PCL[/system/framework/org.apache.http.legacy.jar] )"

ANDROID_LOG_TAGS="*:e" out/soong/host/linux-x86/bin/dex2oatd --avoid-storing-invocation --write-invocation-to=out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/oat/arm64/package.invocation --runtime-arg -Xms64m --runtime-arg -Xmx512m --runtime-arg -Xbootclasspath:out/soong/phhgsi_arm64_ab/dex_artjars_input/core-oj.jar:out/soong/phhgsi_arm64_ab/dex_artjars_input/core-libart.jar:out/soong/phhgsi_arm64_ab/dex_artjars_input/okhttp.jar:out/soong/phhgsi_arm64_ab/dex_artjars_input/bouncycastle.jar:out/soong/phhgsi_arm64_ab/dex_artjars_input/apache-xml.jar:out/soong/phhgsi_arm64_ab/dex_bootjars_input/framework.jar:out/soong/phhgsi_arm64_ab/dex_bootjars_input/framework-graphics.jar:out/soong/phhgsi_arm64_ab/dex_bootjars_input/ext.jar:out/soong/phhgsi_arm64_ab/dex_bootjars_input/telephony-common.jar:out/soong/phhgsi_arm64_ab/dex_bootjars_input/voip-common.jar:out/soong/phhgsi_arm64_ab/dex_bootjars_input/ims-common.jar:out/soong/phhgsi_arm64_ab/dex_bootjars_input/core-icu4j.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-appsearch.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/conscrypt.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/android.net.ipsec.ike.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/updatable-media.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-mediaprovider.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-statsd.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-permission.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-permission-s.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-scheduling.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-sdkextensions.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-connectivity.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-tethering.jar:out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-wifi.jar --runtime-arg -Xbootclasspath-locations:/apex/com.android.art/javalib/core-oj.jar:/apex/com.android.art/javalib/core-libart.jar:/apex/com.android.art/javalib/okhttp.jar:/apex/com.android.art/javalib/bouncycastle.jar:/apex/com.android.art/javalib/apache-xml.jar:/system/framework/framework.jar:/system/framework/framework-graphics.jar:/system/framework/ext.jar:/system/framework/telephony-common.jar:/system/framework/voip-common.jar:/system/framework/ims-common.jar:/apex/com.android.i18n/javalib/core-icu4j.jar:/apex/com.android.appsearch/javalib/framework-appsearch.jar:/apex/com.android.conscrypt/javalib/conscrypt.jar:/apex/com.android.ipsec/javalib/android.net.ipsec.ike.jar:/apex/com.android.media/javalib/updatable-media.jar:/apex/com.android.mediaprovider/javalib/framework-mediaprovider.jar:/apex/com.android.os.statsd/javalib/framework-statsd.jar:/apex/com.android.permission/javalib/framework-permission.jar:/apex/com.android.permission/javalib/framework-permission-s.jar:/apex/com.android.scheduling/javalib/framework-scheduling.jar:/apex/com.android.sdkext/javalib/framework-sdkextensions.jar:/apex/com.android.tethering/javalib/framework-connectivity.jar:/apex/com.android.tethering/javalib/framework-tethering.jar:/apex/com.android.wifi/javalib/framework-wifi.jar ${class_loader_context_arg} ${stored_class_loader_context_arg} --boot-image=out/soong/phhgsi_arm64_ab/dex_artjars/android/apex/art_boot_images/javalib/boot.art:out/soong/phhgsi_arm64_ab/dex_bootjars/android/system/framework/boot-framework.art --dex-file=$1 --dex-location=/product/app/CalculatorGoogle/CalculatorGoogle.apk --oat-file=out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/oat/arm64/package.odex --android-root=out/empty --instruction-set=arm64 --instruction-set-variant=generic --instruction-set-features=default --no-generate-debug-info --generate-build-id --abort-on-hard-verifier-error --force-determinism --no-inline-from=core-oj.jar --compiler-filter=$(if test -s  out/target/common/obj/APPS/CalculatorGoogle_intermediates/enforce_uses_libraries.status  ; then echo verify ; else echo quicken ; fi) --generate-mini-debug-info --compilation-reason=prebuilt

rm -rf out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install

mkdir -p out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install

mkdir -p out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install/system/product/app/CalculatorGoogle/oat/arm64

cp -f out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/oat/arm64/package.odex out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install/system/product/app/CalculatorGoogle/oat/arm64/CalculatorGoogle.odex

mkdir -p out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install/system/product/app/CalculatorGoogle/oat/arm64

cp -f out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/oat/arm64/package.vdex out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install/system/product/app/CalculatorGoogle/oat/arm64/CalculatorGoogle.vdex

out/soong/host/linux-x86/bin/soong_zip -o $2 -C out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install -D out/target/product/phhgsi_arm64_ab/obj/APPS/CalculatorGoogle_intermediates/dexpreopt_install

rm -f $2.d
echo -n $2 > $2.d
cat >> $2.d <<'EOF'
: \
    out/soong/host/linux-x86/bin/construct_context \
    out/soong/host/linux-x86/bin/dex2oatd \
    out/soong/host/linux-x86/bin/manifest_check \
    out/soong/host/linux-x86/bin/soong_zip \
    out/soong/host/linux-x86/bin/aapt \
    out/soong/phhgsi_arm64_ab/dex_artjars_input/apache-xml.jar \
    out/soong/phhgsi_arm64_ab/dex_artjars_input/bouncycastle.jar \
    out/soong/phhgsi_arm64_ab/dex_artjars_input/core-libart.jar \
    out/soong/phhgsi_arm64_ab/dex_artjars_input/core-oj.jar \
    out/soong/phhgsi_arm64_ab/dex_artjars_input/okhttp.jar \
    out/soong/phhgsi_arm64_ab/dex_bootjars_input/core-icu4j.jar \
    out/soong/phhgsi_arm64_ab/dex_bootjars_input/ext.jar \
    out/soong/phhgsi_arm64_ab/dex_bootjars_input/framework-graphics.jar \
    out/soong/phhgsi_arm64_ab/dex_bootjars_input/framework.jar \
    out/soong/phhgsi_arm64_ab/dex_bootjars_input/ims-common.jar \
    out/soong/phhgsi_arm64_ab/dex_bootjars_input/telephony-common.jar \
    out/soong/phhgsi_arm64_ab/dex_bootjars_input/voip-common.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/android.net.ipsec.ike.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/conscrypt.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-appsearch.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-connectivity.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-mediaprovider.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-permission-s.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-permission.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-scheduling.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-sdkextensions.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-statsd.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-tethering.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/framework-wifi.jar \
    out/soong/phhgsi_arm64_ab/updatable_bootjars/updatable-media.jar \
    out/target/common/obj/APPS/CalculatorGoogle_intermediates/enforce_uses_libraries.status \
    out/target/common/obj/JAVA_LIBRARIES/android.hidl.base-V1.0-java_intermediates/javalib.jar \
    out/target/common/obj/JAVA_LIBRARIES/android.hidl.manager-V1.0-java_intermediates/javalib.jar \
    out/target/common/obj/JAVA_LIBRARIES/android.test.base_intermediates/javalib.jar \
    out/target/common/obj/JAVA_LIBRARIES/org.apache.http.legacy_intermediates/javalib.jar \

EOF

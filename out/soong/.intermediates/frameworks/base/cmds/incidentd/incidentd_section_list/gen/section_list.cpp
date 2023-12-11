// Auto generated file. Do not modify

#include "section_list.h"

namespace android {
namespace os {
namespace incidentd {
// Generate SECTION_LIST.

const Section* SECTION_LIST[] = {
    new CommandSection(1000, "getprop", NULL),
    new FileSection(1002, "/proc/version"),
    new FileSection(1100, "/system/etc/event-log-tags"),
    new LogSection(1101,  "main", NULL),
    new LogSection(1102,  "radio", NULL),
    new LogSection(1103,  "events", NULL),
    new LogSection(1104,  "system", NULL),
    new LogSection(1105,  "crash", NULL),
    new LogSection(1106,  "stats", NULL),
    new LogSection(1107,  "security", NULL),
    new LogSection(1108,  "kernel", NULL),
    new LogSection(1109,  "main", "-L", NULL),
    new LogSection(1110,  "radio", "-L", NULL),
    new LogSection(1111,  "events", "-L", NULL),
    new LogSection(1112,  "system", "-L", NULL),
    new LogSection(1113,  "crash", "-L", NULL),
    new LogSection(1114,  "stats", "-L", NULL),
    new LogSection(1115,  "security", "-L", NULL),
    new CommandSection(1116, "/system/bin/sh", "/system/bin/incident-helper-cmd", "-l", "run", "persisted_logs", "--limit", "10MB", NULL),
    new TombstoneSection(1200, "native"),
    new TombstoneSection(1201, "hal"),
    new TombstoneSection(1202, "java"),
    new FileSection(2001, "/proc/pagetypeinfo"),
    new FileSection(2002, "/d/wakeup_sources"),
    new CommandSection(2003, "top", "-b", "-n", "1", "-H", "-s", "6", "-o", "pid,tid,user,pr,ni,%cpu,s,virt,res,pcy,cmd,name", NULL),
    new FileSection(2004, "/sys/devices/system/cpu/cpufreq/all_time_in_state"),
    new CommandSection(2005, "ps", "-A", "-T", "-Z", "-O", "pri,nice,rtprio,sched,pcy,time", NULL),
    new FileSection(2006, "/sys/class/power_supply/bms/battery_type"),
    new GZipSection(2007, "/sys/fs/pstore/console-ramoops", "/sys/fs/pstore/console-ramoops-0", "/proc/last_kmsg", NULL),
    new DumpsysSection(3000,  "fingerprint", "--proto", "--incident", NULL),
    new DumpsysSection(3001,  "netstats", "--proto", NULL),
    new DumpsysSection(3002,  "settings", "--proto", NULL),
    new DumpsysSection(3004,  "notification", "--proto", NULL),
    new DumpsysSection(3005,  "batterystats", "--proto", NULL),
    new DumpsysSection(3006,  "battery", "--proto", NULL),
    new DumpsysSection(3007,  "diskstats", "--proto", NULL),
    new DumpsysSection(3008,  "package", "--proto", NULL),
    new DumpsysSection(3009,  "power", "--proto", NULL),
    new DumpsysSection(3010,  "print", "--proto", NULL),
    new DumpsysSection(3011,  "procstats", "--proto", NULL),
    new DumpsysSection(3012,  "activity", "--proto", "activities", NULL),
    new DumpsysSection(3013,  "activity", "--proto", "broadcasts", NULL),
    new DumpsysSection(3014,  "activity", "--proto", "service", NULL),
    new DumpsysSection(3015,  "activity", "--proto", "processes", NULL),
    new DumpsysSection(3016,  "alarm", "--proto", NULL),
    new DumpsysSection(3017,  "window", "--proto", NULL),
    new DumpsysSection(3018,  "meminfo", "-a", "--proto", NULL),
    new DumpsysSection(3019,  "graphicsstats", "--proto", NULL),
    new DumpsysSection(3020,  "jobscheduler", "--proto", NULL),
    new DumpsysSection(3021,  "usb", "--proto", NULL),
#if ALLOW_RESTRICTED_SECTIONS
    new DumpsysSection(3022,  "batterystats", "--proto", "--history", NULL),
#endif
#if ALLOW_RESTRICTED_SECTIONS
    new DumpsysSection(3023,  "stats", "--proto", NULL),
#endif
    new DumpsysSection(3024,  "role", "--proto", NULL),
#if ALLOW_RESTRICTED_SECTIONS
    new DumpsysSection(3025,  "incidentcompanion", "--restricted_image", NULL),
#endif
    new FileSection(3026, "/data/misc/perfetto-traces/incident-trace"),
    new DumpsysSection(3027,  "dropbox", "--proto", "data_app_crash", NULL),
    new DumpsysSection(3028,  "dropbox", "--proto", "data_app_anr", NULL),
    new DumpsysSection(3029,  "dropbox", "--proto", "data_app_native_crash", NULL),
    new DumpsysSection(3030,  "dropbox", "--proto", "data_app_strictmode", NULL),
    new DumpsysSection(3031,  "dropbox", "--proto", "data_app_wtf", NULL),
    new DumpsysSection(3032,  "dropbox", "--proto", "system_app_crash", NULL),
    new DumpsysSection(3033,  "dropbox", "--proto", "system_app_anr", NULL),
    new DumpsysSection(3034,  "dropbox", "--proto", "system_app_native_crash", NULL),
    new DumpsysSection(3035,  "dropbox", "--proto", "system_app_strictmode", NULL),
    new DumpsysSection(3036,  "dropbox", "--proto", "system_app_wtf", NULL),
    new DumpsysSection(3037,  "dropbox", "--proto", "system_server_crash", NULL),
    new DumpsysSection(3038,  "dropbox", "--proto", "system_server_anr", NULL),
    new DumpsysSection(3039,  "dropbox", "--proto", "system_server_native_crash", NULL),
    new DumpsysSection(3040,  "dropbox", "--proto", "system_server_lowmem", NULL),
    new DumpsysSection(3041,  "dropbox", "--proto", "system_server_strictmode", NULL),
    new DumpsysSection(3042,  "dropbox", "--proto", "system_server_watchdog", NULL),
    new DumpsysSection(3043,  "dropbox", "--proto", "system_server_wtf", NULL),
    new DumpsysSection(3044,  "dropbox", "--proto", "SYSTEM_RECOVERY_LOG", NULL),
    new DumpsysSection(3045,  "dropbox", "--proto", "SYSTEM_TOMBSTONE", NULL),
    new DumpsysSection(3046,  "dropbox", "--proto", "SubsystemRestart", NULL),
    new DumpsysSection(3047,  "cpuinfo", "--proto", NULL),
    new DumpsysSection(3049,  "connmetrics", "--proto", NULL),
    new DumpsysSection(3050,  "bluetooth_manager", "--proto", NULL),
    new DumpsysSection(3051,  "contexthub", "--proto", NULL),
    new DumpsysSection(3052,  "nfc", "--proto", NULL),
    new DumpsysSection(3053,  "sensorservice", "--proto", NULL),
    new DumpsysSection(3054,  "powerstats", "--proto", "meter", NULL),
    new DumpsysSection(3055,  "powerstats", "--proto", "model", NULL),
    new DumpsysSection(3056,  "powerstats", "--proto", "residency", NULL),
#if ALLOW_RESTRICTED_SECTIONS
    new TextDumpsysSection(4000,  "wifi", NULL),
#endif
#if ALLOW_RESTRICTED_SECTIONS
    new TextDumpsysSection(4001,  "bluetooth_manager", NULL),
#endif
    NULL };

// =============================================================================

// Generate PRIVACY_POLICY_LIST.


// Incident Report Section: header (1)
// default android__os__IncidentProto__header: fieldDest=255 incidentDest=255

// Incident Report Section: metadata (2)
// default android__os__IncidentProto__metadata: fieldDest=255 incidentDest=255

// Incident Report Section: system_properties (1000)
Privacy android__os__SystemPropertiesProto__extra_properties = { 1, 11, NULL, 0, NULL };
Privacy android__os__SystemPropertiesProto__init_svc = { 12, 11, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__log = { 16, 11, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__adb_secure = { 1, 8, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__bootimage = { 8, 11, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__bootloader = { 9, 9, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__bootmode = { 10, 9, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__build = { 11, 11, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__camera_notify_nfc = { 12, 8, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__com_android_dataroaming = { 14, 8, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__com_android_prov_mobiledata = { 15, 8, NULL, 200, NULL };
Privacy android__os__SystemPropertiesProto__Ro__hardware = { 27, 11, NULL, 0, NULL };
Privacy android__os__SystemPropertiesProto__Ro__product = { 32, 11, NULL, 200, NULL };

Privacy* android_os_SystemPropertiesProto_Ro__MSG__255[] = {
    &android__os__SystemPropertiesProto__Ro__adb_secure,
    &android__os__SystemPropertiesProto__Ro__bootimage,
    &android__os__SystemPropertiesProto__Ro__bootloader,
    &android__os__SystemPropertiesProto__Ro__bootmode,
    &android__os__SystemPropertiesProto__Ro__build,
    &android__os__SystemPropertiesProto__Ro__camera_notify_nfc,
    &android__os__SystemPropertiesProto__Ro__com_android_dataroaming,
    &android__os__SystemPropertiesProto__Ro__com_android_prov_mobiledata,
    &android__os__SystemPropertiesProto__Ro__hardware,
    &android__os__SystemPropertiesProto__Ro__product,
    NULL };

Privacy android__os__SystemPropertiesProto__ro = { 21, 11, android_os_SystemPropertiesProto_Ro__MSG__255, 255, NULL };

Privacy* android_os_SystemPropertiesProto__MSG__255[] = {
    &android__os__SystemPropertiesProto__extra_properties,
    &android__os__SystemPropertiesProto__init_svc,
    &android__os__SystemPropertiesProto__log,
    &android__os__SystemPropertiesProto__ro,
    NULL };

Privacy android__os__IncidentProto__system_properties = { 1000, 11, android_os_SystemPropertiesProto__MSG__255, 255, NULL };

// Incident Report Section: kernel_version (1002)
Privacy android__os__IncidentProto__kernel_version = { 1002, 9, NULL, 200, NULL };

// Incident Report Section: event_log_tag_map (1100)
Privacy android__os__IncidentProto__event_log_tag_map = { 1100, 11, NULL, 200, NULL };

// Incident Report Section: main_logs (1101)
Privacy android__os__IncidentProto__main_logs = { 1101, 11, NULL, 100, NULL };

// Incident Report Section: radio_logs (1102)
Privacy android__os__IncidentProto__radio_logs = { 1102, 11, NULL, 100, NULL };

// Incident Report Section: events_logs (1103)
Privacy android__os__IncidentProto__events_logs = { 1103, 11, NULL, 100, NULL };

// Incident Report Section: system_logs (1104)
Privacy android__os__IncidentProto__system_logs = { 1104, 11, NULL, 100, NULL };

// Incident Report Section: crash_logs (1105)
Privacy android__os__IncidentProto__crash_logs = { 1105, 11, NULL, 100, NULL };

// Incident Report Section: stats_logs (1106)
Privacy android__os__IncidentProto__stats_logs = { 1106, 11, NULL, 100, NULL };

// Incident Report Section: security_logs (1107)
Privacy android__os__IncidentProto__security_logs = { 1107, 11, NULL, 100, NULL };

// Incident Report Section: kernel_logs (1108)
Privacy android__os__IncidentProto__kernel_logs = { 1108, 11, NULL, 100, NULL };

// Incident Report Section: last_main_logs (1109)
Privacy android__os__IncidentProto__last_main_logs = { 1109, 11, NULL, 100, NULL };

// Incident Report Section: last_radio_logs (1110)
Privacy android__os__IncidentProto__last_radio_logs = { 1110, 11, NULL, 100, NULL };

// Incident Report Section: last_events_logs (1111)
Privacy android__os__IncidentProto__last_events_logs = { 1111, 11, NULL, 100, NULL };

// Incident Report Section: last_system_logs (1112)
Privacy android__os__IncidentProto__last_system_logs = { 1112, 11, NULL, 100, NULL };

// Incident Report Section: last_crash_logs (1113)
Privacy android__os__IncidentProto__last_crash_logs = { 1113, 11, NULL, 100, NULL };

// Incident Report Section: last_stats_logs (1114)
Privacy android__os__IncidentProto__last_stats_logs = { 1114, 11, NULL, 100, NULL };

// Incident Report Section: last_security_logs (1115)
Privacy android__os__IncidentProto__last_security_logs = { 1115, 11, NULL, 100, NULL };

// Incident Report Section: persisted_logs (1116)
Privacy android__os__IncidentProto__persisted_logs = { 1116, 11, NULL, 100, NULL };

// Incident Report Section: native_traces (1200)
Privacy android__os__IncidentProto__native_traces = { 1200, 11, NULL, 100, NULL };

// Incident Report Section: hal_traces (1201)
Privacy android__os__IncidentProto__hal_traces = { 1201, 11, NULL, 100, NULL };

// Incident Report Section: java_traces (1202)
Privacy android__os__IncidentProto__java_traces = { 1202, 11, NULL, 100, NULL };

// Incident Report Section: procrank (2000)
Privacy android__os__IncidentProto__procrank = { 2000, 11, NULL, 200, NULL };

// Incident Report Section: page_type_info (2001)
Privacy android__os__IncidentProto__page_type_info = { 2001, 11, NULL, 200, NULL };

// Incident Report Section: kernel_wake_sources (2002)
Privacy android__os__IncidentProto__kernel_wake_sources = { 2002, 11, NULL, 200, NULL };

// Incident Report Section: cpu_info (2003)
Privacy android__os__IncidentProto__cpu_info = { 2003, 11, NULL, 200, NULL };

// Incident Report Section: cpu_freq (2004)
Privacy android__os__IncidentProto__cpu_freq = { 2004, 11, NULL, 200, NULL };

// Incident Report Section: processes_and_threads (2005)
Privacy android__os__PsProto__Process__addr = { 9, 9, NULL, 0, NULL };

Privacy* android_os_PsProto_Process__MSG__200[] = {
    &android__os__PsProto__Process__addr,
    NULL };

Privacy android__os__PsProto__processes = { 1, 11, android_os_PsProto_Process__MSG__200, 200, NULL };

Privacy* android_os_PsProto__MSG__200[] = {
    &android__os__PsProto__processes,
    NULL };

Privacy android__os__IncidentProto__processes_and_threads = { 2005, 11, android_os_PsProto__MSG__200, 200, NULL };

// Incident Report Section: battery_type (2006)
Privacy android__os__IncidentProto__battery_type = { 2006, 11, NULL, 200, NULL };

// Incident Report Section: last_kmsg (2007)
Privacy android__os__IncidentProto__last_kmsg = { 2007, 11, NULL, 100, NULL };

// Incident Report Section: fingerprint (3000)
Privacy android__os__IncidentProto__fingerprint = { 3000, 11, NULL, 200, NULL };

// Incident Report Section: netstats (3001)
Privacy android__service__NetworkIdentityProto__subscriber_id = { 2, 9, NULL, 100, NULL };
Privacy android__service__NetworkIdentityProto__network_id = { 3, 9, NULL, 100, NULL };

Privacy* android_service_NetworkIdentityProto__MSG__200[] = {
    &android__service__NetworkIdentityProto__subscriber_id,
    &android__service__NetworkIdentityProto__network_id,
    NULL };

Privacy android__service__NetworkIdentitySetProto__identities = { 1, 11, android_service_NetworkIdentityProto__MSG__200, 200, NULL };

Privacy* android_service_NetworkIdentitySetProto__MSG__200[] = {
    &android__service__NetworkIdentitySetProto__identities,
    NULL };

Privacy android__service__NetworkInterfaceProto__identities = { 2, 11, android_service_NetworkIdentitySetProto__MSG__200, 200, NULL };

Privacy* android_service_NetworkInterfaceProto__MSG__200[] = {
    &android__service__NetworkInterfaceProto__identities,
    NULL };

Privacy android__service__NetworkStatsServiceDumpProto__active_interfaces = { 1, 11, android_service_NetworkInterfaceProto__MSG__200, 200, NULL };
Privacy android__service__NetworkStatsServiceDumpProto__active_uid_interfaces = { 2, 11, android_service_NetworkInterfaceProto__MSG__200, 200, NULL };
Privacy android__service__NetworkStatsCollectionKeyProto__identity = { 1, 11, android_service_NetworkIdentitySetProto__MSG__200, 200, NULL };

Privacy* android_service_NetworkStatsCollectionKeyProto__MSG__200[] = {
    &android__service__NetworkStatsCollectionKeyProto__identity,
    NULL };

Privacy android__service__NetworkStatsCollectionStatsProto__key = { 1, 11, android_service_NetworkStatsCollectionKeyProto__MSG__200, 200, NULL };

Privacy* android_service_NetworkStatsCollectionStatsProto__MSG__200[] = {
    &android__service__NetworkStatsCollectionStatsProto__key,
    NULL };

Privacy android__service__NetworkStatsCollectionProto__stats = { 1, 11, android_service_NetworkStatsCollectionStatsProto__MSG__200, 200, NULL };

Privacy* android_service_NetworkStatsCollectionProto__MSG__200[] = {
    &android__service__NetworkStatsCollectionProto__stats,
    NULL };

Privacy android__service__NetworkStatsRecorderProto__complete_history = { 2, 11, android_service_NetworkStatsCollectionProto__MSG__200, 200, NULL };

Privacy* android_service_NetworkStatsRecorderProto__MSG__200[] = {
    &android__service__NetworkStatsRecorderProto__complete_history,
    NULL };

Privacy android__service__NetworkStatsServiceDumpProto__dev_stats = { 3, 11, android_service_NetworkStatsRecorderProto__MSG__200, 200, NULL };
Privacy android__service__NetworkStatsServiceDumpProto__xt_stats = { 4, 11, android_service_NetworkStatsRecorderProto__MSG__200, 200, NULL };
Privacy android__service__NetworkStatsServiceDumpProto__uid_stats = { 5, 11, android_service_NetworkStatsRecorderProto__MSG__200, 200, NULL };
Privacy android__service__NetworkStatsServiceDumpProto__uid_tag_stats = { 6, 11, android_service_NetworkStatsRecorderProto__MSG__200, 200, NULL };

Privacy* android_service_NetworkStatsServiceDumpProto__MSG__200[] = {
    &android__service__NetworkStatsServiceDumpProto__active_interfaces,
    &android__service__NetworkStatsServiceDumpProto__active_uid_interfaces,
    &android__service__NetworkStatsServiceDumpProto__dev_stats,
    &android__service__NetworkStatsServiceDumpProto__xt_stats,
    &android__service__NetworkStatsServiceDumpProto__uid_stats,
    &android__service__NetworkStatsServiceDumpProto__uid_tag_stats,
    NULL };

Privacy android__os__IncidentProto__netstats = { 3001, 11, android_service_NetworkStatsServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: settings (3002)
Privacy android__providers__settings__UserSettingsProto__user_id = { 1, 5, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__autoclick_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__autoclick_delay = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__button_target_component = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_enabled = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_locale = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_preset = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_background_color = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_foreground_color = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_edge_type = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_edge_color = { 12, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_window_color = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_typeface = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__captioning_font_scale = { 15, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__display_daltonizer_enabled = { 16, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__display_daltonizer = { 17, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__display_inversion_enabled = { 18, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__display_magnification_enabled = { 19, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__display_magnification_navbar_enabled = { 20, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__display_magnification_scale = { 21, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__high_text_contrast_enabled = { 22, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__large_pointer_icon = { 23, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__shortcut_enabled = { 24, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__shortcut_on_lock_screen = { 25, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__shortcut_dialog_shown = { 26, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__shortcut_target_service = { 27, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__soft_keyboard_mode = { 28, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__speak_password = { 29, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__touch_exploration_enabled = { 30, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__non_interactive_ui_timeout_ms = { 32, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__interactive_ui_timeout_ms = { 33, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__accessibility_magnification_mode = { 34, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__button_targets = { 35, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__accessibility_magnification_capability = { 36, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__accessibility_button_mode = { 37, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_size = { 38, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_icon_type = { 39, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_opacity = { 40, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_fade_enabled = { 41, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Accessibility__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Accessibility__enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__autoclick_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__autoclick_delay,
    &android__providers__settings__SecureSettingsProto__Accessibility__button_target_component,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_locale,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_preset,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_background_color,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_foreground_color,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_edge_type,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_edge_color,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_window_color,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_typeface,
    &android__providers__settings__SecureSettingsProto__Accessibility__captioning_font_scale,
    &android__providers__settings__SecureSettingsProto__Accessibility__display_daltonizer_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__display_daltonizer,
    &android__providers__settings__SecureSettingsProto__Accessibility__display_inversion_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__display_magnification_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__display_magnification_navbar_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__display_magnification_scale,
    &android__providers__settings__SecureSettingsProto__Accessibility__high_text_contrast_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__large_pointer_icon,
    &android__providers__settings__SecureSettingsProto__Accessibility__shortcut_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__shortcut_on_lock_screen,
    &android__providers__settings__SecureSettingsProto__Accessibility__shortcut_dialog_shown,
    &android__providers__settings__SecureSettingsProto__Accessibility__shortcut_target_service,
    &android__providers__settings__SecureSettingsProto__Accessibility__soft_keyboard_mode,
    &android__providers__settings__SecureSettingsProto__Accessibility__speak_password,
    &android__providers__settings__SecureSettingsProto__Accessibility__touch_exploration_enabled,
    &android__providers__settings__SecureSettingsProto__Accessibility__non_interactive_ui_timeout_ms,
    &android__providers__settings__SecureSettingsProto__Accessibility__interactive_ui_timeout_ms,
    &android__providers__settings__SecureSettingsProto__Accessibility__accessibility_magnification_mode,
    &android__providers__settings__SecureSettingsProto__Accessibility__button_targets,
    &android__providers__settings__SecureSettingsProto__Accessibility__accessibility_magnification_capability,
    &android__providers__settings__SecureSettingsProto__Accessibility__accessibility_button_mode,
    &android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_size,
    &android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_icon_type,
    &android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_opacity,
    &android__providers__settings__SecureSettingsProto__Accessibility__accessibility_floating_menu_fade_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__accessibility = { 2, 11, android_providers_settings_SecureSettingsProto_Accessibility__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__AlwaysOnVpn__lockdown = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_AlwaysOnVpn__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__AlwaysOnVpn__lockdown,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__always_on_vpn = { 4, 11, android_providers_settings_SecureSettingsProto_AlwaysOnVpn__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__anr_show_background = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__assistant = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__structure_enabled = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__screenshot_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__disclosure_enabled = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__gesture_enabled = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__gesture_sensitivity = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__gesture_silence_alerts_enabled = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__gesture_wake_enabled = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__gesture_setup_complete = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__touch_gesture_enabled = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Assist__long_press_home_enabled = { 11, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Assist__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Assist__assistant,
    &android__providers__settings__SecureSettingsProto__Assist__structure_enabled,
    &android__providers__settings__SecureSettingsProto__Assist__screenshot_enabled,
    &android__providers__settings__SecureSettingsProto__Assist__disclosure_enabled,
    &android__providers__settings__SecureSettingsProto__Assist__gesture_enabled,
    &android__providers__settings__SecureSettingsProto__Assist__gesture_sensitivity,
    &android__providers__settings__SecureSettingsProto__Assist__gesture_silence_alerts_enabled,
    &android__providers__settings__SecureSettingsProto__Assist__gesture_wake_enabled,
    &android__providers__settings__SecureSettingsProto__Assist__gesture_setup_complete,
    &android__providers__settings__SecureSettingsProto__Assist__touch_gesture_enabled,
    &android__providers__settings__SecureSettingsProto__Assist__long_press_home_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__assist = { 7, 11, android_providers_settings_SecureSettingsProto_Assist__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__service = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__feature_field_classification = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__user_data_max_user_data_size = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__user_data_max_field_classification_ids_size = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__user_data_max_category_count = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__user_data_max_value_length = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__user_data_min_value_length = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Autofill__service_search_uri = { 8, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Autofill__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Autofill__service,
    &android__providers__settings__SecureSettingsProto__Autofill__feature_field_classification,
    &android__providers__settings__SecureSettingsProto__Autofill__user_data_max_user_data_size,
    &android__providers__settings__SecureSettingsProto__Autofill__user_data_max_field_classification_ids_size,
    &android__providers__settings__SecureSettingsProto__Autofill__user_data_max_category_count,
    &android__providers__settings__SecureSettingsProto__Autofill__user_data_max_value_length,
    &android__providers__settings__SecureSettingsProto__Autofill__user_data_min_value_length,
    &android__providers__settings__SecureSettingsProto__Autofill__service_search_uri,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__autofill = { 8, 11, android_providers_settings_SecureSettingsProto_Autofill__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__AutomaticStorageManager__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__AutomaticStorageManager__days_to_retain = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__AutomaticStorageManager__bytes_cleared = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__AutomaticStorageManager__last_run = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__AutomaticStorageManager__turned_off_by_policy = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_AutomaticStorageManager__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__AutomaticStorageManager__enabled,
    &android__providers__settings__SecureSettingsProto__AutomaticStorageManager__days_to_retain,
    &android__providers__settings__SecureSettingsProto__AutomaticStorageManager__bytes_cleared,
    &android__providers__settings__SecureSettingsProto__AutomaticStorageManager__last_run,
    &android__providers__settings__SecureSettingsProto__AutomaticStorageManager__turned_off_by_policy,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__automatic_storage_manager = { 9, 11, android_providers_settings_SecureSettingsProto_AutomaticStorageManager__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Backup__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Backup__auto_restore = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Backup__provisioned = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Backup__transport = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Backup__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Backup__enabled,
    &android__providers__settings__SecureSettingsProto__Backup__auto_restore,
    &android__providers__settings__SecureSettingsProto__Backup__provisioned,
    &android__providers__settings__SecureSettingsProto__Backup__transport,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__backup = { 10, 11, android_providers_settings_SecureSettingsProto_Backup__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__bluetooth_on_while_driving = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Camera__gesture_disabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Camera__double_tap_power_gesture_disabled = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Camera__double_twist_to_flip_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Camera__lift_trigger_enabled = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Camera__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Camera__gesture_disabled,
    &android__providers__settings__SecureSettingsProto__Camera__double_tap_power_gesture_disabled,
    &android__providers__settings__SecureSettingsProto__Camera__double_twist_to_flip_enabled,
    &android__providers__settings__SecureSettingsProto__Camera__lift_trigger_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__camera = { 12, 11, android_providers_settings_SecureSettingsProto_Camera__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__carrier_apps_handled = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__cmas_additional_broadcast_pkg = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__connectivity_release_pending_intent_delay_ms = { 16, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__device_paired = { 17, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__dialer_default_application = { 18, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__display_density_forced = { 19, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__double_tap_to_wake = { 20, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Doze__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Doze__always_on = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Doze__pulse_on_pick_up = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Doze__pulse_on_long_press = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Doze__pulse_on_double_tap = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Doze__pulse_on_tap = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Doze__suppress = { 7, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Doze__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Doze__enabled,
    &android__providers__settings__SecureSettingsProto__Doze__always_on,
    &android__providers__settings__SecureSettingsProto__Doze__pulse_on_pick_up,
    &android__providers__settings__SecureSettingsProto__Doze__pulse_on_long_press,
    &android__providers__settings__SecureSettingsProto__Doze__pulse_on_double_tap,
    &android__providers__settings__SecureSettingsProto__Doze__pulse_on_tap,
    &android__providers__settings__SecureSettingsProto__Doze__suppress,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__doze = { 21, 11, android_providers_settings_SecureSettingsProto_Doze__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__emergency_assistance_application = { 22, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__enhanced_voice_privacy_enabled = { 23, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__immersive_mode_confirmations = { 24, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Incall__power_button_behavior = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Incall__back_button_behavior = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Incall__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Incall__power_button_behavior,
    &android__providers__settings__SecureSettingsProto__Incall__back_button_behavior,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__incall = { 25, 11, android_providers_settings_SecureSettingsProto_Incall__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__default_input_method = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__disabled_system_input_methods = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__enabled_input_methods = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__method_selector_visibility = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__subtype_history = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__selected_input_method_subtype = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__show_ime_with_hard_keyboard = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__InputMethods__default_voice_input_method = { 8, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_InputMethods__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__InputMethods__default_input_method,
    &android__providers__settings__SecureSettingsProto__InputMethods__disabled_system_input_methods,
    &android__providers__settings__SecureSettingsProto__InputMethods__enabled_input_methods,
    &android__providers__settings__SecureSettingsProto__InputMethods__method_selector_visibility,
    &android__providers__settings__SecureSettingsProto__InputMethods__subtype_history,
    &android__providers__settings__SecureSettingsProto__InputMethods__selected_input_method_subtype,
    &android__providers__settings__SecureSettingsProto__InputMethods__show_ime_with_hard_keyboard,
    &android__providers__settings__SecureSettingsProto__InputMethods__default_voice_input_method,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__input_methods = { 26, 11, android_providers_settings_SecureSettingsProto_InputMethods__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__install_non_market_apps = { 27, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__instant_apps_enabled = { 28, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__last_setup_shown = { 30, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Location__mode = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Location__changer = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Location__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Location__mode,
    &android__providers__settings__SecureSettingsProto__Location__changer,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__location = { 31, 11, android_providers_settings_SecureSettingsProto_Location__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__LockScreen__lock_after_timeout = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__LockScreen__allow_private_notifications = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__LockScreen__allow_remote_input = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__LockScreen__show_notifications = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_LockScreen__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__LockScreen__lock_after_timeout,
    &android__providers__settings__SecureSettingsProto__LockScreen__allow_private_notifications,
    &android__providers__settings__SecureSettingsProto__LockScreen__allow_remote_input,
    &android__providers__settings__SecureSettingsProto__LockScreen__show_notifications,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__lock_screen = { 32, 11, android_providers_settings_SecureSettingsProto_LockScreen__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__lock_to_app_exit_locked = { 33, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__lockdown_in_power_menu = { 34, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__long_press_timeout = { 35, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__ManagedProfile__contact_remote_search = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_ManagedProfile__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__ManagedProfile__contact_remote_search,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__managed_profile = { 36, 11, android_providers_settings_SecureSettingsProto_ManagedProfile__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Mount__play_notification_snd = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Mount__ums_autostart = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Mount__ums_prompt = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Mount__ums_notify_enabled = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Mount__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Mount__play_notification_snd,
    &android__providers__settings__SecureSettingsProto__Mount__ums_autostart,
    &android__providers__settings__SecureSettingsProto__Mount__ums_prompt,
    &android__providers__settings__SecureSettingsProto__Mount__ums_notify_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__mount = { 37, 11, android_providers_settings_SecureSettingsProto_Mount__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__multi_press_timeout = { 38, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NfcPayment__default_component = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NfcPayment__foreground = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NfcPayment__payment_service_search_uri = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_NfcPayment__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__NfcPayment__default_component,
    &android__providers__settings__SecureSettingsProto__NfcPayment__foreground,
    &android__providers__settings__SecureSettingsProto__NfcPayment__payment_service_search_uri,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__nfc_payment = { 39, 11, android_providers_settings_SecureSettingsProto_NfcPayment__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__NightDisplay__activated = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NightDisplay__auto_mode = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NightDisplay__color_temperature = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NightDisplay__custom_start_time = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NightDisplay__custom_end_time = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__NightDisplay__last_activated_time = { 6, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_NightDisplay__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__NightDisplay__activated,
    &android__providers__settings__SecureSettingsProto__NightDisplay__auto_mode,
    &android__providers__settings__SecureSettingsProto__NightDisplay__color_temperature,
    &android__providers__settings__SecureSettingsProto__NightDisplay__custom_start_time,
    &android__providers__settings__SecureSettingsProto__NightDisplay__custom_end_time,
    &android__providers__settings__SecureSettingsProto__NightDisplay__last_activated_time,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__night_display = { 40, 11, android_providers_settings_SecureSettingsProto_NightDisplay__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Notification__enabled_assistant = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Notification__enabled_listeners = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Notification__enabled_policy_access_packages = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Notification__badging = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Notification__show_note_about_notification_hiding = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Notification__in_call_notification_enabled = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Notification__bubbles = { 7, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Notification__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Notification__enabled_assistant,
    &android__providers__settings__SecureSettingsProto__Notification__enabled_listeners,
    &android__providers__settings__SecureSettingsProto__Notification__enabled_policy_access_packages,
    &android__providers__settings__SecureSettingsProto__Notification__badging,
    &android__providers__settings__SecureSettingsProto__Notification__show_note_about_notification_hiding,
    &android__providers__settings__SecureSettingsProto__Notification__in_call_notification_enabled,
    &android__providers__settings__SecureSettingsProto__Notification__bubbles,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__notification = { 41, 11, android_providers_settings_SecureSettingsProto_Notification__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__PackageVerifier__user_consent = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__PackageVerifier__state = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_PackageVerifier__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__PackageVerifier__user_consent,
    &android__providers__settings__SecureSettingsProto__PackageVerifier__state,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__package_verifier = { 42, 11, android_providers_settings_SecureSettingsProto_PackageVerifier__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__ParentalControl__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__ParentalControl__last_update = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__ParentalControl__redirect_url = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_ParentalControl__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__ParentalControl__enabled,
    &android__providers__settings__SecureSettingsProto__ParentalControl__last_update,
    &android__providers__settings__SecureSettingsProto__ParentalControl__redirect_url,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__parental_control = { 43, 11, android_providers_settings_SecureSettingsProto_ParentalControl__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__PrintService__search_uri = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_PrintService__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__PrintService__search_uri,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__print_service = { 44, 11, android_providers_settings_SecureSettingsProto_PrintService__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__QuickSettings__tiles = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__QuickSettings__auto_added_tiles = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_QuickSettings__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__QuickSettings__tiles,
    &android__providers__settings__SecureSettingsProto__QuickSettings__auto_added_tiles,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__qs = { 45, 11, android_providers_settings_SecureSettingsProto_QuickSettings__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Rotation__show_rotation_suggestions = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Rotation__num_rotation_suggestions_accepted = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Rotation__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Rotation__show_rotation_suggestions,
    &android__providers__settings__SecureSettingsProto__Rotation__num_rotation_suggestions_accepted,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__rotation = { 46, 11, android_providers_settings_SecureSettingsProto_Rotation__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Screensaver__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Screensaver__components = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Screensaver__activate_on_dock = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Screensaver__activate_on_sleep = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Screensaver__default_component = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Screensaver__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Screensaver__enabled,
    &android__providers__settings__SecureSettingsProto__Screensaver__components,
    &android__providers__settings__SecureSettingsProto__Screensaver__activate_on_dock,
    &android__providers__settings__SecureSettingsProto__Screensaver__activate_on_sleep,
    &android__providers__settings__SecureSettingsProto__Screensaver__default_component,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__screensaver = { 47, 11, android_providers_settings_SecureSettingsProto_Screensaver__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__global_search_activity = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__num_promoted_sources = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__max_results_to_display = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__max_results_per_source = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__web_results_override_limit = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__promoted_source_deadline_millis = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__source_timeout_millis = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__prefill_millis = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__max_stat_age_millis = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__max_source_event_age_millis = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__min_impressions_for_source_ranking = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__min_clicks_for_source_ranking = { 12, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__max_shortcuts_returned = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__query_thread_core_pool_size = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__query_thread_max_pool_size = { 15, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__shortcut_refresh_core_pool_size = { 16, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__shortcut_refresh_max_pool_size = { 17, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__thread_keepalive_seconds = { 18, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Search__per_source_concurrent_query_limit = { 19, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Search__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Search__global_search_activity,
    &android__providers__settings__SecureSettingsProto__Search__num_promoted_sources,
    &android__providers__settings__SecureSettingsProto__Search__max_results_to_display,
    &android__providers__settings__SecureSettingsProto__Search__max_results_per_source,
    &android__providers__settings__SecureSettingsProto__Search__web_results_override_limit,
    &android__providers__settings__SecureSettingsProto__Search__promoted_source_deadline_millis,
    &android__providers__settings__SecureSettingsProto__Search__source_timeout_millis,
    &android__providers__settings__SecureSettingsProto__Search__prefill_millis,
    &android__providers__settings__SecureSettingsProto__Search__max_stat_age_millis,
    &android__providers__settings__SecureSettingsProto__Search__max_source_event_age_millis,
    &android__providers__settings__SecureSettingsProto__Search__min_impressions_for_source_ranking,
    &android__providers__settings__SecureSettingsProto__Search__min_clicks_for_source_ranking,
    &android__providers__settings__SecureSettingsProto__Search__max_shortcuts_returned,
    &android__providers__settings__SecureSettingsProto__Search__query_thread_core_pool_size,
    &android__providers__settings__SecureSettingsProto__Search__query_thread_max_pool_size,
    &android__providers__settings__SecureSettingsProto__Search__shortcut_refresh_core_pool_size,
    &android__providers__settings__SecureSettingsProto__Search__shortcut_refresh_max_pool_size,
    &android__providers__settings__SecureSettingsProto__Search__thread_keepalive_seconds,
    &android__providers__settings__SecureSettingsProto__Search__per_source_concurrent_query_limit,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__search = { 48, 11, android_providers_settings_SecureSettingsProto_Search__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__SpellChecker__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__SpellChecker__selected = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__SpellChecker__selected_subtype = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_SpellChecker__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__SpellChecker__enabled,
    &android__providers__settings__SecureSettingsProto__SpellChecker__selected,
    &android__providers__settings__SecureSettingsProto__SpellChecker__selected_subtype,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__spell_checker = { 49, 11, android_providers_settings_SecureSettingsProto_SpellChecker__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__settings_classname = { 50, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__show_first_crash_dialog_dev_option = { 51, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__skip_first_use_hints = { 52, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__sleep_timeout = { 53, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__sms_default_application = { 54, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__sync_parent_sounds = { 55, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__system_navigation_keys_enabled = { 56, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__trust_agents_initialized = { 57, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Tts__default_rate = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Tts__default_pitch = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Tts__default_synth = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Tts__default_locale = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Tts__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Tts__default_rate,
    &android__providers__settings__SecureSettingsProto__Tts__default_pitch,
    &android__providers__settings__SecureSettingsProto__Tts__default_synth,
    &android__providers__settings__SecureSettingsProto__Tts__default_locale,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__tts = { 58, 11, android_providers_settings_SecureSettingsProto_Tts__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Tty__tty_mode_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Tty__preferred_tty_mode = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Tty__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Tty__tty_mode_enabled,
    &android__providers__settings__SecureSettingsProto__Tty__preferred_tty_mode,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__tty = { 59, 11, android_providers_settings_SecureSettingsProto_Tty__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Tv__user_setup_complete = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Tv__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Tv__user_setup_complete,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__tv = { 60, 11, android_providers_settings_SecureSettingsProto_Tv__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__ui_night_mode = { 61, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__unknown_sources_default_reversed = { 62, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__usb_audio_automatic_routing_disabled = { 63, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__user_setup_complete = { 64, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Voice__interaction_service = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Voice__recognition_service = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Voice__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Voice__interaction_service,
    &android__providers__settings__SecureSettingsProto__Voice__recognition_service,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__voice = { 65, 11, android_providers_settings_SecureSettingsProto_Voice__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Volume__hush_gesture = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Volume__unsafe_volume_music_active_ms = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Volume__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Volume__hush_gesture,
    &android__providers__settings__SecureSettingsProto__Volume__unsafe_volume_music_active_ms,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__volume = { 66, 11, android_providers_settings_SecureSettingsProto_Volume__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Vr__display_mode = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Vr__enabled_listeners = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Vr__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Vr__display_mode,
    &android__providers__settings__SecureSettingsProto__Vr__enabled_listeners,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__vr = { 67, 11, android_providers_settings_SecureSettingsProto_Vr__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__wake_gesture_enabled = { 68, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__rtt_calling_mode = { 69, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Launcher__swipe_up_to_switch_apps_enabled = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Launcher__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Launcher__swipe_up_to_switch_apps_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__launcher = { 70, 11, android_providers_settings_SecureSettingsProto_Launcher__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Zen__duration = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Zen__show_zen_upgrade_notification = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Zen__show_zen_settings_suggestion = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Zen__settings_updated = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Zen__settings_suggestion_viewed = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Zen__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Zen__duration,
    &android__providers__settings__SecureSettingsProto__Zen__show_zen_upgrade_notification,
    &android__providers__settings__SecureSettingsProto__Zen__show_zen_settings_suggestion,
    &android__providers__settings__SecureSettingsProto__Zen__settings_updated,
    &android__providers__settings__SecureSettingsProto__Zen__settings_suggestion_viewed,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__zen = { 71, 11, android_providers_settings_SecureSettingsProto_Zen__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Sounds__charging_sounds_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Sounds__charging_vibration_enabled = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Sounds__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Sounds__charging_sounds_enabled,
    &android__providers__settings__SecureSettingsProto__Sounds__charging_vibration_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__sounds = { 72, 11, android_providers_settings_SecureSettingsProto_Sounds__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__LocationAccessCheck__interval_millis = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__LocationAccessCheck__delay_millis = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_LocationAccessCheck__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__LocationAccessCheck__interval_millis,
    &android__providers__settings__SecureSettingsProto__LocationAccessCheck__delay_millis,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__location_access_check = { 73, 11, android_providers_settings_SecureSettingsProto_LocationAccessCheck__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__aware_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__silence_alarms_count = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__silence_calls_count = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__silence_enabled = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__silence_timer_count = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__skip_count = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__skip_enabled = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__silence_alarms_touch_count = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__silence_calls_touch_count = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__silence_timer_touch_count = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__skip_touch_count = { 12, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__aware_tap_pause_gesture_count = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__Gesture__aware_tap_pause_touch_count = { 14, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Gesture__MSG__255[] = {
    &android__providers__settings__SecureSettingsProto__Gesture__aware_enabled,
    &android__providers__settings__SecureSettingsProto__Gesture__silence_alarms_count,
    &android__providers__settings__SecureSettingsProto__Gesture__silence_calls_count,
    &android__providers__settings__SecureSettingsProto__Gesture__silence_enabled,
    &android__providers__settings__SecureSettingsProto__Gesture__silence_timer_count,
    &android__providers__settings__SecureSettingsProto__Gesture__skip_count,
    &android__providers__settings__SecureSettingsProto__Gesture__skip_enabled,
    &android__providers__settings__SecureSettingsProto__Gesture__silence_alarms_touch_count,
    &android__providers__settings__SecureSettingsProto__Gesture__silence_calls_touch_count,
    &android__providers__settings__SecureSettingsProto__Gesture__silence_timer_touch_count,
    &android__providers__settings__SecureSettingsProto__Gesture__skip_touch_count,
    &android__providers__settings__SecureSettingsProto__Gesture__aware_tap_pause_gesture_count,
    &android__providers__settings__SecureSettingsProto__Gesture__aware_tap_pause_touch_count,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__gesture = { 74, 11, android_providers_settings_SecureSettingsProto_Gesture__MSG__255, 255, NULL };
Privacy android__providers__settings__SecureSettingsProto__theme_customization_overlay_packages = { 75, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__navigation_mode = { 76, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__GestureNavigation__back_gesture_inset_scale_left = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__GestureNavigation__back_gesture_inset_scale_right = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_GestureNavigation__MSG__255[] = {
    &android__providers__settings__SecureSettingsProto__GestureNavigation__back_gesture_inset_scale_left,
    &android__providers__settings__SecureSettingsProto__GestureNavigation__back_gesture_inset_scale_right,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__gesture_navigation = { 77, 11, android_providers_settings_SecureSettingsProto_GestureNavigation__MSG__255, 255, NULL };
Privacy android__providers__settings__SecureSettingsProto__AdaptiveSleep__enabled = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_AdaptiveSleep__MSG__255[] = {
    &android__providers__settings__SecureSettingsProto__AdaptiveSleep__enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__adaptive_sleep = { 78, 11, android_providers_settings_SecureSettingsProto_AdaptiveSleep__MSG__255, 255, NULL };
Privacy android__providers__settings__SecureSettingsProto__Controls__enabled = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Controls__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__Controls__enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__controls = { 79, 11, android_providers_settings_SecureSettingsProto_Controls__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__OneHanded__one_handed_mode_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__OneHanded__one_handed_mode_timeout = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__OneHanded__taps_app_to_exit = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__OneHanded__one_handed_mode_activated = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_OneHanded__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__OneHanded__one_handed_mode_enabled,
    &android__providers__settings__SecureSettingsProto__OneHanded__one_handed_mode_timeout,
    &android__providers__settings__SecureSettingsProto__OneHanded__taps_app_to_exit,
    &android__providers__settings__SecureSettingsProto__OneHanded__one_handed_mode_activated,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__onehanded = { 80, 11, android_providers_settings_SecureSettingsProto_OneHanded__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__PowerMenuPrivacy__show = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_PowerMenuPrivacy__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__PowerMenuPrivacy__show,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__power_menu_privacy = { 81, 11, android_providers_settings_SecureSettingsProto_PowerMenuPrivacy__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__swipe_bottom_to_notification_enabled = { 82, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__EmergencyResponse__emergency_gesture_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__EmergencyResponse__emergency_gesture_sound_enabled = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_EmergencyResponse__MSG__255[] = {
    &android__providers__settings__SecureSettingsProto__EmergencyResponse__emergency_gesture_enabled,
    &android__providers__settings__SecureSettingsProto__EmergencyResponse__emergency_gesture_sound_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__emergency_response = { 83, 11, android_providers_settings_SecureSettingsProto_EmergencyResponse__MSG__255, 255, NULL };
Privacy android__providers__settings__SecureSettingsProto__adaptive_connectivity_enabled = { 84, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__font_weight_adjustment = { 85, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__AssistHandles__learning_time_elapsed_millis = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__AssistHandles__learning_event_count = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_AssistHandles__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__AssistHandles__learning_time_elapsed_millis,
    &android__providers__settings__SecureSettingsProto__AssistHandles__learning_event_count,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__assist_handles = { 86, 11, android_providers_settings_SecureSettingsProto_AssistHandles__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__ReduceBrightColors__activated = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__ReduceBrightColors__level = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SecureSettingsProto__ReduceBrightColors__persist_across_reboots = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_ReduceBrightColors__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__ReduceBrightColors__activated,
    &android__providers__settings__SecureSettingsProto__ReduceBrightColors__level,
    &android__providers__settings__SecureSettingsProto__ReduceBrightColors__persist_across_reboots,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__reduce_bright_colors = { 87, 11, android_providers_settings_SecureSettingsProto_ReduceBrightColors__MSG__100, 100, NULL };
Privacy android__providers__settings__SecureSettingsProto__CameraAutorotate__enabled = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_CameraAutorotate__MSG__255[] = {
    &android__providers__settings__SecureSettingsProto__CameraAutorotate__enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__camera_autorotate = { 88, 11, android_providers_settings_SecureSettingsProto_CameraAutorotate__MSG__255, 255, NULL };
Privacy android__providers__settings__SecureSettingsProto__Clipboard__show_access_notifications = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_Clipboard__MSG__255[] = {
    &android__providers__settings__SecureSettingsProto__Clipboard__show_access_notifications,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__clipboard = { 89, 11, android_providers_settings_SecureSettingsProto_Clipboard__MSG__255, 255, NULL };
Privacy android__providers__settings__SecureSettingsProto__DateTime__location_time_zone_detection_enabled = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SecureSettingsProto_DateTime__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__DateTime__location_time_zone_detection_enabled,
    NULL };

Privacy android__providers__settings__SecureSettingsProto__date_time = { 90, 11, android_providers_settings_SecureSettingsProto_DateTime__MSG__100, 100, NULL };

Privacy* android_providers_settings_SecureSettingsProto__MSG__100[] = {
    &android__providers__settings__SecureSettingsProto__accessibility,
    &android__providers__settings__SecureSettingsProto__always_on_vpn,
    &android__providers__settings__SecureSettingsProto__anr_show_background,
    &android__providers__settings__SecureSettingsProto__assist,
    &android__providers__settings__SecureSettingsProto__autofill,
    &android__providers__settings__SecureSettingsProto__automatic_storage_manager,
    &android__providers__settings__SecureSettingsProto__backup,
    &android__providers__settings__SecureSettingsProto__bluetooth_on_while_driving,
    &android__providers__settings__SecureSettingsProto__camera,
    &android__providers__settings__SecureSettingsProto__carrier_apps_handled,
    &android__providers__settings__SecureSettingsProto__cmas_additional_broadcast_pkg,
    &android__providers__settings__SecureSettingsProto__connectivity_release_pending_intent_delay_ms,
    &android__providers__settings__SecureSettingsProto__device_paired,
    &android__providers__settings__SecureSettingsProto__dialer_default_application,
    &android__providers__settings__SecureSettingsProto__display_density_forced,
    &android__providers__settings__SecureSettingsProto__double_tap_to_wake,
    &android__providers__settings__SecureSettingsProto__doze,
    &android__providers__settings__SecureSettingsProto__emergency_assistance_application,
    &android__providers__settings__SecureSettingsProto__enhanced_voice_privacy_enabled,
    &android__providers__settings__SecureSettingsProto__immersive_mode_confirmations,
    &android__providers__settings__SecureSettingsProto__incall,
    &android__providers__settings__SecureSettingsProto__input_methods,
    &android__providers__settings__SecureSettingsProto__install_non_market_apps,
    &android__providers__settings__SecureSettingsProto__instant_apps_enabled,
    &android__providers__settings__SecureSettingsProto__last_setup_shown,
    &android__providers__settings__SecureSettingsProto__location,
    &android__providers__settings__SecureSettingsProto__lock_screen,
    &android__providers__settings__SecureSettingsProto__lock_to_app_exit_locked,
    &android__providers__settings__SecureSettingsProto__lockdown_in_power_menu,
    &android__providers__settings__SecureSettingsProto__long_press_timeout,
    &android__providers__settings__SecureSettingsProto__managed_profile,
    &android__providers__settings__SecureSettingsProto__mount,
    &android__providers__settings__SecureSettingsProto__multi_press_timeout,
    &android__providers__settings__SecureSettingsProto__nfc_payment,
    &android__providers__settings__SecureSettingsProto__night_display,
    &android__providers__settings__SecureSettingsProto__notification,
    &android__providers__settings__SecureSettingsProto__package_verifier,
    &android__providers__settings__SecureSettingsProto__parental_control,
    &android__providers__settings__SecureSettingsProto__print_service,
    &android__providers__settings__SecureSettingsProto__qs,
    &android__providers__settings__SecureSettingsProto__rotation,
    &android__providers__settings__SecureSettingsProto__screensaver,
    &android__providers__settings__SecureSettingsProto__search,
    &android__providers__settings__SecureSettingsProto__spell_checker,
    &android__providers__settings__SecureSettingsProto__settings_classname,
    &android__providers__settings__SecureSettingsProto__show_first_crash_dialog_dev_option,
    &android__providers__settings__SecureSettingsProto__skip_first_use_hints,
    &android__providers__settings__SecureSettingsProto__sleep_timeout,
    &android__providers__settings__SecureSettingsProto__sms_default_application,
    &android__providers__settings__SecureSettingsProto__sync_parent_sounds,
    &android__providers__settings__SecureSettingsProto__system_navigation_keys_enabled,
    &android__providers__settings__SecureSettingsProto__trust_agents_initialized,
    &android__providers__settings__SecureSettingsProto__tts,
    &android__providers__settings__SecureSettingsProto__tty,
    &android__providers__settings__SecureSettingsProto__tv,
    &android__providers__settings__SecureSettingsProto__ui_night_mode,
    &android__providers__settings__SecureSettingsProto__unknown_sources_default_reversed,
    &android__providers__settings__SecureSettingsProto__usb_audio_automatic_routing_disabled,
    &android__providers__settings__SecureSettingsProto__user_setup_complete,
    &android__providers__settings__SecureSettingsProto__voice,
    &android__providers__settings__SecureSettingsProto__volume,
    &android__providers__settings__SecureSettingsProto__vr,
    &android__providers__settings__SecureSettingsProto__wake_gesture_enabled,
    &android__providers__settings__SecureSettingsProto__rtt_calling_mode,
    &android__providers__settings__SecureSettingsProto__launcher,
    &android__providers__settings__SecureSettingsProto__zen,
    &android__providers__settings__SecureSettingsProto__sounds,
    &android__providers__settings__SecureSettingsProto__location_access_check,
    &android__providers__settings__SecureSettingsProto__gesture,
    &android__providers__settings__SecureSettingsProto__theme_customization_overlay_packages,
    &android__providers__settings__SecureSettingsProto__navigation_mode,
    &android__providers__settings__SecureSettingsProto__gesture_navigation,
    &android__providers__settings__SecureSettingsProto__adaptive_sleep,
    &android__providers__settings__SecureSettingsProto__controls,
    &android__providers__settings__SecureSettingsProto__onehanded,
    &android__providers__settings__SecureSettingsProto__power_menu_privacy,
    &android__providers__settings__SecureSettingsProto__swipe_bottom_to_notification_enabled,
    &android__providers__settings__SecureSettingsProto__emergency_response,
    &android__providers__settings__SecureSettingsProto__adaptive_connectivity_enabled,
    &android__providers__settings__SecureSettingsProto__font_weight_adjustment,
    &android__providers__settings__SecureSettingsProto__assist_handles,
    &android__providers__settings__SecureSettingsProto__reduce_bright_colors,
    &android__providers__settings__SecureSettingsProto__camera_autorotate,
    &android__providers__settings__SecureSettingsProto__clipboard,
    &android__providers__settings__SecureSettingsProto__date_time,
    NULL };

Privacy android__providers__settings__UserSettingsProto__secure_settings = { 2, 11, android_providers_settings_SecureSettingsProto__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__advanced_settings = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Bluetooth__discoverability = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Bluetooth__discoverability_timeout_secs = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Bluetooth__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Bluetooth__discoverability,
    &android__providers__settings__SystemSettingsProto__Bluetooth__discoverability_timeout_secs,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__bluetooth = { 4, 11, android_providers_settings_SystemSettingsProto_Bluetooth__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__display_color_mode = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__DevOptions__pointer_location = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__DevOptions__show_touches = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__DevOptions__window_orientation_listener_log = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_DevOptions__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__DevOptions__pointer_location,
    &android__providers__settings__SystemSettingsProto__DevOptions__show_touches,
    &android__providers__settings__SystemSettingsProto__DevOptions__window_orientation_listener_log,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__developer_options = { 7, 11, android_providers_settings_SystemSettingsProto_DevOptions__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__DtmfTone__play_when_dialing = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__DtmfTone__type_played_when_dialing = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_DtmfTone__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__DtmfTone__play_when_dialing,
    &android__providers__settings__SystemSettingsProto__DtmfTone__type_played_when_dialing,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__dtmf_tone = { 8, 11, android_providers_settings_SystemSettingsProto_DtmfTone__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__egg_mode = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__end_button_behavior = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__font_scale = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__HapticFeedback__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__HapticFeedback__intensity = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_HapticFeedback__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__HapticFeedback__enabled,
    &android__providers__settings__SystemSettingsProto__HapticFeedback__intensity,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__haptic_feedback = { 12, 11, android_providers_settings_SystemSettingsProto_HapticFeedback__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__hearing_aid = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__lock_to_app_enabled = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Lockscreen__sounds_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Lockscreen__disabled = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Lockscreen__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Lockscreen__sounds_enabled,
    &android__providers__settings__SystemSettingsProto__Lockscreen__disabled,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__lockscreen = { 15, 11, android_providers_settings_SystemSettingsProto_Lockscreen__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__Notification__light_pulse = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Notification__vibration_intensity = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Notification__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Notification__light_pulse,
    &android__providers__settings__SystemSettingsProto__Notification__vibration_intensity,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__notification = { 17, 11, android_providers_settings_SystemSettingsProto_Notification__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__pointer_speed = { 18, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Rotation__accelerometer_rotation = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Rotation__user_rotation = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Rotation__hide_rotation_lock_toggle_for_accessibility = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Rotation__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Rotation__accelerometer_rotation,
    &android__providers__settings__SystemSettingsProto__Rotation__user_rotation,
    &android__providers__settings__SystemSettingsProto__Rotation__hide_rotation_lock_toggle_for_accessibility,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__rotation = { 20, 11, android_providers_settings_SystemSettingsProto_Rotation__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__Screen__off_timeout = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Screen__brightness = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Screen__brightness_for_vr = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Screen__brightness_mode = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Screen__auto_brightness_adj = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Screen__brightness_float = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Screen__brightness_for_vr_float = { 7, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Screen__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Screen__off_timeout,
    &android__providers__settings__SystemSettingsProto__Screen__brightness,
    &android__providers__settings__SystemSettingsProto__Screen__brightness_for_vr,
    &android__providers__settings__SystemSettingsProto__Screen__brightness_mode,
    &android__providers__settings__SystemSettingsProto__Screen__auto_brightness_adj,
    &android__providers__settings__SystemSettingsProto__Screen__brightness_float,
    &android__providers__settings__SystemSettingsProto__Screen__brightness_for_vr_float,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__screen = { 22, 11, android_providers_settings_SystemSettingsProto_Screen__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__setup_wizard_has_run = { 23, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__show_battery_percent = { 24, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__show_gtalk_service_status = { 25, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Sip__receive_calls = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Sip__call_options = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Sip__always = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Sip__address_only = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Sip__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Sip__receive_calls,
    &android__providers__settings__SystemSettingsProto__Sip__call_options,
    &android__providers__settings__SystemSettingsProto__Sip__always,
    &android__providers__settings__SystemSettingsProto__Sip__address_only,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__sip = { 26, 11, android_providers_settings_SystemSettingsProto_Sip__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__sound_effects_enabled = { 27, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__system_locales = { 28, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Text__auto_replace = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Text__auto_caps = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Text__auto_punctuate = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Text__show_password = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Text__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Text__auto_replace,
    &android__providers__settings__SystemSettingsProto__Text__auto_caps,
    &android__providers__settings__SystemSettingsProto__Text__auto_punctuate,
    &android__providers__settings__SystemSettingsProto__Text__show_password,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__text = { 29, 11, android_providers_settings_SystemSettingsProto_Text__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__time_12_24 = { 30, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__tty_mode = { 31, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Vibrate__on = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Vibrate__input_devices = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Vibrate__in_silent = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Vibrate__when_ringing = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Vibrate__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Vibrate__on,
    &android__providers__settings__SystemSettingsProto__Vibrate__input_devices,
    &android__providers__settings__SystemSettingsProto__Vibrate__in_silent,
    &android__providers__settings__SystemSettingsProto__Vibrate__when_ringing,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__vibrate = { 32, 11, android_providers_settings_SystemSettingsProto_Vibrate__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__ring = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__system = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__voice = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__music = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__alarm = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__notification = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__bluetooth_sco = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__accessibility = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__master = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__master_mono = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__mode_ringer_streams_affected = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__mute_streams_affected = { 12, 11, NULL, 200, NULL };
Privacy android__providers__settings__SystemSettingsProto__Volume__master_balance = { 13, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto_Volume__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__Volume__ring,
    &android__providers__settings__SystemSettingsProto__Volume__system,
    &android__providers__settings__SystemSettingsProto__Volume__voice,
    &android__providers__settings__SystemSettingsProto__Volume__music,
    &android__providers__settings__SystemSettingsProto__Volume__alarm,
    &android__providers__settings__SystemSettingsProto__Volume__notification,
    &android__providers__settings__SystemSettingsProto__Volume__bluetooth_sco,
    &android__providers__settings__SystemSettingsProto__Volume__accessibility,
    &android__providers__settings__SystemSettingsProto__Volume__master,
    &android__providers__settings__SystemSettingsProto__Volume__master_mono,
    &android__providers__settings__SystemSettingsProto__Volume__mode_ringer_streams_affected,
    &android__providers__settings__SystemSettingsProto__Volume__mute_streams_affected,
    &android__providers__settings__SystemSettingsProto__Volume__master_balance,
    NULL };

Privacy android__providers__settings__SystemSettingsProto__volume = { 33, 11, android_providers_settings_SystemSettingsProto_Volume__MSG__100, 100, NULL };
Privacy android__providers__settings__SystemSettingsProto__when_to_make_wifi_calls = { 34, 11, NULL, 200, NULL };

Privacy* android_providers_settings_SystemSettingsProto__MSG__100[] = {
    &android__providers__settings__SystemSettingsProto__advanced_settings,
    &android__providers__settings__SystemSettingsProto__bluetooth,
    &android__providers__settings__SystemSettingsProto__display_color_mode,
    &android__providers__settings__SystemSettingsProto__developer_options,
    &android__providers__settings__SystemSettingsProto__dtmf_tone,
    &android__providers__settings__SystemSettingsProto__egg_mode,
    &android__providers__settings__SystemSettingsProto__end_button_behavior,
    &android__providers__settings__SystemSettingsProto__font_scale,
    &android__providers__settings__SystemSettingsProto__haptic_feedback,
    &android__providers__settings__SystemSettingsProto__hearing_aid,
    &android__providers__settings__SystemSettingsProto__lock_to_app_enabled,
    &android__providers__settings__SystemSettingsProto__lockscreen,
    &android__providers__settings__SystemSettingsProto__notification,
    &android__providers__settings__SystemSettingsProto__pointer_speed,
    &android__providers__settings__SystemSettingsProto__rotation,
    &android__providers__settings__SystemSettingsProto__screen,
    &android__providers__settings__SystemSettingsProto__setup_wizard_has_run,
    &android__providers__settings__SystemSettingsProto__show_battery_percent,
    &android__providers__settings__SystemSettingsProto__show_gtalk_service_status,
    &android__providers__settings__SystemSettingsProto__sip,
    &android__providers__settings__SystemSettingsProto__sound_effects_enabled,
    &android__providers__settings__SystemSettingsProto__system_locales,
    &android__providers__settings__SystemSettingsProto__text,
    &android__providers__settings__SystemSettingsProto__time_12_24,
    &android__providers__settings__SystemSettingsProto__tty_mode,
    &android__providers__settings__SystemSettingsProto__vibrate,
    &android__providers__settings__SystemSettingsProto__volume,
    &android__providers__settings__SystemSettingsProto__when_to_make_wifi_calls,
    NULL };

Privacy android__providers__settings__UserSettingsProto__system_settings = { 3, 11, android_providers_settings_SystemSettingsProto__MSG__100, 100, NULL };

Privacy* android_providers_settings_UserSettingsProto__MSG__100[] = {
    &android__providers__settings__UserSettingsProto__user_id,
    &android__providers__settings__UserSettingsProto__secure_settings,
    &android__providers__settings__UserSettingsProto__system_settings,
    NULL };

Privacy android__providers__settings__SettingsServiceDumpProto__user_settings = { 1, 11, android_providers_settings_UserSettingsProto__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__adb_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__add_users_when_locked = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__AirplaneMode__on = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__AirplaneMode__radios = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__AirplaneMode__toggleable_radios = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_AirplaneMode__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__AirplaneMode__on,
    &android__providers__settings__GlobalSettingsProto__AirplaneMode__radios,
    &android__providers__settings__GlobalSettingsProto__AirplaneMode__toggleable_radios,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__airplane_mode = { 5, 11, android_providers_settings_GlobalSettingsProto_AirplaneMode__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__allow_user_switching_when_system_user_locked = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__always_finish_activities = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__animator_duration_scale = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Anomaly__config_version = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Anomaly__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Anomaly__config_version,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__anomaly = { 11, 11, android_providers_settings_GlobalSettingsProto_Anomaly__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__App__standby_enabled = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__App__auto_restriction_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__App__forced_app_standby_enabled = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__App__forced_app_standby_for_small_battery_enabled = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_App__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__App__standby_enabled,
    &android__providers__settings__GlobalSettingsProto__App__auto_restriction_enabled,
    &android__providers__settings__GlobalSettingsProto__App__forced_app_standby_enabled,
    &android__providers__settings__GlobalSettingsProto__App__forced_app_standby_for_small_battery_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__app = { 13, 11, android_providers_settings_GlobalSettingsProto_App__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__assisted_gps_enabled = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__audio_safe_volume_state = { 15, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DateTime__auto_time = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DateTime__auto_time_zone = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_DateTime__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__DateTime__auto_time,
    &android__providers__settings__GlobalSettingsProto__DateTime__auto_time_zone,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__date_time = { 16, 11, android_providers_settings_GlobalSettingsProto_DateTime__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Battery__discharge_duration_threshold = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Battery__discharge_threshold = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Battery__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Battery__discharge_duration_threshold,
    &android__providers__settings__GlobalSettingsProto__Battery__discharge_threshold,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__battery = { 19, 11, android_providers_settings_GlobalSettingsProto_Battery__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__always_available = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__low_power_window_ms = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__balanced_window_ms = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__low_latency_window_ms = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__low_power_interval_ms = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__balanced_interval_ms = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__low_latency_interval_ms = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__BleScan__background_mode = { 8, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_BleScan__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__BleScan__always_available,
    &android__providers__settings__GlobalSettingsProto__BleScan__low_power_window_ms,
    &android__providers__settings__GlobalSettingsProto__BleScan__balanced_window_ms,
    &android__providers__settings__GlobalSettingsProto__BleScan__low_latency_window_ms,
    &android__providers__settings__GlobalSettingsProto__BleScan__low_power_interval_ms,
    &android__providers__settings__GlobalSettingsProto__BleScan__balanced_interval_ms,
    &android__providers__settings__GlobalSettingsProto__BleScan__low_latency_interval_ms,
    &android__providers__settings__GlobalSettingsProto__BleScan__background_mode,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__ble_scan = { 20, 11, android_providers_settings_GlobalSettingsProto_BleScan__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Bluetooth__class_of_device = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Bluetooth__on = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Bluetooth__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Bluetooth__class_of_device,
    &android__providers__settings__GlobalSettingsProto__Bluetooth__on,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__bluetooth = { 21, 11, android_providers_settings_GlobalSettingsProto_Bluetooth__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__boot_count = { 22, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__bugreport_in_power_menu = { 23, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__call_auto_retry = { 24, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__CaptivePortal__mode = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__CaptivePortal__detection_enabled = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__CaptivePortal__use_https = { 8, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_CaptivePortal__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__CaptivePortal__mode,
    &android__providers__settings__GlobalSettingsProto__CaptivePortal__detection_enabled,
    &android__providers__settings__GlobalSettingsProto__CaptivePortal__use_https,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__captive_portal = { 25, 11, android_providers_settings_GlobalSettingsProto_CaptivePortal__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Carrier__app_whitelist = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Carrier__app_names = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Carrier__install_carrier_app_notification_persistent = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Carrier__install_carrier_app_notification_sleep_millis = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Carrier__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Carrier__app_whitelist,
    &android__providers__settings__GlobalSettingsProto__Carrier__app_names,
    &android__providers__settings__GlobalSettingsProto__Carrier__install_carrier_app_notification_persistent,
    &android__providers__settings__GlobalSettingsProto__Carrier__install_carrier_app_notification_sleep_millis,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__carrier = { 26, 11, android_providers_settings_GlobalSettingsProto_Carrier__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Cdma__cell_broadcast_sms = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Cdma__roaming_mode = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Cdma__subscription_mode = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Cdma__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Cdma__cell_broadcast_sms,
    &android__providers__settings__GlobalSettingsProto__Cdma__roaming_mode,
    &android__providers__settings__GlobalSettingsProto__Cdma__subscription_mode,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__cdma = { 27, 11, android_providers_settings_GlobalSettingsProto_Cdma__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__cell_on = { 28, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__chained_battery_attribution_enabled = { 30, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__compatibility_mode = { 31, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Connectivity__metrics_buffer_size = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Connectivity__change_delay = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Connectivity__sampling_interval_in_seconds = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Connectivity__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Connectivity__metrics_buffer_size,
    &android__providers__settings__GlobalSettingsProto__Connectivity__change_delay,
    &android__providers__settings__GlobalSettingsProto__Connectivity__sampling_interval_in_seconds,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__connectivity = { 32, 11, android_providers_settings_GlobalSettingsProto_Connectivity__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__contact_metadata_sync_enabled = { 33, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__contacts_database_wal_enabled = { 34, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Data__activity_timeout_mobile = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Data__activity_timeout_wifi = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Data__roaming = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Data__stall_alarm_non_aggressive_delay_in_ms = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Data__stall_alarm_aggressive_delay_in_ms = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Data__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Data__activity_timeout_mobile,
    &android__providers__settings__GlobalSettingsProto__Data__activity_timeout_wifi,
    &android__providers__settings__GlobalSettingsProto__Data__roaming,
    &android__providers__settings__GlobalSettingsProto__Data__stall_alarm_non_aggressive_delay_in_ms,
    &android__providers__settings__GlobalSettingsProto__Data__stall_alarm_aggressive_delay_in_ms,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__data = { 35, 11, android_providers_settings_GlobalSettingsProto_Data__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Database__creation_buildid = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Database__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Database__creation_buildid,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__database = { 36, 11, android_providers_settings_GlobalSettingsProto_Database__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Debug__view_attributes = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Debug__view_attributes_application_package = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Debug__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Debug__view_attributes,
    &android__providers__settings__GlobalSettingsProto__Debug__view_attributes_application_package,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__debug = { 37, 11, android_providers_settings_GlobalSettingsProto_Debug__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Default__install_location = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Default__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Default__install_location,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__default = { 38, 11, android_providers_settings_GlobalSettingsProto_Default__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__settings_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__force_resizable_activities = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__enable_freeform_windows_support = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__force_rtl = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__emulate_display_cutout = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__force_desktop_mode_on_external_displays = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__enable_sizecompat_freeform = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__enable_non_resizable_multi_window = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Development__disable_window_blurs = { 9, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Development__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Development__settings_enabled,
    &android__providers__settings__GlobalSettingsProto__Development__force_resizable_activities,
    &android__providers__settings__GlobalSettingsProto__Development__enable_freeform_windows_support,
    &android__providers__settings__GlobalSettingsProto__Development__force_rtl,
    &android__providers__settings__GlobalSettingsProto__Development__emulate_display_cutout,
    &android__providers__settings__GlobalSettingsProto__Development__force_desktop_mode_on_external_displays,
    &android__providers__settings__GlobalSettingsProto__Development__enable_sizecompat_freeform,
    &android__providers__settings__GlobalSettingsProto__Development__enable_non_resizable_multi_window,
    &android__providers__settings__GlobalSettingsProto__Development__disable_window_blurs,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__development = { 39, 11, android_providers_settings_GlobalSettingsProto_Development__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Device__provisioned = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Device__provisioning_mobile_data_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Device__demo_mode = { 6, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Device__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Device__provisioned,
    &android__providers__settings__GlobalSettingsProto__Device__provisioning_mobile_data_enabled,
    &android__providers__settings__GlobalSettingsProto__Device__demo_mode,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__device = { 40, 11, android_providers_settings_GlobalSettingsProto_Device__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__disk_free_change_reporting_threshold = { 41, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Display__size_forced = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Display__scaling_force = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Display__panel_lpm = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Display__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Display__size_forced,
    &android__providers__settings__GlobalSettingsProto__Display__scaling_force,
    &android__providers__settings__GlobalSettingsProto__Display__panel_lpm,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__display = { 42, 11, android_providers_settings_GlobalSettingsProto_Display__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DnsResolver__sample_validity_seconds = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DnsResolver__success_threshold_percent = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DnsResolver__min_samples = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DnsResolver__max_samples = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_DnsResolver__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__DnsResolver__sample_validity_seconds,
    &android__providers__settings__GlobalSettingsProto__DnsResolver__success_threshold_percent,
    &android__providers__settings__GlobalSettingsProto__DnsResolver__min_samples,
    &android__providers__settings__GlobalSettingsProto__DnsResolver__max_samples,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__dns_resolver = { 43, 11, android_providers_settings_GlobalSettingsProto_DnsResolver__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__dock_audio_media_enabled = { 44, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Download__max_bytes_over_mobile = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Download__recommended_max_bytes_over_mobile = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Download__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Download__max_bytes_over_mobile,
    &android__providers__settings__GlobalSettingsProto__Download__recommended_max_bytes_over_mobile,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__download = { 45, 11, android_providers_settings_GlobalSettingsProto_Download__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Dropbox__age_seconds = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Dropbox__max_files = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Dropbox__quota_kb = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Dropbox__quota_percent = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Dropbox__reserve_percent = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Dropbox__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Dropbox__age_seconds,
    &android__providers__settings__GlobalSettingsProto__Dropbox__max_files,
    &android__providers__settings__GlobalSettingsProto__Dropbox__quota_kb,
    &android__providers__settings__GlobalSettingsProto__Dropbox__quota_percent,
    &android__providers__settings__GlobalSettingsProto__Dropbox__reserve_percent,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__dropbox = { 46, 11, android_providers_settings_GlobalSettingsProto_Dropbox__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Emergency__tone = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Emergency__affordance_needed = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Emergency__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Emergency__tone,
    &android__providers__settings__GlobalSettingsProto__Emergency__affordance_needed,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__emergency = { 47, 11, android_providers_settings_GlobalSettingsProto_Emergency__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__accessibility_global_gesture_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__gpu_debug_layers = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__ephemeral_feature = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__cellular_on_boot = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__diskstats_logging = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__cache_quota_calculation = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__deletion_helper_no_threshold_toggle = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Enable__gnss_raw_meas_full_tracking = { 8, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Enable__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Enable__accessibility_global_gesture_enabled,
    &android__providers__settings__GlobalSettingsProto__Enable__gpu_debug_layers,
    &android__providers__settings__GlobalSettingsProto__Enable__ephemeral_feature,
    &android__providers__settings__GlobalSettingsProto__Enable__cellular_on_boot,
    &android__providers__settings__GlobalSettingsProto__Enable__diskstats_logging,
    &android__providers__settings__GlobalSettingsProto__Enable__cache_quota_calculation,
    &android__providers__settings__GlobalSettingsProto__Enable__deletion_helper_no_threshold_toggle,
    &android__providers__settings__GlobalSettingsProto__Enable__gnss_raw_meas_full_tracking,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__enable = { 48, 11, android_providers_settings_GlobalSettingsProto_Enable__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__encoded_surround_output = { 49, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__enhanced_4g_mode_enabled = { 50, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Euicc__provisioned = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Euicc__factory_reset_timeout_millis = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Euicc__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Euicc__provisioned,
    &android__providers__settings__GlobalSettingsProto__Euicc__factory_reset_timeout_millis,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__euicc = { 52, 11, android_providers_settings_GlobalSettingsProto_Euicc__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__fancy_ime_animations = { 53, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__force_allow_on_external = { 54, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__fps_divisor = { 55, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__fstrim_mandatory_interval = { 56, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__GlobalHttpProxy__setting_ui_enabled = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_GlobalHttpProxy__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__GlobalHttpProxy__setting_ui_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__global_http_proxy = { 57, 11, android_providers_settings_GlobalSettingsProto_GlobalHttpProxy__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__gprs_register_check_period_ms = { 58, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Gpu__debug_layers = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Gpu__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Gpu__debug_layers,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__gpu = { 59, 11, android_providers_settings_GlobalSettingsProto_Gpu__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Hdmi__control_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Hdmi__system_audio_control_enabled = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Hdmi__control_auto_wakeup_enabled = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Hdmi__control_auto_device_off_enabled = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Hdmi__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Hdmi__control_enabled,
    &android__providers__settings__GlobalSettingsProto__Hdmi__system_audio_control_enabled,
    &android__providers__settings__GlobalSettingsProto__Hdmi__control_auto_wakeup_enabled,
    &android__providers__settings__GlobalSettingsProto__Hdmi__control_auto_device_off_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__hdmi = { 60, 11, android_providers_settings_GlobalSettingsProto_Hdmi__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__heads_up_notifications_enabled = { 61, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__hidden_api_blacklist_exemptions = { 62, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InetCondition__debounce_up_delay = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InetCondition__debounce_down_delay = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_InetCondition__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__InetCondition__debounce_up_delay,
    &android__providers__settings__GlobalSettingsProto__InetCondition__debounce_down_delay,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__inet_condition = { 63, 11, android_providers_settings_GlobalSettingsProto_InetCondition__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InstantApp__dexopt_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InstantApp__ephemeral_cookie_max_size_bytes = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InstantApp__installed_min_cache_period = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InstantApp__installed_max_cache_period = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InstantApp__uninstalled_min_cache_period = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__InstantApp__uninstalled_max_cache_period = { 6, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_InstantApp__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__InstantApp__dexopt_enabled,
    &android__providers__settings__GlobalSettingsProto__InstantApp__ephemeral_cookie_max_size_bytes,
    &android__providers__settings__GlobalSettingsProto__InstantApp__installed_min_cache_period,
    &android__providers__settings__GlobalSettingsProto__InstantApp__installed_max_cache_period,
    &android__providers__settings__GlobalSettingsProto__InstantApp__uninstalled_min_cache_period,
    &android__providers__settings__GlobalSettingsProto__InstantApp__uninstalled_max_cache_period,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__instant_app = { 64, 11, android_providers_settings_GlobalSettingsProto_InstantApp__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__keep_profile_in_background = { 67, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__background_throttle_interval_ms = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__background_throttle_proximity_alert_interval_ms = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__background_throttle_package_whitelist = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__settings_link_to_permissions_enabled = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__global_kill_switch = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__gnss_satellite_blocklist = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__gnss_hal_location_request_duration_millis = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Location__ignore_settings_package_whitelist = { 8, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Location__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Location__background_throttle_interval_ms,
    &android__providers__settings__GlobalSettingsProto__Location__background_throttle_proximity_alert_interval_ms,
    &android__providers__settings__GlobalSettingsProto__Location__background_throttle_package_whitelist,
    &android__providers__settings__GlobalSettingsProto__Location__settings_link_to_permissions_enabled,
    &android__providers__settings__GlobalSettingsProto__Location__global_kill_switch,
    &android__providers__settings__GlobalSettingsProto__Location__gnss_satellite_blocklist,
    &android__providers__settings__GlobalSettingsProto__Location__gnss_hal_location_request_duration_millis,
    &android__providers__settings__GlobalSettingsProto__Location__ignore_settings_package_whitelist,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__location = { 69, 11, android_providers_settings_GlobalSettingsProto_Location__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__LowPowerMode__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__LowPowerMode__trigger_level = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__LowPowerMode__trigger_level_max = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__LowPowerMode__automatic_power_saver_mode = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_LowPowerMode__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__LowPowerMode__enabled,
    &android__providers__settings__GlobalSettingsProto__LowPowerMode__trigger_level,
    &android__providers__settings__GlobalSettingsProto__LowPowerMode__trigger_level_max,
    &android__providers__settings__GlobalSettingsProto__LowPowerMode__automatic_power_saver_mode,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__low_power_mode = { 70, 11, android_providers_settings_GlobalSettingsProto_LowPowerMode__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__lte_service_forced = { 71, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__mdc_initial_max_retry = { 72, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Mhl__input_switching_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Mhl__power_charge_enabled = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Mhl__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Mhl__input_switching_enabled,
    &android__providers__settings__GlobalSettingsProto__Mhl__power_charge_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__mhl = { 73, 11, android_providers_settings_GlobalSettingsProto_Mhl__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__MobileData__allowed = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__MobileData__always_on = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_MobileData__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__MobileData__allowed,
    &android__providers__settings__GlobalSettingsProto__MobileData__always_on,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__mobile_data = { 74, 11, android_providers_settings_GlobalSettingsProto_MobileData__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__mode_ringer = { 75, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__MultiSim__voice_call_subscription = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__MultiSim__voice_prompt = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__MultiSim__data_call_subscription = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__MultiSim__sms_subscription = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__MultiSim__sms_prompt = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_MultiSim__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__MultiSim__voice_call_subscription,
    &android__providers__settings__GlobalSettingsProto__MultiSim__voice_prompt,
    &android__providers__settings__GlobalSettingsProto__MultiSim__data_call_subscription,
    &android__providers__settings__GlobalSettingsProto__MultiSim__sms_subscription,
    &android__providers__settings__GlobalSettingsProto__MultiSim__sms_prompt,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__multi_sim = { 76, 11, android_providers_settings_GlobalSettingsProto_MultiSim__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__poll_interval = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__time_cache_max_age = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__global_alert_bytes = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__sample_enabled = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__augment_enabled = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__dev_bucket_duration = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__dev_persist_bytes = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__dev_rotate_age = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__dev_delete_age = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_bucket_duration = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_persist_bytes = { 12, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_rotate_age = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_delete_age = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_bucket_duration = { 15, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_persist_bytes = { 16, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_rotate_age = { 17, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_delete_age = { 18, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Netstats__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Netstats__enabled,
    &android__providers__settings__GlobalSettingsProto__Netstats__poll_interval,
    &android__providers__settings__GlobalSettingsProto__Netstats__time_cache_max_age,
    &android__providers__settings__GlobalSettingsProto__Netstats__global_alert_bytes,
    &android__providers__settings__GlobalSettingsProto__Netstats__sample_enabled,
    &android__providers__settings__GlobalSettingsProto__Netstats__augment_enabled,
    &android__providers__settings__GlobalSettingsProto__Netstats__dev_bucket_duration,
    &android__providers__settings__GlobalSettingsProto__Netstats__dev_persist_bytes,
    &android__providers__settings__GlobalSettingsProto__Netstats__dev_rotate_age,
    &android__providers__settings__GlobalSettingsProto__Netstats__dev_delete_age,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_bucket_duration,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_persist_bytes,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_rotate_age,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_delete_age,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_bucket_duration,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_persist_bytes,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_rotate_age,
    &android__providers__settings__GlobalSettingsProto__Netstats__uid_tag_delete_age,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__netstats = { 77, 11, android_providers_settings_GlobalSettingsProto_Netstats__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__preferred_network_mode = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__scorer_app = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__switch_notification_daily_limit = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__switch_notification_rate_limit_millis = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__avoid_bad_wifi = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__metered_multipath_preference = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__watchlist_last_report_time = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__scoring_ui_enabled = { 9, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__recommendations_enabled = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__recommendations_package = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__recommendation_request_timeout_ms = { 12, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__watchlist_enabled = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__scoring_provisioned = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__access_timeout_ms = { 15, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Network__recommended_network_evaluator_cache_expiry_ms = { 16, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Network__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Network__preferred_network_mode,
    &android__providers__settings__GlobalSettingsProto__Network__scorer_app,
    &android__providers__settings__GlobalSettingsProto__Network__switch_notification_daily_limit,
    &android__providers__settings__GlobalSettingsProto__Network__switch_notification_rate_limit_millis,
    &android__providers__settings__GlobalSettingsProto__Network__avoid_bad_wifi,
    &android__providers__settings__GlobalSettingsProto__Network__metered_multipath_preference,
    &android__providers__settings__GlobalSettingsProto__Network__watchlist_last_report_time,
    &android__providers__settings__GlobalSettingsProto__Network__scoring_ui_enabled,
    &android__providers__settings__GlobalSettingsProto__Network__recommendations_enabled,
    &android__providers__settings__GlobalSettingsProto__Network__recommendations_package,
    &android__providers__settings__GlobalSettingsProto__Network__recommendation_request_timeout_ms,
    &android__providers__settings__GlobalSettingsProto__Network__watchlist_enabled,
    &android__providers__settings__GlobalSettingsProto__Network__scoring_provisioned,
    &android__providers__settings__GlobalSettingsProto__Network__access_timeout_ms,
    &android__providers__settings__GlobalSettingsProto__Network__recommended_network_evaluator_cache_expiry_ms,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__network = { 78, 11, android_providers_settings_GlobalSettingsProto_Network__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__new_contact_aggregator = { 79, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__night_display_forced_auto_mode_available = { 80, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__NitzUpdate__diff = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__NitzUpdate__spacing = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_NitzUpdate__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__NitzUpdate__diff,
    &android__providers__settings__GlobalSettingsProto__NitzUpdate__spacing,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__nitz_update = { 81, 11, android_providers_settings_GlobalSettingsProto_NitzUpdate__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Notification__max_notification_enqueue_rate = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Notification__show_notification_channel_warnings = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Notification__snooze_options = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Notification__smart_replies_in_notifications_flags = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Notification__smart_suggestions_in_notifications_flags = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Notification__bubbles = { 6, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Notification__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Notification__max_notification_enqueue_rate,
    &android__providers__settings__GlobalSettingsProto__Notification__show_notification_channel_warnings,
    &android__providers__settings__GlobalSettingsProto__Notification__snooze_options,
    &android__providers__settings__GlobalSettingsProto__Notification__smart_replies_in_notifications_flags,
    &android__providers__settings__GlobalSettingsProto__Notification__smart_suggestions_in_notifications_flags,
    &android__providers__settings__GlobalSettingsProto__Notification__bubbles,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__notification = { 82, 11, android_providers_settings_GlobalSettingsProto_Notification__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__nsd_on = { 83, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Ntp__timeout_ms = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Ntp__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Ntp__timeout_ms,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__ntp = { 84, 11, android_providers_settings_GlobalSettingsProto_Ntp__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__UserAbsentSmallBattery__radios_off_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__UserAbsentSmallBattery__touch_off_enabled = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_UserAbsentSmallBattery__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__UserAbsentSmallBattery__radios_off_enabled,
    &android__providers__settings__GlobalSettingsProto__UserAbsentSmallBattery__touch_off_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__user_absent_small_battery = { 85, 11, android_providers_settings_GlobalSettingsProto_UserAbsentSmallBattery__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__ota_disable_automatic_update = { 86, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__overlay_display_devices = { 87, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__override_settings_provider_restore_any_version = { 88, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__pac_change_delay = { 89, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PackageVerifier__enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PackageVerifier__timeout = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PackageVerifier__setting_visible = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PackageVerifier__include_adb = { 5, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_PackageVerifier__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__PackageVerifier__enabled,
    &android__providers__settings__GlobalSettingsProto__PackageVerifier__timeout,
    &android__providers__settings__GlobalSettingsProto__PackageVerifier__setting_visible,
    &android__providers__settings__GlobalSettingsProto__PackageVerifier__include_adb,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__package_verifier = { 90, 11, android_providers_settings_GlobalSettingsProto_PackageVerifier__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PdpWatchdog__poll_interval_ms = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PdpWatchdog__long_poll_interval_ms = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PdpWatchdog__error_poll_interval_ms = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PdpWatchdog__trigger_packet_count = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PdpWatchdog__error_poll_count = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__PdpWatchdog__max_pdp_reset_fail_count = { 6, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_PdpWatchdog__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__PdpWatchdog__poll_interval_ms,
    &android__providers__settings__GlobalSettingsProto__PdpWatchdog__long_poll_interval_ms,
    &android__providers__settings__GlobalSettingsProto__PdpWatchdog__error_poll_interval_ms,
    &android__providers__settings__GlobalSettingsProto__PdpWatchdog__trigger_packet_count,
    &android__providers__settings__GlobalSettingsProto__PdpWatchdog__error_poll_count,
    &android__providers__settings__GlobalSettingsProto__PdpWatchdog__max_pdp_reset_fail_count,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__pdp_watchdog = { 91, 11, android_providers_settings_GlobalSettingsProto_PdpWatchdog__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__private = { 96, 11, NULL, 0, NULL };
Privacy android__providers__settings__GlobalSettingsProto__provisioning_apn_alarm_delay_in_ms = { 97, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__read_external_storage_enforced_default = { 98, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__require_password_to_decrypt = { 99, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__safe_boot_disallowed = { 100, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Selinux__status = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Selinux__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Selinux__status,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__selinux = { 101, 11, android_providers_settings_GlobalSettingsProto_Selinux__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__send_action_app_error = { 102, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__set_install_location = { 103, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__show_first_crash_dialog = { 105, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__show_restart_in_crash_dialog = { 106, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__show_mute_in_crash_dialog = { 107, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sms__outgoing_check_interval_ms = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sms__outgoing_check_max_count = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sms__short_code_confirmation = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sms__short_code_rule = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sms__access_restriction_enabled = { 7, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Sms__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Sms__outgoing_check_interval_ms,
    &android__providers__settings__GlobalSettingsProto__Sms__outgoing_check_max_count,
    &android__providers__settings__GlobalSettingsProto__Sms__short_code_confirmation,
    &android__providers__settings__GlobalSettingsProto__Sms__short_code_rule,
    &android__providers__settings__GlobalSettingsProto__Sms__access_restriction_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__sms = { 109, 11, android_providers_settings_GlobalSettingsProto_Sms__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sounds__dock_sounds_enabled = { 7, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sounds__dock_sounds_enabled_when_accessibility = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sounds__low_battery_sound_timeout = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sounds__low_battery_sounds_enabled = { 12, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Sounds__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Sounds__dock_sounds_enabled,
    &android__providers__settings__GlobalSettingsProto__Sounds__dock_sounds_enabled_when_accessibility,
    &android__providers__settings__GlobalSettingsProto__Sounds__low_battery_sound_timeout,
    &android__providers__settings__GlobalSettingsProto__Sounds__low_battery_sounds_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__sounds = { 110, 11, android_providers_settings_GlobalSettingsProto_Sounds__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__SoundTrigger__max_sound_trigger_detection_service_ops_per_day = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__SoundTrigger__detection_service_op_timeout_ms = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_SoundTrigger__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__SoundTrigger__max_sound_trigger_detection_service_ops_per_day,
    &android__providers__settings__GlobalSettingsProto__SoundTrigger__detection_service_op_timeout_ms,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__sound_trigger = { 111, 11, android_providers_settings_GlobalSettingsProto_SoundTrigger__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__speed_label_cache_eviction_age_ms = { 112, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__sqlite_compatibility_wal_flags = { 113, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__stay_on_while_plugged_in = { 114, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Storage__benchmark_interval = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Storage__settings_clobber_threshold = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Storage__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Storage__benchmark_interval,
    &android__providers__settings__GlobalSettingsProto__Storage__settings_clobber_threshold,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__storage = { 115, 11, android_providers_settings_GlobalSettingsProto_Storage__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sync__max_retry_delay_in_seconds = { 1, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Sync__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Sync__max_retry_delay_in_seconds,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__sync = { 116, 11, android_providers_settings_GlobalSettingsProto_Sync__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sys__free_storage_log_interval_mins = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sys__storage_threshold_percentage = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sys__storage_threshold_max_bytes = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sys__storage_full_threshold_bytes = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sys__storage_cache_percentage = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sys__storage_cache_max_bytes = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Sys__uidcpupower = { 8, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Sys__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Sys__free_storage_log_interval_mins,
    &android__providers__settings__GlobalSettingsProto__Sys__storage_threshold_percentage,
    &android__providers__settings__GlobalSettingsProto__Sys__storage_threshold_max_bytes,
    &android__providers__settings__GlobalSettingsProto__Sys__storage_full_threshold_bytes,
    &android__providers__settings__GlobalSettingsProto__Sys__storage_cache_percentage,
    &android__providers__settings__GlobalSettingsProto__Sys__storage_cache_max_bytes,
    &android__providers__settings__GlobalSettingsProto__Sys__uidcpupower,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__sys = { 117, 11, android_providers_settings_GlobalSettingsProto_Sys__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__tcp_default_init_rwnd = { 118, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__TemperatureWarning__show_temperature_warning = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__TemperatureWarning__warning_temperature_level = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__TemperatureWarning__show_usb_temperature_alarm = { 3, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_TemperatureWarning__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__TemperatureWarning__show_temperature_warning,
    &android__providers__settings__GlobalSettingsProto__TemperatureWarning__warning_temperature_level,
    &android__providers__settings__GlobalSettingsProto__TemperatureWarning__show_usb_temperature_alarm,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__temperature_warning = { 119, 11, android_providers_settings_GlobalSettingsProto_TemperatureWarning__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Tether__supported = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Tether__dun_required = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Tether__offload_disabled = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Tether__timeout_enabled = { 112, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Tether__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Tether__supported,
    &android__providers__settings__GlobalSettingsProto__Tether__dun_required,
    &android__providers__settings__GlobalSettingsProto__Tether__offload_disabled,
    &android__providers__settings__GlobalSettingsProto__Tether__timeout_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__tether = { 120, 11, android_providers_settings_GlobalSettingsProto_Tether__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__theater_mode_on = { 122, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__time_only_mode_constants = { 123, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__transition_animation_scale = { 124, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__unused_static_shared_lib_min_cache_period_ms = { 126, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__usb_mass_storage_enabled = { 127, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__use_google_mail = { 128, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__use_open_wifi_package = { 129, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__vt_ims_enabled = { 130, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__wait_for_debugger = { 131, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Webview__fallback_logic_enabled = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Webview__provider = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Webview__multiprocess = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Webview__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Webview__fallback_logic_enabled,
    &android__providers__settings__GlobalSettingsProto__Webview__provider,
    &android__providers__settings__GlobalSettingsProto__Webview__multiprocess,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__webview = { 132, 11, android_providers_settings_GlobalSettingsProto_Webview__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wfc__ims_enabled = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wfc__ims_mode = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wfc__ims_roaming_mode = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wfc__ims_roaming_enabled = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Wfc__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Wfc__ims_enabled,
    &android__providers__settings__GlobalSettingsProto__Wfc__ims_mode,
    &android__providers__settings__GlobalSettingsProto__Wfc__ims_roaming_mode,
    &android__providers__settings__GlobalSettingsProto__Wfc__ims_roaming_enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__wfc = { 133, 11, android_providers_settings_GlobalSettingsProto_Wfc__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__sleep_policy = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__badging_thresholds = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__display_on = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__display_certification_on = { 4, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__display_wps_config = { 5, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__networks_available_notification_on = { 6, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__networks_available_repeat_delay = { 8, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__framework_scan_interval_ms = { 10, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__idle_ms = { 11, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__num_open_networks_kept = { 12, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__on = { 13, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__scan_always_available = { 14, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__wakeup_enabled = { 15, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__saved_state = { 16, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__supplicant_scan_interval_ms = { 17, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__enhanced_auto_join = { 18, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__network_show_rssi = { 19, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__scan_interval_when_p2p_connected_ms = { 20, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__watchdog_on = { 21, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__watchdog_poor_network_test_enabled = { 22, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__suspend_optimizations_enabled = { 23, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__verbose_logging_enabled = { 24, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__max_dhcp_retry_count = { 26, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__mobile_data_transition_wakelock_timeout_ms = { 27, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__device_owner_configs_lockdown = { 28, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__frequency_band = { 29, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__ephemeral_out_of_range_timeout_ms = { 32, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__on_when_proxy_disconnected = { 33, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Wifi__bounce_delay_override_ms = { 34, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Wifi__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Wifi__sleep_policy,
    &android__providers__settings__GlobalSettingsProto__Wifi__badging_thresholds,
    &android__providers__settings__GlobalSettingsProto__Wifi__display_on,
    &android__providers__settings__GlobalSettingsProto__Wifi__display_certification_on,
    &android__providers__settings__GlobalSettingsProto__Wifi__display_wps_config,
    &android__providers__settings__GlobalSettingsProto__Wifi__networks_available_notification_on,
    &android__providers__settings__GlobalSettingsProto__Wifi__networks_available_repeat_delay,
    &android__providers__settings__GlobalSettingsProto__Wifi__framework_scan_interval_ms,
    &android__providers__settings__GlobalSettingsProto__Wifi__idle_ms,
    &android__providers__settings__GlobalSettingsProto__Wifi__num_open_networks_kept,
    &android__providers__settings__GlobalSettingsProto__Wifi__on,
    &android__providers__settings__GlobalSettingsProto__Wifi__scan_always_available,
    &android__providers__settings__GlobalSettingsProto__Wifi__wakeup_enabled,
    &android__providers__settings__GlobalSettingsProto__Wifi__saved_state,
    &android__providers__settings__GlobalSettingsProto__Wifi__supplicant_scan_interval_ms,
    &android__providers__settings__GlobalSettingsProto__Wifi__enhanced_auto_join,
    &android__providers__settings__GlobalSettingsProto__Wifi__network_show_rssi,
    &android__providers__settings__GlobalSettingsProto__Wifi__scan_interval_when_p2p_connected_ms,
    &android__providers__settings__GlobalSettingsProto__Wifi__watchdog_on,
    &android__providers__settings__GlobalSettingsProto__Wifi__watchdog_poor_network_test_enabled,
    &android__providers__settings__GlobalSettingsProto__Wifi__suspend_optimizations_enabled,
    &android__providers__settings__GlobalSettingsProto__Wifi__verbose_logging_enabled,
    &android__providers__settings__GlobalSettingsProto__Wifi__max_dhcp_retry_count,
    &android__providers__settings__GlobalSettingsProto__Wifi__mobile_data_transition_wakelock_timeout_ms,
    &android__providers__settings__GlobalSettingsProto__Wifi__device_owner_configs_lockdown,
    &android__providers__settings__GlobalSettingsProto__Wifi__frequency_band,
    &android__providers__settings__GlobalSettingsProto__Wifi__ephemeral_out_of_range_timeout_ms,
    &android__providers__settings__GlobalSettingsProto__Wifi__on_when_proxy_disconnected,
    &android__providers__settings__GlobalSettingsProto__Wifi__bounce_delay_override_ms,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__wifi = { 134, 11, android_providers_settings_GlobalSettingsProto_Wifi__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__wimax_networks_available_notification_on = { 135, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__window_animation_scale = { 136, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__wtf_is_fatal = { 137, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Zen__mode = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Zen__mode_ringer_level = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Zen__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Zen__mode,
    &android__providers__settings__GlobalSettingsProto__Zen__mode_ringer_level,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__zen = { 138, 11, android_providers_settings_GlobalSettingsProto_Zen__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__zram_enabled = { 139, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Autofill__compat_mode_allowed_packages = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Autofill__logging_level = { 2, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Autofill__max_partitions_size = { 3, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__Autofill__max_visible_datasets = { 4, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_Autofill__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__Autofill__compat_mode_allowed_packages,
    &android__providers__settings__GlobalSettingsProto__Autofill__logging_level,
    &android__providers__settings__GlobalSettingsProto__Autofill__max_partitions_size,
    &android__providers__settings__GlobalSettingsProto__Autofill__max_visible_datasets,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__autofill = { 140, 11, android_providers_settings_GlobalSettingsProto_Autofill__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__show_hidden_launcher_icon_apps_enabled = { 141, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__show_new_app_installed_notification_enabled = { 142, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DynamicPowerSavings__disable_threshold = { 1, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__DynamicPowerSavings__enabled = { 2, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto_DynamicPowerSavings__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__DynamicPowerSavings__disable_threshold,
    &android__providers__settings__GlobalSettingsProto__DynamicPowerSavings__enabled,
    NULL };

Privacy android__providers__settings__GlobalSettingsProto__dynamic_power_savings = { 143, 11, android_providers_settings_GlobalSettingsProto_DynamicPowerSavings__MSG__100, 100, NULL };
Privacy android__providers__settings__GlobalSettingsProto__native_flags_health_check_enabled = { 144, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__text_classifier_action_model_params = { 145, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__apply_ramping_ringer = { 147, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__app_ops_constants = { 148, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__cached_apps_freezer_enabled = { 152, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__nr_nsa_tracking_screen_off_mode = { 153, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__power_button_long_press_duration_ms = { 154, 11, NULL, 200, NULL };
Privacy android__providers__settings__GlobalSettingsProto__uwb_enabled = { 155, 11, NULL, 200, NULL };

Privacy* android_providers_settings_GlobalSettingsProto__MSG__100[] = {
    &android__providers__settings__GlobalSettingsProto__adb_enabled,
    &android__providers__settings__GlobalSettingsProto__add_users_when_locked,
    &android__providers__settings__GlobalSettingsProto__airplane_mode,
    &android__providers__settings__GlobalSettingsProto__allow_user_switching_when_system_user_locked,
    &android__providers__settings__GlobalSettingsProto__always_finish_activities,
    &android__providers__settings__GlobalSettingsProto__animator_duration_scale,
    &android__providers__settings__GlobalSettingsProto__anomaly,
    &android__providers__settings__GlobalSettingsProto__app,
    &android__providers__settings__GlobalSettingsProto__assisted_gps_enabled,
    &android__providers__settings__GlobalSettingsProto__audio_safe_volume_state,
    &android__providers__settings__GlobalSettingsProto__date_time,
    &android__providers__settings__GlobalSettingsProto__battery,
    &android__providers__settings__GlobalSettingsProto__ble_scan,
    &android__providers__settings__GlobalSettingsProto__bluetooth,
    &android__providers__settings__GlobalSettingsProto__boot_count,
    &android__providers__settings__GlobalSettingsProto__bugreport_in_power_menu,
    &android__providers__settings__GlobalSettingsProto__call_auto_retry,
    &android__providers__settings__GlobalSettingsProto__captive_portal,
    &android__providers__settings__GlobalSettingsProto__carrier,
    &android__providers__settings__GlobalSettingsProto__cdma,
    &android__providers__settings__GlobalSettingsProto__cell_on,
    &android__providers__settings__GlobalSettingsProto__chained_battery_attribution_enabled,
    &android__providers__settings__GlobalSettingsProto__compatibility_mode,
    &android__providers__settings__GlobalSettingsProto__connectivity,
    &android__providers__settings__GlobalSettingsProto__contact_metadata_sync_enabled,
    &android__providers__settings__GlobalSettingsProto__contacts_database_wal_enabled,
    &android__providers__settings__GlobalSettingsProto__data,
    &android__providers__settings__GlobalSettingsProto__database,
    &android__providers__settings__GlobalSettingsProto__debug,
    &android__providers__settings__GlobalSettingsProto__default,
    &android__providers__settings__GlobalSettingsProto__development,
    &android__providers__settings__GlobalSettingsProto__device,
    &android__providers__settings__GlobalSettingsProto__disk_free_change_reporting_threshold,
    &android__providers__settings__GlobalSettingsProto__display,
    &android__providers__settings__GlobalSettingsProto__dns_resolver,
    &android__providers__settings__GlobalSettingsProto__dock_audio_media_enabled,
    &android__providers__settings__GlobalSettingsProto__download,
    &android__providers__settings__GlobalSettingsProto__dropbox,
    &android__providers__settings__GlobalSettingsProto__emergency,
    &android__providers__settings__GlobalSettingsProto__enable,
    &android__providers__settings__GlobalSettingsProto__encoded_surround_output,
    &android__providers__settings__GlobalSettingsProto__enhanced_4g_mode_enabled,
    &android__providers__settings__GlobalSettingsProto__euicc,
    &android__providers__settings__GlobalSettingsProto__fancy_ime_animations,
    &android__providers__settings__GlobalSettingsProto__force_allow_on_external,
    &android__providers__settings__GlobalSettingsProto__fps_divisor,
    &android__providers__settings__GlobalSettingsProto__fstrim_mandatory_interval,
    &android__providers__settings__GlobalSettingsProto__global_http_proxy,
    &android__providers__settings__GlobalSettingsProto__gprs_register_check_period_ms,
    &android__providers__settings__GlobalSettingsProto__gpu,
    &android__providers__settings__GlobalSettingsProto__hdmi,
    &android__providers__settings__GlobalSettingsProto__heads_up_notifications_enabled,
    &android__providers__settings__GlobalSettingsProto__hidden_api_blacklist_exemptions,
    &android__providers__settings__GlobalSettingsProto__inet_condition,
    &android__providers__settings__GlobalSettingsProto__instant_app,
    &android__providers__settings__GlobalSettingsProto__keep_profile_in_background,
    &android__providers__settings__GlobalSettingsProto__location,
    &android__providers__settings__GlobalSettingsProto__low_power_mode,
    &android__providers__settings__GlobalSettingsProto__lte_service_forced,
    &android__providers__settings__GlobalSettingsProto__mdc_initial_max_retry,
    &android__providers__settings__GlobalSettingsProto__mhl,
    &android__providers__settings__GlobalSettingsProto__mobile_data,
    &android__providers__settings__GlobalSettingsProto__mode_ringer,
    &android__providers__settings__GlobalSettingsProto__multi_sim,
    &android__providers__settings__GlobalSettingsProto__netstats,
    &android__providers__settings__GlobalSettingsProto__network,
    &android__providers__settings__GlobalSettingsProto__new_contact_aggregator,
    &android__providers__settings__GlobalSettingsProto__night_display_forced_auto_mode_available,
    &android__providers__settings__GlobalSettingsProto__nitz_update,
    &android__providers__settings__GlobalSettingsProto__notification,
    &android__providers__settings__GlobalSettingsProto__nsd_on,
    &android__providers__settings__GlobalSettingsProto__ntp,
    &android__providers__settings__GlobalSettingsProto__user_absent_small_battery,
    &android__providers__settings__GlobalSettingsProto__ota_disable_automatic_update,
    &android__providers__settings__GlobalSettingsProto__overlay_display_devices,
    &android__providers__settings__GlobalSettingsProto__override_settings_provider_restore_any_version,
    &android__providers__settings__GlobalSettingsProto__pac_change_delay,
    &android__providers__settings__GlobalSettingsProto__package_verifier,
    &android__providers__settings__GlobalSettingsProto__pdp_watchdog,
    &android__providers__settings__GlobalSettingsProto__private,
    &android__providers__settings__GlobalSettingsProto__provisioning_apn_alarm_delay_in_ms,
    &android__providers__settings__GlobalSettingsProto__read_external_storage_enforced_default,
    &android__providers__settings__GlobalSettingsProto__require_password_to_decrypt,
    &android__providers__settings__GlobalSettingsProto__safe_boot_disallowed,
    &android__providers__settings__GlobalSettingsProto__selinux,
    &android__providers__settings__GlobalSettingsProto__send_action_app_error,
    &android__providers__settings__GlobalSettingsProto__set_install_location,
    &android__providers__settings__GlobalSettingsProto__show_first_crash_dialog,
    &android__providers__settings__GlobalSettingsProto__show_restart_in_crash_dialog,
    &android__providers__settings__GlobalSettingsProto__show_mute_in_crash_dialog,
    &android__providers__settings__GlobalSettingsProto__sms,
    &android__providers__settings__GlobalSettingsProto__sounds,
    &android__providers__settings__GlobalSettingsProto__sound_trigger,
    &android__providers__settings__GlobalSettingsProto__speed_label_cache_eviction_age_ms,
    &android__providers__settings__GlobalSettingsProto__sqlite_compatibility_wal_flags,
    &android__providers__settings__GlobalSettingsProto__stay_on_while_plugged_in,
    &android__providers__settings__GlobalSettingsProto__storage,
    &android__providers__settings__GlobalSettingsProto__sync,
    &android__providers__settings__GlobalSettingsProto__sys,
    &android__providers__settings__GlobalSettingsProto__tcp_default_init_rwnd,
    &android__providers__settings__GlobalSettingsProto__temperature_warning,
    &android__providers__settings__GlobalSettingsProto__tether,
    &android__providers__settings__GlobalSettingsProto__theater_mode_on,
    &android__providers__settings__GlobalSettingsProto__time_only_mode_constants,
    &android__providers__settings__GlobalSettingsProto__transition_animation_scale,
    &android__providers__settings__GlobalSettingsProto__unused_static_shared_lib_min_cache_period_ms,
    &android__providers__settings__GlobalSettingsProto__usb_mass_storage_enabled,
    &android__providers__settings__GlobalSettingsProto__use_google_mail,
    &android__providers__settings__GlobalSettingsProto__use_open_wifi_package,
    &android__providers__settings__GlobalSettingsProto__vt_ims_enabled,
    &android__providers__settings__GlobalSettingsProto__wait_for_debugger,
    &android__providers__settings__GlobalSettingsProto__webview,
    &android__providers__settings__GlobalSettingsProto__wfc,
    &android__providers__settings__GlobalSettingsProto__wifi,
    &android__providers__settings__GlobalSettingsProto__wimax_networks_available_notification_on,
    &android__providers__settings__GlobalSettingsProto__window_animation_scale,
    &android__providers__settings__GlobalSettingsProto__wtf_is_fatal,
    &android__providers__settings__GlobalSettingsProto__zen,
    &android__providers__settings__GlobalSettingsProto__zram_enabled,
    &android__providers__settings__GlobalSettingsProto__autofill,
    &android__providers__settings__GlobalSettingsProto__show_hidden_launcher_icon_apps_enabled,
    &android__providers__settings__GlobalSettingsProto__show_new_app_installed_notification_enabled,
    &android__providers__settings__GlobalSettingsProto__dynamic_power_savings,
    &android__providers__settings__GlobalSettingsProto__native_flags_health_check_enabled,
    &android__providers__settings__GlobalSettingsProto__text_classifier_action_model_params,
    &android__providers__settings__GlobalSettingsProto__apply_ramping_ringer,
    &android__providers__settings__GlobalSettingsProto__app_ops_constants,
    &android__providers__settings__GlobalSettingsProto__cached_apps_freezer_enabled,
    &android__providers__settings__GlobalSettingsProto__nr_nsa_tracking_screen_off_mode,
    &android__providers__settings__GlobalSettingsProto__power_button_long_press_duration_ms,
    &android__providers__settings__GlobalSettingsProto__uwb_enabled,
    NULL };

Privacy android__providers__settings__SettingsServiceDumpProto__global_settings = { 2, 11, android_providers_settings_GlobalSettingsProto__MSG__100, 100, NULL };

Privacy* android_providers_settings_SettingsServiceDumpProto__MSG__100[] = {
    &android__providers__settings__SettingsServiceDumpProto__user_settings,
    &android__providers__settings__SettingsServiceDumpProto__global_settings,
    NULL };

Privacy android__os__IncidentProto__settings = { 3002, 11, android_providers_settings_SettingsServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: appwidget (3003)
// default android__os__IncidentProto__appwidget: fieldDest=255 incidentDest=255

// Incident Report Section: notification (3004)
Privacy android__service__notification__NotificationRecordProto__channel_id = { 4, 9, NULL, 100, NULL };
Privacy android__service__notification__NotificationRecordProto__sound = { 5, 9, NULL, 100, NULL };
Privacy android__media__AudioAttributesProto__tags = { 4, 9, NULL, 100, NULL };

Privacy* android_media_AudioAttributesProto__MSG__200[] = {
    &android__media__AudioAttributesProto__tags,
    NULL };

Privacy android__service__notification__NotificationRecordProto__audio_attributes = { 6, 11, android_media_AudioAttributesProto__MSG__200, 200, NULL };
Privacy android__service__notification__NotificationRecordProto__group_key = { 9, 9, NULL, 100, NULL };

Privacy* android_service_notification_NotificationRecordProto__MSG__200[] = {
    &android__service__notification__NotificationRecordProto__channel_id,
    &android__service__notification__NotificationRecordProto__sound,
    &android__service__notification__NotificationRecordProto__audio_attributes,
    &android__service__notification__NotificationRecordProto__group_key,
    NULL };

Privacy android__service__notification__NotificationServiceDumpProto__records = { 1, 11, android_service_notification_NotificationRecordProto__MSG__200, 200, NULL };
Privacy android__service__notification__ZenRuleProto__creation_time_ms = { 3, 3, NULL, 200, NULL };
Privacy android__service__notification__ZenRuleProto__enabled = { 4, 8, NULL, 200, NULL };
Privacy android__service__notification__ZenRuleProto__enabler = { 5, 9, NULL, 200, NULL };
Privacy android__service__notification__ZenRuleProto__is_snoozing = { 6, 8, NULL, 200, NULL };
Privacy android__service__notification__ZenRuleProto__zen_mode = { 7, 14, NULL, 200, NULL };
Privacy android__service__notification__ConditionProto__icon = { 5, 5, NULL, 200, NULL };
Privacy android__service__notification__ConditionProto__state = { 6, 14, NULL, 200, NULL };
Privacy android__service__notification__ConditionProto__flags = { 7, 5, NULL, 200, NULL };

Privacy* android_service_notification_ConditionProto__MSG__100[] = {
    &android__service__notification__ConditionProto__icon,
    &android__service__notification__ConditionProto__state,
    &android__service__notification__ConditionProto__flags,
    NULL };

Privacy android__service__notification__ZenRuleProto__condition = { 9, 11, android_service_notification_ConditionProto__MSG__100, 100, NULL };
Privacy android__service__notification__ZenRuleProto__component = { 10, 11, NULL, 200, NULL };
Privacy android__service__notification__ZenRuleProto__zenPolicy = { 11, 11, NULL, 200, NULL };
Privacy android__service__notification__ZenRuleProto__modified = { 12, 8, NULL, 200, NULL };

Privacy* android_service_notification_ZenRuleProto__MSG__100[] = {
    &android__service__notification__ZenRuleProto__creation_time_ms,
    &android__service__notification__ZenRuleProto__enabled,
    &android__service__notification__ZenRuleProto__enabler,
    &android__service__notification__ZenRuleProto__is_snoozing,
    &android__service__notification__ZenRuleProto__zen_mode,
    &android__service__notification__ZenRuleProto__condition,
    &android__service__notification__ZenRuleProto__component,
    &android__service__notification__ZenRuleProto__zenPolicy,
    &android__service__notification__ZenRuleProto__modified,
    NULL };

Privacy android__service__notification__ZenModeProto__enabled_active_conditions = { 2, 11, android_service_notification_ZenRuleProto__MSG__100, 100, NULL };

Privacy* android_service_notification_ZenModeProto__MSG__200[] = {
    &android__service__notification__ZenModeProto__enabled_active_conditions,
    NULL };

Privacy android__service__notification__NotificationServiceDumpProto__zen = { 2, 11, android_service_notification_ZenModeProto__MSG__200, 200, NULL };
Privacy android__app__NotificationChannelProto__id = { 1, 9, NULL, 100, NULL };
Privacy android__app__NotificationChannelProto__name = { 2, 9, NULL, 100, NULL };
Privacy android__app__NotificationChannelProto__description = { 3, 9, NULL, 100, NULL };
Privacy android__app__NotificationChannelProto__sound = { 7, 9, NULL, 100, NULL };
Privacy android__app__NotificationChannelProto__group = { 15, 9, NULL, 100, NULL };
Privacy android__app__NotificationChannelProto__audio_attributes = { 16, 11, android_media_AudioAttributesProto__MSG__200, 200, NULL };

Privacy* android_app_NotificationChannelProto__MSG__200[] = {
    &android__app__NotificationChannelProto__id,
    &android__app__NotificationChannelProto__name,
    &android__app__NotificationChannelProto__description,
    &android__app__NotificationChannelProto__sound,
    &android__app__NotificationChannelProto__group,
    &android__app__NotificationChannelProto__audio_attributes,
    NULL };

Privacy android__service__notification__RankingHelperProto__RecordProto__channels = { 7, 11, android_app_NotificationChannelProto__MSG__200, 200, NULL };
Privacy android__app__NotificationChannelGroupProto__channels = { 5, 11, android_app_NotificationChannelProto__MSG__200, 200, NULL };

Privacy* android_app_NotificationChannelGroupProto__MSG__100[] = {
    &android__app__NotificationChannelGroupProto__channels,
    NULL };

Privacy android__service__notification__RankingHelperProto__RecordProto__channel_groups = { 8, 11, android_app_NotificationChannelGroupProto__MSG__100, 100, NULL };

Privacy* android_service_notification_RankingHelperProto_RecordProto__MSG__200[] = {
    &android__service__notification__RankingHelperProto__RecordProto__channels,
    &android__service__notification__RankingHelperProto__RecordProto__channel_groups,
    NULL };

Privacy android__service__notification__RankingHelperProto__records = { 2, 11, android_service_notification_RankingHelperProto_RecordProto__MSG__200, 200, NULL };
Privacy android__service__notification__RankingHelperProto__records_restored_without_uid = { 3, 11, android_service_notification_RankingHelperProto_RecordProto__MSG__200, 200, NULL };

Privacy* android_service_notification_RankingHelperProto__MSG__200[] = {
    &android__service__notification__RankingHelperProto__records,
    &android__service__notification__RankingHelperProto__records_restored_without_uid,
    NULL };

Privacy android__service__notification__NotificationServiceDumpProto__ranking_config = { 8, 11, android_service_notification_RankingHelperProto__MSG__200, 200, NULL };

Privacy* android_service_notification_NotificationServiceDumpProto__MSG__200[] = {
    &android__service__notification__NotificationServiceDumpProto__records,
    &android__service__notification__NotificationServiceDumpProto__zen,
    &android__service__notification__NotificationServiceDumpProto__ranking_config,
    NULL };

Privacy android__os__IncidentProto__notification = { 3004, 11, android_service_notification_NotificationServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: batterystats (3005)
Privacy android__os__IncidentProto__batterystats = { 3005, 11, NULL, 200, NULL };

// Incident Report Section: battery (3006)
Privacy android__os__IncidentProto__battery = { 3006, 11, NULL, 200, NULL };

// Incident Report Section: diskstats (3007)
Privacy android__os__IncidentProto__diskstats = { 3007, 11, NULL, 200, NULL };

// Incident Report Section: package (3008)
Privacy android__service__pm__PackageProto__states = { 11, 11, NULL, 255, NULL };

Privacy* android_service_pm_PackageProto__MSG__200[] = {
    &android__service__pm__PackageProto__states,
    NULL };

Privacy android__service__pm__PackageServiceDumpProto__packages = { 5, 11, android_service_pm_PackageProto__MSG__200, 200, NULL };
Privacy android__service__pm__PackageServiceDumpProto__messages = { 7, 9, NULL, 100, NULL };

Privacy* android_service_pm_PackageServiceDumpProto__MSG__200[] = {
    &android__service__pm__PackageServiceDumpProto__packages,
    &android__service__pm__PackageServiceDumpProto__messages,
    NULL };

Privacy android__os__IncidentProto__package = { 3008, 11, android_service_pm_PackageServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: power (3009)
Privacy android__os__MessageProto__obj = { 6, 9, NULL, 100, NULL };

Privacy* android_os_MessageProto__MSG__200[] = {
    &android__os__MessageProto__obj,
    NULL };

Privacy android__os__MessageQueueProto__messages = { 1, 11, android_os_MessageProto__MSG__200, 200, NULL };

Privacy* android_os_MessageQueueProto__MSG__200[] = {
    &android__os__MessageQueueProto__messages,
    NULL };

Privacy android__os__LooperProto__queue = { 3, 11, android_os_MessageQueueProto__MSG__200, 200, NULL };

Privacy* android_os_LooperProto__MSG__200[] = {
    &android__os__LooperProto__queue,
    NULL };

Privacy com__android__server__power__PowerManagerServiceDumpProto__looper = { 46, 11, android_os_LooperProto__MSG__200, 200, NULL };

Privacy* com_android_server_power_PowerManagerServiceDumpProto__MSG__200[] = {
    &com__android__server__power__PowerManagerServiceDumpProto__looper,
    NULL };

Privacy android__os__IncidentProto__power = { 3009, 11, com_android_server_power_PowerManagerServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: print (3010)
Privacy android__service__print__PrinterIdProto__service_name = { 1, 11, NULL, 200, NULL };

Privacy* android_service_print_PrinterIdProto__MSG__100[] = {
    &android__service__print__PrinterIdProto__service_name,
    NULL };

Privacy android__service__print__ActivePrintServiceProto__tracked_printers = { 7, 11, android_service_print_PrinterIdProto__MSG__100, 100, NULL };

Privacy* android_service_print_ActivePrintServiceProto__MSG__200[] = {
    &android__service__print__ActivePrintServiceProto__tracked_printers,
    NULL };

Privacy android__service__print__PrintUserStateProto__active_services = { 4, 11, android_service_print_ActivePrintServiceProto__MSG__200, 200, NULL };
Privacy android__service__print__PrintJobInfoProto__label = { 1, 9, NULL, 100, NULL };
Privacy android__service__print__PrintJobInfoProto__print_job_id = { 2, 9, NULL, 100, NULL };
Privacy android__service__print__PrintJobInfoProto__printer = { 4, 11, android_service_print_PrinterIdProto__MSG__100, 100, NULL };
Privacy android__service__print__PrintJobInfoProto__tag = { 5, 9, NULL, 100, NULL };
Privacy android__service__print__PrintDocumentInfoProto__name = { 1, 9, NULL, 100, NULL };

Privacy* android_service_print_PrintDocumentInfoProto__MSG__200[] = {
    &android__service__print__PrintDocumentInfoProto__name,
    NULL };

Privacy android__service__print__PrintJobInfoProto__document_info = { 8, 11, android_service_print_PrintDocumentInfoProto__MSG__200, 200, NULL };

Privacy* android_service_print_PrintJobInfoProto__MSG__200[] = {
    &android__service__print__PrintJobInfoProto__label,
    &android__service__print__PrintJobInfoProto__print_job_id,
    &android__service__print__PrintJobInfoProto__printer,
    &android__service__print__PrintJobInfoProto__tag,
    &android__service__print__PrintJobInfoProto__document_info,
    NULL };

Privacy android__service__print__CachedPrintJobProto__print_job = { 2, 11, android_service_print_PrintJobInfoProto__MSG__200, 200, NULL };

Privacy* android_service_print_CachedPrintJobProto__MSG__200[] = {
    &android__service__print__CachedPrintJobProto__print_job,
    NULL };

Privacy android__service__print__PrintUserStateProto__cached_print_jobs = { 5, 11, android_service_print_CachedPrintJobProto__MSG__200, 200, NULL };
Privacy android__service__print__PrinterDiscoverySessionProto__tracked_printer_requests = { 5, 11, android_service_print_PrinterIdProto__MSG__100, 100, NULL };
Privacy android__service__print__PrinterInfoProto__id = { 1, 11, android_service_print_PrinterIdProto__MSG__100, 100, NULL };
Privacy android__service__print__PrinterInfoProto__status = { 3, 14, NULL, 200, NULL };
Privacy android__service__print__PrinterInfoProto__capabilities = { 5, 11, NULL, 200, NULL };

Privacy* android_service_print_PrinterInfoProto__MSG__100[] = {
    &android__service__print__PrinterInfoProto__id,
    &android__service__print__PrinterInfoProto__status,
    &android__service__print__PrinterInfoProto__capabilities,
    NULL };

Privacy android__service__print__PrinterDiscoverySessionProto__printer = { 6, 11, android_service_print_PrinterInfoProto__MSG__100, 100, NULL };

Privacy* android_service_print_PrinterDiscoverySessionProto__MSG__200[] = {
    &android__service__print__PrinterDiscoverySessionProto__tracked_printer_requests,
    &android__service__print__PrinterDiscoverySessionProto__printer,
    NULL };

Privacy android__service__print__PrintUserStateProto__discovery_sessions = { 6, 11, android_service_print_PrinterDiscoverySessionProto__MSG__200, 200, NULL };
Privacy android__service__print__PrintSpoolerInternalStateProto__print_jobs = { 1, 11, android_service_print_PrintJobInfoProto__MSG__200, 200, NULL };
Privacy android__service__print__PrintSpoolerInternalStateProto__print_job_files = { 2, 9, NULL, 100, NULL };

Privacy* android_service_print_PrintSpoolerInternalStateProto__MSG__200[] = {
    &android__service__print__PrintSpoolerInternalStateProto__print_jobs,
    &android__service__print__PrintSpoolerInternalStateProto__print_job_files,
    NULL };

Privacy android__service__print__PrintSpoolerStateProto__internal_state = { 3, 11, android_service_print_PrintSpoolerInternalStateProto__MSG__200, 200, NULL };

Privacy* android_service_print_PrintSpoolerStateProto__MSG__200[] = {
    &android__service__print__PrintSpoolerStateProto__internal_state,
    NULL };

Privacy android__service__print__PrintUserStateProto__print_spooler_state = { 7, 11, android_service_print_PrintSpoolerStateProto__MSG__200, 200, NULL };

Privacy* android_service_print_PrintUserStateProto__MSG__200[] = {
    &android__service__print__PrintUserStateProto__active_services,
    &android__service__print__PrintUserStateProto__cached_print_jobs,
    &android__service__print__PrintUserStateProto__discovery_sessions,
    &android__service__print__PrintUserStateProto__print_spooler_state,
    NULL };

Privacy android__service__print__PrintServiceDumpProto__user_states = { 1, 11, android_service_print_PrintUserStateProto__MSG__200, 200, NULL };

Privacy* android_service_print_PrintServiceDumpProto__MSG__200[] = {
    &android__service__print__PrintServiceDumpProto__user_states,
    NULL };

Privacy android__os__IncidentProto__print = { 3010, 11, android_service_print_PrintServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: procstats (3011)
Privacy android__service__procstats__ProcessStatsProto__assocs = { 7, 11, NULL, 255, NULL };

Privacy* android_service_procstats_ProcessStatsProto__MSG__200[] = {
    &android__service__procstats__ProcessStatsProto__assocs,
    NULL };

Privacy android__service__procstats__ProcessStatsSectionProto__process_stats = { 8, 11, android_service_procstats_ProcessStatsProto__MSG__200, 200, NULL };
Privacy android__service__procstats__ProcessStatsPackageProto__process_stats = { 4, 11, android_service_procstats_ProcessStatsProto__MSG__200, 200, NULL };

Privacy* android_service_procstats_ProcessStatsPackageProto__MSG__200[] = {
    &android__service__procstats__ProcessStatsPackageProto__process_stats,
    NULL };

Privacy android__service__procstats__ProcessStatsSectionProto__package_stats = { 9, 11, android_service_procstats_ProcessStatsPackageProto__MSG__200, 200, NULL };

Privacy* android_service_procstats_ProcessStatsSectionProto__MSG__200[] = {
    &android__service__procstats__ProcessStatsSectionProto__process_stats,
    &android__service__procstats__ProcessStatsSectionProto__package_stats,
    NULL };

Privacy android__service__procstats__ProcessStatsServiceDumpProto__procstats_now = { 1, 11, android_service_procstats_ProcessStatsSectionProto__MSG__200, 200, NULL };
Privacy android__service__procstats__ProcessStatsServiceDumpProto__procstats_over_3hrs = { 2, 11, android_service_procstats_ProcessStatsSectionProto__MSG__200, 200, NULL };
Privacy android__service__procstats__ProcessStatsServiceDumpProto__procstats_over_24hrs = { 3, 11, android_service_procstats_ProcessStatsSectionProto__MSG__200, 200, NULL };

Privacy* android_service_procstats_ProcessStatsServiceDumpProto__MSG__200[] = {
    &android__service__procstats__ProcessStatsServiceDumpProto__procstats_now,
    &android__service__procstats__ProcessStatsServiceDumpProto__procstats_over_3hrs,
    &android__service__procstats__ProcessStatsServiceDumpProto__procstats_over_24hrs,
    NULL };

Privacy android__os__IncidentProto__procstats = { 3011, 11, android_service_procstats_ProcessStatsServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: activities (3012)
Privacy android__content__ConfigurationProto__mnc = { 3, 13, NULL, 100, NULL };

Privacy* android_content_ConfigurationProto__MSG__200[] = {
    &android__content__ConfigurationProto__mnc,
    NULL };

Privacy com__android__server__wm__ConfigurationContainerProto__override_configuration = { 1, 11, android_content_ConfigurationProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__ConfigurationContainerProto__full_configuration = { 2, 11, android_content_ConfigurationProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__ConfigurationContainerProto__merged_override_configuration = { 3, 11, android_content_ConfigurationProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_ConfigurationContainerProto__MSG__200[] = {
    &com__android__server__wm__ConfigurationContainerProto__override_configuration,
    &com__android__server__wm__ConfigurationContainerProto__full_configuration,
    &com__android__server__wm__ConfigurationContainerProto__merged_override_configuration,
    NULL };

Privacy com__android__server__wm__WindowContainerProto__configuration_container = { 1, 11, com_android_server_wm_ConfigurationContainerProto__MSG__200, 200, NULL };
Privacy android__view__SurfaceControlProto__name = { 2, 9, NULL, 100, NULL };

Privacy* android_view_SurfaceControlProto__MSG__200[] = {
    &android__view__SurfaceControlProto__name,
    NULL };

Privacy com__android__server__wm__SurfaceAnimatorProto__leash = { 1, 11, android_view_SurfaceControlProto__MSG__200, 200, NULL };
Privacy android__view__RemoteAnimationTargetProto__leash = { 3, 11, android_view_SurfaceControlProto__MSG__200, 200, NULL };
Privacy android__view__RemoteAnimationTargetProto__start_leash = { 11, 11, android_view_SurfaceControlProto__MSG__200, 200, NULL };

Privacy* android_view_RemoteAnimationTargetProto__MSG__200[] = {
    &android__view__RemoteAnimationTargetProto__leash,
    &android__view__RemoteAnimationTargetProto__start_leash,
    NULL };

Privacy com__android__server__wm__RemoteAnimationAdapterWrapperProto__target = { 1, 11, android_view_RemoteAnimationTargetProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_RemoteAnimationAdapterWrapperProto__MSG__200[] = {
    &com__android__server__wm__RemoteAnimationAdapterWrapperProto__target,
    NULL };

Privacy com__android__server__wm__AnimationAdapterProto__remote = { 2, 11, com_android_server_wm_RemoteAnimationAdapterWrapperProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_AnimationAdapterProto__MSG__200[] = {
    &com__android__server__wm__AnimationAdapterProto__remote,
    NULL };

Privacy com__android__server__wm__SurfaceAnimatorProto__animation_adapter = { 3, 11, com_android_server_wm_AnimationAdapterProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_SurfaceAnimatorProto__MSG__200[] = {
    &com__android__server__wm__SurfaceAnimatorProto__leash,
    &com__android__server__wm__SurfaceAnimatorProto__animation_adapter,
    NULL };

Privacy com__android__server__wm__WindowContainerProto__surface_animator = { 4, 11, com_android_server_wm_SurfaceAnimatorProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerChildProto__window_container = { 2, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowContainerProto__MSG__200
Privacy com__android__server__wm__DisplayContentProto__window_container = { 1, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowContainerProto__MSG__200
Privacy com__android__server__wm__WindowTokenProto__window_container = { 1, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowContainerProto__MSG__200
Privacy com__android__server__wm__WindowStateProto__window_container = { 1, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowContainerProto__MSG__200
Privacy com__android__server__wm__IdentifierProto__title = { 3, 9, NULL, 100, NULL };

Privacy* com_android_server_wm_IdentifierProto__MSG__200[] = {
    &com__android__server__wm__IdentifierProto__title,
    NULL };

Privacy com__android__server__wm__WindowStateProto__identifier = { 2, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowStateProto__child_windows = { 15, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowStateProto__MSG__200

Privacy* com_android_server_wm_WindowStateProto__MSG__200[] = {
    &com__android__server__wm__WindowStateProto__window_container,
    &com__android__server__wm__WindowStateProto__identifier,
    &com__android__server__wm__WindowStateProto__child_windows,
    NULL };

Privacy com__android__server__wm__WindowTokenProto__windows = { 3, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_WindowTokenProto__MSG__200[] = {
    &com__android__server__wm__WindowTokenProto__window_container,
    &com__android__server__wm__WindowTokenProto__windows,
    NULL };

Privacy com__android__server__wm__DisplayContentProto__above_app_windows = { 6, 11, com_android_server_wm_WindowTokenProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__below_app_windows = { 7, 11, com_android_server_wm_WindowTokenProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__ime_windows = { 8, 11, com_android_server_wm_WindowTokenProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__opening_apps = { 17, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__closing_apps = { 18, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__changing_apps = { 19, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__overlay_windows = { 20, 11, com_android_server_wm_WindowTokenProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayAreaProto__window_container = { 1, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowContainerProto__MSG__200
Privacy com__android__server__wm__DisplayAreaProto__name = { 2, 9, NULL, 100, NULL };
Privacy com__android__server__wm__DisplayAreaChildProto__display_area = { 1, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_DisplayAreaProto__MSG__200
Privacy com__android__server__wm__DisplayAreaChildProto__window = { 2, 11, com_android_server_wm_WindowTokenProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_DisplayAreaChildProto__MSG__200[] = {
    &com__android__server__wm__DisplayAreaChildProto__display_area,
    &com__android__server__wm__DisplayAreaChildProto__window,
    NULL };

Privacy com__android__server__wm__DisplayAreaProto__children = { 3, 11, com_android_server_wm_DisplayAreaChildProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_DisplayAreaProto__MSG__200[] = {
    &com__android__server__wm__DisplayAreaProto__window_container,
    &com__android__server__wm__DisplayAreaProto__name,
    &com__android__server__wm__DisplayAreaProto__children,
    NULL };

Privacy com__android__server__wm__DisplayContentProto__root_display_area = { 21, 11, com_android_server_wm_DisplayAreaProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__resumed_activity = { 24, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__TaskProto__window_container = { 1, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowContainerProto__MSG__200
Privacy com__android__server__wm__TaskProto__tasks = { 10, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_TaskProto__MSG__200
Privacy com__android__server__wm__ActivityRecordProto__name = { 1, 9, NULL, 100, NULL };
Privacy com__android__server__wm__ActivityRecordProto__window_token = { 2, 11, com_android_server_wm_WindowTokenProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerThumbnailProto__surface_animator = { 3, 11, com_android_server_wm_SurfaceAnimatorProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_WindowContainerThumbnailProto__MSG__200[] = {
    &com__android__server__wm__WindowContainerThumbnailProto__surface_animator,
    NULL };

Privacy com__android__server__wm__ActivityRecordProto__thumbnail = { 6, 11, com_android_server_wm_WindowContainerThumbnailProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__ActivityRecordProto__starting_window = { 19, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__ActivityRecordProto__identifier = { 26, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__ActivityRecordProto__state = { 27, 9, NULL, 100, NULL };

Privacy* com_android_server_wm_ActivityRecordProto__MSG__200[] = {
    &com__android__server__wm__ActivityRecordProto__name,
    &com__android__server__wm__ActivityRecordProto__window_token,
    &com__android__server__wm__ActivityRecordProto__thumbnail,
    &com__android__server__wm__ActivityRecordProto__starting_window,
    &com__android__server__wm__ActivityRecordProto__identifier,
    &com__android__server__wm__ActivityRecordProto__state,
    NULL };

Privacy com__android__server__wm__TaskProto__activities = { 11, 11, com_android_server_wm_ActivityRecordProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__TaskProto__resumed_activity = { 12, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__TaskFragmentProto__window_container = { 1, 11, NULL, 200, NULL }; // self recursion field of com_android_server_wm_WindowContainerProto__MSG__200

Privacy* com_android_server_wm_TaskFragmentProto__MSG__200[] = {
    &com__android__server__wm__TaskFragmentProto__window_container,
    NULL };

Privacy com__android__server__wm__TaskProto__task_fragment = { 31, 11, com_android_server_wm_TaskFragmentProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_TaskProto__MSG__200[] = {
    &com__android__server__wm__TaskProto__window_container,
    &com__android__server__wm__TaskProto__tasks,
    &com__android__server__wm__TaskProto__activities,
    &com__android__server__wm__TaskProto__resumed_activity,
    &com__android__server__wm__TaskProto__task_fragment,
    NULL };

Privacy com__android__server__wm__DisplayContentProto__tasks = { 25, 11, com_android_server_wm_TaskProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__input_method_target = { 27, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__input_method_input_target = { 28, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__input_method_control_target = { 29, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__DisplayContentProto__current_focus = { 30, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy android__view__InsetsSourceProto__frame = { 2, 11, NULL, 200, NULL };
Privacy android__view__InsetsSourceProto__visible_frame = { 3, 11, NULL, 200, NULL };

Privacy* android_view_InsetsSourceProto__MSG__255[] = {
    &android__view__InsetsSourceProto__frame,
    &android__view__InsetsSourceProto__visible_frame,
    NULL };

Privacy com__android__server__wm__InsetsSourceProviderProto__source = { 1, 11, android_view_InsetsSourceProto__MSG__255, 255, NULL };
Privacy android__view__InsetsSourceControlProto__position = { 2, 11, NULL, 200, NULL };
Privacy android__view__InsetsSourceControlProto__leash = { 3, 11, android_view_SurfaceControlProto__MSG__200, 200, NULL };

Privacy* android_view_InsetsSourceControlProto__MSG__255[] = {
    &android__view__InsetsSourceControlProto__position,
    &android__view__InsetsSourceControlProto__leash,
    NULL };

Privacy com__android__server__wm__InsetsSourceProviderProto__fake_control = { 3, 11, android_view_InsetsSourceControlProto__MSG__255, 255, NULL };
Privacy com__android__server__wm__InsetsSourceProviderProto__control = { 4, 11, android_view_InsetsSourceControlProto__MSG__255, 255, NULL };
Privacy com__android__server__wm__InsetsSourceProviderProto__control_target = { 5, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__InsetsSourceProviderProto__pending_control_target = { 6, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__InsetsSourceProviderProto__fake_control_target = { 7, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__InsetsSourceProviderProto__captured_leash = { 8, 11, android_view_SurfaceControlProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_InsetsSourceProviderProto__MSG__200[] = {
    &com__android__server__wm__InsetsSourceProviderProto__source,
    &com__android__server__wm__InsetsSourceProviderProto__fake_control,
    &com__android__server__wm__InsetsSourceProviderProto__control,
    &com__android__server__wm__InsetsSourceProviderProto__control_target,
    &com__android__server__wm__InsetsSourceProviderProto__pending_control_target,
    &com__android__server__wm__InsetsSourceProviderProto__fake_control_target,
    &com__android__server__wm__InsetsSourceProviderProto__captured_leash,
    NULL };

Privacy com__android__server__wm__ImeInsetsSourceProviderProto__insets_source_provider = { 1, 11, com_android_server_wm_InsetsSourceProviderProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__ImeInsetsSourceProviderProto__ime_target_from_ime = { 2, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_ImeInsetsSourceProviderProto__MSG__200[] = {
    &com__android__server__wm__ImeInsetsSourceProviderProto__insets_source_provider,
    &com__android__server__wm__ImeInsetsSourceProviderProto__ime_target_from_ime,
    NULL };

Privacy com__android__server__wm__DisplayContentProto__ime_insets_source_provider = { 31, 11, com_android_server_wm_ImeInsetsSourceProviderProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_DisplayContentProto__MSG__200[] = {
    &com__android__server__wm__DisplayContentProto__window_container,
    &com__android__server__wm__DisplayContentProto__above_app_windows,
    &com__android__server__wm__DisplayContentProto__below_app_windows,
    &com__android__server__wm__DisplayContentProto__ime_windows,
    &com__android__server__wm__DisplayContentProto__opening_apps,
    &com__android__server__wm__DisplayContentProto__closing_apps,
    &com__android__server__wm__DisplayContentProto__changing_apps,
    &com__android__server__wm__DisplayContentProto__overlay_windows,
    &com__android__server__wm__DisplayContentProto__root_display_area,
    &com__android__server__wm__DisplayContentProto__resumed_activity,
    &com__android__server__wm__DisplayContentProto__tasks,
    &com__android__server__wm__DisplayContentProto__input_method_target,
    &com__android__server__wm__DisplayContentProto__input_method_input_target,
    &com__android__server__wm__DisplayContentProto__input_method_control_target,
    &com__android__server__wm__DisplayContentProto__current_focus,
    &com__android__server__wm__DisplayContentProto__ime_insets_source_provider,
    NULL };

Privacy com__android__server__wm__WindowContainerChildProto__display_content = { 3, 11, com_android_server_wm_DisplayContentProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerChildProto__display_area = { 4, 11, com_android_server_wm_DisplayAreaProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerChildProto__task = { 5, 11, com_android_server_wm_TaskProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerChildProto__activity = { 6, 11, com_android_server_wm_ActivityRecordProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerChildProto__window_token = { 7, 11, com_android_server_wm_WindowTokenProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerChildProto__window = { 8, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerChildProto__task_fragment = { 9, 11, com_android_server_wm_TaskFragmentProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_WindowContainerChildProto__MSG__200[] = {
    &com__android__server__wm__WindowContainerChildProto__window_container,
    &com__android__server__wm__WindowContainerChildProto__display_content,
    &com__android__server__wm__WindowContainerChildProto__display_area,
    &com__android__server__wm__WindowContainerChildProto__task,
    &com__android__server__wm__WindowContainerChildProto__activity,
    &com__android__server__wm__WindowContainerChildProto__window_token,
    &com__android__server__wm__WindowContainerChildProto__window,
    &com__android__server__wm__WindowContainerChildProto__task_fragment,
    NULL };

Privacy com__android__server__wm__WindowContainerProto__children = { 5, 11, com_android_server_wm_WindowContainerChildProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerProto__identifier = { 6, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowContainerProto__surface_control = { 7, 11, android_view_SurfaceControlProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_WindowContainerProto__MSG__200[] = {
    &com__android__server__wm__WindowContainerProto__configuration_container,
    &com__android__server__wm__WindowContainerProto__surface_animator,
    &com__android__server__wm__WindowContainerProto__children,
    &com__android__server__wm__WindowContainerProto__identifier,
    &com__android__server__wm__WindowContainerProto__surface_control,
    NULL };

Privacy com__android__server__wm__RootWindowContainerProto__window_container = { 1, 11, com_android_server_wm_WindowContainerProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__RootWindowContainerProto__displays = { 2, 11, com_android_server_wm_DisplayContentProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__RootWindowContainerProto__windows = { 4, 11, com_android_server_wm_WindowStateProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__RootWindowContainerProto__pending_activities = { 7, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_RootWindowContainerProto__MSG__200[] = {
    &com__android__server__wm__RootWindowContainerProto__window_container,
    &com__android__server__wm__RootWindowContainerProto__displays,
    &com__android__server__wm__RootWindowContainerProto__windows,
    &com__android__server__wm__RootWindowContainerProto__pending_activities,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpActivitiesProto__root_window_container = { 2, 11, com_android_server_wm_RootWindowContainerProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpActivitiesProto__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpActivitiesProto__root_window_container,
    NULL };

Privacy android__os__IncidentProto__activities = { 3012, 11, com_android_server_am_ActivityManagerServiceDumpActivitiesProto__MSG__200, 200, NULL };

// Incident Report Section: broadcasts (3013)
Privacy android__content__IntentFilterProto__data_schemes = { 3, 9, NULL, 100, NULL };
Privacy android__content__IntentFilterProto__data_scheme_specs = { 4, 11, NULL, 100, NULL };
Privacy android__content__IntentFilterProto__data_paths = { 6, 11, NULL, 100, NULL };

Privacy* android_content_IntentFilterProto__MSG__200[] = {
    &android__content__IntentFilterProto__data_schemes,
    &android__content__IntentFilterProto__data_scheme_specs,
    &android__content__IntentFilterProto__data_paths,
    NULL };

Privacy com__android__server__am__BroadcastFilterProto__intent_filter = { 1, 11, android_content_IntentFilterProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_BroadcastFilterProto__MSG__200[] = {
    &com__android__server__am__BroadcastFilterProto__intent_filter,
    NULL };

Privacy com__android__server__am__ReceiverListProto__filters = { 7, 11, com_android_server_am_BroadcastFilterProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_ReceiverListProto__MSG__200[] = {
    &com__android__server__am__ReceiverListProto__filters,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__receiver_list = { 1, 11, com_android_server_am_ReceiverListProto__MSG__200, 200, NULL };
Privacy android__content__IntentProto__data = { 3, 9, NULL, 100, NULL };
Privacy android__content__IntentProto__clip_data = { 9, 9, NULL, 0, NULL };
Privacy android__content__IntentProto__extras = { 10, 9, NULL, 0, NULL };
Privacy android__content__IntentProto__identifier = { 13, 9, NULL, 100, NULL };

Privacy* android_content_IntentProto__MSG__200[] = {
    &android__content__IntentProto__data,
    &android__content__IntentProto__clip_data,
    &android__content__IntentProto__extras,
    &android__content__IntentProto__identifier,
    NULL };

Privacy com__android__server__am__BroadcastQueueProto__BroadcastSummary__intent = { 1, 11, android_content_IntentProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_BroadcastQueueProto_BroadcastSummary__MSG__200[] = {
    &com__android__server__am__BroadcastQueueProto__BroadcastSummary__intent,
    NULL };

Privacy com__android__server__am__BroadcastQueueProto__historical_broadcasts_summary = { 6, 11, com_android_server_am_BroadcastQueueProto_BroadcastSummary__MSG__200, 200, NULL };

Privacy* com_android_server_am_BroadcastQueueProto__MSG__200[] = {
    &com__android__server__am__BroadcastQueueProto__historical_broadcasts_summary,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__broadcast_queue = { 3, 11, com_android_server_am_BroadcastQueueProto__MSG__200, 200, NULL };
Privacy com__android__server__am__StickyBroadcastProto__StickyAction__intents = { 2, 11, android_content_IntentProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_StickyBroadcastProto_StickyAction__MSG__200[] = {
    &com__android__server__am__StickyBroadcastProto__StickyAction__intents,
    NULL };

Privacy com__android__server__am__StickyBroadcastProto__actions = { 2, 11, com_android_server_am_StickyBroadcastProto_StickyAction__MSG__200, 200, NULL };

Privacy* com_android_server_am_StickyBroadcastProto__MSG__200[] = {
    &com__android__server__am__StickyBroadcastProto__actions,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__sticky_broadcasts = { 4, 11, com_android_server_am_StickyBroadcastProto__MSG__200, 200, NULL };
Privacy com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__MainHandler__looper = { 2, 11, android_os_LooperProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpBroadcastsProto_MainHandler__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__MainHandler__looper,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__handler = { 5, 11, com_android_server_am_ActivityManagerServiceDumpBroadcastsProto_MainHandler__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpBroadcastsProto__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__receiver_list,
    &com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__broadcast_queue,
    &com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__sticky_broadcasts,
    &com__android__server__am__ActivityManagerServiceDumpBroadcastsProto__handler,
    NULL };

Privacy android__os__IncidentProto__broadcasts = { 3013, 11, com_android_server_am_ActivityManagerServiceDumpBroadcastsProto__MSG__200, 200, NULL };

// Incident Report Section: amservices (3014)
Privacy com__android__server__am__ServiceRecordProto__intent = { 4, 11, android_content_IntentProto__MSG__200, 200, NULL };
Privacy com__android__server__am__ServiceRecordProto__appinfo = { 8, 11, NULL, 100, NULL };
Privacy android__app__NotificationProto__channel_id = { 1, 9, NULL, 100, NULL };
Privacy android__app__NotificationProto__category = { 5, 9, NULL, 100, NULL };
Privacy android__app__NotificationProto__group_key = { 6, 9, NULL, 100, NULL };
Privacy android__app__NotificationProto__sort_key = { 7, 9, NULL, 100, NULL };
Privacy android__app__NotificationProto__public_version = { 10, 11, NULL, 200, NULL }; // self recursion field of android_app_NotificationProto__MSG__200

Privacy* android_app_NotificationProto__MSG__200[] = {
    &android__app__NotificationProto__channel_id,
    &android__app__NotificationProto__category,
    &android__app__NotificationProto__group_key,
    &android__app__NotificationProto__sort_key,
    &android__app__NotificationProto__public_version,
    NULL };

Privacy com__android__server__am__ServiceRecordProto__Foreground__notification = { 2, 11, android_app_NotificationProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_ServiceRecordProto_Foreground__MSG__200[] = {
    &com__android__server__am__ServiceRecordProto__Foreground__notification,
    NULL };

Privacy com__android__server__am__ServiceRecordProto__foreground = { 13, 11, com_android_server_am_ServiceRecordProto_Foreground__MSG__200, 200, NULL };
Privacy com__android__server__am__ServiceRecordProto__StartItem__intent = { 5, 11, android_content_IntentProto__MSG__200, 200, NULL };
Privacy com__android__server__am__GrantUriProto__uri = { 2, 9, NULL, 100, NULL };

Privacy* com_android_server_am_GrantUriProto__MSG__200[] = {
    &com__android__server__am__GrantUriProto__uri,
    NULL };

Privacy com__android__server__am__NeededUriGrantsProto__grants = { 4, 11, com_android_server_am_GrantUriProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_NeededUriGrantsProto__MSG__200[] = {
    &com__android__server__am__NeededUriGrantsProto__grants,
    NULL };

Privacy com__android__server__am__ServiceRecordProto__StartItem__needed_grants = { 6, 11, com_android_server_am_NeededUriGrantsProto__MSG__200, 200, NULL };
Privacy com__android__server__am__UriPermissionOwnerProto__read_perms = { 2, 11, com_android_server_am_GrantUriProto__MSG__200, 200, NULL };
Privacy com__android__server__am__UriPermissionOwnerProto__write_perms = { 3, 11, com_android_server_am_GrantUriProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_UriPermissionOwnerProto__MSG__100[] = {
    &com__android__server__am__UriPermissionOwnerProto__read_perms,
    &com__android__server__am__UriPermissionOwnerProto__write_perms,
    NULL };

Privacy com__android__server__am__ServiceRecordProto__StartItem__uri_permissions = { 7, 11, com_android_server_am_UriPermissionOwnerProto__MSG__100, 100, NULL };

Privacy* com_android_server_am_ServiceRecordProto_StartItem__MSG__200[] = {
    &com__android__server__am__ServiceRecordProto__StartItem__intent,
    &com__android__server__am__ServiceRecordProto__StartItem__needed_grants,
    &com__android__server__am__ServiceRecordProto__StartItem__uri_permissions,
    NULL };

Privacy com__android__server__am__ServiceRecordProto__delivered_starts = { 23, 11, com_android_server_am_ServiceRecordProto_StartItem__MSG__200, 200, NULL };
Privacy com__android__server__am__ServiceRecordProto__pending_starts = { 24, 11, com_android_server_am_ServiceRecordProto_StartItem__MSG__200, 200, NULL };
Privacy com__android__server__am__IntentBindRecordProto__intent = { 1, 11, android_content_IntentProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_IntentBindRecordProto__MSG__200[] = {
    &com__android__server__am__IntentBindRecordProto__intent,
    NULL };

Privacy com__android__server__am__ServiceRecordProto__bindings = { 25, 11, com_android_server_am_IntentBindRecordProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_ServiceRecordProto__MSG__200[] = {
    &com__android__server__am__ServiceRecordProto__intent,
    &com__android__server__am__ServiceRecordProto__appinfo,
    &com__android__server__am__ServiceRecordProto__foreground,
    &com__android__server__am__ServiceRecordProto__delivered_starts,
    &com__android__server__am__ServiceRecordProto__pending_starts,
    &com__android__server__am__ServiceRecordProto__bindings,
    NULL };

Privacy com__android__server__am__ActiveServicesProto__ServicesByUser__service_records = { 2, 11, com_android_server_am_ServiceRecordProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActiveServicesProto_ServicesByUser__MSG__200[] = {
    &com__android__server__am__ActiveServicesProto__ServicesByUser__service_records,
    NULL };

Privacy com__android__server__am__ActiveServicesProto__services_by_users = { 1, 11, com_android_server_am_ActiveServicesProto_ServicesByUser__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActiveServicesProto__MSG__200[] = {
    &com__android__server__am__ActiveServicesProto__services_by_users,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpServicesProto__active_services = { 1, 11, com_android_server_am_ActiveServicesProto__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpServicesProto__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpServicesProto__active_services,
    NULL };

Privacy android__os__IncidentProto__amservices = { 3014, 11, com_android_server_am_ActivityManagerServiceDumpServicesProto__MSG__200, 200, NULL };

// Incident Report Section: amprocesses (3015)
Privacy android__content__pm__ApplicationInfoProto__detail = { 17, 11, NULL, 100, NULL };

Privacy* android_content_pm_ApplicationInfoProto__MSG__200[] = {
    &android__content__pm__ApplicationInfoProto__detail,
    NULL };

Privacy com__android__server__am__ActiveInstrumentationProto__target_info = { 5, 11, android_content_pm_ApplicationInfoProto__MSG__200, 200, NULL };
Privacy android__os__BundleProto__parcelled_data_size = { 1, 5, NULL, 200, NULL };
Privacy android__os__BundleProto__map_data = { 2, 9, NULL, 100, NULL };

Privacy* android_os_BundleProto__MSG__255[] = {
    &android__os__BundleProto__parcelled_data_size,
    &android__os__BundleProto__map_data,
    NULL };

Privacy com__android__server__am__ActiveInstrumentationProto__arguments = { 10, 11, android_os_BundleProto__MSG__255, 255, NULL };

Privacy* com_android_server_am_ActiveInstrumentationProto__MSG__200[] = {
    &com__android__server__am__ActiveInstrumentationProto__target_info,
    &com__android__server__am__ActiveInstrumentationProto__arguments,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__active_instrumentations = { 3, 11, com_android_server_am_ActiveInstrumentationProto__MSG__200, 200, NULL };
Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__important_procs = { 8, 11, NULL, 100, NULL };
Privacy com__android__server__am__AppErrorsProto__BadProcess__Entry__long_msg = { 4, 9, NULL, 100, NULL };
Privacy com__android__server__am__AppErrorsProto__BadProcess__Entry__stack = { 5, 9, NULL, 100, NULL };

Privacy* com_android_server_am_AppErrorsProto_BadProcess_Entry__MSG__200[] = {
    &com__android__server__am__AppErrorsProto__BadProcess__Entry__long_msg,
    &com__android__server__am__AppErrorsProto__BadProcess__Entry__stack,
    NULL };

Privacy com__android__server__am__AppErrorsProto__BadProcess__entries = { 2, 11, com_android_server_am_AppErrorsProto_BadProcess_Entry__MSG__200, 200, NULL };

Privacy* com_android_server_am_AppErrorsProto_BadProcess__MSG__200[] = {
    &com__android__server__am__AppErrorsProto__BadProcess__entries,
    NULL };

Privacy com__android__server__am__AppErrorsProto__bad_processes = { 3, 11, com_android_server_am_AppErrorsProto_BadProcess__MSG__200, 200, NULL };

Privacy* com_android_server_am_AppErrorsProto__MSG__200[] = {
    &com__android__server__am__AppErrorsProto__bad_processes,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__app_errors = { 13, 11, com_android_server_am_AppErrorsProto__MSG__200, 200, NULL };
Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__global_configuration = { 19, 11, android_content_ConfigurationProto__MSG__200, 200, NULL };
Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__SleepStatus__sleep_tokens = { 2, 9, NULL, 100, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpProcessesProto_SleepStatus__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__SleepStatus__sleep_tokens,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__sleep_status = { 27, 11, com_android_server_am_ActivityManagerServiceDumpProcessesProto_SleepStatus__MSG__200, 200, NULL };
Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__MemWatchProcess__Dump__uri = { 6, 9, NULL, 100, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpProcessesProto_MemWatchProcess_Dump__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__MemWatchProcess__Dump__uri,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__MemWatchProcess__dump = { 2, 11, com_android_server_am_ActivityManagerServiceDumpProcessesProto_MemWatchProcess_Dump__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpProcessesProto_MemWatchProcess__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__MemWatchProcess__dump,
    NULL };

Privacy com__android__server__am__ActivityManagerServiceDumpProcessesProto__mem_watch_processes = { 32, 11, com_android_server_am_ActivityManagerServiceDumpProcessesProto_MemWatchProcess__MSG__200, 200, NULL };

Privacy* com_android_server_am_ActivityManagerServiceDumpProcessesProto__MSG__200[] = {
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__active_instrumentations,
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__important_procs,
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__app_errors,
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__global_configuration,
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__sleep_status,
    &com__android__server__am__ActivityManagerServiceDumpProcessesProto__mem_watch_processes,
    NULL };

Privacy android__os__IncidentProto__amprocesses = { 3015, 11, com_android_server_am_ActivityManagerServiceDumpProcessesProto__MSG__200, 200, NULL };

// Incident Report Section: alarm (3016)
Privacy com__android__server__alarm__AlarmProto__tag = { 1, 9, NULL, 100, NULL };
Privacy com__android__server__alarm__AlarmProto__listener = { 10, 9, NULL, 100, NULL };

Privacy* com_android_server_alarm_AlarmProto__MSG__200[] = {
    &com__android__server__alarm__AlarmProto__tag,
    &com__android__server__alarm__AlarmProto__listener,
    NULL };

Privacy com__android__server__alarm__BatchProto__alarms = { 4, 11, com_android_server_alarm_AlarmProto__MSG__200, 200, NULL };

Privacy* com_android_server_alarm_BatchProto__MSG__200[] = {
    &com__android__server__alarm__BatchProto__alarms,
    NULL };

Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__pending_alarm_batches = { 19, 11, com_android_server_alarm_BatchProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__pending_user_blocked_background_alarms = { 20, 11, com_android_server_alarm_AlarmProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__pending_idle_until = { 21, 11, com_android_server_alarm_AlarmProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__pending_while_idle_alarms = { 22, 11, com_android_server_alarm_AlarmProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__next_wake_from_idle = { 23, 11, com_android_server_alarm_AlarmProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__past_due_non_wakeup_alarms = { 24, 11, com_android_server_alarm_AlarmProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__InFlightProto__tag = { 2, 9, NULL, 100, NULL };
Privacy com__android__server__alarm__FilterStatsProto__tag = { 1, 9, NULL, 100, NULL };

Privacy* com_android_server_alarm_FilterStatsProto__MSG__200[] = {
    &com__android__server__alarm__FilterStatsProto__tag,
    NULL };

Privacy com__android__server__alarm__InFlightProto__filter_stats = { 7, 11, com_android_server_alarm_FilterStatsProto__MSG__200, 200, NULL };

Privacy* com_android_server_alarm_InFlightProto__MSG__200[] = {
    &com__android__server__alarm__InFlightProto__tag,
    &com__android__server__alarm__InFlightProto__filter_stats,
    NULL };

Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__outstanding_deliveries = { 34, 11, com_android_server_alarm_InFlightProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__recent_problems = { 37, 11, NULL, 100, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__TopAlarm__filter = { 3, 11, com_android_server_alarm_FilterStatsProto__MSG__200, 200, NULL };

Privacy* com_android_server_alarm_AlarmManagerServiceDumpProto_TopAlarm__MSG__200[] = {
    &com__android__server__alarm__AlarmManagerServiceDumpProto__TopAlarm__filter,
    NULL };

Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__top_alarms = { 38, 11, com_android_server_alarm_AlarmManagerServiceDumpProto_TopAlarm__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__AlarmStat__filters = { 2, 11, com_android_server_alarm_FilterStatsProto__MSG__200, 200, NULL };

Privacy* com_android_server_alarm_AlarmManagerServiceDumpProto_AlarmStat__MSG__200[] = {
    &com__android__server__alarm__AlarmManagerServiceDumpProto__AlarmStat__filters,
    NULL };

Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__alarm_stats = { 39, 11, com_android_server_alarm_AlarmManagerServiceDumpProto_AlarmStat__MSG__200, 200, NULL };
Privacy com__android__server__alarm__IdleDispatchEntryProto__tag = { 3, 9, NULL, 100, NULL };

Privacy* com_android_server_alarm_IdleDispatchEntryProto__MSG__200[] = {
    &com__android__server__alarm__IdleDispatchEntryProto__tag,
    NULL };

Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__allow_while_idle_dispatches = { 40, 11, com_android_server_alarm_IdleDispatchEntryProto__MSG__200, 200, NULL };
Privacy com__android__server__alarm__AlarmManagerServiceDumpProto__pending_alarms = { 42, 11, com_android_server_alarm_AlarmProto__MSG__200, 200, NULL };

Privacy* com_android_server_alarm_AlarmManagerServiceDumpProto__MSG__200[] = {
    &com__android__server__alarm__AlarmManagerServiceDumpProto__pending_alarm_batches,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__pending_user_blocked_background_alarms,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__pending_idle_until,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__pending_while_idle_alarms,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__next_wake_from_idle,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__past_due_non_wakeup_alarms,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__outstanding_deliveries,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__recent_problems,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__top_alarms,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__alarm_stats,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__allow_while_idle_dispatches,
    &com__android__server__alarm__AlarmManagerServiceDumpProto__pending_alarms,
    NULL };

Privacy android__os__IncidentProto__alarm = { 3016, 11, com_android_server_alarm_AlarmManagerServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: window (3017)
Privacy com__android__server__wm__WindowManagerPolicyProto__focused_window = { 9, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowManagerPolicyProto__top_fullscreen_opaque_window = { 10, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowManagerPolicyProto__top_fullscreen_opaque_or_dimming_window = { 11, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_WindowManagerPolicyProto__MSG__200[] = {
    &com__android__server__wm__WindowManagerPolicyProto__focused_window,
    &com__android__server__wm__WindowManagerPolicyProto__top_fullscreen_opaque_window,
    &com__android__server__wm__WindowManagerPolicyProto__top_fullscreen_opaque_or_dimming_window,
    NULL };

Privacy com__android__server__wm__WindowManagerServiceDumpProto__policy = { 1, 11, com_android_server_wm_WindowManagerPolicyProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowManagerServiceDumpProto__root_window_container = { 2, 11, com_android_server_wm_RootWindowContainerProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowManagerServiceDumpProto__focused_window = { 3, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };
Privacy com__android__server__wm__WindowManagerServiceDumpProto__input_method_window = { 5, 11, com_android_server_wm_IdentifierProto__MSG__200, 200, NULL };

Privacy* com_android_server_wm_WindowManagerServiceDumpProto__MSG__200[] = {
    &com__android__server__wm__WindowManagerServiceDumpProto__policy,
    &com__android__server__wm__WindowManagerServiceDumpProto__root_window_container,
    &com__android__server__wm__WindowManagerServiceDumpProto__focused_window,
    &com__android__server__wm__WindowManagerServiceDumpProto__input_method_window,
    NULL };

Privacy android__os__IncidentProto__window = { 3017, 11, com_android_server_wm_WindowManagerServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: meminfo (3018)
Privacy android__os__IncidentProto__meminfo = { 3018, 11, NULL, 200, NULL };

// Incident Report Section: graphicsstats (3019)
Privacy android__os__IncidentProto__graphicsstats = { 3019, 11, NULL, 200, NULL };

// Incident Report Section: jobscheduler (3020)
Privacy com__android__server__job__JobStatusDumpProto__JobInfo__TriggerContentUri__flags = { 1, 5, NULL, 200, NULL };
Privacy com__android__server__job__JobStatusDumpProto__JobInfo__TriggerContentUri__uri = { 2, 9, NULL, 100, NULL };

Privacy* com_android_server_job_JobStatusDumpProto_JobInfo_TriggerContentUri__MSG__255[] = {
    &com__android__server__job__JobStatusDumpProto__JobInfo__TriggerContentUri__flags,
    &com__android__server__job__JobStatusDumpProto__JobInfo__TriggerContentUri__uri,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__JobInfo__trigger_content_uris = { 11, 11, com_android_server_job_JobStatusDumpProto_JobInfo_TriggerContentUri__MSG__255, 255, NULL };
Privacy android__os__PersistableBundleProto__parcelled_data_size = { 1, 5, NULL, 200, NULL };
Privacy android__os__PersistableBundleProto__map_data = { 2, 9, NULL, 100, NULL };

Privacy* android_os_PersistableBundleProto__MSG__255[] = {
    &android__os__PersistableBundleProto__parcelled_data_size,
    &android__os__PersistableBundleProto__map_data,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__JobInfo__extras = { 14, 11, android_os_PersistableBundleProto__MSG__255, 255, NULL };
Privacy com__android__server__job__JobStatusDumpProto__JobInfo__transient_extras = { 15, 11, android_os_BundleProto__MSG__255, 255, NULL };
Privacy android__content__ClipDescriptionProto__label = { 2, 9, NULL, 100, NULL };
Privacy android__content__ClipDescriptionProto__extras = { 3, 11, android_os_PersistableBundleProto__MSG__255, 255, NULL };

Privacy* android_content_ClipDescriptionProto__MSG__200[] = {
    &android__content__ClipDescriptionProto__label,
    &android__content__ClipDescriptionProto__extras,
    NULL };

Privacy android__content__ClipDataProto__description = { 1, 11, android_content_ClipDescriptionProto__MSG__200, 200, NULL };
Privacy android__content__ClipDataProto__icon = { 2, 11, NULL, 200, NULL };
Privacy android__content__ClipDataProto__Item__intent = { 4, 11, android_content_IntentProto__MSG__200, 200, NULL };
Privacy android__content__ClipDataProto__Item__nothing = { 5, 8, NULL, 200, NULL };

Privacy* android_content_ClipDataProto_Item__MSG__0[] = {
    &android__content__ClipDataProto__Item__intent,
    &android__content__ClipDataProto__Item__nothing,
    NULL };

Privacy android__content__ClipDataProto__items = { 3, 11, android_content_ClipDataProto_Item__MSG__0, 0, NULL };

Privacy* android_content_ClipDataProto__MSG__0[] = {
    &android__content__ClipDataProto__description,
    &android__content__ClipDataProto__icon,
    &android__content__ClipDataProto__items,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__JobInfo__clip_data = { 16, 11, android_content_ClipDataProto__MSG__0, 0, NULL };
Privacy com__android__server__job__GrantedUriPermissionsDumpProto__flags = { 1, 5, NULL, 200, NULL };
Privacy com__android__server__job__GrantedUriPermissionsDumpProto__source_user_id = { 2, 5, NULL, 200, NULL };

Privacy* com_android_server_job_GrantedUriPermissionsDumpProto__MSG__100[] = {
    &com__android__server__job__GrantedUriPermissionsDumpProto__flags,
    &com__android__server__job__GrantedUriPermissionsDumpProto__source_user_id,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__JobInfo__granted_uri_permissions = { 17, 11, com_android_server_job_GrantedUriPermissionsDumpProto__MSG__100, 100, NULL };
Privacy android__net__NetworkCapabilitiesProto__network_specifier = { 5, 9, NULL, 100, NULL };

Privacy* android_net_NetworkCapabilitiesProto__MSG__200[] = {
    &android__net__NetworkCapabilitiesProto__network_specifier,
    NULL };

Privacy android__net__NetworkRequestProto__network_capabilities = { 4, 11, android_net_NetworkCapabilitiesProto__MSG__200, 200, NULL };

Privacy* android_net_NetworkRequestProto__MSG__200[] = {
    &android__net__NetworkRequestProto__network_capabilities,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__JobInfo__required_network = { 18, 11, android_net_NetworkRequestProto__MSG__200, 200, NULL };

Privacy* com_android_server_job_JobStatusDumpProto_JobInfo__MSG__200[] = {
    &com__android__server__job__JobStatusDumpProto__JobInfo__trigger_content_uris,
    &com__android__server__job__JobStatusDumpProto__JobInfo__extras,
    &com__android__server__job__JobStatusDumpProto__JobInfo__transient_extras,
    &com__android__server__job__JobStatusDumpProto__JobInfo__clip_data,
    &com__android__server__job__JobStatusDumpProto__JobInfo__granted_uri_permissions,
    &com__android__server__job__JobStatusDumpProto__JobInfo__required_network,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__job_info = { 6, 11, com_android_server_job_JobStatusDumpProto_JobInfo__MSG__200, 200, NULL };
Privacy com__android__server__job__JobStatusDumpProto__changed_authorities = { 12, 9, NULL, 100, NULL };
Privacy com__android__server__job__JobStatusDumpProto__changed_uris = { 13, 9, NULL, 100, NULL };
Privacy android__net__NetworkProto__net_id = { 1, 5, NULL, 200, NULL };

Privacy* android_net_NetworkProto__MSG__255[] = {
    &android__net__NetworkProto__net_id,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__network = { 14, 11, android_net_NetworkProto__MSG__255, 255, NULL };
Privacy com__android__server__job__JobStatusDumpProto__JobWorkItem__intent = { 3, 11, android_content_IntentProto__MSG__200, 200, NULL };
Privacy com__android__server__job__JobStatusDumpProto__JobWorkItem__uri_grants = { 4, 11, com_android_server_job_GrantedUriPermissionsDumpProto__MSG__100, 100, NULL };

Privacy* com_android_server_job_JobStatusDumpProto_JobWorkItem__MSG__200[] = {
    &com__android__server__job__JobStatusDumpProto__JobWorkItem__intent,
    &com__android__server__job__JobStatusDumpProto__JobWorkItem__uri_grants,
    NULL };

Privacy com__android__server__job__JobStatusDumpProto__pending_work = { 15, 11, com_android_server_job_JobStatusDumpProto_JobWorkItem__MSG__200, 200, NULL };
Privacy com__android__server__job__JobStatusDumpProto__executing_work = { 16, 11, com_android_server_job_JobStatusDumpProto_JobWorkItem__MSG__200, 200, NULL };
Privacy com__android__server__job__JobStatusDumpProto__implicit_constraints = { 25, 11, NULL, 255, NULL };

Privacy* com_android_server_job_JobStatusDumpProto__MSG__200[] = {
    &com__android__server__job__JobStatusDumpProto__job_info,
    &com__android__server__job__JobStatusDumpProto__changed_authorities,
    &com__android__server__job__JobStatusDumpProto__changed_uris,
    &com__android__server__job__JobStatusDumpProto__network,
    &com__android__server__job__JobStatusDumpProto__pending_work,
    &com__android__server__job__JobStatusDumpProto__executing_work,
    &com__android__server__job__JobStatusDumpProto__implicit_constraints,
    NULL };

Privacy com__android__server__job__JobSchedulerServiceDumpProto__RegisteredJob__dump = { 2, 11, com_android_server_job_JobStatusDumpProto__MSG__200, 200, NULL };

Privacy* com_android_server_job_JobSchedulerServiceDumpProto_RegisteredJob__MSG__200[] = {
    &com__android__server__job__JobSchedulerServiceDumpProto__RegisteredJob__dump,
    NULL };

Privacy com__android__server__job__JobSchedulerServiceDumpProto__registered_jobs = { 3, 11, com_android_server_job_JobSchedulerServiceDumpProto_RegisteredJob__MSG__200, 200, NULL };
Privacy com__android__server__job__StateControllerProto__ConnectivityController__TrackedJob__required_network = { 3, 11, android_net_NetworkRequestProto__MSG__200, 200, NULL };

Privacy* com_android_server_job_StateControllerProto_ConnectivityController_TrackedJob__MSG__200[] = {
    &com__android__server__job__StateControllerProto__ConnectivityController__TrackedJob__required_network,
    NULL };

Privacy com__android__server__job__StateControllerProto__ConnectivityController__tracked_jobs = { 2, 11, com_android_server_job_StateControllerProto_ConnectivityController_TrackedJob__MSG__200, 200, NULL };
Privacy com__android__server__job__StateControllerProto__ConnectivityController__available_networks = { 4, 11, android_net_NetworkProto__MSG__255, 255, NULL };

Privacy* com_android_server_job_StateControllerProto_ConnectivityController__MSG__200[] = {
    &com__android__server__job__StateControllerProto__ConnectivityController__tracked_jobs,
    &com__android__server__job__StateControllerProto__ConnectivityController__available_networks,
    NULL };

Privacy com__android__server__job__StateControllerProto__connectivity = { 3, 11, com_android_server_job_StateControllerProto_ConnectivityController__MSG__200, 200, NULL };
Privacy com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__uri = { 1, 9, NULL, 100, NULL };
Privacy com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__JobInstance__changed_authorities = { 5, 9, NULL, 100, NULL };
Privacy com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__JobInstance__changed_uris = { 6, 9, NULL, 100, NULL };

Privacy* com_android_server_job_StateControllerProto_ContentObserverController_Observer_TriggerContentData_JobInstance__MSG__200[] = {
    &com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__JobInstance__changed_authorities,
    &com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__JobInstance__changed_uris,
    NULL };

Privacy com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__jobs = { 3, 11, com_android_server_job_StateControllerProto_ContentObserverController_Observer_TriggerContentData_JobInstance__MSG__200, 200, NULL };

Privacy* com_android_server_job_StateControllerProto_ContentObserverController_Observer_TriggerContentData__MSG__200[] = {
    &com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__uri,
    &com__android__server__job__StateControllerProto__ContentObserverController__Observer__TriggerContentData__jobs,
    NULL };

Privacy com__android__server__job__StateControllerProto__ContentObserverController__Observer__triggers = { 2, 11, com_android_server_job_StateControllerProto_ContentObserverController_Observer_TriggerContentData__MSG__200, 200, NULL };

Privacy* com_android_server_job_StateControllerProto_ContentObserverController_Observer__MSG__200[] = {
    &com__android__server__job__StateControllerProto__ContentObserverController__Observer__triggers,
    NULL };

Privacy com__android__server__job__StateControllerProto__ContentObserverController__observers = { 2, 11, com_android_server_job_StateControllerProto_ContentObserverController_Observer__MSG__200, 200, NULL };

Privacy* com_android_server_job_StateControllerProto_ContentObserverController__MSG__200[] = {
    &com__android__server__job__StateControllerProto__ContentObserverController__observers,
    NULL };

Privacy com__android__server__job__StateControllerProto__content_observer = { 4, 11, com_android_server_job_StateControllerProto_ContentObserverController__MSG__200, 200, NULL };

Privacy* com_android_server_job_StateControllerProto__MSG__200[] = {
    &com__android__server__job__StateControllerProto__connectivity,
    &com__android__server__job__StateControllerProto__content_observer,
    NULL };

Privacy com__android__server__job__JobSchedulerServiceDumpProto__controllers = { 4, 11, com_android_server_job_StateControllerProto__MSG__200, 200, NULL };
Privacy com__android__server__job__JobSchedulerServiceDumpProto__PendingJob__dump = { 2, 11, com_android_server_job_JobStatusDumpProto__MSG__200, 200, NULL };

Privacy* com_android_server_job_JobSchedulerServiceDumpProto_PendingJob__MSG__200[] = {
    &com__android__server__job__JobSchedulerServiceDumpProto__PendingJob__dump,
    NULL };

Privacy com__android__server__job__JobSchedulerServiceDumpProto__pending_jobs = { 9, 11, com_android_server_job_JobSchedulerServiceDumpProto_PendingJob__MSG__200, 200, NULL };
Privacy com__android__server__job__JobSchedulerServiceDumpProto__ActiveJob__RunningJob__dump = { 4, 11, com_android_server_job_JobStatusDumpProto__MSG__200, 200, NULL };

Privacy* com_android_server_job_JobSchedulerServiceDumpProto_ActiveJob_RunningJob__MSG__200[] = {
    &com__android__server__job__JobSchedulerServiceDumpProto__ActiveJob__RunningJob__dump,
    NULL };

Privacy com__android__server__job__JobSchedulerServiceDumpProto__ActiveJob__running = { 2, 11, com_android_server_job_JobSchedulerServiceDumpProto_ActiveJob_RunningJob__MSG__200, 200, NULL };

Privacy* com_android_server_job_JobSchedulerServiceDumpProto_ActiveJob__MSG__200[] = {
    &com__android__server__job__JobSchedulerServiceDumpProto__ActiveJob__running,
    NULL };

Privacy com__android__server__job__JobSchedulerServiceDumpProto__active_jobs = { 10, 11, com_android_server_job_JobSchedulerServiceDumpProto_ActiveJob__MSG__200, 200, NULL };
Privacy com__android__server__job__JobSchedulerServiceDumpProto__persist_stats = { 21, 11, NULL, 255, NULL };

Privacy* com_android_server_job_JobSchedulerServiceDumpProto__MSG__200[] = {
    &com__android__server__job__JobSchedulerServiceDumpProto__registered_jobs,
    &com__android__server__job__JobSchedulerServiceDumpProto__controllers,
    &com__android__server__job__JobSchedulerServiceDumpProto__pending_jobs,
    &com__android__server__job__JobSchedulerServiceDumpProto__active_jobs,
    &com__android__server__job__JobSchedulerServiceDumpProto__persist_stats,
    NULL };

Privacy android__os__IncidentProto__jobscheduler = { 3020, 11, com_android_server_job_JobSchedulerServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: usb (3021)
Privacy android__service__usb__UsbAccessoryProto__uri = { 5, 9, NULL, 100, NULL };
Privacy android__service__usb__UsbAccessoryProto__serial = { 6, 9, NULL, 0, NULL };

Privacy* android_service_usb_UsbAccessoryProto__MSG__200[] = {
    &android__service__usb__UsbAccessoryProto__uri,
    &android__service__usb__UsbAccessoryProto__serial,
    NULL };

Privacy android__service__usb__UsbHandlerProto__current_accessory = { 7, 11, android_service_usb_UsbAccessoryProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbHandlerProto__MSG__200[] = {
    &android__service__usb__UsbHandlerProto__current_accessory,
    NULL };

Privacy android__service__usb__UsbDeviceManagerProto__handler = { 1, 11, android_service_usb_UsbHandlerProto__MSG__200, 200, NULL };
Privacy android__service__usb__UsbDebuggingManagerProto__last_key_received = { 2, 9, NULL, 100, NULL };
Privacy android__service__usb__UsbDebuggingManagerProto__user_keys = { 3, 9, NULL, 0, NULL };
Privacy android__service__usb__UsbDebuggingManagerProto__system_keys = { 4, 9, NULL, 0, NULL };

Privacy* android_service_usb_UsbDebuggingManagerProto__MSG__200[] = {
    &android__service__usb__UsbDebuggingManagerProto__last_key_received,
    &android__service__usb__UsbDebuggingManagerProto__user_keys,
    &android__service__usb__UsbDebuggingManagerProto__system_keys,
    NULL };

Privacy android__service__usb__UsbDeviceManagerProto__debugging_manager = { 2, 11, android_service_usb_UsbDebuggingManagerProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbDeviceManagerProto__MSG__200[] = {
    &android__service__usb__UsbDeviceManagerProto__handler,
    &android__service__usb__UsbDeviceManagerProto__debugging_manager,
    NULL };

Privacy android__service__usb__UsbServiceDumpProto__device_manager = { 1, 11, android_service_usb_UsbDeviceManagerProto__MSG__200, 200, NULL };
Privacy android__service__usb__UsbDeviceProto__serial_number = { 10, 9, NULL, 0, NULL };

Privacy* android_service_usb_UsbDeviceProto__MSG__200[] = {
    &android__service__usb__UsbDeviceProto__serial_number,
    NULL };

Privacy android__service__usb__UsbHostManagerProto__devices = { 2, 11, android_service_usb_UsbDeviceProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbHostManagerProto__MSG__200[] = {
    &android__service__usb__UsbHostManagerProto__devices,
    NULL };

Privacy android__service__usb__UsbServiceDumpProto__host_manager = { 2, 11, android_service_usb_UsbHostManagerProto__MSG__200, 200, NULL };
Privacy android__service__usb__UsbDeviceFilterProto__serial_number = { 8, 9, NULL, 100, NULL };

Privacy* android_service_usb_UsbDeviceFilterProto__MSG__200[] = {
    &android__service__usb__UsbDeviceFilterProto__serial_number,
    NULL };

Privacy android__service__usb__UsbDeviceAttachedActivities__filters = { 2, 11, android_service_usb_UsbDeviceFilterProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbDeviceAttachedActivities__MSG__200[] = {
    &android__service__usb__UsbDeviceAttachedActivities__filters,
    NULL };

Privacy android__service__usb__UsbUserSettingsManagerProto__device_attached_activities = { 4, 11, android_service_usb_UsbDeviceAttachedActivities__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbUserSettingsManagerProto__MSG__200[] = {
    &android__service__usb__UsbUserSettingsManagerProto__device_attached_activities,
    NULL };

Privacy android__service__usb__UsbSettingsManagerProto__user_settings = { 1, 11, android_service_usb_UsbUserSettingsManagerProto__MSG__200, 200, NULL };
Privacy android__service__usb__UsbSettingsDevicePreferenceProto__filter = { 1, 11, android_service_usb_UsbDeviceFilterProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbSettingsDevicePreferenceProto__MSG__200[] = {
    &android__service__usb__UsbSettingsDevicePreferenceProto__filter,
    NULL };

Privacy android__service__usb__UsbProfileGroupSettingsManagerProto__device_preferences = { 2, 11, android_service_usb_UsbSettingsDevicePreferenceProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbProfileGroupSettingsManagerProto__MSG__200[] = {
    &android__service__usb__UsbProfileGroupSettingsManagerProto__device_preferences,
    NULL };

Privacy android__service__usb__UsbSettingsManagerProto__profile_group_settings = { 2, 11, android_service_usb_UsbProfileGroupSettingsManagerProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbSettingsManagerProto__MSG__200[] = {
    &android__service__usb__UsbSettingsManagerProto__user_settings,
    &android__service__usb__UsbSettingsManagerProto__profile_group_settings,
    NULL };

Privacy android__service__usb__UsbServiceDumpProto__settings_manager = { 5, 11, android_service_usb_UsbSettingsManagerProto__MSG__200, 200, NULL };
Privacy android__service__usb__UsbDevicePersistentPermissionProto__device_filter = { 1, 11, android_service_usb_UsbDeviceFilterProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbDevicePersistentPermissionProto__MSG__200[] = {
    &android__service__usb__UsbDevicePersistentPermissionProto__device_filter,
    NULL };

Privacy android__service__usb__UsbUserPermissionsManagerProto__device_persistent_permissions = { 4, 11, android_service_usb_UsbDevicePersistentPermissionProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbUserPermissionsManagerProto__MSG__200[] = {
    &android__service__usb__UsbUserPermissionsManagerProto__device_persistent_permissions,
    NULL };

Privacy android__service__usb__UsbPermissionsManagerProto__user_permissions = { 1, 11, android_service_usb_UsbUserPermissionsManagerProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbPermissionsManagerProto__MSG__200[] = {
    &android__service__usb__UsbPermissionsManagerProto__user_permissions,
    NULL };

Privacy android__service__usb__UsbServiceDumpProto__permissions_manager = { 6, 11, android_service_usb_UsbPermissionsManagerProto__MSG__200, 200, NULL };

Privacy* android_service_usb_UsbServiceDumpProto__MSG__200[] = {
    &android__service__usb__UsbServiceDumpProto__device_manager,
    &android__service__usb__UsbServiceDumpProto__host_manager,
    &android__service__usb__UsbServiceDumpProto__settings_manager,
    &android__service__usb__UsbServiceDumpProto__permissions_manager,
    NULL };

Privacy android__os__IncidentProto__usb = { 3021, 11, android_service_usb_UsbServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: battery_history (3022)
Privacy android__os__IncidentProto__battery_history = { 3022, 11, NULL, 200, NULL };

// Incident Report Section: stats_data (3023)
Privacy android__os__IncidentProto__stats_data = { 3023, 11, NULL, 200, NULL };

// Incident Report Section: role (3024)
Privacy android__os__IncidentProto__role = { 3024, 11, NULL, 200, NULL };

// Incident Report Section: restricted_images (3025)
Privacy android__os__IncidentProto__restricted_images = { 3025, 11, NULL, 100, NULL };

// Incident Report Section: system_trace (3026)
Privacy android__os__IncidentProto__system_trace = { 3026, 12, NULL, 200, NULL };

// Incident Report Section: dropbox_data_app_crash (3027)
Privacy android__service__dropbox__DropBoxManagerServiceDumpProto__Entry__time_ms = { 1, 3, NULL, 200, NULL };

Privacy* android_service_dropbox_DropBoxManagerServiceDumpProto_Entry__MSG__255[] = {
    &android__service__dropbox__DropBoxManagerServiceDumpProto__Entry__time_ms,
    NULL };

Privacy android__service__dropbox__DropBoxManagerServiceDumpProto__entries = { 1, 11, android_service_dropbox_DropBoxManagerServiceDumpProto_Entry__MSG__255, 255, NULL };

Privacy* android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100[] = {
    &android__service__dropbox__DropBoxManagerServiceDumpProto__entries,
    NULL };

Privacy android__os__IncidentProto__dropbox_data_app_crash = { 3027, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_data_app_anr (3028)
Privacy android__os__IncidentProto__dropbox_data_app_anr = { 3028, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_data_app_native_crash (3029)
Privacy android__os__IncidentProto__dropbox_data_app_native_crash = { 3029, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_data_app_strictmode (3030)
Privacy android__os__IncidentProto__dropbox_data_app_strictmode = { 3030, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_data_app_wtf (3031)
Privacy android__os__IncidentProto__dropbox_data_app_wtf = { 3031, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_app_crash (3032)
Privacy android__os__IncidentProto__dropbox_system_app_crash = { 3032, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_app_anr (3033)
Privacy android__os__IncidentProto__dropbox_system_app_anr = { 3033, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_app_native_crash (3034)
Privacy android__os__IncidentProto__dropbox_system_app_native_crash = { 3034, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_app_strictmode (3035)
Privacy android__os__IncidentProto__dropbox_system_app_strictmode = { 3035, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_app_wtf (3036)
Privacy android__os__IncidentProto__dropbox_system_app_wtf = { 3036, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_server_crash (3037)
Privacy android__os__IncidentProto__dropbox_system_server_crash = { 3037, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_server_anr (3038)
Privacy android__os__IncidentProto__dropbox_system_server_anr = { 3038, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_server_native_crash (3039)
Privacy android__os__IncidentProto__dropbox_system_server_native_crash = { 3039, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_server_lowmem (3040)
Privacy android__os__IncidentProto__dropbox_system_server_lowmem = { 3040, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_server_strictmode (3041)
Privacy android__os__IncidentProto__dropbox_system_server_strictmode = { 3041, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_server_watchdog (3042)
Privacy android__os__IncidentProto__dropbox_system_server_watchdog = { 3042, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_server_wtf (3043)
Privacy android__os__IncidentProto__dropbox_system_server_wtf = { 3043, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_recovery_log (3044)
Privacy android__os__IncidentProto__dropbox_system_recovery_log = { 3044, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_system_tombstone (3045)
Privacy android__os__IncidentProto__dropbox_system_tombstone = { 3045, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: dropbox_subsystem_restart (3046)
Privacy android__os__IncidentProto__dropbox_subsystem_restart = { 3046, 11, android_service_dropbox_DropBoxManagerServiceDumpProto__MSG__100, 100, NULL };

// Incident Report Section: process_cpu_usage (3047)
Privacy android__os__IncidentProto__process_cpu_usage = { 3047, 11, NULL, 200, NULL };

// Incident Report Section: ip_connectivity_metrics (3049)
// default android__os__IncidentProto__ip_connectivity_metrics: fieldDest=255 incidentDest=255

// Incident Report Section: bluetooth_manager (3050)
Privacy com__android__server__BluetoothManagerServiceDumpProto__address = { 4, 9, NULL, 100, NULL };
Privacy com__android__server__BluetoothManagerServiceDumpProto__name = { 5, 9, NULL, 100, NULL };

Privacy* com_android_server_BluetoothManagerServiceDumpProto__MSG__200[] = {
    &com__android__server__BluetoothManagerServiceDumpProto__address,
    &com__android__server__BluetoothManagerServiceDumpProto__name,
    NULL };

Privacy android__os__IncidentProto__bluetooth_manager = { 3050, 11, com_android_server_BluetoothManagerServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: context_hub (3051)
Privacy android__os__IncidentProto__context_hub = { 3051, 11, NULL, 200, NULL };

// Incident Report Section: nfc_service (3052)
Privacy com__android__nfc__P2pLinkManagerProto__callback_ndef = { 8, 9, NULL, 100, NULL };
Privacy android__nfc__NdefRecordProto__type = { 1, 12, NULL, 100, NULL };
Privacy android__nfc__NdefRecordProto__id = { 2, 12, NULL, 100, NULL };

Privacy* android_nfc_NdefRecordProto__MSG__200[] = {
    &android__nfc__NdefRecordProto__type,
    &android__nfc__NdefRecordProto__id,
    NULL };

Privacy android__nfc__NdefMessageProto__ndef_records = { 1, 11, android_nfc_NdefRecordProto__MSG__200, 200, NULL };

Privacy* android_nfc_NdefMessageProto__MSG__200[] = {
    &android__nfc__NdefMessageProto__ndef_records,
    NULL };

Privacy com__android__nfc__P2pLinkManagerProto__message_to_send = { 9, 11, android_nfc_NdefMessageProto__MSG__200, 200, NULL };
Privacy com__android__nfc__P2pLinkManagerProto__uris_to_send = { 10, 9, NULL, 100, NULL };

Privacy* com_android_nfc_P2pLinkManagerProto__MSG__200[] = {
    &com__android__nfc__P2pLinkManagerProto__callback_ndef,
    &com__android__nfc__P2pLinkManagerProto__message_to_send,
    &com__android__nfc__P2pLinkManagerProto__uris_to_send,
    NULL };

Privacy com__android__nfc__NfcServiceDumpProto__p2p_link_manager = { 16, 11, com_android_nfc_P2pLinkManagerProto__MSG__200, 200, NULL };
Privacy android__nfc__cardemulation__ApduServiceInfoProto__component_name = { 1, 11, NULL, 200, NULL };

Privacy* android_nfc_cardemulation_ApduServiceInfoProto__MSG__100[] = {
    &android__nfc__cardemulation__ApduServiceInfoProto__component_name,
    NULL };

Privacy com__android__nfc__cardemulation__RegisteredServicesCacheProto__apdu_service_infos = { 1, 11, android_nfc_cardemulation_ApduServiceInfoProto__MSG__100, 100, NULL };

Privacy* com_android_nfc_cardemulation_RegisteredServicesCacheProto__MSG__200[] = {
    &com__android__nfc__cardemulation__RegisteredServicesCacheProto__apdu_service_infos,
    NULL };

Privacy com__android__nfc__cardemulation__CardEmulationManagerProto__registered_services_cache = { 1, 11, com_android_nfc_cardemulation_RegisteredServicesCacheProto__MSG__200, 200, NULL };
Privacy android__nfc__cardemulation__NfcFServiceInfoProto__component_name = { 1, 11, NULL, 200, NULL };

Privacy* android_nfc_cardemulation_NfcFServiceInfoProto__MSG__100[] = {
    &android__nfc__cardemulation__NfcFServiceInfoProto__component_name,
    NULL };

Privacy com__android__nfc__cardemulation__RegisteredNfcFServicesCacheProto__nfc_fservice_info = { 1, 11, android_nfc_cardemulation_NfcFServiceInfoProto__MSG__100, 100, NULL };

Privacy* com_android_nfc_cardemulation_RegisteredNfcFServicesCacheProto__MSG__200[] = {
    &com__android__nfc__cardemulation__RegisteredNfcFServicesCacheProto__nfc_fservice_info,
    NULL };

Privacy com__android__nfc__cardemulation__CardEmulationManagerProto__registered_nfc_f_services_cache = { 2, 11, com_android_nfc_cardemulation_RegisteredNfcFServicesCacheProto__MSG__200, 200, NULL };
Privacy com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__key = { 1, 9, NULL, 100, NULL };
Privacy com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__category = { 2, 9, NULL, 100, NULL };
Privacy com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__default_component = { 3, 11, NULL, 200, NULL };
Privacy com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__services = { 4, 11, android_nfc_cardemulation_ApduServiceInfoProto__MSG__100, 100, NULL };

Privacy* com_android_nfc_cardemulation_RegisteredAidCacheProto_AidCacheEntry__MSG__255[] = {
    &com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__key,
    &com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__category,
    &com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__default_component,
    &com__android__nfc__cardemulation__RegisteredAidCacheProto__AidCacheEntry__services,
    NULL };

Privacy com__android__nfc__cardemulation__RegisteredAidCacheProto__aid_cache_entries = { 1, 11, com_android_nfc_cardemulation_RegisteredAidCacheProto_AidCacheEntry__MSG__255, 255, NULL };
Privacy com__android__nfc__cardemulation__AidRoutingManagerProto__Route__aids = { 2, 9, NULL, 100, NULL };

Privacy* com_android_nfc_cardemulation_AidRoutingManagerProto_Route__MSG__200[] = {
    &com__android__nfc__cardemulation__AidRoutingManagerProto__Route__aids,
    NULL };

Privacy com__android__nfc__cardemulation__AidRoutingManagerProto__routes = { 2, 11, com_android_nfc_cardemulation_AidRoutingManagerProto_Route__MSG__200, 200, NULL };

Privacy* com_android_nfc_cardemulation_AidRoutingManagerProto__MSG__200[] = {
    &com__android__nfc__cardemulation__AidRoutingManagerProto__routes,
    NULL };

Privacy com__android__nfc__cardemulation__RegisteredAidCacheProto__routing_manager = { 4, 11, com_android_nfc_cardemulation_AidRoutingManagerProto__MSG__200, 200, NULL };

Privacy* com_android_nfc_cardemulation_RegisteredAidCacheProto__MSG__200[] = {
    &com__android__nfc__cardemulation__RegisteredAidCacheProto__aid_cache_entries,
    &com__android__nfc__cardemulation__RegisteredAidCacheProto__routing_manager,
    NULL };

Privacy com__android__nfc__cardemulation__CardEmulationManagerProto__aid_cache = { 5, 11, com_android_nfc_cardemulation_RegisteredAidCacheProto__MSG__200, 200, NULL };
Privacy com__android__nfc__cardemulation__RegisteredT3tIdentifiersCacheProto__t3t_identifier_cache_entries = { 1, 11, android_nfc_cardemulation_NfcFServiceInfoProto__MSG__100, 100, NULL };
Privacy com__android__nfc__cardemulation__SystemCodeRoutingManagerProto__t3t_identifiers = { 1, 11, NULL, 100, NULL };

Privacy* com_android_nfc_cardemulation_SystemCodeRoutingManagerProto__MSG__200[] = {
    &com__android__nfc__cardemulation__SystemCodeRoutingManagerProto__t3t_identifiers,
    NULL };

Privacy com__android__nfc__cardemulation__RegisteredT3tIdentifiersCacheProto__routing_manager = { 2, 11, com_android_nfc_cardemulation_SystemCodeRoutingManagerProto__MSG__200, 200, NULL };

Privacy* com_android_nfc_cardemulation_RegisteredT3tIdentifiersCacheProto__MSG__200[] = {
    &com__android__nfc__cardemulation__RegisteredT3tIdentifiersCacheProto__t3t_identifier_cache_entries,
    &com__android__nfc__cardemulation__RegisteredT3tIdentifiersCacheProto__routing_manager,
    NULL };

Privacy com__android__nfc__cardemulation__CardEmulationManagerProto__t3t_identifiers_cache = { 6, 11, com_android_nfc_cardemulation_RegisteredT3tIdentifiersCacheProto__MSG__200, 200, NULL };

Privacy* com_android_nfc_cardemulation_CardEmulationManagerProto__MSG__200[] = {
    &com__android__nfc__cardemulation__CardEmulationManagerProto__registered_services_cache,
    &com__android__nfc__cardemulation__CardEmulationManagerProto__registered_nfc_f_services_cache,
    &com__android__nfc__cardemulation__CardEmulationManagerProto__aid_cache,
    &com__android__nfc__cardemulation__CardEmulationManagerProto__t3t_identifiers_cache,
    NULL };

Privacy com__android__nfc__NfcServiceDumpProto__card_emulation_manager = { 17, 11, com_android_nfc_cardemulation_CardEmulationManagerProto__MSG__200, 200, NULL };
Privacy com__android__nfc__NfcDispatcherProto__override_filters = { 5, 11, android_content_IntentFilterProto__MSG__200, 200, NULL };

Privacy* com_android_nfc_NfcDispatcherProto__MSG__200[] = {
    &com__android__nfc__NfcDispatcherProto__override_filters,
    NULL };

Privacy com__android__nfc__NfcServiceDumpProto__nfc_dispatcher = { 18, 11, com_android_nfc_NfcDispatcherProto__MSG__200, 200, NULL };
Privacy com__android__nfc__NfcServiceDumpProto__native_crash_logs = { 19, 9, NULL, 100, NULL };

Privacy* com_android_nfc_NfcServiceDumpProto__MSG__200[] = {
    &com__android__nfc__NfcServiceDumpProto__p2p_link_manager,
    &com__android__nfc__NfcServiceDumpProto__card_emulation_manager,
    &com__android__nfc__NfcServiceDumpProto__nfc_dispatcher,
    &com__android__nfc__NfcServiceDumpProto__native_crash_logs,
    NULL };

Privacy android__os__IncidentProto__nfc_service = { 3052, 11, com_android_nfc_NfcServiceDumpProto__MSG__200, 200, NULL };

// Incident Report Section: sensor_service (3053)
Privacy android__service__SensorEventsProto__RecentEventsLog__name = { 1, 9, NULL, 100, NULL };

Privacy* android_service_SensorEventsProto_RecentEventsLog__MSG__200[] = {
    &android__service__SensorEventsProto__RecentEventsLog__name,
    NULL };

Privacy android__service__SensorEventsProto__recent_events_logs = { 1, 11, android_service_SensorEventsProto_RecentEventsLog__MSG__200, 200, NULL };

Privacy* android_service_SensorEventsProto__MSG__200[] = {
    &android__service__SensorEventsProto__recent_events_logs,
    NULL };

Privacy android__service__SensorServiceProto__sensor_events = { 5, 11, android_service_SensorEventsProto__MSG__200, 200, NULL };

Privacy* android_service_SensorServiceProto__MSG__200[] = {
    &android__service__SensorServiceProto__sensor_events,
    NULL };

Privacy android__os__IncidentProto__sensor_service = { 3053, 11, android_service_SensorServiceProto__MSG__200, 200, NULL };

// Incident Report Section: powerstats_meter (3054)
// default android__os__IncidentProto__powerstats_meter: fieldDest=255 incidentDest=255

// Incident Report Section: powerstats_model (3055)
// default android__os__IncidentProto__powerstats_model: fieldDest=255 incidentDest=255

// Incident Report Section: powerstats_residency (3056)
// default android__os__IncidentProto__powerstats_residency: fieldDest=255 incidentDest=255

// Incident Report Section: textdump_wifi (4000)
Privacy android__os__IncidentProto__textdump_wifi = { 4000, 11, NULL, 100, NULL };

// Incident Report Section: textdump_bluetooth (4001)
Privacy android__os__IncidentProto__textdump_bluetooth = { 4001, 11, NULL, 100, NULL };

static const Privacy** createList() {
    com__android__server__wm__WindowContainerChildProto__window_container.children = com_android_server_wm_WindowContainerProto__MSG__200;
    com__android__server__wm__DisplayContentProto__window_container.children = com_android_server_wm_WindowContainerProto__MSG__200;
    com__android__server__wm__WindowTokenProto__window_container.children = com_android_server_wm_WindowContainerProto__MSG__200;
    com__android__server__wm__WindowStateProto__window_container.children = com_android_server_wm_WindowContainerProto__MSG__200;
    com__android__server__wm__WindowStateProto__child_windows.children = com_android_server_wm_WindowStateProto__MSG__200;
    com__android__server__wm__DisplayAreaProto__window_container.children = com_android_server_wm_WindowContainerProto__MSG__200;
    com__android__server__wm__DisplayAreaChildProto__display_area.children = com_android_server_wm_DisplayAreaProto__MSG__200;
    com__android__server__wm__TaskProto__window_container.children = com_android_server_wm_WindowContainerProto__MSG__200;
    com__android__server__wm__TaskProto__tasks.children = com_android_server_wm_TaskProto__MSG__200;
    com__android__server__wm__TaskFragmentProto__window_container.children = com_android_server_wm_WindowContainerProto__MSG__200;
    android__app__NotificationProto__public_version.children = android_app_NotificationProto__MSG__200;
    Privacy** privacyArray = (Privacy**)malloc(83 * sizeof(Privacy**));
    privacyArray[0] = &android__os__IncidentProto__system_properties;
    privacyArray[1] = &android__os__IncidentProto__kernel_version;
    privacyArray[2] = &android__os__IncidentProto__event_log_tag_map;
    privacyArray[3] = &android__os__IncidentProto__main_logs;
    privacyArray[4] = &android__os__IncidentProto__radio_logs;
    privacyArray[5] = &android__os__IncidentProto__events_logs;
    privacyArray[6] = &android__os__IncidentProto__system_logs;
    privacyArray[7] = &android__os__IncidentProto__crash_logs;
    privacyArray[8] = &android__os__IncidentProto__stats_logs;
    privacyArray[9] = &android__os__IncidentProto__security_logs;
    privacyArray[10] = &android__os__IncidentProto__kernel_logs;
    privacyArray[11] = &android__os__IncidentProto__last_main_logs;
    privacyArray[12] = &android__os__IncidentProto__last_radio_logs;
    privacyArray[13] = &android__os__IncidentProto__last_events_logs;
    privacyArray[14] = &android__os__IncidentProto__last_system_logs;
    privacyArray[15] = &android__os__IncidentProto__last_crash_logs;
    privacyArray[16] = &android__os__IncidentProto__last_stats_logs;
    privacyArray[17] = &android__os__IncidentProto__last_security_logs;
    privacyArray[18] = &android__os__IncidentProto__persisted_logs;
    privacyArray[19] = &android__os__IncidentProto__native_traces;
    privacyArray[20] = &android__os__IncidentProto__hal_traces;
    privacyArray[21] = &android__os__IncidentProto__java_traces;
    privacyArray[22] = &android__os__IncidentProto__procrank;
    privacyArray[23] = &android__os__IncidentProto__page_type_info;
    privacyArray[24] = &android__os__IncidentProto__kernel_wake_sources;
    privacyArray[25] = &android__os__IncidentProto__cpu_info;
    privacyArray[26] = &android__os__IncidentProto__cpu_freq;
    privacyArray[27] = &android__os__IncidentProto__processes_and_threads;
    privacyArray[28] = &android__os__IncidentProto__battery_type;
    privacyArray[29] = &android__os__IncidentProto__last_kmsg;
    privacyArray[30] = &android__os__IncidentProto__fingerprint;
    privacyArray[31] = &android__os__IncidentProto__netstats;
    privacyArray[32] = &android__os__IncidentProto__settings;
    privacyArray[33] = &android__os__IncidentProto__notification;
    privacyArray[34] = &android__os__IncidentProto__batterystats;
    privacyArray[35] = &android__os__IncidentProto__battery;
    privacyArray[36] = &android__os__IncidentProto__diskstats;
    privacyArray[37] = &android__os__IncidentProto__package;
    privacyArray[38] = &android__os__IncidentProto__power;
    privacyArray[39] = &android__os__IncidentProto__print;
    privacyArray[40] = &android__os__IncidentProto__procstats;
    privacyArray[41] = &android__os__IncidentProto__activities;
    privacyArray[42] = &android__os__IncidentProto__broadcasts;
    privacyArray[43] = &android__os__IncidentProto__amservices;
    privacyArray[44] = &android__os__IncidentProto__amprocesses;
    privacyArray[45] = &android__os__IncidentProto__alarm;
    privacyArray[46] = &android__os__IncidentProto__window;
    privacyArray[47] = &android__os__IncidentProto__meminfo;
    privacyArray[48] = &android__os__IncidentProto__graphicsstats;
    privacyArray[49] = &android__os__IncidentProto__jobscheduler;
    privacyArray[50] = &android__os__IncidentProto__usb;
    privacyArray[51] = &android__os__IncidentProto__battery_history;
    privacyArray[52] = &android__os__IncidentProto__stats_data;
    privacyArray[53] = &android__os__IncidentProto__role;
    privacyArray[54] = &android__os__IncidentProto__restricted_images;
    privacyArray[55] = &android__os__IncidentProto__system_trace;
    privacyArray[56] = &android__os__IncidentProto__dropbox_data_app_crash;
    privacyArray[57] = &android__os__IncidentProto__dropbox_data_app_anr;
    privacyArray[58] = &android__os__IncidentProto__dropbox_data_app_native_crash;
    privacyArray[59] = &android__os__IncidentProto__dropbox_data_app_strictmode;
    privacyArray[60] = &android__os__IncidentProto__dropbox_data_app_wtf;
    privacyArray[61] = &android__os__IncidentProto__dropbox_system_app_crash;
    privacyArray[62] = &android__os__IncidentProto__dropbox_system_app_anr;
    privacyArray[63] = &android__os__IncidentProto__dropbox_system_app_native_crash;
    privacyArray[64] = &android__os__IncidentProto__dropbox_system_app_strictmode;
    privacyArray[65] = &android__os__IncidentProto__dropbox_system_app_wtf;
    privacyArray[66] = &android__os__IncidentProto__dropbox_system_server_crash;
    privacyArray[67] = &android__os__IncidentProto__dropbox_system_server_anr;
    privacyArray[68] = &android__os__IncidentProto__dropbox_system_server_native_crash;
    privacyArray[69] = &android__os__IncidentProto__dropbox_system_server_lowmem;
    privacyArray[70] = &android__os__IncidentProto__dropbox_system_server_strictmode;
    privacyArray[71] = &android__os__IncidentProto__dropbox_system_server_watchdog;
    privacyArray[72] = &android__os__IncidentProto__dropbox_system_server_wtf;
    privacyArray[73] = &android__os__IncidentProto__dropbox_system_recovery_log;
    privacyArray[74] = &android__os__IncidentProto__dropbox_system_tombstone;
    privacyArray[75] = &android__os__IncidentProto__dropbox_subsystem_restart;
    privacyArray[76] = &android__os__IncidentProto__process_cpu_usage;
    privacyArray[77] = &android__os__IncidentProto__bluetooth_manager;
    privacyArray[78] = &android__os__IncidentProto__context_hub;
    privacyArray[79] = &android__os__IncidentProto__nfc_service;
    privacyArray[80] = &android__os__IncidentProto__sensor_service;
    privacyArray[81] = &android__os__IncidentProto__textdump_wifi;
    privacyArray[82] = &android__os__IncidentProto__textdump_bluetooth;
    return const_cast<const Privacy**>(privacyArray);
}

const Privacy** PRIVACY_POLICY_LIST = createList();

const int PRIVACY_POLICY_COUNT = 83;
}  // incidentd
}  // os
}  // android

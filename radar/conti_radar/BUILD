load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])


filegroup(
    name = "runtime_data",
    srcs = glob([
        "conf/*.txt",
        "conf/*.conf",
        "dag/*.dag",
        "launch/*.launch",
    ]),
)

cc_library(
    name = "conti_radar_message_manager",
    srcs = ["conti_radar_message_manager.cc"],
    hdrs = ["conti_radar_message_manager.h"],
    deps = [
        "//common/util:message_util",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/can_comm:can_sender",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "//common_msgs/drivers/radar/conti_radar/protocol:drivers_conti_radar_protocol",
    ],
)

cc_library(
    name = "conti_radar_canbus_lib",
    srcs = ["conti_radar_canbus_component.cc"],
    hdrs = ["conti_radar_canbus_component.h"],
    copts = ['-DMODULE_NAME=\\"conti_radar\\"'],
    deps = [
        ":conti_radar_message_manager",
        "//core/cyber",
        "//common/adapters:adapter_gflags",
        "//common/monitor_log",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/can_comm:can_receiver",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "//common_msgs/drivers/canbus/proto:sensor_canbus_conf_cc_proto",
        "//common_msgs/drivers/radar/conti_radar/protocol:drivers_conti_radar_protocol",
        "//common_msgs/localization/proto:localization_cc_proto",
        "//common_msgs/localization/proto:pose_cc_proto",
        "@eigen",
    ],
)

cc_binary(
    name = "libconti_radar.so",
    linkshared = True,
    linkstatic = False,
    deps = [":conti_radar_canbus_lib"],
)



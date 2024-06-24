load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])

GNSS_COPTS = ['-DMODULE_NAME=\\"gnss\\"']

cc_binary(
    name = "libgnss_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":gnss_component_lib"],
)

cc_library(
    name = "gnss_component_lib",
    srcs = ["gnss_component.cc"],
    hdrs = ["gnss_component.h"],
    copts = GNSS_COPTS,
    deps = [
        "//core/cyber",
        "//common_msgs/canbus/proto:chassis_cc_proto",
        "//common_msgs/common/configs/proto:vehicle_config_cc_proto",
        "//common/monitor_log",
        "//common_msgs/common/proto:drive_state_cc_proto",
        "//common_msgs/common/proto:vehicle_signal_cc_proto",
        "//common_msgs/drivers/gnss/proto:gnss_status_cc_proto",
        "//common_msgs/drivers/gnss/proto:ins_cc_proto",
        "//common_msgs/drivers/gnss/stream:gnss_stream",
    ],
)


filegroup(
    name = "runtime_data",
    srcs = glob([
        "conf/*.txt",
        "dag/*.dag",
        "launch/*.launch",
    ]),
)



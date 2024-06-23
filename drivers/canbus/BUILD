load("@rules_cc//cc:defs.bzl", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sensor_gflags",
    srcs = ["sensor_gflags.cc"],
    hdrs = ["sensor_gflags.h"],
    deps = [
        "@com_github_gflags_gflags//:gflags",
    ],
)

cc_library(
    name = "sensor_canbus_lib",
    hdrs = ["sensor_canbus.h"],
    deps = [
        ":sensor_gflags",
        "//common_msgs/common/monitor_log",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/can_comm:can_receiver",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
    ],
)



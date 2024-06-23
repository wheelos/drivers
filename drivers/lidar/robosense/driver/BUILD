
load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

ROBOSENSE_COPTS = ['-DMODULE_NAME=\\"robosense\\"']

cc_library(
    name = "robosense_driver_component_lib",
    srcs = [
        "robosense_driver_component.cc",
    ],
    hdrs = [
        "robosense_driver_component.h",
    ],
    copts = ROBOSENSE_COPTS,
    deps = [
        ":driver",
        "//core/cyber",
    ],
)

cc_library(
    name = "driver",
    srcs = [
        "driver.cpp",
        "utility.cpp",
    ],
    hdrs = [
        "driver.h",
        "utility.h",
    ],
    copts = ROBOSENSE_COPTS,
    deps = [
        "//core/cyber",
        "//common_msgs/common/util",
        "//common_msgs/drivers/lidar/common/driver_factory:driver_base",
        "//common_msgs/drivers/lidar/proto:config_proto",
        "//common_msgs/drivers/lidar/proto:robosense_proto",
        "//common_msgs/drivers/lidar/robosense:decoder_factory",
        "//common_msgs/drivers/lidar/robosense/input",
        "//common_msgs/drivers/proto:pointcloud_cc_proto",
    ],
)



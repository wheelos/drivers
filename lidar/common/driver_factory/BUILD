load("@rules_cc//cc:defs.bzl", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "lidar_driver_factory",
    srcs = ["lidar_driver_factory.cc"],
    hdrs = ["lidar_driver_factory.h"],
    deps = [
        ":driver_base",
        "//core/cyber",
        "//common/util:factory",
        "//common_msgs/drivers/lidar/hesai/driver",
        "//common_msgs/drivers/lidar/proto:config",
        "//common_msgs/drivers/lidar/proto:lidar_parameter",
        "//common_msgs/drivers/lidar/robosense/driver",
        "//common_msgs/drivers/lidar/velodyne/driver",
    ],
)

cc_library(
    name = "driver_base",
    hdrs = ["driver_base.h"],
    deps = [
        "//common/util",
        "//common/util:factory",
    ],
)



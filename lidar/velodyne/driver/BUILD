load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "libvelodyne_driver_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":velodyne_driver_component_lib"],
)

cc_library(
    name = "velodyne_driver_component_lib",
    srcs = ["velodyne_driver_component.cc"],
    hdrs = ["velodyne_driver_component.h"],
    copts = ['-DMODULE_NAME=\\"velodyne\\"'],
    deps = [
        "//core/cyber",
        "//mimas/util:message_util",
        "//common_msgs/drivers/lidar/velodyne/driver",
    ],
)

cc_library(
    name = "driver",
    srcs = [
        "driver.cc",
        "driver64.cc",
        "input.cc",
        "socket_input.cc",
    ],
    hdrs = [
        "driver.h",
        "input.h",
        "socket_input.h",
    ],
    copts = ['-DMODULE_NAME=\\"velodyne\\"'],
    deps = [
        "//core/cyber",
        "//mimas/util:message_util",
        "//drivers/lidar/common/driver_factory:driver_base",
        "//common_msgs/drivers/lidar/proto:config",
        "//common_msgs/drivers/lidar/proto:velodyne_config_cc_proto",
    ],
)



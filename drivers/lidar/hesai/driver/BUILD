load("@rules_cc//cc:defs.bzl", "cc_library")


package(default_visibility = ["//visibility:public"])

HESAI_COPTS = ['-DMODULE_NAME=\\"hesai\\"']

cc_library(
    name = "hesai_component",
    srcs = ["hesai_component.cc"],
    hdrs = ["hesai_component.h"],
    copts = HESAI_COPTS,
    deps = [
        ":driver",
        "//core/cyber",
        "//common_msgs/drivers/lidar/hesai:parser_factory",
        "//common_msgs/drivers/lidar/proto:hesai_config_cc_proto",
    ],
)

cc_library(
    name = "driver",
    srcs = ["driver.cc"],
    hdrs = ["driver.h"],
    copts = HESAI_COPTS,
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/lidar/common/driver_factory:driver_base",
        "//common_msgs/drivers/lidar/hesai:parser",
        "//common_msgs/drivers/lidar/hesai:parser_factory",
        "//common_msgs/drivers/lidar/hesai:type_defs",
        "//common_msgs/drivers/lidar/hesai:udp_input",
        "//common_msgs/drivers/lidar/proto:config_proto",
    ],
)



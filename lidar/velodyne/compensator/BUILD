load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "libvelodyne_compensator_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":compensator_component_lib"],
)

cc_library(
    name = "compensator_component_lib",
    srcs = ["compensator_component.cc"],
    hdrs = ["compensator_component.h"],
    copts = ['-DMODULE_NAME=\\"velodyne\\"'],
    deps = [
        "//core/cyber",
        "//common/adapters:adapter_gflags",
        "//common/latency_recorder",
        "//common_msgs/drivers/lidar/proto:velodyne_cc_proto",
        "//common_msgs/drivers/lidar/velodyne/compensator:compensator_lib",
    ],
)

cc_library(
    name = "compensator_lib",
    srcs = ["compensator.cc"],
    hdrs = ["compensator.h"],
    copts = ['-DMODULE_NAME=\\"velodyne\\"'],
    deps = [
        "//common_msgs/drivers/lidar/proto:velodyne_config_cc_proto",
        "//common_msgs/drivers/proto:pointcloud_cc_proto",
        "//common_msgs/transform:buffer",
        "@eigen",
    ],
)



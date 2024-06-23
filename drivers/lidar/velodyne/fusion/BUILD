load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "libvelodyne_fusion_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":fusion_component_lib"],
)

cc_library(
    name = "fusion_component_lib",
    srcs = ["pri_sec_fusion_component.cc"],
    hdrs = ["pri_sec_fusion_component.h"],
    copts = ['-DMODULE_NAME=\\"velodyne\\"'],
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/lidar/proto:velodyne_config_cc_proto",
        "//common_msgs/drivers/proto:pointcloud_cc_proto",
        "//common_msgs/transform:buffer",
        "@eigen",
    ],
)



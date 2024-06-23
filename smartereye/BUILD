load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])

CAMERA_COPTS = ['-DMODULE_NAME=\\"camera\\"']


filegroup(
    name = "runtime_data",
    srcs = glob([
        "conf/*.txt",
        "dag/*.dag",
        "launch/*.launch",
    ]),
)

cc_binary(
    name = "libsmartereye_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [
        ":compress_component_lib",
        ":smartereye_component_lib",
    ],
)

cc_library(
    name = "smartereye_component_lib",
    srcs = ["smartereye_component.cc"],
    hdrs = ["smartereye_component.h"],
    copts = CAMERA_COPTS,
    deps = [
        ":smartereye_device",
        ":smartereye_handler",
        "//core/cyber",
        "//common_msgs/common/adapters:adapter_gflags",
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/common/proto:header_cc_proto",
        "//common_msgs/drivers/proto:sensor_image_cc_proto",
        "//common_msgs/drivers/proto:smartereye_cc_proto",
        "//third_party/camera_library/smartereye",
    ],
)

cc_library(
    name = "smartereye_device",
    srcs = ["smartereye_device.cc"],
    hdrs = ["smartereye_device.h"],
    copts = CAMERA_COPTS,
    deps = [
        ":smartereye_handler",
        "//core/cyber",
        "//common_msgs/drivers/smartereye/proto:config_cc_proto",
        "//third_party/camera_library/smartereye",
    ],
)

cc_library(
    name = "smartereye_handler",
    srcs = ["smartereye_handler.cc"],
    hdrs = ["smartereye_handler.h"],
    copts = CAMERA_COPTS,
    deps = [
        "//core/cyber",
        "//third_party/camera_library/smartereye",
    ],
)

cc_library(
    name = "compress_component_lib",
    srcs = ["compress_component.cc"],
    hdrs = ["compress_component.h"],
    copts = CAMERA_COPTS,
    deps = [
        "//core/cyber",
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/common/proto:header_cc_proto",
        "//common_msgs/drivers/proto:sensor_image_cc_proto",
        "//common_msgs/drivers/proto:smartereye_cc_proto",
        "//common_msgs/drivers/smartereye/proto:config_cc_proto",
        "@opencv//:highgui",
    ],
)



load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])


filegroup(
    name = "runtime_files",
    srcs = glob([
        "conf/*.txt",
        "dag/*.dag",
        "launch/*.launch",
    ])
)

cc_binary(
    name = "libvideo_driver_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":video_driver_component_lib"],
)

cc_library(
    name = "video_driver_component_lib",
    srcs = ["video_driver_component.cc"],
    hdrs = ["video_driver_component.h"],
    copts = ['-DMODULE_NAME=\\"video\\"'],
    deps = [
        "//core/cyber",
        "//common/util:message_util",
        "//common_msgs/drivers/video:driver",
        "//common_msgs/drivers/video:socket",
    ],
)

cc_library(
    name = "driver",
    srcs = ["driver.cc"],
    hdrs = [
        "driver.h",
        "socket_input.h",
    ],
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/proto:sensor_image_cc_proto",
        "//common_msgs/drivers/video/proto:video_h265cfg_cc_proto",
    ],
)

cc_library(
    name = "socket",
    srcs = ["socket_input.cc"],
    hdrs = [
        "input.h",
        "socket_input.h",
    ],
    deps = [
        "//core/cyber",
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/common/proto:header_cc_proto",
        "//common/util",
        "//common_msgs/drivers/proto:sensor_image_cc_proto",
    ],
)



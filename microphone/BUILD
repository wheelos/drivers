load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])

MICROPHONE_COPTS = ['-DMODULE_NAME=\\"microphone\\"']

cc_binary(
    name = "libmicrophone_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [
        ":microphone_component_lib",
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

cc_library(
    name = "microphone_component_lib",
    srcs = ["microphone_component.cc"],
    hdrs = ["microphone_component.h"],
    copts = MICROPHONE_COPTS,
    deps = [
        "//core/cyber",
        "//mimas/util:message_util",
        "//common_msgs/drivers/microphone:respeaker",
        "//common_msgs/drivers/microphone/proto:audio_cc_proto",
        "//common_msgs/drivers/microphone/proto:microphone_config_cc_proto",
    ],
)

cc_library(
    name = "respeaker",
    srcs = ["respeaker.cc"],
    hdrs = ["respeaker.h"],
    copts = MICROPHONE_COPTS,
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/microphone/proto:microphone_config_cc_proto",
        "@portaudio",
    ],
)



load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "socket_can_client_raw",
    srcs = ["socket_can_client_raw.cc"],
    hdrs = ["socket_can_client_raw.h"],
    deps = [
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/drivers/canbus/can_client",
    ],
)

cc_test(
    name = "socket_can_client_raw_test",
    size = "small",
    srcs = ["socket_can_client_raw_test.cc"],
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/canbus/can_client/socket:socket_can_client_raw",
        "//common_msgs/drivers/canbus/common:canbus_common",
        "@com_google_googletest//:gtest_main",
    ],
)



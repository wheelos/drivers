load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "esd_can_client",
    srcs = ["esd_can_client.cc"],
    hdrs = ["esd_can_client.h"],
    deps = [
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/drivers/canbus:sensor_gflags",
        "//common_msgs/drivers/canbus/can_client",
        "//third_party/can_card_library/esd_can",
    ],
)

cc_test(
    name = "esd_can_client_test",
    size = "small",
    srcs = ["esd_can_client_test.cc"],
    deps = [
        ":esd_can_client",
        "//core/cyber",
        "//common_msgs/drivers/canbus/common:canbus_common",
        "@com_google_googletest//:gtest_main",
    ],
)



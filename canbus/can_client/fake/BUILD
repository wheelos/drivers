load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "fake_can_client",
    srcs = ["fake_can_client.cc"],
    hdrs = ["fake_can_client.h"],
    deps = [
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/drivers/canbus/can_client",
    ],
)

cc_test(
    name = "fake_can_client_test",
    size = "small",
    srcs = ["fake_can_client_test.cc"],
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/canbus/can_client/fake:fake_can_client",
        "//common_msgs/drivers/canbus/common:canbus_common",
        "@com_google_googletest//:gtest_main",
    ],
)



load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "can_client_factory",
    srcs = ["can_client_factory.cc"],
    hdrs = ["can_client_factory.h"],
    copts = select({
        "//:use_esd_can": ["-DUSE_ESD_CAN=1"],
        "//conditions:default": ["-DUSE_ESD_CAN=0"],
    }),
    deps = [
        "//core/cyber",
        "//mimas/util:factory",
        "//common_msgs/drivers/canbus/can_client",
        "//common_msgs/drivers/canbus/can_client/fake:fake_can_client",
        "//common_msgs/drivers/canbus/can_client/hermes_can:hermes_can_client",
        "//common_msgs/drivers/canbus/can_client/socket:socket_can_client_raw",
        "//drivers/canbus/common:canbus_common",
        "//common_msgs/drivers/canbus/proto:can_card_parameter_cc_proto",
        ] + select({
            "//:use_esd_can": [
                "//common_msgs/drivers/canbus/can_client/esd:esd_can_client",
            ],
            "//conditions:default": [],
        }),
)

cc_library(
    name = "can_client",
    hdrs = ["can_client.h"],
    deps = [
        "//mimas/util",
        "//drivers/canbus/common:canbus_common",
        "//common_msgs/drivers/canbus/proto:can_card_parameter_cc_proto",
    ],
)

cc_binary(
    name = "can_client_tool",
    srcs = ["can_client_tool.cc"],
    deps = [
        "//core/cyber/time",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/proto:can_card_parameter_cc_proto",
        "@com_github_gflags_gflags//:gflags",
    ],
)

cc_test(
    name = "can_client_factory_test",
    size = "small",
    srcs = ["can_client_factory_test.cc"],
    deps = [
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/proto:can_card_parameter_cc_proto",
        "@com_google_googletest//:gtest_main",
    ],
)



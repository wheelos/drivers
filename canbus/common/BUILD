load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "canbus_common",
    srcs = ["byte.cc"],
    hdrs = [
        "byte.h",
        "canbus_consts.h",
    ],
    deps = [
        "//drivers/canbus:sensor_gflags",
    ],
)

cc_test(
    name = "byte_test",
    size = "small",
    srcs = ["byte_test.cc"],
    deps = [
        "//drivers/canbus/common:canbus_common",
        "@com_google_googletest//:gtest_main",
    ],
)



load("@rules_cc//cc:defs.bzl", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "gnss_stream",
    deps = [
        ":ntrip_stream",
        ":raw_stream",
        ":serial_stream",
        ":tcp_stream",
        ":udp_stream",
    ],
)

cc_library(
    name = "ntrip_stream",
    srcs = ["ntrip_stream.cc"],
    hdrs = ["tcp_stream.h"],
    deps = [
        ":stream",
        "//core/cyber",
        "//mimas/adapters:adapter_gflags",
        "//mimas/math",
        "//common_msgs/common/proto:pnc_point_cc_proto",
        "//mimas/util",
    ],
)

cc_library(
    name = "raw_stream",
    srcs = ["raw_stream.cc"],
    hdrs = ["raw_stream.h"],
    deps = [
        ":ntrip_stream",
        ":serial_stream",
        ":stream",
        "//core/cyber",
        "//common_msgs/canbus/proto:chassis_cc_proto",
        "//mimas/adapters:adapter_gflags",
        "//mimas/configs/proto:vehicle_config_cc_proto",
        "//common_msgs/common/proto:drive_state_cc_proto",
        "//common_msgs/common/proto:vehicle_signal_cc_proto",
        "//mimas/util:message_util",
        "//common_msgs/drivers/gnss/parser:gnss_parser",
        "//common_msgs/drivers/gnss/proto:gnss_status_cc_proto",
        "//common_msgs/drivers/gnss/proto:heading_cc_proto",
        "//common_msgs/drivers/gnss/proto:imu_cc_proto",
        "//common_msgs/drivers/gnss/util:gnss_util",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "serial_stream",
    srcs = ["serial_stream.cc"],
    deps = [
        ":stream",
        "//core/cyber",
        "//common_msgs/drivers/gnss/util:gnss_util",
    ],
)

cc_library(
    name = "tcp_stream",
    srcs = ["tcp_stream.cc"],
    hdrs = ["tcp_stream.h"],
    deps = [
        ":stream",
        "//core/cyber",
    ],
)

cc_library(
    name = "udp_stream",
    srcs = ["udp_stream.cc"],
    deps = [
        ":stream",
        "//core/cyber",
        "//common_msgs/drivers/gnss/util:gnss_util",
    ],
)

cc_library(
    name = "stream",
    hdrs = ["stream.h"],
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/gnss/util:gnss_util",
    ],
)



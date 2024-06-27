load("@rules_cc//cc:defs.bzl", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "gnss_parser",
    deps = [
        ":data_parser",
        ":novatel_parser",
        ":rtcm_parsers",
    ],
)

cc_library(
    name = "data_parser",
    srcs = ["data_parser.cc"],
    hdrs = [
        "data_parser.h",
        "parser.h",
    ],
    copts = ["-Ithird_party/rtklib"],
    deps = [
        ":novatel_parser",
        "//core/cyber",
        "//mimas/adapters:adapter_gflags",
        "//mimas/util:message_util",
        "//common_msgs/drivers/gnss/proto:gnss_best_pose_cc_proto",
        "//common_msgs/drivers/gnss/proto:gnss_cc_proto",
        "//common_msgs/drivers/gnss/proto:gnss_status_cc_proto",
        "//common_msgs/drivers/gnss/util:gnss_util",
        "//common_msgs/localization/proto:gps_cc_proto",
        "//common_msgs/localization/proto:imu_cc_proto",
        "//common_msgs/transform:transform_broadcaster",
        "@eigen",
        "@proj",
    ],
)

cc_library(
    name = "novatel_parser",
    srcs = ["novatel_parser.cc"],
    hdrs = [
        "novatel_messages.h",
        "parser.h",
        "rtcm_decode.h",
    ],
    copts = ["-Ithird_party/rtklib"],
    deps = [
        "//core/cyber",
        "//mimas/adapters:adapter_gflags",
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/common/proto:geometry_cc_proto",
        "//common_msgs/common/proto:header_cc_proto",
        "//common_msgs/drivers/gnss/proto:config_cc_proto",
        "//common_msgs/drivers/gnss/proto:gnss_best_pose_cc_proto",
        "//common_msgs/drivers/gnss/proto:gnss_cc_proto",
        "//common_msgs/drivers/gnss/proto:gnss_raw_observation_cc_proto",
        "//common_msgs/drivers/gnss/proto:heading_cc_proto",
        "//common_msgs/drivers/gnss/proto:imu_cc_proto",
        "//common_msgs/drivers/gnss/proto:ins_cc_proto",
        "//common_msgs/drivers/gnss/util:gnss_util",
        "//third_party/rtklib",
    ],
)

cc_library(
    name = "rtcm_parsers",
    srcs = [
        "rtcm3_parser.cc",
        "rtcm_parser.cc",
    ],
    hdrs = [
        "parser.h",
        "rtcm3_parser.h",
        "rtcm_decode.h",
        "rtcm_parser.h",
    ],
    copts = ["-Ithird_party/rtklib"],
    deps = [
        "//core/cyber",
        "//mimas/adapters:adapter_gflags",
        "//common_msgs/drivers/gnss/proto:config_cc_proto",
        "//common_msgs/drivers/gnss/proto:gnss_raw_observation_cc_proto",
        "//common_msgs/drivers/gnss/util:gnss_util",
        "//third_party/rtklib",
    ],
)



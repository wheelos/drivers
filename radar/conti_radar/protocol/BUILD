load("@rules_cc//cc:defs.bzl", "cc_library")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "drivers_conti_radar_protocol",
    srcs = glob([
        "*.cc",
    ]),
    hdrs = glob([
        "*.h",
    ]),
    deps = [
        "//common_msgs/common/proto:header_cc_proto",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "//common_msgs/drivers/canbus/proto:can_card_parameter_cc_proto",
        "//common_msgs/drivers/proto:conti_radar_cc_proto",
        "//common_msgs/drivers/radar/conti_radar/proto:conti_radar_conf_cc_proto",
    ],
)



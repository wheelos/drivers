load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])


filegroup(
    name = "runtime_data",
    srcs = glob([
        "conf/*.txt",
        "conf/*.conf",
        "dag/*.dag",
        "launch/*.launch",
    ]),
)

cc_library(
    name = "ultrasonic_radar_message_manager",
    srcs = ["ultrasonic_radar_message_manager.cc"],
    hdrs = ["ultrasonic_radar_message_manager.h"],
    deps = [
        "//common_msgs/common/proto:header_cc_proto",
        "//mimas/util:message_util",
        "//common_msgs/drivers/canbus:sensor_gflags",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/can_comm:can_sender",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "//common_msgs/drivers/proto:ultrasonic_radar_cc_proto",
    ],
)

#  cc_test(
#    name = "ultrasonic_radar_message_manager_test",
#    size = "small",
#     srcs = ["ultrasonic_radar_message_manager_test.cc"],
#     deps = [
#         "ultrasonic_radar_message_manager",
#         "@com_google_googletest//:gtest_main",
#     ],
# )

cc_library(
    name = "ultrasonic_radar_canbus_lib",
    srcs = ["ultrasonic_radar_canbus.cc"],
    hdrs = ["ultrasonic_radar_canbus.h"],
    deps = [
        ":ultrasonic_radar_message_manager",
        "//common_msgs/common/monitor_log",
        "//common_msgs/common/status",
        "//common_msgs/drivers/canbus:sensor_gflags",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/can_comm:can_receiver",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "//common_msgs/drivers/canbus/proto:sensor_canbus_conf_cc_proto",
        "//common_msgs/drivers/radar/ultrasonic_radar/proto:ultrasonic_radar_conf_cc_proto",
    ],
)

# cc_test(
#     name = "ultrasonic_radar_canbus_test",
#     size = "small",
#     srcs = ["ultrasonic_radar_canbus_test.cc"],
#     deps = [
#         ":ultrasonic_radar_canbus_lib",
#         ":ultrasonic_radar_message_manager",
#         "@com_google_googletest//:gtest_main",
#     ],
# )

cc_library(
    name = "ultrasonic_radar_canbus_component_lib",
    srcs = ["ultrasonic_radar_canbus_component.cc"],
    hdrs = ["ultrasonic_radar_canbus_component.h"],
    copts = ['-DMODULE_NAME=\\"ultrasonic_radar_canbus\\"'],
    deps = [
        ":ultrasonic_radar_canbus_lib",
        "//common_msgs/common/adapters:adapter_gflags",
        "//common_msgs/drivers/proto:ultrasonic_radar_cc_proto",
    ],
)

cc_binary(
    name = "libultrasonic_radar_canbus_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":ultrasonic_radar_canbus_component_lib"],
)



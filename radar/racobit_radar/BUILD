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
    name = "racobit_radar_message_manager",
    srcs = ["racobit_radar_message_manager.cc"],
    hdrs = ["racobit_radar_message_manager.h"],
    deps = [
        "//mimas/util:message_util",
        "//common_msgs/drivers/canbus:sensor_gflags",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/can_comm:can_sender",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "//common_msgs/drivers/proto:racobit_radar_cc_proto",
        "//common_msgs/drivers/radar/racobit_radar/protocol:drivers_racobit_radar_protocol",
    ],
)

# cc_test(
#     name = "racobit_radar_message_manager_test",
#     size = "small",
#     srcs = ["racobit_radar_message_manager_test.cc"],
#     deps = [
#         "racobit_radar_message_manager",
#         "@com_google_googletest//:gtest_main",
#     ],
# )

cc_library(
    name = "racobit_radar_canbus_lib",
    srcs = ["racobit_radar_canbus_component.cc"],
    hdrs = ["racobit_radar_canbus_component.h"],
    copts = ['-DMODULE_NAME=\\"racobit_radar_canbus\\"'],
    deps = [
        ":racobit_radar_message_manager",
        "//core/cyber",
        "//mimas/adapters:adapter_gflags",
        "//mimas/monitor_log",
        "//mimas/status",
        "//common_msgs/drivers/canbus:sensor_gflags",
        "//common_msgs/drivers/canbus/can_client:can_client_factory",
        "//common_msgs/drivers/canbus/can_comm:can_receiver",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "//common_msgs/drivers/canbus/proto:sensor_canbus_conf_cc_proto",
        "//common_msgs/drivers/radar/racobit_radar/protocol:drivers_racobit_radar_protocol",
    ],
)

cc_binary(
    name = "libracobit_radar_canbus_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":racobit_radar_canbus_lib"],
)



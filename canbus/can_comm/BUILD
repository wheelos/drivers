load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")


package(default_visibility = ["//visibility:public"])

cc_library(
    name = "can_receiver",
    hdrs = ["can_receiver.h"],
    deps = [
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/drivers/canbus/can_client",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "can_sender",
    hdrs = ["can_sender.h"],
    deps = [
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/drivers/canbus/can_client",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "@com_google_googletest//:gtest",
    ],
)

cc_library(
    name = "message_manager_base",
    hdrs = [
        "message_manager.h",
        "protocol_data.h",
    ],
    deps = [
        "//core/cyber/common:log",
        "//core/cyber/time",
        "//common_msgs/common/proto:error_code_cc_proto",
        "//common_msgs/drivers/canbus/common:canbus_common",
    ],
)

cc_test(
    name = "can_sender_test",
    size = "small",
    srcs = ["can_sender_test.cc"],
    deps = [
        "//core/cyber",
        "//common_msgs/canbus/proto:ch_cc_proto",
        "//common_msgs/canbus/proto:chassis_cc_proto",
        "//common_msgs/canbus/proto:chassis_detail_cc_proto",
        "//common_msgs/canbus/proto:ge3_cc_proto",
        "//common_msgs/canbus/proto:lexus_cc_proto",
        "//common_msgs/canbus/proto:transit_cc_proto",
        "//common_msgs/canbus/proto:wey_cc_proto",
        "//common_msgs/canbus/proto:zhongyun_cc_proto",
        "//common_msgs/canbus/proto:neolix_edu_cc_proto",
        "//common_msgs/drivers/canbus/can_client/fake:fake_can_client",
        "//common_msgs/drivers/canbus/can_comm:can_sender",
        "//common_msgs/drivers/canbus/common:canbus_common",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "can_receiver_test",
    size = "small",
    srcs = ["can_receiver_test.cc"],
    deps = [
        "//core/cyber",
        "//common_msgs/canbus/proto:ch_cc_proto",
        "//common_msgs/canbus/proto:chassis_cc_proto",
        "//common_msgs/canbus/proto:chassis_detail_cc_proto",
        "//common_msgs/canbus/proto:ge3_cc_proto",
        "//common_msgs/canbus/proto:lexus_cc_proto",
        "//common_msgs/canbus/proto:transit_cc_proto",
        "//common_msgs/canbus/proto:wey_cc_proto",
        "//common_msgs/canbus/proto:zhongyun_cc_proto",
        "//common_msgs/canbus/proto:neolix_edu_cc_proto",
        "//common_msgs/common/configs/proto:vehicle_config_cc_proto",
        "//common_msgs/common/proto:drive_state_cc_proto",
        "//common_msgs/common/proto:header_cc_proto",
        "//common_msgs/common/proto:vehicle_signal_cc_proto",
        "//common_msgs/drivers/canbus/can_client/fake:fake_can_client",
        "//common_msgs/drivers/canbus/can_comm:can_receiver",
        "//common_msgs/drivers/canbus/common:canbus_common",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "protocol_data_test",
    size = "small",
    srcs = ["protocol_data_test.cc"],
    deps = [
        "//common_msgs/canbus/proto:ch_cc_proto",
        "//common_msgs/canbus/proto:chassis_cc_proto",
        "//common_msgs/canbus/proto:chassis_detail_cc_proto",
        "//common_msgs/canbus/proto:ge3_cc_proto",
        "//common_msgs/canbus/proto:lexus_cc_proto",
        "//common_msgs/canbus/proto:transit_cc_proto",
        "//common_msgs/canbus/proto:wey_cc_proto",
        "//common_msgs/canbus/proto:zhongyun_cc_proto",
        "//common_msgs/canbus/proto:neolix_edu_cc_proto",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "message_manager_test",
    size = "small",
    srcs = ["message_manager_test.cc"],
    deps = [
        "//core/cyber",
        "//common_msgs/canbus/proto:chassis_detail_cc_proto",
        "//common_msgs/drivers/canbus/can_comm:message_manager_base",
        "@com_google_googletest//:gtest_main",
    ],
)



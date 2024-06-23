load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


package(default_visibility = ["//visibility:public"])

HESAI_COPTS = ['-DMODULE_NAME=\\"hesai\\"']


filegroup(
    name = "runtime_data",
    srcs = glob([
        "conf/*.txt",
        "conf/*.conf",
        "dag/*.dag",
        "launch/*.launch",
    ]),
)

cc_binary(
    name = "libhesai_driver_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [
        ":hesai_convert_component",
        "//common_msgs/drivers/lidar/hesai/driver:hesai_component",
    ],
)

cc_library(
    name = "hesai_convert_component",
    srcs = ["parser/hesai_convert_component.cc"],
    hdrs = ["parser/hesai_convert_component.h"],
    copts = HESAI_COPTS,
    deps = [
        ":parser_factory",
        "//core/cyber",
        "//common_msgs/drivers/lidar/hesai/driver",
        "//common_msgs/drivers/lidar/proto:hesai_config_cc_proto",
    ],
)

cc_library(
    name = "parser_factory",
    srcs = ["parser/parser_factory.cc"],
    hdrs = ["parser/parser_factory.h"],
    copts = HESAI_COPTS,
    deps = [
        ":hesai40_parser",
        ":hesai64_parser",
        ":parser",
        "//core/cyber",
    ],
)

cc_library(
    name = "hesai64_parser",
    srcs = ["parser/hesai64_parser.cc"],
    hdrs = ["parser/hesai64_parser.h"],
    copts = HESAI_COPTS,
    deps = [
        ":parser",
        "//core/cyber",
    ],
)

cc_library(
    name = "hesai40_parser",
    srcs = ["parser/hesai40_parser.cc"],
    hdrs = ["parser/hesai40_parser.h"],
    copts = HESAI_COPTS,
    deps = [
        ":parser",
        "//core/cyber",
    ],
)

cc_library(
    name = "parser",
    srcs = ["parser/parser.cc"],
    hdrs = ["parser/parser.h"],
    copts = HESAI_COPTS,
    deps = [
        ":tcp_cmd_client",
        ":type_defs",
        "//core/cyber",
        "//common_msgs/drivers/lidar/proto:hesai_cc_proto",
        "//common_msgs/drivers/lidar/proto:hesai_config_cc_proto",
        "//common_msgs/drivers/proto:pointcloud_cc_proto",
    ],
)

cc_library(
    name = "udp_input",
    srcs = ["input/udp_input.cc"],
    hdrs = ["input/udp_input.h"],
    copts = HESAI_COPTS,
    deps = [
        ":type_defs",
        "//core/cyber",
    ],
)

cc_library(
    name = "tcp_cmd_client",
    srcs = ["parser/tcp_cmd_client.cc"],
    hdrs = ["parser/tcp_cmd_client.h"],
    copts = HESAI_COPTS,
    deps = ["//core/cyber"],
)

cc_library(
    name = "type_defs",
    hdrs = ["common/type_defs.h"],
    deps = [":const_var"],
)

cc_library(
    name = "const_var",
    hdrs = ["common/const_var.h"],
)



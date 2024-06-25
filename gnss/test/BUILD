load("@rules_cc//cc:defs.bzl", "cc_binary")


package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "parser_cli",
    srcs = ["parser_cli.cc"],
    deps = [
        "//core/cyber",
        "//common_msgs/drivers/gnss/proto:gnss_status_cc_proto",
        "//common_msgs/drivers/gnss/stream:gnss_stream",
        "@com_github_gflags_gflags//:gflags",
    ],
)



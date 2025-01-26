#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include <example_interfaces/msg/string.hpp>
#include "sub_node.hpp"

SubNode::SubNode(
    const std::string& name_space,
    const rclcpp::NodeOptions& options
):Node("sub_test", name_space, options){
    sub_ = this->create_subscription<example_interfaces::msg::String>(
        "topic_test",
        rclcpp::QoS(10),
        this->SubNode::sub_callback
    )
}


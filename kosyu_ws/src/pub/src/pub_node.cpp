#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include <example_interfaces/msg/string.hpp>

#include "pub_node.hpp"

using namespace std::chrono_literals;

PubNode::PubNode(const std::string& name_space, const rclcpp::NodeOptions& options)
 : Node("pub_node_test", name_space, options), count_(0){
  publisher_ = this->create_publisher<example_interfaces::msg::String>("topic_test", rclcpp::QoS(10));
  timer_ = this->create_wall_timer(
    500ms,
    [this](){
      auto msg = std::make_shared<example_interfaces::msg::String>();
      msg->data = "hello " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Pub:%s", msg->data.c_str());
      publisher_->publish(*msg);
    }
  );
 }
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"
using std::placeholders::_1;

class SubNode : public rclcpp::Node
{
  public:
    SubNode()
    : Node("sub_node_test")
    {
      subscription_ = this->create_subscription<example_interfaces::msg::String>(
      "topic_test", 10, std::bind(&SubNode::topic_callback, this, _1));
    }

  private:
    void topic_callback(const example_interfaces::msg::String::SharedPtr msg) const //<- kono const ha class no menbahennsuu henkousinai
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubNode>());
    rclcpp::shutdown();
    return 0;
}
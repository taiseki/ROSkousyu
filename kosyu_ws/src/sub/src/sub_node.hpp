#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/string.hpp>

class SubNode : public rclcpp::Node{
    private:
        rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr sub_;
    public:
        SubNode(
            const std::string& name_space="",
            const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
        );
    private:
        void sub_callback(example_interfaces::msg::String::SharedPtr msg){
            RCLCPP_INFO(this->get_logger(), "sub: %s", msg);
        }
};
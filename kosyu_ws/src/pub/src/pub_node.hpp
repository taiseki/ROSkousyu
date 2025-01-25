#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/string.hpp>

class PubNode : public rclcpp::Node{
    private:
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        size_t count_;
    public:
        PubNode(
            const std::string& name_space="",
            const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
        );
};
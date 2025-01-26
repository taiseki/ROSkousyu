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
    private:
        void timer_callback(){
            auto msg = std::make_shared<example_interfaces::msg::String>();
            msg->data = "hello " + std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(), "Pub:%s", msg->data.c_str());
            publisher_->publish(*msg);
        }
};
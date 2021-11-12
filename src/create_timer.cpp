#include <ros2_timer_test/create_timer.hpp>

CreateTimerTestComponent::CreateTimerTestComponent(const rclcpp::NodeOptions & node_options)
: Node("create_timer_test", node_options)
{
    // Timer
    timer_ = rclcpp::create_timer(this, this->get_clock(),
        rclcpp::Duration::from_seconds(1.0),
        std::bind(&CreateTimerTestComponent::onTimer, this));
}

void CreateTimerTestComponent::onTimer()
{
    RCLCPP_INFO(get_logger(), "onTimer() called!");
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(CreateTimerTestComponent)

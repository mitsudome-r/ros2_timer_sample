#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/header.hpp>


class GenericTimerTestComponent: public rclcpp::Node
{
public:
  explicit GenericTimerTestComponent(const rclcpp::NodeOptions & node_options);

private:

  // Timer
  rclcpp::TimerBase::SharedPtr timer_;
  void onTimer();
};


// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:action/DriverAction.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__DRIVER_ACTION__TRAITS_HPP_
#define INTERFACES__ACTION__DETAIL__DRIVER_ACTION__TRAITS_HPP_

#include "interfaces/action/detail/driver_action__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'instruction'
#include "interfaces/msg/detail/driving_instruction__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_Goal>()
{
  return "interfaces::action::DriverAction_Goal";
}

template<>
inline const char * name<interfaces::action::DriverAction_Goal>()
{
  return "interfaces/action/DriverAction_Goal";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_Goal>
  : std::integral_constant<bool, has_fixed_size<interfaces::msg::DrivingInstruction>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_Goal>
  : std::integral_constant<bool, has_bounded_size<interfaces::msg::DrivingInstruction>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "interfaces/msg/detail/driving_result__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_Result>()
{
  return "interfaces::action::DriverAction_Result";
}

template<>
inline const char * name<interfaces::action::DriverAction_Result>()
{
  return "interfaces/action/DriverAction_Result";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_Result>
  : std::integral_constant<bool, has_fixed_size<interfaces::msg::DrivingResult>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_Result>
  : std::integral_constant<bool, has_bounded_size<interfaces::msg::DrivingResult>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'feedback'
#include "interfaces/msg/detail/driving_feedback__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_Feedback>()
{
  return "interfaces::action::DriverAction_Feedback";
}

template<>
inline const char * name<interfaces::action::DriverAction_Feedback>()
{
  return "interfaces/action/DriverAction_Feedback";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_Feedback>
  : std::integral_constant<bool, has_fixed_size<interfaces::msg::DrivingFeedback>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_Feedback>
  : std::integral_constant<bool, has_bounded_size<interfaces::msg::DrivingFeedback>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "interfaces/action/detail/driver_action__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_SendGoal_Request>()
{
  return "interfaces::action::DriverAction_SendGoal_Request";
}

template<>
inline const char * name<interfaces::action::DriverAction_SendGoal_Request>()
{
  return "interfaces/action/DriverAction_SendGoal_Request";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::DriverAction_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::DriverAction_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_SendGoal_Response>()
{
  return "interfaces::action::DriverAction_SendGoal_Response";
}

template<>
inline const char * name<interfaces::action::DriverAction_SendGoal_Response>()
{
  return "interfaces/action/DriverAction_SendGoal_Response";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_SendGoal>()
{
  return "interfaces::action::DriverAction_SendGoal";
}

template<>
inline const char * name<interfaces::action::DriverAction_SendGoal>()
{
  return "interfaces/action/DriverAction_SendGoal";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::action::DriverAction_SendGoal_Request>::value &&
    has_fixed_size<interfaces::action::DriverAction_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::action::DriverAction_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::action::DriverAction_SendGoal_Request>::value &&
    has_bounded_size<interfaces::action::DriverAction_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<interfaces::action::DriverAction_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::action::DriverAction_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::action::DriverAction_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_GetResult_Request>()
{
  return "interfaces::action::DriverAction_GetResult_Request";
}

template<>
inline const char * name<interfaces::action::DriverAction_GetResult_Request>()
{
  return "interfaces/action/DriverAction_GetResult_Request";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "interfaces/action/detail/driver_action__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_GetResult_Response>()
{
  return "interfaces::action::DriverAction_GetResult_Response";
}

template<>
inline const char * name<interfaces::action::DriverAction_GetResult_Response>()
{
  return "interfaces/action/DriverAction_GetResult_Response";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::DriverAction_Result>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::DriverAction_Result>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_GetResult>()
{
  return "interfaces::action::DriverAction_GetResult";
}

template<>
inline const char * name<interfaces::action::DriverAction_GetResult>()
{
  return "interfaces/action/DriverAction_GetResult";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::action::DriverAction_GetResult_Request>::value &&
    has_fixed_size<interfaces::action::DriverAction_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::action::DriverAction_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::action::DriverAction_GetResult_Request>::value &&
    has_bounded_size<interfaces::action::DriverAction_GetResult_Response>::value
  >
{
};

template<>
struct is_service<interfaces::action::DriverAction_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::action::DriverAction_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::action::DriverAction_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "interfaces/action/detail/driver_action__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::DriverAction_FeedbackMessage>()
{
  return "interfaces::action::DriverAction_FeedbackMessage";
}

template<>
inline const char * name<interfaces::action::DriverAction_FeedbackMessage>()
{
  return "interfaces/action/DriverAction_FeedbackMessage";
}

template<>
struct has_fixed_size<interfaces::action::DriverAction_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::DriverAction_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::DriverAction_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::DriverAction_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::DriverAction_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<interfaces::action::DriverAction>
  : std::true_type
{
};

template<>
struct is_action_goal<interfaces::action::DriverAction_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<interfaces::action::DriverAction_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<interfaces::action::DriverAction_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // INTERFACES__ACTION__DETAIL__DRIVER_ACTION__TRAITS_HPP_

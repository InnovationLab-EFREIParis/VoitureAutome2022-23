// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:msg/DrivingFeedback.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "interfaces/msg/detail/driving_feedback__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DrivingFeedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interfaces::msg::DrivingFeedback(_init);
}

void DrivingFeedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interfaces::msg::DrivingFeedback *>(message_memory);
  typed_message->~DrivingFeedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DrivingFeedback_message_member_array[1] = {
  {
    "todo",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces::msg::DrivingFeedback, todo),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DrivingFeedback_message_members = {
  "interfaces::msg",  // message namespace
  "DrivingFeedback",  // message name
  1,  // number of fields
  sizeof(interfaces::msg::DrivingFeedback),
  DrivingFeedback_message_member_array,  // message members
  DrivingFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  DrivingFeedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DrivingFeedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DrivingFeedback_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::msg::DrivingFeedback>()
{
  return &::interfaces::msg::rosidl_typesupport_introspection_cpp::DrivingFeedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, msg, DrivingFeedback)() {
  return &::interfaces::msg::rosidl_typesupport_introspection_cpp::DrivingFeedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

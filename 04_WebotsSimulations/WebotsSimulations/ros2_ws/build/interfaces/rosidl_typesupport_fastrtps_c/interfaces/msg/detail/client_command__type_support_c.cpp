// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from interfaces:msg/ClientCommand.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/client_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interfaces/msg/detail/client_command__struct.h"
#include "interfaces/msg/detail/client_command__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ClientCommand__ros_msg_type = interfaces__msg__ClientCommand;

static bool _ClientCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ClientCommand__ros_msg_type * ros_message = static_cast<const _ClientCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: up
  {
    cdr << (ros_message->up ? true : false);
  }

  // Field name: down
  {
    cdr << (ros_message->down ? true : false);
  }

  // Field name: right
  {
    cdr << (ros_message->right ? true : false);
  }

  // Field name: left
  {
    cdr << (ros_message->left ? true : false);
  }

  return true;
}

static bool _ClientCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ClientCommand__ros_msg_type * ros_message = static_cast<_ClientCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: up
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->up = tmp ? true : false;
  }

  // Field name: down
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->down = tmp ? true : false;
  }

  // Field name: right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->right = tmp ? true : false;
  }

  // Field name: left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->left = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t get_serialized_size_interfaces__msg__ClientCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ClientCommand__ros_msg_type * ros_message = static_cast<const _ClientCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name up
  {
    size_t item_size = sizeof(ros_message->up);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name down
  {
    size_t item_size = sizeof(ros_message->down);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right
  {
    size_t item_size = sizeof(ros_message->right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left
  {
    size_t item_size = sizeof(ros_message->left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ClientCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_interfaces__msg__ClientCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t max_serialized_size_interfaces__msg__ClientCommand(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: up
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: down
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ClientCommand__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_interfaces__msg__ClientCommand(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ClientCommand = {
  "interfaces::msg",
  "ClientCommand",
  _ClientCommand__cdr_serialize,
  _ClientCommand__cdr_deserialize,
  _ClientCommand__get_serialized_size,
  _ClientCommand__max_serialized_size
};

static rosidl_message_type_support_t _ClientCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ClientCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, msg, ClientCommand)() {
  return &_ClientCommand__type_support;
}

#if defined(__cplusplus)
}
#endif

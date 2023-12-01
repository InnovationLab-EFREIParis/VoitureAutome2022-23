// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from interfaces:msg/DrivingResult.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/driving_result__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interfaces/msg/detail/driving_result__struct.h"
#include "interfaces/msg/detail/driving_result__functions.h"
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

#include "interfaces/msg/detail/mon_ackermann_drive__functions.h"  // instruction

// forward declare type support functions
size_t get_serialized_size_interfaces__msg__MonAckermannDrive(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_interfaces__msg__MonAckermannDrive(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, msg, MonAckermannDrive)();


using _DrivingResult__ros_msg_type = interfaces__msg__DrivingResult;

static bool _DrivingResult__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DrivingResult__ros_msg_type * ros_message = static_cast<const _DrivingResult__ros_msg_type *>(untyped_ros_message);
  // Field name: instruction
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, interfaces, msg, MonAckermannDrive
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->instruction, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _DrivingResult__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DrivingResult__ros_msg_type * ros_message = static_cast<_DrivingResult__ros_msg_type *>(untyped_ros_message);
  // Field name: instruction
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, interfaces, msg, MonAckermannDrive
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->instruction))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t get_serialized_size_interfaces__msg__DrivingResult(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DrivingResult__ros_msg_type * ros_message = static_cast<const _DrivingResult__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name instruction

  current_alignment += get_serialized_size_interfaces__msg__MonAckermannDrive(
    &(ros_message->instruction), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _DrivingResult__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_interfaces__msg__DrivingResult(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t max_serialized_size_interfaces__msg__DrivingResult(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: instruction
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_interfaces__msg__MonAckermannDrive(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _DrivingResult__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_interfaces__msg__DrivingResult(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_DrivingResult = {
  "interfaces::msg",
  "DrivingResult",
  _DrivingResult__cdr_serialize,
  _DrivingResult__cdr_deserialize,
  _DrivingResult__get_serialized_size,
  _DrivingResult__max_serialized_size
};

static rosidl_message_type_support_t _DrivingResult__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DrivingResult,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, msg, DrivingResult)() {
  return &_DrivingResult__type_support;
}

#if defined(__cplusplus)
}
#endif

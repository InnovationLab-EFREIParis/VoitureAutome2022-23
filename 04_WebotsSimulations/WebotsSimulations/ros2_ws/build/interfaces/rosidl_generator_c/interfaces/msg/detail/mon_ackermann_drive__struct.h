// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/MonAckermannDrive.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__STRUCT_H_
#define INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/MonAckermannDrive in the package interfaces.
typedef struct interfaces__msg__MonAckermannDrive
{
  float steering_angle;
  float steering_angle_velocity;
  float speed;
  float acceleration;
  float jerk;
} interfaces__msg__MonAckermannDrive;

// Struct for a sequence of interfaces__msg__MonAckermannDrive.
typedef struct interfaces__msg__MonAckermannDrive__Sequence
{
  interfaces__msg__MonAckermannDrive * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__MonAckermannDrive__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__STRUCT_H_

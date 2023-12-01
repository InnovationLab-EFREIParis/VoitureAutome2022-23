// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:action/DriverAction.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "interfaces/action/detail/driver_action__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_Goal_type_support_ids_t;

static const _DriverAction_Goal_type_support_ids_t _DriverAction_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_Goal_type_support_symbol_names_t _DriverAction_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_Goal)),
  }
};

typedef struct _DriverAction_Goal_type_support_data_t
{
  void * data[2];
} _DriverAction_Goal_type_support_data_t;

static _DriverAction_Goal_type_support_data_t _DriverAction_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_Goal_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_Goal>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_Goal)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_Result_type_support_ids_t;

static const _DriverAction_Result_type_support_ids_t _DriverAction_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_Result_type_support_symbol_names_t _DriverAction_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_Result)),
  }
};

typedef struct _DriverAction_Result_type_support_data_t
{
  void * data[2];
} _DriverAction_Result_type_support_data_t;

static _DriverAction_Result_type_support_data_t _DriverAction_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_Result_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_Result_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_Result_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_Result>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_Result)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_Feedback_type_support_ids_t;

static const _DriverAction_Feedback_type_support_ids_t _DriverAction_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_Feedback_type_support_symbol_names_t _DriverAction_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_Feedback)),
  }
};

typedef struct _DriverAction_Feedback_type_support_data_t
{
  void * data[2];
} _DriverAction_Feedback_type_support_data_t;

static _DriverAction_Feedback_type_support_data_t _DriverAction_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_Feedback_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_Feedback>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_Feedback)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_SendGoal_Request_type_support_ids_t;

static const _DriverAction_SendGoal_Request_type_support_ids_t _DriverAction_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_SendGoal_Request_type_support_symbol_names_t _DriverAction_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_SendGoal_Request)),
  }
};

typedef struct _DriverAction_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _DriverAction_SendGoal_Request_type_support_data_t;

static _DriverAction_SendGoal_Request_type_support_data_t _DriverAction_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_SendGoal_Request_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_SendGoal_Request>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_SendGoal_Request)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_SendGoal_Response_type_support_ids_t;

static const _DriverAction_SendGoal_Response_type_support_ids_t _DriverAction_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_SendGoal_Response_type_support_symbol_names_t _DriverAction_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_SendGoal_Response)),
  }
};

typedef struct _DriverAction_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _DriverAction_SendGoal_Response_type_support_data_t;

static _DriverAction_SendGoal_Response_type_support_data_t _DriverAction_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_SendGoal_Response_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_SendGoal_Response>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_SendGoal_Response)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_SendGoal_type_support_ids_t;

static const _DriverAction_SendGoal_type_support_ids_t _DriverAction_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_SendGoal_type_support_symbol_names_t _DriverAction_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_SendGoal)),
  }
};

typedef struct _DriverAction_SendGoal_type_support_data_t
{
  void * data[2];
} _DriverAction_SendGoal_type_support_data_t;

static _DriverAction_SendGoal_type_support_data_t _DriverAction_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_SendGoal_service_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t DriverAction_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<interfaces::action::DriverAction_SendGoal>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_GetResult_Request_type_support_ids_t;

static const _DriverAction_GetResult_Request_type_support_ids_t _DriverAction_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_GetResult_Request_type_support_symbol_names_t _DriverAction_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_GetResult_Request)),
  }
};

typedef struct _DriverAction_GetResult_Request_type_support_data_t
{
  void * data[2];
} _DriverAction_GetResult_Request_type_support_data_t;

static _DriverAction_GetResult_Request_type_support_data_t _DriverAction_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_GetResult_Request_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_GetResult_Request>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_GetResult_Request)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_GetResult_Response_type_support_ids_t;

static const _DriverAction_GetResult_Response_type_support_ids_t _DriverAction_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_GetResult_Response_type_support_symbol_names_t _DriverAction_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_GetResult_Response)),
  }
};

typedef struct _DriverAction_GetResult_Response_type_support_data_t
{
  void * data[2];
} _DriverAction_GetResult_Response_type_support_data_t;

static _DriverAction_GetResult_Response_type_support_data_t _DriverAction_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_GetResult_Response_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_GetResult_Response>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_GetResult_Response)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_GetResult_type_support_ids_t;

static const _DriverAction_GetResult_type_support_ids_t _DriverAction_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_GetResult_type_support_symbol_names_t _DriverAction_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_GetResult)),
  }
};

typedef struct _DriverAction_GetResult_type_support_data_t
{
  void * data[2];
} _DriverAction_GetResult_type_support_data_t;

static _DriverAction_GetResult_type_support_data_t _DriverAction_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_GetResult_service_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t DriverAction_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<interfaces::action::DriverAction_GetResult>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DriverAction_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DriverAction_FeedbackMessage_type_support_ids_t;

static const _DriverAction_FeedbackMessage_type_support_ids_t _DriverAction_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DriverAction_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DriverAction_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DriverAction_FeedbackMessage_type_support_symbol_names_t _DriverAction_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, action, DriverAction_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, action, DriverAction_FeedbackMessage)),
  }
};

typedef struct _DriverAction_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _DriverAction_FeedbackMessage_type_support_data_t;

static _DriverAction_FeedbackMessage_type_support_data_t _DriverAction_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DriverAction_FeedbackMessage_message_typesupport_map = {
  2,
  "interfaces",
  &_DriverAction_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_DriverAction_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_DriverAction_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DriverAction_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DriverAction_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::action::DriverAction_FeedbackMessage>()
{
  return &::interfaces::action::rosidl_typesupport_cpp::DriverAction_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces, action, DriverAction_FeedbackMessage)() {
  return get_message_type_support_handle<interfaces::action::DriverAction_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "interfaces/action/detail/driver_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t DriverAction_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<interfaces::action::DriverAction>()
{
  using ::interfaces::action::rosidl_typesupport_cpp::DriverAction_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  DriverAction_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::interfaces::action::DriverAction::Impl::SendGoalService>();
  DriverAction_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::interfaces::action::DriverAction::Impl::GetResultService>();
  DriverAction_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::interfaces::action::DriverAction::Impl::CancelGoalService>();
  DriverAction_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::interfaces::action::DriverAction::Impl::FeedbackMessage>();
  DriverAction_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::interfaces::action::DriverAction::Impl::GoalStatusMessage>();
  return &DriverAction_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

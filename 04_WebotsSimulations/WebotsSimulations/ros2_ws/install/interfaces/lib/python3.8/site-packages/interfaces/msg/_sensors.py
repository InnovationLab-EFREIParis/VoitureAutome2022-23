# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/Sensors.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Sensors(type):
    """Metaclass of message 'Sensors'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interfaces.msg.Sensors')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sensors
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sensors
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sensors
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sensors
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sensors

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Sensors(metaclass=Metaclass_Sensors):
    """Message class 'Sensors'."""

    __slots__ = [
        '_example_sensor1_name',
        '_example_sensor1_value',
        '_example_sensor2_name',
        '_example_sensor2_value',
        '_example_sensor3_name',
        '_example_sensor3_value',
    ]

    _fields_and_field_types = {
        'example_sensor1_name': 'string',
        'example_sensor1_value': 'int64',
        'example_sensor2_name': 'string',
        'example_sensor2_value': 'int64',
        'example_sensor3_name': 'string',
        'example_sensor3_value': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.example_sensor1_name = kwargs.get('example_sensor1_name', str())
        self.example_sensor1_value = kwargs.get('example_sensor1_value', int())
        self.example_sensor2_name = kwargs.get('example_sensor2_name', str())
        self.example_sensor2_value = kwargs.get('example_sensor2_value', int())
        self.example_sensor3_name = kwargs.get('example_sensor3_name', str())
        self.example_sensor3_value = kwargs.get('example_sensor3_value', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.example_sensor1_name != other.example_sensor1_name:
            return False
        if self.example_sensor1_value != other.example_sensor1_value:
            return False
        if self.example_sensor2_name != other.example_sensor2_name:
            return False
        if self.example_sensor2_value != other.example_sensor2_value:
            return False
        if self.example_sensor3_name != other.example_sensor3_name:
            return False
        if self.example_sensor3_value != other.example_sensor3_value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def example_sensor1_name(self):
        """Message field 'example_sensor1_name'."""
        return self._example_sensor1_name

    @example_sensor1_name.setter
    def example_sensor1_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'example_sensor1_name' field must be of type 'str'"
        self._example_sensor1_name = value

    @property
    def example_sensor1_value(self):
        """Message field 'example_sensor1_value'."""
        return self._example_sensor1_value

    @example_sensor1_value.setter
    def example_sensor1_value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'example_sensor1_value' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'example_sensor1_value' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._example_sensor1_value = value

    @property
    def example_sensor2_name(self):
        """Message field 'example_sensor2_name'."""
        return self._example_sensor2_name

    @example_sensor2_name.setter
    def example_sensor2_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'example_sensor2_name' field must be of type 'str'"
        self._example_sensor2_name = value

    @property
    def example_sensor2_value(self):
        """Message field 'example_sensor2_value'."""
        return self._example_sensor2_value

    @example_sensor2_value.setter
    def example_sensor2_value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'example_sensor2_value' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'example_sensor2_value' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._example_sensor2_value = value

    @property
    def example_sensor3_name(self):
        """Message field 'example_sensor3_name'."""
        return self._example_sensor3_name

    @example_sensor3_name.setter
    def example_sensor3_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'example_sensor3_name' field must be of type 'str'"
        self._example_sensor3_name = value

    @property
    def example_sensor3_value(self):
        """Message field 'example_sensor3_value'."""
        return self._example_sensor3_value

    @example_sensor3_value.setter
    def example_sensor3_value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'example_sensor3_value' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'example_sensor3_value' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._example_sensor3_value = value

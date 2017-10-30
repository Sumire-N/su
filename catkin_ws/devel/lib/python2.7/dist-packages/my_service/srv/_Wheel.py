# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from my_service/WheelRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class WheelRequest(genpy.Message):
  _md5sum = "f0250a22f26b2d4fb70fdb58e85f8b9a"
  _type = "my_service/WheelRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 target_linear_velocity
float64 target_angular_velocity
"""
  __slots__ = ['target_linear_velocity','target_angular_velocity']
  _slot_types = ['float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       target_linear_velocity,target_angular_velocity

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(WheelRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.target_linear_velocity is None:
        self.target_linear_velocity = 0.
      if self.target_angular_velocity is None:
        self.target_angular_velocity = 0.
    else:
      self.target_linear_velocity = 0.
      self.target_angular_velocity = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2d.pack(_x.target_linear_velocity, _x.target_angular_velocity))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.target_linear_velocity, _x.target_angular_velocity,) = _struct_2d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2d.pack(_x.target_linear_velocity, _x.target_angular_velocity))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.target_linear_velocity, _x.target_angular_velocity,) = _struct_2d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2d = struct.Struct("<2d")
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from my_service/WheelResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class WheelResponse(genpy.Message):
  _md5sum = "056d03b83b9853a858cfe23bcf52551d"
  _type = "my_service/WheelResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 current_linear_velocity
float64 current_angular_velocity

"""
  __slots__ = ['current_linear_velocity','current_angular_velocity']
  _slot_types = ['float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       current_linear_velocity,current_angular_velocity

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(WheelResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.current_linear_velocity is None:
        self.current_linear_velocity = 0.
      if self.current_angular_velocity is None:
        self.current_angular_velocity = 0.
    else:
      self.current_linear_velocity = 0.
      self.current_angular_velocity = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2d.pack(_x.current_linear_velocity, _x.current_angular_velocity))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.current_linear_velocity, _x.current_angular_velocity,) = _struct_2d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2d.pack(_x.current_linear_velocity, _x.current_angular_velocity))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.current_linear_velocity, _x.current_angular_velocity,) = _struct_2d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2d = struct.Struct("<2d")
class Wheel(object):
  _type          = 'my_service/Wheel'
  _md5sum = 'ef11d1e759e69b1c0c4a1abd582c4abd'
  _request_class  = WheelRequest
  _response_class = WheelResponse

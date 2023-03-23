#pragma once
#include <stdint.h>

// -----------------------
// -- Macro definitions --
// -----------------------

#define CREATE_VEC2_STRUCT(StructName, DataType)	\
	typedef union									\
	{												\
		DataType data[2];							\
		struct { DataType x, y; };					\
	}StructName

#define CREATE_VEC3_STRUCT(StructName, DataType)	\
	typedef union									\
	{												\
		DataType data[3];							\
		struct { DataType x, y, z; };				\
		struct { DataType r, g, b; };				\
	}StructName

#define CREATE_VEC4_STRUCT(StructName, DataType)	\
	typedef union									\
	{												\
		DataType data[4];							\
		struct { DataType x, y, z, w; };			\
		struct { DataType r, g, b, a; };			\
	}StructName


// -------------
// -- Structs --
// -------------

CREATE_VEC2_STRUCT(v2ui8, uint8_t);		// vector2 [uint8]
CREATE_VEC2_STRUCT(v2ui32, uint32_t);	// vector2 [unsigned int]
CREATE_VEC2_STRUCT(v2i32, int32_t);		// vector2 [int]
CREATE_VEC2_STRUCT(v2f32, float);		// vector2 [float]

CREATE_VEC3_STRUCT(v3ui8, uint8_t);		// vector3 [uint8]
CREATE_VEC3_STRUCT(v3ui32, uint32_t);	// vector3 [unsigned int]
CREATE_VEC3_STRUCT(v3i32, int32_t);		// vector3 [int]
CREATE_VEC3_STRUCT(v3f32, float);		// vector3 [float]

CREATE_VEC4_STRUCT(v4ui8, uint8_t);		// vector4 [uint8]
CREATE_VEC4_STRUCT(v4ui32, uint32_t);	// vector4 [unsigned int]
CREATE_VEC4_STRUCT(v4i32, int32_t);		// vector4 [int]
CREATE_VEC4_STRUCT(v4f32, float);		// vector4 [float]


// ---------------
// -- Functions --
// ---------------


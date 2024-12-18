#ifndef __g_shader_vertex_skeleton_header__
#define __g_shader_vertex_skeleton_header__
static const char *g_shader_vertex_skeleton = ""
#if defined(USE_LD)
"skeleton.vert.glsl"
#else
"attribute vec3 H;"
"attribute vec3 t;"
"attribute vec4 A;"
"attribute vec4 E;"
"uniform mat4 P;"
"uniform mat4 Y;"
"uniform mat3 Q;"
"uniform mat4 L[64];"
"uniform vec3 T;"
"varying vec3 D;"
"varying vec3 f;"
"void main()"
"{"
"ivec4 C=ivec4(E);"
"mat4 x=L[C.s]*A.s+L[C.t]*A.t+L[C.p]*A.p;"
"vec3 A=(x*vec4(H,1)).stp,H=mat3(x)*t;"
"D=Q*H,f=T-(Y*vec4(A,1)).stp,gl_Position=P*vec4(A,1);"
"}"
#endif
"";
#if !defined(DNLOAD_RENAME_UNUSED)
#if defined(__GNUC__)
#define DNLOAD_RENAME_UNUSED __attribute__((unused))
#else
#define DNLOAD_RENAME_UNUSED
#endif
#endif
static const char* g_shader_vertex_skeleton_attribute_position DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"position"
#else
"H"
#endif
"";
static const char* g_shader_vertex_skeleton_attribute_normal DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"normal"
#else
"t"
#endif
"";
static const char* g_shader_vertex_skeleton_attribute_bone_weight DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"bone_weight"
#else
"A"
#endif
"";
static const char* g_shader_vertex_skeleton_attribute_bone_ref DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"bone_ref"
#else
"E"
#endif
"";
static const char* g_shader_vertex_skeleton_uniform_combined_transform DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"combined_transform"
#else
"P"
#endif
"";
static const char* g_shader_vertex_skeleton_uniform_modelview_transform DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"modelview_transform"
#else
"Y"
#endif
"";
static const char* g_shader_vertex_skeleton_uniform_normal_transform DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"normal_transform"
#else
"Q"
#endif
"";
static const char* g_shader_vertex_skeleton_uniform_skeleton DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"skeleton"
#else
"L"
#endif
"";
static const char* g_shader_vertex_skeleton_uniform_camera_position DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"camera_position"
#else
"T"
#endif
"";
#endif

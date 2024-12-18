#ifndef __g_shader_fragment_font_overlay_header__
#define __g_shader_fragment_font_overlay_header__
static const char *g_shader_fragment_font_overlay = ""
#if defined(USE_LD)
"font_overlay.frag.glsl"
#else
"uniform sampler2D Q;"
"uniform sampler2D T;"
"varying vec2 A;"
"varying vec2 D;"
"void main()"
"{"
"float H=texture2D(Q,A).s,f=texture2D(T,D).s+.001;"
"gl_FragColor=vec4(x(f,H*.6));"
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
static const char* g_shader_fragment_font_overlay_uniform_glyph DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"glyph"
#else
"Q"
#endif
"";
static const char* g_shader_fragment_font_overlay_uniform_stipple DNLOAD_RENAME_UNUSED = ""
#if defined(USE_LD)
"stipple"
#else
"T"
#endif
"";
#endif

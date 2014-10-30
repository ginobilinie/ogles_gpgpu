#ifndef OGLES_GPGPU_COMMON_PROC_GRAYSCALE
#define OGLES_GPGPU_COMMON_PROC_GRAYSCALE

#include "../common_includes.h"

#include "procbase.h"

#define OGLES_GPGPU_COMMON_PROC_GRAYSCALE_FSHADER "\
precision mediump float; \
varying vec2 vTexCoord; \
uniform sampler2D sTexture; \
const vec3 rgb2gray = vec3(0.299, 0.587, 0.114); \
void main() { \
    float gray = dot(texture2D(sTexture, vTexCoord).rgb, rgb2gray); \
    gl_FragColor = vec4(gray, gray, gray, 1.0); \
}\
"

namespace ogles_gpgpu {
class GrayscaleProc : public ProcBase {
public:
    GrayscaleProc();
    
    void setOutputSize(float scaleFactor)  { procParamOutScale = scaleFactor; }
    void setOutputSize(int outW, int outH) { procParamOutW = outW; procParamOutH = outH; }
    
    virtual void init(int inW, int inH);
    
    virtual void render();
    
private:
    int procParamOutW;
    int procParamOutH;
    float procParamOutScale;
    
	GLint shParamAPos;
	GLint shParamATexCoord;
	GLfloat vertexBuf[OGLES_GPGPU_QUAD_VERTEX_BUFSIZE];
	GLfloat texCoordBuf[OGLES_GPGPU_QUAD_TEX_BUFSIZE];
};
}

#endif
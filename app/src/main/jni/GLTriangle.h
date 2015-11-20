//
// Created by Maksim Podkorytov on 11/20/15.
//

#ifndef NDK_OPEN_GL_ES2_TRIANGLE_GLTRIANGLE_H
#define NDK_OPEN_GL_ES2_TRIANGLE_GLTRIANGLE_H

#include <GLES2/gl2.h>

class GLTriangle {
private:

    const GLfloat rad1 = 0.4;
    const GLfloat phase1 = .4;
    const GLfloat freq1 = -1. / 360;

    const GLfloat rad2 = .8;
    const GLfloat phase2 = 0;
    const GLfloat freq2 = -1. / 30;

    size_t time = 0;

    const GLchar v_shader[1024] =
            "attribute vec4 vPosition;    \n"
            "void main()                  \n"
            "{                            \n"
            "   gl_Position = vPosition;  \n"
            "}                            \n";
    const GLchar p_shader[1024] =
            "precision mediump float;					  \n"
            "void main()                                  \n"
            "{                                            \n"
            "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 0.5 );\n"
            "}                                            \n";

    GLuint m_programObject;
    int width, height;
public:
    void init();
    void draw();
    void resizeView(int, int);
};

#endif //NDK_OPEN_GL_ES2_TRIANGLE_GLTRIANGLE_H

